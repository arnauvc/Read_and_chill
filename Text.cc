#include "Text.hh"

Text::Text(){
    numfrases = 0;
    numparaules = 0;
}

Text::~Text(){

}

int const Text::consultar_numfrases(){
    return numfrases;
}

int const Text::consultar_numparaules(){
    return numparaules;
}

string const Text::titol_text(){
    return titol;
}

string const Text::autor_text(){
   return autor;
}

void const Text::info_text(){//aquesta funcio no retorna les cites associades al text
   cout << autor << " " << titol << " " << numfrases << " " << numparaules << endl;
}

void const Text::contingut_text(){
    for(map<int,Frase>::const_iterator i=contingut.begin(); i != contingut.end(); ++i){
        cout << (i->first) << " ";
        Frase f = i->second;
        f.escriu_frase();
    }
}

map<int,Frase> const Text::interval_frases(int x, int y){
    map<int,Frase> m;
    map<int,Frase>::const_iterator j;
    if( x>y or x>contingut.size() or y>contingut.size() or contingut.empty() ){
        cout << "error del interval" <<endl;
    }
    else{
        for(int i = x; i <= y; ++i){
            map<int,Frase>::const_iterator j = contingut.find(i);
            m.insert(make_pair(j->first,j->second));
        }
        return m;
    }
}

void const Text::paraules_frase(string s1){ //ara per ara, funciona amb la funcio TROBAT !!!
    //
    istringstream iss(s1);
    ws(iss);
    string op;
    iss >> op;
    set<int> s = tau.frases_paraula(op);
    for(set<int>::const_iterator j = s.begin(); j != s.end(); ++j){
        map<int,Frase>::const_iterator i = contingut.find(*j);
        Frase f = i->second;
        if(f.trobat(s1)) {
            cout << i->first << " ";
            f.escriu_frase();
        }
    }
}

bool const Text::buscar_paraules(string s) {
	return tau.existeix_cadena(s);
}

void Text::substitueix_paraules(string s1, string s2){
    tau.intercanviar(s1,s2);
    for(map<int,Frase>::iterator i = contingut.begin(); i != contingut.end(); ++i){
        i->second.canvi_paraules(s1,s2);
    }
}

void const Text::expressio_frases(string s1){//portara feina
    int j;
    for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i) {
        Frase f = i->second;
        j = 0;
        if (/*compleix_expressio(s1, j)*/ true) {
            f.escriu_frase();
        }
    }
}

void const Text::taula_frequencies(){
    tau.taula_frequencies();
}

void Text::llegir_text(string ti){
    int a = 1;
    string line, op;
    titol = ti;
    string tmp;
    getline(cin, tmp);
    
    string::size_type i = tmp.find("autor");
    if (i != string::npos) tmp.erase(0,6);
    tmp.erase(tmp.begin(), tmp.begin()+1);
    tmp.erase(tmp.size()-1, tmp.size());
    autor = tmp;
    getline(cin, line);
    bool pam = false;
    int l;
    string aux;
    bool primer = true;
    string vamos;
    bool yeah = true;
    bool superprimer = true;
    while(line != "****") {
        istringstream iss(line);
        yeah = false;
        while(not yeah) {
        pam = false;
        while ((iss >> op and not pam) or primer) {
            vamos = op;
            l = op.size();
            if ((char(op[l-1]) == '.') or (char(op[l-1]) == '?') or (char(op[l-1]) == '!')) {
                pam = true;     
            }
            if (primer) {
                 primer = false;
                if (char(op[0]) >= 'a' and char(op[0]) <= 'z') {
                    aux += " "; 
                    aux += op;
                }
                if (superprimer) {
                    aux = op;
                    superprimer = false;
                }
            }
            else {
                aux += " ";
                aux += op;
            }
        }
        if (pam) {
            Frase fr;
            fr.llegir_frase(aux, tau, a);
            contingut.insert(make_pair(a, fr));
            ++a;
            ++numfrases;
            numparaules += fr.consultar_numparaules();
            aux.clear();
        }
        if (op == vamos) { 
             getline(cin, line);
             yeah = true;
        }
        else {
            yeah = false;
            aux += op;
            primer = true;
        }
        }
    }
    tau.ordenar_taulafreq();
}
//....................................................................................................................
// Retorna true si el paràmetre implicit compleix l'expressio exp, fals altrament
// "exp" es l'expressió, "i" és la posició de l'element actual (comencem a 0, primer element de exp)
/*bool Tasca::compleix_expressio(const string &exp, int &i) {
    if (exp[i]!='(') {  //Si l'element no es un parentesi, l'analitzem
        string e;   //Si es una etiqueta, es guardara a "e"
        while (exp[i]!='|' and exp[i]!='&' and exp[i]!=')') { //Si es una etiqueta (no es '&' o ',' o ')') la guardem
                                      // a "e" i avancem posicions (i) fins trobar un caracter
                                      // que no pertanyi a l'etiqueta ('.' o ',' o ')')
            e.push_back(exp[i]);    // fem push_back per afegir la nova lletra al final del string "e"
            ++i;            //avançem posicio
        }
        return (conte_etiqueta_simple(e)); //Utilitzem la funcio per saber si la tasca conte l'etiqueta "e",
                           // retorna fals si no.
    } else { // Si es un parentesi '(', es el principi d'una expressio booleana
        ++i;  //Avancem una posicio, podrem trobar un altre parentesi (una altre expressio) o una etiqueta
        bool r1 = compleix_expressio(exp,i);  //retorna cert si es una etiqueta i aquesta pertany a la tasca,
                              // fals altrament. Si no es una etiqueta, retorna cert si la següent
                              // expressió trobada es certa.
        char c = exp[i];    // c=element actual, element que va despres de l'etiqueta trobada a la
                    // linia anterior. Nomes pot ser "&" o ",".
        ++i;            // Avancem una posicio, hem de trobar nova etiqueta o un parentesi (nova expressio)
        bool r2 = compleix_expressio(exp,i); //retorna cert si es una etiqueta i aquesta pertany a la tasca,
                             // fals altrament. Si no es una etiqueta retorna cert si la següent
                             // expressió trobada es certa.
        ++i;            //Avancem una posicio, per que "i" retorni el valor adequat (sempre
                    // una posicio despres de l'element analitzat en aquesta iteracio).
        if (c=='&') {       // Haviem guardat "&" o "," a "c".
            return (r1 and r2); //Si es "&" es un and, retorna true si es compleix
        } else {
            return (r1 or r2);  //Si es "|" es un or, retorna true si es compleix
        }
    }
}*/
