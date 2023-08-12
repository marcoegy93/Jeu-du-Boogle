#pragma once

/**
 * @file ConteneurTDE.h
 * @brief Composant d'un conteneur d'items de capacit� extensible.
 */

#include "Item.h"

 /** @brief Conteneur d'items allou�s en m�moire dynamique
  *  de capacit� extensible suivant un pas d'extension.
  */
struct ConteneurTDE {
	unsigned int existant;
	/// Capacit� du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur allou� en m�moire dynamique.
	Item* tab;
};

/**
 * @brief Initialise un conteneur d'items.
 * Allocation en m�moire dynamique du conteneur d'items
 * de capacit� (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa d�sallocation en fin d'utilisation.
 * @param[out] c Le conteneur d'items.
 * @param [in] capa Capacit� du conteneur.
 * @param [in] p Pas d'extension de capacit�.
 * @pre capa > 0 et p > 0.
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique.
 * @see initialiser.
 * @param[in,out] c Le conteneur d'items.
 */
void detruire(ConteneurTDE& c);

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @see saisir.
 * @param[in,out] c Le conteneur d'items.
 * @param[in] i La position o� ajouter/modifier l'item.
 * @param[in] it L'item � �crire.
 */
void ecrire(ConteneurTDE& c, unsigned int i, const Item it);

/**
* @brief Permet une saisie au clavier de mots qui seront �crit dans un conteneur d'items.
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
* @brief Trie un conteneur d'items sous forme canonique � l'aide d'un tri � bulle, c'est � dire que les mots sont tri�s par ordre croissant et qu'il n'apparaisse qu'une seule fois.
* @see supprimer.
* @param[in,out] c le conteneur d'items.
*/
void trier(ConteneurTDE& c);