#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"


void init_animation_time(image load[])
{
char file[30];
int i;
for (i=1 ;i<=64; i++)
{
//loading menu principale
 sprintf(file,"clock/%d.png",i);
load[i].img = IMG_Load(file);
load[i].pos.x=0;
load[i].pos.y=0;
	 			
}//end loading menu principale
}


void init_image_victoire(image *load)
{
load->img = IMG_Load("background/win.png");
load->pos.x=0;
load->pos.y=0;
}
void init_image_defeat(image *load)
{
load->img = IMG_Load("background/lose.png");
load->pos.x=0;
load->pos.y=0;
}



void afficherr(image p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.img, NULL, ecran,&p.pos);

}

void init_images_enigme(image *im,image *imo,char file[],char fich[],char c)
{
switch(c)
       {
       case '1':
        im->img = IMG_Load(file);
        im->pos.x=10;
        im->pos.y=10; 
        break;
       case '2':
        //inititialisation image 2 de l'enigme
        im->img = IMG_Load(file);
        im->pos.x=20;
        im->pos.y=200;
        //inititialisation image 2 selectionner de l'enigme
        imo->img = IMG_Load(fich);
        imo->pos.x=20;
        imo->pos.y=200;
        break;
       case '3':
        //inititialisation image 3 de l'enigme
        im->img = IMG_Load(file);
        im->pos.x=20;
        im->pos.y=300;
        //inititialisation image 3 selectionner de l'enigme
        imo->img = IMG_Load(fich);
        imo->pos.x=20;
        imo->pos.y=300;
        break;
       case '4':
        //inititialisation image 4 de l'enigme
        im->img = IMG_Load(file);
        im->pos.x=20;
        im->pos.y=400;
        //inititialisation image 4 selectionner de l'enigme
        imo->img = IMG_Load(fich);
        imo->pos.x=20;
        imo->pos.y=400;
        break;
      }
}

enigme init_enigme()
  { image a;
    enigme e;
    char c,file[30],fich[30] ;
    int l,occ=0;
    srand(time(NULL));
    l=1+rand() %5 ;
   

    
        sprintf(file,"fich/%d.txt",l);
        FILE* f=fopen(file,"r") ;
       while((c=fgetc(f))!=EOF)
      {
       occ++ ;
       sprintf(file,"quiz/%d/%c.png",l,c);
       sprintf(fich,"quiz/%d/%co.png",l,c);
      if(occ!=5)
      {
       switch(c)
       {
       case '1':
       init_images_enigme(&e.im1,NULL,file,fich,c); 
        break;
       case '2':
        init_images_enigme(&e.im2,&e.im2o,file,fich,c); 
        break;
       case '3':
        init_images_enigme(&e.im3,&e.im3o,file,fich,c);
        break;
       case '4':
        init_images_enigme(&e.im4,&e.im4o,file,fich,c);
        break;
 
      
       }
      }
     else
       {
       switch(c)
       {
       case '1':
        e.res=1 ;
        break;
       case '2':
        e.res=2 ;
        break;
       case '3':
        e.res=3 ;
        break;
       case '4':
        e.res=4 ;
        break;


       }
       }
      }
     fclose(f);
  return e;
  }

void afficher_enigme(enigme e,SDL_Surface *ecran)
{
afficherr(e.im1,ecran);
afficherr(e.im2,ecran);
afficherr(e.im3,ecran);
afficherr(e.im4,ecran);
}


void animation_time(image clock[],int i,SDL_Surface *ecran)
{
 afficherr(clock[i],ecran);
 

} 









