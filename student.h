#ifndef STUDENT_H
#define STUDENT_H

#pragma once

#include <QPoint>
#include <QImage>
#include <QRect>
#include "gameobject.h"

class Student : public GameObject
{

public:
    QPoint *target;

    Student(double x, double y, QImage *si);

    virtual void animate();

    virtual void setTarget(QPoint *point);
    virtual QPoint *getTarget();

};


#endif // STUDENT_H
