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
* @file fonction.c
* @author H4Y3
* @version 2.0
* @date 22 Mai 2013
* @brief Définit les fonctions d'interraction du jeu
*/


/**
* @fn void fight(personage *agg, personage *vic)
* @details Le principe du fight
* @param agg Un pointeur sur la structure personnage (Aggressor)
* @param vic Un pointeur sur la structure personnage (Victim)
* @return void */
void fight(personage *agg, personage *vic)
{
	int r = rand() % 100;

	if(agg->is_fighting==0)
	{
		if(r<=agg->stat.HC)
		{
			r = (rand() % (agg->stat.DPS_MAX - agg->stat.DPS_MIN))+agg->stat.DPS_MIN;
			vic->stat.HP=vic->stat.HP-r;
		}

		if(vic->stat.HP<=0)
		{
			vic->is_alive=0;
		}
		agg->is_fighting=1;
	}
}
/**
* @fn int Collision(personage p1, personage p2)
* @details Collision entre les deux personnages (Richard & Ennemis)
* @param
p1 pointeur sur la structure personnage
* @param p2 pointeur sur la structure personnage
* @return Soit 0 soit 1 */
int Collision(personage p1, personage p2)
{
	if((p2.X > p1.X + p1.W) || (p2.X + p2.W < p1.X)) //trop à droite ou trop à gauche
		return 0;
	else
		return 1;
}
/**
* @fn int aggro(personage p1, personage p2)
* @details Une fonction qui test l'espacement entre deux personnages
* @param p1 pointeur sur la structure personnage
* @param p2 pointeur sur la structure personnage
* @return SOit 0 soit 1 */
int aggro(personage p1, personage p2)
{
	if((p2.X > p1.X + p1.W+AGG_ZONE) || (p2.X + p2.W +AGG_ZONE< p1.X)) 
		return 0;
	else
		return 1;
}
/**
* @fn void get_path(personage p,char str[])
* @details Renvoie le chemin du personnage a charger selon la position et l'etat
* @param p Structure personnage
* @param str Adresse de l'element a charger
* @return void */
void get_path(personage p,char str[])
{
	sprintf(str,"../graphs/pirate%df%d%c.bmp",p.type,p.is_fighting,p.direction);
}

/**
* @fn void increment(int *lvl,int *seq)
* @details Incrementation du stage + sequence
* @param lvl Pointeur sur la variable Level
* @param seq Pointeur sur la variable Sequence
* @return void */
void increment(int *lvl,int *seq)
{
	if((*seq)<4 && (*lvl)!=4)
	{
		(*seq)++;
	}
	else
	{
		(*lvl)++;
		(*seq)=0;
	}
}
/**
* @fn void random_move(personage *p, int xmin, int xmax)
* @details Deplacement Aléatoire
* @param p Pointeur sur la structure Personnage
* @param xmin Coordonné X minimale
* @param xmax Coordonné X maximale
* @return void */
void random_move(personage *p, int xmin, int xmax)
{
	// add the step to the AI position
	p->X += p->px;  

	// if the pirate reached the limit of movement zone inverse the step
	if ( p->X < xmin) 
	{
		p->px=ABS(p->px);
		p->direction='d';
	}
	if (p->X + p->W > xmax)
	{
		p->px=-ABS(p->px);
		p->direction='g'; 
	}
}
/**
* @fn void move_to_main(personage *p,personage m)
* @details Deplacement d'ennemis vers Richard
* @param p Pointeur sur la structure Personnage (Pirate)
* @param m Pointeur sur la structure Personnage (Richard)
* @return void */
void move_to_main(personage *p,personage m)
{
	if(p->X > m.X + m.W)
	{
		(p->X)--;
		p->direction='g';
	}
	if(p->X + p->W < m.X)
	{
		(p->X)++;
		p->direction='d';
	}
}
/**
* @fn int get_colorHP(int perc)
* @details Colorier la barre de vie selon le pourcentage de vie
* @param perc Pourcentage de vie
* @return Couleur (Vert-Oranger-Rouge) */
int get_colorHP(int perc)
{
	if(perc>66)
	{
		return(makecol(0,255,0));
	}
	else if(perc>33)
	{
		return(makecol(255,128,0));
	}
	else
	{
		return(makecol(255,0,0));				
	}
}
/**
* @fn void set_score(personage *p)
* @details Calcul de score du joueur
* @param p Pointeur sur la Structure Personnage (En particulier, le champ "SCORE")
* @return Score */
void set_score(personage *p)
{
	p->stat.SCORE+=100;
}

