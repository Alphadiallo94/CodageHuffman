#ifndef MODELEABR_H_INCLUDED
#define MODELEABR_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    	int val;
	char lettre;
    	struct Node* gauche;
    	struct Node* droite;
};

typedef struct Node* arbre;

arbre CreerNoeud ( int val,char lettre);

int RechercherABR (arbre R, int val);

arbre InsererABR_rec (arbre R, int val ,char lettre);

void detruireABR (arbre R);

#endif
