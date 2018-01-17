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
    char cote[10];
    char titre[30];
    char categorie[30];
}Ouvrage;
/*Structure d'Ouvrage*/

/*Fonctions Lecteurs*/
Lecteur lireLec(FILE *fe);
Lecteur lireLec2(Lecteur **tLec, int *n);
int chargementLecteur(char *nomFich, Lecteur **tLec, int tmax);
void affichageLec(Lecteur **tLec, int n);
int InscriptionLec(Lecteur **tLec, int n, int tmax, Lecteur *l);
void clearBuffer(void);
int rechSequentiel(Lecteur **tLec, int n, char *val, int *trouve);
int supprimeLec(Lecteur **tLec, int n);
void ajoutEmprunt(Lecteur **tLec, int n);
void miseajour(Lecteur **tLec, int *n);
void sauvegardeBin(Lecteur **tLec, int n, Ouvrage **o, int n2);
/*Fonctions Lecteurs*/

/*Fonctions Ouvrages*/
Ouvrage lire1Ouvrage(FILE *fe);
int chargementOuvrages(char *nomFich, Ouvrage **tOuv, int tmax);
void affichageOuvrage(Ouvrage **tOuv, int n);
/*Fonctions Ouvrages*/

/*Fonctions Menu*/
void selectGui(int *val);
void menu(Lecteur **tLec, int n);
/*Fonctions Menu*/

/*Fonction Test*/
void test(void);
/*Fonction Test*/
