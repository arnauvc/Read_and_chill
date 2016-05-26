#include "Text.hh"

Text::Text(){
    numfrases = 0;
    numparaules = 0;
}

Text::~Text(){

}

int Text::consultar_numfrases() const{
    return numfrases;
}

int Text::consultar_numparaules() const {
    return numparaules;
}

string Text::titol_text() const {
    return titol;
}

string Text::autor_text() const{
   return autor;
}

void Text::info_text() const{
   cout << autor << " " << "\"" << titol << "\"" << " " << numfrases << " " << numparaules << endl;
}

void Text::contingut_text() const{
    for(map<int,Frase>::const_iterator i=contingut.begin(); i != contingut.end(); ++i){
        cout << i->first << " ";
        //Frase f = i->second;
        i->second.escriu_frase();
    }
}

map<int,Frase> Text::interval_frases(int x, int y, bool &b){
    map<int,Frase> m;
    map<int,Frase>::const_iterator j;
    if((x < 1) or (y > contingut.size()) or (x > y)) {
        cout << "error" << endl;
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
    
    istringstream iss(s1);
    string op, temp;
    iss >> op;
    set<int> s,m,insec;
    temp = op;
    s = tau.frases_paraula(op);
    
    while(iss >> op){
        
        set<int>::iterator j = s.begin();
        if(not s.empty() and *j != -1){
            set<int> m = tau.frases_paraula(op);
            set<int>::const_iterator k = m.begin();
            if(not m.empty() and *k != -1){
                insec.clear();
                set_intersection(s.begin(), s.end(), m.begin(), m.end(), inserter(insec, insec.begin() ) );
                s = insec;
            }
        }
    }
    
    set<int>::const_iterator j = insec.begin();
    if (j != insec.end()) {
        if(*j != -1){
            for(j = insec.begin(); j != insec.end(); ++j){
                map<int,Frase>::const_iterator i = contingut.find(*j);
                if(i != contingut.end()){
                    if(i->second.trobat(s1)) {
                        cout << i->first << " ";
                        i->second.escriu_frase();
                    }
                }
            }
        }
    }
    
    /*
    
    istringstream iss(s1);
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
    
    */
    
}

bool Text::buscar_paraules(const string s) const {
	return tau.existeix_cadena(s);
}

bool Text::substitueix_paraules(string s1, string s2){ //////////////////
    /*
    bool p = false;
    bool m = false;
    p =tau.intercanviar(s1,s2);
    for(map<int,Frase>::iterator i = contingut.begin(); i != contingut.end(); ++i){//FLIPO!!!!! AMB LENVIAMENT DE LA FRASE AMB f.()....WA JUTGE!
        bool s = i->second.canvi_paraules(s1,s2);
        if(!m and s) m = true;
    }
    if(p and m) return true;
    */
    
    bool p = false;
    bool m = false;
    
    set<int> s = tau.frases_paraula(s1);
    set<int>::const_iterator j = s.begin();
    p = tau.intercanviar(s1,s2);
    
    if (j != s.end()) {
         if(*j != -1){
            for(j = s.begin(); j != s.end(); ++j){
                map<int,Frase>::iterator i = contingut.find(*j);
                if(i != contingut.end()){
                    bool s = i->second.canvi_paraules(s1,s2);
                    if(!m and s) m = true;
                }
            }
            if(p and m) return true;
        }
    }
    return false;
    
}

void Text::expressio_frases(string s1, bool expp){//portara feina
    for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i) {
        Frase f = i->second;//NO DEIXA TREURE LA COPIA A CAUSA DE LA FUNCIO COMPLEIX EXPRESIO!!!!!!!!!!!!!!!!!!!!
        int j = 0;
        if (compleix_expressio(s1, j, f, expp)) {
            cout << i->first << " ";
            i->second.escriu_frase();
        }
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
    istringstream ass(line);
    ass >> op;
    while(op != "****") {//no sha acabat el text
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
            istringstream ess(line);
            ess >> op;
    }
    tau.ordenar_taulafreq();
}

