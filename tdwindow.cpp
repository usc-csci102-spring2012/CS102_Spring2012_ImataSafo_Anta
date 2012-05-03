#include "tdwindow.h"

#include <QtGui>

 #include "tdefense.h"
 #include "tdwindow.h"

 TDWindow::TDWindow()
 {
     board = new TDefense;

     nextPieceLabel = new QLabel;
     nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
     nextPieceLabel->setAlignment(Qt::AlignCenter);

     IQLcd = new QLCDNumber(5);
     IQLcd->setSegmentStyle(QLCDNumber::Filled);
     WeekLcd = new QLCDNumber(2);
     WeekLcd->setSegmentStyle(QLCDNumber::Filled);

     startButton = new QPushButton(tr("&Start"));
     startButton->setFocusPolicy(Qt::NoFocus);
     pauseButton = new QPushButton(tr("&Pause"));
     pauseButton->setFocusPolicy(Qt::NoFocus);
     quitButton = new QPushButton(tr("&Quit"));
     quitButton->setFocusPolicy(Qt::NoFocus);

     connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
     connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
     connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
     connect(board, SIGNAL(iqChanged(int)), IQLcd, SLOT(display(int)));
     connect(board, SIGNAL(weekChanged(int)), WeekLcd, SLOT(display(int)));

     QGridLayout *layout = new QGridLayout;
     layout->addWidget(createLabel(tr("Week")), 2, 0);
     layout->addWidget(WeekLcd, 3, 0);
     layout->addWidget(startButton, 4, 0);
     layout->addWidget(board, 0, 1, 6, 1);
     layout->addWidget(createLabel(tr("IQ")), 0, 2);
     layout->addWidget(IQLcd, 1, 2);
     layout->addWidget(quitButton, 4, 2);
     layout->addWidget(pauseButton, 5, 2);
     setLayout(layout);

     setWindowTitle(tr("College Tower Defense"));
     resize(550, 370);
 }

 QLabel *TDWindow::createLabel(const QString &text)
 {
     QLabel *lbl = new QLabel(text);
     lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
     return lbl;
 }
