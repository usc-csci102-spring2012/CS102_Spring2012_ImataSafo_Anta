#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include <QImage>
#include <QRect>
#include "gameobject.h"

class Enemy : public GameObject
{
public:
    int advance;
    int speed;
    int health;
    bool isDropped;

    Enemy(double x, double y, QImage *i);

    virtual void followPath() = 0;


private:
    void InitializeInstanceFields();
};


#endif // ENEMY_H
