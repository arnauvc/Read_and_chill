#include "Biblioteca.hh"
#include "Text.hh"
#include "Frase.hh"

Biblioteca::Biblioteca(){
    triat = false;
    ncites = 1;
}

Biblioteca::~Biblioteca(){
    
}

Text Biblioteca::triar_text(string s){
	triat = false;
	string op, op1;
	string aux = s;
	int count = 0;
	istringstream ass(s);
	while (ass >> op) ++count;//contador de cuantes paraules hem de tractar en total
	int auxcount = count;
	bool primer,segon,tr,tr1,final = false;
       for (map<string, map<string, Text> >::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end() and not segon and not tr1; ++i) {
		tr = false;
		primer = false;
		s = aux;
		count = auxcount;
		map<string, Text> k = i->second;
		istringstream iss(s);
		for (map<string, Text>::const_iterator j = k.begin(); j != k.end() and not segon and not tr1; ++j) {
            //primer = false;
			Text t = j->second;
            while (iss >> op) {
            	//cout << "0" << endl;
            	istringstream oss(i->first);
            	while (oss >> op1) { //bucle per buscar paraules a l'autor
            		//cout << "aut " << "op: " << op << " " << "op1: " << op1 << endl;
            		if (op == op1) {
            			//cout << "encontrado en autor" << endl;
            			string::size_type i = s.find(op);
            			if (i != string::npos){
				            s.erase(0, i+op.length()+1);
			            }
			            --count;
            		}
            	}
            	istringstream ess(j->first);
            	while (ess >> op1) { //bucle per buscar paraules al titol
            		//cout << "tit " << "op: " << op << " " << "op1: " << op1 << endl;
            		if (op == op1) {
            			//cout << "encontrado en titulo" << endl;
            			string::size_type i = s.find(op);
            			if (i != string::npos){
				            s.erase(0, i+op.length()+1);
			            }
			            --count;
            		}
            	}
            }           
			if (count > 0) {//si falten paraules per trobar, si aixo es 0 es que s'ha trobat totes les paraules entre el titol i l'autor
				//cout << "1" << endl;
			    //cout << "super important string s recortado: " << s << endl;
				if (t.buscar_paraules(s)) {
					ttriat = j->second;
					if (not segon and primer) {//segon text que cumpleix la condicio
						segon = true;
						//cout << "encontrado en contenido segunda vez" << endl;
				    }
					if(not primer) {//primer text que compleix la condicio
						primer = true;
						final = true;
						//cout << "encontrado en contenido primera vez" << endl;
				    }
				}
		    }
		    else {
		    	if (tr and not tr1) {//segon text que es cumpleix per titol i autor
		        	tr1 = true;
		        	//cout << "encontrado en titulo i autor todo segunda vez" << endl;
		        }
		    	if(not tr) {//primer text que es cumpleix per titol i autor
		    	    triat = true;
		    		ttriat = j->second;
		    		tr = true;
		    		//cout << "encontrado en titulo i autor todo primera vez" << endl;
		        }
		    }
		}
	}
	if ((primer and not segon and not tr1) or (not primer and tr and not tr1) or (final and not primer)) {
		triat = true;
		//cout << "yeah men!" << endl;
		return ttriat;
	}
	if (not triat) cout << "error" << endl;
	return ttriat;
}

bool Biblioteca::consultar_triat(){
    return triat;
}

void Biblioteca::tots_textos(){
	Text t;
    for (map<string, map<string, Text> >::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end(); ++i) {
    	map<string, Text> k = i->second;
    	for (map<string, Text>::const_iterator j = k.begin(); j != k.end(); ++j) {
			t = j->second;
    		cout << t.autor_text() << " " << "\"" << t.titol_text() << "\"" << endl;
    	}
    }
}

void Biblioteca::textos_autor(string s){
	map<string, map<string, Text> >::const_iterator i = conjunt_textos.find(s);
	if(i != conjunt_textos.end()){
        map<string, Text> k = i->second;
        for (map<string, Text>::const_iterator j = k.begin(); j != k.end(); ++j) {
            cout << "\"" << j->first << "\"" << endl;
        }
    }
}

void Biblioteca::tots_autors(){
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
	bool es;
    Text t;
    t.llegir_text(op);
    string s = t.autor_text();
    string ti = t.titol_text();
    map<string, map<string, Text> >::iterator i = conjunt_textos.find(s);
    if (i == conjunt_textos.end()) {
    	map<string, Text> u;
    	u.insert(make_pair(ti, t));
    	conjunt_textos.insert(make_pair(s, u));
    	es = false;
    }
    else {
    	map<string, Text> h;
    	h = i->second;
    	map<string, Text>::iterator j = h.find(ti);
    	if (j == h.end()) {
    		i->second.insert(make_pair(ti, t));
    		es = false;
        }
        else { 
        	es = true;
        	cout << "error" << endl;
        }
    }
    if (not es) {
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
}

void Biblioteca::eliminar_text(){
	map<string, map<string, Text> >::iterator i = conjunt_textos.find(ttriat.autor_text());
    map<string, Text>::iterator j = i->second.find(ttriat.titol_text());
    if(i != conjunt_textos.end() && j != i->second.end() ){
        if(i->second.size() == 1 && j->first == ttriat.titol_text()){
            conjunt_textos.erase(ttriat.autor_text());
            triat = false;
        }
        else{
            i->second.erase(ttriat.titol_text());
            triat = false;
        }
    }
    map<string, infoautor>::iterator k = conjunt_autors.find(ttriat.autor_text());
    if(k != conjunt_autors.end()){
        if(k->second.ntextos == 1) conjunt_autors.erase(ttriat.autor_text());
        else{
            --k->second.ntextos;
            k->second.nfrases -= ttriat.consultar_numfrases();
            k->second.nparaules -= ttriat.consultar_numparaules();
        }
    } 
}

void Biblioteca::afegir_cita(int x, int y){
	//2 o 3 incials y despres el numero! per la referencia!
	bool si = true;
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
        bool nec = true;//Aquest bool no afecta a la funcio afegir_cita, pero fa falta per mi
  	    k.contingutcita = ttriat.interval_frases(x, y, nec);
	}
	else {
		while (i != conjunt_cites.end()) {
            infocita e = i->second;
            if (e.firstfrase == x and e.lastfrase == y and e.aut == autor and e.tit == titol) si = false;
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
		if(si) {
			k.firstfrase = x;
   	        k.lastfrase = y;
			k.aut = autor;
			k.tit = titol;
            bool nec = true;//Aquest bool no afecta a la funcio afegir_cita, pero fa falta per mi
  	        k.contingutcita = ttriat.interval_frases(x, y, nec);
  	    }
	}
	if(si) {
        cout << "insereix la cita nova" <<endl;
        conjunt_cites.insert(make_pair(refe, k));
    }
	else cout << "error" << endl;
}

void Biblioteca::cites_autor(string autor) {
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		if (autor == i->second.aut) {
			cout << i->first << endl;
			for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				Frase fr = j->second;
				cout << j->first << " "; 
				fr.escriu_frase();
			}
			cout << i->second.aut << " " << "\"" << i->second.tit << "\"" << endl;
		}
    }
}

void Biblioteca::info_cita(string referencia) {
	map<string,infocita>::const_iterator i = conjunt_cites.find(referencia);
	if (i != conjunt_cites.end()){
		cout << i->second.aut << " " << "\"" << i->second.tit << "\"" << endl; 
		cout << i->second.firstfrase << "-" << i->second.lastfrase << endl;
		for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				Frase fr = j->second;
				cout << j->first << " "; 
				fr.escriu_frase();
		}
    }
    else cout << "error" << endl;
}

void Biblioteca::totes_cites() {
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		cout << i->first << endl;
		for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				Frase fr = j->second;
				cout << j->first << " "; 
				fr.escriu_frase();
		}
		cout << i->second.aut << " " << "\"" << i->second.tit << "\"" << endl;
    }
}

void Biblioteca::cites_text(bool b) {
	if(b) cout << "Cites Associades:" << endl;
	string titol = ttriat.titol_text();
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		if(i->second.tit == titol) {
			cout << i->first << endl;
			for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
					Frase fr = j->second;
					cout << j->first << " "; 
					fr.escriu_frase();
			}
			if(not b) cout << i->second.aut << " " << "\"" << i->second.tit << "\"" << endl;
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
