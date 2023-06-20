#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>
#include"fonction.h"
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<math.h>
  
#define wicked 0.5
#define micked 0.05

typedef struct ennemi{
SDL_Surface *sprite; 
int  direction;
int time,nbr;
SDL_Rect posscreen;
SDL_Rect possprite;
SDL_Rect pos1,pos2;
}ennemi;
typedef struct ennemi ennemi;

typedef struct coin{
SDL_Surface *sprite; 
int  direction;
int time,nbr;
SDL_Rect posscreen;
SDL_Rect possprite;
SDL_Rect pos1,pos2;
}coin;
typedef struct coin coin;

void initennemi(ennemi *e);
void afficherennemi(ennemi *e,SDL_Surface *screen);
void liberer(ennemi *a);
void animer(ennemi *e);
void deplace(ennemi *e);
void deplacement(ennemi *e);
void initcoin(coin *e);
void affichercoin(coin *e,SDL_Surface *screen);
void animerc(coin *e);
void deplacementcoin(coin *c);
int collision_enemy_perso(SDL_Rect perso, ennemi e);
void deplacerIA( ennemi * e, SDL_Rect posperso );
#endif // MENU_H_INCLUDED
