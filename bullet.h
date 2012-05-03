#ifndef BULLET_H
#define BULLET_H

#pragma once

#include <QImage>
#include <QRect>
#include "gameobject.h"

class Bullet : public GameObject
{

    public:
        Bullet(double x, double y, double vx, double vy, QImage *i);

};



#endif // BULLET_H
