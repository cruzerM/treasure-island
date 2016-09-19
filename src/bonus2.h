#ifndef INCLUDE_bonus_2
#define INCLUDE_bonus_2

/**
* @file bonus2.h
* @author H4Y3
* @version 3.0
* @date 25 Mai 2013
* @brief Le fichier Header relatif au fichier bonus2.c (bonus 2)
*/

/**
*@brief Declaration des variables souris
*/
extern volatile int mouse_x; /*!< Abscisse de la souris */
extern volatile int mouse_y; /*!< Coordonnée de la souris */
extern volatile int mouse_b; /*!< Bouton cliqué */

/**
*@brief Declaration des Bitmaps nécessaire
*/

////////////////////////////////////////
BITMAP* t_logo; /*!< le logo Twitter */
BITMAP* r_logo; /*!< le logo Red Bull*/
BITMAP* c_logo; /*!< le logo CentOs*/
BITMAP* t_choix; /*!< les choix relatifs à Twitter*/
BITMAP* r_choix; /*!< les choix relatifs à Red Bull*/
BITMAP* c_choix; /*!< les choix relatifs à CentOs*/
BITMAP* tick; /*!< Bitmap tick (v)*/
BITMAP* x; /*!< Bitmap erreur (x)*/
BITMAP* curseur;  /*!< le curseur */
BITMAP* background2; /*!< le background */
////////////////////////////////////////
void load_bitmaps(BITMAP** t_logo, BITMAP** r_logo, BITMAP** c_logo, BITMAP** t_choix, BITMAP** r_choix, BITMAP** c_choix, BITMAP** tick, BITMAP** x, BITMAP** background2);
void destroy_bitmaps (BITMAP** t_logo, BITMAP** r_logo, BITMAP** c_logo, BITMAP** t_choix, BITMAP** r_choix, BITMAP** c_choix, BITMAP** tick, BITMAP** x, BITMAP** background2);
//void load_cursor(BITMAP** curseur);
//void destroy_cursor(BITMAP** curseur);
void main_fct (BITMAP* buffer, BITMAP* t_logo, BITMAP* r_logo, BITMAP* c_logo, BITMAP* t_choix, BITMAP* r_choix, BITMAP* c_choix, BITMAP* tick, BITMAP* x, BITMAP* background2);

#endif
