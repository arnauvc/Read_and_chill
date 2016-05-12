// Retorna true si el paràmetre implicit compleix l'expressio exp, fals altrament
// "exp" es l'expressió, "i" és la posició de l'element actual (comencem a 0, primer element de exp)
bool Tasca::compleix_expressio(const string &exp, int &i) {
	if (exp[i]!='(') {	//Si l'element no es un parentesi, l'analitzem
		string e;	//Si es una etiqueta, es guardara a "e"
		while (exp[i]!='.' and exp[i]!=',' and exp[i]!=')') { //Si es una etiqueta (no es '.' o ',' o ')') la guardem 
								      // a "e" i avancem posicions (i) fins trobar un caracter 
								      // que no pertanyi a l'etiqueta ('.' o ',' o ')') 
			e.push_back(exp[i]); 	// fem push_back per afegir la nova lletra al final del string "e"
			++i;			//avançem posicio
		}
		return (conte_etiqueta_simple(e)); //Utilitzem la funcio per saber si la tasca conte l'etiqueta "e", 
						   // retorna fals si no.
	} else { // Si es un parentesi '(', es el principi d'una expressio booleana
		++i;  //Avancem una posicio, podrem trobar un altre parentesi (una altre expressio) o una etiqueta
		bool r1 = compleix_expressio(exp,i);  //retorna cert si es una etiqueta i aquesta pertany a la tasca,
						      // fals altrament. Si no es una etiqueta, retorna cert si la següent 
						      // expressió trobada es certa.
		char c = exp[i]; 	// c=element actual, element que va despres de l'etiqueta trobada a la
					// linia anterior. Nomes pot ser "." o ",".
		++i; 			// Avancem una posicio, hem de trobar nova etiqueta o un parentesi (nova expressio)
		bool r2 = compleix_expressio(exp,i); //retorna cert si es una etiqueta i aquesta pertany a la tasca, 
						     // fals altrament. Si no es una etiqueta retorna cert si la següent
						     // expressió trobada es certa.
		++i;			//Avancem una posicio, per que "i" retorni el valor adequat (sempre 
					// una posicio despres de l'element analitzat en aquesta iteracio).
		if (c=='.') {		// Haviem guardat "." o "," a "c". 
			return (r1 and r2);	//Si es "." es un and, retorna true si es compleix
		} else {
			return (r1 or r2);	//Si es "," es un or, retorna true si es compleix
		}
	}
}
