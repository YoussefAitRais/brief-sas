#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max 30

// declaration des variable

typedef struct date
{

    int jour;
    int mois;
    int annee;



} date;

typedef struct Gtaches
{
    int idtache;
    char titre[100];
    char description [500];
    date dateecheance;
    char priorite[500];

} Gtaches;


// fonction ajouter un tache

void ajoutetache(Gtaches tache[],int i)
{




    tache[i].idtache=i+1;
    printf("-Ajouter Un Tache  %d \n",i+1);
    printf("------------espace----------\n");

    printf("  Ajouter Un titre \n");
    scanf ("  %s", &tache[i].titre);


    printf("  Ajouter Un description \n");
    scanf ("  %s", &tache[i].description);


    printf("    Ajouter la date de echeance \n");

    // verification d'ate echeance

    do {
    // jour entre 1 et 31
    printf("-jour : \n");
    scanf (" %d", &tache[i].dateecheance.jour);
    if ( tache[i].dateecheance.jour <1 || tache[i].dateecheance.jour > 31)
    {
        printf("Erreur: le jour doit etre entre 1 et 31.\n");
    }
    }while( tache[i].dateecheance.jour <1 || tache[i].dateecheance.jour > 31);

    // le mois entre 1 et 12
    do {
    printf("-mois: \n");
    scanf (" %d", &tache[i].dateecheance.mois);
    if ( tache[i].dateecheance.mois <1 || tache[i].dateecheance.mois > 12)
    {
        printf("Erreur: le mois doit etre entre 1 et 12.\n");
    }
    } while ( tache[i].dateecheance.mois <1 || tache[i].dateecheance.mois > 12);

    // l'annee <=0
    do {
    printf("-annee : \n");
    scanf (" %d", &tache[i].dateecheance.annee);
    if (tache[i].dateecheance.annee < 2000 || tache[i].dateecheance.annee > 2050)
    {
        printf("Erreur: le annee doit etre entre 2000 et 2030.\n");
    }

    } while (tache[i].dateecheance.annee < 2000 || tache[i].dateecheance.annee > 2050 );

    printf("  -Ajouter une priorite : high| medium | low : \n");

    // verification de priorite
    while (1){
         scanf ("%s", &tache[i].priorite);

    if ( strcmp (tache[i].priorite , "high") ==0 ||
         strcmp (tache[i].priorite , "medium") ==0 ||
         strcmp (tache[i].priorite , "low") ==0)
        {
        break;
 }
        printf ("Erreur : la reponse doit etre entre 'high' 'medium' 'low' \n ");
    }
        printf("|-----------------------------------|\n");
}
// Fonction pour modifier une tâche

void modifietache (Gtaches tache[], int i)
{


    printf(" -modifier Un Tache  %d \n",i);
    printf("|------------espace----------| \n");

    printf(" -modifier Un titre \n");

    scanf (" %s", &tache[i].titre);


    printf("-modifier Un description \n");
    scanf ("%s", &tache[i].description);


    printf("-modifier la date de echeance \n");
    printf("--jour : \n");
    scanf ("%d", &tache[i].dateecheance.jour);
    printf("--mois: \n");
    scanf ("%d", &tache[i].dateecheance.mois);
    printf("--annee : \n");
    scanf ("%d", &tache[i].dateecheance.annee);



    printf("-modifier une priorite : \n");
    scanf ("%s", &tache[i].priorite);

    printf("|-----------------------------------|\n");
}

// fonction pour supprimer une tâche

void suprimetache ( Gtaches tache[], int nbr ,int index)
{



    printf("|-----------------------------------|\n");
    Gtaches tm;
    for (int i=index ; i<nbr ; i++)
    {
        tm=tache[i];
        tache[i] = tache[i+1] ;
        tache[i+1]=tm;
    }

}

//fonction filtre une tache

void filtretache ( Gtaches tache[], char priorite [], int nbr)

{
    for ( int i = 0 ; i< nbr ; i++)
    {

        if ( strcmp (tache[i].priorite, priorite) == 0 )

        {
            printf("La  Tache : %d \n",i+1);

            printf ("Un titre : %s \n", tache[i].titre);
            scanf ("Un description : %s \n", tache[i].description);


            printf("la date de echeance \n");

            printf ("jour : %d  \n", tache[i].dateecheance.jour);
            printf ("mois: %d \n", tache[i].dateecheance.mois);
            printf ("annee : %d \n", tache[i].dateecheance.annee);

            printf ("une priorite : %s \n", tache[i].priorite);

            printf("|-----------------------------------|\n");
        }

    }
}

main ()
{

    struct Gtaches tache[max];
    int ch,nbr=0;
    int indice;

// Afficher le menu principal
// Options :
// 1. Ajouter une tâche
// 2. Afficher la liste des tâches
// 3. Modifier une tâche
// 4. Supprimer une tâche
// 5. Filtrer les tâches par priorité
    bool close = false;
    do
    {
        printf(" ===>|| Afficher Le Menu Principale : ||<====\n");
         printf("                                         \n");

        printf("         1-Ajouter Un Tache : \n");
        printf("         2-Afficher la liste des taches : \n");
        printf("         3-Modifier une tache : \n");
        printf("         4-Supprimer une tache : \n");
        printf("         5-Filtrer les taches par priorite: \n");

        printf("                                         \n");
        printf("======> Donnez votre choix : <======= \n");
        scanf("%d",&ch);

        printf("|-----------------------------------|\n");


        switch(ch)
        {
        case 1 :

            ajoutetache(tache,nbr);
            nbr++;
            break;

        case 2 :
            if (nbr==0)
            {
                printf("---------Aucun Tache-----  \n");
            }

            //afficher les tache
            for (int i=0 ; i<nbr ; i++)

            {

                printf("--La  Tache : %d \n",tache[i].idtache);

                printf ("--Un titre : %s \n", tache[i].titre);


                scanf ("--Un description : %s \n", tache[i].description);


                printf("--la date de echeance \n");

                printf ("jour : %d  \n", tache[i].dateecheance.jour);
                printf ("mois: %d \n", tache[i].dateecheance.mois);
                printf ("annee : %d \n", tache[i].dateecheance.annee);

                printf ("une priorite : %s \n", tache[i].priorite);
                printf("|-----------------------------------|\n");
            }
            break;
        case 3 :


            if (nbr==0)
            {
                printf("---------Aucun Tache----- \n");
            }

            printf("--Donner moi un indice \n");
            scanf("%d", &indice);
            modifietache ( tache, indice-1);

            printf( "----------Bien Modifie-----------\n");
            printf("|-----------------------------------|\n");

            break;
        case 4 :
            if (nbr==0)
            {
                printf(" ---------Aucun Tache----- \n");
            }
             int indx;
                printf("------------Suprimmer une tache---------- \n");
                printf ("--Saisir l'indice \n");
                scanf("%d", &indx);
            suprimetache(tache, nbr,indx-1);
            nbr--;
            printf("Bien Supprimer \n");
            break;

        case 5 :

            printf("Sasir La priorite\n");
            char pr [20];
            scanf("%s", &pr);

            filtretache(tache,pr,nbr);
            break;

        case 0:
            printf("Au revoir");
            close = true;
            break;
        default :
            printf("Au revoir");
            close = true;
            break;
        }
    }
    while(close == false);
    return 0;
}
