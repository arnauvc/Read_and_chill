/** @file Text.hh
	@brief Classe Text
*/

#ifndef TEXT_HH
#define TEXT_HH

#include <iostream>
#include <string>

using namespace std;

class Text{

	private: //no esta be
		Frase titol;
		string autor;
		
		string contingut;//no te sentit

	public:
		/* Constructores */

		/** @brief Creadora per defecte.
			\pre cert
			\post El resultat es un nou text amb autor, titol i contingut
		*/ 
		Text();
	
		/* Destructora */
		/** @brief Destructora per defecte.
			\pre Existeixi un objecte text
			\post Destrueix el text
		*/
		~Text();
		/* Modificadores*/

		

};

#endif
