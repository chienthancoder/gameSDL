#pragma once
#include"Components.h"
#include"TextureManager.h"
#include"SDL.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, desRect;
	
	int frames = 0;
	int speed = 100;
	bool animated = 0;
public:
	SDL_RendererFlip spriteflip = SDL_FLIP_NONE;
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		SetText(path);
	}
	SpriteComponent(const char* path,int mframes, int mspeed)
	{
		animated = true;
		frames = mframes;
		speed = mspeed;
		SetText(path);
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}
	void SetText(const char* path)
	{
		texture = texturemanager::LoadTexture(path);
	}
	void init() override
	{
		
		transform = &entity->getComponent<TransformComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		
	}

	void update() override
	{
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}
		desRect.x = static_cast<int>(transform->position.x);
		desRect.y = static_cast<int>(transform->position.y);
		desRect.w = transform->width * transform->scale;
		desRect.h = transform->height * transform->scale;
	}

	void draw() override
	{
		texturemanager::draw(texture, srcRect, desRect,spriteflip);
	}
};