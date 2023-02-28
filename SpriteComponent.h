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

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		SetText(path);
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
		desRect.w = desRect.h = 64;
	}

	void update() override
	{
		desRect.x = (int)transform->position.x;
		desRect.y = (int)transform->position.y;
	}

	void draw() override
	{
		texturemanager::Draw(texture, srcRect, desRect);
	}
};