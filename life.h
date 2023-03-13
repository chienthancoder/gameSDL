#pragma once
#include"Components.h"
#include"Game.h"
class LifeOfEntiy : public Component
{
public:
	int hp;
	SDL_Rect rec = { 0,0,100,32 };
	LifeOfEntiy(int HP)
	{
		hp = HP;
		SDL_RenderDrawRect(Game::renderer, &rec);
	}
	void init() override
	{
	
	}

	void update() override
	{
		if (hp < 0) Game::isRunning = 0;
	}


};