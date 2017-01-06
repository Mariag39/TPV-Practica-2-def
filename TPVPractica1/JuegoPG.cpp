#include "JuegoPG.h"
#include "SDL.h"
#include "Sound.h"
#include "TexturaSDL.h"
#include "GlobosPG.h"
#include "Premio.h"
#include "Mariposa.h"
#include <iostream>
#include "SDL_image.h"
#include <vector>
#include <time.h>
using namespace std;

JuegoPG::JuegoPG()
{
	//inicializar vectores
	srand(SDL_GetTicks());
	if (initSDL()) {
		error = false;
	}
	else {
		error = true;
	}
	
	
	

	gameOver = false;

	punts = 0;
	numMariposas = 1;
	premios = numMariposas;
	numGlobos = 20;
	exit = false;
	nombarch.emplace_back("..\\bmps\\sky.png");
	nombarch.emplace_back("..\\bmps\\yellow.png");
	nombarch.emplace_back("..\\bmps\\premio.png");
	nombarch.emplace_back("..\\bmps\\mariposa.png");
	
	
	

}
void JuegoPG::Mensaje(string msg1, string msg2) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
		msg1.c_str(), msg2.c_str(), nullptr);
}

bool JuegoPG::initSDL() {
	bool success = true; //Initialization flag


						 //Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;

	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWindow = SDL_CreateWindow("SDL Práctica 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr) {
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (pRenderer == nullptr) {
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}
void JuegoPG::closeSDL() {

	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}
void JuegoPG::render()  {
	//Clear the window to background color 
	SDL_RenderClear(pRenderer);

	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	SDL_Rect rect;
	rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	objetostext[TFondo]->draw(pRenderer, rect);
	for (int i = 0; i < objetosvec.size(); i++) {
		objetosvec[i]->draw();
	}

	//Show window																			
	SDL_RenderPresent(pRenderer);
}
void JuegoPG::initMedia() {
  
	for (int i = 0; i < 4; i++) {
		objetostext.push_back(new TexturaSDL());
		objetostext[i]->load(pRenderer, nombarch[i]);
	}
}
TexturaSDL* JuegoPG::getTextura(Textura_t et) const{
	return objetostext[et];
}
void JuegoPG::random(int& x, int& y) {
	y = rand() % SCREEN_HEIGHT;
	x = rand() % SCREEN_WIDTH;
	if (y > SCREEN_HEIGHT - 100) y = SCREEN_HEIGHT - 100;
	if (x > SCREEN_WIDTH - 100) x = SCREEN_WIDTH - 100;

}
bool JuegoPG::initObjetos(){
	
	int x;
	int y;
	for (int i = 0; i < numGlobos; i++) {

		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		objetosvec.push_back(new GlobosPG(TGlobo,x, y, this));
	}
	for (int i = 0; i < numMariposas; i++) {

		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		objetosvec.push_back(new Mariposa(TMariposa,x, y, this));
	}
	x = rand() % (SCREEN_HEIGHT - 5);
	y = rand() % (SCREEN_WIDTH - 5);
	objetosvec.push_back(new Premio(TPremio,x, y, this));
	return true;
  }

void JuegoPG::freeMedia() {
	for (unsigned int i = 0; i < objetosvec.size(); i++) {
		if (objetosvec[i] != nullptr) {
			delete objetosvec[i];
			
		}
	}
	for (unsigned int i = 0; i < objetostext.size(); i++) {
		delete objetostext[i];
		
	}
}
void JuegoPG::onClick(){
	bool pinchado = false;
	for (int i = objetosvec.size() - 1; i >= 0; i--) {
		if (objetosvec[i]->onClick()) {
			pinchado = true;
		}
	}
}
void JuegoPG::getMousePos(int& mpx, int& mpy) const{
	mpx = x;
	mpy = y;
}
void JuegoPG::newBaja(ObjetoJuego* po){
	if (dynamic_cast<GlobosPG*>(po)){
		numGlobos--;
		
	}
	
	else if (dynamic_cast<Premio*>(po)){
		dynamic_cast<Premio*>(po)->visible = false;
	}
}
void JuegoPG::newPuntos(ObjetoJuego* po) {
	if (dynamic_cast<GlobosPG*>(po)) {
		punts += dynamic_cast<GlobosPG*>(po)->getPuntos();
	}
	else if (dynamic_cast<Premio*>(po)) {
		punts += dynamic_cast<Premio*>(po)->getPuntos();
	}

}
void JuegoPG::newPremio(){ 

		dynamic_cast<Premio*>(objetosvec[objetosvec.size() - 1])->visible = true;
	
}

void JuegoPG::update() {
	for (int i = 0; i < objetosvec.size(); ++i) {
		objetosvec[i]->update();
	}
	if (numGlobos <= 0) {
		gameOver = true;
	}
}

void JuegoPG::onExit() {
	exit = true;
	cout << "EXIT ";
}
void JuegoPG::run() {
	if (!error) {
		Uint32 MSxUpdate = 500;
		cout << "PLAY\n";
		Uint32 lastUpdate = SDL_GetTicks();
		Mensaje("PLAY","Ready?");
		initMedia();
		initObjetos();
		render();
		handle_event();
		while (!exit && !gameOver) {
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate) {
				update();
				lastUpdate = SDL_GetTicks();
			}
			render();
			handle_event();
		}

		if (exit || gameOver) {
			string puntuacion = to_string(punts);
			Mensaje("Game Over", "Puntuacion: " +puntuacion);
			closeSDL();
			cout << "\nHas obtenido " << punts << " puntos\n";
		}
		/*music->close();*/
		SDL_Delay(1000);
		
		cin.get();
	}
}

void JuegoPG::handle_event() {
	SDL_Event e;
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) {
			onExit();
		}
	else if (e.type == SDL_MOUSEBUTTONUP) {
		if (e.button.button == SDL_BUTTON_LEFT) {
			cout << "CLICK";
			x = e.button.x;
			y = e.button.y;
			onClick();
		}
	}
}
}


JuegoPG::~JuegoPG()
{
	freeMedia ();
	closeSDL();
	
	
}
