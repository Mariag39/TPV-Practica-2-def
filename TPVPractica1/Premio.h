#pragma once

#include "ObjetoPG.h"
#include "SDL.h"



class Premio : public ObjetoPG
{
public:
	Premio(Textura_t text, int x, int y, JuegoPG* pJuego);
	virtual ~Premio();
	bool onClick();
	int getPuntos();
	virtual void update();
	int pp;

private:
	int ini = 15;
	void reinicio();
	int oport;
};

