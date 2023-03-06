#pragma once
#include"Components.h"
#include"Vector2D.h"

class EnemyCountSystem
{
public:
	int countEnemy = 0;
	int maxEnemy;
	EnemyCountSystem(int a)
	{
		maxEnemy = a;
	}

	void update()
	{
		countEnemy++;
	}

	void refresh()
	{
		countEnemy--;
	}
};
