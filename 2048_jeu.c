#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonction.h"

int main()
{
	srand(time(NULL)) ;
	
	int* grille = (int*)malloc(sizeof(int)*16) ;
	for (int indice=0;indice<16;indice++)
	{
		grille[indice] = 0;
	}


	rajoute_2(grille); //La grille initiale comporte deux cases non vides.
	rajoute_2(grille);

	affichage(grille) ;
	int fini = victoire(grille);
	while (!fini) //victoire vaut 1 en cas de défaite et 2 en cas de victoire, donc !victoire vaut true tant que la partie est en cours.
	{
		//Pour vérifié si il y a eu un mouvement, on copie la grille dans une grille temporaire et on regarde si la grille temporaire est égale a la grille de jeu apres l'action. Si il n'y a pas eu de mouvement, on ne rajoutera pas de nouveau 2 sur la grille.
		int grille_tmp[16];
		for (int indice=0;indice<16;indice++)
		{
			grille_tmp[indice] = grille[indice];
		} 

		char tmp[256] ;
		printf("\nQuel coup voulez vous jouer?\nd=droite; z=haut; q=gauche; s=bas;e=quitter\n");
        scanf("%s", tmp) ;
        char touche = tmp[0] ;
        //mouvements : 0=droite; 1=haut; 2=gauche; 3=bas
        if(touche == 'z') 
		{
			mouvement(grille, 1);
		}
		else if(touche == 'q') 
		{
			mouvement(grille, 2);
		}
        else if(touche == 's') 
		{
			mouvement(grille, 3);
		}
        else if(touche == 'd')
		{
			mouvement(grille, 0);
		} 
		else if (touche == 'e')
		{
			break;
		}
		else
		{
			printf("Valeur donnée non valide\n");
			continue;
		}

		if (!sont_egaux(grille,grille_tmp)) //on n'ajoute un 2 que si un mouvement à été effectué donc que la grille à été modifiée.
		{
			rajoute_2(grille);
		}
		affichage(grille) ;
		fini = victoire(grille);
	}
	if(fini==2)
		printf("Victoire !\n");
	else
		printf("Game over\n");
	free(grille);
	return 0 ;
}
