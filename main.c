#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"

int main()
{
/*-----------------------------------------------VARIABLES----------------------------------*/
    int direction=-1;//variable pour savoir la direction du perso 
    int  distance = 100;
    
    SDL_Event event;
    
    minimap m;
    
    Personne p, gp,mp ;
    
    temps t;
    
    SDL_Surface *screen = NULL, *imageDeFond = NULL, *masked = NULL; 
    
    SDL_Rect position_BG;
    
    int  i = 0;
    
    int redimensionnement =  40*100/100; //distance parcourue par le mini perso dans la minmap
    
    int continuer = 1;
    
    screen = SDL_SetVideoMode(1600, 800, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    
      if (screen == NULL)
    {
        printf("ERREUR: %s\n", SDL_GetError());
        return 1;
    }
    
    TTF_Init();
    
  //initialisation
    position_BG.x = 0;
    position_BG.y = 0;
    
    initmap(&m);
    initialiser_temps(&t);
    imageDeFond = IMG_Load("map1.png");
    masked = IMG_Load("map1_masked.png");

    p.sprite = IMG_Load("point.png");
    p.position_perso.x = 0;
    p.position_perso.y = 192.5;

    gp.sprite = IMG_Load("aziz.png");
    
    gp.position_perso.x = 0;
    gp.position_perso.y = 550;

    mp.position_perso.x = 0;
    mp.position_perso.y = 550;



    while (continuer)
    {

        SDL_BlitSurface(imageDeFond, NULL, screen, &position_BG);
        afficherminimap(m, screen);
        SDL_BlitSurface(p.sprite, NULL, screen, &p.position_perso);
        SDL_BlitSurface(gp.sprite, NULL, screen, &gp.position_perso);
        afficher_temps(&t, screen);

      
        
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
                
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
               
                case SDLK_ESCAPE:
                    continuer = 0;
                break;
                
                case SDLK_RIGHT:
          //direction prend 0 pour que le mini perso bouge a droite sur la minimap grace a la fonction majminimap      	
                    direction=0;      
                     
                    gp.position_perso.x+=distance;
                     
                    majminimap(&p,&m,direction,redimensionnement);
                    //bordure de la map
                    if(gp.position_perso.x+88>=1600)
                    {
                    gp.position_perso.x=1600-88;
                    majminimap(&p,&m,direction,redimensionnement);
                    
                    }
                    //bordure  de la map
                    if(p.position_perso.x+35>=600)
                    {
                   
                    p.position_perso.x=600-35;
                     majminimap(&p,&m,direction,redimensionnement);
                    }
                    
                    if (collisionPP(gp, masked) == 1)
                    { 
                   	 
                   	 
                   	 direction=-1;
 
                       gp.position_perso.x = mp.position_perso.x;
                       p.position_perso.x =gp.position_perso.x; 
                       
                       majminimap(&p,&m,direction,redimensionnement);
                    }
                   break;

                case SDLK_LEFT:
                 //direction prend 1 pour que le mini perso bouge a gauche sur la minimap grace a la fonction majminimap  
                      direction=1;
 
                    gp.position_perso.x-=distance;
                     
                    majminimap(&p,&m,direction,redimensionnement);
                
                  if (collisionPP(gp, masked) == 1)
                    { 
                   	 
                   	 
                   	 direction=-1;
 
                       gp.position_perso.x = mp.position_perso.x;
                       p.position_perso.x =gp.position_perso.x; 
                       
                       majminimap(&p,&m,direction,redimensionnement);
                    }
                
                 break;


                    case SDLK_DOWN:
                    //direction prend 2 pour que le mini perso bouge en bas sur la minimap grace a la fonction majminimap  
                    direction=2;
 
                    gp.position_perso.y+=distance;
                     
                    majminimap(&p,&m,direction,redimensionnement);
                  
                    //bordure  de la map
                  
                   if(p.position_perso.y+35>=280)
                    {
                   
                    p.position_perso.y=280-35;
                     majminimap(&p,&m,direction,redimensionnement);
                    }
                  
                  
                  
                  if (collisionPP(gp, masked) == 1)
                    { 
                   	 
                   	 
                   	 direction=-1;
 
                       gp.position_perso.y = 550;
                       p.position_perso.y = 192.5; 
                       
                       majminimap(&p,&m,direction,redimensionnement);
                    }
                
                    break;


                    case SDLK_UP:
                    //direction prend 3 pour que le mini perso bouge en haut sur la minimap grace a la fonction majminimap  
                       direction=3;
 
                    gp.position_perso.y-=distance;
                     
                    //majminimap(&p,&m,direction,redimensionnement);
                  
                   if(p.position_perso.y+35>=0)
                    {
                   
                     p.position_perso.y-=35;
                     //majminimap(&p,&m,direction,redimensionnement);
                    }
                  
                  
                  
                 		 if (collisionPP(gp, masked) == 1)
                    { 
                   	 
                   	 
                   	 direction=-1;
 
                       gp.position_perso.y = 550;
                       p.position_perso.y = 192.5; 
                       
                       majminimap(&p,&m,direction,redimensionnement);
                    }
                  
                    break;

                case SDLK_p:
                
                    imageDeFond = IMG_Load("map1_masked.png");
                    
                    break;
                case SDLK_o:
                
                    imageDeFond = IMG_Load("map1.png");

                }
                
            }
        }
        SDL_Flip(screen);
    }
    
    free_minimap(&m);
    SDL_FreeSurface(p.sprite);
   
    free_temps(&t, screen);
    SDL_FreeSurface(screen);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
