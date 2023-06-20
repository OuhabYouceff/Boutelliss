#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"

void option(SDL_Surface *ecran)

{

//-----------------------------------------------------initialisation de quelque variable----------------------------------------------


int done=1 ;

int j=1;

Image menu,Menus[100];
char animations[100];

SDL_Event event ;

Image c[5],variable[5],barre1,barre2,f,f2,v,v_1,v_2,v_3,v_4,v2,v2_1,v2_2,v2_3,v2_4,sfx,vol;


int cursor=0,curseur=0;
int i;

Mix_Music *music;
Mix_Chunk *clickmusic;

int volume=2;
int sound=2;
int en;
 //Music Background

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	    {
	    printf("%s",Mix_GetError());
	    }

	    music = Mix_LoadMUS("sounds/night.mp3");
	    Mix_PlayMusic(music,-1);
	    Mix_VolumeMusic(50);
	    clickmusic=Mix_LoadWAV("sounds/crack1.wav");


//--------------------------------------------------------------initialisation de base-------------------------------------------------------

//initmenu2(&menu);
initmenus2(&Menus[j],animations);
initf(&f);
initf2(&f2);
initv(&v);
initv_1(&v_1);
initv_2(&v_2);
initv_3(&v_3);
initv_4(&v_4);
initv2(&v2);
initv2_1(&v2_1);
initv2_2(&v2_2);
initv2_3(&v2_3);
initv2_4(&v2_4);
initvol(&vol);
initsfx(&sfx);

while(done)
{
//afficher(menu,ecran);

//--------------------------------------------------animation-----------------------------------------------------------------------

if (j==83)
{
j=1;
}
j++;		
SDL_BlitSurface(Menus[j].img,NULL,ecran,&Menus[j].pos1);
SDL_Delay(100);

//--------------------------------------------------affichage-----------------------------------------------------------------------

//afficher(f,ecran);
afficher(v,ecran);
afficher(v2,ecran);
afficher(vol,ecran);
afficher(sfx,ecran);


while(SDL_PollEvent(&event))
{
switch(event.type)
{	
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_ESCAPE:
done=0;
 music = Mix_LoadMUS("sounds/the-last-of-us-theme-song.mp3");
	    Mix_PlayMusic(music,-1);
	    Mix_VolumeMusic(en);
break;
case SDLK_UP:
volume+=1;
break;
case SDLK_DOWN:
volume-=1;
break;
case SDLK_RIGHT:
Mix_PlayChannel(1,clickmusic,0);
sound+=1;
break;
case SDLK_LEFT:
Mix_PlayChannel(1,clickmusic,0);
sound-=1;
break;
}break;

//----------------------------------------------------mousemostion------------------------------------------------------------------

case SDL_MOUSEMOTION:
{


				if((event.motion.x>203) && (event.motion.x<343) && (event.motion.y>240) && (event.motion.y<291))
						{
							cursor=1;
							curseur=1;
						}
				else 
						{
					cursor=0;
					curseur=0;
						}
}break;

//-----------------------------------------------------fullscreen-------------------------------------------------------------------

case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
{
switch(curseur)
{
case 1:
Mix_PlayChannel(1,clickmusic,0);
SDL_WM_ToggleFullScreen(ecran);
//ecran = SDL_SetVideoMode(640,360,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE |SDL_OPENGL | SDL_FULLSCREEN);
break ;
}			                                             
}

}
}
if(volume<0)
{
volume=0;
}
else if(volume>4)
{
volume=4;
}

if(sound<0)
{
sound=0;
}
else if(sound>4)
{
sound=4;
}

switch(cursor)
{
case 0:
afficher(f,ecran);
break;
case 1:
afficher(f2,ecran);
break ;
}


switch(volume)
{
case 0:
afficher(v_4,ecran);
Mix_VolumeMusic(0);
en=0;
break;
case 1:
afficher(v_3,ecran);
Mix_VolumeMusic(25);
en=25;
break;
case 2:
afficher(v,ecran);
Mix_VolumeMusic(50);
en=50;
break;
case 3:
afficher(v_1,ecran);
Mix_VolumeMusic(75);
en=75;
break;
case 4:
afficher(v_2,ecran);
Mix_VolumeMusic(100);
en=100;
break;
}

switch(sound)
{
case 0:
afficher(v2_4,ecran);
Mix_Volume(1,0);

break;
case 1:
afficher(v2_3,ecran);
Mix_Volume(1,25);

break;
case 2:
afficher(v2,ecran);
Mix_Volume(1,50);

break;
case 3:
afficher(v2_1,ecran);
Mix_Volume(1,75);

break;
case 4:
afficher(v2_2,ecran);
Mix_Volume(1,100);

break;
}
SDL_Flip(ecran);
}
}




		
