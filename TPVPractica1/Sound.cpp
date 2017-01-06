//#include "JuegoPG.h"
//#include "SDL.h"
//#include "SDL_mixer.h"
//#include "TexturaSDL.h"
//#include "GlobosPG.h"
//#include <iostream>
//#include "SDL_image.h"
//#include "Sound.h"
//#include <string>
//
//using namespace std;
//
//Sound::Sound(string musica) {
//	initMusica();
//	loadMusic(musica);
//}
//Sound::~Sound() {
//
//}
//bool Sound::initMusica() {
//	Mix_Init(27);
//	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}
//
//void Sound::PlayMusic() {
//	Mix_PlayMusic(music, -1);
//}
//
//bool Sound::loadMusic(string mus) {
//	music = Mix_LoadMUS(mus.c_str());
//
//
//	if (music == nullptr) {
//		return false;
//	}
//	else {
//
//		return true;
//	}
//}
//void Sound::close() {
//	Mix_Quit();
//}