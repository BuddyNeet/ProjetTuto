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

/*Structure de Ouvrage*/
typedef struct{
    char cote[10];
    char titre[30];
    char categorie[30];
}Ouvrage;
/*Structure de Ouvrage*/

/*Fonctions*/
Lecteur lireLec(FILE *fe);
Lecteur lireLec2(void);
int chargementLecteur(char *nomFich, Lecteur **tLec, int tmax);
void affichageLec(Lecteur **tLec, int n);
int rechDicoNom(Lecteur **tLec, int n, char *val);
int InscriptionLec(Lecteur **tLec, int n, int tmax, Lecteur *l);
void clearBuffer(void);
int rechDicoPrenom(Lecteur **tLec, int n, char *val);
int supprimeLec(Lecteur **tLec, int n);
void ajoutEmprunt(Lecteur **tLec, int n);
void miseajour(Lecteur **tLec, int *n);
void test(void);
/*Fonctions*/
