#include <iostream>
#include <map>
#include <sstream>
//#include "Text.hh"
#include "Frase.hh"

using namespace std;


int main(){
	
	/*
	Text t;
	t.llegir_text();
	string g = t.autor_text();
	cout << g << endl;
	g = t.titol_text();
	cout << g << endl;
	int ii = t.consultar_numfrases();
	cout << ii << endl;
	ii = t.consultar_numparaules();
	cout << ii << endl;
	cout << endl;
	t.info_text();
	cout << endl;
	t.contingut_text();
	int x, y;
	x = 1;
	y = 3;
	t.interval_frases(x,y);
	
	string s = "the";
	t.paraules_frase(s);
	
	string tt = "dummy";
	string pp = "dick";
	t.substitueix_paraules(tt,pp);
	*/
	
	map<int,Frase> contingut;
	int numfrases = 0;
	int a = 1;
    Frase fr;
    string line;
    getline(cin,line);
    while(line != "****"){
        //fer la consulta del numero de paraules de cada frase;
        // numparaules += Frase::num_paraules
		cout << "1";
        fr.llegir_frase();
		cout << "2";
        contingut.insert(make_pair(a, fr ));
		cout << "3";
        ++a;
        ++numfrases;
		getline(cin, line);
		cout << "4";
    }
    
    
    for(map<int,Frase>::const_iterator i = contingut.begin(); i != contingut.end(); ++i){
        cout << (i->first) << " ";
        Frase f = i->second;
        f.escriu_frase();
    }
}