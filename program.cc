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
	string linia,op;
	getline(cin,linia);
        while( linia != "sortir"){
            
            cout << linia << endl;
            string liniac = linia;
            istringstream iss(linia);
            iss >> op;
            //istringstream oss = iss;
            //string consulta;
            //ws(iss);
            //getline(iss,consulta);
            
            if(!biblio.consultar_triat()){
                
            }
            
            //consultes sense parametre explicit
            if(liniac == "eliminar text"){
                cout << "entra";
                biblio.eliminar_text();

            }
            
            else if(liniac == "tots textos ?"){
                biblio.tots_textos();
            }
            
            else if(liniac == "tots autors ?"){
                biblio.tots_autors();
            }
            
            else if(liniac == "info ?"){
                texttriat.info_text();
                //Falta fer el cout de les cites del textelse if(liniac == "info ?"){
                
                //Falta fer el cout de les cites del text
                //texttriat.autor_text();
            }
            

            else if (liniac == "contingut ?"){
                texttriat.contingut_text();
            }

            else if (liniac == "nombre de frases ?"){
                cout << texttriat.consultar_numfrases() << endl;
            }

            else if (liniac == "nombre de paraules ?"){
                cout << texttriat.consultar_numparaules() << endl;
            }

            else if (liniac == "taula de frequencies ?"){
                texttriat.taula_frequencies();
            }
            
            else if (liniac == "autor ?"){
                cout << texttriat.autor_text() << endl;
            }

            else if (liniac == "contingut ?"){
                texttriat.contingut_text();
            }

            else if (liniac == "nombre de frases ?"){
                cout << texttriat.consultar_numfrases() << endl;
            }

            else if (liniac == "nombre de paraules ?"){
                cout << texttriat.consultar_numparaules() << endl;
            }

            else if (liniac == "taula de frequencies ?"){
                texttriat.taula_frequencies();
            }
            
            
            //consultes amb parametre explicit
            
            else if(op == "afegirtext"){
                biblio.afegir_text();
            }

            else if(op == "triartext"){
				string s;
				bool b = false;
				getline(cin,s);
                texttriat = biblio.triar_text(s,b);
            }
            
            else if(op == "llegir cita"){
                int x,y;
                ws(iss);
                iss >> x;
                iss >> y;
                biblio.afegir_cita(x,y);

            }
            
            else if(op == "textos autor"){
                biblio.textos_autor();
            }
            
            //cal tractar paraula per paraula, no la frase
            
            else if(op == "substitueix"){
                string s1,s2;
                ws(iss);
                iss >> s1;
                iss >> s2;
                texttriat.substitueix_paraules(s1,s2);
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
            
            else {
                cout << "error" << endl;
                while ( iss >> op) cout << op << endl;
            }

            getline(cin, linia);

        }
}




