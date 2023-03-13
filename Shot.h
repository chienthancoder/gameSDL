#pragma once
#include"Components.h"
#include<vector>
#include"projectiles.h"

class shot : public Component
{
public:
	TransformComponent* transform;
	std::vector<CreateProjectiles*> projectiles;
	
	shot() = default;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			if (Game::event.key.keysym.sym == SDLK_j)
			{
				CreateProjectiles* bullet = new CreateProjectiles();
				bullet->init();
				bullet->xpos = static_cast<int>(transform->position.x);
				bullet->ypos = static_cast<int>(transform->position.y);
				bullet->update();
				projectiles.push_back(bullet);
			}
		}
		
	}

	void draw() override
	{
		for (auto c : projectiles)
		{
			c->des.x+=5;
			c->draw();
		}
	}
};