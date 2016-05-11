#include <iostream>
#include <map>
#include <sstream>
#include "Text.hh"
#include "Frase.hh"

using namespace std;


int main(){
	
	Text t;
	t.llegir_text();
	/*string g = t.titol_text();
	cout << g << endl;
	g = t.autor_text();
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
	*/string s = "milapod holanuriko hipiwawe";
	t.paraules_frase(s);
	string tt = "zukile";
	string pp = "dick";
	t.substitueix_paraules(tt,pp);
	t.contingut_text();
	
	
	/*
	map<int,Frase> contingut;
	int numfrases = 0;
	int a = 1;
    
    string autor,line;
    //getline(cin, autor);
	getline(cin, line);
    while(line != "****"){
		Frase fr;
        //fer la consulta del numero de paraules de cada frase;
        // numparaules += Frase::num_paraules
        fr.llegir_frase(line);
        contingut.insert(make_pair(a, fr));
        ++a;
        numfrases += numfrases;
		getline(cin, line);
    }

	do{
		cout << "1";
        fr.llegir_frase();
		cout << "2";
        contingut.insert(make_pair(a, fr ));
		cout << "3";
        ++a;
        ++numfrases;
		//getline(cin, line);
		cout << "4";
	}
	while(line != "****");
	*/
	
	
}