/** @file Taulesaux.hh
	@brief Classe Taulesaux
*/

#ifndef TAULESAUX_HH
#define TAULESAUX_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Frase.hh"


using namespace std;

class Taulesaux{

	private:
		map<string,vector<int> > taulaparaules;
		
		vector<pair<int,string> > taulafreq;
		
		bool static sort_comp(const pair<int,string>& lhs, const pair<int,string>& rhs){
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second.size()<rhs.second.size() ) || (!(rhs.first<lhs.first) && !(rhs.second.size()<lhs.second.size() )&& lhs.second<rhs.second);
		}
	public:
		
		//MODIFICADORA
		/** @brief 
			\pre 
			\post 
		*/ 
		void insertar_paraula(string paraula, int numf);
		
		//CONSULTORES
		bool const existeix_paraula(string s); //busca la paraula en el map taulaparaules
		
		
		vector<int> const frases_paraula(string s);
		
		
		//ESCRIPTORA
		void const taula_frequencies();
};

#endif