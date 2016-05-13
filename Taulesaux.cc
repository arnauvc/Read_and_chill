#include <sstream>
#include "Taulesaux.hh"

//CREADORA
Taulesaux::Taulesaux(){}

Taulesaux::~Taulesaux(){}

//MODIFICADORA
void Taulesaux::insertar_paraula(string paraula, int numf, string ant){
	Node n;
	map<string, Node >::const_iterator i = taulaparaules.find(paraula);
	map<string, int >::iterator j = taulafreqe.find(paraula);
	if (i != taulaparaules.end()) {
		n = i->second;
		n.anterior = i->second.anterior;
		n.posicions.push_back(numf);
		taulaparaules.insert(make_pair(paraula,n));
		++(j->second);
	}
	else {
		n.posicions.push_back(numf);
		taulaparaules.erase(paraula);
		taulaparaules.insert(make_pair(paraula,n));
		taulafreqe.insert(make_pair(paraula,1));
	}
}

void Taulesaux::ordenar_taulafreq(){
	for (map<string, int >::iterator j = taulafreqe.begin(); j != taulafreqe.end(); ++j){
		vectorauxiliar.push_back(make_pair(j->second,j->first));
	}
	sort(vectorauxiliar.begin(), vectorauxiliar.end(), sort_comp);
}

//CONSULTORES
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
			if(i->second.anterior == ant) return false;
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

vector<int> const Taulesaux::frases_paraula(string paraula){
  map<string, Node>::const_iterator i = taulaparaules.find(paraula);
	return i->second.posicions;
}

//ESCRIPTORA
void const Taulesaux::taula_frequencies(){
	for(int i = 0; i < vectorauxiliar.size(); ++i){
		cout << vectorauxiliar[i].second << " " << vectorauxiliar[i].first <<endl;
	}
}
