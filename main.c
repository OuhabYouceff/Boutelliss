#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"

int main (int argc , char** argv)
{


/*--------------------------------------------------------------------------------------------------*/
SDL_Surface *screen=NULL;

//varibales
int continuer=3;
int collision=0;
SDL_Surface *bg=NULL;
SDL_Rect posbg;
SDL_Event event;

//position map
posbg.x=0;
posbg.y=0;

//variables
ennemi e;
coin c,c2;

/*---------------------------------init perso----------------------------*/
SDL_Surface *p=NULL;
p=IMG_Load("perso1.png");

SDL_Rect posp;

posp.x=0;
posp.y=400;
posp.w=41;
posp.h=70;

/*---------------------------------init perso-------------------------------------------------------*/


//some variables


SDL_Rect camera;

camera.h=100;
camera.w=250;
camera.x=0;
camera.y=154;


/*--------------------------------------------------------------------------------------------------*/
SDL_Init(SDL_INIT_VIDEO);
	
	screen = SDL_SetVideoMode(2000,512,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);
	
	SDL_WM_SetCaption("entite 2nd",NULL);

if(!screen)
{
 printf ("Unable to set video: %s\n" ,SDL_GetError());
 return 1;
}
/*--------------------------------------------------------------------------------------------------*/

//initialisations de base

bg=IMG_Load("big_map.png");
initennemi(&e);
initcoin(&c);


//boucle infinie !
while (continuer)
{
SDL_BlitSurface(bg,NULL,screen,&posbg);
SDL_BlitSurface(p,NULL,screen,&posp);
affichercoin(&c,screen);
afficherennemi(&e,screen);



SDL_PollEvent (&event);

animer(&e);
animerc(&c);
deplacement(&e);
deplacementcoin(&c);
deplacerIA(&e,posp);


collision=collision_enemy_perso(posp,e);
printf("%d\n",collision);

if (collision==1)
{ 

posp.x+=500;

}



 	
 
 
 switch(event.type)
{
	 case SDL_QUIT:
 		continuer=0;
 	 break;
 	 
 	

case SDL_KEYDOWN:
 
	switch (event.key.keysym.sym)
 {
	
   	case SDLK_RIGHT:
   		posp.x+=20;
   		
   		
  		break;
 	case SDLK_LEFT:
   		posp.x-=20;
   		
   		
  		break;
 	
}

}
SDL_Flip(screen);
}
liberer(&e); 
}
