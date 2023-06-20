#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"


int main (int argc , char** argv)
{

/*--------------------------------------------------------initialisation des variables----------------------------------------*/

SDL_Surface *screen=NULL;

int continuer=3,j=0,i=1,test=0,k=1,curseur=0,cursor=0,affiche=0,d,try=1;

SDL_Event event;

char animation[100],animations[100],anima[600];//pour l'animation du background check la fonction sprintf sur internet et dans le fichier image.c

//toutes les variables de type Image dans le fichier image.h

Image link,Sett,Start,Quit,Start2,Sett2,Quit2,menu,menu2,Menu[100],Menus[100],anim[600],s,barre,c[5],variable[5],credit,credit2,f,f2,b,t,sfx,vol;

//Text t;


Mix_Music *music;				//variables pour la musique 
Mix_Chunk *clickmusic;				

int commencer=0;    				//variable intermediaire pour activer l'animation avant menu
int commencer2;
int r=1;

//initialisation du text  xDDDD

TTF_Init();

int cont=0;					//variable pour passer le mode fenetrer plein ecran xD

int w=640; 
int h=360;	
	
/*------------------------------------------------------creation d'une fenetre---------------------------------------------*/

SDL_Init(SDL_INIT_VIDEO);
	
	SDL_WM_SetIcon(IMG_Load("image/icon.png"),NULL);
	
	screen = SDL_SetVideoMode(w,h,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);
	
	SDL_WM_SetCaption("BOUTELLISS",NULL);


//En cas d'erreur de l'initialisation de la fenetre 
if(!screen)
{
 printf ("Unable to set video: %s\n" ,SDL_GetError());
 return 1;
}


/*---------------------------------------------------Music Background-------------------------------------------------------*/

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	    {
	    printf("%s",Mix_GetError());
	    }

	    music = Mix_LoadMUS("sounds/the-last-of-us-theme-song.mp3");
	    Mix_PlayMusic(music,-1);
	    Mix_VolumeMusic(50);
	    clickmusic=Mix_LoadWAV("sounds/crack1.wav");
	  
 
/*-----------------------------------------------------initialisations-------------------------------------------------------*/

initanim(&anim[j],anima);
initmenu(&Menu[j],animation);
initmenus(&s);
initmenu2(&menu);
initStart(&Start);
initSett(&Sett);
initQuit(&Quit);
initStart2(&Start2);
initSett2(&Sett2);
initQuit2(&Quit2);
initcredit(&credit);
initcredit2(&credit2);
initb(&b);
initt(&t);
initsfx(&sfx);
initsfx(&vol);
//initText(&t);


//Boucle infinie !
while (continuer)
{	

//---------------------------------------------------animation avant menu principale---------------------------------------------



if (commencer==0)
{	
if (r==81)
{
commencer=1;
}


SDL_BlitSurface(anim[r].img,NULL,screen,&anim[r].pos1);
r++;
SDL_Delay(100);
 

}


//----------------------------------------------------------menu principale------------------------------------------------------		


//----------------------------------------------------------affichage animation du backg-----------------------------------------

else
 if (commencer==1)
{


if (k==83)
{
k=0;
}		
SDL_BlitSurface(Menu[k].img,NULL,screen,&Menu[k].pos1);
k++;
SDL_Delay(100);


//------------------------------------------------------------------------------------------------------------------------------
	
/*-------------------------------------affichage des bouttons + textes de decoration-----------------------------------------*/
	
afficher(Start,screen);
afficher(Sett,screen);
afficher(Quit,screen);
afficher(credit,screen);
afficher(b,screen);
afficher(t,screen);
//displaytext(t,screen);


/*----------------------------------------------------mouvement clavier + souris--------------------------------------------*/

while(SDL_PollEvent(&event))
{    
switch(event.type)
{
	
case SDL_KEYDOWN: 
                                                    
switch(event.key.keysym.sym)
{


case SDL_RESIZABLE:   //pour passer en mode fullscreen windowed
//commencer2=1;
afficher(menu,screen);

break;

case SDLK_ESCAPE:    //quit 
    continuer=0;
    	break;
    	
/*-------------------------------------utilisation du clavier pour naviguer sur le menu-------------------------------------*/    	
case SDLK_UP:	     		
	
	if (i==1)
		{
		 Mix_PlayChannel(1,clickmusic,0);
			i=3;
		}
	else
	        {
	         Mix_PlayChannel(1,clickmusic,0);
		        i--;
	        }
break;


case SDLK_DOWN:
	if(i==3)
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
//start(screen);
play(screen,&continuer);
}
else if (i==2)
{
Mix_PlayChannel(1,clickmusic,0);
option(screen);

}
else if(i==3)
{
Mix_PlayChannel(1,clickmusic,0);
continuer=0;
}
break;
}
break;


 /*---------------------------------------------------utilisation de la souris pour naviguer sur le menu----------------------------------*/
 
                           	case SDL_MOUSEMOTION:


				if((event.motion.x>70) && (event.motion.x<210) && (event.motion.y>72) && (event.motion.y<123))
						{

		// (i,curseur,cursor)variable intermediaire qui nous permet d'afficher les deuxiemes bouttons voir les dernieres lignes
						curseur=1; 
						cursor=1;
						i=0;
						
						}

				else if((event.motion.x>70) && (event.motion.x<210) && (event.motion.y>142) && (event.motion.y<193))
						{
						
						curseur=2;
						cursor=2;
						i=0;
						
						}

				else if ((event.motion.x>70) && (event.motion.x<210) && (event.motion.y>214) && (event.motion.y<265))
						{
						curseur=3;
						cursor=3;
						i=0;
						
						}
						
				else if ((event.motion.x>540) && (event.motion.x<630) && (event.motion.y>327) && (event.motion.y<347))
						{
						curseur=4;
						cursor=4;
						i=0;
						
						}
						else 
						{						
						curseur=0;
						cursor=0;
						
						}
						break;SDL_Flip(screen);
						
					case SDL_QUIT: //deuxieme methode pour quit (crois rouge fenetre)
					continuer=0;
					break;		
            			
            	
				case SDL_MOUSEBUTTONDOWN:
		
/*----------------------------------------------click souris sur un bouttons-----------------------------------*/
				
        	if (event.button.button == SDL_BUTTON_LEFT)
        	{
switch(curseur)
{
case 1:
Mix_PlayChannel(1,clickmusic,0);
//start(screen);
play(screen,&continuer);				//fonction qui nous permet de passer vers l'ecran game voir fichier start.c
break ;
case 2:
Mix_PlayChannel(1,clickmusic,0);
option(screen);			//fonction qui nous permet de passer vers l'ecran settings voir fichier settings.c
break ;
case 3:
Mix_PlayChannel(1,clickmusic,0);
continuer=0;				//quit
break ;
case 4:
creditt(screen);			//fonction qui nous permet de passer vers l'ecran credits voir fichier credits.c
break;                    
}
}
}

}

/*------------------------------------------------selection des bouttons graces aux variables intermediaires---------------*/

 if (i==1)
{
afficher(Start2,screen);

}
if (i==2)
{

afficher(Sett2,screen);

}
if  (i==3)
{

afficher(Quit2,screen);
}



  switch(cursor)
{
case 1:

afficher(Start2,screen);

break ;
case 2:

afficher(Sett2,screen);

break ;
case 3:
afficher(Quit2,screen);

break ;
case 4:
afficher(credit2,screen);

break;
}

/*---------------------------------------------------condition 5atfetli bzhar 5ater ken ybugui fi faza sghira------------------------*/

if (curseur==0)
{

Mix_PlayChannel(0,clickmusic,0);
}


}

SDL_Flip(screen);

}         

                       


/*--------------------------------------------------------Liberation de la memoire-----------------------------------------*/

	
	liberers(screen);
	liberer(menu);
	liberer(Start);
	liberer(Sett);
	liberer(Quit);
	liberer(Start2);
	liberer(Sett2);
	liberer(Quit2);
	libererm(Menu,82);
	//freeText(t);
	SDL_Quit();
	
	return 0;
	
}
