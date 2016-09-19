#ifndef INCLUDE_bonus_1bis
#define INCLUDE_bonus_1bis

#include <allegro.h>



#define p10 76
#define p11 234
#define p20 319
#define p22 477
#define p3 561
#define p33 719
#define y_up1 92
#define y_up2 217
#define y_down1 271
#define y_down2 396
//////////////////rebecca//////////////////////////


/**
* @file bonus1.h
* @author H4Y3
* @version 3.0
* @date 25 Mai 2013
* @brief Le fichier Header relatif au fichier bonus1.c (bonus 1)
*/

/**
*@brief La structure Rebecca
*@details Cette structure renferme l'ensemble des variables relatives à Rebecca
*/


typedef struct {
	BITMAP *img_bravo;  /*!< Image en cas de succès */
	BITMAP *img_erreur; /*!< Image en cas d'erreur */
	BITMAP *img_perdu; /*!< Image en cas d'échec */
        int x; /*!< Abscisse */
	int y; /*!< Coordonnée */
}Rebecca ;
///////////////////////////////////////////////////
/**
*@brief Declaration des variables souris
*/
extern volatile int mouse_x; /*!< Abscisse de la souris */
extern volatile int mouse_y; /*!< Coordonnée de la souris */
extern volatile int mouse_b; /*!< Bouton cliqué */
/////////////////////////////////////////////////////
/**
*@brief Declaration des Bitmaps nécessaire
*/
BITMAP* plaque_s;  /*!< la plaque Sparrow */
BITMAP* plaque_mb; /*!< la plaque du mini boss */
BITMAP* plaque_p;  /*!< la plaque du pirate */
BITMAP* plaque_6_v; /*!< bitmap presentant les 6 plaques vides */
//BITMAP* curseur;  /*!< le curseur */
BITMAP* background; /*!< le background */


Rebecca R;
/////////////////////////////////////////////////////



void load_plaques( BITMAP** background, BITMAP** plaque_s, BITMAP** plaque_mb, BITMAP** plaque_p, BITMAP** plaque_6_v);  
void destroy_plaques(BITMAP** background, BITMAP** plaque_s, BITMAP** plaque_mb, BITMAP** plaque_p, BITMAP** plaque_6_v);
void load_cursor(BITMAP** curseur);
void destroy_cursor(BITMAP** curseur);
void main_fct1( BITMAP* buffer, BITMAP* background, BITMAP* plaque_s, BITMAP* plaque_mb, BITMAP* plaque_p, BITMAP* plaque_6_v, BITMAP* curseur, Rebecca *R);
/////////////////////////rebecca////////////////////////////////////
void load_Rebecca(Rebecca *R);
void destroy_Rebecca(Rebecca *R);
void init_Rebecca(Rebecca *R);
void draw_Rebecca_bonus (Rebecca *R,BITMAP *buffer, int indice);
////////////////////////////////////////////////////////////
#endif
