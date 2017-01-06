#include "TexturaSDL.h"
#include "JuegoPG.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
using namespace std;



TexturaSDL::TexturaSDL()
{
	width = 0;
	height = 0;
	mov = false;

}
bool TexturaSDL::load(SDL_Renderer* pRenderer, const string& nombArch) {
	//Liberamos la textura preexistente
	SDL_Surface* pTempSurface = nullptr;
	bool success = true;


	//Load image				
	pTempSurface = IMG_Load(nombArch.c_str());
	if (pTempSurface == nullptr) {
		cout << "Unable to load image " << nombArch << "! \nSDL Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		texturas = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		width = pTempSurface->clip_rect.w;
		height = pTempSurface->clip_rect.h;
		rect = pTempSurface->clip_rect;
		success = texturas != nullptr;
	}

	return success;
}

void TexturaSDL::draw(SDL_Renderer* pRenderer, SDL_Rect &rect, SDL_Rect const& rframe) {
	SDL_RenderCopy(pRenderer, texturas, &rframe, &rect);
}
void TexturaSDL::draw(SDL_Renderer* pRenderer, SDL_Rect const& rect) {
	SDL_Rect disrect;
	disrect.x = 0;
	disrect.y = 0;
	disrect.w = width;
	disrect.h = height;
	SDL_RenderCopy(pRenderer, texturas, &disrect, &rect);

}

void TexturaSDL::free() {
	if (texturas != nullptr) {
		SDL_DestroyTexture(texturas);
		texturas = nullptr;
		width = 0;
		height = 0;

	}
}

int TexturaSDL::getHeight() { return height; }
int TexturaSDL::getWidth() { return width; }


TexturaSDL::~TexturaSDL()
{
	free();


}