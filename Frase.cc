#include "Frase.hh"

Frase::Frase() {
	num_paraules = 0;
}

Frase::~Frase() {}

void Frase::llegir_frase(string s, Taulesaux &tau, int numf) {
    string ant;
    string op;
    istringstream iss(s);
    iss >> op;
    int l = op.size();	
    while (char(op[l-1]) != '.' and char(op[l-1]) != '?' and char(op[l-1]) != '!') {
        if (char(op[l-1]) == ',' or char(op[l-1]) == ':' or char(op[l-1]) == ';') {
            string tmp = op;
            op.erase(l-1);
            frase_in.push_back(make_pair(op, ant));
            tau.insertar_paraula(op, numf);
            ant = op;
            string c;
            char car = tmp[l-1];
            if (car == ',') c = ",";
            else if (car == ':') c = ":";
            else c = ";";
            frase_in.push_back(make_pair(c, ant));
            ant = c;
    	}
    	else {
            frase_in.push_back(make_pair(op, ant));
            tau.insertar_paraula(op, numf);
    	    ant = op;
        }
    	++num_paraules;
    	ws(iss);
    	iss >> op;
    	l = op.size();
    }
    char car = op[l-1];
    string c;
    if (car == '.') c = ".";
    else if (car == '?') c = "?";
    else c = "!";
    op.erase(l-1);
    frase_in.push_back(make_pair(op, ant));
    tau.insertar_paraula(op, numf);
    frase_in.push_back(make_pair(c, ant)); 
    ++num_paraules;
    
}

void Frase::escriu_frase() {
    int x = frase_in.size();
    bool primer = true;
    for (int i = 0; i < x; ++i) {
        if (primer) {
            cout << frase_in[i].first;
            primer = false;
        }
        else if (i < x-1) {
            if (frase_in[i].first == "," or frase_in[i].first == ":" or frase_in[i].first == ";") {
                cout << frase_in[i].first;
            }
            else cout << " " << frase_in[i].first;
        }
        else cout << frase_in[i].first ; /*" "*/
    }
    cout << endl;
}

int Frase::consultar_numparaules() {
	return num_paraules;
}

bool Frase::trobat(string s) {
    int x = frase_in.size();
    bool trobat = false;
    string actual, ant, op1, op2;
    istringstream iss(s);
    iss >> actual;
    int i,l;
	
    for (i = 0; i < x and not trobat; ++i) {
		op1 = frase_in[i].first;
		l = op1.size();
        if (char(op1[l-1]) == '.' or char(op1[l-1]) == '?' or char(op1[l-1]) == '!') {
            	op1.erase(l-1, l-1);	
        }
        if(actual == op1) trobat =true;
    }
    if (trobat) {
		op1 = frase_in[i].second;
		l = op1.size();
		if (char(op1[l-1]) == '.' or char(op1[l-1]) == '?' or char(op1[l-1]) == '!') {
            	op1.erase(l-1, l-1);	
		}
        ant = op1;
        while (iss >>actual and i<x) {
			
			op1= frase_in[i].first;
			l = op1.size();
			if (char(op1[l-1]) == '.' or char(op1[l-1]) == '?' or char(op1[l-1]) == '!') {
            	op1.erase(l-1, l-1);	
			}
			op2 = frase_in[i].second;
			l = op2.size();
			
			op2 = frase_in[i].second;
			if (char(op2[l-1]) == '.' or char(op2[l-1]) == '?' or char(op2[l-1]) == '!') {
            	
				op2.erase(l-1, l-1);	
			}
			
            if (op1 == actual) {
                if (op2 != ant) return false; 
            }
            else {
                return false;
            }
            
            ant = op1;
            ++i;
        }
        return true;
    }
    return false;
}

void Frase::canvi_paraules(string s1, string s2) {
    for (int i = 0; i < frase_in.size(); ++i) {
        if (frase_in[i].first == s1) {
            (frase_in[i]).first = s2;
        }
    }
}


















