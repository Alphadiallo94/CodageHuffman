#include "listeCode.h"
#include "operations.h"

/*fonction pour lire la chaine donner pour compresser ou decompresser*/
char * lireChaine()
{
	char* chaine = malloc(255*sizeof(char));
	fgetc(stdin);
	fgets(chaine,255,stdin);
	return chaine;
}


/*fonction pour sortir le minimum(la fréquence la plus petite) d'une liste d'arbre*/
nd minListe (nd n)
{
	nd a=n;
	while(n!=NULL)
	{
		if(a->valeur->val>n->valeur->val)
		{
			a=n;
		}
	n=n->suivant;
	}
	return a;
}
/*fonction qui fusionne deux noeud arbre en creant un troisieme et les deux sont ses fils */
nd fusionerListe (nd a, nd b)
{
	nd n=creerNoeud_liste('/');
	n->valeur->val=a->valeur->val+b->valeur->val;
	n->valeur->gauche=a->valeur;
	n->valeur->droite=b->valeur;
	return n;
}
/*fonction qui affiche l'arbre de gauche a droite*/
void afficherABR(arbre a)
{
	printf("%d , %c\n",a->val,a->lettre);
	if(a->gauche!=NULL)
		afficherABR(a->gauche);
	if(a->droite!=NULL)
		afficherABR(a->droite);

}
/*fonction qui calcule la taille d'une liste d'arbre */
int taille(nd l)
{
	int cpt=0;
	while(l!=NULL)
	{
		cpt++;
		l=l->suivant;
	}
	return cpt;
}
/*fonction qui construit l'arbre des lettre en utilisant une liste d'arbre et libère l'espace de tout les neouds qui existaient dans la liste d'arbre , il reste juste le dernier qu'on renvoi sa valeur qui est un arbre*/
void constuireABR(nd l,arbre *f)
{
	
	while(taille(l)!=1)
	{
		nd a,b,c=NULL;
		a=minListe(l);
		a=supprimerNoeud_liste(&l,a->valeur->lettre);
		b=minListe(l);
		c=fusionerListe(a,b);
		ajouterNoeudfus(l,c);
		b=supprimerNoeud_liste(&l,b->valeur->lettre);	
		free(a);
		free(b);
		a=NULL;
		b=NULL;
	}
	(*f)=malloc(sizeof(arbre));
	(*f)=l->valeur;

}
/*fonction qui l'arbre des lettres et construit a chaque lettre son code*/
void construireListeCode(arbre a,char * code,listeCode *l)
{
	if(a->gauche!=NULL)
	{

		char c[]={'0','\0'};
		char * ptrTemp=realloc(code,strlen(code)*sizeof(char)+sizeof(char)*2);
		code=ptrTemp;
		char *codetemp=malloc(strlen(code)*sizeof(char)+sizeof(char)*2);
		memcpy(codetemp,code,strlen(code)+1);
		strcat(code,c);
		construireListeCode(a->gauche,code,l);
		char d[]={'1','\0'};
		strcat(codetemp,d);
		construireListeCode(a->droite,codetemp,l);
	
	}
	else
	{
		ajouterFinNoeudCode(l,a->lettre,code);
	}
}
/*fonction qui prends un texte et la liste des lettres avec leur code et compresse le texte*/
char * compressionTexte(char * texte,listeCode l)
{
	char * temp;
	char * code=malloc(sizeof(char));
	code[0]='\0';
	unsigned int i;
	for(i=0;i<strlen(texte);i++)
	{
		temp=retournerCodeLettre(l,texte[i]);
		code=realloc(code,strlen(code)+strlen(temp)+sizeof(char)*2);
		strcat(code,temp);
		code[strlen(code)]='\0';
	}		
	return code;
}
/*fonction qui prends un texte en binaire et un arbre de lettre et décompresse le texte*/
char * decompressionTexte(char * texte, arbre a)
{
	if(strlen(texte)==0)
	{
		printf("DECOMPRESSION ECHOUEE\n");
		return NULL;
	}
	char c[2];
	char * decode=malloc(sizeof(char));
	decode[0]='\0';
	arbre temp=malloc(sizeof(arbre));
	temp=a;
	unsigned int i;
	
	for (i=0;i<strlen(texte);i++)
	{		
		if(texte[i]!='0' && texte[i]!='1')
		{
			printf("CODE ERRONE, BINAIRE REQUIS\n");
			return NULL;
		}
 		if(texte[i]=='0')
		{
				temp=temp->gauche;
				if(temp->gauche==NULL)
				{
					c[0]=temp->lettre;
					c[1]='\0';
					decode=realloc(decode,strlen(decode)*sizeof(char)+sizeof(char)*2);
					strcat(decode,c);
					temp=a;
				}

		}
		else
		{
					temp=temp->droite;
					if(temp->gauche==NULL)
					{
						c[0]=temp->lettre;
						c[1]='\0';
						decode=realloc(decode,strlen(decode)*sizeof(char)+sizeof(char)*2);
						strcat(decode,c);
						temp=a;
					}

		}
	}
		free(temp);
		if(temp !=a)
		{
			printf("DECOMPRESSION ECHOUEE CODE TROP COURT\n");
			return NULL;
		}
	return decode;
}
