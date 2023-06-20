#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "image.h"

/*------------------------------------------initialisation----------------------------------------*/
void initmap(minimap *m)
{
    m->position_mini.x = 0;
    m->position_mini.y = 13;				
    m->sprite = NULL;
    m->sprite = IMG_Load("miniperso/minimap.png");
}


void initialiser_temps(temps *t)
{
    t->texte = NULL;
    t->position.x = 1450;
    t->position.y = 15;
    t->police = NULL;
    t->police = TTF_OpenFont("28 Days Later.ttf",50);
    strcpy(t->entree, "");				//initialiser la chaine "entree" qui se trouve dans la structure "temps", a vide
    (t->secondesEcoulees) = 0;
    time(&(t->t1)); //temps du debut
}

/*-------------------------------------------------------Affichage--------------------------------------------------*/
void afficherminimap(minimap m, SDL_Surface *screen)
{
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
}

void afficher_temps(temps *t, SDL_Surface *screen)
{
    SDL_Color couleurnoir = {255, 0, 0}; //code couleur rouge
    
    time(&(t->t2)); // temps actuel

    t->secondesEcoulees = t->t2 - t->t1; //temps actuel - temps initiale = temps ecouler

    t->min = ((t->secondesEcoulees / 60));  //transformer les secondes en minutes
    t->sec = ((t->secondesEcoulees) % 60);  //les secondes restantes
    int millisecondes=SDL_GetTicks()%60;
    
    sprintf(t->entree, "%02d:%02d:%02d", t->min, t->sec, millisecondes);	//mettre le temps ecouler dans la chaine "entree"

    t->texte = TTF_RenderText_Blended(t->police, t->entree, couleurnoir);    

    SDL_BlitSurface(t->texte, NULL, screen, &(t->position)); /* Blit du texte */ //afficher la chaine ou il y a le temps ecouler
}



void free_minimap(minimap *m)
{
    SDL_FreeSurface(m->sprite);
}


/*--------------------------------------------------------Fonction MajMinimap-----------------------------------------------*/

void majminimap (Personne *p, minimap *m ,int direction ,int redimensionnement)
{
//chaque fois que direction va changer dans le main la position du perso va changer grace a la variable redimensionnement
  if (direction==0)
  p->position_perso.x += redimensionnement;

  if (direction==1)
  p->position_perso.x -= redimensionnement;

  if (direction==2)
  p->position_perso.y += redimensionnement;

  if (direction==3)
  p->position_perso.y -= redimensionnement;

}


/*---------------------------------------------Fonction Score---------------------------------------------*/



void meilleur( char nomfichier[],char nomfichier2[], int *score, char nomjoueur[])
{

int i=0,j=0;
     char c,c2,ch[90];
   FILE *f=NULL,*f2=NULL ;
   f=fopen(nomfichier,"r");
   f2=fopen(nomfichier2,"r");
if ((f!=NULL)&&(f2!=NULL))
{ while((c2=fgetc(f2))!=EOF)
  {
   nomjoueur[i]=c;
   j++;
  }
  while((c=fgetc(f))!=EOF)
  {
   ch[i]=c;
   i++;
  }
  sscanf(ch,"%d",&(*score));
  fclose(f);
  fclose(f2);
}
else
    printf ("error \n");

}


/*----------------------------------------------------------Liberation--------------------------------------*/
void free_temps(temps *t, SDL_Surface *screen)
{
    SDL_FreeSurface(t->texte);
    TTF_CloseFont(t->police);
}



void playername(SDL_Surface *screen , char chaine[50])
{

	TTF_Init();
SDL_Event event;
int i=0;
SDL_EnableKeyRepeat(200,0);
SDL_Rect pos;
SDL_Surface *texte;
SDL_Surface *c;
c=IMG_Load("64.jpg");

TTF_Font *police;
SDL_Color color={255,255,255};
police=TTF_OpenFont("ARCADECLASSIC.TTF",40);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
pos.x=500;
pos.y=250;
while(i < 20) { 
 SDL_BlitSurface(c,NULL,screen,NULL);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
texte=TTF_RenderText_Solid(police,chaine,color);
SDL_BlitSurface(texte, NULL, screen, &pos);
SDL_Flip(screen);

  SDL_WaitEvent(&event);
  switch (event.type){
case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{  case SDLK_a:
                    strcat(chaine,"a");
                    break;
                    case SDLK_q:
                    strcat(chaine,"q");
                    break;
                    case SDLK_w:
                    strcat(chaine,"w");
                    break;
                    case SDLK_e:
                    strcat(chaine,"e");
                    break;
                    case SDLK_r:
                    strcat(chaine,"r");
                    break;
                    case SDLK_t:
                    strcat(chaine,"t");
                    break;
                    case SDLK_y:
                    strcat(chaine,"y");
                    break;
                    case SDLK_u:
                    strcat(chaine,"u");
                    break;
                    case SDLK_i:
                    strcat(chaine,"i");
                    break;
                    case SDLK_o:
                    strcat(chaine,"o");
                    break;
                    case SDLK_p:
                    strcat(chaine,"p");
                    break;
                    case SDLK_s:
                    strcat(chaine,"s");
                    break;
                    case SDLK_d:
                    strcat(chaine,"d");
                    break;
                    case SDLK_f:
                    strcat(chaine,"f");
                    break;
                    case SDLK_g:
                    strcat(chaine,"g");
                    break;
                    case SDLK_h:
                    strcat(chaine,"h");
                    break;
                    case SDLK_j:
                    strcat(chaine,"j");
                    break;
                    case SDLK_k:
                    strcat(chaine,"k");
                    break;
                    case SDLK_l:
                    strcat(chaine,"l");
                    break;
                    case SDLK_z:
                    strcat(chaine,"z");
                    break;
                    case SDLK_x:
                    strcat(chaine,"x");
                    break;
                    case SDLK_c:
                    strcat(chaine,"c");
                    break;
                    case SDLK_v:
                    strcat(chaine,"v");
                    break;
                    case SDLK_b:
                    strcat(chaine,"b");
                    break;
                    case SDLK_n:
                    strcat(chaine,"n");
                    break;
                    case SDLK_m:
                    strcat(chaine,"m");
                    break;
                    case SDLK_SPACE:
                    strcat(chaine," ");
                    break;
              case SDLK_RETURN:
                    i=22;
                    break;
                     case SDLK_ESCAPE:
                    SDL_Quit();
                    break;
                     
}


case SDL_KEYUP:
switch (event.key.keysym.sym)
			{  case SDLK_ESCAPE:
                    strcat(chaine,"\0");
                    break;
                 case SDLK_a:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_q:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_w:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_e:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_r:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_t:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_y:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_u:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_i:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_o:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_p:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_s:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_d:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_f:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_g:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_h:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_j:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_k:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_l:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_z:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_x:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_c:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_v:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_b:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_n:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_m:
                    strcat(chaine,"\0");
                    break;
              }
  




}
}
}

void sauvgarder (int score,char nomjoueur[],char nomfichier[])
{
    FILE *fichier = NULL;
    
    fichier = fopen(nomfichier, "a+");
    fprintf(fichier, "%s %d\n", nomjoueur, score);
    fclose(fichier);
}




void sauvegarder1(perso p,backg b,Personne p1) {
FILE *fichier;
save s;
s.p=p;
s.b=b;
s.p1=p1;
fichier=fopen("save_perso","wb");
if (fichier != NULL)
{
    fwrite(&s,sizeof(save),1,fichier);
    printf("game saved\n");
}else printf("failed");


fclose(fichier);

}

int charger (perso *p,backg *b,Personne *p1 ){
    FILE *fichier;
    save s;
    fichier=fopen("save_perso","rb");
    fread(&s,sizeof(save),1,fichier);
    fclose(fichier);
    p->position.x=s.p.position.x;
    p->position.y=s.p.position.y;
    b->pos1.x=s.b.pos1.x;
    b->pos1.y=s.b.pos1.y;
    p1->position_perso.x=s.p1.position_perso.x;
    //p1->position_perso.y=s.p1.position_perso.y;
    
    printf("perso et background chargés\n");
}


