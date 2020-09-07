#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "focmath.h"
#define ITERATION 57
#define DISTANCE 10

int iteration = ITERATION;
int distanceMax = DISTANCE;

double Xmin = -2, Xmax = 2, Ymin = -2, Ymax = 2;

double X(int pX)
{
	return ((pX * (Xmax - Xmin)) / PX ) + Xmin;
}

/////////////////
//Convertion de//
//pixel en     //
//coordonnées  //
/////////////////

double Y(int pY)
{
	return ((pY - PY) * -(Ymax - Ymin)) / PY + Ymin;
}

double distance(Z z)
{
	return sqrt((z.X * z.X) + (z.Y * z.Y));
}

/*
Multiplication
de deux nombre complexe
*/
Z mult(Z z1, Z z2)
{
	Z zResult;
	zResult.X = z1.X * z2.X - z1.Y * z2.Y;
	zResult.Y = z1.X * z2.Y + z1.Y * z2.X;
	return zResult;
}

/*
addition de deux nombre complexe
*/
Z add(Z z1, Z z2)
{
	Z zResult;
	zResult.X = z1.X + z2.X;
	zResult.Y = z1.Y + z2.Y;
	return zResult;
}

void Colorier(int pX, int pY, SDL_Color couleur, SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, couleur.r, couleur.g, couleur.b, couleur.a);
	SDL_RenderDrawPoint(renderer, pX, pY);
}

void resentrer()
{
	Xmin = -2, Xmax = 2, Ymin = -2, Ymax = 2;
}

///////////////
//applique la//
//suite et   //
//la teste   //
///////////////
int teste(Z zTeste, char indice, Z z, int puiss)
{
	int i;
	for (i = 0; i < iteration; i++)
	{
		if(indice == 'm')
		{
			if(puiss == 1)
			{
				z = add(z, zTeste);
			}
			else if(puiss == 2)
			{
				z = add(mult(z, z), zTeste);
			}
			else if(puiss == 3)
			{
				z = add(mult(z, mult(z, z)), zTeste);
			}
			else if(puiss == 4)
			{
				z = add(mult(mult(z, z), mult(z, z)), zTeste);
			}
			else if(puiss == 5)
			{
				z = add(mult(mult(mult(z, z), mult(z, z)), z), zTeste);
			}
			else if(puiss == 6)
			{
				z = add(mult(mult(mult(z, z), mult(z, z)), mult(z, z)), zTeste);
			}
			else if(puiss == 7)
			{
				z = add(mult(mult(mult(mult(z, z), mult(z, z)), mult(z, z)), z), zTeste);
			}
			else if(puiss == 8)
			{
				z = add(mult(mult(mult(mult(z, z), mult(z, z)), mult(z, z)), mult(z, z)), zTeste);
			}
			else if(puiss == 9)
			{
				z = add(mult(mult(mult(mult(mult(z, z), mult(z, z)), mult(z, z)), mult(z, z)), z), zTeste);
			}

			if (distance(z) >= distanceMax)
				return i;
			
		}
		else if(indice == 'j')
		{
			zTeste = add(mult(zTeste, zTeste), z);

			if(distance(zTeste) >= distanceMax)
				return i;
		}
		
	}
	return 0;
}

/////////////////////
//coloriage du plan//
/////////////////////
void Plan(SDL_Renderer *renderer, char indice, Z z, int puiss)
{
	////////////////////////
	//	Défintion de 	  //
	// toutes les couleurs//
	////////////////////////
	SDL_Color couleur[1792];
	for (int i = 0; i < 256; i++)
	{	
		// noir vers magenta
		couleur[i].r = i;
		couleur[i].g = 0;
		couleur[i].b = i;
		couleur[i].a = 255;
		// magenta vers bleu
		couleur[i + 256].r = 255 - i;
		couleur[i + 256].g = 0;
		couleur[i + 256].b = 255;
		couleur[i + 256].a = 255;
		// bleu ver cyan
		couleur[i + 512].r = 0;
		couleur[i + 512].g = i;
		couleur[i + 512].b = 255;
		couleur[i + 512].a = 255;
		// cyan ver vert
		couleur[i + 768].r = 0;
		couleur[i + 768].g = 255;
		couleur[i + 768].b = 255 - i;
		couleur[i + 768].a =255; 
		// vert vers jaune
		couleur[i + 1024].r = i;
		couleur[i + 1024].g = 255;
		couleur[i + 1024].b = 0;
		couleur[i + 1024].a = 255;
		// jaune vers rouge
		couleur[i + 1280].r = 255;
		couleur[i + 1280].g = 255 - i;
		couleur[i + 1280].b = 0;
		couleur[i + 1280].a = 255;
		// rouge vers noir
		couleur[i + 1536].r = 255 - i;
		couleur[i + 1536].g = 0;
		couleur[i + 1536].b = 0;
		couleur[i + 1536].a = 255;
	}
	// Pour chaque point du plan
	int pX, pY, i;
	Z zTeste;
	for(pX = 0; pX <= PX; pX++)
	{
		for (pY = 0; pY < PY; pY ++)
		{
			i = 0;
			zTeste.X = X(pX);
			zTeste.Y = Y(pY);
			i = teste(zTeste, indice, z, puiss);
			Colorier(pX, pY, couleur[(i * (1792 / iteration)) % 1792], renderer);
		}
	}
}

void augmentationIteration()
{
	iteration = iteration * 2;
}

void diminutionIteration()
{
	iteration = iteration / 2 ;
}

void augmentationDistance()
{
	distanceMax = distanceMax + 1;
}

void diminutionDistance()
{
	distanceMax = distanceMax - 1;
}