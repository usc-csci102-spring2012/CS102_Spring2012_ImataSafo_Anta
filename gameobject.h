#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#pragma once

#include <QImage>
#include <QRect>

class GameObject
{
public:
    QRect *myRect;
    QImage myImage;
    double myX, myY,myDX, myDY;
    double myVX, myVY;

    GameObject(double x, double y, QImage *i);

    ~GameObject();

    void move();

    void moveX(double speed);

    void moveY(double speed);

    void moveXY(double speedX, double speedY);

    bool intersects(GameObject *go);

    //Various accessor/mutator methods
    double getX();
    double getY();
    double getVX();
    double getVY();
    double getCenterX();
    double getCenterY();
    QRect *getRect();
    QImage &getImage();
    void setX(double x);
    void setY(double y);
    void setVX(double vx);
    void setVY(double vy);
    void setImage(QImage *i);

};


#endif // GAMEOBJECT_H
