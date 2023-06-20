#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"


//----------------------------------------------initialisation du background anime----------------------------------------------

void initmenu(Image Menu[],char animation[])
{
int i;
for (i=0; i<83; i++)
{
sprintf(animation,"backg/menu-%d.jpg",i+1);
Menu[i].img=IMG_Load(animation);  
Menu[i].pos1.x=0;
Menu[i].pos1.y=0; 			
}
}

void initmenus2(Image Menus[],char animations[])
{
int i;
for (i=1; i<83; i++)
{
sprintf(animations,"settingsbg/%dnight.png",i+1);
Menus[i].img=IMG_Load(animations);  
Menus[i].pos1.x=0;
Menus[i].pos1.y=0; 			
}
}

void initbackgroundanimer(Image Menus[],char animations[])
{
int i;
for (i=1; i<63; i++)
{
sprintf(animations,"backgjeu/lvl-%d.png",i+1);
Menus[i].img=IMG_Load(animations);  
Menus[i].pos1.x=0;
Menus[i].pos1.y=0; 			
}
}

//-------------------------------------------------------animation avant menu----------------------------------------------

void initanim(Image anim[],char anima[])
{
int i;
for (i=1; i<81; i++)
{
sprintf(anima,"anim1/%d.jpg",i);
anim[i].img=IMG_Load(anima);  
anim[i].pos1.x=0;
anim[i].pos1.y=0; 			
}
}


//-----------------------------------------------------------menu principale-----------------------------------------------
void initStart(Image *Start)
{
    Start->img= IMG_Load("buttons/1.png");
       if(Start->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    Start->pos1.x=70; 
    Start->pos1.y=72; 
    Start->pos1.w=140;
    Start->pos1.h=51;
    Start->pos2.x=70;
    Start->pos2.y=72;
}

void initSett(Image *Sett)
{
    Sett->img= IMG_Load("buttons/3.png");
       if(Sett->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    Sett->pos1.x=70; 
    Sett->pos1.y=142; 
    

    Sett->pos2.x=70;
    Sett->pos2.y=142;
}



void initQuit(Image *Quit)
{
    Quit->img= IMG_Load("buttons/5.png");
       if(Quit->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    Quit->pos1.x=70; 
    Quit->pos1.y=214; 
    

    Quit->pos2.x=70;
    Quit->pos2.y=214;
}


void initStart2(Image *Start2)
{
    Start2->img= IMG_Load("buttons/2.png");
       if(Start2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    Start2->pos1.x=70; 
    Start2->pos1.y=72; 
    Start2->pos1.w=140;
    Start2->pos1.h=51;
    Start2->pos2.x=70;
    Start2->pos2.y=72;
}

void initSett2(Image *Sett2)
{
    Sett2->img= IMG_Load("buttons/4.png");
       if(Sett2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
     Sett2->pos1.x=70; 
    Sett2->pos1.y=142; 
    

    Sett2->pos2.x=104;
    Sett2->pos2.y=200;
}



void initQuit2(Image *Quit2)
{
    Quit2->img= IMG_Load("buttons/6.png");
       if(Quit2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    Quit2->pos1.x=70; 
    Quit2->pos1.y=214;  
    

    Quit2->pos2.x=104;
    Quit2->pos2.y=300;
}
void initcredit(Image *credit)
{
    credit->img= IMG_Load("buttons/7.png");
       if(credit->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	credit->pos1.x=540;
	credit->pos1.y=327;	
	credit->pos1.w=0;
	credit->pos1.h=0;
	
	credit->pos2.x=550;
	credit->pos2.y=327;		
}
void initcredit2(Image *credit2)
{
    credit2->img= IMG_Load("buttons/8.png");
       if(credit2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	credit2->pos1.x=540;
	credit2->pos1.y=327;	
	credit2->pos1.w=0;
	credit2->pos1.h=0;
	
	credit2->pos2.x=550;
	credit2->pos2.y=327;		
}
//---------------------------------------------------------menu single/multi player-------------------------------------------------------------------

void initsingle(Image *single)
{
    single->img= IMG_Load("buttons/15.png");
       if(single->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    single->pos1.x=70; 
    single->pos1.y=72; 
    single->pos1.w=140;
    single->pos1.h=51;
    single->pos2.x=70;
    single->pos2.y=72;
}

void initmulti(Image *multi)
{
    multi->img= IMG_Load("buttons/17.png");
       if(multi->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    multi->pos1.x=70; 
    multi->pos1.y=142; 
    

    multi->pos2.x=70;
    multi->pos2.y=142;
}

void initsingle2(Image *single2)
{
    single2->img= IMG_Load("buttons/16.png");
       if(single2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    single2->pos1.x=70; 
    single2->pos1.y=72; 
    single2->pos1.w=140;
    single2->pos1.h=51;
    single2->pos2.x=70;
    single2->pos2.y=72;
}

void initmulti2(Image *multi2)
{
    multi2->img= IMG_Load("buttons/18.png");
       if(multi2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    multi2->pos1.x=70; 
    multi2->pos1.y=142; 
    

    multi2->pos2.x=70;
    multi2->pos2.y=142;
}
//-------------------------------------------initialisation du menu statique pour Game------------------------------------------
void initmenus(Image *s)
{
    s->img= IMG_Load("image/bg.png");
       if(s->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	s->pos1.x=0;
	s->pos1.y=0;	
	s->pos1.w=0;
	s->pos1.h=0;
	
	s->pos2.x=0;
	s->pos2.y=0;	
	s->pos2.w=(SCREEN_W);
	s->pos2.h=(SCREEN_H);
}


//-------------------------------------initialisation du menu statique pour credit------------------------------------------

void initmenuc(Image *c)
{
    c->img= IMG_Load("image/credits.png");
       if(c->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	c->pos1.x=0;
	c->pos1.y=0;	
	c->pos1.w=0;
	c->pos1.h=0;
	
	c->pos2.x=0;
	c->pos2.y=0;	
	c->pos2.w=(SCREEN_W);
	c->pos2.h=(SCREEN_H);
}

//--------------------------------------------------------menu settings--------------------------------------------------------------
//-----------------------------------------initialisation du menu statique pour settings---------------------------------------------
void initmenu2(Image *menu)
{
    menu->img= IMG_Load("image/settings.png");
       if(menu->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	menu->pos1.x=0;
	menu->pos1.y=0;	
	menu->pos1.w=0;
	menu->pos1.h=0;
	
	menu->pos2.x=0;
	menu->pos2.y=0;	
	menu->pos2.w=(SCREEN_W);
	menu->pos2.h=(SCREEN_H);
}
//-------------------------------------initialisation des bouttons fullscreen menu settings------------------------------------------
void initf(Image *f)
{
       f->img= IMG_Load("buttons/9.png");
       if(f->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	f->pos1.x=203;
	f->pos1.y=240;	
	
	
	f->pos2.x=203;
	f->pos2.y=240;		
}

void initf2(Image *f2)
{
    f2->img= IMG_Load("buttons/10.png");
       if(f2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	f2->pos1.x=203;
	f2->pos1.y=240;	

	
	f2->pos2.x=203;
	f2->pos2.y=240;		
}
//-----------------------------------------------init des barres volume static----------------------------------------------
//-----------------------------------------------init des barre volume principale-------------------------------------------
void initv(Image *v)
{
    v->img= IMG_Load("barre/volume3.png");
       if(v->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v->pos1.x=40;
	v->pos1.y=120;	

	
	v->pos2.x=0;
	v->pos2.y=200;		
}

void initv_1(Image *v_1)
{
    v_1->img= IMG_Load("barre/volume4.png");
       if(v_1->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v_1->pos1.x=40;
	v_1->pos1.y=120;	

	
	v_1->pos2.x=0;
	v_1->pos2.y=200;		
}
void initv_2(Image *v_2)
{
    v_2->img= IMG_Load("barre/volume5.png");
       if(v_2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v_2->pos1.x=40;
	v_2->pos1.y=120;	

	
	v_2->pos2.x=0;
	v_2->pos2.y=200;		
}
void initv_3(Image *v_3)
{
    v_3->img= IMG_Load("barre/volume2.png");
       if(v_3->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v_3->pos1.x=40;
	v_3->pos1.y=120;	

	
	v_3->pos2.x=0;
	v_3->pos2.y=200;		
}
void initv_4(Image *v_4)
{
    v_4->img= IMG_Load("barre/volume1.png");
       if(v_4->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v_4->pos1.x=40;
	v_4->pos1.y=120;	

	
	v_4->pos2.x=0;
	v_4->pos2.y=200;		
}
//-----------------------------------------------------initialisation des barres sfx----------------------------------------
void initv2(Image *v2)
{
    v2->img= IMG_Load("barre/volume3.png");
       if(v2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v2->pos1.x=40;
	v2->pos1.y=190;	

	
	v2->pos2.x=0;
	v2->pos2.y=300;		
}
void initv2_1(Image *v2_1)
{
    v2_1->img= IMG_Load("barre/volume4.png");
       if(v2_1->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v2_1->pos1.x=40;
	v2_1->pos1.y=190;	

	
	v2_1->pos2.x=0;
	v2_1->pos2.y=300;		
}
void initv2_2(Image *v2_2)
{
    v2_2->img= IMG_Load("barre/volume5.png");
       if(v2_2->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v2_2->pos1.x=40;
	v2_2->pos1.y=190;	

	
	v2_2->pos2.x=0;
	v2_2->pos2.y=300;		
}
void initv2_3(Image *v2_3)
{
    v2_3->img= IMG_Load("barre/volume2.png");
       if(v2_3->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v2_3->pos1.x=40;
	v2_3->pos1.y=190;	

	
	v2_3->pos2.x=0;
	v2_3->pos2.y=300;		
}
void initv2_4(Image *v2_4)
{
    v2_4->img= IMG_Load("barre/volume1.png");
       if(v2_4->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	v2_4->pos1.x=40;
	v2_4->pos1.y=190;	

	
	v2_4->pos2.x=0;
	v2_4->pos2.y=300;		
}
//--------------------------------------------------------decoration des barres------------------------------------------------
void initvol(Image *vol)
{
    vol->img= IMG_Load("image/volume.png");
       if(vol->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	vol->pos1.x=108;
	vol->pos1.y=83;	

	
	vol->pos2.x=0;
	vol->pos2.y=200;		
}

void initsfx(Image *sfx)
{
    sfx->img= IMG_Load("image/sfx.png");
       if(sfx->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	sfx->pos1.x=109;
	sfx->pos1.y=153;	

	
	sfx->pos2.x=0;
	sfx->pos2.y=200;		
}
//---------------------------------------------------------decoration--------------------------------------------------------------
void initt(Image *t)
{
    t->img= IMG_Load("image/version1.0.png");
       if(t->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	t->pos1.x=5;
	t->pos1.y=350;	

	
	t->pos2.x=0;
	t->pos2.y=200;		
}
void initb(Image *b)
{
    b->img= IMG_Load("image/title.png");
       if(b->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	b->pos1.x=300;
	b->pos1.y=90;	

	
	b->pos2.x=0;
	b->pos2.y=200;		
}


//--------------------------------------------fonction affichage de n'importe quelle image------------------------------------

void afficher(Image p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.img,NULL,screen,&p.pos1);
}


//-----------------------------------------------------liberation-------------------------------------------------------------
void liberers(SDL_Surface *screen)
{
	SDL_FreeSurface(screen);
}


void liberer(Image A)
{
	SDL_FreeSurface(A.img);

}

/*---------------------------------------------liberation des animations----------------------------------------*/

void libererm(Image anim[],int n)
{
 int i ;
 
 for (i=0;i<n;i++)
 {
 SDL_FreeSurface(anim[i].img);
 }

}


void initfinn(Image *fi)
{
    
    fi->img= IMG_Load("finn1.png");
       if(fi->img == NULL){
           printf("Unable to Load The Image: %s \n ", SDL_GetError());
           return;
       }
    	fi->pos1.x=366;
	fi->pos1.y=381;	
	fi->pos1.h=74;
	fi->pos1.w=42;
			
}







