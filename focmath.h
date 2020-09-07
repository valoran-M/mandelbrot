#define PX 900
#define PY 900

typedef struct Z Z;
struct Z
{
	double X;
	double Y;
};

void Plan(SDL_Renderer *renderer, char indice, Z z, int puiss);
void resentrer();
void augmentationIteration();
void diminutionIteration();
void augmentationDistance();
void diminutionDistance();