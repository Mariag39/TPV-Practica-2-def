#ifndef _H_ObjetoPG_H_
#define _H_ObjetoPG_H_
#include "ObjetoPG.h"

using namespace std;


ObjetoPG::ObjetoPG(JuegoPG* juego, Textura_t text, int x, int y)
{
	pJuego = juego;
	texturas = text;
	rect.x = x;
	rect.y = y;

}
bool ObjetoPG::dentro(int x, int y) const {
	
	
	return (x >= rect.x && x <= (rect.x + rect.w) && y >= rect.y && y <= (rect.y + rect.h));
	
}

bool ObjetoPG::onClick() {
	int pmx;
	int pmy;
	pJuego->getMousePos(pmx, pmy);
	return dentro(pmx, pmy);
}
void ObjetoPG::draw() {
	if(visible)
		pJuego->getTextura(texturas)->draw(pJuego->getRender(), rect);
   
}

ObjetoPG::~ObjetoPG()
{
}

#endif
