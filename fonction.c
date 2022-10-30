#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int victoire(int* grille)
{
	for (int ind=0;ind<16;ind++)
	{
		if (grille[ind]==0)
		{
			return 0;
		}
		else if (grille[ind] == 2048)
		{
			return 2;
		}
	}
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

void n_espaces(int n)
{
	for(int i = 0 ; i<n ; i++)
	{ 
		printf(" ") ;
	}
}

void affichage(int* tab)
{
	
	printf("\n-----------------------\n") ;

	for(int j = 0 ; j<4 ; j++)
	{
		for(int i = 0 ; i<4 ; i++)
		{
			if(tab[(j*4)+i] != 0) printf("%d", tab[(j*4)+i]) ;
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
	int emplacements_vides[16] ;
	int acc = 0;
	for(int i = 0 ; i<16 ; i++)
	{
		if(tab[i] == 0)
		{
			emplacements_vides[acc] = i ;
			acc++ ;
		}
    	}
    	
    	int emplacement_du_2 = emplacements_vides[rand() % acc] ;
    	
    	if(rand() % 100 >= 75) tab[emplacement_du_2] = 4 ;
    	else tab[emplacement_du_2] = 2 ;
}

void turn_grid(int* grille)
{
    int temp_grid[16];
    for (int ind=0;ind<16;ind++)
    {
        temp_grid[ind] = grille[ind];
    }
    int ind_case = 0; 
	for (int i=12;i<16;i++) 
    {
        for (int j = i; j>=(i%4); j-=4)
        {
            grille[ind_case] = temp_grid[j];
            ind_case += 1;
        }
    }
}

void deplacement_droite(int* grille,int case1)
{    
  for (int i = 0; i < 4; i++)
	{
	  for (int indice = case1 + 3; indice > case1; indice--)
	    {
	      if (grille[indice] == 0 && grille[indice - 1] != 0)
            {
                grille[indice] = grille[indice-1];
                grille[indice] = 0;
            }
	    }
	}
}

void mouvement_vers_droite (int *grille)
{
  for (int case1 = 0; case1 < 16; case1 += 4)
    {
    //deplacement des tuiles non fusionnées
    deplacement_droite(grille, case1);
    //fusion des tuiles de la ligne
      for (int ind=case1+3;ind>case1;ind--)
      {
        if (grille[ind]==grille[ind-1])
        {
            grille[ind-1] = 2 * grille[ind];
            grille[ind] = 0;
        }  
      }
    //deplacement des tuiles fusionnées
    deplacement_droite(grille, case1);
    }
}

void mouvement(int* grille,int id_mouvement) //id = 0:droite; 1:haut; 2:gauche; 3:bas
{
  for (int i=0;i<id_mouvement;i++)//tourne la grille pour orienter vers la droite la direction du mouvement
  {
    turn_grid(grille);
  }
  mouvement_vers_droite(grille);//effectue le mouvement vers la droite
  for (int i=0;i<4-id_mouvement;i++)//remet la grille dans la bonne orientation
  {
    turn_grid(grille);
  }
}