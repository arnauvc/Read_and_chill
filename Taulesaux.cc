#include <sstream>
#include "Taulesaux.hh"

//CREADORA
Taulesaux::Taulesaux(){
    modificat = false;
}

Taulesaux::~Taulesaux(){}

//MODIFICADORA
void Taulesaux::insertar_paraula(string paraula, int numf){
    modificat = true;
    Node n;
    auto i = taulaparaules.find(paraula);
    set<int>::iterator it;
    if (i != taulaparaules.end()) {
    	it = n.posicions.end();
        n = i->second;
        n.freq += 1;
        n.posicions.insert(it, numf);
        taulaparaules.erase(paraula);
        taulaparaules.insert(make_pair(paraula,n));
    }
    else {
    	it = n.posicions.begin();
        n.posicions.insert(it, numf);
        n.freq = 1;
        taulaparaules.insert(make_pair(paraula,n));
    }
}

void Taulesaux::ordenar_taulafreq(){
	if(modificat){
        vectorauxiliar.clear();
        vectorauxiliar = vector<pair<int,string> >(taulaparaules.size());
        int i = 0;
        for (auto j = taulaparaules.begin(); j != taulaparaules.end(); ++j){
            vectorauxiliar[i] = make_pair(j->second.freq, j->first);
            ++i;
        }
        sort(vectorauxiliar.begin(), vectorauxiliar.end(), sort_comp);
        modificat = false;
    }
}

//CONSULTORES
bool Taulesaux::existeix_cadena(const string s) const {
	string actual;
	istringstream iss(s);
	iss >> actual;
	auto i = taulaparaules.find(actual);
	if (i != taulaparaules.end()){
            while(iss >> actual){
                i = taulaparaules.find(actual);
                if(i == taulaparaules.end()) return false;
            }
            return true;
	}
	return false;
}

set<int> Taulesaux::frases_paraula(string paraula){

    auto i = taulaparaules.find(paraula);
    if(i != taulaparaules.end()){
        return i->second.posicions;
    }
    else {
        set<int> m;
        m.insert(-1);//en cas que no trobi la paraula retorna un map amb un element -1
        return m;
    }
}

bool Taulesaux::intercanviar(string s1, string s2){
    //taulaparaules
    if(s1 != s2){
    	int rep;
		Node n;
		auto i = taulaparaules.find(s1);
		if(i != taulaparaules.end()){ 
            modificat = true;
			n = i->second;
			auto j = taulaparaules.find(s2);
			if(j != taulaparaules.end()){
				rep = i->second.freq;
				j->second.freq += rep;
				(i->second).posicions.insert((j->second).posicions.begin(),(j->second).posicions.end());
				taulaparaules.erase(s1);
			}
			else{
				taulaparaules.erase(s1);
				taulaparaules.insert(make_pair(s2,n));
			}
            return true;
		}
		return false;
    }
    return true;
}

//ESCRIPTORA
void Taulesaux::taula_frequencies(){
    ordenar_taulafreq();
    for(int i = 0; i < vectorauxiliar.size(); ++i){
        cout << vectorauxiliar[i].second << " " << vectorauxiliar[i].first <<endl;
    }
}
