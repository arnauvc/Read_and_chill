
/** @file Frase.hh
	@brief Classe Frase
*/

#ifndef FRASE_HH
#define FRASE_HH

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "Taulesaux.hh"

using namespace std;

class Frase{

	private:
	
		int num_paraules;
		vector<pair<string, string> > frase_in;

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

		/** @brief consulta numero de paraules
			\pre cert
			\post consulta numero de paraules de la frase
		*/
		int const consultar_numparaules();

		/** @brief consulta un string
			\pre cert
			\post consulta si existeix un string a una frase
		*/
		bool const trobat(string s);
         
		/* Llegir i escriure */

        /* Llegir i escriure */
        /** @brief Lectora de frases
        		\pre cert
        		\post llegeix una frase del p.i
		*/
        void llegir_frase(string s,Taulesaux &ta, int numf);
		
		/** @brief escriptora de frases
        		 \pre cert
        		 \post escriu una frase del p.i
		*/
		void const escriu_frase();

		/** @brief canvia una paraula per l'altra
        		 \pre cert
        		 \post canvia el s1 pel s2 al p.i
		*/
		void canvi_paraules(string s1, string s2);
};

#endif
