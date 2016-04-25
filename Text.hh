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
		set<Frase> contingut;//no m'agrada
		int numparaules;
		int numfrases;
                map<string,int> taulafreq;
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

		/** @brief canvia totes les paraules string1 per string2 del contingut de l'ultim text triat 
			\pre que hi hagi un text triat
			\post canvia totes les paraules string1 per string2 del contingut de l'ultim text triat 
		*/ 
		void substitueix_paraules(string s1, string s2);
		
		/* Consultores */
		
		/** @brief mostra el nombre de frases
			\pre cert
			\post mostra el nombre de frases
		*/
		int consultar_numfrases();
		
		/** @brief mostra el nombre de paraules
			\pre cert
			\post mostra el nombre de paraules
		*/
		int consultar_numparaules();
		
		/** @brief mostra l'autor, titol, nombre de frases i de paraules i cites associades a l'ultim text triat
			\pre que hi hagi un text triat
			\post mostra l'autor, titol, nombre de frases i de paraules i cites associades a l'ultim text triat
		*/ 
		void info_text();
		
		/** @brief mostra l'autor de l'ultim text triat
			\pre que hi hagi un text triat
			\post mostra l'autor de l'ultim text triat
		*/ 
		string autor_text();
		
		/** @brief mostra el contingut de l'ultim text triat per ordre de frases numerades i un canvi de linea a cada frase
			\pre que hi hagi un text triat
			\post ostra el contingut de l'ultim text triat per ordre de frases numerades i un canvi de linea a cada frase
		*/ 
		set<Frase> contingut_text();
		
		/* Llegir */
		
		/** @brief llegeix la entrada de dades del titol, l'autor i el contigut del text
			\pre cert
			\post llegeix la entrada de dades del titol, l'autor i el contigut del text
		*/
		void llegir_text();

};

#endif
