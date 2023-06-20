#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"


void start2(SDL_Surface *ecran)
{



ecran = SDL_SetVideoMode(600,300,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);//pour agrandir la fennetre si on click sur single/multi

Mix_Music *music;				//variables pour la musique 
Mix_Chunk *clickmusic;

 	    music = Mix_LoadMUS("sounds/plume.mp3");
	    Mix_PlayMusic(music,-1);
	    Mix_VolumeMusic(50);


int done=1 ;
int j=1;
char animm[100];
Image s,backg_animer[100];

SDL_Event event;
SDL_EnableKeyRepeat(200, 0);
SDL_Event e;


/*-------------------------------------------------score------------*/

int count=0,maxcount=0,score=0;
txt txt_scoree;
//init_txt_score(&txt_scoree,score);
/*-------------------------------------------------score------------*/


perso p;
//vie v;
Image v;

/*----------------------------------------initialisation de base--------------------------*/
//initmenus(&s);
initbackgroundanimer(&backg_animer[j],animm);
initialiser_Perso1(&p);
//initialiser_vie(&v);'
initvie(&v);


//boucle infinie!
while(done)
{

/*--------------------------------affichage du background animer--------------------------*/
if (j==63)
{
j=1;
}		
SDL_BlitSurface(backg_animer[j].img,NULL,ecran,&backg_animer[j].pos1);
j++;
SDL_Delay(50);



afficher(s,ecran);
afficher(v,ecran);
afficherPerso1(&p,ecran);
//afficher_vie (&v,ecran);

SDL_PollEvent(&event);

deplacer_perso1(&p,ecran,event);
saut1(&p,event,ecran);
animer_perso(&p,ecran);


 count=p.x;
      if(count-maxcount>=100)
         {
          //  score++;
           // init_txt_score(&txt_scoree,score);
           maxcount=count ;
            
         }
        // afficher_txt(txt_scoree,ecran);	
        
        

//changer_vie(&p,&v ,ecran); (il faut la fonction colision)

switch(event.type)
{	
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDL_QUIT:
done=0;
break;
case SDLK_ESCAPE:
{
done=0;
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

