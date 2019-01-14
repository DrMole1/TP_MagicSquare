//implémentations des bibliothèques et fichier annexes (macros)
#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "function.c"




//Fonction
//Implémentation
// =============================================================
// Description : Méthode pour faire apparaître un carré magique sur l'écran
// Entrées : /
// Sorties : Un tableau qui est le carré magique
// Note :
// =============================================================
int main()  //programme principal MAIN
{
    //déclaration des variables locales au main
    int nCarre[COTE][COTE];
    int nCpt=1;
    tJeton Jeton;

    //procédure d'initialisation
    initialiser(nCarre, &Jeton);

    //boucle de traitement principal
    for (nCpt = 1 ; nCpt<=COTE*COTE ; nCpt++)
    {
        avancer_droite (&Jeton);
        avancer(&Jeton);
        if (rechercher_vide (Jeton, nCarre)==0)
        {
            avancer_gauche(&Jeton);
            avancer(&Jeton);
        }
        placer (Jeton, nCarre, nCpt);
    }

    /*nCarre[4][5]=16;*/
    //affichage du Carre à l'écran
    afficher(nCarre);

    return 0;
}
