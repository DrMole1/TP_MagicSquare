
//BUT : Créer un carré magique, tableau d'entiers de 5 par 5 ou 7 par 7, incrémenté par des valeurs de 1 à 25 ou 1 à 49.
//PRINCIPE : Le premier entier 1 se trouve au nord du milieu de la table
//On place les chiffres de façon croissante en allant au nord est de la position courante, une seule fois
//Si la place est déjà prise, on se déplace au nord-ouest jusqu'à trouver cette place libre
//La grille est considérée comme sphérique
//Créer algo du carré magique en tableau à 2 DIM qui matérialisera la grille
//Structure enregistrement contenant les positions x et y
//Fonctionne pour 5 par 5 ou 7 par 7
//Fonctions initialiser, avancer gauche, avancer droite, avancer corriger (donc enclencher avancer gauche), rechercher, placer, afficher,
//ENTREES : Aucune entrée
//SORTIE : Le carré magique

//implémentations des bibliothèques (macros)
#include <stdio.h>
#include <stdlib.h>

//déclarations des constantes
#define COTE 5  //à changer par 7 pour une grille de 7x7 !
#define SUP 6
#define CMIN 1
#define CSMIN 0
#define CMAX 5
#define CSMAX 6
#define MIN 1
#define XSTART 3
#define YSTART 2
#define XSTARTSUP 4
#define YSTARTSUP 3

//on définit la structure tJeton
typedef struct tJeton
{
    int nX;
    int nY;

}tJeton;

//Enumération du booléen
typedef enum Bool {false,true} Bool;

// Prototype : signatures des méthodes
// ======================================================================
void initialiser(int pnCarre[COTE][COTE], tJeton *pJeton);
void afficher(const int nCarre[COTE][COTE]);
void avancer_droite (tJeton *pJeton);
void avancer_gauche(tJeton *pJeton);
Bool rechercher_vide(const tJeton Jeton, const int nCarre[COTE][COTE]);
void avancer(tJeton *pJeton);
void placer(const tJeton Jeton, int pnCarre[COTE][COTE], const int nCpt);
// ======================================================================



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
    for (nCpt = 1 ; nCpt<COTE*COTE +1 ; nCpt++)
    {
        avancer_droite (&Jeton);
        avancer(&Jeton);
        if (rechercher_vide (Jeton, nCarre)==0)
        {
            avancer_gauche(&Jeton);
            avancer(&Jeton);
            placer (Jeton, nCarre, nCpt);
        }
        else
        {
            placer (Jeton, nCarre, nCpt);
        }
    }

    //affichage du Carre à l'écran
    afficher(nCarre);

    return 0;
}


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
    for (nCpt=MIN ; nCpt < SUP ; nCpt++)
    {
        for (nCpt2=1 ; nCpt2 < SUP ; nCpt2++)
        {
            pnCarre[nCpt][nCpt2] = 0;
        }
    }

    //Initialisation des propriétés du Jeton
    pJeton->nX = XSTART;  // Convention pour passer une valeur dans un pointeur dans une structure !
    pJeton->nY = YSTART;
    if (COTE == 7)
    {
        pJeton->nX = XSTARTSUP;  // si jamais la grille est de 7x7
        pJeton->nY = YSTARTSUP;
    }
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
    for (nCpt=MIN ; nCpt < SUP ; nCpt++)
    {
        printf("\n");  //retour chariot
        for (nCpt2=1 ; nCpt2 < SUP ; nCpt2++)
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
    if (pJeton->nX == CSMIN)
    {
        //on le fait revenir en WRAP à droite de la grille
        pJeton->nX = CMAX;
    }
    else if (pJeton->nX == CSMAX)
    {
        pJeton->nX = CMIN;
        //on le fait revenir en WRAP à gauche de la grille
    }

    if (pJeton->nY == CSMIN)
    {
        pJeton->nY = CMAX;
        //on le fait revenir en WRAP en bas de la grille
    }
    else if (pJeton->nY == CSMAX)
    {
        pJeton->nY = CMIN;
        //on le fait revenir en WRAP en haut de la grille
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

//fichier .h qui détient les bibliothèques/déclarations
//fichier .c qui contient les fonctions
//fichier .c qui contient le programme principal
