/**
 * @file ConteneurTDE.cpp
 * @brief Composant de conteneur d'items de capacité extensible
 */

#include <iostream>
#include <cassert>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

#include "ConteneurTDE.h"

void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa > 0) && (p > 0));
	c.capacite = capa;
	c.pasExtension = p;
	c.tab = new Item[capa];
	c.existant = 0;
}

void detruire(ConteneurTDE& c) {
	delete[] c.tab;
	c.tab = NULL;
}

void ecrire(ConteneurTDE& c, unsigned int i, const Item it) {
	if (i >= c.capacite) {
		unsigned int newTaille = (i + 1) * c.pasExtension;
		Item* newT = new Item[newTaille];
		for (unsigned int i = 0; i < c.capacite; ++i)
			strcpy(newT[i], c.tab[i]);
		delete[] c.tab;
		c.tab = newT;
		c.capacite = newTaille;
	}
	strcpy(c.tab[i], it);
}

void saisir(ConteneurTDE& c) {
	Item buffer;
	unsigned int i = 0;
	do {
		cin >> buffer;
		if (strcmp(buffer, "*") == 1) {
			ecrire(c, i, buffer);
			c.existant++;
			++i;
		}
	} while (strcmp(buffer, "*") == 1);
}


void supprimer(ConteneurTDE& c) {
	for (unsigned int i = 0; i < c.existant; ++i) {
		if (strcmp(c.tab[i], c.tab[i + 1]) == 0) {
			for (unsigned int k = i; k < c.existant; k++) {
				strcpy(c.tab[k], c.tab[k + 1]);
			}
			c.existant--;
			i--;
		}
	}
}

void trier(ConteneurTDE& c) {
	Item tmp;
	for (unsigned int i = 0; i < c.existant; i++) {
		for (unsigned int j = 0; j < i; j++) {
			if (strcmp(c.tab[i], c.tab[j]) < 0) {
				strcpy(tmp, c.tab[i]);
				ecrire(c, i, c.tab[j]);
				ecrire(c, j, tmp);
			}
		}
	}
	supprimer(c);
}