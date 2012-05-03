#include "problem.h"

Problem::Problem(double x, double y, QImage *i) : Enemy(x, y, i)
{
    InitializeInstanceFields();
}

void Problem::followPath()
{
    advance++;

    if (advance < 100 / speed)
        setVY(speed);
    else if (advance < (100 + 200) / speed)
    {
        setVY(0);
        setVX(speed);
    }
    else if (advance < (300 + 100) / speed)
    {
        setVX(0);
        setVY(speed);
    }
    else if (advance < (400 + 400) / speed)
    {
        setVY(0);
        setVX(-speed);
    }
    else if (advance < (800 + 200) / speed)
    {
        setVX(0);
        setVY(speed);
    }
    else if (advance < (1000 + 400) / speed)
    {
        setVY(0);
        setVX(speed);
    }
    else if (advance < (1400 + 200) / speed)
    {
        setVX(0);
        setVY(-speed);
    }
    else if (advance < (1600 + 200) / speed)
    {
        setVY(0);
        setVX(-speed);
    }
    else if (advance < (1800 + 200) / speed)
    {
        setVX(0);
        setVY(speed);
    }
    else if (advance < (2000 + 300) / speed)
    {
        setVY(0);
        setVX(-speed);
    }
    else if (advance < (2300 + 200) / speed)
    {
        setVX(0);
        setVY(speed);
    }
    else
    {
        setVX(0);
        setVY(speed);
    }
}

void Problem::InitializeInstanceFields()
{
    speed = 2;
    health = 1;
}

