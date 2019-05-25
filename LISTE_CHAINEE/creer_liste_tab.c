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

Liste creer_liste(ET t[], int n,Liste L);
ET tab[tail];

main()
 {

    Liste maliste=NULL;
    int i,n;
    printf ("Entrez la taille du vecteur");
    scanf("%d",&n);
    for (i=0; i<n;i++)
        {
            printf("Entrez les informations de l'etudiant n:%d\n",i+1);
            printf("nom:  ");
            scanf("%s",&tab[i].nom);
            printf("matricule:  ");
            scanf("%s",&tab[i].matricule);
            printf("age:  ");
            scanf("%d",&tab[i].age);
        }

   /* for (i=0; i<4;i++)
        {
            printf("les informations de l'etudiant n:%d\n",i+1);
            printf("nom:  %s\n",tab[i].nom);
            printf("matricule:  %s\n",tab[i].matricule);
            printf("age:  %d\n\n",tab[i].age);
        }*/

    maliste=creer_liste(tab,n,maliste);
    afficher_liste(maliste);
    //affichlistgd(maliste);

 }

Liste creer_liste(ET t[], int n,Liste L)
{
    Liste dernier=NULL ,courant;
    int i=0;
    printf("copie des elements dans la liste chainee....\n");
    while (i<n)
    {
        courant = (struct cellule*)malloc (sizeof (struct cellule));
        courant->suivant=dernier;

        strcpy (courant->donnee.nom,t[i].nom);
        strcpy(courant->donnee.matricule,t[i].matricule);
        courant->donnee.age=t[i].age;
        dernier=courant;
        i++;
    }
    L=dernier;
    return L;
     free(courant);
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
