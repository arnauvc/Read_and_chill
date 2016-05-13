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
	if (i != taulaparaules.end()) {
		n = i->second;
		n.anterior = i->second.anterior;
		n.posicions.push_back(numf);
		taulaparaules.insert(make_pair(paraula,n));
		
		taulafreq.push_back(make_pair(1,paraula));
	}
	else {
		n.posicions.push_back(numf);
		taulaparaules.erase(paraula);
		taulaparaules.insert(make_pair(paraula,n));
		taulafreq.push_back(make_pair(1,paraula));
	}
	//Sempre fem push_back amb frequencia 1 i despres recorrem el vector per eliminar les repeticions i ordenem.
	
}

void Taulesaux::ordenar_taulafreq(){
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
	
	for(int g = 0;g < taulafreq.size(); ++g){
		cout << taulafreq[g].second << taulafreq[g].first << endl;
	}
	/*
	cout << "size abans = " << taulafreq.size() <<endl;
	vector<pair<int,string> >(taulafreq).swap(taulafreq);
	cout << "size despres = " <<taulafreq.size() << endl;
	*/
	sort(taulafreq.begin(), taulafreq.end(), sort_comp);
}

/////////////////VERSIO1


/*
/////////////////VERSIO2 AMB LLISTA wwwwwait for it bitch, won't do that if not needed, ofc
void Taulesaux::insertar_paraula(string paraula, int numf, string ant){
	
/
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
	//Sempre fem push_back amb frequencia 1 i despres recorrem el vector per eliminar les repeticions i ordenem.
	taulafreq.push_back(make_pair(1,paraula));
}

void Taulesaux::ordenar_taulafreq(){
	int num;
	string s;
	for(int j = 0; j < taulafreq.size(); ++j){
		num = taulafreq[j].first;
		s = taulafreq[j].second;
		while(taulafreq[j].second){
			
		}
		
	}
	
	sort(taulafreq.begin(), taulafreq.end(), sort_comp);
}
/////////////////VERSIO2
*/




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
	for(int i = 0; i < taulafreq.size(); ++i){
		cout << taulafreq[i].second << " " << taulafreq[i].first <<endl;
	}
	
}	

