#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

/*Lecture du fichier fe et retourne l'adresse de type Lecteur*/
Lecteur lireLec(FILE *fe){
    Lecteur l;
    
    fscanf(fe, "%s %s %s %s %s", &l.numLec, &l.nom, &l.prenom, &l.cp, &l.ville);
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

/* Recherche dico prénom */
int rechDicoPrenom(Lecteur **tLec, int n, char *val){
    int pos, m;
    
    if(n == 0)
        return 0;
    if(n == 1)
        if(strcmp(val, tLec[0]->prenom) <= 0)
            return 0;
        else
            return 1;
    m = (n-1)/2;
    if(strcmp(val, tLec[m]->prenom) <= 0){
        pos = rechDicoNom(tLec, m+1, val);
    }else{
        pos = m+1+rechDicoNom(tLec+m+1, n-(m+1), val);
    }
    return pos;    
}
/* Recherche dico prénom */

/*Decale à droite*/
void DecalerAD(Lecteur **tLec, int n, int pos){
	int i;

	for(i=n-1; i>= pos; i--)
		tLec[i+1] = tLec[i];
}
/*Decale à droite*/

/*Lis un lecteur au clavier*/
Lecteur lireLec2(void){
    
    Lecteur l;
    printf("Entrez le numero Lecteur: \n");
    scanf("%s", &l.numLec);
    clearBuffer();
    printf("Entrez le nom Lecteur: \n");
    scanf("%s", &l.nom);
    clearBuffer();
    printf("Entrez le prenom Lecteur: \n");
    scanf("%s", &l.prenom);
    clearBuffer();
    printf("Entrez le code postal du Lecteur: \n");
    scanf("%s", &l.cp);
    clearBuffer();
    printf("Entrez la ville du Lecteur: \n");
    scanf("%s", &l.ville);
    clearBuffer();
    printf("Entrez la rue du Lecteur: \n");
    fgets(l.rue, 61, stdin);
    l.rue[strlen(l.rue)-1] = '\0';
 
    return l;
}
/*Lis un lecteur au clavier*/

/*Inscrit un Lecteur et retourne la nouvelle taille logique du tableau*/
int InscriptionLec(Lecteur **tLec, int n, int tmax, Lecteur *l){
	int pos, i;

	// create fonction lecture depuis clavier pour mettre en paramètre d'entrée le pointeur de lecteur
    if( n== tmax) {
        printf( "table pleine \n");
        return -1;}
	


  
	pos = rechDicoNom(tLec, n, l->nom);

	DecalerAD(tLec, n, pos);
   
    tLec[pos]=l;
    n=n+1;
	return n;
    
}
/*Inscrit un Lecteur et retourne la nouvelle taille logique du tableau*/

/*Supprime un lecteur*/
int supprimeLec(Lecteur **tLec, int n){
	int pos, answer, i;
	char nom[30];
	
	printf("Saisir nom lecteur à supprimer: \n");
	scanf("%s", &nom);
	pos = rechDicoNom(tLec, n, nom);
	if(strcmp(tLec[pos]->nom, nom) == 0){
		printf("Voulez vous vraiment supprimer : %s %s ? \n", tLec[pos]->nom, tLec[pos]->prenom);
		printf("Répondre par 0 ou 1 \n");
		scanf("%d", &answer);
		if(answer == 1){
			for(i = pos; i < n-1 ; i++){
				*tLec[i]=*tLec[i+1];
			}
			free(tLec[n-1]);
			return n-1;
		}else{
			return n;
		}
	}else{
		printf("La référence recherchée doesn't exist \n");
	}

}
/*Supprime un lecteur*/

/**/
void ajoutEmprunt(Lecteur **tLec, int n){
	char nom [30];
	int pos;

	printf("Entrez le nom du lecteur auquel vous souhaitez ajouter un Emprunt\n");
	scanf("%s", &nom);

	pos = rechDicoNom(tLec, n, nom);

	printf("Ecrivez la référence de l'Emprunt: \n");
	scanf("%s", &tLec[pos]->liste->cote);
	printf("Ecrivez la date de type JJ-MM-AAAA: \n");
	scanf("%s", &tLec[pos]->liste->date);

}
/**/

/*Clear le buffer d'entrée standart*/
void clearBuffer(void){
	int c;

	while((c = getchar()) != '\n' && c != EOF );

}
/*Clear le buffer d'entrée standart*/

/*Fonction appellante*/
void test(void){
	Lecteur *tLec[50];
    Lecteur *l;
    l = (Lecteur*) malloc(sizeof(Lecteur)); //Allocation dynamique de Lecteur
    if(l == NULL){
        printf("Erreur malloc \n");
        return ;
    }
	int n, tmax = 50, pos = 14;
	char nomFichier[30]="lecteur.list", valNom[30]="Descarte";

	n = chargementLecteur(nomFichier, tLec, tmax);
	if (n == -1){
		printf("Erreur fonction chargement \n");
		return;
	}
	affichageLec(tLec, n);
    
    /*pos = rechDicoNom(tLec, n, valNom);
    printf("Position de %s : %d \n", valNom, pos);*/
    *l=lireLec2();
	n = InscriptionLec(tLec, n, tmax, l);
    
    //printf("%s %s %s %s %s %s \n", l->numLec, l->nom, l->prenom, l->cp, l->ville, l->rue);
	affichageLec(tLec, n);

	ajoutEmprunt(tLec, n);
	affichageLec(tLec, n);

	n = supprimeLec(tLec, n);
	affichageLec(tLec, n);

}
/*Fonction appellante*/
