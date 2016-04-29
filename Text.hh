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
		map<int,Frase> contingut;//Ha de ser un map<>, no pot ser un set perque necessitem que estiguin ordenat pel numero.
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
		
		/* Llegir */
		
		/** @brief llegeix el p.i
			\pre cert
			\post llegeix el titol, l'autor i el contigut del p.i
		*/
		void llegir_text();

};

#endif
