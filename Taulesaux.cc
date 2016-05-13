#include <sstream>
#include "Taulesaux.hh"

//CREADORA
/** @brief 
	\pre 
	\post 
*/ 
Taulesaux::Taulesaux(){}

/** @brief 
	\pre 
	\post 
*/ 	
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
/** @brief 
	\pre 
	\post 
*/ 
bool const Taulesaux::existeix_cadena(string s){//busca la paraula en el map taulaparaules
	
	bool trobat = false;
	int k = s.size();
	string actual, ant;
	istringstream iss(s);
	iss >> actual;
	--k;
	
	map<string, Node>::const_iterator i = taulaparaules.find(actual);
	if (i != taulaparaules.end()){
		
		ant = i->first;
		iss >> actual;
		--k;
		
		while(k > 0){
			i = taulaparaules.find(actual);
			if(i->second.anterior == ant) {
				
				return false;
				
			}
			else trobat = true;
			ant = i->first;
			iss >> actual;
			--k;
			++i;
			
		}
		
		return true;
	}
	
	return trobat;
	
}

/** @brief 
	\pre 
	\post 
*/ 
vector<int> const Taulesaux::frases_paraula(string paraula){
	
	map<string, Node>::const_iterator i = taulaparaules.find(paraula);
	return i->second.posicions;
	
}


//ESCRIPTORA
/** @brief 
	\pre 
	\post 
*/ 
void const Taulesaux::taula_frequencies(){
	
	for(int i = 0; i < taulafreq.size(); ++i){
		cout << taulafreq[i].second << " " << taulafreq[i].first <<endl;
	}
	
}	

