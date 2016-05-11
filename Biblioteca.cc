#include "Biblioteca.hh"
#include "Text.hh"
#include "Frase.hh"

Biblioteca::Biblioteca(){
    triat = false;
}

Biblioteca::~Biblioteca(){
    
}

Text Biblioteca::triar_text(){
    
}

bool const Biblioteca::consultar_triat(){
    return triat;
}

void Biblioteca::tots_textos(){
    
}

void Biblioteca::textos_autor(){
    
}

void Biblioteca::tots_autors(){

}

void Biblioteca::afegir_text(){
    
}

void Biblioteca::afegir_cita(int x, int y){
	char first, last;
	first = cin.get();     // get one character
	cin.ignore(256,' ');   // ignore until space
	last = cin.get();      // get one character

}

void Biblioteca::eliminar_text(){
    
}
