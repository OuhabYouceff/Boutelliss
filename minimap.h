#ifndef minimap_H
#define minimap_H
#include <time.h>

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

void initmap(minimap *m);
void afficherminimap(minimap m, SDL_Surface *screen);
void free_minimap(minimap *m);
void majminimap (Personne *p, minimap *m ,int direction ,int redimensionnement);
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t, SDL_Surface *ecran);
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP(Personne p, SDL_Surface *Masque);
void sauvegarder( int score, char nomjoueur[], char nomfichier[],char nomfichier2[]);
void meilleur( char nomfichier[],char nomfichier2[], int *score, char nomjoueur[]);
#endif
