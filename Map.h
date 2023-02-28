#pragma once
#include"Game.h"
#include"TextureManager.h"

class Map
{
public:
	Map();
	~Map();
	void LoadMap(int arr[20][25]);
	void DrawMap();


private:
	SDL_Rect src, dest;

	SDL_Texture* tex1;
	SDL_Texture* tex2;
	SDL_Texture* tex3;

	int map[20][25];
	 
};