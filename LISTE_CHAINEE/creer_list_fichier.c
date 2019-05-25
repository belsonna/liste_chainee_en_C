#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define tail 50
//definition du type etudiant
typedef struct etudiant
{
   char nom[20],matricule[8];
   int age;

}ET;


//definition du type cellule
typedef struct cellule
{
    ET donnee;
    struct cellule *suivant;
}tcellule;

typedef tcellule* Liste;

void afficher_liste(Liste L);
void affichlistgd(Liste laffich);
void creerfichier();

Liste creer_liste(Liste L);
FILE *f;

main()
 {

    Liste maliste=NULL;
    int i,n;
    creerfichier();
    maliste=creer_liste(maliste);
    afficher_liste(maliste);
    //affichlistgd(maliste);

 }

Liste creer_liste(Liste L)
{
    Liste dernier=NULL ,courant;
    int i=0;
    ET e;
    char *ch,chaine[256],nomfichier[20];
    printf ("Entrez le nom du fichier: ");
    scanf("%s",&nomfichier);
   /* if((f=fopen(nomfichier,"r+"))==NULL)
        {
           printf("Erreur d'ouverture du fichier %s",nomfichier);
           exit(1);
        }*/
    if((f=fopen(nomfichier,"r+"))!=NULL)
    {
        printf("copie des elements du fichier dans la liste chainee....\n");

        while((ch=fgets(chaine,256,f))!=NULL)
           {
               printf("dans le while");
                sscanf(ch,"%s %s %d",e.nom,e.matricule,&e.age);
                  //printf("\n%16s %14s %6d", etu.nom,etu.mat,etu.age);

                  courant->suivant=dernier;
                  courant=(struct cellule*)malloc(sizeof(struct cellule ));
                  strcpy(courant->donnee.nom,e.nom);
                  strcpy(courant->donnee.matricule, e.matricule);
                  courant->donnee.age = e.age;
                  dernier=courant;
            }
            L=dernier;
    }



    return L;
     free(courant);
     fclose(f);
    printf("Fin de la copie\n\n");

}

void afficher_liste( Liste l)
{
    Liste courant;
    courant=l;


    int i=1;
    while (courant!=NULL)
    {
        printf("\n\n\n\n");
        printf("Information de l'etudiant n: %d\n",i);
        printf("nom: %s\n",courant->donnee.nom);
        printf("matricule: %s\n",courant->donnee.matricule);
        printf("age: %d\n",courant->donnee.age);
        //free(courant);
        courant=courant->suivant;
        i++;

    }

}
void affichlistgd(Liste laffich)
{
    Liste  courant =laffich;
    int i=1;
    //a=n;
    //printf("la liste chainee");
if (courant !=NULL)
    {
        printf("\n\n\n\n");
        printf("Information de l'etudiant n: %d\n",i);
        printf("nom: %s\n",courant->donnee.nom);
        printf("matricule: %s\n",courant->donnee.matricule);
        printf("age: %d\n",courant->donnee.age);
        i++;
        affichlistgd(courant->suivant);
    }
}
void creerfichier()
{
	FILE *f;
	ET e;
	int rep=1;
	char nomfichier[20];
    printf ("Entrez  le nom du fichier: ");
    scanf("%s",&nomfichier);


    if((f=fopen(nomfichier,"w"))==NULL)
    {
        printf("Erreur de creation du fichier!!");
        exit(1);
    }
    while(rep==1)

        {
            printf("\n Entrez les informations sur l'etudiant a enregistrer\n");
            printf("Nom:\t");
            scanf("%s",e.nom);
            printf("\nmatricule:\t");
            scanf("%s",e.matricule);
            printf("\nage:\t");
            scanf("%d",&e.age);
            printf("%10s \t  %10s  \t %2d", e.nom,e.matricule,e.age);
            fprintf(f,"%1s %s %d\n",e.nom,e.matricule,e.age);
            printf("\nvoulez-vous enregistrer un autre etudiant");
            scanf("%d",&rep);

        }

}
