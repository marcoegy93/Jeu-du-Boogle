#include <iostream>
#include <cstring>
#include "Grille.h"
#pragma warning(disable:4996)
using namespace std;

void exo1();
void exo2();
void exo3();
void exo4();
void exo5();
void exo6();

int main() {
	int num;
	cin >> num;
	switch (num) {
	case 1:
		exo1(); break;
	case 2:
		exo2(); break;
	case 3:
		exo3(); break;
	case 4:
		exo4(); break;
	case 5:
		exo5(); break;
	case 6:
		exo6(); break;
	}
}

void exo1() {
	unsigned int longueur_mot = 0;
	unsigned int point, score = 0;
	char mot[30];
	do {

		/*----Pour chaque longueur de mot est attribué un certain nombre de points lesquels sont additionnés entres eux----*/
		cin >> mot;
		longueur_mot = strlen(mot);
		if (longueur_mot <= 2) {
			point = 0;
		}
		if (longueur_mot == 3 || longueur_mot == 4) {
			point = 1;
		}
		if (longueur_mot == 5) {
			point = 2;
		}
		if (longueur_mot == 6) {
			point = 3;
		}
		if (longueur_mot == 7) {
			point = 5;
		}
		if (longueur_mot >= 8) {
			point = 11;
		}
		score += point;
		if (strcmp(mot, "*") == 0) {
			cout << score;
		}
	} while (strcmp(mot, "*") != 0);
}

void exo2() {
	ConteneurTDE c;

	/*----Allocation en mémoire dynamique du conteneur d'items----*/
	initialiser(c, 45, 2);

	/*----Saisir----*/
	saisir(c);

	/*----Trier----*/
	trier(c);

	/*----Affichage----*/
	for (unsigned int i = 0; i < c.existant; i++) {
		cout << c.tab[i] << endl;
	}
	cout << "*" << endl;

	/*----Désallocation d'un conteneur d'items en mémoire dynamique.----*/
	detruire(c);
}

void exo3() {
	int i = 0, k = 0;
	ConteneurTDE c1;
	ConteneurTDE c2;

	/*----Allocation en mémoire dynamique des conteneurs d'items----*/
	initialiser(c1, 45, 2);
	initialiser(c2, 45, 2);

	/*----Saisir----*/
	saisir(c1);
	saisir(c2);

	/*----Trier----*/
	trier(c1);
	trier(c2);

	/*----Affichage----*/
	for (unsigned int i = 0; i < c2.existant; ++i) {
		for (unsigned int k = 0; k < c1.existant; k++) {
			if (strcmp(c2.tab[i], c1.tab[k]) == 0) {
				for (unsigned int j = i; j < c2.existant; j++) {
					strcpy(c2.tab[j], c2.tab[j + 1]);
				}
				c2.existant--;
				k = 0;
			}
		}
	}
	for (i = 0; i < c2.existant; i++) {
		cout << c2.tab[i] << endl;
	}
	cout << "*" << endl;
	/*----Désallocation des conteneurs d'items en mémoire dynamique.----*/
	detruire(c1);
	detruire(c2);
}

void exo4() {
	int i = 0, k = 0;
	ConteneurTDE c1;
	ConteneurTDE c2;

	/*----Allocation en mémoire dynamique des conteneurs d'items----*/
	initialiser(c1, 45, 2);
	initialiser(c2, 45, 2);

	/*----Saisir----*/
	saisir(c1);
	saisir(c2);

	/*----Trier----*/
	/*trier(c1);*/
	trier(c2);

	/*----Affichage----*/
	for (unsigned int i = 0; i < c2.existant; ++i) {
		for (unsigned int k = 0; k < c1.existant; k++) {
			if (strcmp(c2.tab[i], c1.tab[k]) == 0) {
				cout << c2.tab[i] << endl;
			}
		}
	}
	cout << "*" << endl;

	/*----Désallocation d'un conteneur d'items en mémoire dynamique.----*/
	detruire(c1);
	detruire(c2);
}

void exo5() {
	Liste liste;

	/*----Allocation de mémoire dynamique d'une liste----*/
	initialiser_liste(liste, 10, 2);
	Item buffer;
	unsigned int k = 0;
	cin >> buffer;
	do {
		unsigned int i = 0;
		ConteneurTDE c;

		/*----Allocation en mémoire dynamique d'un conteneur d'item temporaire----*/
		initialiser(c, 45, 2);
		do {
			if (strcmp(buffer, "*") == 0) {
				break;
			}

			/*----Ecriture du buffer dans le conteneur temporaire----*/
			ecrire(c, i, buffer);
			c.existant++;
			++i;
			cin >> buffer;

		} while (strcmp(buffer, "*") != 0);

		/*----Trie du conteneur temporaire----*/
		trier(c);

		/*----Ecriture des conteneurs temporaires dans la liste----*/
		ecrire_liste(liste, k, c);

		/*----Désallocation d'un conteneur d'items temporaire en mémoire dynamique.----*/
		detruire(c);

		cin >> buffer;

	} while (strcmp(buffer, "*") != 0);

	/*----Renvoie un conteneur dynamique final trié----*/
	ConteneurTDE final = comparer_liste(liste);

	/*----Affichage du conteneur final----*/
	for (unsigned int i = 0; i < final.existant; i++) {
		cout << final.tab[i] << endl;
	}
	cout << "*" << endl;

	/*----Désallocation d'un conteneur d'items final en mémoire dynamique.----*/
	detruire(final);

	/*----Désallocation d'une liste conteneur d'items en mémoire dynamique.----*/
	detruire_liste(liste);
}

void exo6() {
	Grille g[TAILLE][TAILLE];
	Item buffer;
	ConteneurTDE final;

	/*----Allocation de mémoire dynamique du Conteneur final----*/
	initialiser(final, 45, 2);
	unsigned int i = 0;

	/*----Création de la grille de jeu----*/
	ecrire_grille(g);
	do {
		bool p = false;
		cin >> buffer;

		if (strcmp(buffer, "") != 0) {

			/*----Recherche du mot dans la grille de jeu----*/
			p = recherche(g, buffer);
			if (p == true) {

				/*----Ecriture du buffer dans le conteneur final----*/
				ecrire(final, i, buffer);
				final.existant++;
				++i;
			}
		}
	} while (strcmp(buffer, "*") != 0);

	/*----Trie du conteneur final----*/
	trier(final);

	/*----Affichage du conteneur final----*/
	for (unsigned int i = 0; i < final.existant; i++) {
		cout << final.tab[i] << endl;
	}
	cout << "*" << endl;

	/*----Désallocation d'un conteneur d'items final en mémoire dynamique.----*/
	detruire(final);
}