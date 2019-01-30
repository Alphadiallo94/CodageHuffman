#include "listeCode.h"

/*fonction qui cree un nouveau noeud d'une liste des codes*/
listeCode creerListeCode(char lettre, char * code)
{
    listeCode l=malloc(sizeof(listeCode));
    l->lettre=lettre;
    l->code=malloc(strlen(code)*sizeof(char));
    strcpy(l->code,code);
    l->next=NULL;
    return l;
}
/*fonction qui prends une liste de code une lettre et son code et l'ajoute a la liste*/
void ajouterFinNoeudCode(listeCode *l, char lettre, char *code)
{
    	if ((*l)==NULL)
      		(*l)=creerListeCode(lettre,code);
    	else
	{
		listeCode temp=malloc(sizeof(listeCode));
		temp=(*l);
		while(temp->next!=NULL)
		  temp=temp->next;
		temp->next=creerListeCode(lettre,code);
    	}
}
/*fonction qui prends une listre et une lettre et qui renvoi son code*/
char * retournerCodeLettre(listeCode l,char lettre)
{
    	if(l->lettre==lettre)
     		 return l->code;
    	else
	{
	      listeCode temp=malloc(sizeof(listeCode));
	      temp=l;
	      while(temp->lettre!=lettre)
		temp=temp->next;
	      return temp->code;
	}
}

void afficherListeCode(listeCode l){
	listeCode temp=malloc(sizeof(listeCode));
	temp=l;
	while(temp!=NULL)
	{
		printf("Code de %c : %s \t \n",temp->lettre,temp->code);
		temp=temp->next;
	}
	free(temp);
}	

void detruireListeCode(listeCode l)
{
	if(l!=NULL)
	{
		if(l->next!=NULL)
		{
			detruireListeCode(l->next);
		}
	free(l->code);		
	free(l);
	}
}

