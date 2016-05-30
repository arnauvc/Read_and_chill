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
    string auxlinia, ant;
	bool triat = false;
    int l;
    bool primer = true;
    bool enter = false;
	getline(cin,linia);
    istringstream ass(linia);
    ass >> op;
    while(op != "sortir"){
        istringstream iss(linia);
        if (not primer and not enter) cout << endl;
        enter = false;
        iss >> op;
        auxlinia.clear();
		if(op == "afegir"){ 
            auxlinia += op;
            iss >> op;
            if(op == "text"){
                auxlinia += " ";
                auxlinia += op;
				iss >> op;
                if (char(op[0]) == '"' and op.size() == 1) {
                     auxlinia += " ";
                     auxlinia += op;
                     iss >> op;
                     auxlinia += op;
                     ant = op;
                }
                else {
                    auxlinia += " ";
                    auxlinia += op;
                    ant = op;
                }
                while (iss >> op) {
                    l = op.size();
                    if ((char(op[l-1]) == '"' or char(op[l-1]) == ','  or char(op[l-1]) == ';'  or char(op[l-1]) == ':' or char(op[l-1]) == '.'  or char(op[l-1]) == '?' or char(op[l-1]) == '!') and (op.size() == 1)) {
                        auxlinia += op;
                    }
                    else {
                        if ((char(op[0]) == '"' or char(op[0]) == ','  or char(op[0]) == ';'  or char(op[0]) == ':' or char(op[0]) == '.'  or char(op[0]) == '?' or char(op[0]) == '!') and (char(op[l-1]) == '"')) auxlinia += op;
                        else {
                            auxlinia += " ";
                            auxlinia += op;
                        }
                    }
                }
                cout << auxlinia << endl;
				string::size_type i = auxlinia.find(ant);
                if (i != string::npos){
                    auxlinia.erase(0, 13);
					auxlinia.erase(auxlinia.size()-1, auxlinia.size());
					biblio.afegir_text(auxlinia);
					if (not biblio.text_si_afegit()) {
						string jeje;
						getline(cin, jeje);
                        istringstream kkss(jeje);
                        kkss >> op;
						while (op != "****") {
                            getline(cin, jeje);
                            istringstream llss(jeje);
                            llss >> op;
                        }
						cout << "error" << endl;
					}
				}
            }
            else if (op == "cita") {
                auxlinia += " ";
                auxlinia += op;
				int x,y;
				iss >> x;
                string Result;
                stringstream convert;
                convert << x;
                Result = convert.str();
				iss >> y;
                auxlinia += " ";
                auxlinia += Result;
                string result;
                stringstream convertt;
                convertt << y;
                result = convertt.str();
                auxlinia += " ";
                auxlinia += result;
                cout << auxlinia << endl;
                if (triat) {
					biblio.afegir_cita(x,y);
				}
				else cout << "error" << endl;
			}
        }
		else if(op == "triar"){
			    auxlinia += op;
                iss >> op;
				//if(op == "text"){
				auxlinia += " ";
                auxlinia += op;
                while (iss >> op) {
                    l = op.size();
                    if ((char(op[0]) == '{') and (op.size() != 1)) {
                        auxlinia += " ";
                        auxlinia += op;
                    }
                    else {
                        if (char(op[0]) == '{') {
                            auxlinia += " ";
                            auxlinia += op;
                            iss >> op;
                            auxlinia += op;
                        }
                        else if ((char(op[l-1]) == '}') and (op.size() == 1)) {
                            auxlinia += op;
                        }
                        else {
                            auxlinia += " ";
                            auxlinia += op;
                        }
                    }
                }
                cout << auxlinia << endl;
				auxlinia.erase(0, 12);
				auxlinia.erase(auxlinia.size()-1, auxlinia.size());
				texttriat = biblio.triar_text(auxlinia);
				//triat = biblio.consultar_triat();
				//}
        }
        else if(op == "tots"){
            auxlinia += op;
			iss >> op;
            auxlinia += " ";
            auxlinia += op;
			if(op == "textos"){
                iss >> op;
                auxlinia += " ";
                auxlinia += op;
                cout << auxlinia << endl;
				biblio.tots_textos();
			}
			else if (op == "autors"){
                iss >> op;
                auxlinia += " ";
                auxlinia += op;
                cout << auxlinia << endl;
				biblio.tots_autors();
			}	
        }
        else if (op == "totes"){
            auxlinia += op;
			iss >> op;
            auxlinia += " ";
            auxlinia += op;
			//if (op == "cites"){
                iss >> op;
                auxlinia += " ";
                auxlinia += op;
                cout << auxlinia << endl;
				biblio.totes_cites();
			//}
		}
		else if(op == "eliminar"){
            auxlinia += op;
            iss >> op;
            auxlinia += " ";
            auxlinia += op;
			if (op == "cita"){
                iss >> op;
                string ref;
                l = op.size();
                if ((char(op[0]) == '"') and (l != 1) and (char(op[l-1]) == '"')) {
                    auxlinia += " ";
                    auxlinia += op;
                    op.erase(0, 1);
                    l = op.size();
                    op.erase (l-1, l-1);
                    ref = op;
                }
                else if ((char(op[0]) == '"') and (l != 1)) {
                    auxlinia += " ";
                    auxlinia += op;
                    op.erase(0, 1);
                    ref = op;
                    iss >> op;
                    auxlinia += op;
                }
                else {
                    auxlinia += " ";
                    auxlinia += op;
                    iss >> op;
                    //auxlinia += op;
                    l = op.size();
                    if ((char(op[l-1]) == '"') and (l != 1)) {
                        auxlinia += op;
                        op.erase(l-1, l-1);
                        ref = op;
                    }
                    else {
                        auxlinia += op;
                        ref = op;
                        iss >> op;
                        auxlinia += op;
                    }
                }
                cout << auxlinia << endl;
				biblio.eliminar_cita(ref);
			}
			else if (op == "text"){
                cout << auxlinia << endl;
				if(triat) biblio.eliminar_text();
				else cout << "error"<<endl;
			}
        }
		else if (op == "cites"){
			auxlinia += op;
			iss >> op;
            auxlinia += " ";
            auxlinia += op;
            int llll;
			if(op == "autor"){
                string autor, ant;
                ant = op;
                while (iss >> op) {
                    l = op.size();
                    llll = ant.size();
                    if(char(op[0]) != '?') {
                        if((char(op[0]) == '"') and (l != 1) and (char(op[l-1]) == '"')){
                            auxlinia += " ";
                            auxlinia += op;
                            op.erase(0, 1);
                            l = op.size();
                            op.erase(l-1, l-1);
                            autor += op;
                        }
                        else if ((char(op[0]) == '"') and (l != 1)) {
                            auxlinia += " ";
                            auxlinia += op;
                            op.erase(0, 1);
                            autor += op;
                        }
                        else if (char(op[0]) == '"') {
                                if (ant == "autor") {
                                    auxlinia += " ";
                                    auxlinia += op;
                                }
                                else auxlinia += op;
                        }
                        else { 
                            if ((char(op[l-1]) == '"') and (l != 1)) {
                                if (char(ant[llll-1]) != '"') auxlinia += " ";
                                auxlinia += op;
                                op.erase(l-1, l-1);
                                if (char(ant[llll-1]) != '"') autor += " ";
                                autor += op;
                            }
                            else if (char(op[l-1]) == '"') {
                                auxlinia += op;
                            }
                            else {
                                if ((char(ant[0]) == '"') and (ant.size() == 1)) {
                                    auxlinia += op;
                                    autor += op;
                                }
                                else {
                                    auxlinia += " ";
                                    auxlinia += op;
                                    autor += " ";
                                    autor += op;
                                }
                            }
                        }
                    }
                    ant = op;
                }
                auxlinia += " ";
                auxlinia += op;
                cout << auxlinia << endl;
				biblio.cites_autor(autor);
            }
			else if (op == "?"){
                cout << auxlinia << endl;
				if(triat){
				    bool b = false;
				    biblio.cites_text(b);
				}
				else cout << "error"<<endl;
			}  
		}
		else if(op == "info"){
            auxlinia += op;
			iss >> op;
            auxlinia += " ";
            auxlinia += op;
			if(op == "?"){
                cout << auxlinia << endl;
                if(triat){
					bool bc = true;
					texttriat.info_text();
					biblio.cites_text(bc);
				}
                else cout << "error" << endl;
			}
			else if(op == "cita"){
				string refer;
                iss >> op;
                l = op.size();
                if ((char(op[0]) == '"') and (l != 1) and (char(op[l-1]) == '"')) {
                    auxlinia += " ";
                    auxlinia += op;
                    op.erase(0, 1);
                    l = op.size();
                    op.erase (l-1, l-1);
                    refer = op;
                }
                else if ((char(op[0]) == '"') and (l != 1)) {
                    auxlinia += " ";
                    auxlinia += op;
                    op.erase(0, 1);
                    refer = op;
                    iss >> op;
                    auxlinia += op;
                }
                else {
                    auxlinia += " ";
                    auxlinia += op;
                    iss >> op;
                    //auxlinia += op;
                    l = op.size();
                    if ((char(op[l-1]) == '"') and (l != 1)) {
                        auxlinia += op;
                        op.erase(l-1, l-1);
                        refer = op;
                    }
                    else {
                        auxlinia += op;
                        refer = op;
                        iss >> op;
                        auxlinia += op;
                    }
                }
                iss >> op;
                auxlinia += " ";
                auxlinia += op;
                cout << auxlinia << endl;
                biblio.info_cita(refer);
			}
        }
        else if(op == "textos"){
            auxlinia += op;
			iss >> op;
            auxlinia += " ";
            auxlinia += op;
            int lllll;
			if(op == "autor"){
				string autor1, ant;
                ant = op;
                while (iss >> op) {
                    l = op.size();
                    lllll = ant.size();
                    if(char(op[0]) != '?') {
                        if((char(op[0]) == '"') and (l != 1) and (char(op[l-1]) == '"')){
                            auxlinia += " ";
                            auxlinia += op;
                            op.erase(0, 1);
                            l = op.size();
                            op.erase(l-1, l-1);
                            autor1 += op;
                        }
                        else if ((char(op[0]) == '"') and (l != 1)) {
                            auxlinia += " ";
                            auxlinia += op;
                            op.erase(0, 1);
                            autor1 += op;
                        }
                        else if (char(op[0]) == '"') {
                                if (ant == "autor") {
                                    auxlinia += " ";
                                    auxlinia += op;
                                }
                                else auxlinia += op;
                        }
                        else { 
                            if ((char(op[l-1]) == '"') and (l != 1)) {
                                if (char(ant[lllll-1]) != '"') auxlinia += " ";
                                auxlinia += op;
                                op.erase(l-1, l-1);
                                if (char(ant[lllll-1]) != '"') autor1 += " ";
                                autor1 += op;
                            }
                            else if (char(op[l-1]) == '"') {
                                auxlinia += op;
                            }
                            else {
                                if ((char(ant[0]) == '"') and (ant.size() == 1)) {
                                    auxlinia += op;
                                    autor1 += op;
                                }
                                else {
                                    auxlinia += " ";
                                    auxlinia += op;
                                    autor1 += " ";
                                    autor1 += op;
                                }
                            }
                        }
                    }
                    ant = op;
                }
                auxlinia += " ";
                auxlinia += op;
                cout << auxlinia << endl;
				biblio.textos_autor(autor1);
			}
        }
        else if (op == "contingut"){
            auxlinia += op;
            iss >> op;
            auxlinia += " ";
            auxlinia += op;
            //if(op == "?"){
                cout << auxlinia << endl;
                if (triat) texttriat.contingut_text();
                else cout << "error"<<endl;
            //}
        }
        else if (op == "autor"){
            auxlinia += op;
            iss >> op;
            auxlinia += " ";
            auxlinia += op;
            //if(op == "?"){
                cout << auxlinia << endl;
                if (triat) cout << texttriat.autor_text() << endl;
                else cout << "error" << endl;
            //}
        }
        else if (op == "nombre"){
            auxlinia += op;
            iss >> op;
            auxlinia += " ";
            auxlinia += op;
            if(op == "de"){
                iss >> op;
                auxlinia += " ";
                auxlinia += op;
                if(op == "frases"){
                    iss >> op;
                    auxlinia += " ";
                    auxlinia += op;
                    cout << auxlinia << endl;
                    if (triat) cout << texttriat.consultar_numfrases() << endl;
                    else cout <<"error"<<endl;
                }
                else if(op == "paraules"){
                    iss >> op;
                    auxlinia += " ";
                    auxlinia += op;
                    cout << auxlinia << endl;
                    if (triat) cout << texttriat.consultar_numparaules() << endl;
                    else cout << "error" << endl;	
                }
            }
        }
        else if (op == "taula"){
            auxlinia += op;
            iss >> op;
            auxlinia += " ";
            auxlinia += op;
            //if(op == "de"){
                iss >> op;
                auxlinia += " ";
                auxlinia += op;
                iss >> op;
                auxlinia += " ";
                auxlinia += op;
                cout << auxlinia << endl;
                //if(op == "frequencies"){
                    if(triat) texttriat.taula_frequencies();
                    else cout << "error" << endl;
                //}
            //}
        }
        else if(op == "substitueix"){
            auxlinia += op;
            string s1, s2;
            iss >> op;
            l = op.size();
            if ((char(op[0]) == '"') and (l != 1) and (char(op[l-1]) == '"')) {
                auxlinia += " ";
                auxlinia += op;
                op.erase(0, 1);
                l = op.size();
                op.erase (l-1, l-1);
                s1 = op;
            }
            else if ((char(op[0]) == '"') and (l != 1)) {
                auxlinia += " ";
                auxlinia += op;
                op.erase(0, 1);
                s1 = op;
                iss >> op;
                auxlinia += op;
            }
            else {
                auxlinia += " ";
                auxlinia += op;
                iss >> op;
                //auxlinia += op;
                l = op.size();
                if ((char(op[l-1]) == '"') and (l != 1)) {
                    auxlinia += op;
                    op.erase(l-1, l-1);
                    s1 = op;
                }
                else {
                    auxlinia += op;
                    s1 = op;
                    iss >> op;
                    auxlinia += op;
                }
            }
            iss >> op;
            auxlinia += " ";
            auxlinia += op;
            iss >> op;
            l = op.size();
            if ((char(op[0]) == '"') and (l != 1) and (char(op[l-1]) == '"')) {
                auxlinia += " ";
                auxlinia += op;
                op.erase(0, 1);
                l = op.size();
                op.erase (l-1, l-1);
                s2 = op;
            }
            else if ((char(op[0]) == '"') and (l != 1)) {
                auxlinia += " ";
                auxlinia += op;
                op.erase(0, 1);
                s2 = op;
                iss >> op;
                auxlinia += op;
            }
            else {
                auxlinia += " ";
                auxlinia += op;
                iss >> op;
                //auxlinia += op;
                l = op.size();
                if ((char(op[l-1]) == '"') and (l != 1)) {
                    auxlinia += op;
                    op.erase(l-1, l-1);
                    s2 = op;
                }
                else {
                    auxlinia += op;
                    s2 = op;
                    iss >> op;
                    auxlinia += op;
                }
            }
            cout << auxlinia << endl;
		    if(triat){
                texttriat.substitueix_paraules(s1,s2);
                //if (ban) biblio.actualitzar_text(texttriat);
            }
		    else cout << "error" << endl;
	    }
        else if (op == "frases"){
                auxlinia += op;
                string s1, ante;
                ante = op;
                iss >> op;
                int lll;
                if(char(op[0]) == '"') {
                while (char(op[0]) != '?') {
                    l = op.size();
                    lll = ante.size();
                    //if(char(op[0]) != '?') {
                        if((char(op[0]) == '"') and (l != 1) and (char(op[l-1]) == '"')){
                            auxlinia += " ";
                            auxlinia += op;
                            op.erase(0, 1);
                            l = op.size();
                            op.erase(l-1, l-1);
                            s1 += op;
                        }
                        else if ((char(op[0]) == '"') and (l != 1)) {
                            auxlinia += " ";
                            auxlinia += op;
                            op.erase(0, 1);
                            s1 += op;
                        }
                        else if (char(op[0]) == '"') {
                                if (ante == "frases") {
                                    auxlinia += " ";
                                    auxlinia += op;
                                }
                                else auxlinia += op;
                        }
                        else { 
                            if ((char(op[l-1]) == '"') and (l != 1)) {
                                if (char(ante[lll-1]) != '"') auxlinia += " ";
                                auxlinia += op;
                                op.erase(l-1, l-1);
                                if (char(ante[lll-1]) != '"') s1 += " ";
                                s1 += op;
                            }
                            else if (char(op[l-1]) == '"') {
                                auxlinia += op;
                            }
                            else {
                                if ((char(ante[0]) == '"') and (lll == 1)) {
                                    auxlinia += op;
                                    s1 += op;
                                }
                                else {
                                    /*if (char(ante[0]) == '"')*/ auxlinia += " ";
                                    auxlinia += op;
                                    s1 += " ";
                                    s1 += op;
                                }
                            }
                        }
                        //}
                        ante = op;
                        iss >> op;
                }
                    auxlinia += " ";
                    auxlinia += op;
                    cout << auxlinia << endl;
                    if(triat) texttriat.paraules_frase(s1);
                    else cout << "error" <<endl;
                }
                else if((char(op[0]) == '(') or (char(op[0]) == '{')){
                    string expresio, antt;
                    int ll;
                    bool expp;
                    bool prpr = true;
                    if (char(op[0]) == '(') expp = true;
                    else expp = false;
                    while (char(op[0]) != '?') {
                        l = op.size();
                        ll = antt.size();
                        if ((char(op[0]) == ')') or (char(op[0]) == '(') or (char(op[0]) == '}')) {
                            if((char(antt[0]) == '&') or (char(antt[0]) == '|')){
                                expresio += " ";
                                expresio += op;
                            }
                            else expresio += op;
                            
                        }
                        else if ((char(op[0]) == '{') and prpr) {
                            //expresio += " ";
                            expresio += op;
                            prpr = false;
                        }
                        else if ((char(op[0]) == '{') and (char(antt[ll-1]) != '&') and (char(antt[ll-1]) != '|')) {
                            expresio += op;
                        }
                        else if ((char(op[0]) == '{') and ((char(antt[ll-1]) == '&') or (char(antt[ll-1]) == '|'))) {
                            expresio += " ";
                            expresio += op;
                        }
                        else if ((char(op[0]) == '&') or ((char(op[0]) == '|'))) {
                            expresio += " ";
                            expresio += op;
                        }
                        else {
                            if (char(antt[ll-1]) == '{') expresio += op;
                            else {
                                expresio += " ";
                                expresio += op;
                            }
                        }
                        prpr = false;
                        antt = op;
                        iss >> op;
                    }
                    auxlinia += " ";
                    auxlinia += expresio;
                    auxlinia += " ";
                    auxlinia += op;
                    cout << auxlinia << endl;
                    if(triat) texttriat.expressio_frases(expresio, expp);
                    else cout << "error" << endl;
                }
                else{
                    auxlinia += " ";
                    auxlinia += op;
                    int x,y;
                    stringstream convert(op);
                    convert >> x;
                    iss >> op;
                    auxlinia += " ";
                    auxlinia += op;
					stringstream convertt(op);
					convertt >> y;
                    iss >> op;
                    auxlinia += " ";
                    auxlinia += op;
                    cout << auxlinia << endl;
                    if(triat){
                        bool ba = false;
                        map<int,Frase> m = texttriat.interval_frases(x,y,ba);
                        if(ba){
                            for(map<int,Frase>::iterator j = m.begin(); j != m.end(); ++j){
                                cout << j->first << " ";
                                j->second.escriu_frase();
                            }
                        }
                    }
                    else cout << "error" << endl;
                }
		}
        else enter = true;
        primer = false;
        triat = biblio.consultar_triat();
        getline(cin, linia);
        istringstream ess(linia);
        ess >> op;
	}
}
