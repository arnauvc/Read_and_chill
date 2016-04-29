/** @file Cita.hh
	@brief Classe Cita
*/

#ifndef CITA_HH
#define CITA_HH

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Cita{

	private:
	  map<string, Frase> c;
	public:
		/* Constructores */

		/** @brief Creadora per defecte.
			\pre cert
			\post El resultat es una nova cita
		*/ 
		Cita();
	
		/* Destructora */
		/** @brief Destructora per defecte.
			\pre Existeixi un objecte text
			\post Destrueix l'objecte tipus cita
		*/
		~Cita();
	
		/*Consultores*/
		
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
		
		/** @brief mostra totes les cites enmagatzemades al p.i
			\pre cert
			\post mostra per cada cita la referencia, contingut de les frases, autor i titol del text d'on provenen ordenades per referencia del p.i
		*/
		void totes_cites();
		
		/* Modificadores*/
		 
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

};

#endif
