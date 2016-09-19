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
* @file richard.c
* @author H4Y3
* @version 1.0
* @date 22 Mai 2013
* @brief Définit les fonctions relatives à Richard
*/


/**
* @fn void main_fight(personage *p,personage pirate[],int nbre)
* @details Les actions relatives au fight
* @param p Un pointeur sur la structure personnage
* @param nbre Liste de pirates
* @return void */
void main_fight(personage *p,personage pirate[],int nbre)
{
int i;
	for(i=0;i<nbre;i++)
	{
		if(pirate[i].is_alive==1)
		{
			if (key[KEY_ENTER]&& Collision((*p),pirate[i])!=0)
			{
				fight(p,&pirate[i]);
				if(!(pirate[i].is_alive))
				{
					set_score(p);
				}
			}
		}
	}
}

/**
* @fn int main_move(int *x , char *d , int w)
* @details Les actions relatives au deplacement
* @param x Cordonnée X du personnage Principal
* @param d Etat de deplacement du personnage Principal
* @param w Width
* @return La coordonné & l'etat de deplacement  */
int main_move(int *x , char *d , int w)
{
	int test=0;
	if (key[KEY_Q]&& (*x)!=0)
	{
		(*x)--;
		(*d)='g';
	}

	if (key [KEY_D] && (*x)!=ECRAN_X-w)
	{
		(*x)++;
		(*d)='d';
	}

	if (key [KEY_D] && (*x)==ECRAN_X-w)
	{
		test=1;
	}

	return test;
}
/*
* @fn void get_main_path(personage p,char str[])
* @details Renvoie le chemin du personnage a charger selon la position et l'etat
* @param p Structure personnage
* @param str Adresse de l'element a charger
* @return void */
void get_main_path(personage p,char str[])
{
	sprintf(str,"../graphs/%cf%d.bmp",p.direction,p.is_fighting);
}

/**
* @fn void reset_main(personage *p)
* @details Re-initialisation du jeu
* @param p Pointeur sur la structure personnage
* @param test Variable pour verifier le passage du stage
* @return void */
void reset_main(personage *p,int test)
{	
	if(test==1)
	p->stat.HP=p->stat.HP_MAX;
	p->X=0;
	p->is_fighting=0;
	p->direction='d';
}

