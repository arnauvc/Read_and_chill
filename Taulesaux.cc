

#include <string>
#include <vector>
#include <map>
#include <utility>
#include <sstream>
#include "Taulesaux.hh"

//CREADORA

Taulesaux::Taulesaux(){}

		
Taulesaux::~Taulesaux(){}


//MODIFICADORA
/** @brief 
	\pre 
	\post 
*/ 
void Taulesaux::insertar_paraula(string paraula, int numf, string ant){
	//insercio en el map
	Node n;
	
	map<string, Node >::const_iterator i = taulaparaules.find(paraula);
	
	if (i != taulaparaules.end()) {
		n = i->second;
		n.anterior = i->second.anterior;
		n.posicions.push_back(numf);
		taulaparaules.insert(make_pair(paraula,n));
	}
	else {
		n.posicions.push_back(numf);
		taulaparaules.erase(paraula);
		taulaparaules.insert(make_pair(paraula,n));
	}
	
	//insercio en la taula de taula_frequencies
	
	
}
		
//CONSULTORES
bool const Taulesaux::existeix_cadena(string s){//busca la paraula en el map taulaparaules
	cout << "2" << endl;
	bool trobat = false;
	int k = s.size();
	string actual, ant;
	istringstream iss(s);
	iss >> actual;
	--k;
	cout << "3" << endl;
	map<string, Node>::const_iterator i = taulaparaules.find(actual);
	if (i != taulaparaules.end()){
		cout <<"4" << endl;
		ant = i->first;
		iss >> actual;
		--k;
		cout << "5" << endl;
		while(k > 0){
			i = taulaparaules.find(actual);
			if(i->second.anterior == ant) {
				cout << "6" << endl;
				return false;
				
			}
			else trobat = true;
			ant = i->first;
			iss >> actual;
			--k;
			++i;
			cout << "7" <<endl;
		}
		cout << "8 " <<endl;
		return true;
	}
	cout << "9" << endl;
	return trobat;
	
}
vector<int> const Taulesaux::frases_paraula(string paraula){
	
	map<string, Node>::const_iterator i = taulaparaules.find(paraula);
	return i->second.posicions;
	
}


//ESCRIPTORA
void const Taulesaux::taula_frequencies(){
	
	for(int i = 0; i < taulafreq.size(); ++i){
		cout << taulafreq[i].second << " " << taulafreq[i].first <<endl;
	}
	
}	

