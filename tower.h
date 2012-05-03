#ifndef TOWER_H
#define TOWER_H

#pragma once

#include <QImage>
#include <QRect>
#include "gameobject.h"

class Tower : public GameObject
{

public:
    double xRange, yRange;
    QRect *range;
    QPoint *targetLocation;

    Tower(double x, double y, QImage *i);

    virtual bool enemyDetected(GameObject *target);

    virtual void drag();

    virtual QRect *getRange();
    virtual QPoint *getTargetLocation();
    virtual void setTargetLocation(QPoint *point);


private:
    void InitializeInstanceFields();
}; // end class definition


#endif // TOWER_H
