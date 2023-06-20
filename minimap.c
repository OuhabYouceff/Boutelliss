#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"

/*------------------------------------------initialisation----------------------------------------*/
void initmap(minimap *m)
{
    m->position_mini.x = 0;
    m->position_mini.y = 0;				
    m->sprite = NULL;
    m->sprite = IMG_Load("minimap1.png");
}


void initialiser_temps(temps *t)
{
    t->texte = NULL;
    t->position.x = 1390;
    t->position.y = 15;
    t->police = NULL;
    t->police = TTF_OpenFont("MarkerNo3HUN-Drip.ttf",70);
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



/*--------------------------------------------------------Fonction Colision------------------------------------------*/

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


int collisionPP(Personne p, SDL_Surface *Masque)
{
    SDL_Color test, couleurnoir = {255, 0, 0};

    SDL_Rect pos[8];
    
    pos[0].x = p.position_perso.x;
    pos[0].y = p.position_perso.y;
    pos[1].x = p.position_perso.x + p.position_perso.w / 2;
    pos[1].y = p.position_perso.y;
    pos[2].x = p.position_perso.x + p.position_perso.w;
    pos[2].y = p.position_perso.y;
    pos[3].x = p.position_perso.x;
    pos[3].y = p.position_perso.y + p.position_perso.h / 2;
    pos[4].x = p.position_perso.x;
    pos[4].y = p.position_perso.y + p.position_perso.h;
    pos[5].x = p.position_perso.x + p.position_perso.w / 2;
    pos[5].y = p.position_perso.y + p.position_perso.h;
    pos[6].x = p.position_perso.x + p.position_perso.w;
    pos[6].y = p.position_perso.y + p.position_perso.h;
    pos[7].x = p.position_perso.x + p.position_perso.w;
    pos[7].y = p.position_perso.y + p.position_perso.h / 2;
    
    int collision = 0, x, y;

    for (int i = 0; i < 8 && collision == 0; i++)
    {
        x = pos[i].x;
        y = pos[i].y;
        
        test = GetPixel(Masque, x, y);
        
        if (test.r == 0 && test.g == 0 && test.b == 0)
            collision = 1;
    }
    return collision;
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

void sauvegarder( int score, char nomjoueur[], char nomfichier[],char nomfichier2[])
{   
FILE *f=NULL,*f2=NULL ;
   f=fopen(nomfichier,"w");
   f2=fopen(nomfichier2,"w");

  fprintf(f,"%d",score);
  fprintf(f2,"%s",nomjoueur);
  fclose(f);
  fclose(f2);

}


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

