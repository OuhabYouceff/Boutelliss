#ifndef Image_H
#define Image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct 
{
SDL_Rect position;
SDL_Rect frame;
SDL_Surface *image;
int curframe;
int direction; 	
int running;
int previousmvt;
double acceleration;
double decelere;
double vitesse;
double v_x;
double v_grav ;
double v_saut ;
double v_y ;		
}perso;



void initialisePerso(perso * p);
void afficherPerso (perso * p,SDL_Surface *screen);



#endif 
