/**
 * @file Liste.cpp
 * @brief Composant de liste en mémoire dynamique et extensible
 */
#include <iostream>
#include <cstring>
#include <cassert>
#include "Liste.h"
#pragma warning(disable:4996)
using namespace std;

void initialiser_liste(Liste& l, unsigned int capa, unsigned int p) {
	assert((capa > 0) && (p > 0));
	l.capacite = capa;
	l.pasExtension = p;
	l.tab = new ConteneurTDE[capa];
	l.existant = 0;
}

void detruire_liste(Liste& l) {
	delete[] l.tab;
	l.tab = NULL;
}

void ecrire_liste(Liste& l, unsigned int i, const ConteneurTDE& c) {
	assert(i < l.nb);

	if (l.existant >= l.capacite) {
		unsigned int newTaille = (l.existant + 1) * l.pasExtension;
		ConteneurTDE* newT = new ConteneurTDE[newTaille];
		for (unsigned int i = 0; i < l.existant; ++i) {
			initialiser(newT[i], 45, 2);
			for (unsigned int j = 0; j < l.tab[i].existant; ++j) {
				ecrire(newT[i], j, l.tab[i].tab[j]);
			}
		}
		delete[] l.tab;
		l.tab = newT;
		l.capacite = newTaille;
	}
	initialiser(l.tab[l.existant], 45, 2);
	for (unsigned int n = 0; n < c.existant; n++) {
		ecrire(l.tab[l.existant], n, c.tab[n]);
		l.tab[l.existant].existant++;
	}
	l.existant++;
}

ConteneurTDE comparer_liste(Liste& l) {
	ConteneurTDE final;
	initialiser(final, 45, 2);
	unsigned int cpt = 0;
	for (unsigned int i = 0; i < l.existant; i++) {
		for (unsigned int j = 0; j < l.tab[i].existant; j++) {
			cpt = 0;
			for (unsigned int w = 0; w < l.existant; w++) {
				for (unsigned int v = 0; v < l.tab[w].existant; v++) {
					if (strcmp(l.tab[i].tab[j], l.tab[w].tab[v]) == 0) {
						cpt++;
						if (cpt == 2) {
							ecrire(final, final.existant, l.tab[i].tab[j]);
							final.existant++;
						}
					}
				}
			}
		}
	}
	trier(final);
	return final;
}