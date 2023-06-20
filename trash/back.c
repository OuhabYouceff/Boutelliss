#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"


//--------------------------------------------Initialisation du joueur type 1--------------------------------------------

/*
void initPlayer(Image *A)
{

	A->img = IMG_Load("link.png");
		if (A->img==NULL)
			{
				return;
			}
	A->pos1.x=0;
	A->pos1.y=0;	
	A->pos1.w=0;
	A->pos1.h=0;
	
	A->pos2.x=0;
	A->pos2.y=0;	
	A->pos2.w=0;
	A->pos2.h=0;
}
*/

//--------------------------------------------Initialisation du joueur type 2--------------------------------------------


void initialiser_Perso(perso * p){



p->image=IMG_Load("player/sheet.png");

Uint32 color=SDL_MapRGB(p->image->format, 255, 255, 255);
SDL_SetColorKey(p->image, SDL_SRCCOLORKEY,color);

p->position.x=POS_X_PERSO;
p->position.y=POS_Y_PERSO;

p->frame.w=W_PERSO;
p->frame.h=H_PERSO;
p->frame.x=POS_X_WALK_DROITE;
p->frame.y=POS_Y_WALK_DROITE;

p->curframe=0;
p->running=1;
p->direction=0;
p->previousmvt=0;

p->v_x =4;
p->v_grav = 0.3;
p->v_saut = -6.5;
p->v_y = p->v_saut;

p->acceleration=0.5;
p->vitesse=0;
p->decelere=-0.5;

}


//--------------------------------------------Affichage du perso--------------------------------------------
void afficherPerso (perso * p,SDL_Surface *screen)
{
	SDL_BlitSurface(p->image,&p->frame,screen,&p->position);     
}
int deplacer_perso(perso *p ,SDL_Surface* screen,SDL_Event ev,Image *b)
{  

int bordery=570;

  /*if(p->direction != p->previousmvt)
	{
		p->direction=0; 
		p->previousmvt = p->direction;
	}*/
	
switch(ev.type)
{

case SDL_KEYDOWN:
 {
	switch (ev.key.keysym.sym)
 {
	
   	case SDLK_d:
   		p->position.x+=p->vitesse;
   		p->direction=1;
  		break;
   	case SDLK_a:
   		p->position.x-=p->vitesse;
   		p->direction=2;
   		break;
 	case SDLK_w:
  		 p->position.y-=p->vitesse;
   		 p->direction=3;
   		break;
        case SDLK_s:
   		p->position.y+=p->vitesse;
   		p->direction=4;
   		break;
	
   	case SDLK_UP:
       	SDL_Delay(35);
       
        	 p->vitesse+=p->acceleration;
         	 p->position.x+=p->vitesse;
         	 p->direction=1;
         
         if(p->vitesse>=15)
         {
           	 p->vitesse=15;
         }
        break;
         
              case SDLK_DOWN:
               
                p->vitesse=0;  
               
                break;
 
}

}

}



if (p->position.x + 65 >= 1027)
{
	p->position.x = 1027-65;
}

 if (back->pos1.x-10275<=0)
 {
 back->pos1.x=10275;
 }
    else
    back->pos1.x-=2;  
else if (p->position.x+65>=1027)
{	
	bordery=1080;
}
       
else if (p->position.y + 95 >= 665)
{
	p->position.y = bordery;
}


}

//-----------------------------------------------------------animation des deplacements---------------------------------------


//----------------------------------------------------------saut------------------------------------------------------------

void saut(perso *p, SDL_Event ev,SDL_Surface* screen)
{

switch(ev.type)
{
case SDL_KEYDOWN:
 {
	switch (ev.key.keysym.sym)
	{
	case SDLK_SPACE:
	        p->position.y-=2;
	break;
        }
 }
}

if(p->position.y<250)
{
  	 p->position.x += p->v_x;
  	 p->position.y+= p->v_y;
   	 p->v_y += p->v_grav;
}
   
if (p->position.y> 250)
{
    	p->v_y = p->v_saut;

}

}



void animationperso(perso *p ,SDL_Surface* screen){



if(p->direction==1)
{
	p->frame.y=195.5;
	p->curframe++;
	SDL_Delay(40);
   
if(p->curframe>=5)
{

	p->curframe=0;
}
	p->frame.x=p->curframe * p->frame.w;  
 
}
else if(p->direction==2)
{ 
	p->frame.y=291.75;
	p->curframe++;
	SDL_Delay(40);

if(p->curframe>=5)
{
        p->curframe=0;
}

	p->frame.x=p->curframe * p->frame.w;  
  
}
else if(p->direction==3)
{ 
	p->frame.y=0;
	p->curframe++;
	SDL_Delay(40);
    
    
if(p->curframe>=5)
{
	p->curframe=0;
}
	p->frame.x=p->curframe * p->frame.w;  

}

else if(p->direction==4)
{ 
	p->frame.y=97.25;
	p->curframe++;
	SDL_Delay(40);
   
if(p->curframe>=5)
{
        p->curframe=0;
}
	p->frame.x=p->curframe * p->frame.w;  
 
}

else if(p->direction==0)
{

	p->frame.x=0;

}

}
