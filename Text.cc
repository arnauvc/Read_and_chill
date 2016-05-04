#include "Text.hh"
#include "Frase.hh"
#include <string>
#include <map>
#include <algorithm>

Text::Text(){
    numfrases = 0;
    numparaules = 0;
}

Text::~Text(){
    
}

void Text::substitueix_paraules(string s1, string s2){
    
}

int const Text::consultar_numfrases(){
    return numfrases;
}

int const Text::consultar_numparaules(){
    return numparaules;
}

void const Text::info_text(){
    
}

void const Text::autor_text(){
    

}

void const Text::taula_frequencies(){

}

map<int,Frase> const Text::contingut_text(){ 

}


void const Text::interval_frases(int x, int y){
	
}

void const Text::expressio_frases(string s1){
	
}

void const Text::paraules_frase(string s1){
	
}

void Text::llegir_text(){
    sort(taulafreq.begin(), taulafreq.end(), sort_comp);
}
