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

using namespace std;

class Taulesaux{

	private:
		
		struct Node {
			vector<int> posicions;
			string anterior;
			
			void const operator=(Node rhs){
				anterior = rhs.anterior;
				for(int i = 0; i < posicions.size(); ++i){
					posicions[i] = rhs.posicions[i];
				}
			}
		};
		
		map<string,Node> taulaparaules;
		
		vector<pair<int,string> > taulafreq;
		
		bool static sort_comp(const pair<int,string>& lhs, const pair<int,string>& rhs){
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second.size()<rhs.second.size() ) || (!(rhs.first<lhs.first) && !(rhs.second.size()<lhs.second.size() )&& lhs.second<rhs.second);
		}
		
		//sort(taulafreq.begin(), taulafreq.end(), sort_comp);
		
	public:
		//CREADORA
		Taulesaux();
		
		~Taulesaux();
		
		//MODIFICADORA
		/** @brief 
			\pre 
			\post 
		*/ 
		void insertar_paraula(string paraula, int numf, string anterior);
		
		//CONSULTORES
		bool const existeix_cadena(string s); //busca la paraula en el map taulaparaules
		
		
		vector<int> const frases_paraula(string s);
		
		
		//ESCRIPTORA
		void const taula_frequencies();
};

#endif