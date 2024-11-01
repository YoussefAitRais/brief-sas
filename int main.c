
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
                printf("--La  Tache : %d \n",i+1);

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
            suprimetache(tache, nbr);
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
            close = true;²
            break;
        }
    }
    while(close == false);
    return 0;
}

