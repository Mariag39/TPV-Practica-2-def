#include "GlobosPG.h"
#include "JuegoPG.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;

GlobosPG::GlobosPG(Textura_t text, int x, int y, JuegoPG* juego) : ObjetoPG(juego,text,x,y)
{
	if (rand() % 100 < PVIS) visible = true; else visible = false;
	explotado = false;
	rect.w = 40;
	rect.h = 40;
	desinflado = 5;
	puntos = 0;
	
}

bool GlobosPG::onClick() {
	if (!explotado) {
		  if (ObjetoPG::onClick()){ 
			  visible = false;
			  explotado = true;
			  pJuego->newBaja(this);
			  pJuego->newPuntos(this);
			 
			  
			  return true;
		}
	}
	else return false;
	
}

void GlobosPG::update() {                       
	//actualiza el estado de los globos
	bool destruido = false;
	if (!explotado && visible) {

		if ((rand() % 100 > PDES)) {
			rect.h -= desinflado;
			rect.w -= desinflado;
			puntos += 5;
			if (rect.h <= 0 || rect.w <= 0) {
				visible = false;
				pJuego->newBaja(this);
				destruido = true;
				explotado = true;
			}
		}
	}
	if (!explotado && !visible)
		if (rand() % 100 < PVIS) visible = true; 
		else {
			visible = false;
			//pJuego->newBaja(this);
		}
	//return destruido;
}

int GlobosPG::getPuntos() {
	return puntos;
}


GlobosPG::~GlobosPG()
{
	
	
}
