#include"TextureManager.h"

 SDL_Texture* texturemanager::LoadTexture( const char* path) {
	SDL_Surface* tmp = IMG_Load(path);
	if (tmp == NULL) std::cout << "error";
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmp);
	SDL_FreeSurface(tmp);
	return tex;
}

 void texturemanager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
 {
	 SDL_RenderCopy(Game::renderer, tex, &src, &dest);
 }
