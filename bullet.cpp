#include "bullet.h"

Bullet::Bullet(double x, double y, double vx, double vy, QImage *i) : GameObject(x, y, i)
{
    myVX = vx;
    myVY = vy;
}

