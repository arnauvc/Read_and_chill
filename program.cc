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
	string linia,op;
	bool triat = false;
	getline(cin,linia);
    while( linia != "sortir"){
		cout << linia << endl;
        istringstream iss(linia);
        iss >> op;
		if(op == "afegir"){ 
			ws(iss);
            iss >> op;
            if(op == "text"){
				ws(iss);
				iss >> op;
				string::size_type i = linia.find(op);
                if (i != string::npos){
                    linia.erase(0, 13);
					linia.erase(linia.size()-1, linia.size());
					biblio.afegir_text(linia);
				}
            }
            else if (op == "cita"){
				if(triat){
					int x,y;//primera frase y ultima frase
					ws(iss);
					iss >> x;
					iss >> y;
					biblio.afegir_cita(x,y);
				}
				else cout << "error" << endl;
			}
        }
		else if(op == "triar"){
                string s;
                iss >> op;
				if(op == "text"){
					linia.erase(0, 12);
					linia.erase(linia.size()-1, linia.size());
					texttriat = biblio.triar_text(linia);
				}
        }
        else if(op == "tots"){
			ws(iss);
			iss >> op;
			if(op == "textos"){
				biblio.tots_textos();
			}
			else if (op == "autors"){
				biblio.tots_autors();
			}	
        }
        else if (op == "totes"){
			ws(iss);
			iss >> op;
			if (op == "cites"){
				biblio.totes_cites();
			}
		}
		else if(op == "eliminar"){
			ws(iss);
            iss >> op;
			if (op == "cita"){
				string s;//referencia
				ws(iss);
				iss >> s;
				s = s.substr(1, (s.size()-2));
				biblio.eliminar_cita(s);
			}
			else if (op == "text"){
				if(triat){
				biblio.eliminar_text();
				triat = biblio.consultar_triat();
				}
				else cout << "error"<<endl;
			}
        }
		else if (op == "cites"){
			ws(iss);
			iss >> op;
			if(op == "autor"){
				
			}
			else if (op == "?"){
				if(triat){
				bool b = false;
				biblio.cites_text(b);
				}
				else cout << "error"<<endl;
			}
		}
		else if(linia == "info"){
			ws(iss);
			iss >> op;
			if(op == "?"){
                if(triat){
					bool bc = true;
					texttriat.info_text();
					biblio.cites_text(bc);
					}
                else cout << "error" << endl;
			}
			else if(op == "cita"){
				string s;
                ws(iss);
                iss >> s;
                s = s.substr(1, (s.size()-2));
                biblio.info_cita(s);
			}
        }
        else if(op == "textos"){ //textos autor " " ?
			ws(iss);
			iss >> op;
			if(op == "autor"){
				string::size_type i = linia.find(op);
				if (i != string::npos){
					linia.erase(0, i+op.length()+2);
					linia.erase(linia.size()-3, linia.size());
					biblio.textos_autor(linia);
				}
			}
        }
        else if (linia == "contingut ?"){
            if (triat)texttriat.contingut_text();
			else cout << "error"<<endl;
        }
        else if (linia == "nombre de frases ?"){
            if(triat) cout << texttriat.consultar_numfrases() << endl;
			else cout <<"error"<<endl;
        }
        else if (linia == "nombre de paraules ?"){
            if(triat) cout << texttriat.consultar_numparaules() << endl;
			else cout << "error" << endl;		
		}
        else if (linia == "taula de frequencies ?"){
            if(triat)texttriat.taula_frequencies();
			else cout << "error" << endl;
        }
        else if (linia == "autor ?"){
            if(triat) cout << texttriat.autor_text() << endl;
			else cout << "error" << endl;
        }
        else if (linia == "contingut ?"){
			if(triat)texttriat.contingut_text();
			else cout << "error" <<endl;
        }
        else if (linia == "nombre de frases ?"){
            if(triat) cout << texttriat.consultar_numfrases() << endl;
			else cout << "error" <<endl;
        }
        else if (linia == "nombre de paraules ?"){
             if(triat)cout << texttriat.consultar_numparaules() << endl;
			 else cout << "error" << endl;
        }   
        else if(op == "substitueix"){
			if(triat){
			string s1,tmp,s2, linia1;
            ws(iss);
			iss >> s1;
			ws(iss);
            iss >> tmp;
			ws(iss);
			iss >> s2;
			cout << s1 <<" "<< s2 << endl;
			linia1 = linia;
			
			string::size_type i = linia1.find(s1);
            if (i != string::npos) {
				linia1.erase(0, 13);
				linia1.erase(i+(s1.length()), linia1.size());
			}
			string::size_type j = linia.find(s2);
            if (j != string::npos) {
				linia.erase(0, j+s1.length()+3);
				linia.erase(j+s2.length(), linia.size());
			cout << s1 <<" "<< s2 << endl;
			}
		/*
            s1 = s1.substr(1, (s1.size()-2));
            s2 = s2.substr(1, (s2.size()-2));
		
		*/	
			cout << s1 <<" "<< s2 << endl;
            texttriat.substitueix_paraules(linia1,linia);
			}
			else cout << "error" << endl;
		}
        else if (op == "frases"){
			if(triat){
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
						texttriat.expressio_frases(linia);
					}
                }
                else{
					int x,y;
					stringstream convert(op);
					convert >> x;
					ws(iss);
                    iss >> y;
                    bool ba = false;
                    map<int,Frase> m = texttriat.interval_frases(x,y,ba);
                    if(ba){
                        for(map<int,Frase>::iterator j = m.begin();j != m.end();++j){
                            cout << j->first << " ";
                            j->second.escriu_frase();
                        }
                    }
                }
			}
			else cout << "error" <<endl;
		}
        else {
			if(!(linia.empty()))cout << "error" << endl;
			triat = biblio.consultar_triat();
        }
        getline(cin, linia);
	}
}
