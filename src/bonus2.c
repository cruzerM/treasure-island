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

void load_bitmaps(BITMAP** t_logo, BITMAP** r_logo, BITMAP** c_logo, BITMAP** t_choix, BITMAP** r_choix, BITMAP** c_choix, BITMAP** tick, BITMAP** x, BITMAP** background2)
{
*t_logo = load_bitmap("../graphs/twitter_logo.bmp", NULL) ;
*r_logo = load_bitmap("../graphs/logo_redbull.bmp", NULL) ;
*c_logo = load_bitmap("../graphs/centos_logo.bmp", NULL) ;
*t_choix = load_bitmap("../graphs/plaque_Twit.bmp", NULL) ;
*r_choix = load_bitmap("../graphs/plaque_RB.bmp", NULL) ;
*c_choix = load_bitmap("../graphs/plaque_Cent.bmp", NULL) ;
*tick = load_bitmap("../graphs/TICK.bmp", NULL) ;
*x = load_bitmap("../graphs/X.bmp", NULL) ;
*background2 = load_bitmap("../graphs/jour.bmp", NULL) ;
if((!*t_logo) || (!*r_logo) || (!*c_logo) || (!*t_choix) || (!*r_choix) || (!*c_choix) || (!*tick) || (!*background2) || (!*x) )
{
set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
allegro_message("Erreur ! Impossible de lire les fichiers :image !");
}
}

void destroy_bitmaps (BITMAP** t_logo, BITMAP** r_logo, BITMAP** c_logo, BITMAP** t_choix, BITMAP** r_choix, BITMAP** c_choix, BITMAP** tick, BITMAP** x, BITMAP** background2)
{
destroy_bitmap(*t_logo) ;
destroy_bitmap(*r_logo) ;
destroy_bitmap(*c_logo) ;
destroy_bitmap(*t_choix) ;
destroy_bitmap(*r_choix) ;
destroy_bitmap(*c_choix) ;
destroy_bitmap(*tick) ;
destroy_bitmap(*x) ;
destroy_bitmap(*background2) ;
}


/*void destroy_cursor(BITMAP** curseur)
{
destroy_bitmap(*curseur);
}


void load_cursor(BITMAP** curseur)
{
*curseur = load_bitmap("../graphs/mouse.bmp", NULL) ;
if(!*curseur)
{
set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
allegro_message("Erreur ! Impossible de lire le curseur !");
}
}*/




void main_fct (BITMAP* buffer, BITMAP* t_logo, BITMAP* r_logo, BITMAP* c_logo, BITMAP* t_choix, BITMAP* r_choix, BITMAP* c_choix, BITMAP* tick, BITMAP* x, BITMAP* background)
{
int j_t=0, j_r=0, j_c=0;
set_mouse_range(0, 0, SCREEN_W-curseur->w,SCREEN_H-curseur->h);
while(!key[KEY_SPACE] )
{
//text_mode(-1);
//textprintf(buffer, font, 300, 300, makecol(255,255,255), "PRESS SPACE TO SKIP");	
clear_bitmap(buffer) ;
textprintf(buffer, font, 300, 550, makecol(255,0,255), "*** PRESS SPACE TO SKIP ***");
while(j_t!=1 && !key[KEY_SPACE])
{
clear_bitmap(buffer) ;
textprintf(buffer, font, 300, 550, makecol(255,0,255), "*** PRESS SPACE TO SKIP ***");
//draw_sprite(buffer, background, 0, 0);	
draw_sprite(buffer, t_logo, 38, 34);	
draw_sprite(buffer, t_choix, 489, 291);
draw_sprite(buffer, curseur, mouse_x, mouse_y);
//draw_sprite(buffer, curseur, 520, 152);
			if (mouse_x < 660 && mouse_x > 520 && mouse_y <374 && mouse_y >345 && (mouse_b & 1))
				{				
					draw_sprite(buffer, tick, mouse_x-20, mouse_y);	
					j_t=1;
					blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
					usleep(500000);
				}
			else if (mouse_b & 1)

				{
					draw_sprite(buffer, x, mouse_x-20, mouse_y);	
				}
blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
}


while(j_r!=1 && !key[KEY_SPACE])
{
clear_bitmap(buffer) ;
textprintf(buffer, font, 300, 550, makecol(255,0,255), "*** PRESS SPACE TO SKIP ***");
//draw_sprite(buffer, background, 0, 0);	
draw_sprite(buffer, r_logo, 38, 42);	
draw_sprite(buffer, r_choix, 489, 291);
draw_sprite(buffer, curseur, mouse_x, mouse_y);
//draw_sprite(buffer, curseur, 520, 152);
			if (mouse_x < 630 && mouse_x > 489 && mouse_y <404 && mouse_y >375 && (mouse_b & 1))
				{
					draw_sprite(buffer, tick, mouse_x-20, mouse_y);	
					j_r=1;
					blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
					usleep(500000);
				}
			else if (mouse_b & 1)

				{
					draw_sprite(buffer, x, mouse_x-20, mouse_y);	
				}
blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
}


while(j_c!=1 && !key[KEY_SPACE])
{
clear_bitmap(buffer) ;
textprintf(buffer, font, 300, 550, makecol(255,0,255), "*** PRESS SPACE TO SKIP ***");
//draw_sprite(buffer, background, 0, 0);	
draw_sprite(buffer, c_logo, 47, 14);	
draw_sprite(buffer, c_choix, 489, 291);
draw_sprite(buffer, curseur, mouse_x, mouse_y);
//draw_sprite(buffer, curseur, 520, 152);
			if (mouse_x < 644 && mouse_x > 506 && mouse_y <320 && mouse_y >291 && (mouse_b & 1))
				{
					draw_sprite(buffer, tick, mouse_x-20, mouse_y);	
					j_c=1;
					blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
					usleep(500000);
				}
			else if (mouse_b & 1)

							{
								draw_sprite(buffer, x, mouse_x-20, mouse_y);	
							}
blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
}
vsync();

blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
}



}
