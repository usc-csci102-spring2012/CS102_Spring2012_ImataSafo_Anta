#include "tower.h"

Tower::Tower(double x, double y, QImage *i) : GameObject(x, y, i)
{
    InitializeInstanceFields();
    double width = i->width(), height = i->height();
    double cx = (x + width / 2) - xRange / 2, cy = (y + height / 2) - yRange / 2;
    range = new QRect(cx, cy, xRange, yRange);
    targetLocation = new QPoint(myX, myY);
}

bool Tower::enemyDetected(GameObject *target)
{
    QRect* rectTarget = target->getRect();
    if (range->intersects(*rectTarget))
        return true;
    return false;
}

void Tower::drag()
{
    myX = targetLocation->x();
    myY = targetLocation->y();
}

QRect *Tower::getRange()
{
    return range;
}

QPoint *Tower::getTargetLocation()
{
    return targetLocation;
}

void Tower::setTargetLocation(QPoint *point)
{
    targetLocation = point;
}

void Tower::InitializeInstanceFields()
{
    xRange = 200;
    yRange = 200;
}

