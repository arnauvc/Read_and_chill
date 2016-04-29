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
		
		
		
		

};

#endif
