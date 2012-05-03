#include "student.h"

Student::Student(double x, double y, QImage *si) : GameObject(x, y, si)
{
}

void Student::animate()
{
    for (int i = 0; i < 5; i++)
        moveX(-1);
    for (int i = 0; i < 5; i++)
        moveX(1);
}

void Student::setTarget(QPoint *point)
{
    target = point;
}

QPoint *Student::getTarget()
{
    return target;
}
