#include "Biblioteca.hh"
#include "Text.hh"
#include "Frase.hh"

Biblioteca::Biblioteca(){
    triat = false;
}

Biblioteca::~Biblioteca(){
    
}

Text const Biblioteca::triar_text(string s){
	for (map<string,Text>::const_iterator i = conjunt_textos.begin(); i < conjunt_textos.end(); ++i) {
		if (i->second.buscar_paraules(s)) {
			ttriat = i->second;
			triat = true;
			return ttriat;
		}
	}
	if (not triat) cout << "error" << endl;
}

bool const Biblioteca::consultar_triat(){
    return triat;
}

void const Biblioteca::tots_textos(){
    
}

void const Biblioteca::textos_autor(){
    
}

void const Biblioteca::tots_autors(){
	//RAPID!
}

void Biblioteca::afegir_text(){
    Text t;
    t.llegir_text();
    string s = t.autor_text();
    conjunt_textos.insert(s, t);
    //hem de buscar que no hi hagi cap autor amb el mateix titol que el nou text afegit sino error 
}

void Biblioteca::afegir_cita(int x, int y){
	/*
	char first, last;
	first = cin.get();     // get one character
	cin.ignore(256,' ');   // ignore until space
	last = cin.get();      // get one character
	*/
}

void Biblioteca::eliminar_text(){
    //map<string, Text>::const_iterator i = find(ttriat.autor_text());
    conjunt_textos.erase(ttriat.autor_text());
    triat = false;
}
