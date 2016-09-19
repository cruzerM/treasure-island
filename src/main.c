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
* @file main.c
* @author H4Y3
* @version 2.0
* @date 22 Mai 2013
* @brief Fichier Main du jeu
*/

int main()
{

	//inializing allegro fonction and check
	if(ini_alleg()!=0) allegro_exit();// initialisation d'allegro

	//creation of bitmaps
	SAMPLE *sound;
	BITMAP *Buffer;
	BITMAP *Image;
	BITMAP *Background;
	BITMAP * help;
	BITMAP *credits;
	//creation of Buffer bitmap
	Buffer = create_bitmap(ECRAN_X, ECRAN_Y);

	//check over the succesful creation of the buffer
	if (!Buffer)
	{
		set_gfx_mode(GFX_TEXT,0,0,0,0);
		allegro_message("erreur");
		allegro_exit();
		exit(EXIT_FAILURE);
	}

	//loading initial bitmaps
	Background = load_bitmap("../graphs/0.bmp", NULL);
	Image = load_bitmap("../graphs/df0.bmp", NULL);
	load_cursor(&curseur);
	load_Rebecca(&R);
	load_plaques( &background, &plaque_s, & plaque_mb, &plaque_p, &plaque_6_v);
	load_bitmaps( &t_logo, &r_logo, &c_logo, &t_choix, &r_choix, &c_choix, &tick, &x, &background2);
	//help = load_bitmap("./help.bmp", NULL);
	//credits = load_bitmap("./credits.bmp", NULL);
	sound = load_sample("../sound.wav");

	//check over the succesful loading of the images
	if (Image == NULL && Background == NULL)
	{
		allegro_message("could not load images");
		allegro_exit();
	}

	//creatiing a list for the AIs and a temporary list
	personage pirate[5];
	int nbre=0;

	//creating main character
	personage Per;

	//initialising main character
	ini_main(&Per,Image->h,Image->w);

	//intialising array holding nber of AIs/sequence
	int T[LEVEL_MAX][SEQUENCE_MAX]={{1,1,2,2,3},{1,2,2,3,1},{2,2,3,3,4},{3,3,4,4,1}};

	// limitation of the zone of free roaming of the AIs
	int xmax=ECRAN_X;
	int xmin=250;

	//level and sequence control
	int level=(0);
	int sequence=(-1);

	//variables to hold lv changes
	int new_lvl=0;
	int new_seq=0;

	//variables for boss and mobs str modifiers
	int str_mod=0;
	int boss_str=5;

	//counter , andvancement and exit variables
	int i=0, test=0,done=0, cine=0;
	//colors
	int black = makecol(0,0,0);
	int grey = makecol(128,128,128);
	int colorHP;

	//percentage health
	int perc;

	//images path
	char path[20];

	int counter=0;

	done=menu (Buffer,Image);
	if (done==0)
	{cine=cinematique(Buffer, Image);}
	//while level didnt exceed the max game lvls and the user didnt hit the quit key the game run
	while(new_lvl!=LEVEL_MAX && !done && cine)
	{
		//play_sample(sound, 255, 128, 1000, 0);
		//if the lvl/sequence changed during the last itiniration make the appropriate changes
		if(new_lvl!=level || new_seq!=sequence)
		{
			//change background if level change
			if (level!=new_lvl)
			{
				clear_bitmap(Buffer);
				if(new_lvl==2)
				{
					init_Rebecca(&R);
					main_fct1( Buffer, background, plaque_s, plaque_mb, plaque_p, plaque_6_v, curseur, &R);

				}
				if(new_lvl==4)
				{


					text_mode(-1);
					main_fct (Buffer, t_logo, r_logo, c_logo, t_choix, r_choix, c_choix, tick, x, background2);
				}
				sprintf(path,"../graphs/%d.bmp",new_lvl);
				Background = load_bitmap(path, NULL);
				//reset the main coordonates and health
				reset_main(&Per,1);
				str_mod++;
			}else
			{
				//reset the main coordonates only
				reset_main(&Per,0);
			}
				level=new_lvl;
				sequence=new_seq;
			if(level!=4)
			{
				nbre=T[level][sequence];
			}
			else
			{
				nbre=1;
			}
				//add new pirates to the list according the array
				if(sequence==4 && (level==1||level==3))
				{
					ini_pirate(&pirate[0],boss_str,3);

				}
				else if(level==4)
				{
					ini_pirate(&pirate[0],boss_str,4);

				}
				else
				{
					for(i=0;i<nbre;i++)
					{
						ini_pirate(&pirate[i],str_mod,-1);
					}
				}
			}

		//move each AI in the list
		for(i=0;i<nbre;i++)

		{
			if(pirate[i].is_alive==1)
			{
			//check if the player entred the interaction zone
			pirate[i].agg=aggro(Per,pirate[i]);

				//if not move it freely
				if(!pirate[i].agg)
				{

					random_move(&pirate[i],xmin,xmax);
				}
				else
				{
					//test the collision
					pirate[i].coll=Collision(Per,pirate[i]);

					//if there is not collision move the AI thoward the player
					if (!pirate[i].coll)
					{
						move_to_main(&pirate[i], Per);
					}

					//if there is start the fight
					else
					{
						fight(&pirate[i],&Per);
					}
				}
			}
		}
		//displaying
		//clear the buffer from the previous iteniration
		clear_bitmap(Buffer);

		//drawing the backgroung on the buffer
		blit(Background, Buffer, 0, 0, 0, 0, Background->w, Background->h);

		//drawing the player if he he is still alive
		if(Per.is_alive==1)
		{
			//get the image path
			get_main_path(Per,path);
			Image = load_bitmap(path, NULL);

			//auto increment fighting state
			if(Per.is_fighting>0)
				Per.is_fighting++;
			if(Per.is_fighting>2)
				Per.is_fighting=0;

			//draw the image
			draw_sprite(Buffer, Image,Per.X,Per.Y );

			//draw the health bar
			perc=(Per.stat.HP*100/Per.stat.HP_MAX)/1;
			if (perc<0)
				perc=0;

			colorHP=get_colorHP(perc);

			rect(Buffer,14, 14, 416,31 ,black);
			rectfill(Buffer,15, 15, 415,30 ,grey);
			rectfill(Buffer,15, 15, 15+perc*4,30 ,colorHP);
		}
		//if he is dead terminate the game
		else
		{
			BITMAP *test;
			test=load_bitmap("../graphs/perdu.bmp", NULL);
			draw_sprite(Buffer, test,0,0);
			done=1;
		}

		if(level==4 && pirate[0].is_alive==0)
			{
			BITMAP *test;
			test=load_bitmap("../graphs/winner.bmp", NULL);
			draw_sprite(Buffer, test,0,0);
			done=1;
			}

		//draw each AI
		for(i=0;i<nbre;i++)
		{
			if(pirate[i].is_alive==1)
			{
				//get the image path
				get_path(pirate[i],path);
				//load the AI image
				Image = load_bitmap(path, NULL);

				//auto increment fighting state
				if(pirate[i].is_fighting>0)
				pirate[i].is_fighting++;
				if(pirate[i].is_fighting>2)
				pirate[i].is_fighting=0;

				//draw the image and the health bar on the buffer
				draw_sprite(Buffer, Image,pirate[i].X,pirate[i].Y);

				//draw the health bar
				perc=(pirate[i].stat.HP*100/pirate[i].stat.HP_MAX)/1;
				if (perc<0)
					perc=0;

				colorHP=get_colorHP(perc);

				rect(Buffer,pirate[i].X-1, pirate[i].Y-16, pirate[i].X+pirate[i].W+1,pirate[i].Y-4 ,black);
				rectfill(Buffer,pirate[i].X, pirate[i].Y-15, pirate[i].X+pirate[i].W,pirate[i].Y-5 ,grey);
				rectfill(Buffer,pirate[i].X, pirate[i].Y-15, pirate[i].X+perc,pirate[i].Y-5 ,colorHP);
			}

		}
		textprintf(Buffer, font, 450, 20, makecol(255,0,0), "YOUR SCORE IS ** %i **",Per.stat.SCORE);
		//draw the buffer on the screen
		blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);


		//listen for movement input
		test=main_move(&Per.X, &Per.direction ,Per.W);

		//listen for fight input
		main_fight(&Per, pirate,nbre);
		for(i=0;i<nbre;i++){
			if(pirate[i].is_alive==1)
			{
				test=0;
			}
		}
		//if all AIs are dead and player move past to right edge of the screen move on the next sequence/lvl
		if (test==1)
			increment(&new_lvl,&new_seq);

		//exit condition
		if(key[KEY_ESC])
			done=1;
	usleep(1000);
	if (done==1) {sleep(2);}
	}
	
	//destroy all bitmaps before quitiing
	destroy_bitmap(Image);
	destroy_bitmap(Background);
	destroy_bitmap(Buffer);
	destroy_cursor(&curseur);
	destroy_plaques( &background, &plaque_s, &plaque_mb, &plaque_p, &plaque_6_v);
	destroy_Rebecca(&R);
	destroy_bitmaps (&t_logo, &r_logo, &c_logo, &t_choix, &r_choix, &c_choix, &tick, &x, &background2);
	destroy_cursor(&curseur);
	return 0;
}
END_OF_MAIN();
