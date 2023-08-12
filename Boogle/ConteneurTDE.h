#pragma once

/**
 * @file ConteneurTDE.h
 * @brief Composant d'un conteneur d'items de capacité extensible.
 */

#include "Item.h"

 /** @brief Conteneur d'items alloués en mémoire dynamique
  *  de capacité extensible suivant un pas d'extension.
  */
struct ConteneurTDE {
	unsigned int existant;
	/// Capacité du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur alloué en mémoire dynamique.
	Item* tab;
};

/**
 * @brief Initialise un conteneur d'items.
 * Allocation en mémoire dynamique du conteneur d'items
 * de capacité (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa désallocation en fin d'utilisation.
 * @param[out] c Le conteneur d'items.
 * @param [in] capa Capacité du conteneur.
 * @param [in] p Pas d'extension de capacité.
 * @pre capa > 0 et p > 0.
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique.
 * @see initialiser.
 * @param[in,out] c Le conteneur d'items.
 */
void detruire(ConteneurTDE& c);

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @see saisir.
 * @param[in,out] c Le conteneur d'items.
 * @param[in] i La position où ajouter/modifier l'item.
 * @param[in] it L'item à écrire.
 */
void ecrire(ConteneurTDE& c, unsigned int i, const Item it);

/**
* @brief Permet une saisie au clavier de mots qui seront écrit dans un conteneur d'items.
* @see ecrire.
* @param[in,out] c le conteneur d'items.
*/
void saisir(ConteneurTDE& c);

/**
* @brief Supprime les doublons de mots dans un conteneur d'items.
* @see trier.
* @param[in,out] c le conteneur d'items.
*/
void supprimer(ConteneurTDE& c);

/**
* @brief Trie un conteneur d'items sous forme canonique à l'aide d'un tri à bulle, c'est à dire que les mots sont triés par ordre croissant et qu'il n'apparaisse qu'une seule fois.
* @see supprimer.
* @param[in,out] c le conteneur d'items.
*/
void trier(ConteneurTDE& c);