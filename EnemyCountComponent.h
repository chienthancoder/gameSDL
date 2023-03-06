#pragma once
#include"Components.h"
#include"Vector2D.h"
#include"EnemyCountSystem.h"

class EnemyCountComponent : public Component
{
public:
	EnemyCountSystem* countenemy;
	EnemyCountComponent()
	{
		countenemy = &entity->getComponent<EnemyCountSystem>();
	}
	void init() override
	{
		countenemy->maxEnemy = 10;
	}

	void update() override
	{
		
	}
};
