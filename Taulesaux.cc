#include <sstream>
#include "Taulesaux.hh"

//CREADORA

Taulesaux::Taulesaux(){}

Taulesaux::~Taulesaux(){}

//MODIFICADORA

/////////////////VERSIO1 AMB VECTOR
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
	//Sempre fem push_back amb frequencia 1 i despres recorrem el vector per eliminar les repeticions i ordenem.
	
}

void Taulesaux::ordenar_taulafreq(){
	for (map<string, int >::iterator j = taulafreqe.begin(); j != taulafreqe.end(); ++j){
		vectorauxiliar.push_back(make_pair(j->second,j->first));
	}
	sort(vectorauxiliar.begin(), vectorauxiliar.end(), sort_comp);
	
	
	
	for(int g = 0;g < vectorauxiliar.size(); ++g){
		cout << vectorauxiliar[g].second << " " << vectorauxiliar[g].first << endl;
	}
	
	/*
	int j = 0;
	int k = 1;
	string s;
	s = taulafreq[j].second;
	while(k < taulafreq.size()){
		if(k < taulafreq.size() and taulafreq[k].second == s){
			while(taulafreq[k].second == s){
				taulafreq[j].first += taulafreq[k].first;
				++k;
			}
			++j;
			taulafreq[j] = taulafreq[k];
			++k;
			s = taulafreq[j].second;
		}
		else {
			if(j+1 == k){
				++k;
				++j;
				s = taulafreq[j].second;
				}
			else{
				++j;
				taulafreq[j] = taulafreq[k];
				++k;
				s = taulafreq[j].second;
			}
		}
	}
	*/
	
	
	
	
	
	
	
	
	/*
	cout << "size abans = " << taulafreq.size() <<endl;
	vector<pair<int,string> >(taulafreq).swap(taulafreq);
	cout << "size despres = " <<taulafreq.size() << endl;
	*/
	// 
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

