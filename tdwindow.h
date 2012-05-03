#ifndef TDWINDOW_H
#define TDWINDOW_H

#include <QFrame>
#include <QWidget>

class QLCDNumber;
class QLabel;
class QPushButton;

class TDefense;

class TDWindow : public QWidget
{
    Q_OBJECT

public:
    TDWindow();

private:
    QLabel *createLabel(const QString &text);

    TDefense *board;
    QLabel *nextPieceLabel;
    QLCDNumber *WeekLcd;
    QLCDNumber *IQLcd;
    QLCDNumber *ExtensionsLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};

#endif // TDWINDOW_H
