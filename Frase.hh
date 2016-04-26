
/** @file Frase.hh
	@brief Classe Frase
*/

#ifndef FRASE_HH
#define FRASE_HH

#include <iostream>
#include <string>

using namespace std;

class Frase{

	private: //no esta be
		int num_paraules; //nombres paraules de la frase

	public:
		/* Constructores */

		/** @brief Creadora per defecte.
			\pre cert
			\post El resultat es un nova frase
                */
		Frase();
	
		/* Destructora */
		/** @brief Destructora per defecte.
			\pre Existeixi un objecte frase
			\post Destrueix la frase
		*/
		~Frase();
		
		/* Consultores */

		/** @brief mostra les frases del p.i entre un interval concret
			\pre text triat
			\post mostra les diferentes frases entre la "x" i la "y" del p.i
		*/
		void interval_frases(int x, int y); //VA A Text.HH MILLOR CREC (perque es el conjunt de frases del contigut de un text triat)

		/** @brief mostra frases del p.i segons l'expressio
			\pre text triat
			\post mostra frases del p.i segons lexpressio
		*/
		void expressio_frases(string s1, string s2);//s'ha d'entendre be el que fa aquesta funcio al PDF!!!!!

		/** @brief mostra frases del p.i segons la sequencia de paraules "k"
			\pre text triat
			\post mostra les diferents frases del p.i on apareix les paraules consecutives 
		*/
		void paraules_frase(Frase k);// s'ha de mirar el tipos de dades aqui i hem dentendre la funcio al PDF!!!!!!

		/* Entrada */

        /** @brief Lectora de frases
            \pre cert
            \post llegeix una frase del p.i
        */
        void llegir_frase();

};

#endif
