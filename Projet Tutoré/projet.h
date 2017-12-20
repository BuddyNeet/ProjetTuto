#include <stdio.h>
#include <stdlib.h>

/*Structure de Emprunt*/
typedef struct{
    char cote[10];
    char date[11];
}Emprunt;
/*Structure de Emprunt*/

/*Structure de Lecteur*/
typedef struct{
    char numLec[20];
    char nom[30];
    char prenom[30];
    char cp[6];
    char ville[30];
    char rue[60];
    Emprunt liste[50];
}Lecteur;
/*Structure de Lecteur*/

/*Structure d'Ouvrage*/
typedef struct{
    char cote[30];
    char titre[30];
    char categorie[30];
}Ouvrage;
/*Structure d'Ouvrage*/

/*Structure de Lecteur*/
typedef struct{
    char numLec[20];
    char nom[30];
    char prenom[30];
}LecTag;
/*Structure de Lecteur*/

/*Structure de liste chainée pour Lecteur*/ 
typedef struct liste{
    LecTag l;
    struct liste *suivant;    
}Maillon, *ListeLecteur;
/*Structure de liste chainée pour Lecteur*/ 

/*Fonctions Lecturs*/
Lecteur lireLec(FILE *fe);
Lecteur lireLec2(Lecteur **tLec, int *n);
int chargementLecteur(char *nomFich, Lecteur **tLec, int tmax);
void affichageLec(Lecteur **tLec, int n);
int rechDicoNom(Lecteur **tLec, int n, char *val);
int InscriptionLec(Lecteur **tLec, int n, int tmax, Lecteur *l);
void clearBuffer(void);
int rechDicoPrenom(Lecteur **tLec, int n, char *val);
int supprimeLec(Lecteur **tLec, int n);
void ajoutEmprunt(Lecteur **tLec, int n);
void miseajour(Lecteur **tLec, int *n);
ListeLecteur tabToList(Lecteur **tLec, int n, ListeLecteur list);
/*Fonctions Lecturs*/

/*Fonctions Ouvrages*/
Ouvrage lire1Ouvrage(FILE *fe);
int chargementOuvrages(char *nomFich, Ouvrage **tOuv, int tmax);
void affichageOuvrage(Ouvrage **tOuv, int n);
/*Fonctions Ouvrages*/

/*Fonctions Lecteur ordre alphabétique*/
ListeLecteur listeVide(void);
ListeLecteur insertionEnTete(ListeLecteur list, LecTag l);
ListeLecteur insertionCroissante(ListeLecteur list, LecTag l);
ListeLecteur supprimeListe(ListeLecteur list);
ListeLecteur suppressionCroissante(ListeLecteur list, LecTag l);
void afficherEnsemble(ListeLecteur list);
/*Fonctions Lecteur ordre alphabétique*/

/*Fonction Test*/
void test(void);
/*Fonction Test*/

/*Fonctions*/
