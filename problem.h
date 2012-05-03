#ifndef PROBLEM_H
#define PROBLEM_H

#pragma once

#include <QImage>
#include <QRect>
#include "enemy.h"

class Problem : public Enemy
{
public:
    double speed;
    int health;

    Problem(double x, double y, QImage *i);

    void followPath();

private:
    void InitializeInstanceFields();
};


#endif // PROBLEM_H
