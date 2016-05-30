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
    for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i){
        cout << i->first << " ";
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
    insec = s;
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
}

bool Text::buscar_paraules(const string s) const {
	return tau.existeix_cadena(s);
}

void Text::substitueix_paraules(string s1, string s2){ ////////////////// 
    set<int> s = tau.frases_paraula(s1);
    set<int>::const_iterator j = s.begin();
    if (j != s.end()) {
         if(*j != -1){
            tau.intercanviar(s1,s2);
            for(j = s.begin(); j != s.end(); ++j){
                map<int,Frase>::iterator i = contingut.find(*j);
                if(i != contingut.end()){
                    i->second.canvi_paraules(s1,s2);
                    
                }
            }
        }
    }
}

void Text::expressio_frases(string s1, bool expp){
    for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i) {
        Frase f = i->second;
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
    list<string> frase_in;
    list<string>::iterator it = frase_in.begin();
    int a = 1;
    string line, op;
    titol = ti;
    autor = autorr;
    getline(cin, line);
    int l;
    istringstream ass(line);
    ass >> op;
    while(op != "****") {
		istringstream iss(line);
		while (iss >> op) {
                l = op.size(); 
				if (char(op[l-1]) == '.' or char(op[l-1]) == '?' or char(op[l-1]) == '!') {
                    if (l == 1) frase_in.insert(it, op);
                    else {
                        char car = op[l-1];
                        string c;
                        if (car == '.') c = ".";
                        else if (car == '?') c = "?";
                        else c = "!";
                        op.erase(l-1);
                        frase_in.insert(it, op);
                        tau.insertar_paraula(op, a);
                        frase_in.insert(it, c);
                        ++numparaules;
                    }
                    Frase fr;
                    fr.llegir_frase(frase_in);
                    contingut.insert(make_pair(a, fr));
                    ++a;
                    ++numfrases;
                    frase_in.clear();
                    it = frase_in.begin();
                }
                else {
                    if (char(op[l-1]) == ',' or char(op[l-1]) == ':' or char(op[l-1]) == ';') {
                        if (l == 1) frase_in.insert(it, op);
                        else {
                            string tmp = op;
                            op.erase(l-1);
                            frase_in.insert(it, op);
                            tau.insertar_paraula(op, a);
                            string c;
                            char car = tmp[l-1];
                            if (car == ',') c = ",";
                            else if (car == ':') c = ":";
                            else c = ";";
                            frase_in.insert(it, c);
                            ++numparaules;
                        }
                    }
                    else {
                        frase_in.insert(it, op);
                        tau.insertar_paraula(op, a);
                        ++numparaules;
                    }
                }
        }
		getline(cin, line);
        istringstream ess(line);
        ess >> op;
    }
    tau.ordenar_taulafreq();
}

