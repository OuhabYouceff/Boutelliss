#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"

void page1(SDL_Surface *ecran)
{
int done=1 ;
Image c;
SDL_Event event ;
int j=1;
ecran = SDL_SetVideoMode(600,300,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
char animm[100];
perso p1;
Input in;
int pause;

Image s,backg_animer[100];

initialiser_Perso(&p1);
//p1.position.x=50;
//p1.position.x=150;

//initmenus(&s);

initbackgroundanimer(&backg_animer[j],animm);
char chaine[50];
//strcpy(chaine,"");
//playername(ecran , chaine);
//printf("%s",chaine);

while(done)
{

/*--------------------------------affichage du background animer--------------------------*/

if (j==63)
{
j=1;
}		
SDL_BlitSurface(backg_animer[j].img,NULL,ecran,&backg_animer[j].pos1);
j++;
SDL_Delay(50);

/*-------------------------------------------------------------------------------------------*/


if (p1.position.x<=53)
{
p1.position.x=53;
}
if(in.right==1)
{
p1.direction=1;
//scrolling=1;
p1.position.x+=10;
animer_perso(&p1,ecran);
//in.right=0;
}

else if (in.left==1)
{
p1.direction=2;
//scrolling=3;
p1.position.x-=10;
animer_perso(&p1,ecran);
}

else if((in.left==1)&&(in.right==1))
{
p1.position.y-=7;
saut1(&p1,event,ecran);
}


afficherPerso1(&p1,ecran);
SDL_PollEvent(&event);


deplacer_perso1(&p1,ecran,event);
//saut1(&p1,event,ecran);
animer_perso(&p1,ecran);
getInput(&in,&pause);

if(p1.position.x>=430)
{
start2(ecran);
}

{switch(event.type)
{	
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_ESCAPE:
{done=0;
ecran = SDL_SetVideoMode(711,400,32,SDL_HWSURFACE| SDL_DOUBLEBUF);
break;
}                                              
}
}

}
SDL_Flip(ecran);
}
}
