#include "gameobject.h"

GameObject::GameObject(double x, double y, QImage *i)
{
    myX = x;
    myY = y;
    myVX = 0;
    myVY = 0;
    myImage = *i;
    myRect = & i->rect();
    myDX = myRect->width();
    myDY = myRect->height();
}

GameObject::~GameObject()
{
}

void GameObject::move()
{
    //We move the rectangle, but not the image
    myX += myVX;
    myY += myVY;
    myRect->setRect(myX, myY, myDX, myDY);
}

void GameObject::moveX(double speed)
{
    myX += speed;
    myRect->setRect(myX, myY, myDX, myDY);
}

void GameObject::moveY(double speed)
{
    myY += speed;
    myRect->setRect(myX, myY, myDX, myDY);
}

void GameObject::moveXY(double speedX, double speedY)
{
    moveX(speedX);
    moveY(speedY);
    myRect->setRect(myX, myY, myDX, myDY);
}

bool GameObject::intersects(GameObject *go)
{
    QRect* goRect = go->getRect();
    if (myRect->intersects(*goRect))
        return true;
    return false;
}

double GameObject::getX()
{
    return myX;
}

double GameObject::getY()
{
    return myY;
}

double GameObject::getVX()
{
    return myVX;
}

double GameObject::getVY()
{
    return myVY;
}

double GameObject::getCenterX()
{
    QPoint center = myRect->center();
    return center.x();
}

double GameObject::getCenterY()
{
    QPoint center = myRect->center();
    return center.y();
}

QRect* GameObject::getRect()
{
    return myRect;
}

QImage& GameObject::getImage()
{
    return myImage;
}

void GameObject::setX(double x)
{
    myX = x;
}

void GameObject::setY(double y)
{
    myX = y;
}

void GameObject::setVX(double vx)
{
    myVX = vx;
}

void GameObject::setVY(double vy)
{
    myVY = vy;
}

void GameObject::setImage(QImage *i)
{
    myImage = *i;
}
