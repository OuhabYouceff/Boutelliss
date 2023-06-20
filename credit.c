#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"

void creditt(SDL_Surface *ecran)
{
int done=1 ;
Image c;
SDL_Event event ;

while(done)
{
initmenuc(&c);
afficher(c,ecran);
while(SDL_PollEvent(&event))
{switch(event.type)
{	
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_ESCAPE:
{done=0;
break;
}                                              
}
}
SDL_Flip(ecran);
}
}
}
