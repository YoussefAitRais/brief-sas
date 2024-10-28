#include <stdio.h>
#include <stdlib.h>

#define max 30

typedef struct date
{

    int jour;
    int mois;
    int annee;


} date;

typedef struct Gtaches
{
    char titre[100];
    char description [500];
    date dateecheance;
    char priorite[500];

} Gtaches;

void ajoutetache(Gtaches tache[],int i)
{



    printf("Ajouter Un Tache  %d \n",i+1);
    printf("------------espace---------- \n");

    printf("Ajouter Un titre \n");

    scanf ("%s", &tache[i].titre);


    printf("Ajouter Un description \n");
    scanf ("%s", &tache[i].description);


    printf("Ajouter la date de echeance \n");
    printf("jour : \n");
    scanf ("%d", &tache[i].dateecheance.jour);
    printf("mois: \n");
    scanf ("%d", &tache[i].dateecheance.mois);
    printf("annee : \n");
    scanf ("%d", &tache[i].dateecheance.annee);



    printf("Ajouter une priorite : \n");
    scanf ("%s", &tache[i].priorite);




}
void affichertache( Gtaches tache[], int index )

{



}






main ()
{

    struct Gtaches tache[max];
    int ch,nbr=0;

// Afficher le menu principal
// Options :
// 1. Ajouter une tâche
// 2. Afficher la liste des tâches
// 3. Modifier une tâche
// 4. Supprimer une tâche
// 5. Filtrer les tâches par priorité
while(1){
    printf(" --------- Afficher Le Menu Principale : --------\n");

    printf("         1-Ajouter Un Tache : \n");
    printf("         2-Afficher la liste des taches : \n");
    printf("         3-Modifier une tache : \n");
    printf("         4-Supprimer une tache : \n");
    printf("         5-Filtrer les taches par priorite: \n");
        printf("------------Donnez votre choix :------------ \n");
        scanf("%d",&ch);


        switch(ch){
        case 1 :
             ajoutetache(tache,nbr);
             nbr++;
             break;
        case 2 :
             for (int i=0 ; i<nbr ; i++)

 {
    printf("La  Tache : %d \n",i+1);

    printf ("Un titre : %s \n", &tache[i].titre);


    scanf ("Un description : %s \n", &tache[i].description);


    printf("la date de echeance \n");

    printf ("jour : %d  \n", &tache[i].dateecheance.jour);
    printf ("mois: %d \n", &tache[i].dateecheance.mois);
    printf ("annee : %d \n", &tache[i].dateecheance.annee);



    printf ("une priorite : %s \n", &tache[i].priorite);

 }

             break;
        case 3 :
             break;
        default :
            break;




        }
}









    return 0;
}
