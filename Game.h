
#ifndef Game_H
#define Game_H
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>


class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, int fullscreen);
	void update();
	void HandleEvent();
	void render();
	void clean();
	bool running() 
	{
		return isRunning;
	}
	static SDL_Renderer* renderer;
	static SDL_Event event;
private:
	bool isRunning = 1;
	SDL_Window* gWindow = NULL;


};


#endif 
