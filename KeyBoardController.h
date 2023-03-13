#pragma once
#include"Components.h"
#include "Game.h"


class KeyBoardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;


	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	
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
				{
					sprite->spriteflip = SDL_FLIP_HORIZONTAL;
					transform->velocity.x = -1;
					break;
				}
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
				sprite->spriteflip = SDL_FLIP_NONE;
				transform->velocity.y = 0;
				break;
			case SDLK_s:
				sprite->spriteflip = SDL_FLIP_NONE;
				transform->velocity.y = 0;
				break;
			case SDLK_a:
				sprite->spriteflip = SDL_FLIP_NONE;
				transform->velocity.x = 0;
				break;
			case SDLK_d:
				sprite->spriteflip = SDL_FLIP_NONE;
				transform->velocity.x = 0;
				break;
			default:
				break;
			}
		}
	}
};