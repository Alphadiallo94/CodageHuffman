#include"modelABR.h"


/*fonction qui cree un nouveau noeud d'arbre*/
arbre CreerNoeud_arbre(int val, char lettre)
{
	arbre R=((arbre)malloc(sizeof(arbre)));
	R->val=val;
	R->lettre=lettre;
	R->gauche=NULL;
    	R->droite=NULL;
    return R;
}


/*fonction qui prend un arbre et une valeur et une lettre et l'ajoute a l'arbre*/
arbre InsererABR_rec (arbre R, int val, char lettre)
{
    if(R==NULL)
       	 return CreerNoeud_arbre(val,lettre);
    else
        {
        if(val < R->val)
             R->gauche=InsererABR_rec(R->gauche,val,lettre);
        else
             R->droite=InsererABR_rec(R->droite,val,lettre);
        }
	return R;
}
/*fonction qui prends un arbre et une valeur et renvoi 1 si la valeur existe 0 sinon*/
int RechercherABR (arbre R, int val)
{
	if(R!=NULL)
	{
		if(R->val==val)
			return 1;
		else
		{
			if(val<R->val)
				return RechercherABR(R->gauche,val);
			else 
				return RechercherABR(R->droite,val);
		}
		
	}
	else 
	return 0;
}
/*fonction qui prends un arbre et le detruis en liberant la mémoire aussi*/
void detruireABR(arbre R)
{
    if(R!=NULL)
    {
        if((R->droite)!=NULL || (R->gauche)!=NULL)
        {
            detruireABR(R->droite);
            detruireABR(R->gauche);
        }
	free(R->droite);
	free(R->gauche);
        free(R);
    }
}

