#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "image.h"

#define screen_w 1080
#define screen_H 720


/*-------------------------------------------------------FONCTIONS INITIALISATION----------------------------------------------------------*/

//Backg
void initbackg(backg *back)
{
	back->img=IMG_Load("image/sidibou.png"); // chargement de background 
	
	back->pos1.x=0;
	back->pos1.y=0;
	back->pos1.w=1248 ;
	back->pos1.h=192;
	back->pos2.x=0;
	back->pos2.y=0;
	back->pos2.w=3360;
	back->pos2.h=512;
	back->camera.x=0;
	back->camera.y=0;
	back->camera.h=512;
	back->camera.w=500;
}


void initbackg2(backg *back)
{
	back->img=IMG_Load("mask.png"); // chargement de background 
	
	back->pos1.x=0;
	back->pos1.y=0;
	back->pos1.w=3360;
	back->pos1.h=512;
	back->pos2.x=0;
	back->pos2.y=0;
	back->pos2.w=3360;
	back->pos2.h=512;
	back->camera.x=0;
	back->camera.y=0;
	back->camera.h=512;
	back->camera.w=500;
}


//////////partage d'ecran

void initbackg3(backg *back2)
{
	back2->img=IMG_Load("big_map.png"); // chargement de background 
	
	back2->pos1.x=0;
	back2->pos1.y=512;
	back2->pos1.w=3360;
	back2->pos1.h=512;
	back2->pos2.x=0;
	back2->pos2.y=0;
	back2->pos2.w=3360;
	back2->pos2.h=512;
	back2->camera.x=0;
	back2->camera.y=0;
	back2->camera.h=512;
	back2->camera.w=500;
}

/*-------------------------------------------------------FONCTION AFFICHAGE----------------------------------------------------------*/

//Backg
void afficherbackg(backg back,SDL_Surface *screen)
{
 SDL_BlitSurface(back.img,NULL,screen,&back.pos1); // bliter background fouk screen 
}

void afficher2(backg back,SDL_Surface *screen)
{
 SDL_BlitSurface(back.img,NULL,screen,&back.pos2); // bliter background fouk screen 
}

void afficher3(backg back3,SDL_Surface *screen)
{
 SDL_BlitSurface(back3.img,NULL,screen,&back3.pos1); // bliter background fouk screen 
}
/*-------------------------------------------------------FONCTION SCROLLING----------------------------------------------------------*/

void scroling(backg *back,int scrolling,backg *mask,backg *back2)
{
		if (scrolling==2) //right
		{
		back->pos1.x=back->pos1.x-15; 
		//mask->pos2.x-=5;
		 
		}
		else if (scrolling==3)//left
		{
		back->pos1.x=back->pos1.x+15;
		//mask->pos2.x+=5;
		
		}
		else if (scrolling==4) //up
		{
		back2->pos1.x=back2->pos1.x-5;
		}
		else if (scrolling==5) //down
		{
		back2->pos1.x=back2->pos1.x+5;
}		}		

/*--------------------------------------------------FONCTION COLLISION--------------------------------------------------*/			
			

SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{

    SDL_Color color;
    Uint32 col = 0;
    //Determine position

    char *pixelPosition = (char *)Background->pixels;
    //Offset by Y
    pixelPosition += (Background->pitch * y);
    //Offset by X
    pixelPosition += (Background->format->BytesPerPixel * x);
    //Copy pixel data
    memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
    //Convert to color
    SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

    return (color);
}


int collisionPP(perso p, backg mask)
{
    SDL_Color test, couleurnoir = {255,255,255};

    SDL_Rect pos[8];
    
    pos[0].x = p.position.x;
    pos[0].y = p.position.y;
    pos[1].x = p.position.x + p.position.w / 2;
    pos[1].y = p.position.y;
    pos[2].x = p.position.x + p.position.w;
    pos[2].y = p.position.y;
    pos[3].x = p.position.x;
    pos[3].y = p.position.y + p.position.h / 2;
    pos[4].x = p.position.x;
    pos[4].y = p.position.y + p.position.h;
    pos[5].x = p.position.x + p.position.w / 2;
    pos[5].y = p.position.y + p.position.h;
    pos[6].x =p.position.x + p.position.w;
    pos[6].y = p.position.y + p.position.h;
    pos[7].x = p.position.x + p.position.w;
    pos[7].y = p.position.y + p.position.h / 2;
    
    int collision = 0, x, y;

    for (int i = 0; i < 8 && collision == 0; i++)
    {
        x = pos[i].x;
        y = pos[i].y;
        
        test = GetPixel(mask.img, x, y);
        
        if (test.r == 255 && test.g == 255 && test.b == 255)
            collision = 1;
    }
    return collision;
}





