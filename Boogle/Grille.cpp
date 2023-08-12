#include <iostream>
#include <cstring>
#include "Grille.h"
#pragma warning(disable:4996)

using namespace std;

void ecrire_grille(Grilles& g) {
	char c;
	for (unsigned int abscisse = 0; abscisse < TAILLE; abscisse++) {
		for (unsigned int ordonnee = 0; ordonnee < TAILLE; ordonnee++) {
			cin >> c;
			g[abscisse][ordonnee].caractere = c;
			g[abscisse][ordonnee].abscisse = abscisse;
			g[abscisse][ordonnee].ordonnee = ordonnee;
		}
	}
}

bool recherche(Grilles& g, Item& mot) {
	bool booleen = false;
	for (unsigned int abscisse = 0; abscisse < TAILLE; abscisse++) {
		for (unsigned int ordonnee = 0; ordonnee < TAILLE; ordonnee++) {
			g[abscisse][ordonnee].booleen = booleen;
		}
	}
	for (unsigned int abscisse = 0; abscisse < TAILLE; abscisse++) {
		for (unsigned int ordonnee = 0; ordonnee < TAILLE; ordonnee++) {
			if (sous_recherche(g, mot, 0, g[abscisse][ordonnee].abscisse, g[abscisse][ordonnee].ordonnee) == true) {
				return true;
			}
		}
	}
	return false;
}

bool sous_recherche(Grilles& g, Item& mot, int pos, int abscisse, int ordonnee) {
	if (pos >= strlen(mot)) {
		return true;
	}
	if (abscisse >= TAILLE || ordonnee >= TAILLE || abscisse < 0 || ordonnee < 0) {
		return false;
	}
	if (g[abscisse][ordonnee].caractere != mot[pos]) {
		return false;
	}
	if (g[abscisse][ordonnee].booleen == true) {
		return false;
	}
	g[abscisse][ordonnee].booleen = true;
	for (unsigned int i = 0; i < 8; ++i) {
		int abs, ord;
		switch (i) {
		case 0: {
			abs = abscisse - 1;
			ord = ordonnee;
			if (sous_recherche(g, mot, pos + 1, abs, ord) == true) {
				return true;	
			}
			break;
		}
		case 1: {
			abs = abscisse - 1;
			ord = ordonnee +1;
			if (sous_recherche(g, mot, pos + 1, abs, ord) == true) {
				return true;
			}
			break;
		}
		case 2: {
			abs = abscisse;
			ord = ordonnee + 1;
			if (sous_recherche(g, mot, pos + 1, abs, ord) == true) {
				return true;
			}
			break;
		}
		case 3: {
			abs = abscisse + 1;
			ord = ordonnee + 1;
			if (sous_recherche(g, mot, pos + 1, abs, ord) == true) {
				return true;
			}
			break;
		}
		case 4: {
			abs = abscisse + 1;
			ord = ordonnee;
			if (sous_recherche(g, mot, pos + 1, abs, ord) == true) {
				return true;
			}
			break;
		}
		case 5: {
			abs = abscisse + 1;
			ord = ordonnee - 1;
			if (sous_recherche(g, mot, pos + 1, abs, ord) == true) {
				return true;
			}
			break;
		}
		case 6: {
			abs = abscisse;
			ord = ordonnee - 1;
			if (sous_recherche(g, mot, pos + 1, abs, ord) == true) {
				return true;
			}
			break;
		}
		case 7: {
			abs = abscisse - 1;
			ord = ordonnee - 1;
			if (sous_recherche(g, mot, pos + 1, abs, ord) == true) {
				return true;
			}
			break;
		}
		}
		if (sous_recherche(g, mot, pos + 1, abscisse, ordonnee) == true) {
			return true;
		}
	}
	g[abscisse][ordonnee].booleen = false;
	return false;
}