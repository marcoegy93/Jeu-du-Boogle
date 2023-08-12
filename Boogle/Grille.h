#pragma once
#include <iostream>
#include "Liste.h"

struct Grille {
	bool booleen;
	int abscisse;
	int ordonnee;
	char caractere;
};
// Hauteur et largeur du terrain de jeu (il est carr�).
enum { TAILLE = 4 };

typedef Grille Grilles[TAILLE][TAILLE];
/**
 * @brief Remplie un terrain de jeu avec des caract�re saisi au clavier, le terrain de jeu est un carr� de 4 par 4.
 * @param[in,out] g la grille de jeu.
 */
void ecrire_grille(Grilles& g);

/**
 * @brief Recherche si le mot saisi peut se lire dans la grille de jeu et retourne un booleen en fonction de si le mot est trouv� ou non.
 * @see sous_recherche.
 * @param[in] la grille g.
 * @param[in] l'item mot.
 * @return true si le mot peut �tre lut, sinon false
 */
bool recherche(Grilles& g, Item& mot);

/**
 * @brief D�termine si le mot commen�ant � la position pos peut �tre plac� � partir de la coordonn�e coord (abscisse et ordonnee).
 * Si oui, il retournera vrai, sinon faux.
 * @see recherche.
 * @param[in] la grille g.
 * @param[in] l'item mot.
 * @param[in] pos la position du caract�re en question dans le mot.
 * @param[in] abscisse l'abscisse du caract�re.
 * @param[in] ordonnee l'ordonne du caract�re. 
 */
bool sous_recherche(Grilles& g, Item& mot, int pos, int abscisse, int ordonnee);