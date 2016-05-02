/**
 * @mainpage Practica PRO2 - Gestor de textos i cites
*/

/** @file program.cc
    @brief Programa principal de <em>Pràctica PRO2 - Gestor de textos i cites</em>.
*/

#include <iostream>
#include <string>
#include <sstream>
#include "Biblioteca.hh"
#include "Text.hh"

using namespace std;

/** @brief Programa principal.
*/

int main(){
	Biblioteca biblio;
        Text texttriat;
        bool ttriat = false;
	string linia,m;
	getline(cin,linia);
        while( linia != "sortir"){
            cout << linia << endl;
            istringstream iss(linia);
            string op;
            iss >> op;
            if(op == "afegir text"){
                //string titol;
                //ws(iss);
                //getline(iss,titol);
                biblio.afegir_text();
            }

            else if(op == "llegir cita"){
                int x,y;
                ws(iss);
                iss >> x;
                iss >> y;
                biblio.afegir_cita(x,y);

            }
            else if(op == "triar text"){
                texttriat = biblio.triar_text();
                ttriat = true;
            }

            else if(op == "eliminar text"){
                biblio.eliminar_text();
                ttriat = false;
            }

            else if(op == "substitueix"){
                string s1,s2;
                ws(iss);
                iss >> s1;
                iss >> s2;
                texttriat.substitueix_paraules(s1,s2);
            }

            else if(op == "textos autor"){
                biblio.textos_autor();
            }

            else if(op == "tots textos"){
                biblio.tots_textos();
            }

            else if(op == "tots autors"){
                biblio.tots_autors();
            }

            else if(op == "info ?"){
                texttriat.info_text();
            }
            
            else if (op == "autor ?"){
                texttriat.autor_text();
            }

            else if (op == "contingut ?"){
                map<int,Frase> contingut;
                contingut = texttriat.contingut_text();
            }
            
            else if (op == "frases"){
                int x,y;
                string s1;
                iss >> op;
                if(op == "//afegir signe de cometes  "){
                    getline(iss,s1);
                    texttriat.paraules_frase(s1);
                }
                else if(op == "(" ){
                    getline(iss,s1);
                    texttriat.expressio_frases(s1);
                }
                else{
                    //string::size_type sz;
                    istringstream ss(op);
                    ss >> x;
                    ss >> y;
                    texttriat.interval_frases(x,y);
                }  
            }

            else if (op == "nombre de frases ?"){
                texttriat.consultar_numfrases();
            }

            else if (op == "nombre de paraules ?"){
                texttriat.consultar_numparaules();
            }

            else if (op == "taula de frequencies ?"){
                texttriat.taula_frequencies();
            }

            else {
                cout << "error" << endl;
                while ( iss >> m) cout << m << endl;
            }

            getline(cin, linia);

        }
}




