#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

/*Lecture du fichier fe et retourne l'adresse de type Lecteur*/
Lecteur lireLec(FILE *fe){
    Lecteur l;
    
    fscanf(fe, " %s %s %s %s %s", &l.numLec, &l.nom, &l.prenom, &l.cp, &l.ville);
	fgets(l.rue, 61, fe);
	l.rue[strlen(l.rue)-1] = '\0';
	fscanf(fe, "%s %s", &l.liste->cote, &l.liste->date);
	return l;
}
/*Lecture du fichier fe et retourne l'adresse de type Lecteur*/

/*Chargement dans un tableau de pointeur les adresses de types Lecteur dans le fichier fe*/
int chargementLecteur(char *nomFich, Lecteur **tLec, int tmax){
	FILE *fe;
	Lecteur *l;
	int i = 0;

	fe = fopen(nomFich, "r");
	if(fe == NULL){
		printf("Erreur ouverture fichier \n");
		return -1;
	}

	l = (Lecteur*) malloc(sizeof(Lecteur)); //Allocation dynamique de Lecteur
	if(l == NULL){
		printf("Erreur malloc \n");
		return -1;
	}
	*l = lireLec(fe);

	while(feof(fe)==0){						//Tant que fin de fichier
		if(i == tmax){
			printf("Erreur tables pleines \n");
			return -1;
		}
		tLec[i]=l;
        l = (Lecteur*) malloc(sizeof(Lecteur));
		if(l == NULL){
			printf("Erreur malloc \n");
			return -1;
		}
		*l = lireLec(fe);
		i++;
	}
	fclose(fe);
	return i;
}
/*Chargement dans un tableau de pointeur les adresses de types Lecteur dans le fichier fe*/

/*Affichage du tableau de pointeur contenant les adresses de type Lecteur*/
void affichageLec(Lecteur **tLec, int n){
	int i;
    
	printf("\n");
	for(i = 0; i < n; i++){
        printf("%s %s %s %s %s %s \n", tLec[i]->numLec, tLec[i]->nom, tLec[i]->prenom, tLec[i]->cp, tLec[i]->ville, tLec[i]->rue);
        printf("%s %s \n", tLec[i]->liste->cote, tLec[i]->liste->date);
	}
	printf("\n");
}
/*Affichage du tableau de pointeur contenant les adresses de type Lecteur*/

/* Recherche dico */
int rechDicoNom(Lecteur **tLec, int n, char *val){
    int pos, m;
    
    if(n == 0)
        return 0;
    if(n == 1)
        if(strcmp(val, tLec[0]->nom) <= 0)
            return 0;
        else
            return 1;
    m = (n-1)/2;
    if(strcmp(val, tLec[m]->nom) <= 0){
        pos = rechDicoNom(tLec, m+1, val);
    }else{
        pos = m+1+rechDicoNom(tLec+m+1, n-(m+1), val);
    }
    return pos;    
}
/* Recherche dico */

/*Inscription d'un lecteur et retourne l'adresse du tableau*/
/*Lecteur *InscriptionLec(Lecteur **tLec, int *n, int *tmax){
	Lecteur l;
	char res;

	if (*n == *tmax){
		l = (Lecteur*)realloc(tLec, 1+*tmax*sizeof(Lecteur));
		if (l == NULL){
			exit (1);
		} else {
			printf("Saisir l'inscription Lecteur: \n");
			scanf("%s %s %s %s %s %s", &l.numLec, &l.nom, &l.prenom, &l.cp, &l.ville, &l.rue);
			printf("Saisir emprunt du lecteur: (Si existant écrire Y sinon écrire N ) \n");
			scanf("%c", &res);
			if (res  == 'N'){
				*l.liste->cote = ' ';
				*l.liste->date = ' ';
			} else {
			printf("Saisir sous forme 'CXXX DD-MM-YYYY'\n");
			scanf("%s %s", &l.liste->cote, &l.liste->date);
			*n += 1;
			*tmax += 1;
			return *l;
			}
		}
	} else {
	printf("Saisir l'inscription Lecteur: \n");
	scanf("%s %s %s %s %s %s", &l.numLec, &l.nom, &l.prenom, &l.cp, &l.ville, &l.rue);
	printf("Saisir emprunt du lecteur: (Si existant écrire Y sinon écrire N ) \n");
	scanf("%c", &res);
		if (res  == 'N'){
			*l.liste->cote = ' ';
			*l.liste->date = ' ';
		} else {
	printf("Saisir sous forme 'CXXX DD-MM-YYYY'\n");
	scanf("%s %s", &l.liste->cote, &l.liste->date);
	*n += 1;
	return *l;
		}
	}
}*/
/*Inscription d'un lecteur et retourne l'adresse du tableau*/

/*Lecteur * InscriptionLec(int *tmax, int *n){
	Lecteur *l;
	int i;
	if (*n == *tmax){
			l=(Lecteur*)realloc((*tmax+1)*sizeof(Lecteur));
		if (l == NULL) exit(1);
		l = ecrireLec();
	}
	l = ecrireLec();
	return l;
}

*/
/*Lecteur ecrireLec(void){
	Lecteur l;

	printf("Saisir l'inscription Lecteur: \n");
	scanf("%s %s %s %s %s %s", &l.numLec, &l.nom, &l.prenom, &l.cp, &l.ville, &l.rue);
	printf("Saisir emprunt du lecteur: (Si existant écrire Y sinon écrire N ) \n");
	scanf("%c", &res);
	if (res  == 'N'){
		l.liste->cote = ' ';
		l.liste->date = ' ';
	} else {
	printf("Saisir sous forme 'CXXX DD-MM-YYYY'\n");
	scanf("%s %s", &l.liste->cote, &l.liste->date);;
	return l;
	}
}*/

/*Nouvelle emprunt dans un lecteur existant*/
/*Emprunt newEmprunt(Lecteur l){
	Emprunt e;



}*/
/*Nouvelle emprunt dans un lecteur existant*/

/*Fonction appellante*/
void test(void){
	Lecteur *tLec[50];
	int n, tmax = 50, pos = 14;
	char nomFichier[30]="lecteur.list", valNom[30]="Descarte";

	n = chargementLecteur(nomFichier, tLec, tmax);
	if (n == -1){
		printf("Erreur fonction chargement \n");
		return;
	}
	affichageLec(tLec, n);
    
    pos = rechDicoNom(tLec, n, valNom);
    printf("Position de %s : %d \n", valNom, pos);

	/*tLec[n] = InscriptionLec(&n, &tmax);
	affichageLec(tLec, n);

    return;*/
}
/*Fonction appellante*/
