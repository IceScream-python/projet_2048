/*Vérifie si la grille donnée comporte un 2048
 * Entrée : unn tableau d'entiers.
 * Sortie : 0 si la grille comporte un 2048, 1 sinon*/
int victoire(int* tab);

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

void fusion (int *grille, int indice1, int indice2);

void echange (int *grille, int indice1, int indice2);

int mouvement_vers_droite (int *grille);

int mouvement_vers_gauche(int *grille);

int mouvement_vers_haut(int *grille);

int mouvement_vers_bas(int *grille);
