#pragma once
#include"Game.h"
#include"Vector2D.h"

class SpawnPointComponent
{
public:
	Vector2D position;
	int maxEnemies;
	float spawnInterval;
	float elapsedTime;
};