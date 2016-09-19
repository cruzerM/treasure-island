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
* @fn void ini_main(personage *m, int h, int w)
* @details Les initialisations du jeu
* @param personnage Un pointeur sur la structure personnage
* @param w Width
* @param h Height
* @return void */
void ini_main(personage *m, int h, int w){
	m->W=w;
	m->H=h;
	m->X=0;
	m->Y=ECRAN_Y-h;
	m->coll=0;
	m->agg=0;
	m->px=0;
	m->direction='d';
	m->type=0;
	m->is_fighting=0;
	m->is_alive=1;
	m->stat.HP_MAX=10000;
	m->stat.HP=10000;
	m->stat.DPS_MIN=20;
	m->stat.DPS_MAX=100;
	m->stat.HC=70;
	m->stat.SCORE=0;
}
/**
* @fn void ini_pirate(personage *p, int id1)
* @details Les initialisations du pirates (positions & stats)
* @param personnage Un pointeur sur la structure personnage
* @param id1 Identifiant
* @return void */
void ini_pirate(personage *p, int str, int typ){
	p->W=WIDTH;
	p->H=HIGHT;
	p->X=(rand() % 350)+250;
	p->Y=ECRAN_Y-HIGHT;
	p->coll=0;
	p->agg=0;
	p->px=1;
	p->direction='d';
	if(typ==-1)
	{
	p->type=(rand() % 2)+1;
	}
	else{
	p->type=typ;
	}
	p->is_fighting=0;
	p->is_alive=1;
	p->stat.HP_MAX=1000+200*str;
	p->stat.HP=1000+200*str;
	p->stat.DPS_MIN=5+2*str;
	p->stat.DPS_MAX=25+4*str;
	p->stat.HC=30+4*str;
	p->stat.SCORE=1000;
}
/**
* @fn int ini_alleg()
* @details Initialisation d'allegro
* @param Aucun
* @return int */
int ini_alleg(){

	// function d'initialisation d'allegro
	allegro_init();

	//chargement du clavier
	if (install_keyboard() == -1)
	{
		allegro_message("Error! %s", allegro_error);
		return -1;
	}

	srand(time(NULL));

	install_mouse() ;

	if (install_mouse () == -1)
	{
		allegro_message("Erreur ! %s", allegro_error) ;

		return -1 ;
	}


	//mattre les color en mode 16bits
	set_color_depth(16);
	
	//chargement du mode graphique
	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, ECRAN_X, ECRAN_Y, 0, 0) != 0)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0); 	//chargement for text mode 
		allegro_message("Unable to initialize video mode!\n%s\n", allegro_error);
		return -1;
	}
	if(install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL))
	 {
	allegro_message("Sound Error: %s", allegro_error);
	return -1; 
	}
	set_volume(255, 255);

	return 0;
}
