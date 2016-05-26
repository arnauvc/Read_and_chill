#include "Frase.hh"

Frase::Frase() {
    //num_paraules = 0;
}

Frase::~Frase() {}

void Frase::llegir_frase(vector<pair<string, string> > frase_ini) {
	frase_in = frase_ini;
    /*string ant;
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
    ant = op;;
    frase_in.push_back(make_pair(c, ant)); 
    ++num_paraules;
    ///////////
    for(int i = 0; i < frase_in.size(); ++i){
        cout << "PRIMER:" << frase_in[i].first << endl;
        cout << "segon:" << frase_in[i].second << endl;
    }
    cout << endl;
    */
}

void Frase::escriu_frase() const {
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
        else cout << frase_in[i].first ; /*" els . / ? / !"*/
    }
    cout << endl;
}

/*int Frase::consultar_numparaules() {
    return num_paraules;
}*/

bool Frase::trobat(string s) const {
    int x = frase_in.size();
    bool trobat = false;
    bool trpri = false;
    bool avan = false;
    bool tnpi = true;
    string actual, actual1, ant, op1, op2;
    int sum = 0;
    istringstream uss(s);
    while (uss >> actual) ++sum;
    int count = 0;
    istringstream ess(s);
    ess >> actual;
    int i,j;
    j = 0;
    for (i = 0; i < x and not trobat; ++i) { 
        count = 0;
        op1 = frase_in[i].first;
        if(actual == op1){
            //cout << "ha entrat" << endl;
            trpri = true;
        }
        
        if (trpri) {
            ++count;
            if(actual.size() == s.size()) return true;
            
            //trobat = true;
            istringstream iss(s);
            iss >> actual;
            
            j = i;
            ++j;
            //cout << "j:" << j << endl;
            ant = op1;
            
            tnpi = true;
            //cout << ant << endl;
            //cout << actual << endl;
            iss >> actual; /////////////////////////////////////////////////////
            
            while (j<x and tnpi and not trobat) {
                avan = false;
                /*
                cout <<"ant:" << ant << endl;
                cout <<"actual: " << actual << endl;
                cout << "vector: " << frase_in[j].first << endl;
                */
                if(frase_in[j].first == "," or frase_in[j].first == ":" or frase_in[j].first == ";"){
                    if(frase_in[j].second == ant){
                       
                        ant = frase_in[j].first;
                    }
                }
                else{                    
                    if(frase_in[j].first == actual){
                        if(frase_in[j].second == ant){
                            ant = frase_in[j].first;
                            ++count;
                            if (count == sum) trobat = true;
                            
                        }
                        else trobat=false;
                    }
                    else trobat =false;

                    avan = true;
                }
                
                if(avan){
                    iss >> actual;
                    if(actual1 == actual) tnpi = false;
                }                
                ++j;
     
            actual1 = actual;
            }
            istringstream oss(s);
            oss >> actual;
        }
        
        trpri = false;
        
        
        
        
    }
    return trobat;
}

bool Frase::canvi_paraules(string s1, string s2) {
    bool a = false;
    string s ;
    bool primer = false;
    bool trobat = false;
    for (int i = 0; i < frase_in.size(); ++i) {
        if (frase_in[i].first == s1) {
            frase_in[i].first = s2;
            
            trobat = true;
            a = true;
            primer = true;
        }
        if(trobat and not primer){
                
                frase_in[i].second = s2;
                trobat = false;
        }
        if(trobat and primer){
            s = s2;
            primer = false;
        }
    }
    return a;
}
