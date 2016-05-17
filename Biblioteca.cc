#include "Biblioteca.hh"
#include "Text.hh"
#include "Frase.hh"

Biblioteca::Biblioteca(){
    triat = false;
    ncites = 1;
}

Biblioteca::~Biblioteca(){
    
}

Text const Biblioteca::triar_text(string s){
	for (map<string, map<string, Text> >::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end(); ++i) {
		map<string, Text> k = i->second;
		for (map<string, Text>::const_iterator j = k.begin(); j != k.end(); ++j) {
			Text t = j->second;
                        /*
                        for(){
                            
                        }
                        for(){
                            
                        }
                        */
			if (t.buscar_paraules(s)) {
				ttriat = j->second;
				triat = true;
				return ttriat;
			}
		}
	}
	if (not triat) cout << "error" << endl;
	return ttriat;
}

bool const Biblioteca::consultar_triat(){
    return triat;
}

void const Biblioteca::tots_textos(){
	Text t;
    for (map<string, map<string, Text> >::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end(); ++i) {
    	map<string, Text> k = i->second;
    	for (map<string, Text>::const_iterator j = k.begin(); j != k.end(); ++j) {
			t = j->second;
    		cout << t.autor_text() << " " << t.titol_text() << endl;
    	}
    }
}

void const Biblioteca::textos_autor(string s){
	map<string, map<string, Text> >::const_iterator i = conjunt_textos.find(s);
	map<string, Text> k = i->second;
    for (map<string, Text>::const_iterator j = k.begin(); j != k.end(); ++j) {
    	cout << j->first << endl;
    }
}

void const Biblioteca::tots_autors(){
	//RAPID!
	string s;
	infoautor k;
	for (map<string, infoautor>::const_iterator i = conjunt_autors.begin(); i != conjunt_autors.end(); ++i) {
		k = i->second;
		s = i->first;
		cout << s << " " << k.ntextos << " ";
		cout << k.nfrases << " " << k.nparaules << endl;
    }
    
}

void Biblioteca::afegir_text(string op){
    Text t;
    t.llegir_text(op);
	
    string s = t.autor_text();
    string ti = t.titol_text();
    map<string, map<string, Text> >::iterator i = conjunt_textos.find(s);
    if (i == conjunt_textos.end()) {
    	map<string, Text> u;
    	u.insert(make_pair(ti, t));
    	conjunt_textos.insert(make_pair(s, u));
    }
    else {
    	i->second.insert(make_pair(ti, t));
    }
    //hem de buscar que no hi hagi cap autor amb el mateix titol que el nou text afegit sino error 
    
    infoautor k;
    map<string, infoautor>::const_iterator j = conjunt_autors.find(s);
    if (j == conjunt_autors.end()) {
		
    	k.ntextos = 1;
	    k.nfrases = t.consultar_numfrases();
	    k.nparaules = t.consultar_numparaules();
    	conjunt_autors.insert(make_pair(s, k));
		
    }
    else {
		
    	k.ntextos = j->second.ntextos + 1;
		k.nfrases = j->second.nfrases + t.consultar_numfrases();
		k.nparaules = j->second.nparaules + t.consultar_numparaules();
		conjunt_autors.erase(s);
		conjunt_autors.insert(make_pair(s, k));
		
	}
	
}

void Biblioteca::eliminar_text(){
    conjunt_textos.erase(ttriat.autor_text());
    triat = false;
}

void Biblioteca::afegir_cita(int x, int y){
	//2 o 3 incials y despres el numero! per la referencia!
	string autor = ttriat.autor_text();
	string titol = ttriat.titol_text();
	string refe;
	int numref = 1;
	infocita k;
	string op;
	istringstream iss(autor);
	while (iss >> op) {
		refe += char(op[0]);
	}
	/*iss >> op;
	refe = char(op[0]);
	iss >> op;
	refe += char(op[0]);*/
	string Result;
	stringstream convert;
	convert << numref;
	Result = convert.str();
	refe += Result;
	map<string,infocita>::iterator i = conjunt_cites.find(refe);
	if (i == conjunt_cites.end()) {
		k.firstfrase = x;
   	        k.lastfrase = y;
		k.aut = autor;
		k.tit = titol;
  	        k.contingutcita = ttriat.interval_frases(x, y);
	}
	else {
		while (i != conjunt_cites.end()) {
			op.clear();
			refe.clear();
			++numref;
			istringstream iss(autor);
		        while (iss >> op) {
		            refe += char(op[0]);
	                }
			string Result;
			stringstream convert;
			convert << numref;
			Result = convert.str();
			refe += Result;
			i = conjunt_cites.find(refe);
		}
		k.firstfrase = x;
   	        k.lastfrase = y;
		k.aut = autor;
		k.tit = titol;
  	        k.contingutcita = ttriat.interval_frases(x, y);
	}
	conjunt_cites.insert(make_pair(refe, k));
}

void const Biblioteca::cites_autor(string autor) {
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		if (autor == i->second.aut) {
			cout << i->first << endl;
			for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				Frase fr = j->second;
				cout << j->first << " "; 
				fr.escriu_frase();
			}
			cout << i->second.aut << " " << i->second.tit << endl;
		}
    }
}

void const Biblioteca::info_cita(string referencia) {
	map<string,infocita>::const_iterator i = conjunt_cites.find(referencia);
	if (i != conjunt_cites.end()){
		cout << i->second.aut << " " << i->second.tit << endl; 
		cout << i->second.firstfrase << "-" << i->second.lastfrase << endl;
		for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				Frase fr = j->second;
				cout << j->first << " "; 
				fr.escriu_frase();
		}
    }
}

void const Biblioteca::totes_cites() {
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		cout << i->first << endl;
		for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				Frase fr = j->second;
				cout << j->first << " "; 
				fr.escriu_frase();
		}
		cout << i->second.aut << " " << i->second.tit << endl;
    }
}

void const Biblioteca::cites_text(bool b) {
	if(b) cout << "Cites associades:" << endl;
	string titol = ttriat.titol_text();
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		if(i->second.tit == titol) {
			cout << i->first << endl;
			for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
					Frase fr = j->second;
					cout << j->first << " "; 
					fr.escriu_frase();
			}
			if(not b) cout << i->second.aut << " " << i->second.tit << endl;
	    }
    }
}

void Biblioteca::eliminar_cita(string referencia) {
	map<string,infocita>::iterator i = conjunt_cites.find(referencia);
    if(i != conjunt_cites.end()) {
    	conjunt_cites.erase(i);
    }
    else cout << "error" << endl;
}
