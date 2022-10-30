#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonction.h"

int main()
{
	srand(time(NULL)) ;

	int grille[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
	
	rajoute_2(grille);
	rajoute_2(grille);

	affichage(grille) ;
	
	while(victoire(grille))
	{
		char tmp[256] ;
        scanf("%s", tmp) ;
        char touche = tmp[0] ;
        
        if(touche == 'z') mouvement_vers_haut(grille) ;
        if(touche == 'q') mouvement_vers_gauche(grille) ;
        if(touche == 's') mouvement_vers_bas(grille) ;
        if(touche == 'd') mouvement_vers_droite(grille) ;

        rajoute_2(grille);
		affichage(grille) ;
	}

	return 0 ;
}