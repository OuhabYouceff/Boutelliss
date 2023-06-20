#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"

void play(SDL_Surface *ecran,int *continuer)
{




int done=1;

int curseur=0,cursor=0;

int i=0;
ecran = SDL_SetVideoMode(711,400,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
Image menu,single,multi,single2,multi2;

SDL_Event event ;

Mix_Chunk *clickmusic;

/*--------------------------------------------------------------initialisation musique------------------------------------------------------*/
 clickmusic=Mix_LoadWAV("sounds/crack1.wav");

//--------------------------------------------------------------initialisation de base-------------------------------------------------------
initmenu2(&menu);
initsingle(&single);
initmulti(&multi);
initsingle2(&single2);
initmulti2(&multi2);

while(done)
{
//-----------------------------------------------------------------affichage de base-----------------------------------------------------------------
afficher(menu,ecran);
afficher(single,ecran);
afficher(multi,ecran);
while(SDL_PollEvent(&event))
{switch(event.type)
{

case SDL_QUIT:
done=0;			//pour quitter directement grace a la croix rouge sans revenir au menu principale
*continuer=0;
break;	
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_ESCAPE:
{done=0;	
	ecran = SDL_SetVideoMode(640,360,32,SDL_HWSURFACE| SDL_DOUBLEBUF);	//pour revenir au menu principale
break;
}

/*-------------------------------------utilisation du clavier pour naviguer sur le menu-------------------------------------*/    	
case SDLK_UP:	     		
	
	if (i==1)
		{
		 Mix_PlayChannel(1,clickmusic,0);
			i=2;
		}
	else
	        {
	         Mix_PlayChannel(1,clickmusic,0);
		        i--;
	        }
break;


case SDLK_DOWN:
	if(i==2)
              	{ 
              	Mix_PlayChannel(1,clickmusic,0);
              	i=1;
              	}
	else
               {
                 Mix_PlayChannel(1,clickmusic,0);
                 i++;
               
                }
break;

case SDLK_RETURN:
if(i==1)
{
Mix_PlayChannel(1,clickmusic,0);
//start2(ecran);
page1(ecran);
}
else if (i==2)
{
Mix_PlayChannel(1,clickmusic,0);
start1(ecran);
}
break;                                             
}

//----------------------------------------------------mousemostion------------------------------------------------------------------

case SDL_MOUSEMOTION:
{


				if((event.motion.x>301) && (event.motion.x<441) && (event.motion.y>133) && (event.motion.y<184))
						{
							cursor=1;
							curseur=1;
							i=0;
						}
				else if((event.motion.x>301) && (event.motion.x<441) && (event.motion.y>210) && (event.motion.y<261))
						{
						
						curseur=2;
						cursor=2;
						i=0;
						
						}		
				else 
						{
					cursor=0;
					curseur=0;
					
						}
}break;SDL_Flip(ecran);

//-----------------------------------------------------basculer vers jeu-------------------------------------------------------------------

case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
{
switch(curseur)
{
case 1:
Mix_PlayChannel(1,clickmusic,0);
start2(ecran);
break;
case 2:
Mix_PlayChannel(1,clickmusic,0);
start1(ecran);
break;
}

}
}
}
switch(cursor)
{
case 0:
//afficher(single,ecran);
//afficher(multi,ecran);
break;
case 1:
afficher(single2,ecran);
break ;
case 2:
afficher(multi2,ecran);
}

/*------------------------------------------------selection des bouttons graces aux variables intermediaires---------------*/

 if (i==1)
{
afficher(single2,ecran);

}
if (i==2)
{

afficher(multi2,ecran);

}

/*---------------------------------------------------kil aaada condition 5atfetli bzhar 5ater ken ybugui fi faza sghira------------------------*/
if (curseur==0)
{

Mix_PlayChannel(0,clickmusic,0);
}

SDL_Flip(ecran);

}
}
