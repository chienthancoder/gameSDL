#include"Game.h"
#include"TextureManager.h"
#include"Components.h"
#include"Map.h"

SDL_Renderer* Game::renderer = nullptr;
Map* map;
Manager manager;
auto& Player(manager.addEntity());

SDL_Event Game::event;
Game::Game()
{};


Game::~Game()
{};


void Game::init(const char *title, int xpos, int ypos, int width, int height, int fullscreen)
{
	int flags = 0;
	if (fullscreen == 1) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialised!" << std::endl;
		gWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (gWindow) {
			std::cout << "Window created" << std::endl;
			renderer = SDL_CreateRenderer(gWindow, -1, 0);
		}
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created" << std::endl;
		}
		isRunning = 1;
		map = new Map();
		Player.addComponent<TransformComponent>();
		Player.addComponent<SpriteComponent>("death-removebg-preview.png");
		Player.addComponent<KeyBoardController>();

	}
	else {
		isRunning = 0;
	}
}

void Game::update()
{

	manager.refresh();
	manager.update();

	

};

void Game::HandleEvent() {

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = 0;
		break;
	default:
		break;
	}
}

void Game::render() {
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


