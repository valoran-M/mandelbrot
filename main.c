#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "focmath.h"


int main(int argc, char const *argv[])
{
	//////////////////////////////
	/* 		Initilisation 		*/
	/*		de la fenêtre		*/
	//////////////////////////////
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stdout, "Echec de l'initilisation de la SDL (%s)\n", SDL_GetError());
		goto Quit;
	}
	SDL_Window *pWindow = NULL;
	pWindow = SDL_CreateWindow("Mandelbrot", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, PX, PY, SDL_WINDOW_SHOWN);

	if (pWindow == NULL)
	{
		fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
		goto Quit;
	}

	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_SOFTWARE);
	if(renderer == NULL)
	{
		fprintf(stderr, "Erreur de la création du render: %s\n", SDL_GetError());
		goto Quit;
	}

	event(renderer);

Quit:
	
	if(pWindow != NULL)
	{
		SDL_DestroyWindow(pWindow);
	}
	if(renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}
	SDL_Quit();

	return 0;
}