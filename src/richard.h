/**
* @file richard.h
* @author H4Y3
* @version 2.0
* @date 22 Mai 2013
* @brief Le fichier Header relatif au fichier richard.c
*/

int main_move(int *x , char *d , int w); //x: abscisse rich d: direction rich w: width rich
void main_fight(personage *p,personage pirate[],int nbre); //pirate: tableau de pirates nbre:taille de pirate
void reset_main(personage *p,int test); //test: test sur health (reinitialisation selon stage)
void get_main_path(personage p,char str[]);// *richard*
