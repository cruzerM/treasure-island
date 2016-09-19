#ifndef INCLUDE_fonction
#define INCLUDE_fonction


#define ECRAN_X	800
#define ECRAN_Y	600
#define AGG_ZONE 100
#define HIGHT 130
#define WIDTH 100
#define LEVEL_MAX 5
#define SEQUENCE_MAX 5
	
/**
* @file fonction.h
* @author H4Y3
* @version 2.0
* @date 22 Mai 2013
* @brief Le fichier Header relatif au fichier fonction.c
*/


/**
*@brief Les etats du jeu
*@details Cette structure renferme l'ensemble des variables qui determinent les etats initiaux
*/
	typedef struct 
	{
	int HP; /*!< Health */
	int HP_MAX; /*!< Health Max */
	int DPS_MAX; /*!< Maximum Damage dealt */
	int DPS_MIN; /*!< Minimum Damage dealt */
	int HC; /*!< Hit Chance */
	int SCORE; /*!< SCORE */
	}stats; /*!< Etats */

/**
*@brief Les parametres du personnage (Principal ou ennemi)
*@details Cette structure renferme l'ensemble des variables qui determinent parametres du personnage
*/
	typedef struct 
	{
	int X; /*!< Coordonnée X */
	int Y; /*!< Coordonnée Y */
	int W; /*!< Width */
	int H; /*!< Height */
	int coll; /*!< Etat de Collision */
	int agg; /*!< Espacement entre Richard & Ennemis */
	int px; /*!< Pas de Desplacement */
	int type; /*!< Type de personnage (Catégorie) */
	char direction; /*!< DIrection du personnage */
	int is_fighting; /*!< Verifie si un personnage est entrain de se battre ou non */
	int is_alive; /*!< En vie / Mort */
	stats stat; /*!< Integration de la structure d'états */
	}personage; /*!< Personnage */




int Collision(personage p1,personage p2);
int aggro(personage p1, personage p2);
void fight(personage *agg, personage *vic); //agg: agressor vic:victim
void get_path(personage p,char str[]); // str:taswira *pirate*

void increment(int *lvl,int *seq); //changement de level & seq
void random_move(personage *p, int xmin, int xmax); //xmin ---> xmax = champ
void move_to_main(personage *p, personage m); //deplacement pirates vers richard
int get_colorHP(int perc); //barre de vie selon HP perc:% health
void set_score(personage *p); //score


#endif
