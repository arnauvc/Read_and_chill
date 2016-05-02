
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
	
		int num_paraules;
		vector<string> frase_in;

	public:
		/* Constructores */

		/** @brief Creadora per defecte.
			\pre cert
			\post crea una frase
                */
		Frase();
	
		/* Destructora */
		/** @brief Destructora per defecte.
			\pre cert
			\post Destrueix la frase
		*/
		~Frase();
                
                /* Llegir i escriure */
        	/** @brief Lectora de frases
        		 \pre cert
        		 \post llegeix una frase del p.i
		*/
        	void llegir_frase();
		
		 /** @brief escriptora de frases
        		 \pre cert
        		 \post escriu una frase del p.i
		  */
		void escriu_frase();
};

#endif
