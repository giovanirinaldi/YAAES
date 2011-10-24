/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 22 20:21:11 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionNewRijndael;
    QAction *actionSetInputMatrix;
    QAction *actionSetKeyMatrix;
    QAction *actionExit;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *layoutStateMatrix;
    QLabel *stateByte13;
    QLabel *stateByte15;
    QLabel *stateByte12;
    QLabel *stateByte14;
    QLabel *stateByte09;
    QLabel *stateByte10;
    QLabel *stateByte11;
    QLabel *stateByte08;
    QLabel *stateByte05;
    QLabel *stateByte06;
    QLabel *stateByte07;
    QLabel *stateByte04;
    QLabel *stateByte00;
    QLabel *stateByte01;
    QLabel *stateByte02;
    QLabel *stateByte03;
    QWidget *gridLayoutWidget_3;
    QGridLayout *layoutInputMatrix;
    QLabel *inputByte00;
    QLabel *inputByte01;
    QLabel *inputByte02;
    QLabel *inputByte03;
    QLabel *inputByte04;
    QLabel *inputByte05;
    QLabel *inputByte06;
    QLabel *inputByte07;
    QLabel *inputByte08;
    QLabel *inputByte09;
    QLabel *inputByte10;
    QLabel *inputByte11;
    QLabel *inputByte12;
    QLabel *inputByte13;
    QLabel *inputByte14;
    QLabel *inputByte15;
    QWidget *gridLayoutWidget_5;
    QGridLayout *layoutOutputMatrix;
    QLabel *outputByte13;
    QLabel *outputByte15;
    QLabel *outputByte12;
    QLabel *outputByte14;
    QLabel *outputByte09;
    QLabel *outputByte10;
    QLabel *outputByte11;
    QLabel *outputByte08;
    QLabel *outputByte05;
    QLabel *outputByte06;
    QLabel *outputByte07;
    QLabel *outputByte04;
    QLabel *outputByte00;
    QLabel *outputByte01;
    QLabel *outputByte02;
    QLabel *outputByte03;
    QLabel *labelInputMatrix;
    QLabel *labelOutputMatrix;
    QLabel *labelKeyMatrix;
    QLabel *labelStateMatrix;
    QPushButton *buttonPreviousOp;
    QPushButton *buttonNextOp;
    QPushButton *buttonFirstOp;
    QPushButton *buttonLastOp;
    QWidget *gridLayoutWidget_4;
    QGridLayout *layoutKeyMatrix;
    QLabel *keyByte00;
    QLabel *keyByte04;
    QLabel *keyByte08;
    QLabel *keyByte12;
    QLabel *keyByte16;
    QLabel *keyByte20;
    QLabel *keyByte24;
    QLabel *keyByte28;
    QLabel *keyByte01;
    QLabel *keyByte05;
    QLabel *keyByte09;
    QLabel *keyByte13;
    QLabel *keyByte17;
    QLabel *keyByte21;
    QLabel *keyByte25;
    QLabel *keyByte29;
    QLabel *keyByte02;
    QLabel *keyByte06;
    QLabel *keyByte10;
    QLabel *keyByte14;
    QLabel *keyByte18;
    QLabel *keyByte22;
    QLabel *keyByte26;
    QLabel *keyByte30;
    QLabel *keyByte03;
    QLabel *keyByte07;
    QLabel *keyByte11;
    QLabel *keyByte15;
    QLabel *keyByte19;
    QLabel *keyByte23;
    QLabel *keyByte27;
    QLabel *keyByte31;
    QWidget *gridLayoutWidget_6;
    QGridLayout *layoutNextMatrix;
    QLabel *nextByte13;
    QLabel *nextByte15;
    QLabel *nextByte12;
    QLabel *nextByte14;
    QLabel *nextByte09;
    QLabel *nextByte10;
    QLabel *nextByte11;
    QLabel *nextByte08;
    QLabel *nextByte05;
    QLabel *nextByte06;
    QLabel *nextByte07;
    QLabel *nextByte04;
    QLabel *nextByte00;
    QLabel *nextByte01;
    QLabel *nextByte02;
    QLabel *nextByte03;
    QWidget *gridLayoutWidget_7;
    QGridLayout *layoutPreviousMatrix;
    QLabel *previousByte13;
    QLabel *previousByte15;
    QLabel *previousByte12;
    QLabel *previousByte14;
    QLabel *previousByte09;
    QLabel *previousByte10;
    QLabel *previousByte11;
    QLabel *previousByte08;
    QLabel *previousByte05;
    QLabel *previousByte06;
    QLabel *previousByte07;
    QLabel *previousByte04;
    QLabel *previousByte00;
    QLabel *previousByte01;
    QLabel *previousByte02;
    QLabel *previousByte03;
    QLabel *labelRound;
    QLabel *labelRoundNumber;
    QLabel *labelOperation;
    QLabel *labelOperationDesc;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionNewRijndael = new QAction(MainWindow);
        actionNewRijndael->setObjectName(QString::fromUtf8("actionNewRijndael"));
        actionSetInputMatrix = new QAction(MainWindow);
        actionSetInputMatrix->setObjectName(QString::fromUtf8("actionSetInputMatrix"));
        actionSetKeyMatrix = new QAction(MainWindow);
        actionSetKeyMatrix->setObjectName(QString::fromUtf8("actionSetKeyMatrix"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(220, 200, 101, 97));
        layoutStateMatrix = new QGridLayout(gridLayoutWidget_2);
        layoutStateMatrix->setContentsMargins(0, 0, 0, 0);
        layoutStateMatrix->setObjectName(QString::fromUtf8("layoutStateMatrix"));
        layoutStateMatrix->setContentsMargins(0, 0, 0, 0);
        stateByte13 = new QLabel(gridLayoutWidget_2);
        stateByte13->setObjectName(QString::fromUtf8("stateByte13"));
        QFont font;
        font.setKerning(true);
        stateByte13->setFont(font);
        stateByte13->setLayoutDirection(Qt::LeftToRight);
        stateByte13->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte13, 2, 3, 1, 1);

        stateByte15 = new QLabel(gridLayoutWidget_2);
        stateByte15->setObjectName(QString::fromUtf8("stateByte15"));
        stateByte15->setFont(font);
        stateByte15->setLayoutDirection(Qt::LeftToRight);
        stateByte15->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte15, 4, 3, 1, 1);

        stateByte12 = new QLabel(gridLayoutWidget_2);
        stateByte12->setObjectName(QString::fromUtf8("stateByte12"));
        stateByte12->setFont(font);
        stateByte12->setLayoutDirection(Qt::LeftToRight);
        stateByte12->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte12, 1, 3, 1, 1);

        stateByte14 = new QLabel(gridLayoutWidget_2);
        stateByte14->setObjectName(QString::fromUtf8("stateByte14"));
        stateByte14->setFont(font);
        stateByte14->setLayoutDirection(Qt::LeftToRight);
        stateByte14->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte14, 3, 3, 1, 1);

        stateByte09 = new QLabel(gridLayoutWidget_2);
        stateByte09->setObjectName(QString::fromUtf8("stateByte09"));
        stateByte09->setFont(font);
        stateByte09->setLayoutDirection(Qt::LeftToRight);
        stateByte09->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte09, 2, 2, 1, 1);

        stateByte10 = new QLabel(gridLayoutWidget_2);
        stateByte10->setObjectName(QString::fromUtf8("stateByte10"));
        stateByte10->setFont(font);
        stateByte10->setLayoutDirection(Qt::LeftToRight);
        stateByte10->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte10, 3, 2, 1, 1);

        stateByte11 = new QLabel(gridLayoutWidget_2);
        stateByte11->setObjectName(QString::fromUtf8("stateByte11"));
        stateByte11->setFont(font);
        stateByte11->setLayoutDirection(Qt::LeftToRight);
        stateByte11->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte11, 4, 2, 1, 1);

        stateByte08 = new QLabel(gridLayoutWidget_2);
        stateByte08->setObjectName(QString::fromUtf8("stateByte08"));
        stateByte08->setFont(font);
        stateByte08->setLayoutDirection(Qt::LeftToRight);
        stateByte08->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte08, 1, 2, 1, 1);

        stateByte05 = new QLabel(gridLayoutWidget_2);
        stateByte05->setObjectName(QString::fromUtf8("stateByte05"));
        stateByte05->setFont(font);
        stateByte05->setLayoutDirection(Qt::LeftToRight);
        stateByte05->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte05, 2, 1, 1, 1);

        stateByte06 = new QLabel(gridLayoutWidget_2);
        stateByte06->setObjectName(QString::fromUtf8("stateByte06"));
        stateByte06->setFont(font);
        stateByte06->setLayoutDirection(Qt::LeftToRight);
        stateByte06->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte06, 3, 1, 1, 1);

        stateByte07 = new QLabel(gridLayoutWidget_2);
        stateByte07->setObjectName(QString::fromUtf8("stateByte07"));
        stateByte07->setFont(font);
        stateByte07->setLayoutDirection(Qt::LeftToRight);
        stateByte07->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte07, 4, 1, 1, 1);

        stateByte04 = new QLabel(gridLayoutWidget_2);
        stateByte04->setObjectName(QString::fromUtf8("stateByte04"));
        stateByte04->setFont(font);
        stateByte04->setLayoutDirection(Qt::LeftToRight);
        stateByte04->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte04, 1, 1, 1, 1);

        stateByte00 = new QLabel(gridLayoutWidget_2);
        stateByte00->setObjectName(QString::fromUtf8("stateByte00"));
        stateByte00->setFont(font);
        stateByte00->setLayoutDirection(Qt::LeftToRight);
        stateByte00->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte00, 1, 0, 1, 1);

        stateByte01 = new QLabel(gridLayoutWidget_2);
        stateByte01->setObjectName(QString::fromUtf8("stateByte01"));
        stateByte01->setFont(font);
        stateByte01->setLayoutDirection(Qt::LeftToRight);
        stateByte01->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte01, 2, 0, 1, 1);

        stateByte02 = new QLabel(gridLayoutWidget_2);
        stateByte02->setObjectName(QString::fromUtf8("stateByte02"));
        stateByte02->setFont(font);
        stateByte02->setLayoutDirection(Qt::LeftToRight);
        stateByte02->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte02, 3, 0, 1, 1);

        stateByte03 = new QLabel(gridLayoutWidget_2);
        stateByte03->setObjectName(QString::fromUtf8("stateByte03"));
        stateByte03->setFont(font);
        stateByte03->setLayoutDirection(Qt::LeftToRight);
        stateByte03->setAlignment(Qt::AlignCenter);

        layoutStateMatrix->addWidget(stateByte03, 4, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(40, 50, 101, 91));
        layoutInputMatrix = new QGridLayout(gridLayoutWidget_3);
        layoutInputMatrix->setObjectName(QString::fromUtf8("layoutInputMatrix"));
        layoutInputMatrix->setContentsMargins(0, 0, 0, 0);
        inputByte00 = new QLabel(gridLayoutWidget_3);
        inputByte00->setObjectName(QString::fromUtf8("inputByte00"));
        inputByte00->setFont(font);
        inputByte00->setLayoutDirection(Qt::LeftToRight);
        inputByte00->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte00, 1, 0, 1, 1);

        inputByte01 = new QLabel(gridLayoutWidget_3);
        inputByte01->setObjectName(QString::fromUtf8("inputByte01"));
        inputByte01->setFont(font);
        inputByte01->setLayoutDirection(Qt::LeftToRight);
        inputByte01->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte01, 2, 0, 1, 1);

        inputByte02 = new QLabel(gridLayoutWidget_3);
        inputByte02->setObjectName(QString::fromUtf8("inputByte02"));
        inputByte02->setFont(font);
        inputByte02->setLayoutDirection(Qt::LeftToRight);
        inputByte02->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte02, 3, 0, 1, 1);

        inputByte03 = new QLabel(gridLayoutWidget_3);
        inputByte03->setObjectName(QString::fromUtf8("inputByte03"));
        inputByte03->setFont(font);
        inputByte03->setLayoutDirection(Qt::LeftToRight);
        inputByte03->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte03, 4, 0, 1, 1);

        inputByte04 = new QLabel(gridLayoutWidget_3);
        inputByte04->setObjectName(QString::fromUtf8("inputByte04"));
        inputByte04->setFont(font);
        inputByte04->setLayoutDirection(Qt::LeftToRight);
        inputByte04->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte04, 1, 1, 1, 1);

        inputByte05 = new QLabel(gridLayoutWidget_3);
        inputByte05->setObjectName(QString::fromUtf8("inputByte05"));
        inputByte05->setFont(font);
        inputByte05->setLayoutDirection(Qt::LeftToRight);
        inputByte05->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte05, 2, 1, 1, 1);

        inputByte06 = new QLabel(gridLayoutWidget_3);
        inputByte06->setObjectName(QString::fromUtf8("inputByte06"));
        inputByte06->setFont(font);
        inputByte06->setLayoutDirection(Qt::LeftToRight);
        inputByte06->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte06, 3, 1, 1, 1);

        inputByte07 = new QLabel(gridLayoutWidget_3);
        inputByte07->setObjectName(QString::fromUtf8("inputByte07"));
        inputByte07->setFont(font);
        inputByte07->setLayoutDirection(Qt::LeftToRight);
        inputByte07->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte07, 4, 1, 1, 1);

        inputByte08 = new QLabel(gridLayoutWidget_3);
        inputByte08->setObjectName(QString::fromUtf8("inputByte08"));
        inputByte08->setFont(font);
        inputByte08->setLayoutDirection(Qt::LeftToRight);
        inputByte08->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte08, 1, 2, 1, 1);

        inputByte09 = new QLabel(gridLayoutWidget_3);
        inputByte09->setObjectName(QString::fromUtf8("inputByte09"));
        inputByte09->setFont(font);
        inputByte09->setLayoutDirection(Qt::LeftToRight);
        inputByte09->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte09, 2, 2, 1, 1);

        inputByte10 = new QLabel(gridLayoutWidget_3);
        inputByte10->setObjectName(QString::fromUtf8("inputByte10"));
        inputByte10->setFont(font);
        inputByte10->setLayoutDirection(Qt::LeftToRight);
        inputByte10->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte10, 3, 2, 1, 1);

        inputByte11 = new QLabel(gridLayoutWidget_3);
        inputByte11->setObjectName(QString::fromUtf8("inputByte11"));
        inputByte11->setFont(font);
        inputByte11->setLayoutDirection(Qt::LeftToRight);
        inputByte11->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte11, 4, 2, 1, 1);

        inputByte12 = new QLabel(gridLayoutWidget_3);
        inputByte12->setObjectName(QString::fromUtf8("inputByte12"));
        inputByte12->setFont(font);
        inputByte12->setLayoutDirection(Qt::LeftToRight);
        inputByte12->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte12, 1, 3, 1, 1);

        inputByte13 = new QLabel(gridLayoutWidget_3);
        inputByte13->setObjectName(QString::fromUtf8("inputByte13"));
        inputByte13->setFont(font);
        inputByte13->setLayoutDirection(Qt::LeftToRight);
        inputByte13->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte13, 2, 3, 1, 1);

        inputByte14 = new QLabel(gridLayoutWidget_3);
        inputByte14->setObjectName(QString::fromUtf8("inputByte14"));
        inputByte14->setFont(font);
        inputByte14->setLayoutDirection(Qt::LeftToRight);
        inputByte14->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte14, 3, 3, 1, 1);

        inputByte15 = new QLabel(gridLayoutWidget_3);
        inputByte15->setObjectName(QString::fromUtf8("inputByte15"));
        inputByte15->setFont(font);
        inputByte15->setLayoutDirection(Qt::LeftToRight);
        inputByte15->setAlignment(Qt::AlignCenter);

        layoutInputMatrix->addWidget(inputByte15, 4, 3, 1, 1);

        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(410, 40, 101, 91));
        layoutOutputMatrix = new QGridLayout(gridLayoutWidget_5);
        layoutOutputMatrix->setObjectName(QString::fromUtf8("layoutOutputMatrix"));
        layoutOutputMatrix->setContentsMargins(0, 0, 0, 0);
        outputByte13 = new QLabel(gridLayoutWidget_5);
        outputByte13->setObjectName(QString::fromUtf8("outputByte13"));
        outputByte13->setFont(font);
        outputByte13->setLayoutDirection(Qt::LeftToRight);
        outputByte13->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte13, 2, 3, 1, 1);

        outputByte15 = new QLabel(gridLayoutWidget_5);
        outputByte15->setObjectName(QString::fromUtf8("outputByte15"));
        outputByte15->setFont(font);
        outputByte15->setLayoutDirection(Qt::LeftToRight);
        outputByte15->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte15, 4, 3, 1, 1);

        outputByte12 = new QLabel(gridLayoutWidget_5);
        outputByte12->setObjectName(QString::fromUtf8("outputByte12"));
        outputByte12->setFont(font);
        outputByte12->setLayoutDirection(Qt::LeftToRight);
        outputByte12->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte12, 1, 3, 1, 1);

        outputByte14 = new QLabel(gridLayoutWidget_5);
        outputByte14->setObjectName(QString::fromUtf8("outputByte14"));
        outputByte14->setFont(font);
        outputByte14->setLayoutDirection(Qt::LeftToRight);
        outputByte14->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte14, 3, 3, 1, 1);

        outputByte09 = new QLabel(gridLayoutWidget_5);
        outputByte09->setObjectName(QString::fromUtf8("outputByte09"));
        outputByte09->setFont(font);
        outputByte09->setLayoutDirection(Qt::LeftToRight);
        outputByte09->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte09, 2, 2, 1, 1);

        outputByte10 = new QLabel(gridLayoutWidget_5);
        outputByte10->setObjectName(QString::fromUtf8("outputByte10"));
        outputByte10->setFont(font);
        outputByte10->setLayoutDirection(Qt::LeftToRight);
        outputByte10->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte10, 3, 2, 1, 1);

        outputByte11 = new QLabel(gridLayoutWidget_5);
        outputByte11->setObjectName(QString::fromUtf8("outputByte11"));
        outputByte11->setFont(font);
        outputByte11->setLayoutDirection(Qt::LeftToRight);
        outputByte11->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte11, 4, 2, 1, 1);

        outputByte08 = new QLabel(gridLayoutWidget_5);
        outputByte08->setObjectName(QString::fromUtf8("outputByte08"));
        outputByte08->setFont(font);
        outputByte08->setLayoutDirection(Qt::LeftToRight);
        outputByte08->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte08, 1, 2, 1, 1);

        outputByte05 = new QLabel(gridLayoutWidget_5);
        outputByte05->setObjectName(QString::fromUtf8("outputByte05"));
        outputByte05->setFont(font);
        outputByte05->setLayoutDirection(Qt::LeftToRight);
        outputByte05->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte05, 2, 1, 1, 1);

        outputByte06 = new QLabel(gridLayoutWidget_5);
        outputByte06->setObjectName(QString::fromUtf8("outputByte06"));
        outputByte06->setFont(font);
        outputByte06->setLayoutDirection(Qt::LeftToRight);
        outputByte06->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte06, 3, 1, 1, 1);

        outputByte07 = new QLabel(gridLayoutWidget_5);
        outputByte07->setObjectName(QString::fromUtf8("outputByte07"));
        outputByte07->setFont(font);
        outputByte07->setLayoutDirection(Qt::LeftToRight);
        outputByte07->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte07, 4, 1, 1, 1);

        outputByte04 = new QLabel(gridLayoutWidget_5);
        outputByte04->setObjectName(QString::fromUtf8("outputByte04"));
        outputByte04->setFont(font);
        outputByte04->setLayoutDirection(Qt::LeftToRight);
        outputByte04->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte04, 1, 1, 1, 1);

        outputByte00 = new QLabel(gridLayoutWidget_5);
        outputByte00->setObjectName(QString::fromUtf8("outputByte00"));
        outputByte00->setFont(font);
        outputByte00->setLayoutDirection(Qt::LeftToRight);
        outputByte00->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte00, 1, 0, 1, 1);

        outputByte01 = new QLabel(gridLayoutWidget_5);
        outputByte01->setObjectName(QString::fromUtf8("outputByte01"));
        outputByte01->setFont(font);
        outputByte01->setLayoutDirection(Qt::LeftToRight);
        outputByte01->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte01, 2, 0, 1, 1);

        outputByte02 = new QLabel(gridLayoutWidget_5);
        outputByte02->setObjectName(QString::fromUtf8("outputByte02"));
        outputByte02->setFont(font);
        outputByte02->setLayoutDirection(Qt::LeftToRight);
        outputByte02->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte02, 3, 0, 1, 1);

        outputByte03 = new QLabel(gridLayoutWidget_5);
        outputByte03->setObjectName(QString::fromUtf8("outputByte03"));
        outputByte03->setFont(font);
        outputByte03->setLayoutDirection(Qt::LeftToRight);
        outputByte03->setAlignment(Qt::AlignCenter);

        layoutOutputMatrix->addWidget(outputByte03, 4, 0, 1, 1);

        labelInputMatrix = new QLabel(centralwidget);
        labelInputMatrix->setObjectName(QString::fromUtf8("labelInputMatrix"));
        labelInputMatrix->setGeometry(QRect(50, 30, 91, 17));
        labelOutputMatrix = new QLabel(centralwidget);
        labelOutputMatrix->setObjectName(QString::fromUtf8("labelOutputMatrix"));
        labelOutputMatrix->setGeometry(QRect(420, 20, 101, 17));
        labelKeyMatrix = new QLabel(centralwidget);
        labelKeyMatrix->setObjectName(QString::fromUtf8("labelKeyMatrix"));
        labelKeyMatrix->setGeometry(QRect(240, 30, 71, 17));
        labelStateMatrix = new QLabel(centralwidget);
        labelStateMatrix->setObjectName(QString::fromUtf8("labelStateMatrix"));
        labelStateMatrix->setGeometry(QRect(230, 180, 91, 17));
        buttonPreviousOp = new QPushButton(centralwidget);
        buttonPreviousOp->setObjectName(QString::fromUtf8("buttonPreviousOp"));
        buttonPreviousOp->setGeometry(QRect(100, 300, 97, 27));
        buttonPreviousOp->setCheckable(false);
        buttonNextOp = new QPushButton(centralwidget);
        buttonNextOp->setObjectName(QString::fromUtf8("buttonNextOp"));
        buttonNextOp->setGeometry(QRect(340, 300, 97, 27));
        buttonFirstOp = new QPushButton(centralwidget);
        buttonFirstOp->setObjectName(QString::fromUtf8("buttonFirstOp"));
        buttonFirstOp->setGeometry(QRect(10, 230, 97, 27));
        buttonLastOp = new QPushButton(centralwidget);
        buttonLastOp->setObjectName(QString::fromUtf8("buttonLastOp"));
        buttonLastOp->setGeometry(QRect(460, 240, 97, 27));
        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(220, 50, 180, 88));
        layoutKeyMatrix = new QGridLayout(gridLayoutWidget_4);
        layoutKeyMatrix->setObjectName(QString::fromUtf8("layoutKeyMatrix"));
        layoutKeyMatrix->setContentsMargins(0, 0, 0, 0);
        keyByte00 = new QLabel(gridLayoutWidget_4);
        keyByte00->setObjectName(QString::fromUtf8("keyByte00"));
        keyByte00->setFont(font);
        keyByte00->setLayoutDirection(Qt::LeftToRight);
        keyByte00->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte00, 0, 0, 1, 1);

        keyByte04 = new QLabel(gridLayoutWidget_4);
        keyByte04->setObjectName(QString::fromUtf8("keyByte04"));
        keyByte04->setFont(font);
        keyByte04->setLayoutDirection(Qt::LeftToRight);
        keyByte04->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte04, 0, 1, 1, 1);

        keyByte08 = new QLabel(gridLayoutWidget_4);
        keyByte08->setObjectName(QString::fromUtf8("keyByte08"));
        keyByte08->setFont(font);
        keyByte08->setLayoutDirection(Qt::LeftToRight);
        keyByte08->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte08, 0, 2, 1, 1);

        keyByte12 = new QLabel(gridLayoutWidget_4);
        keyByte12->setObjectName(QString::fromUtf8("keyByte12"));
        keyByte12->setFont(font);
        keyByte12->setLayoutDirection(Qt::LeftToRight);
        keyByte12->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte12, 0, 3, 1, 1);

        keyByte16 = new QLabel(gridLayoutWidget_4);
        keyByte16->setObjectName(QString::fromUtf8("keyByte16"));
        keyByte16->setFont(font);
        keyByte16->setLayoutDirection(Qt::LeftToRight);
        keyByte16->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte16, 0, 4, 1, 1);

        keyByte20 = new QLabel(gridLayoutWidget_4);
        keyByte20->setObjectName(QString::fromUtf8("keyByte20"));
        keyByte20->setFont(font);
        keyByte20->setLayoutDirection(Qt::LeftToRight);
        keyByte20->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte20, 0, 5, 1, 1);

        keyByte24 = new QLabel(gridLayoutWidget_4);
        keyByte24->setObjectName(QString::fromUtf8("keyByte24"));
        keyByte24->setFont(font);
        keyByte24->setLayoutDirection(Qt::LeftToRight);
        keyByte24->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte24, 0, 6, 1, 1);

        keyByte28 = new QLabel(gridLayoutWidget_4);
        keyByte28->setObjectName(QString::fromUtf8("keyByte28"));
        keyByte28->setFont(font);
        keyByte28->setLayoutDirection(Qt::LeftToRight);
        keyByte28->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte28, 0, 7, 1, 1);

        keyByte01 = new QLabel(gridLayoutWidget_4);
        keyByte01->setObjectName(QString::fromUtf8("keyByte01"));
        keyByte01->setFont(font);
        keyByte01->setLayoutDirection(Qt::LeftToRight);
        keyByte01->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte01, 1, 0, 1, 1);

        keyByte05 = new QLabel(gridLayoutWidget_4);
        keyByte05->setObjectName(QString::fromUtf8("keyByte05"));
        keyByte05->setFont(font);
        keyByte05->setLayoutDirection(Qt::LeftToRight);
        keyByte05->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte05, 1, 1, 1, 1);

        keyByte09 = new QLabel(gridLayoutWidget_4);
        keyByte09->setObjectName(QString::fromUtf8("keyByte09"));
        keyByte09->setFont(font);
        keyByte09->setLayoutDirection(Qt::LeftToRight);
        keyByte09->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte09, 1, 2, 1, 1);

        keyByte13 = new QLabel(gridLayoutWidget_4);
        keyByte13->setObjectName(QString::fromUtf8("keyByte13"));
        keyByte13->setFont(font);
        keyByte13->setLayoutDirection(Qt::LeftToRight);
        keyByte13->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte13, 1, 3, 1, 1);

        keyByte17 = new QLabel(gridLayoutWidget_4);
        keyByte17->setObjectName(QString::fromUtf8("keyByte17"));
        keyByte17->setFont(font);
        keyByte17->setLayoutDirection(Qt::LeftToRight);
        keyByte17->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte17, 1, 4, 1, 1);

        keyByte21 = new QLabel(gridLayoutWidget_4);
        keyByte21->setObjectName(QString::fromUtf8("keyByte21"));
        keyByte21->setFont(font);
        keyByte21->setLayoutDirection(Qt::LeftToRight);
        keyByte21->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte21, 1, 5, 1, 1);

        keyByte25 = new QLabel(gridLayoutWidget_4);
        keyByte25->setObjectName(QString::fromUtf8("keyByte25"));
        keyByte25->setFont(font);
        keyByte25->setLayoutDirection(Qt::LeftToRight);
        keyByte25->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte25, 1, 6, 1, 1);

        keyByte29 = new QLabel(gridLayoutWidget_4);
        keyByte29->setObjectName(QString::fromUtf8("keyByte29"));
        keyByte29->setFont(font);
        keyByte29->setLayoutDirection(Qt::LeftToRight);
        keyByte29->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte29, 1, 7, 1, 1);

        keyByte02 = new QLabel(gridLayoutWidget_4);
        keyByte02->setObjectName(QString::fromUtf8("keyByte02"));
        keyByte02->setFont(font);
        keyByte02->setLayoutDirection(Qt::LeftToRight);
        keyByte02->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte02, 2, 0, 1, 1);

        keyByte06 = new QLabel(gridLayoutWidget_4);
        keyByte06->setObjectName(QString::fromUtf8("keyByte06"));
        keyByte06->setFont(font);
        keyByte06->setLayoutDirection(Qt::LeftToRight);
        keyByte06->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte06, 2, 1, 1, 1);

        keyByte10 = new QLabel(gridLayoutWidget_4);
        keyByte10->setObjectName(QString::fromUtf8("keyByte10"));
        keyByte10->setFont(font);
        keyByte10->setLayoutDirection(Qt::LeftToRight);
        keyByte10->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte10, 2, 2, 1, 1);

        keyByte14 = new QLabel(gridLayoutWidget_4);
        keyByte14->setObjectName(QString::fromUtf8("keyByte14"));
        keyByte14->setFont(font);
        keyByte14->setLayoutDirection(Qt::LeftToRight);
        keyByte14->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte14, 2, 3, 1, 1);

        keyByte18 = new QLabel(gridLayoutWidget_4);
        keyByte18->setObjectName(QString::fromUtf8("keyByte18"));
        keyByte18->setFont(font);
        keyByte18->setLayoutDirection(Qt::LeftToRight);
        keyByte18->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte18, 2, 4, 1, 1);

        keyByte22 = new QLabel(gridLayoutWidget_4);
        keyByte22->setObjectName(QString::fromUtf8("keyByte22"));
        keyByte22->setFont(font);
        keyByte22->setLayoutDirection(Qt::LeftToRight);
        keyByte22->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte22, 2, 5, 1, 1);

        keyByte26 = new QLabel(gridLayoutWidget_4);
        keyByte26->setObjectName(QString::fromUtf8("keyByte26"));
        keyByte26->setFont(font);
        keyByte26->setLayoutDirection(Qt::LeftToRight);
        keyByte26->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte26, 2, 6, 1, 1);

        keyByte30 = new QLabel(gridLayoutWidget_4);
        keyByte30->setObjectName(QString::fromUtf8("keyByte30"));
        keyByte30->setFont(font);
        keyByte30->setLayoutDirection(Qt::LeftToRight);
        keyByte30->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte30, 2, 7, 1, 1);

        keyByte03 = new QLabel(gridLayoutWidget_4);
        keyByte03->setObjectName(QString::fromUtf8("keyByte03"));
        keyByte03->setFont(font);
        keyByte03->setLayoutDirection(Qt::LeftToRight);
        keyByte03->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte03, 3, 0, 1, 1);

        keyByte07 = new QLabel(gridLayoutWidget_4);
        keyByte07->setObjectName(QString::fromUtf8("keyByte07"));
        keyByte07->setFont(font);
        keyByte07->setLayoutDirection(Qt::LeftToRight);
        keyByte07->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte07, 3, 1, 1, 1);

        keyByte11 = new QLabel(gridLayoutWidget_4);
        keyByte11->setObjectName(QString::fromUtf8("keyByte11"));
        keyByte11->setFont(font);
        keyByte11->setLayoutDirection(Qt::LeftToRight);
        keyByte11->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte11, 3, 2, 1, 1);

        keyByte15 = new QLabel(gridLayoutWidget_4);
        keyByte15->setObjectName(QString::fromUtf8("keyByte15"));
        keyByte15->setFont(font);
        keyByte15->setLayoutDirection(Qt::LeftToRight);
        keyByte15->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte15, 3, 3, 1, 1);

        keyByte19 = new QLabel(gridLayoutWidget_4);
        keyByte19->setObjectName(QString::fromUtf8("keyByte19"));
        keyByte19->setFont(font);
        keyByte19->setLayoutDirection(Qt::LeftToRight);
        keyByte19->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte19, 3, 4, 1, 1);

        keyByte23 = new QLabel(gridLayoutWidget_4);
        keyByte23->setObjectName(QString::fromUtf8("keyByte23"));
        keyByte23->setFont(font);
        keyByte23->setLayoutDirection(Qt::LeftToRight);
        keyByte23->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte23, 3, 5, 1, 1);

        keyByte27 = new QLabel(gridLayoutWidget_4);
        keyByte27->setObjectName(QString::fromUtf8("keyByte27"));
        keyByte27->setFont(font);
        keyByte27->setLayoutDirection(Qt::LeftToRight);
        keyByte27->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte27, 3, 6, 1, 1);

        keyByte31 = new QLabel(gridLayoutWidget_4);
        keyByte31->setObjectName(QString::fromUtf8("keyByte31"));
        keyByte31->setFont(font);
        keyByte31->setLayoutDirection(Qt::LeftToRight);
        keyByte31->setAlignment(Qt::AlignCenter);

        layoutKeyMatrix->addWidget(keyByte31, 3, 7, 1, 1);

        gridLayoutWidget_6 = new QWidget(centralwidget);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(340, 200, 101, 97));
        layoutNextMatrix = new QGridLayout(gridLayoutWidget_6);
        layoutNextMatrix->setContentsMargins(0, 0, 0, 0);
        layoutNextMatrix->setObjectName(QString::fromUtf8("layoutNextMatrix"));
        layoutNextMatrix->setContentsMargins(0, 0, 0, 0);
        nextByte13 = new QLabel(gridLayoutWidget_6);
        nextByte13->setObjectName(QString::fromUtf8("nextByte13"));
        nextByte13->setFont(font);
        nextByte13->setLayoutDirection(Qt::LeftToRight);
        nextByte13->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte13, 2, 3, 1, 1);

        nextByte15 = new QLabel(gridLayoutWidget_6);
        nextByte15->setObjectName(QString::fromUtf8("nextByte15"));
        nextByte15->setFont(font);
        nextByte15->setLayoutDirection(Qt::LeftToRight);
        nextByte15->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte15, 4, 3, 1, 1);

        nextByte12 = new QLabel(gridLayoutWidget_6);
        nextByte12->setObjectName(QString::fromUtf8("nextByte12"));
        nextByte12->setFont(font);
        nextByte12->setLayoutDirection(Qt::LeftToRight);
        nextByte12->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte12, 1, 3, 1, 1);

        nextByte14 = new QLabel(gridLayoutWidget_6);
        nextByte14->setObjectName(QString::fromUtf8("nextByte14"));
        nextByte14->setFont(font);
        nextByte14->setLayoutDirection(Qt::LeftToRight);
        nextByte14->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte14, 3, 3, 1, 1);

        nextByte09 = new QLabel(gridLayoutWidget_6);
        nextByte09->setObjectName(QString::fromUtf8("nextByte09"));
        nextByte09->setFont(font);
        nextByte09->setLayoutDirection(Qt::LeftToRight);
        nextByte09->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte09, 2, 2, 1, 1);

        nextByte10 = new QLabel(gridLayoutWidget_6);
        nextByte10->setObjectName(QString::fromUtf8("nextByte10"));
        nextByte10->setFont(font);
        nextByte10->setLayoutDirection(Qt::LeftToRight);
        nextByte10->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte10, 3, 2, 1, 1);

        nextByte11 = new QLabel(gridLayoutWidget_6);
        nextByte11->setObjectName(QString::fromUtf8("nextByte11"));
        nextByte11->setFont(font);
        nextByte11->setLayoutDirection(Qt::LeftToRight);
        nextByte11->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte11, 4, 2, 1, 1);

        nextByte08 = new QLabel(gridLayoutWidget_6);
        nextByte08->setObjectName(QString::fromUtf8("nextByte08"));
        nextByte08->setFont(font);
        nextByte08->setLayoutDirection(Qt::LeftToRight);
        nextByte08->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte08, 1, 2, 1, 1);

        nextByte05 = new QLabel(gridLayoutWidget_6);
        nextByte05->setObjectName(QString::fromUtf8("nextByte05"));
        nextByte05->setFont(font);
        nextByte05->setLayoutDirection(Qt::LeftToRight);
        nextByte05->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte05, 2, 1, 1, 1);

        nextByte06 = new QLabel(gridLayoutWidget_6);
        nextByte06->setObjectName(QString::fromUtf8("nextByte06"));
        nextByte06->setFont(font);
        nextByte06->setLayoutDirection(Qt::LeftToRight);
        nextByte06->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte06, 3, 1, 1, 1);

        nextByte07 = new QLabel(gridLayoutWidget_6);
        nextByte07->setObjectName(QString::fromUtf8("nextByte07"));
        nextByte07->setFont(font);
        nextByte07->setLayoutDirection(Qt::LeftToRight);
        nextByte07->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte07, 4, 1, 1, 1);

        nextByte04 = new QLabel(gridLayoutWidget_6);
        nextByte04->setObjectName(QString::fromUtf8("nextByte04"));
        nextByte04->setFont(font);
        nextByte04->setLayoutDirection(Qt::LeftToRight);
        nextByte04->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte04, 1, 1, 1, 1);

        nextByte00 = new QLabel(gridLayoutWidget_6);
        nextByte00->setObjectName(QString::fromUtf8("nextByte00"));
        nextByte00->setFont(font);
        nextByte00->setLayoutDirection(Qt::LeftToRight);
        nextByte00->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte00, 1, 0, 1, 1);

        nextByte01 = new QLabel(gridLayoutWidget_6);
        nextByte01->setObjectName(QString::fromUtf8("nextByte01"));
        nextByte01->setFont(font);
        nextByte01->setLayoutDirection(Qt::LeftToRight);
        nextByte01->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte01, 2, 0, 1, 1);

        nextByte02 = new QLabel(gridLayoutWidget_6);
        nextByte02->setObjectName(QString::fromUtf8("nextByte02"));
        nextByte02->setFont(font);
        nextByte02->setLayoutDirection(Qt::LeftToRight);
        nextByte02->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte02, 3, 0, 1, 1);

        nextByte03 = new QLabel(gridLayoutWidget_6);
        nextByte03->setObjectName(QString::fromUtf8("nextByte03"));
        nextByte03->setFont(font);
        nextByte03->setLayoutDirection(Qt::LeftToRight);
        nextByte03->setAlignment(Qt::AlignCenter);

        layoutNextMatrix->addWidget(nextByte03, 4, 0, 1, 1);

        gridLayoutWidget_7 = new QWidget(centralwidget);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(110, 200, 101, 97));
        layoutPreviousMatrix = new QGridLayout(gridLayoutWidget_7);
        layoutPreviousMatrix->setContentsMargins(0, 0, 0, 0);
        layoutPreviousMatrix->setObjectName(QString::fromUtf8("layoutPreviousMatrix"));
        layoutPreviousMatrix->setContentsMargins(0, 0, 0, 0);
        previousByte13 = new QLabel(gridLayoutWidget_7);
        previousByte13->setObjectName(QString::fromUtf8("previousByte13"));
        previousByte13->setFont(font);
        previousByte13->setLayoutDirection(Qt::LeftToRight);
        previousByte13->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte13, 2, 3, 1, 1);

        previousByte15 = new QLabel(gridLayoutWidget_7);
        previousByte15->setObjectName(QString::fromUtf8("previousByte15"));
        previousByte15->setFont(font);
        previousByte15->setLayoutDirection(Qt::LeftToRight);
        previousByte15->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte15, 4, 3, 1, 1);

        previousByte12 = new QLabel(gridLayoutWidget_7);
        previousByte12->setObjectName(QString::fromUtf8("previousByte12"));
        previousByte12->setFont(font);
        previousByte12->setLayoutDirection(Qt::LeftToRight);
        previousByte12->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte12, 1, 3, 1, 1);

        previousByte14 = new QLabel(gridLayoutWidget_7);
        previousByte14->setObjectName(QString::fromUtf8("previousByte14"));
        previousByte14->setFont(font);
        previousByte14->setLayoutDirection(Qt::LeftToRight);
        previousByte14->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte14, 3, 3, 1, 1);

        previousByte09 = new QLabel(gridLayoutWidget_7);
        previousByte09->setObjectName(QString::fromUtf8("previousByte09"));
        previousByte09->setFont(font);
        previousByte09->setLayoutDirection(Qt::LeftToRight);
        previousByte09->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte09, 2, 2, 1, 1);

        previousByte10 = new QLabel(gridLayoutWidget_7);
        previousByte10->setObjectName(QString::fromUtf8("previousByte10"));
        previousByte10->setFont(font);
        previousByte10->setLayoutDirection(Qt::LeftToRight);
        previousByte10->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte10, 3, 2, 1, 1);

        previousByte11 = new QLabel(gridLayoutWidget_7);
        previousByte11->setObjectName(QString::fromUtf8("previousByte11"));
        previousByte11->setFont(font);
        previousByte11->setLayoutDirection(Qt::LeftToRight);
        previousByte11->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte11, 4, 2, 1, 1);

        previousByte08 = new QLabel(gridLayoutWidget_7);
        previousByte08->setObjectName(QString::fromUtf8("previousByte08"));
        previousByte08->setFont(font);
        previousByte08->setLayoutDirection(Qt::LeftToRight);
        previousByte08->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte08, 1, 2, 1, 1);

        previousByte05 = new QLabel(gridLayoutWidget_7);
        previousByte05->setObjectName(QString::fromUtf8("previousByte05"));
        previousByte05->setFont(font);
        previousByte05->setLayoutDirection(Qt::LeftToRight);
        previousByte05->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte05, 2, 1, 1, 1);

        previousByte06 = new QLabel(gridLayoutWidget_7);
        previousByte06->setObjectName(QString::fromUtf8("previousByte06"));
        previousByte06->setFont(font);
        previousByte06->setLayoutDirection(Qt::LeftToRight);
        previousByte06->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte06, 3, 1, 1, 1);

        previousByte07 = new QLabel(gridLayoutWidget_7);
        previousByte07->setObjectName(QString::fromUtf8("previousByte07"));
        previousByte07->setFont(font);
        previousByte07->setLayoutDirection(Qt::LeftToRight);
        previousByte07->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte07, 4, 1, 1, 1);

        previousByte04 = new QLabel(gridLayoutWidget_7);
        previousByte04->setObjectName(QString::fromUtf8("previousByte04"));
        previousByte04->setFont(font);
        previousByte04->setLayoutDirection(Qt::LeftToRight);
        previousByte04->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte04, 1, 1, 1, 1);

        previousByte00 = new QLabel(gridLayoutWidget_7);
        previousByte00->setObjectName(QString::fromUtf8("previousByte00"));
        previousByte00->setFont(font);
        previousByte00->setLayoutDirection(Qt::LeftToRight);
        previousByte00->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte00, 1, 0, 1, 1);

        previousByte01 = new QLabel(gridLayoutWidget_7);
        previousByte01->setObjectName(QString::fromUtf8("previousByte01"));
        previousByte01->setFont(font);
        previousByte01->setLayoutDirection(Qt::LeftToRight);
        previousByte01->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte01, 2, 0, 1, 1);

        previousByte02 = new QLabel(gridLayoutWidget_7);
        previousByte02->setObjectName(QString::fromUtf8("previousByte02"));
        previousByte02->setFont(font);
        previousByte02->setLayoutDirection(Qt::LeftToRight);
        previousByte02->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte02, 3, 0, 1, 1);

        previousByte03 = new QLabel(gridLayoutWidget_7);
        previousByte03->setObjectName(QString::fromUtf8("previousByte03"));
        previousByte03->setFont(font);
        previousByte03->setLayoutDirection(Qt::LeftToRight);
        previousByte03->setAlignment(Qt::AlignCenter);

        layoutPreviousMatrix->addWidget(previousByte03, 4, 0, 1, 1);

        labelRound = new QLabel(centralwidget);
        labelRound->setObjectName(QString::fromUtf8("labelRound"));
        labelRound->setGeometry(QRect(80, 350, 41, 17));
        labelRoundNumber = new QLabel(centralwidget);
        labelRoundNumber->setObjectName(QString::fromUtf8("labelRoundNumber"));
        labelRoundNumber->setGeometry(QRect(130, 350, 21, 17));
        labelOperation = new QLabel(centralwidget);
        labelOperation->setObjectName(QString::fromUtf8("labelOperation"));
        labelOperation->setGeometry(QRect(210, 350, 71, 17));
        labelOperationDesc = new QLabel(centralwidget);
        labelOperationDesc->setObjectName(QString::fromUtf8("labelOperationDesc"));
        labelOperationDesc->setGeometry(QRect(290, 350, 161, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewRijndael);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuEdit->addAction(actionSetInputMatrix);
        menuEdit->addAction(actionSetKeyMatrix);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "YAAES", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionNewRijndael->setText(QApplication::translate("MainWindow", "New Rijndael", 0, QApplication::UnicodeUTF8));
        actionSetInputMatrix->setText(QApplication::translate("MainWindow", "Set Input Matrix", 0, QApplication::UnicodeUTF8));
        actionSetKeyMatrix->setText(QApplication::translate("MainWindow", "Set Key Matrix", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        stateByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        labelInputMatrix->setText(QApplication::translate("MainWindow", "Input Matrix", 0, QApplication::UnicodeUTF8));
        labelOutputMatrix->setText(QApplication::translate("MainWindow", "Output Matrix", 0, QApplication::UnicodeUTF8));
        labelKeyMatrix->setText(QApplication::translate("MainWindow", "Key Matrix", 0, QApplication::UnicodeUTF8));
        labelStateMatrix->setText(QApplication::translate("MainWindow", "State Matrix", 0, QApplication::UnicodeUTF8));
        buttonPreviousOp->setText(QApplication::translate("MainWindow", "Previous", 0, QApplication::UnicodeUTF8));
        buttonNextOp->setText(QApplication::translate("MainWindow", "Next", 0, QApplication::UnicodeUTF8));
        buttonFirstOp->setText(QApplication::translate("MainWindow", "First", 0, QApplication::UnicodeUTF8));
        buttonLastOp->setText(QApplication::translate("MainWindow", "Last", 0, QApplication::UnicodeUTF8));
        keyByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte16->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte20->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte24->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte28->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte17->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte21->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte25->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte29->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte18->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte22->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte26->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte30->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte19->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte23->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte27->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte31->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        labelRound->setText(QApplication::translate("MainWindow", "Round", 0, QApplication::UnicodeUTF8));
        labelRoundNumber->setText(QApplication::translate("MainWindow", "99", 0, QApplication::UnicodeUTF8));
        labelOperation->setText(QApplication::translate("MainWindow", "Operation", 0, QApplication::UnicodeUTF8));
        labelOperationDesc->setText(QApplication::translate("MainWindow", "AddRoundKey", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
