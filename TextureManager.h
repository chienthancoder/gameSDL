#pragma once
#include"Game.h"

class texturemanager 
{
public:
	static SDL_Texture* LoadTexture( const char* path);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip spriteflip);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
private:
	SDL_Renderer* renderer;
};