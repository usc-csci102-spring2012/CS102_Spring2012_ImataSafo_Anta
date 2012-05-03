#ifndef TDEFENSE_H
#define TDEFENSE_H

#pragma once

#include "student.h"
#include "problem.h"
#include "assignment.h"
#include "paper.h"
#include "midterm.h"
#include "tower.h"
#include "bullet.h"
#include <QVector>
#include <QWidget>
#include <QImage>
#include <QRect>
#include <QKeyEvent>
#include <QMouseEvent>

class TDefense : public QWidget
{
    Q_OBJECT

private:
    int timerID;
    Student *myStudent;
    int IQ, funds, extensions;
    //Enemy Lists
    QVector<Problem*> myProblems;
    QVector<Assignment*> myAssignments;
    QVector<Paper*> myPapers;
    QVector<Midterm*> myMidterms;
    //Tower Lists
    QVector<Tower*> myTowers;
    //Bullet Lists
    QVector<Bullet*> myStudentBullets;
    QVector<Bullet*> myTowerBullets;
    int gpWidth, gpHeight;
    int week, semester, year;
    int timerInterval, launchModerator,
        numEnemiesLaunched, numEnemiesDropped, numEnemiesShot;
    QRect *windowRect; //This is used to "clear" the window
    bool isStarted, isPaused, isLaunched, isOver, isWon,
         studentShotFired, studentBulletAdded, towerBulletAdded;
    QImage *problem, *assignment1, *assignment2, *paper1, *paper2, *paper3, *paper4, *paper5,
           *midterm1, *midterm2, *midterm3, *midterm4, *midterm5, *midtermA, *midtermB, *midtermC,
           *pencil, *student, *pi, *stapler, *staple;

public:
    TDefense(QWidget *parent = 0);
    ~TDefense();

    void start();

    void pause();

    void launch();

    void gameOver();

    void gameWon();

    void enemyAction();
         void problemAction();
         void assignmentAction();
         void paperAction();
         void midtermAction();

    void clearEnemies();
         void clearProblems();
         void clearAssignments();
         void clearPapers();
         void clearMidterms();

    void studentAction();

    void towerAction();
         void dragTower();
         void towerShoot();

    void studentShoot(QPoint *target);

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    void InitializeInstanceFields();
}; // end class definition

#endif // TDEFENSE_H
