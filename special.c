#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"
#include "enigme.h"

void start2(SDL_Surface *ecran)
{



ecran = SDL_SetVideoMode(2000,512,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);//pour agrandir la fennetre si on click sur single/multi

Mix_Music *music;				//variables pour la musique 
Mix_Chunk *clickmusic;

 	    music = Mix_LoadMUS("sounds/plume.mp3");
	    Mix_PlayMusic(music,-1);
	    Mix_VolumeMusic(50);

Input in;
int pause;


int done=1,enigme ;

int scrolling;
int j=1;

int a=1;

char animm[100];

Image s,backg_animer[100];

//SDL_Event event;
SDL_EnableKeyRepeat(200, 0);
SDL_Event event;
SDL_Surface *bg;

/*-------------------------------------------------score------------*/
int count=0,maxcount=0,score=0;
txt txt_scoree;
init_txt_score(&txt_scoree,score);
/*-------------------------------------------------score------------*/

/*-------------------------------------------------vie--------------*/
perso p1;
//vie v;
Image vf,vm,v1,v2,finn;

initvief(&vf);
initvie(&v1);
initvie0(&v2);
initviemeh(&vm);
int vie=4; 
/*-------------------------------------------------vie--------------*/

/*----------------------------------------initialisation de base--------------------------*/

//partie magnifique
//initmenus(&s);
//initbackgroundanimer(&backg_animer[j],animm);
//initialiser_vie(&v);


//*--------------------------------------------------*//
initialiser_Perso1(&p1);
bg=IMG_Load("image/big_map.png");


SDL_Rect posbg;
posbg.x=0;
posbg.y=0;
/*----------------------------------minimap----------------------*/

int direction=-1;
int  distance = 5;
int b=1;
minimap m;

Personne p, gp,mp,petit ;
 temps t;
  int redimensionnement =  20*19/100; //distance parcourue par le mini perso dans la minmap
  
  TTF_Init();
  initmap(&m);
  initialiser_temps(&t);
  
  p.sprite = IMG_Load("miniperso/azizmini.png");
  p.position_perso.x = 0;
  p.position_perso.y = 81;
  
  petit.sprite = IMG_Load("miniperso/azizmini1.png");
   //petit.position_perso.x = 0;
  // petit.position_perso.y = 220;
/*----------------------------------minimap----------------------*/


/*---------------------------------BACKGROUND--------------------*/

//init
backg back,mask;


/*------------------------------------------------------VARIABLE POUR ANIMATION--------------------------------------*/
SDL_Surface *crow;
SDL_Rect pos_crow;//pos crow al ecran
pos_crow.x=500;//bsh matodhherch mn awel l ooba 
pos_crow.y=50;
crow=IMG_Load("crow.png");
SDL_Rect pos_sprite;//pos_crow al sprite
pos_sprite.x=0;
pos_sprite.y=0;
pos_sprite.h=65;
pos_sprite.w=524/9;

int animation_crow=0;//yaaref ken saret animation welee
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
Mix_Chunk* Music;
Music = Mix_LoadWAV("music.wav");
int music_played=0;
	
/*------------------------------------------------------VARIABLE POUR ANIMATION--------------------------------------*/

initbackg(&back);
//initbackg2(&mask);


/*---------------------------------BACKGROUND--------------------*/


/*----------------------------------init entite secondaire------------------*/

//variables
ennemi e;
coin c,c2;
int collision;
int collision1;


char chaine[50];
char nomjoueur[50];
int cc=0;

initennemi(&e);
//initcoin(&c);
/*----------------------------------init entite secondaire------------------*/

strcpy(chaine,"");
playername(ecran , chaine);
printf("%s",chaine);

//charger (&p1,&back,&p);
//boucle infinie!
while(done)




{
/*--------------------------------affichage du background animer--------------------------*/
/*
if (j==63)
{
j=1;
}		
SDL_BlitSurface(backg_animer[j].img,NULL,ecran,&backg_animer[j].pos1);
j++;
SDL_Delay(50);
*/
/*-------------------------------------------------------------------------------------------*/

//SDL_BlitSurface(bg,NULL,ecran,&posbg);

/*------------------------------BACKGROUND---------------------------*/
//afficher2(mask,screen);
afficherbackg(back,ecran);

if(in.right==1)
{
p1.direction=1;
p1.position.x+=10;
scrolling=2;
animer_perso(&p1,ecran);
//in.right=0;
}

else if (in.left==1)
{
p1.direction=2;
scrolling=3;
p1.position.x-=10;
animer_perso(&p1,ecran);
}

else if((in.left==1)&&(in.right==1))
{
p1.position.y-=7;
saut1(&p1,event,ecran);
}

if (collision1==1)
{ 

p1.position.x+=150;
p.position_perso.x+=25;
vie-- ;
arduinoWriteData(5);
}

if(vie<=0)
{
 ecran = SDL_SetVideoMode(800,600,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);
 enigme=enigmee(ecran);
 
 if(enigme==1)
  {
   vie=4;
   ecran = SDL_SetVideoMode(2000,512,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);
  }
 else 
  {
   
   done=0;
  }
}
getInput(&in,&pause);
switch(vie)
{
case 1:
afficher(v2,ecran);
break;

case 2:
afficher(vm,ecran);
break;

case 3:
afficher(v1,ecran);
break;

case 4:
afficher(vf,ecran);
break;
}

if( p1.position.x>=900)
       	{
       	
       	srand( time( NULL ) );
       	game(ecran,&done);
       		
       	}

afficherPerso1(&p1,ecran);

/*-------------------------------entite secondaire-------------------------------*/
afficherennemi(&e,ecran);
//affichercoin(&c,ecran);
/*-------------------------------entite secondaire-------------------------------*/

SDL_PollEvent(&event);

deplacer_perso1(&p1,ecran,event);
saut1(&p1,event,ecran);
animer_perso(&p1,ecran);



//entite secondaire
animer(&e);
animerc(&c);
deplacement(&e);
deplacementcoin(&c);
deplacerIA(&e,p1);

collision1=collision_enemy_perso(p1,e);
//printf("%d\n",collision1);



//fin entite secondaire 

 p1.x=p1.position.x;
 count=p1.x;
      if(count-maxcount>100)
         {
           score++;
            init_txt_score(&txt_scoree,score);
           maxcount=count ;
            
         }
        afficher_txt(txt_scoree,ecran);	
        
      
        

/*------------------------------------------------PARTIE MINIMAP + PERSO INTEGRATION----------------------------------*/

afficherminimap(m, ecran);
if(b==1)
{
SDL_BlitSurface(p.sprite, NULL, ecran, &p.position_perso);
}
else
{
SDL_BlitSurface(petit.sprite, NULL, ecran, &petit.position_perso);
}
afficher_temps(&t, ecran);
 
 
switch(event.type)
{	

case SDL_KEYDOWN:

switch(event.key.keysym.sym)
{

case SDL_QUIT:
done=0;
break;

case SDLK_ESCAPE:
{
done=0;
ecran = SDL_SetVideoMode(640,360,32,SDL_DOUBLEBUF|SDL_HWSURFACE |SDL_SRCALPHA|SDL_RESIZABLE);//pour remetre les parametres initiale de la fenetre

 music = Mix_LoadMUS("sounds/the-last-of-us-theme-song.mp3"); //remetre la musique du menu principale
	    Mix_PlayMusic(music,-1);
	    Mix_VolumeMusic(50);
break;
} 



   case SDLK_d:
   {
          //direction prend 0 pour que le mini perso bouge a droite sur la minimap grace a la fonction majminimap      	
                    b=1;
                    direction=0;      
                    majminimap(&p,&m,direction,redimensionnement);
                   
                    //bordure de la map
                    if(p1.position.x+88>=1600)
                    {
                    p1.position.x=1600-88;
                    majminimap(&p,&m,direction,redimensionnement);
                    }
                    
                    //bordure  de la minimap
                    if(p.position_perso.x+35>=600)
                    {
                   
                    p.position_perso.x=600-35;
                     majminimap(&p,&m,direction,redimensionnement);                    }
                    
 /*----------------------BACKGROUND-------------*/
                    
                  	  scrolling=2;
  			
  			//collision=collisionPP(perso,mask);
  			//printf("collision %d\n",collision);
			
			if (back.pos1.x +back.pos1.w <=1000)
					{
						
						scrolling=1;
					}
					
			 /*if (collision==1)
			{
				perso.pos1.x=0;
				//back.pos1.x=0;
				mask.pos2.x=0;
			}*/
				
				
			}	
  			
               
    break;  
           case SDLK_a:
                 //direction prend 1 pour que le mini perso bouge a gauche sur la minimap grace a la fonction majminimap  
                      	b=0; 
                       petit.position_perso.x =p.position_perso.x ;
   			petit.position_perso.y =p.position_perso.y ;
                      	direction=1;
 	
                 	majminimap(&p,&m,direction,redimensionnement);
                 	
                 	 scrolling=3;
  			 
  			 	if (back.pos1.x >= 0)
					{
						back.pos1.x=0;
					}
					
                 	
	    break;
                                       
}
}

 
 //PARTIE SCROLL
/*--------------------------------------------------------------------------------------------------------------------------------*/
    if (scrolling==4) 
  {

   scroling(&back,scrolling,&mask,&back);	
  scrolling=1;	
 
  }
   if (scrolling==3) 
  {

 scroling(&back,scrolling,&mask,&back);
  scrolling=1;	
  }
  if (scrolling==2) 
  {
    
  scroling(&back,scrolling,&mask,&back);
  
 scrolling=1;	
  }
  if (scrolling==5) 
  {

   scroling(&back,scrolling,&mask,&back);
  scrolling=1;	
  }
 
 
/*--------------------------------------------------------------------------------------------------------------------------------*/
//aniamtion crow 

if(back.pos1.x<2000){


if(music_played==0){
Mix_PlayChannel(-1,Music,0 );
music_played=1;
}

SDL_BlitSurface(crow,&pos_sprite,ecran,&pos_crow);

if(pos_crow.x<=1200){
pos_sprite.x+=pos_sprite.w;
if(pos_sprite.x>=524)
pos_sprite.x=0;


pos_crow.x+=5;
}
SDL_Delay(50);
}

//sauvgarder ( score,chaine,"sauvegarde.txt");
sauvegarder1(p1,back,p);
SDL_Flip(ecran);
}

printf(" MEILLEUR SCORE ACTUEL DE %s EST :%d\n",chaine,score);
}

