#pragma once
#include "SDL.h"
#include <string>
using namespace std;

class TexturaSDL
{


public:
	TexturaSDL();
	~TexturaSDL();
	void free();
	bool load(SDL_Renderer* pRenderer, string const& nombArch);
	void draw(SDL_Renderer* pRenderer, SDL_Rect &rect, SDL_Rect const& rframe);
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);
	
	int getWidth();
	int getHeight();
	
	//bool load(SDL_Renderer*, string const& nombArch, SDL_Color const& colKey)
	// static SDL_Surface* load(string nombreArchivo)
private:
	SDL_Texture* texturas;
	SDL_Rect rect;
	int width;
	int height;
	bool mov;

};

