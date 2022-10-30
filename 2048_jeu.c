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
        scanf("%s", tmp) ;
        char touche = tmp[0] ;
        //mouvements : 0=droite; 1=haut; 2=gauche; 3=bas
        if(touche == 'z') mouvement(grille, 1) ;
        if(touche == 'q') mouvement(grille, 2) ;
        if(touche == 's') mouvement(grille, 3) ;
        if(touche == 'd') mouvement(grille, 0) ;
        rajoute_2(grille);
		affichage(grille) ;
	}
	free(grille);
	return 0 ;
}