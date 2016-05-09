#include "Frase.hh"

/* Constants */

const char *ER1 = "error";
#include <exception>

Frase::Frase() {
	num_paraules = 0;
}

Frase::~Frase() {}

void Frase::llegir_frase() {
    string s;
    while (cin >> s and s != ".") { //falta mirar si nomes es acabat en punt o amb mes signes de puntuacio
    	frase_in.push_back(s);
    	++num_paraules;
    }
}

void Frase::escriu_frase() {
	int x = frase_in.size();
	bool primer = true;
	for (int i = 0; i < x; ++i) {
		if (primer) {
			cout << frase_in[i];
			primer = false;
		}
		else cout << " " << frase_in[i];
	}
	cout << endl;
}
