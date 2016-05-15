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
            string liniac = linia;
            istringstream iss(linia);
            iss >> op;
            
            if(liniac == "eliminar text"){
                triat = false;
                biblio.eliminar_text();
            }
            else if(liniac == "tots textos ?"){
                biblio.tots_textos();
            }
            else if(liniac == "tots autors ?"){
                biblio.tots_autors();
            }
            else if(liniac == "info ?" && triat){
                texttriat.info_text();
                //Falta fer el cout de les cites del textelse if(liniac == "info ?"){
                //Falta fer el cout de les cites del text
                //texttriat.autor_text();
            }
            else if (liniac == "contingut ?"){
                if (triat) texttriat.contingut_text();
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
            //consultes amb parametre explicit
            else if(op == "afegir"){
                ws(iss);
                iss >> op;
                if(op == "text"){
                    string::size_type i = liniac.find(op);
                    if (i != string::npos) liniac.erase(0, i+(op.length()+1));
                    biblio.afegir_text(liniac);
                }
                else if(op == "cita"){
                    int x,y;//primera frase y ultima frase
                    ws(iss);
                    iss >> x;
                    iss >> y;
                    biblio.afegir_cita(x,y);
                }
                
            }
            else if(op == "triar"){
                string s;
                //bool b = false;
                iss >> op;
                string::size_type i = liniac.find("text");
                if (i != string::npos) liniac.erase(0,i+(op.length()+1));
                liniac.erase(liniac.begin(), liniac.begin()+1);
                liniac.erase(liniac.size()-1, liniac.size());
                triat = true;
                texttriat = biblio.triar_text(liniac);
                //if(!b) cout << "No trobat "<< endl;
            }
            else if(op == "infocita"){
                string s;//referencia
                //cin >> s;
                ws(iss);
                iss >> s;
                biblio.info_cita(s);
            }
            else if(op == "citesautor"){
                string s;//autor
                //cin >> s;
                //ws(iss);
                //iss >> s;
                getline(cin, s);
                biblio.cites_autor(s);
            }
            else if(op == "totescites"){
                biblio.totes_cites();
            }
            else if(op == "eliminarcita"){
                string s;//referencia
                //cin >> s;
                ws(iss);
                iss >> s;
                biblio.eliminar_cita(s);
            }
            else if(op == "textosautor"){
                string s;
                getline(cin,s);
                biblio.textos_autor(s);
            }
            //cal tractar paraula per paraula, no la frase
            else if(op == "substitueix" && triat){
                string s1,tmp,s2;
                ws(iss);
                iss >> s1;
                iss >> tmp;
                iss >> s2;
                s1.erase(s1.begin(), s1.begin()+1);
                s1.erase(s1.size()-1, s1.size());
                s2.erase(s2.begin(), s2.begin()+1);
                s2.erase(s2.size()-1, s2.size());
                cout << "arriba aqui" <<endl;
                texttriat.substitueix_paraules(s1,s2);
                texttriat = biblio.triar_text(s2);
                cout << "surt" <<endl;
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
                    string::size_type i = liniac.find(tmp);
                    if (i != string::npos) liniac.erase(i, tmp.length()+1);
                    cout << liniac <<endl;
                    //texttriat.expressio_frases(linia);
                }
                else{
                    int x,y;
                    
                    istringstream ss(op);
                    ss >> x;
                    ss >> y;
                    
                    /*
                    iss >> x;
                    ws(iss);
                    iss >> y;
                    */
                    cout << x <<" " <<y <<endl;
                    map<int,Frase> m = texttriat.interval_frases(x,y);
                    for(map<int,Frase>::iterator j = m.begin();j != m.end();++j){
                        cout << j->first << " ";
                        j->second.escriu_frase();
                    }
                }
            }
            else {
                if(!(linia.empty()))cout << "comanda incorrecte" << endl;
            }
            getline(cin, linia);
        }
}
