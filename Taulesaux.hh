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
#include <algorithm>

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
		
		int const busqueda(vector<pair<int,string> > &taulafreq, string valor, int low, int high) {
			if (high < low) return -1 ;
			if (taulafreq[((low + high) / 2)].second > valor) return busqueda(taulafreq, valor, low, ((low + high) / 2)-1);
			else if (taulafreq[((low + high) / 2)].second < valor) return busqueda(taulafreq, valor, ((low + high) / 2)+1, high);
			else return ((low + high) / 2);
		}
		
			
		
		void insertion_sort (int arr[], int length){
			int j, temp;
			
		for (int i = 0; i < length; i++){
			j = i;
			
			while (j > 0 && arr[j] < arr[j-1]){
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;
				}
			}
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
		void insertar_paraula(string paraula, int numf, string anterior);
		
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
		bool const existeix_cadena(string s); //busca la paraula en el map taulaparaules
		
		/** @brief 
			\pre 
			\post 
		*/ 	
		vector<int> const frases_paraula(string s);
		
		
		//ESCRIPTORA
		/** @brief 
			\pre 
			\post 
		*/ 	
		void const taula_frequencies();
};

#endif