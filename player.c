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

p->curframe=0;				//variable qui nous permet de savoir sur quelle frame nous nous trouvons
//p->running=1;				
p->direction=0;			//variable direction pour les differents etats spritesheet
p->previousmvt=0;			//variable intermediaire ou on sauvegarde la derniere direction 
	
p->v_x =4;				//vecteur qui nous permet davancer dans la fonction saut
p->v_grav = 0.3;			//vecteur qui nous permet de revenir a "y" initiale dans la fonction saut
p->v_saut = -6.5;			//vecteur qui nous permet de prendre de la hauteur dans la fonction saut
p->v_y = p->v_saut;			

p->acceleration=0.5;		
p->vitesse=0;			
p->decelere=-0.5;

}

void initialiser_Perso2(perso * p){



p->image=IMG_Load("player/sheet.png");

Uint32 color=SDL_MapRGB(p->image->format, 255, 255, 255);
SDL_SetColorKey(p->image, SDL_SRCCOLORKEY,color);

p->position.x=POS_X_PERSO2;
p->position.y=POS_Y_PERSO2;

p->frame.w=W_PERSO;
p->frame.h=H_PERSO;
p->frame.x=POS_X_WALK_DROITE;
p->frame.y=POS_Y_WALK_DROITE;

p->curframe=0;				//variable qui nous permet de savoir sur quelle frame nous nous trouvons
//p->running=1;				
p->direction=2;			//variable direction pour les differents etats spritesheet
p->previousmvt=0;			//variable intermediaire ou on sauvegarde la derniere direction 
	
p->v_x =4;				//vecteur qui nous permet davancer dans la fonction saut
p->v_grav = 0.3;			//vecteur qui nous permet de revenir a "y" initiale dans la fonction saut
p->v_saut = -6.5;			//vecteur qui nous permet de prendre de la hauteur dans la fonction saut
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

//--------------------------------------------Deplacement du perso------------------------------------------
int deplacer_perso(perso *p ,SDL_Surface* screen,SDL_Event ev)
{  

int bordery=570;		//variable bordure de la map

 if(p->direction !=0)
	{
		p->direction=0; 			//Pour reinitialiser le perso sans mouvement
		
	}
	
switch(ev.type)
{

case SDL_KEYDOWN:
 {
	switch (ev.key.keysym.sym)
 {
	
   	case SDLK_d:
   		p->position.x+=p->vitesse;
   		p->direction=1;
   		p->previousmvt=1;
   		
  		break;
   	case SDLK_a:
   		p->position.x-=p->vitesse;
   		p->direction=2;
   		p->previousmvt=2;
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
         	 //p->position.x+=p->vitesse;
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

//some borders of the map 

if (p->position.x + W_PERSO  >= 1060)
{
	p->position.x = 1060-W_PERSO;
}

 							
else if (p->position.x+W_PERSO >=1060)
{	
	bordery=1060;
}
       
else if (p->position.y + H_PERSO >= 665)
{
	p->position.y = bordery;
}


}

int deplacer_perso2(perso *p ,SDL_Surface* screen,SDL_Event ev)
{  

int bordery=570;		//variable bordure de la map

 if(p->direction !=0)
	{
		p->direction=0; 			//Pour reinitialiser le perso sans mouvement
		
	}
	
switch(ev.type)
{

case SDL_KEYDOWN:
 {
	switch (ev.key.keysym.sym)
 {
	
   	case SDLK_l:
   		p->position.x+=p->vitesse;
   		p->direction=1;
   		p->previousmvt=1;
   		
  		break;
   	case SDLK_j:
   		p->position.x-=p->vitesse;
   		p->direction=2;
   		p->previousmvt=2;
   		break;
 	case SDLK_i:
  		 p->position.y-=p->vitesse;
   		 p->direction=3;
   		break;
        case SDLK_k:
   		p->position.y+=p->vitesse;
   		p->direction=4;
   		break;
	
   	case SDLK_UP:
       	 SDL_Delay(35);
        	 p->vitesse+=p->acceleration;
         	 //p->position.x+=p->vitesse;
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

//some borders of the map 

if (p->position.x + W_PERSO  >= 1060)
{
	p->position.x = 1060-W_PERSO;
}

 							
else if (p->position.x+W_PERSO >=1060)
{	
	bordery=1060;
}
       
else if (p->position.y + H_PERSO >= 665)
{
	p->position.y = bordery;
}


}

//---------------------------------------------------------fonction acceleration-----------------------------------------

//xD Njamanech !





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
	        p->position.y-=10;
	break;
        }
 }
}

if((p->position.y<250))
{
	if (p->previousmvt==1)
	{
  	 p->position.x += p->v_x;
  	 p->position.y+= p->v_y;
   	 p->v_y += p->v_grav;
	}
	else
	{
  	 p->position.x -= p->v_x;
  	 p->position.y+= p->v_y;
   	 p->v_y += p->v_grav;
	}
}
   
if (p->position.y> 250)
{
    	p->v_y = p->v_saut;

}

}


//-----------------------------------------------------------animation des deplacements---------------------------------------


void animer_perso(perso *p ,SDL_Surface* screen){

int firstframe=2;

if(p->direction==1)
{
	p->frame.y=POS_Y_WALK_DROITE;
	p->curframe++;					//animation droite
	SDL_Delay(100);
   
if(p->curframe>=MAX_FRAMES)
{

	p->curframe=firstframe;					
}
	p->frame.x=p->curframe * p->frame.w;  
 
}
else if(p->direction==2)
{ 
	p->frame.y=POS_Y_WALK_GAUCHE;
	p->curframe++;					//animation gauche
	SDL_Delay(100);

if(p->curframe>=MAX_FRAMES)
{
        p->curframe=firstframe;
}

	p->frame.x=p->curframe * p->frame.w;  
  
}
else if(p->direction==3)
{ 
	p->frame.y=POS_Y_WALK_UP;
	p->curframe++;					//animation up
	SDL_Delay(100);
    
    
if(p->curframe>=MAX_FRAMES)
{
	p->curframe=firstframe;
}
	p->frame.x=p->curframe * p->frame.w;  

}

else if(p->direction==4)
{ 
	p->frame.y= POS_Y_WALK_DOWN ;
	p->curframe++;					//animation down
	SDL_Delay(100);
   
if(p->curframe>=MAX_FRAMES)
{
        p->curframe=firstframe;
}
	p->frame.x=p->curframe * p->frame.w;  
 
}

else if(p->direction==0)
{
							//pas d'animation
	p->frame.x=0;			//initialiser le perso a gauche de la map

}

}
