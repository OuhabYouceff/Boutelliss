#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"

int enigmee(SDL_Surface *ecran)
{SDL_Event event ;
image winn,losee,clock[67];
enigme e;
int done=1,curseur=0,cursor=0,win=0,lose=0,victory,defeat,i=1,nbr=1,j=1;

init_animation_time(clock);
init_image_victoire(&winn);
init_image_defeat(&losee);
e=init_enigme();


while(done)
	{	
                if(i==65)
                  {
                   i=1;
                   nbr++;                 
                  }                


                 if(victory==1)
                 {
                    SDL_Delay(3000);
                     done=0;
                 }
                 if(defeat==1)
                 {
                    SDL_Delay(3000);
                     done=0;
                 }
                

               if(nbr!=3)
                 {
                 animation_time(clock,i,ecran);
                 i++;
                 SDL_Delay(100);
                 }

                afficher_enigme(e,ecran);

              if (win==1)
                {
                 afficherr(winn,ecran);
                
                   switch(e.res)
            	{	
            		case 2:
            		afficherr(e.im2o,ecran);
            		break;
            		case 3:
            		 afficherr(e.im3o,ecran);
            		break;
            		case 4:
            		afficherr(e.im4o,ecran);
            		break;
                }
                 
                     victory=1;
                }
   
              if(lose==1)
                {
                 afficherr(losee,ecran);
                   switch(e.res)
            	{	
            		case 2:
            		afficherr(e.im2o,ecran);
            		break;
            		case 3:
            		 afficherr(e.im3o,ecran);
            		break;
            		case 4:
            		afficherr(e.im4o,ecran);
            		break;
                   
            	}
                 
                   defeat=1;
                }    
                    switch(cursor)
            	{	
            		case 2:
            		afficherr(e.im2o,ecran);
            		break;
            		case 3:
            		 afficherr(e.im3o,ecran);
            		break;
            		case 4:
            		afficherr(e.im4o,ecran);
            		break;
            	}
	
		while (SDL_PollEvent(&event)){
		switch(event.type)
		{
		case SDL_QUIT:
			done=0;
			break;

	  case SDL_KEYDOWN:
	      switch(event.key.keysym.sym)
			{ 
	         case SDLK_ESCAPE:
		done=0;
		break;
                       }
	case SDL_MOUSEMOTION :
	     if((event.motion.x>20 )&&(event.motion.x<180)&&(event.motion.y>200)&&(event.motion.y<264))
            	{
                       curseur=2;         
                       cursor=2;
                } 

              else if((event.motion.x>20 )&&(event.motion.x<180)&&(event.motion.y>300)&&(event.motion.y<364))
              {
            		curseur=3;         
                       cursor=3;
              }
              else if((event.motion.x>20 )&&(event.motion.x<180)&&(event.motion.y>400)&&(event.motion.y<464))
              {
                       curseur=4;         
                       cursor=4;
              }        
    
              else{       
                 cursor=0;
                 curseur=0;
                  }
        break;                       
                       
       case SDL_MOUSEBUTTONUP:
        
            if(event.button.button==SDL_BUTTON_LEFT)
            	      { 
            	
            	if((curseur==e.res)&&(nbr!=3))
                    {
	            win=1;
                    }   
                else if ((curseur!=e.res)||(nbr==3))
                { 
                lose=1;
            	}
			
		  }
	         

                 
                }}
		SDL_Flip(ecran);	
	}
	
if (victory==1)
return 1;
if (defeat==1)
return 0;





}

