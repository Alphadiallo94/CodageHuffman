#ifndef LISTEABR_H_INCLUDED
#define LISTEABR_H_INCLUDED

#include "modelABR.h"

struct noeud 
{
	arbre valeur;
	struct noeud* suivant;

}noeud;

typedef struct noeud * nd;

nd creerNoeud_liste(char let);

void construireListe(char * chaine,nd *l);

nd rechercherNoeud_liste(nd n,char let);

void ajouterNoeud_liste(nd *n,char let);

nd supprimerNoeud_liste(nd *n,char let);

void ajouterNoeudfus(nd n,nd d);

#endif
