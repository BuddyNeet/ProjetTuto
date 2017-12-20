#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet.h"

/*---- LECTEURS ----*/

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

/*---- LECTEURS ----*/

/*---- OUVRAGES ----*/

/*Lecture du fichier fe et retourne l'adresse de type Lecteur*/
Ouvrage lire1Ouvrage(FILE *fe){
    Ouvrage o;
    
    fscanf(fe, "%s", &o.cote);
	fgets(o.titre, 31, fe);
	o.titre[strlen(o.titre)-1] = '\0';
	fscanf(fe, "%s", &o.categorie);
	return o;
}
/*Lecture du fichier fe et retourne l'adresse de type Lecteur*/

/*Chargement dans un tableau de pointeur les adresses de types Lecteur dans le fichier fe*/
int chargementOuvrages(char *nomFich, Ouvrage **tOuv, int tmax){
	FILE *fe;
	Ouvrage *o;
	int i = 0;

	fe = fopen(nomFich, "r");
	if(fe == NULL){
		printf("Erreur ouverture fichier \n");
		return -1;
	}

	o = (Ouvrage*) malloc(sizeof(Ouvrage)); //Allocation dynamique de Lecteur
	if(o == NULL){
		printf("Erreur malloc \n");
		return -1;
	}
	*o = lire1Ouvrage(fe);

	while(feof(fe)==0){						//Tant que fin de fichier
		if(i == tmax){
			printf("Erreur tables pleines \n");
			return -1;
		}
		tOuv[i]=o;
        o = (Ouvrage*) malloc(sizeof(Ouvrage));
		if(o == NULL){
			printf("Erreur malloc \n");
			return -1;
		}
		*o = lire1Ouvrage(fe);
		i++;
	}
	fclose(fe);
	return i;
}
/*Chargement dans un tableau de pointeur les adresses de types Lecteur dans le fichier fe*/

/*Affichage du tableau de pointeur contenant les adresses de type Lecteur*/
void affichageOuvrage(Ouvrage **tOuv, int n){
	int i;
    
	printf("\n");
	for(i = 0; i < n; i++){
        printf("%s %s %s \n", tOuv[i]->cote, tOuv[i]->titre, tOuv[i]->categorie);
	}
	printf("\n");
}
/*Affichage du tableau de pointeur contenant les adresses de type Lecteur*/

/*---- OUVRAGES ----*/

/*---- LECTEUR ORDRE ALPHABETIQUE----*/

ListeLecteur listeVide(void){
	return NULL;
}

ListeLecteur insertionEnTete(ListeLecteur list, LecTag l){
	Maillon *x;

	x = (Maillon*)malloc(sizeof(Maillon));
	if (x == NULL) exit(1);
	x->l = l;
	x->suivant = list;
	return x;
}

ListeLecteur insertionCroissante(ListeLecteur list, LecTag l){

	if (list == NULL)
		return insertionEnTete(list, l);
	if (strcmp(l.numLec, list->l.numLec) <= 0)
		return insertionEnTete(list, l);

	list->suivant = insertionCroissante(list->suivant, l);
	return list;
}

ListeLecteur supprimeListe(ListeLecteur list){
	ListeLecteur x;

	x = list->suivant;
	free(list);
	return x; //adresse nouvelle élément en tete de liste
}

ListeLecteur suppressionCroissante(ListeLecteur list, LecTag l){

	if (list == NULL)
		return list;
	if (strcmp(l.numLec, list->l.numLec) <= 0)
		return list;
	if (strcmp(l.numLec, list->l.numLec) == 0)
		return supprimeListe(list);

	list->suivant = suppressionCroissante(list->suivant, l);
	return list;

}

void afficherEnsemble(ListeLecteur list){
	
	if( list == NULL ) return;
	
    printf("%s %s %s \n", list->l.numLec, list->l.nom, list->l.prenom);
	afficherEnsemble(list->suivant);
	return;	
}

/*---- LECTEUR ORDRE ALPHABETIQUE----*/

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
Lecteur lireLec2(Lecteur **tLec, int *n){
    
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
    ajoutEmprunt(tLec, *n);
 
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
	int posN, posP, answer, i;
	char nom[30], prenom[30];
	
	printf("Saisir nom et prénom du lecteur à supprimer: \n");
	scanf("%s %s", &nom, &prenom);
	posN = rechDicoNom(tLec, n, nom);
	posP = rechDicoPrenom(tLec, n, prenom);
	if (posN == posP){

		if((strcmp(tLec[posN]->nom, nom) == 0) && (strcmp(tLec[posP]->prenom, prenom) == 0)){
			printf("Voulez vous vraiment supprimer : %s %s ? \n", tLec[posN]->nom, tLec[posP]->prenom);
			printf("Répondre par 0(Non) ou 1(Oui) \n");
			scanf("%d", &answer);
			if(answer == 1){
				for(i = posN; i < n-1 ; i++){
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
	}else{
		printf("N'existe pas dans la liste\n");
		return n;
	}
}
/*Supprime un lecteur*/

/*Mise à jour dans un fichier intermédiaire*/
void miseajour(Lecteur **tLec, int *n){
	FILE *maj;
	Lecteur a;
	int i;

	maj = fopen("lecteurMaJ.liste", "w");
	if (maj == NULL) exit(1);
	
	for (int i = 0; i < *n; i++){
		fprintf(maj, "%s %s %s %s %s %s \n", tLec[i]->numLec, tLec[i]->nom, tLec[i]->prenom, tLec[i]->cp, tLec[i]->ville, tLec[i]->rue );
		fprintf(maj, "%s %s \n", tLec[i]->liste->cote, tLec[i]->liste->date);
	}

	return;
}
/*Mise à jour dans un fichier intermédiaire*/

/**/
void ajoutEmprunt(Lecteur **tLec, int n){
	char nom [30], prenom[30];
	int posN, posP;

	printf("Entrez le nom et prénom du lecteur auquel vous souhaitez ajouter un Emprunt\n");
	scanf("%s %s", &nom, &prenom);

	posN = rechDicoNom(tLec, n, nom);
	posP = rechDicoNom(tLec, n, prenom);

	if (posN == posP){
		printf("Ecrivez la référence de l'Emprunt: \n");
		scanf("%s", &tLec[posN]->liste->cote);
		printf("Ecrivez la date de type JJ-MM-AAAA: \n");
		scanf("%s", &tLec[posN]->liste->date);
		return;
	}else{
		printf("N'existe pas dans la liste\n");
		return;
	}

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
	Ouvrage *tOuv[50];
    Ouvrage *o;
	int n, tmax = 50, pos = 14, n2;
	char nomFichier[30]="lecteur.list", valNom[30]="Descartes", nomFichierO[30]="ouvrage.list"; 

    l = (Lecteur*) malloc(sizeof(Lecteur)); //Allocation dynamique de Lecteur
    if(l == NULL){
        printf("Erreur malloc \n");
        return ;
    }

	n = chargementLecteur(nomFichier, tLec, tmax);
	if (n == -1){
		printf("Erreur fonction chargement \n");
		return;
	}
	affichageLec(tLec, n);
    

	n2 = chargementOuvrages(nomFichierO, tOuv, tmax);
	if (n2 == -1){
		printf("Erreur fonction chargement \n");
		return;
	}
	affichageOuvrage(tOuv, n2);

    /**l=lireLec2(tLec, &n);
	n = InscriptionLec(tLec, n, tmax, l);*/
    
    
	/*affichageLec(tLec, n);
	miseajour(tLec, &n);*/

	//n = supprimeLec(tLec, n);
}
/*Fonction appellante*/
