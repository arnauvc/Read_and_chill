
/** @file Frase.hh
	@brief Classe Frase
*/

#ifndef FRASE_HH
#define FRASE_HH

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include "Taulesaux.hh"

using namespace std;

class Frase{

	private:
	
		//int num_paraules;
		list<string> frase_in;

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

		/* Consultores */


		/** @brief consulta un string
			\pre cert
			\post consulta si existeix un string a una frase
		*/
		bool trobat(string s) const;
         
		/* Llegir i escriure */

                /* Llegir i escriure */
                /** @brief Lectora de frases
                    \pre cert
                    \post llegeix una frase del p.i
		*/
        void llegir_frase(list<string> frase_ini);
		
		/** @brief escriptora de frases
        		 \pre cert
        		 \post escriu una frase del p.i
		*/
		void escriu_frase() const;

		/** @brief canvia una paraula per l'altra
        		 \pre cert
        		 \post canvia el s1 pel s2 al p.i
		*/
		bool canvi_paraules(string s1, string s2);
};

#endif
