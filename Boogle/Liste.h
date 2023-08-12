#pragma once

/**
 * @file Liste.h
 * @brief Composant de liste en m�moire dynamique et extensible.
 */

#include "ConteneurTDE.h"

struct Liste {
	/// Conteneur m�morisant les �l�ments de la liste.
	ConteneurTDE* tab;
	/// Nombre d'�l�ments stock�s dans la liste.
	unsigned int nb;
	unsigned int existant;
	/// Capacit� de la liste (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
};

/**
 * @brief Initialiser une liste vide, la liste est allou�e en m�moire dynamique.
 * @see detruire, la liste est � d�sallouer en fin d�utilisation.
 * @param[out] l La liste � initialiser.
 * @param[in] capa Capacit� de la liste.
 * @param[in] pas Pas d�extension de la liste.
 * @pre capa > 0 et pas > 0.
 */
void initialiser_liste(Liste& l, unsigned int capa, unsigned int pas);

/**
 * @brief D�sallouer une liste.
 * @see initialiser
 * @param[out] l La liste.
 */
void detruire_liste(Liste& l);

/**
 * @brief Ecrire un item dans la liste.
 * @param[in,out] l La liste.
 * @param[in] pos Position de l'�l�ment � �crire.
 * @param[in] c le conteneur d'items.
 * @pre 0 <= pos < longueur(l).
*/
void ecrire_liste(Liste& l, unsigned int pos, const ConteneurTDE& c);

/**
 * @brief Compare les conteneurs d'items dans une liste et retourne un conteneur final qui affiche tous les mots apparaissant dans au moins deux de ces conteneurs de la liste initiale.
 * @param[in,out] l La liste.
 * @return le conteneur dynamique final.
*/
ConteneurTDE comparer_liste(Liste& l);