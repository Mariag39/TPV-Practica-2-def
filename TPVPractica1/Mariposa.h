#pragma once
#ifndef _H_Mariposa_H_
#define _H_Mariposa_H_
#include "ObjetoPG.h"
#include "SDL.h"
#include "TexturaSDL.h" // pregunta pero yo creo que si hace falta, el draw lo necesiará,no?


class Mariposa : public ObjetoPG
{
public:
	Mariposa(Textura_t text, int x, int y, JuegoPG* juego);
	virtual ~Mariposa();
	void draw();
	bool onClick();
	virtual void update();
	bool visible;
private:
	SDL_Rect rframe;
	int clicks;
	int frames;
	int actframe;
	int velx, vely;
	int puntos;
	void movimiento();
};
#endif