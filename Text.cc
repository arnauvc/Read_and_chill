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

void const Text::interval_frases(int x, int y){
    map<int,Frase>::const_iterator j;
    if( x>y or x>contingut.size() or y>contingut.size() or contingut.empty() ){
        throw "error";
    }
    
    else{
        for(int i = x; i <= y; ++i){
            j = contingut.find(i);
			cout << j->first;
            Frase f = (*j).second;
            f.escriu_frase();
        }
    }
}

void const Text::paraules_frase(string s1){
	for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i){
        Frase f = i->second;
        if(f.trobat(s1)) {
			cout << i->first << " ";
			f.escriu_frase();
		}
    }
}

void Text::substitueix_paraules(string s1, string s2){
	cout << "0" << endl;
    for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i){
		cout << "1" << endl;
        Frase f = i->second;
		int num = i->first;
        f.canvi_paraules(s1,s2);
		contingut.erase(num);
		contingut.insert(make_pair(num,f));
		
    }
}

void const Text::expressio_frases(string s1){//portara feina
	
}



void const Text::taula_frequencies(){
    for(int i = 0; i < taulafreq.size(); ++i){
        cout << taulafreq[i].second << " " << taulafreq[i].first <<endl;
    }
}

void Text::llegir_text(){ // falta definir l'acabament de la lectura, La lectora de Frase podria retornar un 0, o 1 segons si detecta *** o no.
    
	int a = 1;
    string line;
	getline(cin, titol);
    getline(cin, autor);
	getline(cin, line);
    while(line != "****"){
		Frase fr;
        //fer la consulta del numero de paraules de cada frase;
        // numparaules += Frase::num_paraules
        fr.llegir_frase(line);
        contingut.insert(make_pair(a, fr));
        ++a;
        ++numfrases;
        numparaules += fr.consultar_numparaules();
		getline(cin, line);
    }
    
    //falta emplenar la taula frequencies
    
    //sort(taulafreq.begin(), taulafreq.end(), sort_comp);
}
