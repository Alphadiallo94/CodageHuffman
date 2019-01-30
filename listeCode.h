#ifndef LISTECODE_H_INCLUDED
#define LISTECODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct noeudCode
{
	char lettre;
 	char * code;
	struct noeudCode * next;

}noeudCode;

typedef struct noeudCode * listeCode;

listeCode creerListeCode(char l, char * code);

void ajouterFinNoeudCode(listeCode *l, char lettre, char *code);

char * retournerCodeLettre(listeCode l,char lettre);

void afficherListeCode(listeCode l);

void detruireListeCode(listeCode l);

#endif
