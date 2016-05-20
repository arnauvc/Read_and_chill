/**
 * @mainpage Practica PRO2 - Gestor de textos i cites
*/

/** @file program.cc
    @brief Programa principal de <em>Practica PRO2 - Gestor de textos i cites</em>.
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
        op = "";
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
					if (not biblio.text_si_afegit()) {
						string jeje;
						getline(cin, jeje);
						while (jeje != "****") getline(cin, jeje);
						cout << "error" << endl;
					}
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
					triat = biblio.consultar_triat();
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
				string::size_type i = linia.find(op);
                if (i != string::npos){
                    linia.erase(0, i+op.size()+2);
					linia.erase(linia.size()-3, linia.size());
					biblio.cites_autor(linia);
				}
            }
			else if (op == "?"){
				if(triat){
				bool b = false;
				biblio.cites_text(b);
				}
				else cout << "error"<<endl;
			}
            
		}
		else if(op == "info"){
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
        else if (op == "contingut"){
            ws(iss);
            iss >> op;
            if(op == "?"){
                if (triat)texttriat.contingut_text();
                else cout << "error"<<endl;
            }
        }
        else if (op == "autor"){
            ws(iss);
            iss >> op;
            if(op == "?"){
                if(triat) cout << texttriat.autor_text() << endl;
                else cout << "error" << endl;
            }
        }
        else if (op == "nombre"){
            ws(iss);
            iss >> op;
            if(op == "de"){
                ws(iss);
                iss >> op;
                if(op == "frases"){
                    if(triat) cout << texttriat.consultar_numfrases() << endl;
                    else cout <<"error"<<endl;
                }
                else if(op == "paraules"){
                    if(triat) cout << texttriat.consultar_numparaules() << endl;
                    else cout << "error" << endl;	
                }
            }
        }
        else if (op == "taula"){
			
			triat = true;
            ws(iss);
            iss >> op;
            if(op == "de"){
				
                ws(iss);
                iss >> op;
                if(op == "frequencies"){
					
                    if(triat){
						
						texttriat.taula_frequencies();
					}
                    else cout << "error" << endl;
                }
            }
            
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
            
                //linia1 = linia;
                
                s1 = s1.substr(1, (s1.size()-2));
                s2 = s2.substr(1, (s2.size()-2));
            
			
            texttriat.substitueix_paraules(s1,s2);
			}
			else cout << "error" << endl;
		}
        else if (op == "frases"){
                string s1,tmp;
                bool bac = true;
                ws(iss);
				tmp = op;
                iss >> op;
                
                if(op[0] == '"'){
                    if(triat){
                    
                    op.erase(op.begin(), op.begin()+1);
                    s1 += op;
                    s1 += " ";
                    
                    while(iss >> op and op != "?"){
                        
                        if(op[op.size()-1] != '"'){
                            s1 += op;
                            s1 += " ";
                            ws(iss);
                        }
                        else {
                            op.erase(op.size()-1, op.size());
                            s1 += op;
                            s1 += " ";
                        }
                        bac = false;
                        
                    }
                    
                    if(bac){
                        s1.erase(s1.size()-2, s1.size());
                    }
                    
                    texttriat.paraules_frase(s1);
                    }
                    else cout << "error" <<endl;
                }
                else if(op[0] == '(' ){
                    if(triat){
                        
                        string::size_type i = linia.find(tmp);
                        if (i != string::npos) {
                            linia.erase(0, i+tmp.length()+1);
                            linia.erase(linia.size()-2, linia.size());
                            
                            texttriat.expressio_frases(linia);
                        }
                    }
                    else cout << "error" << endl;
                }
                else{
                    if(triat){
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
                    else cout << "error" << endl;
                }
		}
		
        else {
			if(!(linia.empty()))cout << "error comanda" << endl;
			
        }
        
    triat = biblio.consultar_triat();
    getline(cin, linia);
	}
}
