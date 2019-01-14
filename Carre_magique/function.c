#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "head.h"

//Procédure
//Implémentation
// =============================================================
// Description : Méthode pour initialiser le tableau et le jeton
// Entrées : Le Tableau du carré et le jeton
// Sorties : Le Tableau du carré et le jeton tous deux initialisés
// Note : Pas de pointeur pour un tableau !
// =============================================================

void initialiser(int pnCarre[COTE][COTE], tJeton *pJeton)
{
    //déclaration des variables locales à la méthode
    int nCpt=0, nCpt2=0;

    //boucles imbriquées de traitement pour assigner à chaque cellule la valeur 0
    for (nCpt=MIN ; nCpt <= COTE ; nCpt++)
    {
        for (nCpt2=1 ; nCpt2 <= COTE ; nCpt2++)
        {
            pnCarre[nCpt][nCpt2] = 0;
        }
    }

    //Initialisation des propriétés du Jeton pour qu'il soit au nord du centre, peu importe le côté
    //utilisation d'un cast pour faire passer un double en int
    //le floor sert à tronquer à l'entier inférieur (floor=étage)
    pJeton->nX = (int)(floor(COTE/2)+1);
    pJeton->nY = (int)(floor(COTE/2));
}



//Procédure
//Implémentation
// =============================================================
// Description : Méthode pour afficher le tableau
// Entrées : Le Tableau du carré
// Sorties : Le Tableau du carré, affiché
// Note :
// =============================================================

void afficher(const int nCarre[COTE][COTE])
//méthode pour afficher un tableau
{
    //déclaration des variables locales à la méthode
    int nCpt=0, nCpt2=0;

    //boucles imbriquées pour afficher la grille
    for (nCpt=MIN ; nCpt <= COTE ; nCpt++)
    {
        printf("\n");  //retour chariot
        for (nCpt2=1 ; nCpt2 <= COTE ; nCpt2++)
        {
            printf("%d ", nCarre[nCpt][nCpt2]);
        }
    }
}



//Procédure
//Implémentation
// =============================================================
// Description : Méthode pour déplacer le jeton vers la droite
// Entrées : Le jeton
// Sorties : Le jeton
// Note :
// =============================================================

void avancer_droite (tJeton *pJeton)
{

    pJeton->nX = pJeton->nX - 1;
    pJeton->nY = pJeton->nY + 1;

}



//Procédure
//Implémentation
// =============================================================
// Description : Méthode pour déplacer le jeton vers la gauche
// Entrées : Le jeton
// Sorties : Le jeton
// Note :
// =============================================================

void avancer_gauche(tJeton *pJeton)
{

    pJeton->nX = pJeton->nX - 1;
    pJeton->nY = pJeton->nY - 1;

}



//Fonction
//Implémentation
// =============================================================
// Description : Méthode pour voir si la cellule est vide ou occupée
// Entrées : Le Tableau du carré, le jeton et la variable EstVide
// Sorties : La variable Vide
// Note : Fonction car renvoie un résultat
// =============================================================

Bool rechercher_vide(const tJeton Jeton, const int nCarre[COTE][COTE])
{
    Bool IsEmpty;
    if (nCarre[Jeton.nX][Jeton.nY] == 0)
    {
        // Si la valeur de la grille est 0, on appellera la procédure placer dans le programme principal
        IsEmpty = 1;
        // TO DO
    }
    else
    {
        //sinon, nous corrigeons la trajectoire du cheminement dans la programme principal
        IsEmpty = 0;
    }

    return IsEmpty;
}



//Procédure
//Implémentation
// =============================================================
// Description : Méthode pour avancer le jeton
// Entrées : Le jeton
// Sorties : La nouvelle position du jeton
// Note : Avancement en "wrap"
// =============================================================

void avancer(tJeton *pJeton)
{
    if (pJeton->nX>CMAX)
    {
        pJeton->nX=CMIN;
        //si le jeton dépasse vers la droite, on le fait revenir en WRAP vers la gauche
    }
    else if (pJeton->nX<CMIN)
    {
        pJeton->nX=CMAX;
        //si le jeton dépasse vers la gauche, on le fait revenir en WRAP vers la droite
    }

    if (pJeton->nY>CMAX)
    {
        pJeton->nY=CMIN;
        //si le jeton dépasse vers le bas, on le fait revenir en WRAP vers le haut
    }
    else if (pJeton->nY<CMIN)
    {
        pJeton->nY=CMAX;
        //si le jeton dépasse vers le haut, on le fait revenir en WRAP vers le bas
    }


}



//Procédure
//Implémentation
// =============================================================
// Description : Méthode pour placer une valeur dans le carré
// Entrées : Le Tableau du carré, le jeton et le compteur
// Sorties : La Tableau ayant une nouvelle valeur
// Note :
// =============================================================

void placer(const tJeton Jeton, int pnCarre[COTE][COTE], const int nCpt)
{
    //on affecte la valeur dans la cellule
    pnCarre[Jeton.nX][Jeton.nY] = nCpt;
}
