#pragma once
#ifndef _H_GlobosPG_H_
#define _H_GlobosPG_H_
#include "SDL.h"
#include "TexturaSDL.h"
#include <vector>
#include "ObjetoPG.h"

	
using namespace std;
class GlobosPG : public ObjetoPG
{


public:
	GlobosPG(Textura_t text, int x, int y, JuegoPG* juego);
	~GlobosPG();
	
	bool onClick();
	virtual int getPuntos();
	virtual void update();
	int puntos;
	


protected:
	float desinflado;
	
	bool explotado;
	const int PVIS = 20;
	const int PDES = 50;
	SDL_Renderer* pRenderer;
	
};
#endif

