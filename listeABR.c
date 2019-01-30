#include "listeABR.h"

/*fonction qui creer un noeud d'une liste d'arbre avec la lettre let et la fréquence 1*/
nd creerNoeud_liste(char let)
{
	nd n=(nd)malloc(sizeof(nd));
	arbre R=CreerNoeud_arbre(1,let);
	n->valeur=R;
	n->suivant = NULL;
	return n;
}
void construireListe(char * chaine,nd *l)
{	
	unsigned int i;
	char * chaine1=chaine;
	for(i=0;i<strlen(chaine1);i++)
	{
		ajouterNoeud_liste(l,chaine1[i]);

	}
}

/*fonction qui prends une listre d'arbre et une lettre et renvoi un pointeur sur le noeud qui contient cette lettre , NULL sinon*/
nd rechercherNoeud_liste(nd n,char let)
{
	if(n->valeur->lettre==let)	
	{
		return n;
	}else
	{	
		nd temp=n;
		if(temp->suivant==NULL)
		{
			return NULL;
		}
		else
		{
			return rechercherNoeud_liste(temp->suivant,let);
		}
	}

}
/*fonction qui prends une liste d'arbre et une lettre , elle ajoute la lettre si elle n'existe pas dans la liste sinon elle ajoute un a sa fréquence*/
void ajouterNoeud_liste(nd *n,char let)
{
		
		if((*n)==NULL)
		{
			(*n)=creerNoeud_liste(let);	
		}
		else 
		{
			nd a=rechercherNoeud_liste((*n),let);
			if(a!=NULL)
			{
			a->valeur->val++;
			}
			else
			{
			nd temp=(*n);
			while(temp->suivant!=NULL)
				temp=temp->suivant;
			temp->suivant=creerNoeud_liste(let);
			}
		}
	
}
/*fonction qui prends une liste d'arbre et ajoute les nouveux noeuds creer par la fonction fusionerListe*/
void ajouterNoeudfus(nd n,nd d)
{
	while(n->suivant!=NULL)
		n=n->suivant;
	n->suivant=d;
}
/*fonction qui prends une liste d'arbre et une lettre et renvoi un pointeur sur le noeud si elle existe dans la liste , NULL sinon*/
nd supprimerNoeud_liste(nd *n,char let)
{
	if((*n)!=NULL)
	{

		nd p=(*n),q=p->suivant;
		if(p->valeur->lettre==let)
		{
			(*n)=q;
			return p;
		}
		else
		{
			while(q!=NULL)
			{
				if(q->valeur->lettre==let)
				{
					p->suivant=q->suivant;
					return q;						
				}
				else
				{
					p=q;
					q=q->suivant;
				}
			}
		}
	}
	return NULL;
}

