#include "Text.hh"

Text::Text(){
    numfrases = 0;
    numparaules = 0;
}

Text::~Text(){

}

int Text::consultar_numfrases(){
    return numfrases;
}

int Text::consultar_numparaules(){
    return numparaules;
}

string Text::titol_text(){
    return titol;
}

string Text::autor_text(){
   return autor;
}

void Text::info_text(){
   cout << autor << " " << "\"" << titol << "\"" << " " << numfrases << " " << numparaules << endl;
}

void Text::contingut_text(){
    for(map<int,Frase>::const_iterator i=contingut.begin(); i != contingut.end(); ++i){
        cout << (i->first) << " ";
        Frase f = i->second;
        f.escriu_frase();
    }
}

map<int,Frase> Text::interval_frases(int x, int y, bool &b){
    map<int,Frase> m;
    map<int,Frase>::const_iterator j;
    if( x>y or x>contingut.size() or y>contingut.size() or contingut.empty() ){
        cout << "error" <<endl;
        b = false;
        return m;
    }
    else{
        for(int i = x; i <= y; ++i){
            map<int,Frase>::const_iterator j = contingut.find(i);
            m.insert(make_pair(j->first,j->second));
        }
        b = true;
        return m;
    }
}

void Text::paraules_frase(string s1){ //ara per ara, funciona amb la funcio TROBAT !!!
    //
    istringstream iss(s1);
    ws(iss);
    string op;
    iss >> op;
    set<int> s = tau.frases_paraula(op);
    set<int>::const_iterator j = s.begin();
    if (j != s.end()) {
        if(*j != -1){
            for(j = s.begin(); j != s.end(); ++j){
                map<int,Frase>::const_iterator i = contingut.find(*j);
                if(i != contingut.end()){
                    Frase f = i->second;
                    if(f.trobat(s1)) {
                        cout << i->first << " ";
                        f.escriu_frase();
                    }
                }
            }
        }
    }
}

bool Text::buscar_paraules(string s) {
	return tau.existeix_cadena(s);
}

void Text::substitueix_paraules(string s1, string s2){
    tau.intercanviar(s1,s2);
    for(map<int,Frase>::iterator i = contingut.begin(); i != contingut.end(); ++i){
        i->second.canvi_paraules(s1,s2);
    }
    
}

void Text::expressio_frases(string s1){//portara feina
    for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i) {
        Frase f = i->second;
        int j = 0;
        if (compleix_expressio(s1, j, f)) {
            cout << i->first << " ";
            f.escriu_frase();
        }
        //cout << s1;
    }
}

void Text::taula_frequencies(){
    tau.taula_frequencies();
}

void Text::llegir_text(string ti, string autorr){
    int a = 1;
    string line, op;
    titol = ti;
    autor = autorr;
    getline(cin, line);
    bool pam = false;
    int l;
    string aux;
	bool juntar = false;
    bool primer = true;
    while(line != "****") {//no sha acabat el text
		istringstream iss(line);//agafa linia nova
		while (iss >> op) {
				l = op.size();
				if ((char(op[l-1]) == '.') or (char(op[l-1]) == '?') or (char(op[l-1]) == '!')) {//sacaba una frase!
					pam = true; 
					if (op == "." or op == "?"  or op == "!") {
						juntar = true;
					}   
				}
				if (primer) {
					primer = false;
					aux = op;
				}
				else {
					if (juntar) {
						aux += op;
						juntar = false;
					}
					else {
						if (op == "," or op == ":"  or op == ";") aux += op;
						else {
							aux += " ";
					        aux += op;
						}
					}
				}
				if (pam) { //HA ACABAT LA FRASE!!!
					Frase fr;
					fr.llegir_frase(aux, tau, a);
					contingut.insert(make_pair(a, fr));
					++a;
					++numfrases;
					numparaules += fr.consultar_numparaules();
					aux.clear();
					primer = true;
					pam = false;
			    }
		}
			getline(cin, line);
		
    }
    tau.ordenar_taulafreq();
}

