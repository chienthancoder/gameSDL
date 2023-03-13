#pragma once
#include"Game.h"
#include"TextureManager.h"
//xây dựng 1 hàm để tạo ra đạn
//xây dụng thuọcc tính bắn đạn từ hàm tạo đạn trên
//thêm sự bắn đạn từ bàn phím.
class CreateProjectiles
{
public:
	int xpos;
	int ypos;

	SDL_Texture* tex;
	SDL_Rect src, des;
	CreateProjectiles()
	{

	}
	void init()
	{
		src.x = src.y = 0;
		src.w = src.h = 32;
		des.w = des.h = 16;
	}
	
	void update()
	{
		des.x = xpos;
		des.y = ypos;
	}
	void draw()
	{
		tex = texturemanager::LoadTexture("death.png");
		texturemanager::Draw(tex, src, des);
	}
};