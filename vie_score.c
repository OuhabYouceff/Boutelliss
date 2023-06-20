#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"	

/*-----------------------------------------------initialisation de la vie---------------------------------*/

/*-----------------type 1----------------------------------*/
void initialiser_vie(vie *v)
{

v->image=IMG_Load("life_bar/life_bar.png");
//SDL_SetColorKey(p->image, SDL_SRCCOLORKEY,color);

v->position.x=POS_X_VIE;
v->position.y=POS_Y_VIE;
v->curframe=4;
v->frame.w=257/5;
v->frame.h=H_VIE;
v->frame.x=(v->frame.w)*(v->curframe);
v->frame.y=0;


}

/*-------------------------type2--------------------------*/
void initvie(Image *v)
{
    v->img= IMG_Load("life_bar/life_bar1.png");
       if(v->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    v->pos1.x=1100; 
    v->pos1.y=20; 
    
}

void initvie0(Image *v0)
{
    v0->img= IMG_Load("life_bar/life_bar0.png");
       if(v0->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    v0->pos1.x=1100; 
    v0->pos1.y=20; 
    
}

void initvief(Image *vf)
{
    vf->img= IMG_Load("life_bar/life_bar_full.png");
       if(vf->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    vf->pos1.x=1100; 
    vf->pos1.y=20; 
    
}

void initviemeh(Image *vm)
{
    vm->img= IMG_Load("life_bar/life_bar_meh.png");
       if(vm->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    vm->pos1.x=1100; 
    vm->pos1.y=20; 
    
}

/*-----------------------------------------------affichage de la vie---------------------------------*/
void afficher_vie (vie *v,SDL_Surface *screen)
{
	SDL_BlitSurface(v->image,&v->frame,screen,&v->position);     
}



/*---------------------------changement de la vie------------------------------------*/

void changer_vie(perso *p,vie *v ,int collision,SDL_Surface* screen)
{

if (collision==1)
{
//v->curframe--;
//v->frame.x-=DISTANCE;
SDL_Delay(100);
}


}




/*------------------------------score-----------------------------------*/
void init_txt_score(txt *txt,int score)
{char s[30];
	// POSITION de txt
	txt->pos.x=1270;
	txt->pos.y=20;
	TTF_Init();
	SDL_Color couleur={0,0,0};
	sprintf(s,"%d",score);
	//initialisation de couleur de txt 
	//chargement d'une police et initisation de la taille 
	txt->p=TTF_OpenFont("28 Days Later.ttf",50);
	
	txt->t=TTF_RenderText_Blended(txt->p,s,couleur);
	// bliter la surface de txt
	 //fermer la police 
	 TTF_CloseFont (txt->p);
	// arreter sdl_ttf;
	 TTF_Quit();
}

void afficher_txt(txt te,SDL_Surface *ecran)
{
SDL_BlitSurface(te.t, NULL, ecran,&te.pos);
}





















