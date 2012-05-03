#include "tdefense.h"
#include <QPainter>
#include <QApplication>
#include <iostream>

TDefense::TDefense(QWidget *parent) : QWidget(parent)
{
    InitializeInstanceFields();
    windowRect = new QRect(-1, -1, gpWidth+2, gpHeight+2);

    problem = new QImage;
    assignment1 = new QImage;
    assignment2 = new QImage;
    paper1 = new QImage;
    paper2 = new QImage;
    paper3 = new QImage;
    paper4 = new QImage;
    paper5 = new QImage;
    midterm1 = new QImage;
    midterm2 = new QImage;
    midterm3 = new QImage;
    midterm4 = new QImage;
    midterm5 = new QImage;
    midtermA = new QImage;
    midtermB = new QImage;
    midtermC = new QImage;
    pencil = new QImage;
    student = new QImage;
    pi = new QImage;
    stapler = new QImage;
    staple = new QImage;

    problem->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\problem.png");
    assignment1->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\assignment1.png");
    assignment2->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\assignment2.png");
    paper1->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\paper1.png");
    paper2->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\paper2.png");
    paper3->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\paper3.png");
    paper4->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\paper4.png");
    paper5->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\paper5.png");
    midterm1->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\midterm1.png");
    midterm2->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\midterm2.png");
    midterm3->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\midterm3.png");
    midterm4->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\midterm4.png");
    midterm5->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\midterm5.png");
    midtermA->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\midtermA.png");
    midtermB->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\midtermB.png");
    midtermC->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\midtermC.png");
    pencil->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\pencil.png");
    student->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\student.png");
    pi->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\pi.png");
    stapler->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\stapler.png");
    staple->load("C:\\Users\\Yemata\\CollegeTowerDefense2\\Images\\staple.png");

    myStudent = new Student(0, 0, student);
    QRect *sRect = myStudent->getRect();
    double sWidth = sRect->width();
    double sHeight = sRect->height();
    myStudent = new Student(gpWidth / 2 - sWidth, gpHeight - sHeight, student);

    myProblems = QVector<Problem*>();
    myAssignments = QVector<Assignment*>();
    myPapers = QVector<Paper*>();
    myMidterms = QVector<Midterm*>();

    myTowers = QVector<Tower*>();

    myStudentBullets = QVector<Bullet*>();
    myTowerBullets = QVector<Bullet*>();

    start();

}

TDefense::~TDefense()
{
    delete myStudent;
    for (unsigned short int i = 0; i < myProblems.size(); i++)
        delete myProblems[i];
    for (unsigned short int i = 0; i < myAssignments.size(); i++)
        delete myAssignments[i];
    for (unsigned short int i = 0; i < myPapers.size(); i++)
        delete myPapers[i];
    for (unsigned short int i = 0; i < myMidterms.size(); i++)
        delete myMidterms[i];
    for (unsigned short int i = 0; i < myTowers.size(); i++)
        delete myTowers[i];
    for (unsigned short int i = 0; i < myStudentBullets.size(); i++)
        delete myStudentBullets[i];
    for (unsigned short int i = 0; i < myTowerBullets.size(); i++)
        delete myTowerBullets[i];
}

void TDefense::start()
{
    if (isPaused)
        return;

    timerID = startTimer(50);
    isStarted = true;
}

void TDefense::pause()
{
    if (!isStarted)
        return;

    isPaused = !isPaused;
    if (isPaused)
    {
        killTimer(timerID);
        repaint();
    }
    else
    {
        timerID = startTimer(20);
    }
}

void TDefense::launch()
{
    isLaunched = true;
}

void TDefense::gameOver()
{
    isLaunched = false;
    isStarted = false;
    isOver = true;
    killTimer(timerID);
}

void TDefense::gameWon()
{
  isWon = true;
  isStarted = false;
  killTimer(timerID);
}

void TDefense::enemyAction()
{
    problemAction();
    assignmentAction();
    paperAction();
    midtermAction();
}
    void TDefense::problemAction()
{
        if (myProblems.size() > 0) {
            for (int i = 0; i < myProblems.size(); i++)
            {
                Problem *curProblem = myProblems[i];
                curProblem->setVX(0);
                curProblem->setVY(1);

                double x = curProblem->getX();
                double y = curProblem->getY();
                double vx = curProblem->getVX();
                double vy = curProblem->getVY();
                int height = curProblem->getImage().height();
                int width = curProblem->getImage().width();

                if ((y <= 0 && vy < 0) || (x <= 0 && vx < 0 || (gpHeight <= (y + height)) && y > 0 && vy > 0) || ((gpWidth == (x + width)) && vx > 0 && vx > 0))
                {
                    if (!curProblem->isDropped)
                    {
                        numEnemiesDropped++;
                        extensions--;
                        IQ--;
                        curProblem->isDropped = true;
                    }
                }

                curProblem->move();
                curProblem->setVX(vx);
                curProblem->setVY(vy);

            } //end outer for
        }
}
    void TDefense::assignmentAction()
{
        /*
        std::cout << "\nmyAssignments size: " << myAssignments.size() << endl;
for (int i = 0; i < myAssignments.size(); i++)
{
    Assignment *curAssignment = myAssignments[i];
    curAssignment->followPath();

    double x = curAssignment->getX();
    double y = curAssignment->getY();
    double vx = curAssignment->getVX();
    double vy = curAssignment->getVY();
    int height = curAssignment->getImage().height();
    int width = curAssignment->getImage().width();

    if ((y <= 0 && vy < 0) || (x <= 0 && vx < 0 || (gpHeight <= (y + height)) && y > 0 && vy > 0) || ((gpWidth == (x + width)) && vx > 0 && vx > 0))
    {
        if (!curAssignment->isDropped)
        {
            numEnemiesDropped++;
            extensions--;
            IQ -= 2;
            curAssignment->isDropped = true;
        }
    }

    curAssignment->move();
    curAssignment->setVX(vx);
    curAssignment->setVY(vy);

} //end outer for
*/
}
    void TDefense::paperAction()
{
        /*
    for (int i = 0; i < myPapers.size(); i++)
    {
        Paper *curPaper = myPapers[i];
        curPaper->followPath();

        double x = curPaper->getX();
        double y = curPaper->getY();
        double vx = curPaper->getVX();
        double vy = curPaper->getVY();
        int height = curPaper->getImage().height();
        int width = curPaper->getImage().width();

        if ((y <= 0 && vy < 0) || (x <= 0 && vx < 0 || (gpHeight <= (y + height)) && y > 0 && vy > 0) || ((gpWidth == (x + width)) && vx > 0 && vx > 0))
        {
            if (!curPaper->isDropped)
            {
                numEnemiesDropped++;
                extensions--;
                IQ -= 3;
                curPaper->isDropped = true;
            }
        }

        curPaper->move();
        curPaper->setVX(vx);
        curPaper->setVY(vy);

    } //end outer for
    */
}

void TDefense::midtermAction()
{
        /*
    for (int i = 0; i < myMidterms.size(); i++)
    {
        Midterm *curMidterm = myMidterms[i];
        curMidterm->followPath();

        double x = curMidterm->getX();
        double y = curMidterm->getY();
        double vx = curMidterm->getVX();
        double vy = curMidterm->getVY();
        int height = curMidterm->getImage().height();
        int width = curMidterm->getImage().width();

        if ((y <= 0 && vy < 0) || (x <= 0 && vx < 0 || (gpHeight <= (y + height)) && y > 0 && vy > 0) || ((gpWidth == (x + width)) && vx > 0 && vx > 0))
        {
            if (!curMidterm->isDropped)
            {
                numEnemiesDropped++;
                extensions--;
                IQ -= 3;
                curMidterm->isDropped = true;
            }
        }

        curMidterm->move();
        curMidterm->setVX(vx);
        curMidterm->setVY(vy);

    } //end outer for
    */
}

void TDefense::clearEnemies()
{
    clearProblems();
    clearAssignments();
    clearPapers();
}
    void TDefense::clearProblems()
{
    for (int i = 0; i < myProblems.size(); i++)
    {
        myProblems.remove(i);
    } // end for
} // end method
    void TDefense::clearAssignments()
{
    for (int i = 0; i < myAssignments.size(); i++)
    {
        myAssignments.remove(i);
    } // end for
} // end method
    void TDefense::clearPapers()
{
    for (int i = 0; i < myPapers.size(); i++)
    {
        myPapers.remove(i);
    } // end for
} // end method
    void TDefense::clearMidterms()
{
    for (int i = 0; i < myMidterms.size(); i++)
    {
        myMidterms.remove(i);
    } // end for
} // end method

void TDefense::studentAction()
{
    QPoint *myTarget = myStudent->getTarget();
    studentShoot(myTarget);

    for (int i = 0; i < myStudentBullets.size(); i++)
    {
        Bullet *curBullet = myStudentBullets[i];
        double bX = curBullet->getX();
        double bY = curBullet->getY();
        double bVX = curBullet->getVX();
        double bVY = curBullet->getVY();
        int bHeight = curBullet->getImage().height();
        int bWidth = curBullet->getImage().width();

        curBullet->move();
        curBullet->setVX(bVX);
        curBullet->setVY(bVY);

        for (int j = 0; j < myProblems.size(); j++)
        {
            Problem *secondProblem = myProblems[j];
            if (curBullet->intersects(secondProblem))
            {
                secondProblem->health--;
                if (secondProblem->health == 0)
                {
                    funds += 10;
                    myProblems.remove(j);
                    numEnemiesShot++;
                }
                studentShotFired = false;
                studentBulletAdded = false;
            }
            else if ((bY <= 0 && bVY < 0) || (bX <= 0 && bVX < 0 || (gpHeight <= (bY + bHeight)) && bY > 0 && bVY > 0) || ((gpWidth == (bX + bWidth)) && bVX > 0 && bVX > 0))
            {
                studentShotFired = false;
                studentBulletAdded = false;
            } // end else if
            if (!studentShotFired && myStudentBullets.size() > 0)
            {
                myStudentBullets.remove(i);
            } // end if
        } // end inner for

        for (int j = 0; j < myAssignments.size(); j++)
        {
            Assignment *secondAssignment = myAssignments[j];
            if (curBullet->intersects(secondAssignment))
            {
                secondAssignment->health--;
                secondAssignment->setImage(assignment2);
                if (secondAssignment->health == 0)
                {
                    funds += 20;
                    myAssignments.remove(j);
                    numEnemiesShot++;
                }
                studentShotFired = false;
                studentBulletAdded = false;
            }
            else if ((bY <= 0 && bVY < 0) || (bX <= 0 && bVX < 0 || (gpHeight <= (bY + bHeight)) && bY > 0 && bVY > 0) || ((gpWidth == (bX + bWidth)) && bVX > 0 && bVX > 0))
            {
                studentShotFired = false;
                studentBulletAdded = false;
            } // end else if
            if (!studentShotFired && myStudentBullets.size() > 0)
            {
                myStudentBullets.remove(i);
            } // end if
        } // end inner for

        for (int j = 0; j < myPapers.size(); j++)
        {
            Paper *secondPaper = myPapers[j];
            if (curBullet->intersects(secondPaper))
            {
                secondPaper->health--;
                switch (secondPaper->health)
                {
                case 4:
                    secondPaper->setImage(paper2);
                    break;
                case 3:
                    secondPaper->setImage(paper3);
                    break;
                case 2:
                    secondPaper->setImage(paper4);
                    break;
                case 1:
                    secondPaper->setImage(paper5);
                    break;
                }
                if (secondPaper->health == 0)
                {
                    funds += 40;
                    myPapers.remove(j);
                    numEnemiesShot++;
                }
                studentShotFired = false;
                studentBulletAdded = false;
            }
            else if ((bY <= 0 && bVY < 0) || (bX <= 0 && bVX < 0 || (gpHeight <= (bY + bHeight)) && bY > 0 && bVY > 0) || ((gpWidth == (bX + bWidth)) && bVX > 0 && bVX > 0))
            {
                studentShotFired = false;
                studentBulletAdded = false;
            } // end else if
            if (!studentShotFired && myStudentBullets.size() > 0)
            {
                myStudentBullets.remove(i);
            } // end if
        } // end inner for

        for (int j = 0; j < myMidterms.size(); j++)
        {
            Midterm *secondMidterm = myMidterms[j];
            if (curBullet->intersects(secondMidterm))
            {
                secondMidterm->health--;
                switch (secondMidterm->health)
                {
                case 17:
                    secondMidterm->setImage(midterm4);
                    break;
                case 16:
                    secondMidterm->setImage(midterm3);
                    break;
                case 15:
                    secondMidterm->setImage(midterm2);
                    break;
                case 14:
                    secondMidterm->setImage(midterm1);
                    break;
                case 13:
                    secondMidterm->setImage(midtermC);
                    break;
                case 12:
                    secondMidterm->setImage(midterm5);
                    break;
                case 11:
                    secondMidterm->setImage(midterm4);
                    break;
                case 10:
                    secondMidterm->setImage(midterm3);
                    break;
                case 9:
                    secondMidterm->setImage(midterm2);
                    break;
                case 8:
                    secondMidterm->setImage(midterm1);
                    break;
                case 7:
                    secondMidterm->setImage(midtermB);
                    break;
                case 6:
                    secondMidterm->setImage(midterm5);
                    break;
                case 5:
                    secondMidterm->setImage(midterm4);
                    break;
                case 4:
                    secondMidterm->setImage(midterm3);
                    break;
                case 3:
                    secondMidterm->setImage(midterm2);
                    break;
                case 2:
                    secondMidterm->setImage(midterm1);
                    break;
                case 1:
                    secondMidterm->setImage(midtermA);
                    break;
                }
                if (secondMidterm->health == 0)
                {
                    funds += 300;
                    myMidterms.remove(j);
                    numEnemiesShot++;
                }
                studentShotFired = false;
                studentBulletAdded = false;
            }
            else if ((bY <= 0 && bVY < 0) || (bX <= 0 && bVX < 0 || (gpHeight <= (bY + bHeight)) && bY > 0 && bVY > 0) || ((gpWidth == (bX + bWidth)) && bVX > 0 && bVX > 0))
            {
                studentShotFired = false;
                studentBulletAdded = false;
            } // end else if
            if (!studentShotFired && myStudentBullets.size() > 0)
            {
                myStudentBullets.remove(i);
            } // end if
        } // end inner for
    } // end outer for
} // end method
    void TDefense::studentShoot(QPoint *target)
{

    double cxBullet, cyBullet, cxTarget, cyTarget;
    double dx, dy, slope, unit = 1;

    cxBullet = myStudent->getCenterX();
    cyBullet = myStudent->getCenterY();
    cxTarget = target->x();
    cyTarget = target->y();

    dx = cxTarget - cxBullet;
    dy = cyTarget - cyBullet;
    slope = - dy / dx;

    if (cxTarget >= gpWidth / 2)
    {
        slope = -slope;
        unit = -unit;
    }

    if (!studentBulletAdded)
    {
        Bullet *b = new Bullet(cxBullet, cyBullet, -5*unit, 5*slope, pi);
        myStudentBullets.push_back(b);
        studentBulletAdded = true;
    }
}

void TDefense::towerAction()
{
    /*
    towerShoot();

    for (int i = 0; i < myTowerBullets.size(); i++)
    {
        Bullet *curBullet = myTowerBullets[i];
        double bX = curBullet->getX();
        double bY = curBullet->getY();
        double bVX = curBullet->getVX();
        double bVY = curBullet->getVY();
        int bHeight = curBullet->getImage().height();
        int bWidth = curBullet->getImage().width();

        curBullet->move();
        curBullet->setVX(bVX);
        curBullet->setVY(bVY);


        for (int j = 0; j < myProblems.size(); j++)
        {
            Problem *secondProblem = myProblems[j];
            if (curBullet->intersects(secondProblem))
            {
                secondProblem->health--;
                if (secondProblem->health == 0)
                {
                    myProblems.remove(j);
                    funds += 10;
                    numEnemiesShot++;
                }
                towerBulletAdded = false;
            }
            else if ((bY <= 0 && bVY < 0) || (bX <= 0 && bVX < 0 || (gpHeight <= (bY + bHeight)) && bY > 0 && bVY > 0) || ((gpWidth == (bX + bWidth)) && bVX > 0 && bVX > 0))
            {
                towerBulletAdded = false;
            } // end else if
            if (!towerBulletAdded && myTowerBullets.size() > 0)
            {
                myTowerBullets.remove(i);
            }
        } // end inner for

        for (int j = 0; j < myAssignments.size(); j++)
        {
            Assignment *secondAssignment = myAssignments[j];
            if (curBullet->intersects(secondAssignment))
            {
                secondAssignment->health--;
                secondAssignment->setImage(assignment2);
                if (secondAssignment->health == 0)
                {
                    funds += 20;
                    myAssignments.remove(j);
                    numEnemiesShot++;
                }
                towerBulletAdded = false;
            }
            else if ((bY <= 0 && bVY < 0) || (bX <= 0 && bVX < 0 || (gpHeight <= (bY + bHeight)) && bY > 0 && bVY > 0) || ((gpWidth == (bX + bWidth)) && bVX > 0 && bVX > 0))
            {
                towerBulletAdded = false;
            } // end else if
            if (!towerBulletAdded && myTowerBullets.size() > 0)
            {
                myTowerBullets.remove(i);
            } // end if
        } // end inner for

        for (int j = 0; j < myPapers.size(); j++)
        {
            Paper *secondPaper = myPapers[j];
            if (curBullet->intersects(secondPaper))
            {
                secondPaper->health--;
                switch (secondPaper->health)
                {
                case 4:
                    secondPaper->setImage(paper2);
                    break;
                case 3:
                    secondPaper->setImage(paper3);
                    break;
                case 2:
                    secondPaper->setImage(paper4);
                    break;
                case 1:
                    secondPaper->setImage(paper5);
                    break;
                }
                if (secondPaper->health == 0)
                {
                    funds += 40;
                    myPapers.remove(j);
                    numEnemiesShot++;
                }
                towerBulletAdded = false;
            }
            else if ((bY <= 0 && bVY < 0) || (bX <= 0 && bVX < 0 || (gpHeight <= (bY + bHeight)) && bY > 0 && bVY > 0) || ((gpWidth == (bX + bWidth)) && bVX > 0 && bVX > 0))
            {
                towerBulletAdded = false;
            } // end else if
            if (!towerBulletAdded && myTowerBullets.size() > 0)
            {
                myTowerBullets.remove(i);
            } // end if
        } // end inner for

        for (int j = 0; j < myMidterms.size(); j++)
        {
            Midterm *secondMidterm = myMidterms[j];
            if (curBullet->intersects(secondMidterm))
            {
                secondMidterm->health--;
                switch (secondMidterm->health)
                {
                case 17:
                    secondMidterm->setImage(midterm4);
                    break;
                case 16:
                    secondMidterm->setImage(midterm3);
                    break;
                case 15:
                    secondMidterm->setImage(midterm2);
                    break;
                case 14:
                    secondMidterm->setImage(midterm1);
                    break;
                case 13:
                    secondMidterm->setImage(midtermC);
                    break;
                case 12:
                    secondMidterm->setImage(midterm5);
                    break;
                case 11:
                    secondMidterm->setImage(midterm4);
                    break;
                case 10:
                    secondMidterm->setImage(midterm3);
                    break;
                case 9:
                    secondMidterm->setImage(midterm2);
                    break;
                case 8:
                    secondMidterm->setImage(midterm1);
                    break;
                case 7:
                    secondMidterm->setImage(midtermB);
                    break;
                case 6:
                    secondMidterm->setImage(midterm5);
                    break;
                case 5:
                    secondMidterm->setImage(midterm4);
                    break;
                case 4:
                    secondMidterm->setImage(midterm3);
                    break;
                case 3:
                    secondMidterm->setImage(midterm2);
                    break;
                case 2:
                    secondMidterm->setImage(midterm1);
                    break;
                case 1:
                    secondMidterm->setImage(midtermA);
                    break;
                }
                if (secondMidterm->health == 0)
                {
                    funds += 40;
                    myMidterms.remove(j);
                    numEnemiesShot++;
                }
                towerBulletAdded = false;
            }
            else if ((bY <= 0 && bVY < 0) || (bX <= 0 && bVX < 0 || (gpHeight <= (bY + bHeight)) && bY > 0 && bVY > 0) || ((gpWidth == (bX + bWidth)) && bVX > 0 && bVX > 0))
            {
                towerBulletAdded = false;
            } // end else if
            if (!towerBulletAdded && myTowerBullets.size() > 0)
            {
                myTowerBullets.remove(i);
            } // end if
        } // end inner for
    } // end outer for
    */
} // end method
    void TDefense::towerShoot()
{
        /*
    double cxBullet, cyBullet, cxTarget, cyTarget;
    double dx, dy, slope, unit = 1;

    for (int i = 0; i < myTowers.size(); i++)
    {
        Tower *curTower = myTowers[i];

        for (int j = 0; j < myProblems.size(); j++)
        {
            Problem *curProblem = myProblems[j];
            if (curTower->enemyDetected(curProblem))
            {
                cxBullet = curTower->getCenterX();
                cyBullet = curTower->getCenterY();
                cxTarget = curProblem->getCenterX();
                cyTarget = curProblem->getCenterY();

                dx = cxTarget - cxBullet;
                dy = cyTarget - cyBullet;
                slope = - dy / dx;

                if (cxTarget >= gpWidth / 2)
                {
                    slope = -slope;
                    unit = -unit;
                } // end if

                if (!towerBulletAdded)
                {
                    Bullet *b = new Bullet(cxBullet, cyBullet, -2*unit, 2*slope, staple);
                    myTowerBullets.push_back(b);
                    towerBulletAdded = true;
                } // end outer if
            } // end 'detection' if
        } // end inner for
    } // end outer for
    */
} // end method

void TDefense::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor* color = new QColor(255, 255, 255);
    painter.fillRect(*windowRect, *color);
    painter.drawRect(*windowRect);

    if (isOver) {

      QFont font("Courier", 15, QFont::DemiBold);
      QFontMetrics fm(font);
      int textWidth = fm.width("GAME OVER");

      painter.setFont(font);
      int h = height();
      int w = width();

      painter.translate(QPoint(w/2, h/2));
      painter.drawText(-textWidth/2, 0, "GAME OVER");
    } else if(isWon) {

      QFont font("Courier", 15, QFont::DemiBold);
      QFontMetrics fm(font);
      int textWidth = fm.width("VICTORY");

      painter.setFont(font);
      int h = height();
      int w = width();

      painter.translate(QPoint(w/2, h/2));
      painter.drawText(-textWidth/2, 0, "VICTORY");
    } else if (isPaused) {

        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("PAUSED");

        painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "PAUSED");
    }
    else
    {

        QFont font("Brush Script MT", 15);
        painter.setFont(font);

        painter.translate(QPoint(30, 30));
        painter.drawText(0, 0, "WWeek: " + week);
        painter.translate(QPoint(13, 15));
        painter.drawText(0, 0, "SSemester: " + semester);
        painter.translate(QPoint(30, 15));
        painter.drawText(0, 0, "YYear: " + year);

        painter.translate(QPoint(-50, 300));
        painter.drawText(0, 0, "IQ: ");
        painter.translate(QPoint(10, 17));
        painter.drawText(0, 0, "Funds: " + funds);
        painter.translate(QPoint(10, 17));
        painter.drawText(0, 0, "EExtensionExtensions: " + extensions);


        painter.drawImage(myStudent->getRect()->center(), myStudent->getImage());
        /*for (int i = 0; i < myTowers.size(); i++)
        {
            Tower *curTower = myTowers[i];
            painter.drawImage(*curTower->getRect(), curTower->getImage());
        }*/

        //if (isLaunched)
        //{

            for (int i = 0; i < myProblems.size(); i++)
            {
                Problem *curProblem = myProblems[i];
                painter.drawImage(*curProblem->getRect(), curProblem->getImage());
            } // end for

            /*
            for (int i = 0; i < myAssignments.size(); i++)
            {
                Assignment *curAssignment = myAssignments[i];
                painter.drawImage(*curAssignment->getRect(), curAssignment->getImage());
            } // end for
            for (int i = 0; i < myPapers.size(); i++)
            {
                Paper *curPaper = myPapers[i];
                painter.drawImage(*curPaper->getRect(), curPaper->getImage());
            } // end for
            for (int i = 0; i < myMidterms.size(); i++)
            {
                Midterm *curMidterm = myMidterms[i];
                painter.drawImage(*curMidterm->getRect(), curMidterm->getImage());
            } // end for
            */

            if (studentShotFired)
            {
                for (int i = 0; i < myStudentBullets.size(); i++)
                {
                    Bullet *curBullet = myStudentBullets[i];
                    painter.drawImage(*curBullet->getRect(), curBullet->getImage());
                } // end for
            } // end 'shotFired' if
            for (int i = 0; i < myTowerBullets.size(); i++)
            {
                Bullet *curBullet = myTowerBullets[i];
                painter.drawImage(*curBullet->getRect(), curBullet->getImage());
            } // end for
        //} // end 'isLaunch' if
    } // end 'isPaused' else
}

void TDefense::timerEvent(QTimerEvent *event)
{
    //if (isLaunched)
    //{
    std::cout << "\nWeek: " << week;

        launchModerator++;
        int round = week - 1;

        if (numEnemiesLaunched <= 10 + (round * 10))
        {
            if (launchModerator % 50 - (round * 5) == 0)
            {
                Problem *p = new Problem(gpWidth / 2, 0, problem);
                myProblems.push_back(p);
                numEnemiesLaunched++;
            }

            if (week > 1)
            {
                Tower *r = new Tower(500, 300, stapler);
                myTowers.push_back(r);
                if (launchModerator % 80 - (round * 10) == 0)
                {
                    Assignment *a = new Assignment(gpWidth / 2, 0, assignment1);
                    myAssignments.push_back(a);
                    numEnemiesLaunched++;
                } // end 'launchModerator' if
            } // end 'week' if

            if (week % 3 == 0)
            {
                if (launchModerator % 150 - (round * 15) == 0)
                {
                    Paper *r = new Paper(gpWidth / 2, 0, paper1);
                    myPapers.push_back(r);
                    numEnemiesLaunched++;
                } // end 'launchModerator' if
            } // 'week' if

            if (week == 5 || week == 9)
            {
                if (launchModerator % 300 - (round * 20) == 0)
                {
                    Midterm *m = new Midterm(gpWidth / 2, 0, midterm5);
                    myMidterms.push_back(m);
                    numEnemiesLaunched++;
                } // end 'launchModerator' if
            } // 'week' if
        } // end 'numEnemiesLaunched' if

        enemyAction();

        if (myProblems.size() > 0) {
            Problem *curProblem = myProblems.back();
            std::cout << "myProblems size: " << myProblems.size();
            std::cout << "\nproblem y-pos: " << curProblem->getY();
        }

        towerAction();
        if (studentShotFired)
            studentAction();

        if (extensions <= 0)
            gameOver();

        if ((numEnemiesShot + numEnemiesDropped) >= 10 + (round * 10))
        {
            clearEnemies();
            numEnemiesDropped = 0;
            numEnemiesLaunched = 1;
            numEnemiesShot = 0;
            isLaunched = false;
            IQ += 10;
            week++;
        }

        if (week == 10)
            semester++;
        if (semester == 2)
        {
            semester = 1;
            year++;
        }

        repaint();
    //} // end 'isLaunch' if
} // end method

void TDefense::keyPressEvent(QKeyEvent *event)
{

    //if (!isLaunched)
    //{
        switch (event->key()) {
        case Qt::Key_P:
        {
            pause();
            break;
        }
        case Qt::Key_Left:
           {
            myStudent->moveXY(-2, 0);
           }
           break;
        case Qt::Key_Right:
           {
            myStudent->moveXY(2, 0);
           }
            break;
        case Qt::Key_Up:
           {
            myStudent->moveXY(0, -2);
           }
            break;
        case Qt::Key_Down:
           {
            myStudent->moveXY(0, 2);
           }
            break;
        case Qt::Key_Space:
            {
                start();
            }
            break;
        case Qt::Key_Escape:
            {
              qApp->exit();
            }
            break;
        default:
            QWidget::keyPressEvent(event);
        }
   // }

}

void TDefense::mousePressEvent(QMouseEvent *event)
{
    if (!isLaunched)
    {
        launch();
    }
    else
    {
        QPoint tempPoint = event->pos();
        QPoint* mousePoint = & tempPoint;
        myStudent->setTarget(mousePoint);
        studentShotFired = true;
    }
}

void TDefense::InitializeInstanceFields()
{
    IQ = 100;
    funds = 0;
    extensions = 10;
    gpWidth = 800;
    gpHeight =480;
    week = 1;
    semester = 1;
    year = 1;
    timerInterval = 20;
    launchModerator = 0;
    numEnemiesLaunched = 1;
    numEnemiesDropped = 0;
    numEnemiesShot = 0;
    isStarted = false;
    isPaused = false;
    isLaunched = true;
    isOver = false;
    isWon = false;
    studentShotFired = false;
    studentBulletAdded = false;
    towerBulletAdded = false;
}
