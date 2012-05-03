#ifndef PAPER_H
#define PAPER_H

#pragma once

#include <QImage>
#include <QRect>
#include "enemy.h"

class Paper : public Enemy
{
public:
    double speed;
    int health;

    Paper(double x, double y, QImage *i);

    void followPath();

    virtual int getHealth();

private:
    void InitializeInstanceFields();
};


#endif // PAPER_H
