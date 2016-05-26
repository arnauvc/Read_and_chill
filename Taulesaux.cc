#include <sstream>
#include "Taulesaux.hh"

//CREADORA
Taulesaux::Taulesaux(){}

Taulesaux::~Taulesaux(){}

//MODIFICADORA
void Taulesaux::insertar_paraula(string paraula, int numf){
    Node n;
    map<string, Node >::const_iterator i = taulaparaules.find(paraula);
    map<string, int >::iterator j = taulafreqe.find(paraula);
    set<int>::iterator it;
    if (i != taulaparaules.end()) {
    	it = n.posicions.end();
        n = i->second;
        n.anterior = i->second.anterior;
        n.posicions.insert(it, numf);
        //n.posicions.push_back(numf);
        taulaparaules.erase(paraula);
        taulaparaules.insert(make_pair(paraula,n));
        ++(j->second);//taulafreqe
    }
    else {
    	it = n.posicions.begin();
        n.posicions.insert(it, numf);
        //n.posicions.push_back(numf);
        //taulaparaules.erase(paraula);
        taulaparaules.insert(make_pair(paraula,n));
        taulafreqe.insert(make_pair(paraula,1));
    }
}

void Taulesaux::ordenar_taulafreq(){
    
    vectorauxiliar.clear();
    for (map<string, int >::iterator j = taulafreqe.begin(); j != taulafreqe.end(); ++j){
        
        vectorauxiliar.push_back(make_pair(j->second,j->first));
    }
    
    sort(vectorauxiliar.begin(), vectorauxiliar.end(), sort_comp);
    
}

//CONSULTORES
bool Taulesaux::existeix_cadena(const string s) const {
	//bool trobat = false;
	string actual;
	istringstream iss(s);
	iss >> actual;
	map<string, Node>::const_iterator i = taulaparaules.find(actual);
	if (i != taulaparaules.end()){
            while(iss >> actual){
                i = taulaparaules.find(actual);
                if(i == taulaparaules.end()) return false;
                //else trobat = true;   NO FA FALTAAA
            }
            return true;
	}
	return false;
}

set<int> Taulesaux::frases_paraula(string paraula){

    map<string, Node>::const_iterator i = taulaparaules.find(paraula);
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
		Node n;
		map<string, Node >::iterator i = taulaparaules.find(s1);
		if(i != taulaparaules.end()){ //ABORTED SOLUCIONAT PER OBRIR AL FINAL EL CORCHETE, ERA NECESARI...
			n = i->second;
			map<string, Node >::const_iterator j = taulaparaules.find(s2);
			if(j != taulaparaules.end()){
				(i->second).posicions.insert((j->second).posicions.begin(),(j->second).posicions.end()); //CAUSANT DEL ABORTED PROGRAM DEL PRIVAT 3!!!!
				taulaparaules.erase(s2);
			}
			else{
				taulaparaules.erase(s1);
				taulaparaules.insert(make_pair(s2,n));
			}
			//taulafreqe
			map<string, int >::iterator k = taulafreqe.find(s1);
			map<string, int >::iterator l = taulafreqe.find(s2);
			int rep;
			if(k != taulafreqe.end()){
				rep = k->second;
				if(l != taulafreqe.end()){
				l->second += rep;
				taulafreqe.erase(s1); 
				}
				else {
					taulafreqe.insert(make_pair(s2,rep));
					taulafreqe.erase(s1); 
				}
			}
			ordenar_taulafreq();
            return true;
		}
		return false;
    }
}

//ESCRIPTORA
void Taulesaux::taula_frequencies(){
    for(int i = 0; i < vectorauxiliar.size(); ++i){
        cout << vectorauxiliar[i].second << " " << vectorauxiliar[i].first <<endl;
    }
}
