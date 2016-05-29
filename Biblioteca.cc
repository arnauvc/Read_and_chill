#include "Biblioteca.hh"
#include "Text.hh"
#include "Frase.hh"

Biblioteca::Biblioteca(){
    triat = false;
    ncites = 1;
    textsiafegit = false;
}

Biblioteca::~Biblioteca(){}

Text Biblioteca::triar_text(string s, Text texttriat){
	triat = false;
	string op, op1;
	string aux = s;
	int count = 0;
	int veg = 0;
	int l;
	istringstream ass(s);
	while (ass >> op) ++count;
	int auxcount = count;
       for (map<string, map<string, Text> >::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end() and veg < 2; ++i) {
		for (map<string, Text>::const_iterator j = i->second.begin(); j != i->second.end() and veg < 2; ++j) {
            s = aux;
            count = auxcount;
            istringstream iss(s);
            while (iss >> op) {
            	istringstream oss(i->first);
            	while (oss >> op1) {
            		if (op == op1) {
            			string::size_type i = s.find(op);
            			if (i != string::npos){
				            s.erase(i, i+op.length());
							--count;
			            }
            		}
            	}
            	istringstream ess(j->first);
            	while (ess >> op1) {
            		l = op1.size();
            		if (char(op1[l-1]) == '.' or char(op1[l-1]) == '?' or char(op1[l-1]) == '!' or char(op1[l-1]) == ',' or char(op1[l-1]) == ';' or char(op1[l-1]) == ':') {
            			op1.erase(l-1, l-1);
            		}
            		if (op == op1) {
            			string::size_type i = s.find(op);
            			if (i != string::npos){
				            s.erase(i, i+op.length());
							//iss >> op;
							--count;
			            }
            		}
            	}
            } 
			if (count > 0) {
				if (j->second.buscar_paraules(s)) {
					ttriat = j->second;
					++veg;
				}
		    }
		    else {
		    	ttriat = j->second;
		    	++veg;
		    }
		}
	}
	if (veg == 1) {
		triat = true;
		return ttriat;
	}
	else cout << "error" << endl;
	return ttriat;
}

bool Biblioteca::consultar_triat(){
    return triat;
}

void Biblioteca::tots_textos(){
    for (map<string, map<string, Text> >::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end(); ++i) {
    	for (map<string, Text>::const_iterator j = i->second.begin(); j != i->second.end(); ++j) {
    		cout << j->second.autor_text() << " " << "\"" << j->second.titol_text() << "\"" << endl;
    	}
    }
}

void Biblioteca::textos_autor(string s){
	map<string, map<string, Text> >::const_iterator i = conjunt_textos.find(s);
	if(i != conjunt_textos.end()){
        for (map<string, Text>::const_iterator j = i->second.begin(); j != i->second.end(); ++j) {
            cout << "\"" << j->first << "\"" << endl;
        }
    }
}

void Biblioteca::tots_autors(){
	for (map<string, infoautor>::const_iterator i = conjunt_autors.begin(); i != conjunt_autors.end(); ++i) {
		cout << i->first << " " << i->second.ntextos << " ";
		cout << i->second.nfrases << " " << i->second.nparaules << endl;
    }
}

void Biblioteca::afegir_text(string op){
	bool es;
    Text t;
    string tmp, aux1,op2;
    getline(cin, tmp);
    int l;
    istringstream oss(tmp);
    oss >> op2;
    oss >> op2;
    l = op2.size();
    bool ppprimer = true;
    if ((char(op2[0]) == '"') and (l != 1) and (char(op2[l-1]) == '"')) {
    	op2.erase(0, 1);
        l = op2.size();
    	op2.erase(l-1, l-1);
    	aux1 += op2;
    	ppprimer = false;
    }
    else if ((char(op2[0]) == '"') and (l != 1)) {
    	op2.erase(0, 1);
    	aux1 += op2;
    	ppprimer = false;
    }
    while (oss >> op2) {
    	l = op2.size();
    	if ((char(op2[l-1]) == '"') and (l != 1)) {
    		if (ppprimer) {
    			op2.erase(l-1, l-1);
    			aux1 += op2;
    			ppprimer = false;
    		}
    		else {
    			op2.erase(l-1, l-1);
    			aux1 += " ";
    			aux1 += op2;
    		}
    	}
    	else {
    		if (char(op2[l-1]) != '"') {
    			if (ppprimer) {
    				aux1 += op2;
    				ppprimer = false;
    			}
    			else {
    				aux1 += " ";
    				aux1 += op2;
    			}
    	    }
        }
    }
    string ti = op;
    string s = aux1;
    map<string, map<string, Text> >::iterator i = conjunt_textos.find(s);
    if (i == conjunt_textos.end()) {
    	t.llegir_text(ti, s);
    	textsiafegit = true;
    	map<string, Text> u;
    	u.insert(make_pair(ti, t));
    	conjunt_textos.insert(make_pair(s, u));
    	es = false;
    }
    else {
    	map<string, Text>::iterator j = i->second.find(ti);
    	if (j == i->second.end()) {
    		t.llegir_text(ti, s);
    		textsiafegit = true;
    		i->second.insert(make_pair(ti, t));
    		es = false;
        }
        else { 
        	es = true;
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

 bool Biblioteca::text_si_afegit() {
 	if (textsiafegit) {
 		textsiafegit = false;
 		return true;
 	}
 	return false;
 }

void Biblioteca::eliminar_text(){
	map<string, map<string, Text> >::iterator i = conjunt_textos.find(ttriat.autor_text());
    map<string, Text>::iterator j = i->second.find(ttriat.titol_text());
    if(i != conjunt_textos.end() and j != i->second.end() ){
        if(i->second.size() < 2 and j->first == ttriat.titol_text()){
            conjunt_textos.erase(i);
            triat = false;
        }
        else{
            i->second.erase(j);
            triat = false;
        }
    }
    map<string, infoautor>::iterator k = conjunt_autors.find(ttriat.autor_text());
    if(k != conjunt_autors.end()){
        if(k->second.ntextos == 1) conjunt_autors.erase(k);
        else{
            k->second.ntextos = k->second.ntextos - 1;
            k->second.nfrases -= ttriat.consultar_numfrases();
            k->second.nparaules -= ttriat.consultar_numparaules();
        }
    }
    triat = false; 
}

void Biblioteca::afegir_cita(int x, int y){
	int espotafegir = ttriat.consultar_numfrases();
	bool trobat1 = false;
	bool si = true;
	bool finjeje = true;
	if (x >= 1 and y <= espotafegir and x <= y) {
    char c;
	finjeje = false;
	string autor = ttriat.autor_text();
	string titol = ttriat.titol_text();
	string refe;
	int numref;
	int auxnum = 0;
	infocita k, e;
	string op;
	istringstream iss(autor);
	while (iss >> op) {
        if (('a' <= char(op[0])) and (char(op[0]) <= 'z')) {
            c = char(op[0]);
            c = 'A' + (c - 'a');
            refe += c;
        }
		else refe += char(op[0]);
	}
	map<string,int>::iterator f = freqrefe.find(refe);
	map<string,infocita>::iterator i;
	if (f != freqrefe.end()) {
		numref = f->second + 1;
		trobat1 = true;
		while (auxnum < numref and si) {
			++auxnum;
			op.clear();
		    refe.clear();
			istringstream ass(autor);
		    while (ass >> op) {
		        if (('a' <= char(op[0])) and (char(op[0]) <= 'z')) {
                    c = char(op[0]);
                    c = 'A' + (c - 'a');
                    refe += c;
                }
                else refe += char(op[0]);
	        }
			string Result;
			stringstream convert;
			convert << auxnum;
			Result = convert.str();
			refe += Result;
			i = conjunt_cites.find(refe);
            if (i != conjunt_cites.end()) {
            	e = i->second;
                if (e.firstfrase == x and e.lastfrase == y and e.aut == autor and e.tit == titol) si = false;
			}
		}
		if (si) f->second = numref;
	}
	else {
		freqrefe.insert(make_pair(refe, 1));
	}
	if (not trobat1) numref = 1;
	if(si) {
		op.clear();
		refe.clear();
		istringstream ess(autor);
		while (ess >> op) {
		    if (('a' <= char(op[0])) and (char(op[0]) <= 'z')) {
                c = char(op[0]);
                c = 'A' + (c - 'a');
                refe += c;
            }
            else refe += char(op[0]);
	    }
		string Result;
		stringstream convert;
		convert << numref;
		Result = convert.str();
		refe += Result;
		k.firstfrase = x;
   	    k.lastfrase = y;
		k.aut = autor;
		k.tit = titol;
        bool nec = true;//Aquest bool no afecta a la funcio afegir_cita, pero fa falta per mi
  	    k.contingutcita = ttriat.interval_frases(x, y, nec);
  	    if (nec) conjunt_cites.insert(make_pair(refe, k));
  	}
    }
    if (not si or finjeje) cout << "error" << endl;
}

void Biblioteca::cites_autor(string autor) {
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		if (autor == i->second.aut) {
			cout << i->first << endl;
			for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				//Frase fr = j->second;
				cout << j->first << " "; 
				j->second.escriu_frase();
			}
			cout << "\"" << i->second.tit << "\"" << endl;
		}
    }
}

void Biblioteca::info_cita(string referencia) {
	map<string,infocita>::const_iterator i = conjunt_cites.find(referencia);
	if (i != conjunt_cites.end()){
		cout << i->second.aut << " " << "\"" << i->second.tit << "\"" << endl; 
		cout << i->second.firstfrase << "-" << i->second.lastfrase << endl;
		for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				cout << j->first << " "; 
				j->second.escriu_frase();
		}
    }
    else cout << "error" << endl;
}

void Biblioteca::actualitzar_text(Text texttriat){
    if(triat){
        map<string, map<string, Text > >::iterator i = conjunt_textos.find(ttriat.autor_text());
        if(i != conjunt_textos.end()){
            map<string, Text>::iterator j = i->second.find(ttriat.titol_text());
            if(j != i->second.end()){
                j->second = texttriat;
            }
        }
    }
}

void Biblioteca::totes_cites() {
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		cout << i->first << endl;
		for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
				cout << j->first << " "; 
				j->second.escriu_frase();
		}
		cout << i->second.aut << " " << "\"" << i->second.tit << "\"" << endl;
    }
}

void Biblioteca::cites_text(bool b) {
	if (b) cout << "Cites Associades:" << endl;
	string titol = ttriat.titol_text();
    string autor = ttriat.autor_text();
	for (map<string,infocita>::const_iterator i = conjunt_cites.begin(); i != conjunt_cites.end(); ++i) {
		if((i->second.tit == titol) and (i->second.aut == autor)) {
			cout << i->first << endl;
			for (map<int,Frase>::const_iterator j = i->second.contingutcita.begin(); j != i->second.contingutcita.end(); ++j) {
					cout << j->first << " "; 
					j->second.escriu_frase();
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
