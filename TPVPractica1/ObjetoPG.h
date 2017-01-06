#pragma once
#include "ObjetoJuego.h"
#include "SDL.h"
#include "JuegoPG.h"


class ObjetoPG :	public ObjetoJuego
{
public:
	ObjetoPG();
	ObjetoPG(JuegoPG* juego, Textura_t text, int x, int y);
	virtual bool dentro(int x, int y) const;	
	virtual void draw();
	virtual bool onClick();
    ~ObjetoPG();
	bool visible;
private: 
	
	
	

protected:
	int pmx;
	int pmy;
	int alto;
	int ancho;
	SDL_Rect rect;
	JuegoPG* pJuego;
	Textura_t texturas;
	
};


