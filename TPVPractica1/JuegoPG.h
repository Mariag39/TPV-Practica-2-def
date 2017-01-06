#pragma once
#include "SDL.h"
#include <vector>
#include "SDL_image.h"
#include "Sound.h"
#include "TexturaSDL.h"
#include "ObjetoJuego.h"
using namespace std;


enum Textura_t { TFondo, TGlobo, TPremio, TMariposa };
class JuegoPG
{
	
public:
	JuegoPG();
	~JuegoPG();
	void run();
	void onExit();
	
	TexturaSDL* getTextura(Textura_t et) const;
	SDL_Renderer* getRender() const { 
		return pRenderer;
	};
	void random(int& x, int& y);
	void getMousePos(int& mpx, int& mpy) const;
	void newBaja(ObjetoJuego* po); // Los objetos informarán al juego cuando causen baja  
	void newPuntos(ObjetoJuego* po); // Los objetos informarán al juego cuando se obtengan puntos 
	void newPremio(); // Los objetos informará al juego cuando se obtenga un premio 
	void initMedia(); // carga las texturas en el vector de texturas (fuente y música)  
	void freeMedia();
	

private:
	int x;
	int y;
	int premios;
	int numMariposas;
	bool initObjetos();
	bool initSDL();
	Textura_t texturas;
	vector<string> nombarch;
	void closeSDL();
	void Mensaje(string msg1, string msg2);
	void render() ;
	void onClick();
	void update();
	void handle_event();
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_Texture* pTexture;
	vector<TexturaSDL*> objetostext;
	vector<ObjetoJuego*> objetosvec; //era GlobosPG
	const int SCREEN_WIDTH = 640;   //Screen dimension
	const int SCREEN_HEIGHT = 480;  //Screen dimension
	
	
	bool error;
	bool exit;
	bool gameOver;
	int punts;
	int numGlobos;

};

