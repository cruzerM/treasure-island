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

/**
* @file menucine.c
* @author H4Y3
* @version 1.0
* @date 22 Mai 2013
* @brief Définit les fonctions de la cinematique et du menu
*/




/**
* @fn int menu (BITMAP *Buffer,BITMAP *image)
* @details Fonction menu
* @param Buffer Variable de type BITMAP ou on va afficher les images
* @param image Variable de type BITMAP qu'on va afficher
* @return La position du bouton */
int menu (BITMAP *Buffer,BITMAP *image)
{
int i=-1;
int done=0;
char path[10];

image=load_bitmap("../graphs/bleu.bmp",NULL);
blit(image, Buffer, 0, 0, 0, 0, image->w, image->h);

	while(!done)
	{
		blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		
		if (key[KEY_DOWN])
		{
			i++;
			if (i>3) 
				i=0;
			sprintf(path,"../graphs/m%d.bmp",i);
			image=load_bitmap(path,NULL);
			blit(image, Buffer, 0, 0, 0, 0, image->w, image->h);
		}

		if (key[KEY_UP])
		{
			i--;
			if (i<0)
				i=3;
			sprintf(path,"../graphs/m%d.bmp",i);
			image=load_bitmap(path,NULL);
			blit(image, Buffer, 0, 0, 0, 0, image->w, image->h);
		}

		//exit condition
		if(key[KEY_ESC])
		{
			done=1;
		}
		
		if(key[KEY_ENTER] && (i==0)) {done=1;}

		if(key[KEY_ENTER] && (i==3)) {return 1;}	

		if(key[KEY_ENTER] && i==1)
		{
			image=load_bitmap("../graphs/help.bmp",NULL);
			blit(image, Buffer, 0, 0, 0, 0, image->w, image->h);
		}

		if(key[KEY_ENTER] && i==2)
		{
			image=load_bitmap("../graphs/credits.bmp",NULL);
			blit(image, Buffer, 0, 0, 0, 0, image->w, image->h);
		}

		
		usleep(110000);
	}
	return i;
}


/**
* @fn int cinematique (BITMAP *Buffer, BITMAP *image)
* @details Fonction menu
* @param Buffer Variable de type BITMAP ou on va afficher les images
* @param image Variable de type BITMAP qu'on va afficher
* @return Fin de la cinematique */
int cinematique (BITMAP *Buffer, BITMAP *image)
{
int i=-1;
int fin=0;
char path[10];

image=load_bitmap("../graphs/c0.bmp",NULL);
blit(image, Buffer, 0, 0, 0, 0, image->w, image->h);

	while(!fin)
	{	
		text_mode(-1);
		textprintf(Buffer, font, 300, 570, makecol(255,0,0), "HOLD ** SPACE KEY TO SKIP **");
		blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		
		//if (key[KEY_RIGHT])
		//{
			i++;
			if (i>8) {i=0; fin=1;}
			sprintf(path,"../graphs/c%d.bmp",i);
			image=load_bitmap(path,NULL);
			blit(image, Buffer, 0, 0, 0, 0, image->w, image->h);
		//}


		//forced exit condition
		if(key[KEY_SPACE])
		{
			fin=1;
		}
		
		
		usleep(1000000);
	}
	return fin;
}
