#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

struct image
{
SDL_Rect pos;
SDL_Surface * img ;
};
typedef struct image image ;
//------------------------------------------------
struct enigme
{
image im1,im2,im3,im4,im2o,im3o,im4o;
int res ;
};
typedef struct enigme enigme;
//------------------------------------------------------------------------------------


//initialisation SDL
void initeverything();

//fonctions pour l'initialisation 
void init_background(image *load);
void init_animation_time(image load[]);
void init_image_victoire(image *load);
void init_image_defeat(image *load);

//fonctions pour l'initialisation enigme
void init_images_enigme(image *im,image *imo,char file[],char fich[],char c);
enigme init_enigme();

//fonctions pour l'affichage
void afficherr(image p,SDL_Surface *ecran);
void afficher_enigme(enigme e,SDL_Surface *ecran);
void animation_time(image clock[],int i,SDL_Surface *ecran);


///fonction principale
int enigmee(SDL_Surface *ecran) ;



