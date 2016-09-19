#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "fonction.h"
#include "menucine.h"
#include "init.h"
#include "richard.h"
#include "bonus1.h"
#include "bonus2.h"


/////
void destroy_plaques(BITMAP** background, BITMAP** plaque_s, BITMAP** plaque_mb, BITMAP** plaque_p, BITMAP** plaque_6_v)
{
destroy_bitmap(*background) ;
destroy_bitmap(*plaque_s) ;
destroy_bitmap(*plaque_mb) ;
destroy_bitmap(*plaque_p) ;
destroy_bitmap(*plaque_6_v) ;
}
/////////

//////////////

void load_plaques( BITMAP** background, BITMAP** plaque_s, BITMAP** plaque_mb, BITMAP** plaque_p, BITMAP** plaque_6_v)
{
*background = load_bitmap("../graphs/nuit.bmp", NULL) ;
*plaque_s = load_bitmap("../graphs/plaque_sparrow.bmp", NULL) ;
*plaque_mb = load_bitmap("../graphs/plaque_MB.bmp", NULL) ;
*plaque_p = load_bitmap("../graphs/plaque_pirate.bmp", NULL) ;
*plaque_6_v = load_bitmap("../graphs/6_plaques_vides.bmp", NULL) ;
if((!*plaque_6_v) || (!*plaque_s) || (!*plaque_mb) || (!*plaque_p))
{
set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
allegro_message("Erreur ! Impossible de lire le fichier image !");
}
}
////// curseur ///////
void destroy_cursor(BITMAP** curseur)
{
destroy_bitmap(*curseur);
}


void load_cursor(BITMAP** curseur)
{
*curseur = load_bitmap("../graphs/mouse.bmp", NULL) ;
if(!*curseur)
{
set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
allegro_message("Erreur ! Impossible de lire le fichier image !");
}
}



//////////////rebecca//////////////////////////////////////



void load_Rebecca(Rebecca *R)
{

	R->img_bravo=load_bitmap("../graphs/bravo.bmp", NULL);
	R->img_erreur=load_bitmap("../graphs/erreur.bmp", NULL);
        R->img_perdu=load_bitmap("../graphs/perdu.bmp", NULL);

	if ((R->img_bravo == NULL) || (R->img_erreur == NULL) || (R->img_perdu == NULL) )
        {
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("Unable to load image !\n%s\n", allegro_error);
		
	}	
	

}


void init_Rebecca(Rebecca *R)
{
	
	R->x =500 ;
	R->y =250 ;
}



// MODULE REBECCA BONUS //
void draw_Rebecca_bonus (Rebecca *R,BITMAP *buffer, int indice)
{
if (indice == 0)
{
	draw_sprite(buffer, R->img_bravo,R->x, R->y);
}
if (indice ==1)
{
	draw_sprite(buffer, R->img_erreur,R->x, R->y);
}
if(indice ==2)
{
	draw_sprite(buffer, R->img_perdu,R->x, R->y);
}

}



void destroy_Rebecca(Rebecca *R)
{
		destroy_bitmap(R->img_bravo);
		destroy_bitmap(R->img_erreur);
                destroy_bitmap(R->img_perdu);

}

void main_fct1( BITMAP* buffer, BITMAP* background, BITMAP* plaque_s, BITMAP* plaque_mb, BITMAP* plaque_p, BITMAP* plaque_6_v, BITMAP* curseur, Rebecca *R)
{
////////////////////////////////
int s_check_1=0,s_check_2=0, sparrow=0, c_s=0;
int mb_check_1=0, mb_check_2=0, mboss=0, c_mb=0;
int p_check_1=0, p_check_2=0, pirate=0, c_p=0;
int score=0, compteur ;
///////////////////////////////
set_mouse_range(0, 0, SCREEN_W-curseur->w,SCREEN_H-curseur->h);

while(!key[KEY_SPACE] )
{
//clear_bitmap(buffer) ;
draw_sprite(buffer, background, 0, 0);
draw_sprite(buffer, plaque_6_v, p10, y_up1);
draw_sprite(buffer, curseur, mouse_x, mouse_y);
//sparrow 1
if (mouse_x < p11 && mouse_x > p10 && mouse_y < y_up2 && mouse_y > y_up1 && (mouse_b & 1))
{
	draw_sprite(buffer, plaque_s, p10, y_up1);
	s_check_1=1;c_s++;
}
//pirate 1
 else if (mouse_x < p22 && mouse_x > p20 && mouse_y < y_up2 && mouse_y > y_up1 && (mouse_b & 1))
{
	draw_sprite(buffer, plaque_p, p20, y_up1);
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
	p_check_1=1;c_p++;

}
//mb 1
 else if (mouse_x < p33 && mouse_x > p3 && mouse_y < y_up2 && mouse_y > y_up1 && (mouse_b & 1))
{
	draw_sprite(buffer, plaque_mb, p3, y_up1);
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
	mb_check_1=1;c_mb++;

}
//mb 2
else if (mouse_x < p11 && mouse_x > p10 && mouse_y < y_down2 && mouse_y > y_down1 && (mouse_b & 1))
{
	draw_sprite(buffer, plaque_mb, p10, y_down1);
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
	mb_check_2=1;c_mb++;
}
//pirate 2
 else if (mouse_x < p22 && mouse_x > p20 && mouse_y < y_down2 && mouse_y > y_down1 && (mouse_b & 1))
{
	draw_sprite(buffer, plaque_p, p20, y_down1);
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
	p_check_2=1;c_p++;

}
//sparrow 2
 else if (mouse_x < p33 && mouse_x > p3 && mouse_y < y_down2 && mouse_y > y_down1 && (mouse_b & 1))
{
	draw_sprite(buffer, plaque_s, p3, y_down1);
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
	s_check_2=1;c_s++;

}
//sparrow check
if ((s_check_1==1) && (s_check_2==1))
{
	draw_sprite(buffer, plaque_s, p10, y_up1);
	draw_sprite(buffer, plaque_s, p3, y_down1);
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
        sparrow=1;
}
// pirate check
if ((p_check_1==1) && (p_check_2==1))
{
	draw_sprite(buffer, plaque_p, p20, y_up1);
	draw_sprite(buffer, plaque_p, p20, y_down1);
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
	pirate=1;
}
//mb check
if ((mb_check_1==1) && (mb_check_2==1))
{
	draw_sprite(buffer, plaque_mb, p3, y_up1);
	draw_sprite(buffer, plaque_mb, p10, y_down1);
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
	mboss=1;
}


//final check
if ( sparrow == 1 && pirate == 1 && mboss == 1)
{

	score =  c_s + c_mb + c_p;
	textprintf(buffer, font, 100, 400, makecol(255,255,255 ), "FELICITATIONS VOTRE SCORE EST ** %i **",score);
	/////////////////////	
			compteur=0;
			draw_Rebecca_bonus(R,buffer,compteur);
			////////////////////		
	draw_sprite(buffer, curseur, mouse_x, mouse_y);
      
}

vsync();
text_mode(-1);
textprintf(buffer, font, 300, 550, makecol(255,255,255), "*** PRESS SPACE TO SKIP ***");
blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;

}

}
