#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED



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
#endif // HEAD_H_INCLUDED
