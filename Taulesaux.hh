/** @file Taulesaux.hh
	@brief Classe Taulesaux
*/

#ifndef TAULESAUX_HH
#define TAULESAUX_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

class Taulesaux{

	private:

		struct Node {
			set<int> posicions;
			string anterior;
                        /*
			void const operator=(Node rhs){
				anterior = rhs.anterior;
				for(int i = 0; i < posicions.size(); ++i){
					posicions[i] = rhs.posicions[i];
				}
			}
			*/
		};

		map<string,Node> taulaparaules;
		
		map<string,int> taulafreqe;
		
		vector<pair<int,string> > vectorauxiliar;

		bool static sort_comp(const pair<int,string>& lhs, const pair<int,string>& rhs){
			if(lhs.first != rhs.first) return lhs.first > rhs.first;
			else if (lhs.second.size()!=rhs.second.size()) return lhs.second.size()<rhs.second.size();
			else return lhs.second < rhs.second;
		}

	public:
		//CREADORA
		/** @brief
			\pre
			\post
		*/
		Taulesaux();

		/** @brief
			\pre
			\post
		*/
		~Taulesaux();

		//MODIFICADORA
		/** @brief
			\pre
			\post
		*/
		void insertar_paraula(string paraula, int numf);

		/** @brief
			\pre
			\post
		*/
		void ordenar_taulafreq();

		//CONSULTORES
		/** @brief
			\pre
			\post
		*/
		bool existeix_cadena(const string s) const ; //busca la paraula en el map taulaparaules

		/** @brief
			\pre
			\post
		*/
		set<int> frases_paraula(string s);
                
                /** @brief
			\pre
			\post
		*/
        bool intercanviar(string s1, string s2);

		//ESCRIPTORA
		/** @brief
			\pre
			\post
		*/
		void taula_frequencies();

};
#endif
