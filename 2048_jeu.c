#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonction.h"

int main()
{
	srand(time(NULL)) ;

	int *grille = (int *) malloc(sizeof(int)*16);
	init_grille(grille);

	rajoute_2(grille);
	rajoute_2(grille);

	affichage(grille) ;
	
	while (!victoire(grille))
	{
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
		else //si l'entrée n'est pas conforme 
		{
			continue;
		}
        rajoute_2(grille);
		affichage(grille) ;
	}
	printf("Partie Terminée\n");
	free(grille);
	return 0 ;
}