#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "listeABR.h"
#include "listeCode.h"

char * lireChaine();

nd minListe(nd n);

nd fusionerListe (nd a, nd b);

void afficherABR(arbre a);

int taille(nd l);

void constuireABR(nd l,arbre *f);

void construireListeCode(arbre a,char * code,listeCode *l);

char * compressionTexte(char * texte,listeCode l);

char * decompressionTexte(char * texte, arbre a);

#endif
