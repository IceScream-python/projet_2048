#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int victoire(int* tab)
{
    for(int i = 0 ; i<16 ; i++)
    {
        if(tab[i] >= 2048) return 0 ;
    }
    
    return 1 ;
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

void init_grille (int *grille)
{
  int case1 = 0;
  int case2 = 1;
  for (int indice = 0; indice < 16; indice++)
    {
      if (indice == case1 || indice == case2)
	{
	  int nombre = rand () % 4;
	  if (nombre <= 4)
	    {
	      nombre = 2;
	    }
	  grille[indice] = nombre;
	}
      else
	{
	  grille[indice] = 2;
	}
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

void fusion (int *grille, int indice1, int indice2)
{
    grille[indice1] = 2 * grille[indice1];
    grille[indice2] = 0;
}

void echange (int *grille, int indice1, int indice2)
{
    //met la valeur de l'indice2 dans indice1 puis met 0 C  indice2
    grille[indice1] = grille[indice2];
    grille[indice2] = 0;
}

int mouvement_vers_droite (int *grille)
{
	int mouvement_effectue = 0;
	for (int case1 = 0; case1 < 16; case1 += 4)
    {
    	//fusion des tuiles de la ligne
    	for (int indice = case1 + 3; indice > case1; indice--)
		{
	  		if (grille[indice] == grille[indice - 1] && grille[indice] != 0)
	    	{
	      		fusion (grille, indice, indice - 1);
	      		mouvement_effectue += 1;
	    	}
		}
      	//deplacement des tuiles fusionnC)es
      	for (int i = 0; i < 4; i++)
		{
	  		for (int indice = case1 + 3; indice > case1; indice--)
	    	{
	      		if (grille[indice] == 0 && grille[indice - 1] != 0)
				{
		  			echange (grille, indice, indice - 1);
		  			mouvement_effectue += 1;
				}
	    	}
		}
	}

    return mouvement_effectue;
}

int mouvement_vers_gauche(int *grille)
{
	int mouvement_effectue = 0;
	for (int case1 = 3; case1 < 17; case1 += 4)
	{
		//fusion des tuiles de la ligne
		for (int indice = case1 - 3; indice < case1; indice++)
		{
			if (grille[indice] == grille[indice + 1] && grille[indice] != 0)
			{
				fusion(grille, indice, indice + 1);
				mouvement_effectue += 1;
			}
		}

		for (int i = 0; i < 4; i++)	//deplacement des tuiles fusionnees
		{
			for (int indice = case1 - 3; indice < case1; indice++)
			{
				if (grille[indice] == 0 && grille[indice + 1] != 0)
				{
					echange(grille, indice, indice + 1);
					mouvement_effectue += 1;
				}
			}
		}
	}

	return mouvement_effectue;
}

int mouvement_vers_haut(int *grille)
{
	int mouvement_effectue = 0;
	for (int case1 = 12; case1 < 16; case1++)
	{
		//fusion des tuiles de la ligne
		for (int indice = case1 % 4; indice < case1; indice += 4)
		{
			if (grille[indice] == grille[indice + 4] && grille[indice] != 0)
			{
				fusion(grille, indice, indice + 4);
				mouvement_effectue += 1;
			}
		}

		for (int i = 0; i < 4; i++)	//deplacement des tuiles fusionnees
		{
			for (int indice = case1 % 4; indice < case1; indice += 4)
			{
				if (grille[indice] == 0 && grille[indice + 4] != 0)
				{
					echange(grille, indice, indice + 4);
					mouvement_effectue += 1;
				}
			}
		}
	}

	return mouvement_effectue;
}

int mouvement_vers_bas(int *grille)
{
	int mouvement_effectue = 0;
	for (int case1 = 0; case1 < 4; case1++)
	{
		//fusion des tuiles de la ligne
		for (int indice = case1; indice < 12; indice += 4)
		{
			if (grille[indice] == grille[indice + 4] && grille[indice] != 0)
			{
				fusion(grille, indice, indice + 4);
				mouvement_effectue += 1;
			}
		}

		for (int i = 0; i < 4; i++)	//deplacement des tuiles fusionnees
		{
			for (int indice = 12 + case1; indice > case1; indice -= 4)
			{
				if (grille[indice] == 0 && grille[indice - 4] != 0)
				{
					echange(grille, indice, indice - 4);
					mouvement_effectue += 1;
				}
			}
		}
	}

	return mouvement_effectue;
}