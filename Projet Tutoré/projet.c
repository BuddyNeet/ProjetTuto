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
        printf("\t %s %s \n", tLec[i]->liste->cote, tLec[i]->liste->date);
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

/*Recherche d"une chaîne de caractère avec confirmation de la recherche ( variable trouve )*/
int rechSequentiel(Lecteur **tLec, int n, char *val, int *trouve){
	int i;

	for (i = 0; i < n; i++){
		//AJOUTER  CONDITION POUR TROUVER LA POSITION MEME SI TROUVE = 0
		if(strcmp(tLec[i]->nom, val) == 0){
			*trouve = 1;
			return i;
		}
        if(strcmp(val, tLec[i]->nom) < 0){
            *trouve = 0;
            return i;
        }
	}
	*trouve = 0;
	return i;
}
/*Recherche d"une chaîne de caractère avec confirmation de la recherche ( variable trouve )*/

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
    return l;
}
/*Lis un lecteur au clavier*/

/*Inscrit un Lecteur et retourne la nouvelle taille logique du tableau*/
int InscriptionLec(Lecteur **tLec, int n, int tmax, Lecteur *l){
	int pos, trouve;

    if(n == tmax) {
        printf( "table pleine \n");
        return -1;
    }

	pos = rechSequentiel(tLec, n, l->nom, &trouve);

	if(trouve == 0){
		DecalerAD(tLec, n, pos);
   
    	tLec[pos]=l;
    	n=n+1;
    	return n;
    }
    printf("ERROR: le lecteur existe déjà\n");
	return n;
    
}
/*Inscrit un Lecteur et retourne la nouvelle taille logique du tableau*/

/*Supprime un lecteur*/
int supprimeLec(Lecteur **tLec, int n){
	int pos, answer, i, trouve;
	char nom[30];
	
	printf("Saisir nom du lecteur à supprimer: \n");
	scanf("%s", &nom);
	pos = rechSequentiel(tLec, n, nom, &trouve);
    
    if(trouve == 0){
        printf("Le lecteur à supprimer n'existe pas \ns");
        return n;
    }

    printf("Voulez vous vraiment supprimer : %s %s ? \n", tLec[pos]->nom, tLec[pos]->prenom);
    printf("Répondre par 0(Non) ou 1(Oui) \n");
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
}
/*Supprime un lecteur*/

/*Mise à jour dans un fichier intermédiaire*/
void miseajour(Lecteur **tLec, int *n){
	FILE *maj;
	int i;

	maj = fopen("lecteur.list", "w");
	if (maj == NULL) exit(1);
	
	for (int i = 0; i < *n; i++){
		fprintf(maj, "%s %s %s %s %s %s \n", tLec[i]->numLec, tLec[i]->nom, tLec[i]->prenom, tLec[i]->cp, tLec[i]->ville, tLec[i]->rue);
		fprintf(maj, "%s %s \n", tLec[i]->liste->cote, tLec[i]->liste->date);
	}
    fclose(maj);
	return;
}
/*Mise à jour dans un fichier intermédiaire*/

/*Sauvegarde des fichiers de données en binaire*/
void sauvegardeBin(Lecteur **tLec, int n, Ouvrage **o, int n2){
	FILE *fb, *fbo;
	fb = fopen("lecteurBin.backup","wb");
	fbo = fopen("ouvrageBin.backup","wb");
	if(fb == NULL) exit(1);
	if(fbo == NULL) exit(2);
	fwrite(&n, sizeof(int), 1, fb);
	fwrite(tLec, sizeof(Lecteur), n, fb);
	fclose(fb);
	fwrite(&n2, sizeof(int), 1, fbo);
	fwrite(o, sizeof(Ouvrage), n2, fbo);
	fclose(fbo);
}
/*Sauvegarde des fichiers de données en binaire*/


/*Ajout d'emprunt à un lecteur*/
void ajoutEmprunt(Lecteur **tLec, int n){
	char nom[30];
	int pos, trouve;

	printf("Entrez le nom du lecteur auquel vous souhaitez ajouter un Emprunt\n");
	scanf("%s", &nom);

	pos = rechSequentiel(tLec, n, nom, &trouve);
    if(trouve == 0){
        printf("Le lecteur n'existe pas\n");
        return;
    }
    
	printf("Ecrivez la référence de l'Emprunt: \n");
	scanf("%s", &tLec[pos]->liste->cote);
	printf("Ecrivez la date de type JJ-MM-AAAA: \n");
	scanf("%s", &tLec[pos]->liste->date);
	return;

}
/*Ajout d'emprunt à un lecteur*/

/*Clear le buffer d'entrée standard*/
void clearBuffer(void){
	int c;

	while((c = getchar()) != '\n' && c != EOF );

}
/*Clear le buffer d'entrée standard*/

/*Menu de sélection*/
void selectGui(int *val){
    printf("\n");
    printf("---- Menu de Séléction ----\n");
    printf("\n");
    printf("Choisir avec un chiffre \n");
    printf("\n");
    printf("1) Afficher la liste des lecteurs\n");
    printf("2) Afficher la liste des ouvrages\n");
    printf("3) Ajouter un lecteur\n");
    printf("4) Ajouter un emprunt\n");
    printf("5) Supprimer un lecteur\n");
    printf("6) Mise à jour fichier lecteur\n");
    printf("7) Sauvegarde des fichiers (binaire)\n");
    printf("0) Quitter le programme\n");
    printf("\n");
    scanf("%d", val);
}
/*Menu de sélection*/

/*Menu*/
void menu(Lecteur **tLec, int n){
    Lecteur *l;
	Ouvrage *tOuv[50];
    Ouvrage *o;
	int pos, n2, val = 0, tmax = 50, trouve;
	char nomFichierO[30]="ouvrage.list", rech[30]; 
    
    l = (Lecteur*) malloc(sizeof(Lecteur)); //Allocation dynamique de Lecteur
    if(l == NULL){
        printf("Erreur malloc \n");
        return ;
    }
    
    selectGui(&val);
    
    if(val == 1){	
        
        affichageLec(tLec, n);
        menu(tLec, n);
    
    }else if(val == 2){
        
        n2 = chargementOuvrages(nomFichierO, tOuv, tmax);
        if (n2 == -1){
            printf("Erreur fonction chargement \n");
            return;
        }
        affichageOuvrage(tOuv, n2);
        menu(tLec, n);
        
    }else if(val == 3){
        
        *l=lireLec2(tLec, &n);
        n = InscriptionLec(tLec, n, tmax, l);
        ajoutEmprunt(tLec, n);
        menu(tLec, n);
        
    }else if(val == 4){
        
        ajoutEmprunt(tLec, n);
        menu(tLec, n);
        
    }else if(val == 5){
        
        n = supprimeLec(tLec, n);
        menu(tLec, n);
        
    }else if(val == 6){
        
        printf("MAJ Faite dans le fichier lecteur.list \n");
        miseajour(tLec, &n);
        menu(tLec, n);
        
    }else if(val == 7){

        sauvegardeBin(tLec, n, tOuv, n2);
        menu(tLec, n);
        
    }else if(val == 0){
        
        printf("Vous avez quitté le programme. \n");
        return;
        
    }else{
        
        printf("Valeur incorrecte\n");
        menu(tLec, n);
        
    }
    
}
/*Menu*/

/*Fonction appellante*/
void test(void){
	Lecteur *tLec[50];
    int n, tmax = 50;
    char nomFichier[30]="lecteur.list";
        
    n = chargementLecteur(nomFichier, tLec, tmax);
    if (n == -1){
        printf("Erreur fonction chargement \n");
        return;
    }

    menu(tLec, n);

}
/*Fonction appellante*/
