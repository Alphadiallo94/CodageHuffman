
#include "operations.h"

int afficherMenu(){
	int choix;
	do{
	printf("\n********************CODAGE DE HUFFMAN********************\n");
	printf("\nQUELLE OPERATION VOULEZ VOUS EFFECTUER ?\n");
	printf("1_ENCODAGE D UNE CHAINE DE CARACTERE\n");
	printf("2_DECODAGE D UNE CHAINE DE CARACTERE\n");
	printf("3_ENCODAGE D UN FICHIER DE CARACTERE\n");
	printf("4_DECODAGE D UN FICHIER DE CARACTER\n");
	printf("5_QUIT\n\n");
	scanf("%d",&choix);
	}while(choix<1||choix>5);
	return choix;
}

int main()
{	
	int choix;//choix c'est pour choisir est que l'utilisateur veut faire.
	int t;//c'est une variable pour vérifier le fichier en entrer que son chemin est correct ou non.
	char  *chaine=malloc(255);//c'est la chaine de carectère.
	nd l=NULL;//la liste d'arbre construite d'une chaine de caractère.
	arbre f=NULL;//l'arbre construit par la liste d'arbre.
	char *txtComp;//c'est le texte apres avoir utilise la compression.
	char *txtDecomp;//c'est le texte apres avoir utilise la decompression.
	char *chaineDecomp=malloc(256);//c'est la chaine qu'on reçois d'un fichier de lettre.
	char *chaineComp=malloc(256);//c'est la chaine qu'on reçois d'un fichier binaire.
	chaineComp[0]='\0';//pour concaténer le contenu de fichier dans la chaine avec la fonction strcat.
	chaineDecomp[0]='\0';//pour concaténer le contenu de fichier dans la chaine avec la fonction strcat.
	char car[255];//c'est le tableau utilisé dans la fonction fgets pour récuperer le contenu du fichier.
	FILE * fp;//c'est le fichier utilisé pour lire ou ecrire dans des fichiers.
	listeCode codel=NULL;//c'est la liste des lettres avec leurs codes en binaire.
	char *c;//c'est le code de chaque lettre qu'on construit dans la fonction constuireListeCode.
	do{
		choix=afficherMenu(); 	
		switch(choix){
			case 1:	
				if(codel)
					detruireListeCode(codel);
				if(l)
					free(l);
				
				if(chaine)
					free(chaine);
				codel=NULL;
				l=NULL;
				f=NULL;
				printf("Donnez votre chaine de caractère à compresser :\n");
				chaine=lireChaine();
				printf("%s\n",chaine);
				chaine[strlen(chaine)-1]='\0';
				construireListe(chaine,&l);
				constuireABR(l,&f);
				afficherABR(f);
				c=malloc(sizeof(char));
	 			c[0]='\0';
				construireListeCode(f,c,&codel);
				afficherListeCode(codel);
				printf("Voici <%s> compressé : %s\n",chaine,compressionTexte(chaine,codel));
				break;
			case 2:
				if(codel==NULL)
				{
					printf("Liste code est vide, décompression impossible \n");
					break;
				}
				else
				{
					printf("Donnez votre texte à décompresser :\n");
					chaine=lireChaine();
					afficherListeCode(codel);
					chaine[strlen(chaine)-1]='\0';
					txtDecomp=decompressionTexte(chaine,f);
					if(txtDecomp)
						printf("Voici <%s> décompresse : %s\n",chaine,txtDecomp);
					else
						printf("DECOMPRESSION ECHOUEE\n");
				}
				break;
			
			case 3:
				if(codel)
					detruireListeCode(codel);		
				if(l)
					free(l);
				if(chaineDecomp)
					free(chaineDecomp);
				chaineDecomp=malloc(sizeof(char)*255);
				chaineDecomp[0]='\0';
				do
				{
					t=1;
					printf("Donnez le chemin du fichier à compresser:\n");
					scanf("%s",chaine);
					fp=fopen(chaine,"r");
					if (fp==NULL)
					{
						printf("Le fichier n'existe pas , veuillez réessayer.\n");
						t=0;
					}
				}while(t==0);
				
				while(fgets(car,255,fp))
				{
					car[strlen(car)]='\0';
					chaineDecomp=realloc(chaineDecomp,strlen(chaineDecomp)*sizeof(char)+strlen(car)*sizeof(char)+sizeof(char));
					strcat(chaineDecomp,car);
							
				}
				printf("Chaine à compresser : %s\n",chaineDecomp);
				codel=NULL;
				l=NULL;	
				construireListe(chaineDecomp,&l);
				constuireABR(l,&f);
				afficherABR(f);
				c=malloc(sizeof(char));
	 			c[0]='\0';
				construireListeCode(f,c,&codel);
				afficherListeCode(codel);
				txtComp=compressionTexte(chaineDecomp,codel);
				printf("Voici votre texte compressé : %s\n",txtComp);
				if(txtComp!=NULL)
				{
					printf("Voulez vous transférer le résultat dans un fichier ?\n");
					printf("1_OUI    2_NON\n");
					do
					{
						scanf("%d",&choix);

					}while(choix<1||choix>2);	
					if(choix==1)
					{
						printf("Donnez le nom du fichier que vous voulez créer :\n");
						scanf("%s",chaine);
						fp=fopen(chaine,"w");
						fwrite(txtComp,1,strlen(txtComp),fp);
						fclose(fp);						
					}
				}
				break;
			case 4:
				if(codel==NULL)
				{
					printf("Liste code est vide, décompression impossible \n");
					break;
				}
				else
				{
					chaineComp=malloc(sizeof(char)*255);
					chaineComp[0]='\0';
					do
					{
						t=1;
						printf("Donnez le le chemin du fichier à décompresser :\n");
						scanf("%s",chaine);
						fp=fopen(chaine,"r");
						if (fp==NULL)
						{
							printf("Le fichier n'existe pas , veuillez réessayer.\n");
							t=0;
						}
					}while(t==0);
				
					while(fgets(car,255,fp))
					{
					
							car[strlen(car)]='\0';
							chaineComp=realloc(chaineComp,strlen(chaineComp)*sizeof(char)+strlen(car)*sizeof(char)+sizeof(char));
							strcat(chaineComp,car);
							
					}
					printf("Chaine à décompresser : %s\n",chaineComp);
					txtDecomp=decompressionTexte(chaineComp,f);
					printf("Chaine décompressé : %s\n",txtDecomp);
					if(txtDecomp!=NULL)
					{
						printf("Voulez vous transférer le résultat dans un fichier ?\n");
						printf("1_OUI    2_NON\n");
						do
						{
							scanf("%d",&choix);

						}while(choix<1||choix>2);
						if(choix==1)
						{
							printf("Donnez le nom du fichier que vous voulez créer :\n");
							scanf("%s",chaine);
							fp=fopen(chaine,"w");
							fwrite(txtDecomp,1,strlen(txtDecomp),fp);
							fclose(fp);						
						}
					}
				}
				break;
			default :
				printf("Aurevoir\n");
		}
	}while(choix!=5);
	free(chaine); 
	free(chaineComp); 
	free(chaineDecomp);
	free(c);
}
