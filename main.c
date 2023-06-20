#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"


SDL_Surface *ecran;


int main(void)
{int resultat;
initeverything();
resultat=enigmee(ecran);
printf("RESULTAT= %d \n ",resultat);
return 0;
}


void initeverything()
{
SDL_Init(SDL_INIT_EVERYTHING);
SDL_WM_SetIcon(IMG_Load("icone.png") , NULL);
ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
SDL_WM_SetCaption("khalil",NULL);

} 

