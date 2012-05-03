#include "enemy.h"

Enemy::Enemy(double x, double y, QImage *i) : GameObject(x, y, i)
{
    InitializeInstanceFields();
}

void Enemy::InitializeInstanceFields()
{
    advance = 0;
    speed = 1;
    health = 0;
    isDropped = false;
}
