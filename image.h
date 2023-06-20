#ifndef Image_H
#define Image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL_ttf.h"
#include <time.h>
#define SCREEN_W 640
#define SCREEN_H 360
#define maxw 1366
#define maxh 768

#define wicked 0.5
#define micked 0.05

#define POS_X_PERSO 0
#define POS_Y_PERSO 250

#define POS_X_PERSO2 300
#define POS_Y_PERSO2 250

#define W_PERSO 66
#define H_PERSO 95
#define POS_X_WALK_DROITE 0
#define POS_Y_WALK_DROITE 194.5
#define POS_Y_WALK_GAUCHE 291.75
#define POS_Y_WALK_UP 0
#define POS_Y_WALK_DOWN 97.25
#define MAX_FRAMES 5

#define POS_X_VIE 0
#define POS_Y_VIE 10
#define H_VIE 38


typedef struct {
    SDL_Rect pos1;
    SDL_Rect pos2;
    SDL_Surface * img;
}Image;

typedef struct { 
SDL_Rect position; 
//TTF_Font *font; 
SDL_Surface * surfaceTexte; 
SDL_Color textColor; 
char texte [20]; 
} Text;

struct txt
{
SDL_Rect pos;
SDL_Surface *t ;
TTF_Font *p;

};
typedef struct txt txt ;


typedef struct
{
	SDL_Rect position_perso;
	SDL_Surface *sprite;
} Personne;

typedef struct
{
	SDL_Rect position_mini;
	SDL_Surface *sprite;
} minimap;

typedef struct temps
{
	SDL_Surface *texte;
	SDL_Rect position;

	TTF_Font *police;

	char entree[100];
	int secondesEcoulees;
	SDL_Color couleurBlanche;
	time_t t1, t2;
	int min, sec;
} temps;
/*-----------------------------------------------------------------------*/


//------------------PARTIE BACKG-----------------------------*/

typedef struct
{
	SDL_Rect pos1; //fin theb taffichi el taswira
	SDL_Rect camera; //kadech theb twari mel taswira
	SDL_Surface *img;  //etaswira
	SDL_Rect pos2; //position du mask
}backg;

//------------------PARTIE BACKG-----------------------------*/

//--------------------------------PARTIE PERSO----------------------------//
typedef struct 
{
int x;
SDL_Rect position;
SDL_Rect frame;
SDL_Surface *image;
int curframe;
int direction; 	
int running;
int previousmvt;
double acceleration;
double decelere;
double vitesse;
double v_x;
double v_grav ;
double v_saut ;
double v_y ;		
}perso;

//--------------------------------PARTIE PERSO----------------------------//

typedef struct
{
SDL_Rect position;
SDL_Rect frame;
SDL_Surface *image;
int curframe;
}vie;

struct Input
{	int left,right,up,down,jump,resume,speed,attack;
};

typedef struct Input Input;

//-------------------------PARTIE XO-------------------------------//
typedef struct
{
SDL_Surface *table;
SDL_Surface *bg;
SDL_Surface *t[2];
int i[3][3];
SDL_Rect r[3][3];
int turn;
int choixx;
int choixy;
}xo;

//-------------------------PARTIE XO-------------------------------//

//-------------------PARTIE ENTITE SECONDAIRE----------------------//
#define wicked 0.5
#define micked 0.05

typedef struct ennemi{
SDL_Surface *sprite; 
int  direction;
int time,nbr;
SDL_Rect posscreen;
SDL_Rect possprite;
SDL_Rect pos1,pos2;
}ennemi;
typedef struct ennemi ennemi;

typedef struct coin{
SDL_Surface *sprite; 
int  direction;
int time,nbr;
SDL_Rect posscreen;
SDL_Rect possprite;
SDL_Rect pos1,pos2;
}coin;
typedef struct coin coin;


typedef struct save
{
  
  perso p;
  backg b;
  Personne p1;
}save;


//------------------------------------------------------------------------------------

//-------------------PARTIE ENTITE SECONDAIRE----------------------//

//void initPlayer(Image *A);

//initiatlisation de base
void initmenu(Image Menu[],char animation[]);
void initStart(Image *Start);
void initSett(Image *Sett);
void initQuit(Image *Quit);
void initStart2(Image *Start2);
void initSett2(Image *Sett2);
void initQuit2(Image *Quit2);
void initmenu2(Image *menu);
void initcredit(Image *credit);
void initcredit2(Image *credit2);
void initb(Image *b);
void initt(Image *t);
void initvol(Image *vol);
void initsfx(Image *sfx);
void initmusic_sound(Image c[],Image variable[]);

//animation avant menu
void initanim(Image anim[],char anima[]);

void initText(Text *A); 

//affichage

void displayText(Text t,SDL_Surface *screen) ;
void afficher(Image p,SDL_Surface *screen);

//liberation

void liberers(SDL_Surface *screen);
void freeText(Text A); 
void liberer(Image A);
void libererm(Image anim[],int n);

//SETTINGS 

void option(SDL_Surface *ecran);
void initmenus2(Image Menus[],char animations[]);
void initbarre(Image c[],Image variable[]);
void initf(Image *f);
void initf2(Image *f2);
int options(SDL_Surface *screen, int vol );
void initv(Image *v);
void initv_1(Image *v_1);
void initv_2(Image *v_2);
void initv_3(Image *v_3);
void initv_4(Image *v_4);
void initv2(Image *v2);
void initv2_1(Image *v2_1);
void initv2_2(Image *v2_2);
void initv2_3(Image *v2_3);
void initv2_4(Image *v2_4);

//play

/*----------premiere partie(ouverture de la fenetre single/multi)-----------*/

void play(SDL_Surface *ecran,int *continuer);
void initsingle(Image *single);
void initmulti(Image *multi);
void initsingle2(Image *single2);
void initmulti2(Image *multi2);

/*----------deuxieme partie(ouverture de la fenetre jeu)-----------*/

void initmenus(Image *s);
void start(SDL_Surface *ecran);
void start1(SDL_Surface *ecran);
void initialiser_Perso(perso * p);
void initialiser_Perso2(perso * p);
void afficherPerso (perso * p,SDL_Surface *screen);
void saut(perso *p, SDL_Event ev,SDL_Surface* screen);
int deplacer_perso(perso *p ,SDL_Surface* screen,SDL_Event event);
int deplacer_perso2(perso *p ,SDL_Surface* screen,SDL_Event ev);
void animer_perso(perso *p ,SDL_Surface* screen);
void getInput(Input *input,int *pause);

//vie
void initialiser_vie(vie *v);
void initvie(Image *v);
void initvie0(Image *v0);
void initvief(Image *vf);
void initviemeh(Image *vm);
void afficher_vie(vie *v,SDL_Surface *screen);
void changer_vie(perso *p,vie *v ,int collision,SDL_Surface* screen);

//score
void init_txt_score(txt *txt,int score);
void afficher_txt(txt te,SDL_Surface *ecran);

//perso 2
void initialiser_Perso1(perso * p);
void afficherPerso1 (perso * p,SDL_Surface *screen);
void saut1(perso *p, SDL_Event ev,SDL_Surface* screen);
int deplacer_perso1(perso *p ,SDL_Surface* screen,SDL_Event event);
void animer_perso1(perso *p ,SDL_Surface* screen);
void libererp(perso A);

//credit
void initmenuc(Image *c);
void creditt(SDL_Surface *ecran);

//backg animer
void start2(SDL_Surface *ecran);
void initbackgroundanimer(Image Menus[],char animations[]);

//entite secondaire
void initennemi(ennemi *e);
void afficherennemi(ennemi *e,SDL_Surface *screen);


void initfinn(Image *fi);

//--------------------------MINIMAP-INTEGRATION-----------------------------------
void initmap(minimap *m);
void afficherminimap(minimap m, SDL_Surface *screen);
void free_minimap(minimap *m);
void majminimap (Personne *p, minimap *m ,int direction ,int redimensionnement);
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t, SDL_Surface *ecran);
void sauvegarder( int score, char nomjoueur[], char nomfichier[],char nomfichier2[]);
void meilleur( char nomfichier[],char nomfichier2[], int *score, char nomjoueur[]);

//-------------------------ENTITE SECONDAIRE-----------------------------------//
void initennemi(ennemi *e);
void afficherennemi(ennemi *e,SDL_Surface *screen);
//void liberer(ennemi *a);
void animer(ennemi *e);
void deplace(ennemi *e);
void deplacement(ennemi *e);
void initcoin(coin *e);
void affichercoin(coin *e,SDL_Surface *screen);
void animerc(coin *e);
void deplacementcoin(coin *c);
int collision_enemy_perso(perso perso, ennemi e);

int game(SDL_Surface *screen,int *done);
void deplacerIA( ennemi * e, perso perso );





//----------------------PARTIE BACKG----------------------------------------*/
void initbackg(backg *back);

void initbackg2(backg *back);

void afficherbackg(backg back,SDL_Surface *screen);

void afficher2(backg back,SDL_Surface *screen);

void scroling(backg *back,int scrolling,backg *mask,backg *back2);

SDL_Color GetPixel(SDL_Surface *Background, int x, int y);

int collisionPP(perso p, backg mask);


//partage d'ecran
void initbackg3(backg *back2);
void afficher3(backg back3,SDL_Surface *screen);


void playername(SDL_Surface *screen , char chaine[50]);
void sauvgarder (int score,char nomjoueur[],char nomfichier[]);

void sauvegarder1(perso p,backg b,Personne p1) ;
int charger (perso *p,backg *b,Personne *p1 );
//-----------------------------------MANETTE---------------------------------*/
int arduinoReadData(int *x);
int arduinoWriteData(int x);


void page1(SDL_Surface *ecran);

#endif 
