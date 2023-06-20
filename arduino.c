#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "image.h"
#include "enigme.h"


int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}


int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}


/*--------------------------------------------------------------*/




void getInput(Input *input,int *pause)
{
int received;	
//in->right=0;
//input from arduino
// partie update relative au actions des bouttons
arduinoReadData(&received);
          
	//printf("%d",received);
          	
          	switch(received)
          	{
          			
          			case 1:
          			 input->right = 1;
          			break;
          			case 2:
          			input->left = 1;
          			break;

         			case 0:

          			input->right = 0;
          			input->left = 0;
          			
          			break;
          	}

SDL_Event event;


    SDL_PollEvent(&event);
    
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        *pause=1;
                    break;

                    case SDLK_LEFT:
                        input->left = 1;
                    break;

                    case SDLK_RIGHT:
                        input->right = 1;
                    break;

                    case SDLK_DOWN:
                        input->down = 1;
                    break;

                    case SDLK_UP:
                        input->up = 1;
                    break;

                    case SDLK_SPACE:
                        input->jump = 1;
                    break;
		    case SDLK_p:
			input->attack= 1;
		    break;
		    case SDLK_LALT:
                    	input->speed = 1;
                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                    case SDLK_LEFT:
                        input->left = 0;
                    break;

                    case SDLK_RIGHT:
                        input->right = 0;
                    break;

                    case SDLK_DOWN:
                        input->down = 0;
                    break;

                    case SDLK_UP:
                        input->up = 0;
                    break;

                    case SDLK_SPACE:
                        input->jump= 0;
                    break;
	            case SDLK_LALT:
                    	input->speed = 0;
                    break;
		    case SDLK_p:
			input->attack=0;
	   	    break;
                    default:
                    break;
                }
            break;


        }

    }

