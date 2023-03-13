#include"Game.h"
#include"TextureManager.h"
#include"Map.h"
#include<ctime>
#include"Components.h"
#include"Collision.h"
#include"ECS.h"

SDL_Renderer* Game::renderer = nullptr;
Map* map;
Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

SDL_Event Game::event;
bool Game::isRunning;
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
		player.addComponent<TransformComponent>();
		player.addComponent<SpriteComponent>("aniamtion-removebg-preview.png", 4, 150);
		player.addComponent<KeyBoardController>();
		player.addComponent<ColliderComponent>("player");
		player.addComponent<LifeOfEntiy>(100);
		player.addComponent<shot>();
		

	}
	else {
		isRunning = 0;
	}
}

void Game::update()
{
	 
	
	manager.refresh();
	manager.update();

	/*if (Collision::AABB(player.getComponent<ColliderComponent>().rec, wall.getComponent<ColliderComponent>().rec))
	{
		std::cout << "Hit" << std::endl; 
		player.getComponent<LifeOfEntiy>().hp--;

		std::cout << player.getComponent<LifeOfEntiy>().hp;
	}*/
		
	

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


