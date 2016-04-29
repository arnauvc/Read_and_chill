/** @file Biblioteca.hh
	@brief Classe Text
*/

#ifndef BIBLIOTECA_HH
#define BIBLIOTECA_HH

#include <iostream>
#include <string>
#include "Frase.hh"
#include "Text.hh"
#include "Cita.hh"

using namespace std;

class Biblioteca{

	private: 
		bool triat; //True si hi ha un text triat, False altrement
		Text ttriat; //Si triat==True, conte el text triat segons condicions
		map<string,Text> conjunt_cites; // 
		map<string,Text> conjunt_textos;//
		
	public:
		/* Constructores */

		/** @brief Creadora per defecte.
			\pre cert
			\post El resultat es una nova biblioteca buida (sense textos ni cites)
		*/ 
		Biblioteca();
	
		/* Destructora */
		
		/** @brief Destructora per defecte.
			\pre Existeixi un objecte biblioteca
			\post Destrueix la biblioteca
		*/
		~Biblioteca();
		
		/*Consultores*/
		
		/** @brief Tria un text segons condicions
			\pre Existeix almenys un text
			\post el p.i queda triat
		*/ 
		void triar_text();
		
		/** @brief Mostra titol i autor de tots els textos
			\pre Existeix almenys un text
			\post Es mostren per pantalla els titols i els seus autors de tots els textos ordenats per autor i titol
		*/ 
		void tots_textos();
		
		/* Modificadores*/
		
		/** @brief Afegeix un text a la biblioteca
			\pre que existeixi almenys una biblioteca
			\post El p.i es el mateix que l'original pero amb un text mes
		*/ 
		void afegir_text();
		
		/** @brief Elimina un text de la biblioteca
			\pre existeix una biblioteca i un text guardat a la biblioteca almenys
			\post El p.i es el mateix que l'original menys el text triat
		*/ 
		void eliminar_text();	

};

#endif
