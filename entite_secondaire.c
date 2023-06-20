#include <stdio.h>
 #include<stdlib.h>
 #include"image.h"
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>
 #include<math.h>
 
 /*--------------------------------------initialisation------------------------------------------------------------*/
 void initennemi(ennemi *e)
 {
 e->sprite=IMG_Load("entite_secondaire1/minion.png");
 if(e->sprite==NULL){
 return ;
 }
 e->nbr=0;
 e->time=wicked;
 e->possprite.x=0;
 e->possprite.y=0;
 e->possprite.w=276;  
 e->possprite.h=152;   
 e->posscreen.x=510;
 e->posscreen.y=390;
 e->posscreen.w=276/6;
 e->posscreen.h=152/2;
 e->direction=0;
 }
 
 
  void initcoin(coin *e)
 {
 e->sprite=IMG_Load("entite_secondaire1/coinf.png");
 if(e->sprite==NULL){
 return ;
 }
 e->nbr=0;
 e->time=micked;
 e->possprite.x=0;
 e->possprite.y=0;
 e->possprite.w=288;
 e->possprite.h=43;   
 e->posscreen.x=200;
 e->posscreen.y=400;
 e->direction=0;
 }
 
 
 /*--------------------------------------------affichage------------------------------------------------------*/
 
void afficherennemi(ennemi *e,SDL_Surface *screen)
 {

 e->pos1.x=e->posscreen.x;
 e->pos1.y=e->posscreen.y;
 e->pos1.h=e->possprite.h;
 e->pos1.w=e->possprite.w;
 
 e->pos2.x=e->nbr*(276/6);
 //e->pos2.y=76/2;
 e->pos2.w=276/6;
 e->pos2.h=152/2;
 SDL_BlitSurface(e->sprite,&e->pos2,screen,&e->pos1);
 }
 
 
 
 void affichercoin(coin *e,SDL_Surface *screen)
 {
 SDL_Rect pos1,pos2;
 pos1.x=e->posscreen.x;
 pos1.y=e->posscreen.y;
 pos1.h=e->possprite.h;
 pos1.w=e->possprite.w;
 
 pos2.x=e->nbr*(288/6);
 pos2.y=0;
 pos2.w=288/6;
 pos2.h=43;
 SDL_BlitSurface(e->sprite,&pos2,screen,&pos1);
 }
 
 /*-----------------------------------------liberation---------------------------------------------------------*/
 
 /*void liberer(ennemi *a)
{
SDL_FreeSurface(a->sprite);
}*/

/*------------------------------------------animation--------------------------------------------------------*/

 void animer(ennemi *e)
 {
 

 
 if(e->time<=0)
 {
 e->nbr++;
e->time=wicked;	
 	if(e->nbr>=e->possprite.w/(276/6))
 	{
 	e->nbr=0;
 	}
 }
 else
 {
 e->time--;
 
 }
 
 }
  
  void animerc(coin *e)
 {
 

 
 if(e->time<=0)
 {
 e->nbr++;
e->time=micked;	
 	if(e->nbr>=e->possprite.w/(288/6))
 	{
 	e->nbr=0;
 	}
 }
 else
 {
 e->time--;
 }
 }
 /*-------------------------------------------deplacement-------------------------------------------------------*/
 
 void deplacement(ennemi *e)
 {
 	
   if(e->direction==0)
   {
   
   SDL_Delay(100);	
   e->pos2.y=76;
   
   e->posscreen.x=e->posscreen.x+5;
	if(e->posscreen.x==600)
		{
		e->direction=1;
		
		}
		
   }	
   
  else if(e->direction==1)
   {
   SDL_Delay(100);
   e->pos2.y=0;
   e->posscreen.x=e->posscreen.x-5;
   	if (e->posscreen.x==0)
   	{
   	
   	e->direction=0;
   	}
   }
   
   
  
 
 
 }
 
  void deplacementcoin(coin *c)
 {
 	
   if(c->direction==0)
   {
   SDL_Delay(100);	
   c->pos2.y=0;
   
   c->posscreen.y=c->posscreen.y-10;
	if(c->posscreen.y==390)
		{
		c->direction=1;
		
		}
		
   }	
   
  else if(c->direction==1)
   {
   SDL_Delay(100);
   c->pos2.y=0;
   c->posscreen.y=c->posscreen.y+10;
   	if (c->posscreen.y==430)
   	{
   	
   	c->direction=0;
   	}
   	
   	
   }
  
 
 
 }
 
/*--------------------------------------------collision------------------------------------------------------*/
 
 int collision_enemy_perso(perso perso, ennemi e)
{
	int collision=0;
	
	if((perso.position.x  >= e.posscreen.x+e.posscreen.w)//GAUCHE
    || (perso.position.x + perso.position.w  <= e.posscreen.x )//DROITE
    || (perso.position.y >= e.posscreen.y + e.posscreen.h )//BAS
    || (perso.position.y + perso.position.h  <=e.posscreen.y)//HAUT
    	)
   	collision=0;
   	else  
   	collision=1;
   	return collision;
    }
    

///////////////////////////////////////////////////////////////////////////////////////////

void deplacerIA( ennemi * e, perso perso )
{
  int distance,distance1;
   
distance = (perso.position.x+perso.position.w)-e->posscreen.x;
distance1 =(e->posscreen.x+e->posscreen.w)-perso.position.x;
 
  if((distance<=400)&&((e->posscreen.x+e->posscreen.w)<perso.position.x))
  {
     e->posscreen.x +=10;
      e->direction=0;
     
       
     
  }
  else if ((distance1<400)&&((perso.position.x+perso.position.w)<e->posscreen.x))
  {
    e->posscreen.x -= 10 ;
    e->direction=1;  
       
  }
}    















    
 
 
 
 
