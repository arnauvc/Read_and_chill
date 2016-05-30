#include "Frase.hh"

Frase::Frase() {

}

Frase::~Frase() {}

void Frase::llegir_frase(list<string> frase_ini) {
	frase_in = frase_ini;
}

void Frase::escriu_frase() const {
    bool primer = true;
    for (list<string>::const_iterator it = frase_in.begin(); it != frase_in.end(); ++it) {
        if (primer) {
            cout << *it;
            primer = false;
        }
        else {
            if (*it == "," or *it == ":" or *it == ";" or *it == "." or *it == "?" or *it == "!") {
                cout << *it;
            }
            else cout << " " << *it;
        }
    }
    cout << endl;
}

bool Frase::trobat(string s) const {
    bool trobat = false;
    string op, act;
    istringstream ess(s);
    ess >> op;
    for (list<string>::const_iterator it = frase_in.begin(); it != frase_in.end() and not trobat; ++it) {
        if(*it == op){
            istringstream iss(s);
            iss >> op;
            list<string>::const_iterator it1 = it;
            ++it1;
            trobat = true;
            while (iss >> op and it1 != frase_in.end() and trobat) {
                if (*it1 == "," or *it1 == ":" or *it1 == ";") ++it1;
                if (*it1 != op) trobat = false;
                ++it1;
            }
            istringstream oss(s);
            oss >> op;
        }
    }
    return trobat;
}

void Frase::canvi_paraules(string s1, string s2) {
    for (list<string>::iterator it = frase_in.begin(); it != frase_in.end(); ++it) {
        if (*it == s1) *it = s2;
    }
}
