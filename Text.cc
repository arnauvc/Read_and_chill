#include "Text.hh"
#include "Frase.hh"
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

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

void const Text::info_text(){//aquesta funcio no retorna les cites associades al text
   cout << autor << " " << titol << " " << numfrases << " " << numparaules << endl; 
}

string const Text::autor_text(){
   return autor; 

}

void const Text::taula_frequencies(){

}

void const Text::contingut_text(){ 
    for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i){
        cout << (i->first) << " ";
        (i->second).escriu_frase();
    }
}


void const Text::interval_frases(int x, int y){
    map<int,Frase>::const_iterator j;
    if( x>y or x>contingut.size() or y>contingut.size() or contingut.empty() ){
        throw "error";
    }
    
    else{
        for(int i = x; i <= y; ++i){
            j = contingut.find(i);
            Frase f = (*j).second;
            f.escriu_frase();
        }
    }
}

void const Text::expressio_frases(string s1){//portara feina
	
}

void const Text::paraules_frase(string s1){
	
}

void Text::llegir_text(){ // falta definir l'acabament de la lectura, La lectora de Frase podria retornar un 0, o 1 segons si detecta *** o no.
    int a = 1;
    while(condicio){
        Frase fr = llegir_frase();
        //fer la consulta del numero de paraules de cada frase;
        // numparaules += Frase::num_paraules
        
        contingut.insert(make_pair(a, fr ));
        ++a;
    }
    
    //falta emplenar la taula frequencies
    
    sort(taulafreq.begin(), taulafreq.end(), sort_comp);
}
