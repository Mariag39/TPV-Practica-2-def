#include "Mariposa.h"


Mariposa::Mariposa(Textura_t text, int x, int y, JuegoPG* juego): ObjetoPG(juego,text,x,y)

{
	frames = 14;
	visible = true;
	puntos = 0;
	actframe = 1;
	velx = -5;
	vely = -5;
	clicks = 0;
	rect.w = 72;
	rect.h = 72;

	rframe.x = 0;
	rframe.y = 0;
	rframe.w = 979 / 14;
	rframe.h = 72;
}
void Mariposa::draw() {
	
	pJuego->getTextura(texturas)->draw(pJuego->getRender(), rect, rframe);
}
void Mariposa::movimiento() {
	pJuego->random(rect.x, rect.y);
}
bool Mariposa::onClick() {
	if (ObjetoPG::onClick()) {
		clicks++;
		movimiento();
		if (clicks == 3) {
			pJuego->newPremio();
			clicks = 0;
		}

	}
	else {
		return false;
	}
}
void Mariposa::update() {
	rframe.x = (974 / 14)*(actframe%frames);

	actframe++;
	if (actframe < frames - 1)actframe++;
	else actframe = 0;

	
	/*rect.x += velx;
	rect.y += vely;
	if (actframe < frames - 1)
		actframe++;
	else actframe = 0;*/
}

Mariposa::~Mariposa()
{

}
