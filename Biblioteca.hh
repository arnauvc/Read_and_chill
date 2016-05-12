/** @file Biblioteca.hh
	@brief Classe Text
*/

#ifndef BIBLIOTECA_HH
#define BIBLIOTECA_HH

#include <iostream>
#include <string>
#include <map>
#include "Frase.hh"
#include "Text.hh"
#include <algorithm>

using namespace std;

class Biblioteca{

	private: 
		struct infoautor{
			int ntextos;
			int nfrases;
			int nparaules;
		};
		
		bool triat;
		Text ttriat;
		map<string,Text> conjunt_cites; //referencia, Cita
		map<string,Text> conjunt_textos; // autor, Text
		map<string,infoautor> conjunt_autors;
		bool static comp_titols(string a, string b) {
			return a < b;
		}
		
	public:
		/* Constructores */

		/** @brief Creadora per defecte.
			\pre cert
			\post crea una biblioteca buida (sense textos ni cites)
		*/ 
		Biblioteca();
	
		/* Destructora */
		
		/** @brief Destructora per defecte.
			\pre cert
			\post Destrueix la biblioteca
		*/
		~Biblioteca();
		
		
		//FUNCIONS PER TEXTOS
		
		/** @brief Tria un text
			\pre Existeix almenys un text
			\post el p.i queda triat i retorna el text triat
		*/ 
	 	Text const triar_text(string s, bool &b);
        
	
		/** @brief 
			\pre 
			\post 
		*/ 
		bool const consultar_triat();
		
		/** @brief Mostra titol i autor de tots els textos
			\pre cert
			\post Es mostren per pantalla els titols i els seus autors de tots els textos ordenats per autor i despres per titol
		*/ 
		void const tots_textos();
		
		/** @brief Afegeix un text a la biblioteca
			\pre que existeixi almenys una biblioteca
			\post El p.i es el mateix que l'original pero amb un text mes
		*/ 
		void afegir_text();
                
		
		/** @brief Elimina un text de la biblioteca
			\pre existeix una biblioteca i un text triat dins
			\post El p.i es el mateix que l'original menys el text triat i no hi ha cap text triat
		*/ 
		void eliminar_text();	
                
                
		
		//FUNCIONS PER CITES
		
		/** @brief mostra totes les cites enmagatzemades al p.i
			\pre cert
			\post mostra per cada cita la referencia, contingut de les frases, autor i titol del text d'on provenen ordenades per referencia 
		*/
		void const totes_cites();
		
		 
		/** @brief afegeix una cita al p.i
			\pre text triat
			\post afegeix una cita al p.i entre la frase x i la frase y del contingut del ultim text triat
		*/
		void afegir_cita(int x, int y);
		
		/** @brief elimina una cita del p.i
			\pre que existeixi la cita al p.i
			\post el p.i es com l'original sense la cita
		*/
		void eliminar_cita(string referencia);
		
		/** @brief mostra informacio del p.i
			\pre existeix la cita
			\post mostra autor, titol, numero de la frase inicial i numero de la frase final i el contingut de la frase o frases que la componen
		*/
		void const info_cita(string referencia);
		
		/** @brief mostra totes les cites del p.i
			\pre existeix l'autor
			\post mostra per cada cita la referencia, contingut de les frases i titol del text don provenen ordenats per referencia
		*/
		void const cites_autor(string autor);

        //FUNCIONS EXTRA        

        /** @brief mostra tots els autors amb textos en el sistema
                        \pre Existeix almenys un autor en el sistema
                        \post mostra tots els autors, amb els seus textos, numero de paraules i de frases de cada text 
        */
        void const tots_autors();
                
        /** @brief asdasdsad
			\pre sadasdsasadsada
			\post adsadsadsadsadasds
         */
        void const textos_autor(string s);
                
                
                

};

#endif
