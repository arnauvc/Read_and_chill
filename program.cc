/**
 * @mainpage Practica PRO2 - Gestor de textos i cites
*/

/** @file program.cc
    @brief Programa principal de <em>Pràctica PRO2 - Gestor de textos i cites</em>.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstddef>
#include "Biblioteca.hh"
#include "Text.hh"

using namespace std;

/** @brief Programa principal.
*/

int main(){
	Biblioteca biblio;
    Text texttriat;
	string linia,op, auxiliar;
	bool triat = false;
	getline(cin,linia);
	auxiliar = linia;
    while( linia != "sortir"){
		auxiliar = linia;
		cout << linia << endl;
        istringstream iss(linia);
        iss >> op;
		if(op == "afegir"){ //FUNCIONA
			ws(iss);
            iss >> op;
            if(op == "text"){
				ws(iss);
				iss >> op;
				string::size_type i = linia.find(op);
                if (i != string::npos){
                    linia.erase(0, 12);
					linia.erase(linia.size(), linia.size());
					biblio.afegir_text(linia);
				}
            }
            else if(op == "cita"){
				int x,y;//primera frase y ultima frase
                ws(iss);
                iss >> x;
                iss >> y;
                biblio.afegir_cita(x,y);
                }
        }
		else if(op == "triar"){ //FUNCIONA . FALTA MIRA TITOL I AUTOR
                string s;
                iss >> op;
				if(op == "text"){
					linia.erase(0, 12);
					linia.erase(linia.size()-1, linia.size());
					texttriat = biblio.triar_text(linia);
				}
        }
        else if(linia == "tots textos ?"){
			biblio.tots_textos();
        }
        else if(linia == "tots autors ?"){
            biblio.tots_autors();
        }
        else if(linia == "totes cites ?"){
            biblio.totes_cites();
        }
        else if(op == "textos"){ //textos autor " " ?
			ws(iss);
			iss >> op;
			string::size_type i = linia.find(op);
            if (i != string::npos){
				linia.erase(0, i+op.length()+2);
				linia.erase(linia.size()-3, linia.size());
				biblio.textos_autor(linia);
			}
        }
		else if(triat && !(linia.empty())){
			if(linia == "eliminar text"){
                biblio.eliminar_text();
				triat = false;
            }
            else if(linia == "info ?"){
				cout << "entra dins de info ?" << endl;
				bool b = true;
                texttriat.info_text();
                biblio.cites_text(b);
                //Falta fer el cout de les cites del textelse if(liniac == "info ?"){
                //Falta fer el cout de les cites del text
                //texttriat.autor_text();
            }
            else if(op == "info"){
				ws(iss);
				iss >> op;
				if(op == "cita"){
					string s;
					ws(iss);
					iss >> s;
					s = s.substr(1, (s.size()-2));
					biblio.info_cita(s);
				}
            }
            else if (linia == "cites ?"){
				bool b = false;
				biblio.cites_text(b);
			}
			else if(op == "cites"){
				ws(iss);
				iss >> op;
				if (op == "autor"){
					string s;
					ws(iss);
					iss >> s;
					s = s.substr(1, (s.size()-2));
					biblio.cites_autor(s);
				}
			}
			else if(op == "afegir"){ //FUNCIONA
				ws(iss);
				iss >> op;
				if(op == "cita"){
					int x,y;//primera frase y ultima frase
					ws(iss);
					iss >> x;
					iss >> y;
					biblio.afegir_cita(x,y);
					}
			}
            else if (linia == "contingut ?"){
                texttriat.contingut_text();
            }
            else if (linia == "nombre de frases ?"){
                cout << texttriat.consultar_numfrases() << endl;
            }
            else if (linia == "nombre de paraules ?"){
                cout << texttriat.consultar_numparaules() << endl;
            }
            else if (linia == "taula de frequencies ?"){
                texttriat.taula_frequencies();
            }
            else if (linia == "autor ?"){
                cout << texttriat.autor_text() << endl;
            }
            else if (linia == "contingut ?"){
                texttriat.contingut_text();
            }
            else if (linia == "nombre de frases ?"){
                cout << texttriat.consultar_numfrases() << endl;
            }
            else if (linia == "nombre de paraules ?"){
                cout << texttriat.consultar_numparaules() << endl;
            }
            else if(op == "eliminar"){
				if (op == "cita"){
					string s;//referencia
					ws(iss);
					iss >> s;
					s = s.substr(1, (s.size()-2));
					biblio.eliminar_cita(s);
				}
			}
            else if(op == "substitueix"){
                string s1,tmp,s2;
                ws(iss);
                iss >> s1;
				ws(iss);
                iss >> tmp;
				ws(iss);
                iss >> s2;
                s1 = s1.substr(1, (s1.size()-2));
                s2 = s2.substr(1, (s2.size()-2));
                texttriat.substitueix_paraules(s1,s2);
            }
            else if (op == "frases"){
                string s1,tmp;
                ws(iss);
				tmp = op;
                iss >> op;
                if(op[0] == '"'){
                    op.erase(op.begin(), op.begin()+1);
                    s1 += op;
                    s1 += " ";
                    ws(iss);
                    iss >> op;
                    while(op[op.size()-1] != '"'){
                        s1 += op;
                        s1 += " ";
                        ws(iss);
                        iss >> op;
                    }
                    op.erase(op.size()-1, op.size());
                    s1 += op;
                    s1 += " ";
                    texttriat.paraules_frase(s1);
                }
                else if(op[0] == '(' ){
                    string::size_type i = linia.find(tmp);
                    if (i != string::npos) {
						linia.erase(0, i+tmp.length()+1);
						linia.erase(linia.size()-2, linia.size());
						cout << linia <<endl;
						//texttriat.expressio_frases(linia);
					}
                }
                else{
					int x,y;
					/*
					cout <<"auxiliar: "<<auxiliar << endl;
					istringstream isss(auxiliar);
					*/
					//iss >> x;
					stringstream convert(op);
					convert >> x;
					ws(iss);
                    iss >> y;
					cout << "l'interval es: " << x << " " << y << endl;
                    map<int,Frase> m = texttriat.interval_frases(x,y);
                    for(map<int,Frase>::iterator j = m.begin();j != m.end();++j){
                        cout << j->first << " ";
                        j->second.escriu_frase();
                    }
                }
			}
			else {
				cout << "error de comanda" << endl;
			}
		}
        else {
			if(!(linia.empty()))cout << "comanda incorrecte" << endl;
			triat = biblio.consultar_triat();
        }
        getline(cin, linia);
	}
}
