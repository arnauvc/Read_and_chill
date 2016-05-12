#include "Biblioteca.hh"
#include "Text.hh"
#include "Frase.hh"
#include <algorithm>

Biblioteca::Biblioteca(){
    triat = false;
}

Biblioteca::~Biblioteca(){
    
}

Text const Biblioteca::triar_text(string s /*,bool &b*/){
	cout << "B" <<endl;
	for (map<string,Text>::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end(); ++i) {
		Text t = i->second;
		cout << "0" << endl;
		if (t.buscar_paraules(s)) {
			cout << "1" << endl;
			ttriat = i->second;
			triat = true;
			//b = true;
			return ttriat;
		}
	}
	if (not triat) cout << "error0" << endl;
	//b = false;
	return ttriat;
}

bool const Biblioteca::consultar_triat(){
    return triat;
}

void const Biblioteca::tots_textos(){
	Text t;
	string s;
    for (map<string,Text>::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end(); ++i) {
    	t = i->second;
    	s = i->first;
    	cout << s << " " << t.titol_text() << endl;
    }
    
}

void const Biblioteca::textos_autor(string s){
	vector<string> titols_autor;
	Text t;
    for (map<string,Text>::const_iterator i = conjunt_textos.begin(); i != conjunt_textos.end(); ++i) {
    	if (i->first == s) {
    		t = i->second;
    		titols_autor.push_back(t.titol_text());
    	}
    }
    sort(titols_autor.begin(), titols_autor.end(), comp_titols);
    for (int i = 0; i < titols_autor.size(); ++i) {
    	cout << titols_autor[i] << endl;
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

void Biblioteca::afegir_text(){
    Text t;
	
    t.llegir_text();
	
    string s = t.autor_text();
    conjunt_textos.insert(make_pair(s, t));
	
    //hem de buscar que no hi hagi cap autor amb el mateix titol que el nou text afegit sino error 
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


		
