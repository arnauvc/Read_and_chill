#include "Biblioteca.hh"
#include "Text.hh"
#include "Frase.hh"
#include <algorithm>

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
			if (t.buscar_paraules(s)) {
				ttriat = j->second;
				triat = true;
				cout << "TROBAT" << endl;
				return ttriat;
			}
		}
	}
	if (not triat) cout << "NO TROBAT" << endl;
	//b = false;
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
    /*sort(titols_autor.begin(), titols_autor.end(), comp_titols);
    for (int i = 0; i < titols_autor.size(); ++i) {
    	cout << titols_autor[i] << endl;
    }*/
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

void Biblioteca::afegir_text(){
    Text t;
    t.llegir_text();
	
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
    //map<string, Text>::const_iterator i = find(ttriat.autor_text());
    conjunt_textos.erase(ttriat.autor_text());
    triat = false;
}

void Biblioteca::afegir_cita(int x, int y){
	
	/*char first, last;
	first = cin.get();     // get one character
	cin.ignore(256,' ');   // ignore until space
	last = cin.get();*/      // get one character
	
}

/*void const Biblioteca::cites_autor(string autor) {
	for (map<string,Text>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		
    }
}

void const Biblioteca::info_cita(string referencia) {

}

void const Biblioteca::totes_cites() {
	for (map<string,Text>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {

    }
}

void Biblioteca::eliminar_cita(string referencia) {
	//map<string, Text>::const_iterator i = find(ttriat.autor_text());
    conjunt_cites.erase(ttriat.autor_text());
}*/
