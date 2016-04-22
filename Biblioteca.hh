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
		bool triat; //True si hi ha un text seleccionat, False altrement
		Text ttriat; //Si triat==True, conte el text triat segons condicions
		
		
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
			\post 
		*/ 
		triar_text();
		
		/** @brief Mostra titol i autor de tots els textos
			\pre Existeix almenys un text
			\post Es mostren per pantalla els titols i els seus autors de tots els textos ordenats per autor i titol
		*/ 
		tots_textos();
		
		/* Modificadores*/
		
		/** @brief Afegeix un text a la biblioteca
			\pre 
			\post El parametre implicit es el mateix pero amb un text mes
		*/ 
		afegir_text();
		
		/** @brief Elimina un text de la biblioteca
			\pre 
			\post El parametre implicit es el mateix menys el text triat
		*/ 
		eliminar_text();
		
		
		
		
		
		

};

#endif
