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
        n.posicions.insert(numf);
        //n.posicions.push_back(numf);
        taulaparaules.insert(make_pair(paraula,n));
        ++(j->second);//taulafreqe
    }
    else {
        n.posicions.insert(numf);
        //n.posicions.push_back(numf);
        taulaparaules.erase(paraula);
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
bool const Taulesaux::existeix_cadena(string s){//busca la paraula en el map taulaparaules
	
	bool trobat = false;
	//int k = s.size();
	string actual, ant;
	istringstream iss(s);
	iss >> actual;
	//--k;
	
	map<string, Node>::const_iterator i = taulaparaules.find(actual);
	
	if (i != taulaparaules.end()){
           // ant = i->first;
            iss >> actual;
           // --k;
            while(iss >> actual){
                i = taulaparaules.find(actual);
                if(i == taulaparaules.end()) return false;
                else trobat = true;
                //iss >> actual;
                //--k;
                //++i;
            }
            return true;
	}
	return trobat;
}

set<int> const Taulesaux::frases_paraula(string paraula){

  map<string, Node>::const_iterator i = taulaparaules.find(paraula);
  
	return i->second.posicions;
}

void Taulesaux::intercanviar(string s1, string s2){
    //taulaparaules
    Node n;
    map<string, Node >::iterator i = taulaparaules.find(s1);
    if(i != taulaparaules.end()){
        n = i->second;
        
    }
    else cout << "error no troba: " << s1 <<endl;
    
    map<string, Node >::const_iterator j = taulaparaules.find(s2);
    
    if(j != taulaparaules.end()){
        
        (i->second).posicions.insert((j->second).posicions.begin(),(j->second).posicions.end());
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
    }
    if(l != taulafreqe.end()){
        
        l->second += rep;
        taulafreqe.erase(s1); 
    }
    else {
        
        taulafreqe.insert(make_pair(s2,rep));
        taulafreqe.erase(s1); 
    }
    
    ordenar_taulafreq();
    
}

//ESCRIPTORA
void const Taulesaux::taula_frequencies(){
    for(int i = 0; i < vectorauxiliar.size(); ++i){
        cout << vectorauxiliar[i].second << " " << vectorauxiliar[i].first <<endl;
    }
}
