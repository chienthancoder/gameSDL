#pragma once
#include"Components.h"
#include "Game.h"


class KeyBoardController : public Component
{
public:
	TransformComponent* transform;
	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym)
			{case SDLK_w:
			{
				if (transform->position.y <= 64)
				{
					transform->velocity.y = 0;
				}
				else
				transform->velocity.y = -1;
				break;
			}
			case SDLK_s:
				if (transform->position.y >= 550)
				{
					transform->velocity.y = 0;
				}
				else
				transform->velocity.y = 1;
				break;
			case SDLK_a:
				if (transform->position.x <= 0)
				{
					transform->velocity.x = 0;
				}
				else
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				if (transform->position.x >= 700)
				{
					transform->velocity.x = 0;
				}
				else
				transform->velocity.x = 1;
				break;
			default:
				break;
			}
		}
		else if (Game::event.type == SDL_KEYUP) {
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = 0;
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				break;
			default:
				break;
			}
		}
	}
};