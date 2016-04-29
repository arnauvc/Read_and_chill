
/** @file Frase.hh
	@brief Classe Frase
*/

#ifndef FRASE_HH
#define FRASE_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Frase{

	private:
		
		
		int num_paraules; //nombres paraules de la frase
		
		vector<string> frase_in;
		

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

	

		/* Entrada */

        /** @brief Lectora de frases
            \pre cert
            \post llegeix una frase del p.i
        */
        void llegir_frase();

};

#endif
