//María García Raldúa, Javier Landaburu Sánchez
#include "SDL.h"  // Para utilizar SDL
#include "JuegoPG.h"
#include <iostream>  // la consola: cin / cout
using namespace std; // Para cualificar automaticamente con std:: los identificadores de la librería estandar 


int main(int argc, char* args[]) {
	system("chcp 1252");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	JuegoPG* game = new JuegoPG();

	game->run();
	delete game;
	cout << " ¡Error!\n Pulsa ENTER para cerrar";  cin.ignore();
	return 0;
}