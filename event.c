#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "focmath.h"


//////////////////////////////
/*	fonction sur toutes les	*/
/*	facon dessiner les Plan */
//////////////////////////////

void dessin(SDL_Renderer *renderer, char indice, Z z, int puiss)
{
	if(indice == 'm')
	{
		Z z = {0 , 0};
		Plan(renderer, indice, z, puiss);
		SDL_RenderPresent(renderer);
	}
	else if(indice == 'j')
	{
		Plan(renderer, indice, z, puiss);
		SDL_RenderPresent(renderer);
	}
}

void event(SDL_Renderer *renderer)
{
	int quiter = 1;
	char indice;
	int indiceDeZ = 0;
	int puiss = 2;
	SDL_Event event;
	Z zm = {0, 0};
	Z z[9];
	z[0].X = 0.3, z[0].Y = 0.5;
	z[1].X = 0.285, z[1].Y = 0.01;
	z[2].X = -1.417022285618, z[2].Y = 0.0099534;
	z[3].X = -0.038088 , z[3].Y = 0.9754633;
	z[4].X = 0.285, z[4].Y = 0.013;
	z[5].X = 0.285, z[5].Y = 0.01;
	z[6].X = -1.476, z[6].Y = 0;
	z[7].X = -0.4, z[7].Y = 0.6;
	z[8].X = -0.8, z[8].Y = 0.156;
	while(quiter)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				quiter = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						quiter = 0;
						break;
					// détecton de la touche m pour dessiner les plan de mandelbrot
					case SDLK_m:
						indice = 'm';
						dessin(renderer, indice, zm, puiss);
						break;
					//détection de la youche j pour dessiner le plan de julia et les faire varier
					case SDLK_j:
						if(indice != 'j')
						{	
							indice = 'j';
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						else if(indice == 'j')
						{
							indiceDeZ = (indiceDeZ + 1) % 9;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					// ressentrer le plan
					case SDLK_r:
						resentrer();
						dessin(renderer, indice, z[indiceDeZ], puiss);
						break;
					//flêche dirrectionnel haut bas pour augmenter ou diminuer les iteration
					case SDLK_UP:
						augmentationIteration();
						dessin(renderer, indice, z[indiceDeZ], puiss);
						break;
					case SDLK_DOWN:
						diminutionIteration();
						dessin(renderer, indice, z[indiceDeZ], puiss);
						break;
					//flêche directionnel droite gzuche pour augmenter la distance maximal d'un point
					case SDLK_RIGHT:
						augmentationDistance();
						dessin(renderer, indice, z[indiceDeZ], puiss);						
						break;
					case SDLK_LEFT:
						diminutionDistance();
						dessin(renderer, indice, z[indiceDeZ], puiss);						
						break;
					//gestion des puissances pour le plan de mandelbroth
					case SDLK_1:
						if(indice == 'm')
						{
							puiss = 1;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					case SDLK_2:
						if(indice == 'm')
						{
							puiss = 2;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					case SDLK_3:
						if(indice == 'm')
						{
							puiss = 3;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					case SDLK_4:
						if(indice == 'm')
						{
							puiss = 4;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					case SDLK_5:
						if(indice == 'm')
						{
							puiss = 5;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					case SDLK_6:
						if(indice == 'm')
						{
							puiss = 6;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					case SDLK_7:
						if(indice == 'm')
						{
							puiss = 7;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					case SDLK_8:
						if(indice == 'm')
						{
							puiss = 8;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
					case SDLK_9:
						if(indice == 'm')
						{
							puiss = 9;
							dessin(renderer, indice, z[indiceDeZ], puiss);
						}
						break;
				}
			break;
		}
	}
}