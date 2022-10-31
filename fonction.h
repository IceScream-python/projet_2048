/*Vérifie si la grille donnée comporte un 2048 ou si plus aucun coup n'est possible
 * Entrée : un tableau d'entiers.
 * Sortie : 2 si la grille comporte un 2048, 0 si au moins un coup est possible sinon 1*/
int victoire(int* tab);

/* Vérifie si les deux grilles données en entrée contiennent les même éléments
* Entrée : deux tableaux d'entiers
* Sortie : true si les deux tableaux contiennent les même éléments, false sinon*/
bool sont_egaux(int* grille, int* grille2);

/*Compte le nombres de chiffres d'un nombre
 * Entrée : Un int
 * Sortie : un int donnant le nombre de chiffre de l'entrée*/ 
int taille_int(int nb);

/*Affiche n fois ' '*/
void n_espaces(int n);

/*Affiche le tableau de jeu
 * Entrée : un tableau (de 4*4)
 * Sortie : Void*/
void affichage(int* tab);

/*Initialise la grille avec des 0
 * Entrée : un tableau 
 * Sortie :void*/
void init_grille (int *grille);

/*Rajoute un 2 sur une case vide de la grille
 * Entrée : Un tableau
 * Sortie : void */
void rajoute_2(int* tab);

/* Effectue la fusion de deux tuiles (d'indice indice1 et indice2) de la grille
* Entrée : un tableau, deux entiers
* Sortie : un void*/
void fusion (int *grille, int indice1, int indice2);

/* déplace la tuile indice1 jusqu'à la tuile indice 2 (on suppose toutes les tuiles entre les 2 cases vides)
* Entrée : un tableau, deux entiers
* Sortie : un void*/
void echange (int *grille, int indice1, int indice2);

/*Renvoie la grille après avoir effectué une rotation dans le sens des aiguilles d'une montre
*Entrée : Un tableau
*Sortie : void */
void turn_grid(int* grille);

/*déplace toute les tuiles de la ligne començant par case1 vers la droite d'antant de cases que de cases vides présentes à leur droite.
*Entrée : Un tableau, un entier
*Sortie : void */
void deplacement_ligne_droite(int* grille,int case1);

/*fait le déplacement et la fusion de toutes les tuiles de la grille vers la droite
*Entrée : un tableau
*Sortie : un void*/
void deplacement_fusion_droite (int *grille);

/*tourne la grille jusqu'a ce que le coté vers lequel on veut faire le mouvement soit vers la droite,
appelle la fonction faisant le mouvement vers la droite puis remet la grille dans son orientation initiale.
*Entrée : un tableau, un entier
*Sortie : un void*/
void mouvement(int* grille,int id_mouvement);