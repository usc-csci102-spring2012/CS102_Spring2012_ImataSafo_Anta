#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#pragma once

#include <QImage>
#include <QRect>
#include "enemy.h"

class Assignment : public Enemy
{
public:
    double speed;
    int health;

    Assignment(double x, double y, QImage *i);

    void followPath();

    int getHealth();

private:
    void InitializeInstanceFields();
};


#endif // ASSIGNMENT_H
