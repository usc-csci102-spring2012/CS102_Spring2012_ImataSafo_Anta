#ifndef MIDTERM_H
#define MIDTERM_H

#pragma once

#include <QImage>
#include <QRect>
#include "enemy.h"

class Midterm : public Enemy
{
public:
    double speed;
    int health;

    Midterm(double x, double y, QImage *i);

    void followPath();

    int getHealth();

private:
    void InitializeInstanceFields();
};


#endif // MIDTERM_H
