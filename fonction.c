#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// fonction gérant les tests de fin de la partie et de modification de la grille, renvoi 1 pour une defaite, 2 pour une victoire, 0 sinon.
int victoire(int* grille)
{
	for (int ind=0;ind<16;ind++)	//on commence par vérifier si il y a un 2048 dans la grille
	{
		if (grille[ind]==2048)
		{
			return 2;
		}
	}
	//Si non on vérifie si il y a une case vide
	for (int ind=0;ind<16;ind++)
	{
		if (grille[ind]==0)
		{
			return 0;
		}
	}
	//Si non on vérifie si on peut effectuer au moins une fusion dans au moins une direction
	for (int ligne=0;ligne<4;ligne++)
	{
		for (int colonne=0;colonne<4;colonne++)
		{
			if (colonne != 3 && (grille[4*ligne + colonne]==grille[4*ligne + colonne+1]))
			{
				return 0;
			}
			else if (colonne != 0 && (grille[4*ligne + colonne]==grille[4*ligne + colonne-1]))
			{
				return 0;
			}
			else if (ligne != 3 && (grille[4*ligne + colonne]==grille[4*ligne + colonne+4]))
			{
				return 0;
			}
			else if (ligne != 0 && (grille[4*ligne + colonne]==grille[4*ligne + colonne-4]))
			{
				return 0;
			}
		}
	}
	return 1; // Si aucun de ces cas n'est vrai alors on a perdu
}

int sont_egaux(int* grille, int* grille2)
{
	for (int indice=0;indice<16;indice++)
	{
		if (grille[indice]!=grille2[indice])
		{
			return 0;
		}
	}
	return 1;
}

//Ci dessous les fonctions pour l'affichage du jeu :

int taille_int(int nb)
{
	if(nb >= 1000) return 4 ;
	if(nb >= 100) return 3 ;
	if(nb >= 10) return 2 ;
	if(nb == 0) return 0 ;
	return 1 ;
}

void n_espaces(int n) //Affiche n espaces
{
	for(int i = 0 ; i<n ; i++)
	{ 
		printf(" ") ;
	}
}

void affichage(int* tab) //Affichage de la grille
{
	printf("\n-----------------------\n") ;

	for(int j = 0 ; j<4 ; j++)
	{
		for(int i = 0 ; i<4 ; i++)
		{
			if(tab[(j*4)+i] != 0) printf("%d", tab[(j*4)+i]) ; //On affiche le nombre puis "4 - taille du nombre" espaces pour que toutes les lignes ai graphiquement la meme longueur.
			n_espaces(4-taille_int(tab[(j*4)+i])) ;
			printf("| ") ;
		}
		printf("\n-----------------------\n") ;
	}
}

//Ci dessous les fonctions modifiant le tableau du jeu :

void init_grille(int *grille)
{
	for (int indice = 0; indice < 16; indice++)
	{
		grille[indice] = 0;
	}
}

void rajoute_2(int* tab)
{
	int emplacements_vides[16] ; //On crée un tableau qui contiendra les indices des cases de la grille de jeu valant 0. (qui sont au maximum de 16 du coup)
	int acc = 0; //Le nombre de case valant 0. (donc la taille de emplacement_vides)
	for(int i = 0 ; i<16 ; i++)
	{
		if(tab[i] == 0)
		{
			emplacements_vides[acc] = i ;
			acc++ ;
		}
	}
	if (acc!=0)//Les indices des cases vides sont ajouté dans le tableau crée préalablement, on tire ensuite au sort l'indice de la case qui sera mise à 2
	{
		int emplacement_du_2 = emplacements_vides[rand() % acc] ;

		if(rand() % 100 <= 75) tab[emplacement_du_2] = 2 ;
		else tab[emplacement_du_2] = 4 ;
	}
}

void fusion (int *grille, int indice1, int indice2)
{
	grille[indice1] = 2 * grille[indice1];
	grille[indice2] = 0;
}

void echange (int *grille, int indice1, int indice2)
{
	grille[indice1] = grille[indice2];
	grille[indice2] = 0;
}

void turn_grid(int* grille)
{
	//on crée une grille temporaire contenant tout les éléments de la grille
	int temp_grid[16]; 
	for (int ind=0;ind<16;ind++)
	{
		temp_grid[ind] = grille[ind];
	}
	int ind_case = 0; 
	//on parcours les colonnes de la grille temporaire pour remplir la grille (pour faire la rotation)
	for (int i=12;i<16;i++)
	{
		for (int j = i;j>=(i%4);j-=4)
		{
			grille[ind_case] = temp_grid[j];
			ind_case += 1;
		}
	}
}

void deplacement_ligne_droite(int* grille,int case1)
{    
	for (int i = 0; i < 4; i++)
	{
		for (int indice = case1 + 3; indice > case1; indice--)
		{
			if (grille[indice] == 0 && grille[indice - 1] != 0)
			{
				echange (grille, indice, indice - 1);
			}
		}
	}
}

void deplacement_fusion_droite(int *grille)
{
	for (int case1 = 0; case1 < 16; case1 += 4)//pour chaque début de ligne
	{
		//deplacement des tuiles non fusionnées
		deplacement_ligne_droite(grille, case1);
		//fusion des tuiles de la ligne
		for (int ind=case1+3;ind>case1;ind--)
		{
			if (grille[ind]==grille[ind-1])
			{
				fusion(grille,ind,ind-1);
			}  
		}
		//deplacement des tuiles fusionnées
		deplacement_ligne_droite(grille, case1);
	}
}

void mouvement(int* grille,int id_mouvement) //id = 0:droite; 1:haut; 2:gauche; 3:bas
{
	//tourne la grille pour orienter vers la droite la direction du mouvement
	for (int i=0;i<id_mouvement;i++)
	{
		turn_grid(grille);
	}
	//effectue le mouvement vers la droite
	deplacement_fusion_droite(grille);
	//remet la grille dans la bonne orientation
	for (int i=0;i<4-id_mouvement;i++)
	{
		turn_grid(grille);
	}
}
