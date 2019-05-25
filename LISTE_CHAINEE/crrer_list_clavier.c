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

Liste creer_liste(Liste L);
//ET tab[tail];

main()
 {

    Liste maliste=NULL;
    int i,n;
    maliste=creer_liste(maliste);
    afficher_liste(maliste);
    //affichlistgd(maliste);

 }

Liste creer_liste(Liste L)
{
    Liste dernier=NULL ,courant;
    int i=1,rep=1;

    while (rep==1)
    {
        printf("Enregistrement de l'Etudiant n: %d \n\n",i);
        //Excution du NEW P
        courant = (struct cellule*)malloc (sizeof (struct cellule));
        courant->suivant=dernier;

        printf("Nom:\t\t");
        scanf("%s",courant->donnee.nom);
       // printf("nom: %s\n",courant->donnee.nom);

        printf("Matricule:\t\t");
        scanf("%s",courant->donnee.matricule);
        //printf("matricule: %s\n",courant->donnee.matricule);

        printf("Age:\t\t");
        scanf("%d",&courant->donnee.age);
        //printf("age: %d\n",courant->donnee.age);
        dernier=courant;
        printf("Continuer l'enregistrez ?(0/1)");
        scanf("%d",&rep);
        i++;
    }
    L=dernier;
    return L;
    //libère p
    free(courant);


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
