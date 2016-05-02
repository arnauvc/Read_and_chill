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
		
		
		//TEXT
		
		/** @brief Tria un text segons condicions
			\pre Existeix almenys un text
			\post el p.i queda triat i retorna el text triat
		*/ 
	 	Text triar_text();
		
		/** @brief Mostra titol i autor de tots els textos
			\pre Existeix almenys un text
			\post Es mostren per pantalla els titols i els seus autors de tots els textos ordenats per autor i titol
		*/ 
		void tots_textos();
		
		
		/** @brief Afegeix un text a la biblioteca
			\pre que existeixi almenys una biblioteca
			\post El p.i es el mateix que l'original pero amb un text mes
		*/ 
		void afegir_text();
                
                 /** @brief el p.i te una paraula especifica "s1"
			\pre text triat
			\post el p.i es com l'original pero substituint la paraula especifica per una altra "s2"
		*/ 
		void substitueix_paraules(string s1, string s2);
		
		/** @brief Elimina un text de la biblioteca
			\pre existeix una biblioteca i un text guardat a la biblioteca almenys
			\post El p.i es el mateix que l'original menys el text triat
		*/ 
		void eliminar_text();	
                
                
		
		//CITES
		
		/** @brief mostra totes les cites enmagatzemades al p.i
			\pre cert
			\post mostra per cada cita la referencia, contingut de les frases, autor i titol del text d'on provenen ordenades per referencia del p.i
		*/
		void totes_cites();
		
		 
		/** @brief afegeix una cita al p.i
			\pre text triat
			\post afegeix una cita al p.i entre la frase x y la frase y del contingut del ultim text triat
		*/
		void afegir_cita(int x, int y);
		
		/** @brief elimina una cita del p.i
			\pre que existeixi la cita
			\post elimina una cita del p.i
		*/
		void eliminar_cita(string referencia);
		
		/** @brief mostra informacio del p.i
			\pre existeix la cita
			\post mostra autor,titol,numero de la frase inicial i numero de la frase final, contingut de la frase o frases que la componen del p.i
		*/
		void info_cita(string referencia);
		
		/** @brief mostra totes les cites del p.i
			\pre existeix l'autor
			\post mostra per cada cita la referencia, contingut de les frases i titol del text don provenen ordenats per referencia del p.i
		*/
		void cites_autor(string autor);

};

#endif
