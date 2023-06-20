#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"


void initText(Text *A) { 
A->position.x=70;     // initialisaation de la position du texte
A->position.y=50; 
//couleur blanche
A->textColor.r=255; 
A->textColor.g=255; 
A->textColor.b=255; 

A->font = TTF_OpenFont( "/home/youcef/Desktop/menuff/texte/ARCADECLASSIC.TTF", 100 ); }

void freeText(Text A) { 
SDL_FreeSurface(A.surfaceTexte); 
} 

void displayText(Text t,SDL_Surface *screen) {
t.surfaceTexte = TTF_RenderText_Solid(t.font, "test", t.textColor ); 
SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position); 
} 
