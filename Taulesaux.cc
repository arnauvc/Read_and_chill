

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Taulesaux.hh"
#include "Frase.hh"



//MODIFICADORA
/** @brief 
	\pre 
	\post 
*/ 
void Taulesaux::insertar_paraula(string paraula, int numf){
	//insercio en el map
	vector<int> v;
	map<string, vector<int> >::const_iterator i = taulaparaules.find(paraula);
	if (i == taulaparaules.end()) {
		v.push_back(numf);
		taulaparaules.insert(make_pair(paraula,v));
	}
	else {
		v = i->second;
		v.push_back(numf);
		taulaparaules.erase(paraula);
		taulaparaules.insert(make_pair(paraula,v));
	}
	
	//insercio en la taula de taula_frequencies
	
	
}
		
//CONSULTORES
bool const Taulesaux::existeix_paraula(string paraula){//busca la paraula en el map taulaparaules
	map<string, vector<int> >::const_iterator i = taulaparaules.find(paraula);
	if (i == taulaparaules.end()) return false; return true;
} 
		
vector<int> const Taulesaux::frases_paraula(string paraula){
	map<string, vector<int> >::const_iterator i = taulaparaules.find(paraula);
	return i->second;
}


//ESCRIPTORA
void const Taulesaux::taula_frequencies(){
	for(int i = 0; i < taulafreq.size(); ++i){
		cout << taulafreq[i].second << " " << taulafreq[i].first <<endl;
	}
}	

