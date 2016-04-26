/** @file Text.hh
	@brief Classe Text
*/

#ifndef TEXT_HH
#define TEXT_HH

#include <iostream>
#include <string>

using namespace std;

class Text{

	private:
		Frase titol;
		string autor;
		set<Frase> contingut;//HO HEM DE DECIDIR AQUETS DIES(l'estructura on guardarem els textos i en general tot)
		int numparaules;
		int numfrases;
                map<string,int> taulafreq;
	public:
		/* Constructores */

		/** @brief Creadora per defecte.
			\pre cert
			\post text buit
		*/ 
		Text();
	
		/* Destructora */
		
		/** @brief Destructora per defecte.
			\pre que existeixi un text
			\post destrueix el text
		*/
		~Text();
		
		/* Modificadores*/

		/** @brief el p.i te una paraula especifica "s1"
			\pre text triat
			\post el p.i es com l'original pero substituint la paraula especifica per una altra "s2"
		*/ 
		void substitueix_paraules(string s1, string s2);
		
		/* Consultores */
		
		/** @brief el p.i te un contingut
			\pre text triat
			\post nombre de frases del contingut del p.i 
		*/
		int consultar_numfrases();
		
		/** @brief el p.i te un contingut
			\pre text triat
			\post nombre de paraules del contingut del p.i
		*/
		int consultar_numparaules();
		
		/** @brief el p.i te autor, titol i contingut
			\pre text triat
			\post mostra l'autor, titol, nombre de frases i de paraules i cites associades del p.i
		*/ 
		void info_text();
		
		/** @brief el p.i te autor
			\pre text triat
			\post mostra l'autor del p.i
		*/ 
		string autor_text();
		
		/** @brief el p.i te contingut
			\pre text triat
			\post mostra el contingut del p.i dividit en les diferents frases que te per ordre d'escritura original del p.i
		*/ 
		set<Frase> contingut_text();
		
		/* Llegir */
		
		/** @brief llegeix el p.i
			\pre cert
			\post llegeix el titol, l'autor i el contigut del p.i
		*/
		void llegir_text();

};

#endif
