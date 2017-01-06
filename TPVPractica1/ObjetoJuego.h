#pragma once
#ifndef _H_ObjetoJuego_H_
#define _H_ObjetoJuego_H_
class ObjetoJuego
{
public:

	ObjetoJuego()
	{
	}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool onClick() = 0;

	virtual ~ObjetoJuego()
	{
	}
};
#endif

