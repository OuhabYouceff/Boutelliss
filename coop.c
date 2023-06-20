#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"


void start1(SDL_Surface *ecran)
{


ecran = SDL_SetVideoMode(1920,1080,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);//pour agrandir la fennetre si on click sur single/multi

Mix_Music *music;				//variables pour la musique 
Mix_Chunk *clickmusic;

 music = Mix_LoadMUS("sounds/plume.mp3");
	    Mix_PlayMusic(music,-1);
	    Mix_VolumeMusic(50);
TTF_Init();
int done=1 ;


Image s;

SDL_Event event;
SDL_EnableKeyRepeat(200, 0);
SDL_Event e;

perso p,p1;
//vie v;

Image v;

initmenus(&s);
initialiser_Perso(&p);
initialiser_Perso2(&p1);
//initialiser_vie(&v);'
initvie(&v);
while(done)
{

afficher(s,ecran);
afficher(v,ecran);
afficherPerso(&p,ecran);
afficherPerso(&p1,ecran);
//afficher_vie (&v,ecran);

SDL_PollEvent(&event);

deplacer_perso(&p,ecran,event);
saut(&p,event,ecran);
animer_perso(&p,ecran);

deplacer_perso2(&p1,ecran,event);
saut(&p1,event,ecran);
animer_perso(&p1,ecran);
//changer_vie(&p,&v ,ecran);
switch(event.type)
{	
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDL_QUIT:
done=0;
break;
case SDLK_ESCAPE:
{done=0;
ecran = SDL_SetVideoMode(640,360,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);//pour remetre les parametres initiale de la fenetre

 music = Mix_LoadMUS("sounds/the-last-of-us-theme-song.mp3"); //remetre la musique du menu principale
	    Mix_PlayMusic(music,-1);
	    Mix_VolumeMusic(50);
break;
}                                              
}
}
SDL_Flip(ecran);

}
}

