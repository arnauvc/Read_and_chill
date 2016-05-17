/** @file Text.hh
	@brief Classe Text
*/

#ifndef TEXT_HH
#define TEXT_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstddef>
#include "Frase.hh"
#include "Taulesaux.hh"
#include <sstream>


using namespace std;

class Text{

	private:
            string titol;
            string autor;
            map<int,Frase> contingut;
            int numparaules;
            int numfrases;
            Taulesaux tau;
            
            
            bool compleix_expressio(const string &exp, int &i, Frase &f) {
                if (exp[i]!='(') {	//Si l'element no es un parentesi, l'analitzem
                    string e;	//Si es una etiqueta, es guardara a "e"
                    while (exp[i]!='.' and exp[i]!=',' and exp[i]!=')') { //Si es una etiqueta (no es '.' o ',' o ')') la guardem 
                                                // a "e" i avancem posicions (i) fins trobar un caracter 
                                                // que no pertanyi a l'etiqueta ('.' o ',' o ')') 
                        e.push_back(exp[i]); 	// fem push_back per afegir la nova lletra al final del string "e"
                        ++i;			//avançem posicio
                    }
                    return f.trobat(e); //Utilitzem la funcio per saber si la tasca conte l'etiqueta "e", 
                                    // retorna fals si no.
                }
                else { // Si es un parentesi '(', es el principi d'una expressio booleana
                    ++i;  //Avancem una posicio, podrem trobar un altre parentesi (una altre expressio) o una etiqueta
                    bool r1 = compleix_expressio(exp,i,f);  //retorna cert si es una etiqueta i aquesta pertany a la tasca,
                                        // fals altrament. Si no es una etiqueta, retorna cert si la següent 
                                        // expressió trobada es certa.
                    char c = exp[i]; 	// c=element actual, element que va despres de l'etiqueta trobada a la
                                // linia anterior. Nomes pot ser "." o ",".
                    ++i; 			// Avancem una posicio, hem de trobar nova etiqueta o un parentesi (nova expressio)
                    bool r2 = compleix_expressio(exp,i,f); //retorna cert si es una etiqueta i aquesta pertany a la tasca, 
                                        // fals altrament. Si no es una etiqueta retorna cert si la següent
                                        // expressió trobada es certa.
                    ++i;			//Avancem una posicio, per que "i" retorni el valor adequat (sempre 
                                // una posicio despres de l'element analitzat en aquesta iteracio).
                    if (c=='&') {		// Haviem guardat "." o "," a "c". 
                        return (r1 and r2);	//Si es "." es un and, retorna true si es compleix
                    } else {
                        return (r1 or r2);	//Si es "," es un or, retorna true si es compleix
                    }
                }
            }
            
		
	public:
            /* Constructores */

            /** @brief Creadora per defecte.
                    \pre cert
                    \post crea un text sense titol ni autor ni contingut(buit)
            */ 
            Text();
	
            /* Destructora */
		
            /** @brief Destructora per defecte.
                    \pre cert
                    \post destrueix el text
            */
            ~Text();
		
		/* Modificadores*/

		
		
		/* Consultores */
		
		/** @brief el p.i te contingut
			\pre text triat
			\post nombre de frases del contingut del p.i 
		*/
		int consultar_numfrases();

		/** @brief 
			\pre 
			\post 
		*/
		bool buscar_paraules(string s);
		
		/** @brief el p.i te contingut
			\pre text triat
			\post nombre de paraules del contingut del p.i
		*/
		int consultar_numparaules();
		
		/** @brief el p.i te autor, titol i contingut
			\pre text triat
			\post mostra l'autor, titol, nombre de frases i de paraules i cites associades del p.i
		*/ 
		void info_text();

		/** @brief el p.i te autor, titol i contingut
			\pre text triat
			\post mostra el titol del p.i
		*/ 
                string titol_text();
		
		/** @brief el p.i te autor, titol i contingut
			\pre text triat
			\post mostra l'autor del p.i
		*/ 
            string autor_text();	

		/** @brief el p.i te autor, titol i contingut
			\pre text triat
			\post mostra el contingut del p.i dividit en les diferents frases que te per ordre d'entrada original del p.i
		*/ 
		void contingut_text();
		
		/** @brief mostra les frases del p.i entre un interval concret
			\pre text triat
			\post mostra les diferents frases entre la "x" i la "y" del p.i
		*/
		map<int,Frase> interval_frases(int x, int y, bool& b);

		/** @brief mostra frases del p.i
			\pre text triat
			\post mostra frases del p.i segons lexpressio
		*/
		void expressio_frases(string s1);
                
                /** @brief el p.i te una paraula especifica "s1"
			\pre text triat
			\post el p.i es com l'original pero substituint la paraula especifica per una altra "s2"
		*/ 
		void substitueix_paraules(string s1, string s2);

		/** @brief mostra frases del p.i
			\pre text triat
			\post mostra les diferents frases del p.i on apareix les paraules consecutives 
		*/
		void paraules_frase(string s1);
		
		
		
		void taula_frequencies();
		
		/* Llegir */
		
		/** @brief llegeix el p.i
			\pre cert
			\post llegeix el titol, l'autor i el contigut del p.i
		*/
		void llegir_text(string ti);
};

#endif
