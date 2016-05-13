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
		
		map<string,int> taulafreqe;
		
		vector<pair<int,string> > vectorauxiliar;
		
		bool static sort_comp(const pair<int,string>& lhs, const pair<int,string>& rhs){
			
			
			if(lhs.first != rhs.first) return lhs.first > rhs.first;
			else if (lhs.second.size()!=rhs.second.size()) return lhs.second.size()<rhs.second.size();
			else lhs.second < rhs.second;	/*
				if(lhs.first < rhs.first) 
			else if (lhs.first == rhs.first && lhs.second.size()<rhs.second.size()) return lhs < rhs;
			else if (lhs.first == rhs.first && lhs.second.size()<rhs.second.size() && lhs.second < rhs.second) return lhs < rhs;
			else return false;
			*/
			//return lhs.first>rhs.first || (!(rhs.first>lhs.first) && lhs.second.size()<rhs.second.size() ) || (!(rhs.first>hs.first) && !(rhs.second.size()>lhs.second.size() )&& lhs.second<rhs.second);
		}
		
		
		/*
		bool operator<(pair<int,string>& lhs, const pair<int,string>& rhs){
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second.size()>rhs.second.size() ) || (!(rhs.first<lhs.first) && !(rhs.second.size()<lhs.second.size() ) && lhs.second>rhs.second);
		}
		*/
		/*
		struct Parella{
				string paraula;
				int repeticions;
				bool operator<(const Parella& p){
					if (repeticions != p.repeticions) return repeticions < p.repeticions;
					else if (paraula.size() != p.paraula.size()) return p.paraula.size() > p.paraula.size();
					else return paraula > p.paraula;
				}
		};
		set<Parella> taulafreqe;
		
		
		*/
		
		
		/*
		bool const Parella::operator<(const Parella& p){
			if (repeticions != p.repeticions) return repeticions < p.repeticions;
			else if (paraula.size() != p.paraula.size()) return n.paraula.size() > p.paraula.size();
			else return paraula > p.paraula();
			
		}
		*/
		
			
		/*
			if(repeticions < p.repeticions) return true;
			if((repeticions == p.repeticions) && (n.paraula.size() > p.paraula.size()) ) return true;
			if ((repeticions == p.repeticions) && (n.paraula.size() == p.paraula.size()) && paraula > p.paraula) return true;
			return false;
		*/
		
		
		

		
		/*
		bool operator<(pair<int,string>& lhs, const pair<int,string>& rhs){
			return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second.size()>rhs.second.size() ) || (!(rhs.first<lhs.first) && !(rhs.second.size()<lhs.second.size() ) && lhs.second>rhs.second);
		}
		
		*/
		
		/*
		bool parella::operator<(const parella& lhs, const parella& rhs){
			//return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second.size()>rhs.second.size() ) || (!(rhs.first<lhs.first) && !(rhs.second.size()<lhs.second.size() ) && lhs.second>rhs.second);
			if(lhs.first<rhs.first)return true;
			else if ( (lhs.first == rhs.first) && (lhs.second.size()>rhs.second.size()) ) return true;
			else if ((lhs.first == rhs.first) && (lhs.second.size() == rhs.second.size()) && (lhs.second > rhs.second)) return true;
			else return false;
				
		}
		*/
		
		
		////////////////////////////////
		
		
		
		/*
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
		///////////////////////////////////
		*/
		
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