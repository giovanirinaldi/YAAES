/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Apr 24 22:17:19 2012
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
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
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
    QPushButton *buttonPreviousOp;
    QPushButton *buttonNextOp;
    QPushButton *buttonFirstOp;
    QPushButton *buttonLastOp;
    QLabel *labelRoundNumber;
    QLabel *labelOperationDesc;
    QGroupBox *groupOutput;
    QLabel *outputByte15;
    QLabel *outputByte04;
    QLabel *outputByte05;
    QLabel *outputByte10;
    QLabel *outputByte12;
    QLabel *outputByte06;
    QLabel *outputByte11;
    QLabel *outputByte13;
    QLabel *outputByte14;
    QLabel *outputByte00;
    QLabel *outputByte01;
    QLabel *outputByte02;
    QLabel *outputByte09;
    QLabel *outputByte08;
    QLabel *outputByte03;
    QLabel *outputByte07;
    QGroupBox *groupInput;
    QLabel *inputByte15;
    QLabel *inputByte13;
    QLabel *inputByte14;
    QLabel *inputByte06;
    QLabel *inputByte04;
    QLabel *inputByte02;
    QLabel *inputByte10;
    QLabel *inputByte09;
    QLabel *inputByte01;
    QLabel *inputByte08;
    QLabel *inputByte00;
    QLabel *inputByte07;
    QLabel *inputByte12;
    QLabel *inputByte03;
    QLabel *inputByte11;
    QLabel *inputByte05;
    QToolButton *btnEditInput;
    QGroupBox *groupKey;
    QLabel *keyByte31;
    QLabel *keyByte08;
    QLabel *keyByte17;
    QLabel *keyByte10;
    QLabel *keyByte00;
    QLabel *keyByte20;
    QLabel *keyByte23;
    QLabel *keyByte11;
    QLabel *keyByte27;
    QLabel *keyByte22;
    QLabel *keyByte01;
    QLabel *keyByte06;
    QLabel *keyByte30;
    QLabel *keyByte12;
    QLabel *keyByte21;
    QLabel *keyByte26;
    QLabel *keyByte02;
    QLabel *keyByte14;
    QLabel *keyByte15;
    QLabel *keyByte05;
    QLabel *keyByte04;
    QLabel *keyByte18;
    QLabel *keyByte13;
    QLabel *keyByte24;
    QLabel *keyByte07;
    QLabel *keyByte16;
    QLabel *keyByte25;
    QLabel *keyByte03;
    QLabel *keyByte09;
    QLabel *keyByte19;
    QLabel *keyByte29;
    QLabel *keyByte28;
    QToolButton *btnEditKey;
    QPushButton *btnShowKey;
    QGroupBox *groupPrevious;
    QLabel *previousByte15;
    QLabel *previousByte05;
    QLabel *previousByte03;
    QLabel *previousByte08;
    QLabel *previousByte09;
    QLabel *previousByte00;
    QLabel *previousByte04;
    QLabel *previousByte07;
    QLabel *previousByte14;
    QLabel *previousByte01;
    QLabel *previousByte10;
    QLabel *previousByte11;
    QLabel *previousByte02;
    QLabel *previousByte06;
    QLabel *previousByte12;
    QLabel *previousByte13;
    QGroupBox *groupState;
    QLabel *stateByte15;
    QLabel *stateByte07;
    QLabel *stateByte06;
    QLabel *stateByte11;
    QLabel *stateByte03;
    QLabel *stateByte10;
    QLabel *stateByte12;
    QLabel *stateByte13;
    QLabel *stateByte05;
    QLabel *stateByte02;
    QLabel *stateByte08;
    QLabel *stateByte00;
    QLabel *stateByte01;
    QLabel *stateByte14;
    QLabel *stateByte04;
    QLabel *stateByte09;
    QGroupBox *groupNext;
    QLabel *nextByte15;
    QLabel *nextByte01;
    QLabel *nextByte09;
    QLabel *nextByte14;
    QLabel *nextByte03;
    QLabel *nextByte10;
    QLabel *nextByte00;
    QLabel *nextByte06;
    QLabel *nextByte11;
    QLabel *nextByte13;
    QLabel *nextByte05;
    QLabel *nextByte07;
    QLabel *nextByte12;
    QLabel *nextByte02;
    QLabel *nextByte08;
    QLabel *nextByte04;
    QLabel *labelPrevOperationDesc;
    QLabel *labelRound;
    QFrame *line;
    QPushButton *btnShowNextOp;
    QPushButton *btnShowPreviousOp;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(609, 514);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(609, 514));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-image: url(imageD.png);\n"
"	background-color: white;\n"
"}"));
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
        buttonPreviousOp = new QPushButton(centralwidget);
        buttonPreviousOp->setObjectName(QString::fromUtf8("buttonPreviousOp"));
        buttonPreviousOp->setGeometry(QRect(210, 420, 101, 27));
        buttonPreviousOp->setCheckable(false);
        buttonNextOp = new QPushButton(centralwidget);
        buttonNextOp->setObjectName(QString::fromUtf8("buttonNextOp"));
        buttonNextOp->setGeometry(QRect(320, 420, 101, 27));
        buttonFirstOp = new QPushButton(centralwidget);
        buttonFirstOp->setObjectName(QString::fromUtf8("buttonFirstOp"));
        buttonFirstOp->setGeometry(QRect(100, 420, 101, 27));
        buttonLastOp = new QPushButton(centralwidget);
        buttonLastOp->setObjectName(QString::fromUtf8("buttonLastOp"));
        buttonLastOp->setGeometry(QRect(430, 420, 101, 27));
        labelRoundNumber = new QLabel(centralwidget);
        labelRoundNumber->setObjectName(QString::fromUtf8("labelRoundNumber"));
        labelRoundNumber->setGeometry(QRect(330, 380, 21, 17));
        labelOperationDesc = new QLabel(centralwidget);
        labelOperationDesc->setObjectName(QString::fromUtf8("labelOperationDesc"));
        labelOperationDesc->setGeometry(QRect(375, 280, 101, 17));
        labelOperationDesc->setAlignment(Qt::AlignCenter);
        groupOutput = new QGroupBox(centralwidget);
        groupOutput->setObjectName(QString::fromUtf8("groupOutput"));
        groupOutput->setGeometry(QRect(455, 20, 150, 150));
        sizePolicy.setHeightForWidth(groupOutput->sizePolicy().hasHeightForWidth());
        groupOutput->setSizePolicy(sizePolicy);
        groupOutput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupOutput->setFlat(false);
        groupOutput->setCheckable(false);
        outputByte15 = new QLabel(groupOutput);
        outputByte15->setObjectName(QString::fromUtf8("outputByte15"));
        outputByte15->setGeometry(QRect(98, 102, 25, 25));
        sizePolicy.setHeightForWidth(outputByte15->sizePolicy().hasHeightForWidth());
        outputByte15->setSizePolicy(sizePolicy);
        QFont font;
        font.setKerning(true);
        outputByte15->setFont(font);
        outputByte15->setLayoutDirection(Qt::LeftToRight);
        outputByte15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte15->setAlignment(Qt::AlignCenter);
        outputByte04 = new QLabel(groupOutput);
        outputByte04->setObjectName(QString::fromUtf8("outputByte04"));
        outputByte04->setGeometry(QRect(50, 30, 25, 25));
        sizePolicy.setHeightForWidth(outputByte04->sizePolicy().hasHeightForWidth());
        outputByte04->setSizePolicy(sizePolicy);
        outputByte04->setFont(font);
        outputByte04->setLayoutDirection(Qt::LeftToRight);
        outputByte04->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte04->setAlignment(Qt::AlignCenter);
        outputByte05 = new QLabel(groupOutput);
        outputByte05->setObjectName(QString::fromUtf8("outputByte05"));
        outputByte05->setGeometry(QRect(50, 54, 25, 25));
        sizePolicy.setHeightForWidth(outputByte05->sizePolicy().hasHeightForWidth());
        outputByte05->setSizePolicy(sizePolicy);
        outputByte05->setFont(font);
        outputByte05->setLayoutDirection(Qt::LeftToRight);
        outputByte05->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte05->setAlignment(Qt::AlignCenter);
        outputByte10 = new QLabel(groupOutput);
        outputByte10->setObjectName(QString::fromUtf8("outputByte10"));
        outputByte10->setGeometry(QRect(74, 78, 25, 25));
        sizePolicy.setHeightForWidth(outputByte10->sizePolicy().hasHeightForWidth());
        outputByte10->setSizePolicy(sizePolicy);
        outputByte10->setFont(font);
        outputByte10->setLayoutDirection(Qt::LeftToRight);
        outputByte10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte10->setAlignment(Qt::AlignCenter);
        outputByte12 = new QLabel(groupOutput);
        outputByte12->setObjectName(QString::fromUtf8("outputByte12"));
        outputByte12->setGeometry(QRect(98, 30, 25, 25));
        sizePolicy.setHeightForWidth(outputByte12->sizePolicy().hasHeightForWidth());
        outputByte12->setSizePolicy(sizePolicy);
        outputByte12->setFont(font);
        outputByte12->setLayoutDirection(Qt::LeftToRight);
        outputByte12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte12->setAlignment(Qt::AlignCenter);
        outputByte06 = new QLabel(groupOutput);
        outputByte06->setObjectName(QString::fromUtf8("outputByte06"));
        outputByte06->setGeometry(QRect(50, 78, 25, 25));
        sizePolicy.setHeightForWidth(outputByte06->sizePolicy().hasHeightForWidth());
        outputByte06->setSizePolicy(sizePolicy);
        outputByte06->setFont(font);
        outputByte06->setLayoutDirection(Qt::LeftToRight);
        outputByte06->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte06->setAlignment(Qt::AlignCenter);
        outputByte11 = new QLabel(groupOutput);
        outputByte11->setObjectName(QString::fromUtf8("outputByte11"));
        outputByte11->setGeometry(QRect(74, 102, 25, 25));
        sizePolicy.setHeightForWidth(outputByte11->sizePolicy().hasHeightForWidth());
        outputByte11->setSizePolicy(sizePolicy);
        outputByte11->setFont(font);
        outputByte11->setLayoutDirection(Qt::LeftToRight);
        outputByte11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte11->setAlignment(Qt::AlignCenter);
        outputByte13 = new QLabel(groupOutput);
        outputByte13->setObjectName(QString::fromUtf8("outputByte13"));
        outputByte13->setGeometry(QRect(98, 54, 25, 25));
        sizePolicy.setHeightForWidth(outputByte13->sizePolicy().hasHeightForWidth());
        outputByte13->setSizePolicy(sizePolicy);
        outputByte13->setFont(font);
        outputByte13->setLayoutDirection(Qt::LeftToRight);
        outputByte13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte13->setAlignment(Qt::AlignCenter);
        outputByte14 = new QLabel(groupOutput);
        outputByte14->setObjectName(QString::fromUtf8("outputByte14"));
        outputByte14->setGeometry(QRect(98, 78, 25, 25));
        sizePolicy.setHeightForWidth(outputByte14->sizePolicy().hasHeightForWidth());
        outputByte14->setSizePolicy(sizePolicy);
        outputByte14->setFont(font);
        outputByte14->setLayoutDirection(Qt::LeftToRight);
        outputByte14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte14->setAlignment(Qt::AlignCenter);
        outputByte00 = new QLabel(groupOutput);
        outputByte00->setObjectName(QString::fromUtf8("outputByte00"));
        outputByte00->setGeometry(QRect(26, 30, 25, 25));
        sizePolicy.setHeightForWidth(outputByte00->sizePolicy().hasHeightForWidth());
        outputByte00->setSizePolicy(sizePolicy);
        outputByte00->setFont(font);
        outputByte00->setLayoutDirection(Qt::LeftToRight);
        outputByte00->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte00->setAlignment(Qt::AlignCenter);
        outputByte01 = new QLabel(groupOutput);
        outputByte01->setObjectName(QString::fromUtf8("outputByte01"));
        outputByte01->setGeometry(QRect(26, 54, 25, 25));
        sizePolicy.setHeightForWidth(outputByte01->sizePolicy().hasHeightForWidth());
        outputByte01->setSizePolicy(sizePolicy);
        outputByte01->setFont(font);
        outputByte01->setLayoutDirection(Qt::LeftToRight);
        outputByte01->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte01->setAlignment(Qt::AlignCenter);
        outputByte02 = new QLabel(groupOutput);
        outputByte02->setObjectName(QString::fromUtf8("outputByte02"));
        outputByte02->setGeometry(QRect(26, 78, 25, 25));
        sizePolicy.setHeightForWidth(outputByte02->sizePolicy().hasHeightForWidth());
        outputByte02->setSizePolicy(sizePolicy);
        outputByte02->setFont(font);
        outputByte02->setLayoutDirection(Qt::LeftToRight);
        outputByte02->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte02->setAlignment(Qt::AlignCenter);
        outputByte09 = new QLabel(groupOutput);
        outputByte09->setObjectName(QString::fromUtf8("outputByte09"));
        outputByte09->setGeometry(QRect(74, 54, 25, 25));
        sizePolicy.setHeightForWidth(outputByte09->sizePolicy().hasHeightForWidth());
        outputByte09->setSizePolicy(sizePolicy);
        outputByte09->setFont(font);
        outputByte09->setLayoutDirection(Qt::LeftToRight);
        outputByte09->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte09->setAlignment(Qt::AlignCenter);
        outputByte08 = new QLabel(groupOutput);
        outputByte08->setObjectName(QString::fromUtf8("outputByte08"));
        outputByte08->setGeometry(QRect(74, 30, 25, 25));
        sizePolicy.setHeightForWidth(outputByte08->sizePolicy().hasHeightForWidth());
        outputByte08->setSizePolicy(sizePolicy);
        outputByte08->setFont(font);
        outputByte08->setLayoutDirection(Qt::LeftToRight);
        outputByte08->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte08->setAlignment(Qt::AlignCenter);
        outputByte03 = new QLabel(groupOutput);
        outputByte03->setObjectName(QString::fromUtf8("outputByte03"));
        outputByte03->setGeometry(QRect(26, 102, 25, 25));
        sizePolicy.setHeightForWidth(outputByte03->sizePolicy().hasHeightForWidth());
        outputByte03->setSizePolicy(sizePolicy);
        outputByte03->setFont(font);
        outputByte03->setLayoutDirection(Qt::LeftToRight);
        outputByte03->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte03->setAlignment(Qt::AlignCenter);
        outputByte07 = new QLabel(groupOutput);
        outputByte07->setObjectName(QString::fromUtf8("outputByte07"));
        outputByte07->setGeometry(QRect(50, 102, 25, 25));
        sizePolicy.setHeightForWidth(outputByte07->sizePolicy().hasHeightForWidth());
        outputByte07->setSizePolicy(sizePolicy);
        outputByte07->setFont(font);
        outputByte07->setLayoutDirection(Qt::LeftToRight);
        outputByte07->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        outputByte07->setAlignment(Qt::AlignCenter);
        groupInput = new QGroupBox(centralwidget);
        groupInput->setObjectName(QString::fromUtf8("groupInput"));
        groupInput->setGeometry(QRect(20, 20, 150, 150));
        sizePolicy.setHeightForWidth(groupInput->sizePolicy().hasHeightForWidth());
        groupInput->setSizePolicy(sizePolicy);
        groupInput->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        inputByte15 = new QLabel(groupInput);
        inputByte15->setObjectName(QString::fromUtf8("inputByte15"));
        inputByte15->setEnabled(true);
        inputByte15->setGeometry(QRect(98, 102, 25, 25));
        sizePolicy.setHeightForWidth(inputByte15->sizePolicy().hasHeightForWidth());
        inputByte15->setSizePolicy(sizePolicy);
        inputByte15->setFont(font);
        inputByte15->setLayoutDirection(Qt::LeftToRight);
        inputByte15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte15->setAlignment(Qt::AlignCenter);
        inputByte13 = new QLabel(groupInput);
        inputByte13->setObjectName(QString::fromUtf8("inputByte13"));
        inputByte13->setEnabled(true);
        inputByte13->setGeometry(QRect(98, 54, 25, 25));
        sizePolicy.setHeightForWidth(inputByte13->sizePolicy().hasHeightForWidth());
        inputByte13->setSizePolicy(sizePolicy);
        inputByte13->setFont(font);
        inputByte13->setLayoutDirection(Qt::LeftToRight);
        inputByte13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte13->setAlignment(Qt::AlignCenter);
        inputByte14 = new QLabel(groupInput);
        inputByte14->setObjectName(QString::fromUtf8("inputByte14"));
        inputByte14->setEnabled(true);
        inputByte14->setGeometry(QRect(98, 78, 25, 25));
        sizePolicy.setHeightForWidth(inputByte14->sizePolicy().hasHeightForWidth());
        inputByte14->setSizePolicy(sizePolicy);
        inputByte14->setFont(font);
        inputByte14->setLayoutDirection(Qt::LeftToRight);
        inputByte14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte14->setAlignment(Qt::AlignCenter);
        inputByte06 = new QLabel(groupInput);
        inputByte06->setObjectName(QString::fromUtf8("inputByte06"));
        inputByte06->setEnabled(true);
        inputByte06->setGeometry(QRect(50, 78, 25, 25));
        sizePolicy.setHeightForWidth(inputByte06->sizePolicy().hasHeightForWidth());
        inputByte06->setSizePolicy(sizePolicy);
        inputByte06->setFont(font);
        inputByte06->setLayoutDirection(Qt::LeftToRight);
        inputByte06->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte06->setAlignment(Qt::AlignCenter);
        inputByte04 = new QLabel(groupInput);
        inputByte04->setObjectName(QString::fromUtf8("inputByte04"));
        inputByte04->setEnabled(true);
        inputByte04->setGeometry(QRect(50, 30, 25, 25));
        sizePolicy.setHeightForWidth(inputByte04->sizePolicy().hasHeightForWidth());
        inputByte04->setSizePolicy(sizePolicy);
        inputByte04->setFont(font);
        inputByte04->setLayoutDirection(Qt::LeftToRight);
        inputByte04->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte04->setAlignment(Qt::AlignCenter);
        inputByte02 = new QLabel(groupInput);
        inputByte02->setObjectName(QString::fromUtf8("inputByte02"));
        inputByte02->setEnabled(true);
        inputByte02->setGeometry(QRect(26, 78, 25, 25));
        sizePolicy.setHeightForWidth(inputByte02->sizePolicy().hasHeightForWidth());
        inputByte02->setSizePolicy(sizePolicy);
        inputByte02->setFont(font);
        inputByte02->setLayoutDirection(Qt::LeftToRight);
        inputByte02->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte02->setAlignment(Qt::AlignCenter);
        inputByte10 = new QLabel(groupInput);
        inputByte10->setObjectName(QString::fromUtf8("inputByte10"));
        inputByte10->setEnabled(true);
        inputByte10->setGeometry(QRect(74, 78, 25, 25));
        sizePolicy.setHeightForWidth(inputByte10->sizePolicy().hasHeightForWidth());
        inputByte10->setSizePolicy(sizePolicy);
        inputByte10->setFont(font);
        inputByte10->setLayoutDirection(Qt::LeftToRight);
        inputByte10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte10->setAlignment(Qt::AlignCenter);
        inputByte09 = new QLabel(groupInput);
        inputByte09->setObjectName(QString::fromUtf8("inputByte09"));
        inputByte09->setEnabled(true);
        inputByte09->setGeometry(QRect(74, 54, 25, 25));
        sizePolicy.setHeightForWidth(inputByte09->sizePolicy().hasHeightForWidth());
        inputByte09->setSizePolicy(sizePolicy);
        inputByte09->setFont(font);
        inputByte09->setLayoutDirection(Qt::LeftToRight);
        inputByte09->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte09->setAlignment(Qt::AlignCenter);
        inputByte01 = new QLabel(groupInput);
        inputByte01->setObjectName(QString::fromUtf8("inputByte01"));
        inputByte01->setEnabled(true);
        inputByte01->setGeometry(QRect(26, 54, 25, 25));
        sizePolicy.setHeightForWidth(inputByte01->sizePolicy().hasHeightForWidth());
        inputByte01->setSizePolicy(sizePolicy);
        inputByte01->setFont(font);
        inputByte01->setLayoutDirection(Qt::LeftToRight);
        inputByte01->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte01->setAlignment(Qt::AlignCenter);
        inputByte08 = new QLabel(groupInput);
        inputByte08->setObjectName(QString::fromUtf8("inputByte08"));
        inputByte08->setEnabled(true);
        inputByte08->setGeometry(QRect(74, 30, 25, 25));
        sizePolicy.setHeightForWidth(inputByte08->sizePolicy().hasHeightForWidth());
        inputByte08->setSizePolicy(sizePolicy);
        inputByte08->setFont(font);
        inputByte08->setLayoutDirection(Qt::LeftToRight);
        inputByte08->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte08->setAlignment(Qt::AlignCenter);
        inputByte00 = new QLabel(groupInput);
        inputByte00->setObjectName(QString::fromUtf8("inputByte00"));
        inputByte00->setEnabled(true);
        inputByte00->setGeometry(QRect(26, 30, 25, 25));
        sizePolicy.setHeightForWidth(inputByte00->sizePolicy().hasHeightForWidth());
        inputByte00->setSizePolicy(sizePolicy);
        inputByte00->setFont(font);
        inputByte00->setLayoutDirection(Qt::LeftToRight);
        inputByte00->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte00->setAlignment(Qt::AlignCenter);
        inputByte00->setWordWrap(false);
        inputByte07 = new QLabel(groupInput);
        inputByte07->setObjectName(QString::fromUtf8("inputByte07"));
        inputByte07->setEnabled(true);
        inputByte07->setGeometry(QRect(50, 102, 25, 25));
        sizePolicy.setHeightForWidth(inputByte07->sizePolicy().hasHeightForWidth());
        inputByte07->setSizePolicy(sizePolicy);
        inputByte07->setFont(font);
        inputByte07->setLayoutDirection(Qt::LeftToRight);
        inputByte07->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte07->setAlignment(Qt::AlignCenter);
        inputByte12 = new QLabel(groupInput);
        inputByte12->setObjectName(QString::fromUtf8("inputByte12"));
        inputByte12->setEnabled(true);
        inputByte12->setGeometry(QRect(98, 30, 25, 25));
        sizePolicy.setHeightForWidth(inputByte12->sizePolicy().hasHeightForWidth());
        inputByte12->setSizePolicy(sizePolicy);
        inputByte12->setFont(font);
        inputByte12->setLayoutDirection(Qt::LeftToRight);
        inputByte12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte12->setAlignment(Qt::AlignCenter);
        inputByte03 = new QLabel(groupInput);
        inputByte03->setObjectName(QString::fromUtf8("inputByte03"));
        inputByte03->setEnabled(true);
        inputByte03->setGeometry(QRect(26, 102, 25, 25));
        sizePolicy.setHeightForWidth(inputByte03->sizePolicy().hasHeightForWidth());
        inputByte03->setSizePolicy(sizePolicy);
        inputByte03->setFont(font);
        inputByte03->setLayoutDirection(Qt::LeftToRight);
        inputByte03->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte03->setAlignment(Qt::AlignCenter);
        inputByte11 = new QLabel(groupInput);
        inputByte11->setObjectName(QString::fromUtf8("inputByte11"));
        inputByte11->setEnabled(true);
        inputByte11->setGeometry(QRect(74, 102, 25, 25));
        sizePolicy.setHeightForWidth(inputByte11->sizePolicy().hasHeightForWidth());
        inputByte11->setSizePolicy(sizePolicy);
        inputByte11->setFont(font);
        inputByte11->setLayoutDirection(Qt::LeftToRight);
        inputByte11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte11->setAlignment(Qt::AlignCenter);
        inputByte05 = new QLabel(groupInput);
        inputByte05->setObjectName(QString::fromUtf8("inputByte05"));
        inputByte05->setEnabled(true);
        inputByte05->setGeometry(QRect(50, 54, 25, 25));
        sizePolicy.setHeightForWidth(inputByte05->sizePolicy().hasHeightForWidth());
        inputByte05->setSizePolicy(sizePolicy);
        inputByte05->setFont(font);
        inputByte05->setLayoutDirection(Qt::LeftToRight);
        inputByte05->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        inputByte05->setAlignment(Qt::AlignCenter);
        btnEditInput = new QToolButton(groupInput);
        btnEditInput->setObjectName(QString::fromUtf8("btnEditInput"));
        btnEditInput->setGeometry(QRect(67, 130, 16, 16));
        groupKey = new QGroupBox(centralwidget);
        groupKey->setObjectName(QString::fromUtf8("groupKey"));
        groupKey->setGeometry(QRect(190, 20, 245, 150));
        groupKey->setLayoutDirection(Qt::LeftToRight);
        groupKey->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        keyByte31 = new QLabel(groupKey);
        keyByte31->setObjectName(QString::fromUtf8("keyByte31"));
        keyByte31->setGeometry(QRect(194, 102, 25, 25));
        sizePolicy.setHeightForWidth(keyByte31->sizePolicy().hasHeightForWidth());
        keyByte31->setSizePolicy(sizePolicy);
        keyByte31->setFont(font);
        keyByte31->setLayoutDirection(Qt::LeftToRight);
        keyByte31->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte31->setAlignment(Qt::AlignCenter);
        keyByte08 = new QLabel(groupKey);
        keyByte08->setObjectName(QString::fromUtf8("keyByte08"));
        keyByte08->setGeometry(QRect(74, 30, 25, 25));
        sizePolicy.setHeightForWidth(keyByte08->sizePolicy().hasHeightForWidth());
        keyByte08->setSizePolicy(sizePolicy);
        keyByte08->setFont(font);
        keyByte08->setLayoutDirection(Qt::LeftToRight);
        keyByte08->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte08->setAlignment(Qt::AlignCenter);
        keyByte17 = new QLabel(groupKey);
        keyByte17->setObjectName(QString::fromUtf8("keyByte17"));
        keyByte17->setGeometry(QRect(122, 54, 25, 25));
        sizePolicy.setHeightForWidth(keyByte17->sizePolicy().hasHeightForWidth());
        keyByte17->setSizePolicy(sizePolicy);
        keyByte17->setFont(font);
        keyByte17->setLayoutDirection(Qt::LeftToRight);
        keyByte17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte17->setAlignment(Qt::AlignCenter);
        keyByte10 = new QLabel(groupKey);
        keyByte10->setObjectName(QString::fromUtf8("keyByte10"));
        keyByte10->setGeometry(QRect(74, 78, 25, 25));
        sizePolicy.setHeightForWidth(keyByte10->sizePolicy().hasHeightForWidth());
        keyByte10->setSizePolicy(sizePolicy);
        keyByte10->setFont(font);
        keyByte10->setLayoutDirection(Qt::LeftToRight);
        keyByte10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte10->setAlignment(Qt::AlignCenter);
        keyByte00 = new QLabel(groupKey);
        keyByte00->setObjectName(QString::fromUtf8("keyByte00"));
        keyByte00->setGeometry(QRect(26, 30, 25, 25));
        sizePolicy.setHeightForWidth(keyByte00->sizePolicy().hasHeightForWidth());
        keyByte00->setSizePolicy(sizePolicy);
        keyByte00->setFont(font);
        keyByte00->setLayoutDirection(Qt::LeftToRight);
        keyByte00->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte00->setAlignment(Qt::AlignCenter);
        keyByte20 = new QLabel(groupKey);
        keyByte20->setObjectName(QString::fromUtf8("keyByte20"));
        keyByte20->setGeometry(QRect(146, 30, 25, 25));
        sizePolicy.setHeightForWidth(keyByte20->sizePolicy().hasHeightForWidth());
        keyByte20->setSizePolicy(sizePolicy);
        keyByte20->setFont(font);
        keyByte20->setLayoutDirection(Qt::LeftToRight);
        keyByte20->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte20->setAlignment(Qt::AlignCenter);
        keyByte23 = new QLabel(groupKey);
        keyByte23->setObjectName(QString::fromUtf8("keyByte23"));
        keyByte23->setGeometry(QRect(146, 102, 25, 25));
        sizePolicy.setHeightForWidth(keyByte23->sizePolicy().hasHeightForWidth());
        keyByte23->setSizePolicy(sizePolicy);
        keyByte23->setFont(font);
        keyByte23->setLayoutDirection(Qt::LeftToRight);
        keyByte23->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte23->setAlignment(Qt::AlignCenter);
        keyByte11 = new QLabel(groupKey);
        keyByte11->setObjectName(QString::fromUtf8("keyByte11"));
        keyByte11->setGeometry(QRect(74, 102, 25, 25));
        sizePolicy.setHeightForWidth(keyByte11->sizePolicy().hasHeightForWidth());
        keyByte11->setSizePolicy(sizePolicy);
        keyByte11->setFont(font);
        keyByte11->setLayoutDirection(Qt::LeftToRight);
        keyByte11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte11->setAlignment(Qt::AlignCenter);
        keyByte27 = new QLabel(groupKey);
        keyByte27->setObjectName(QString::fromUtf8("keyByte27"));
        keyByte27->setGeometry(QRect(170, 102, 25, 25));
        sizePolicy.setHeightForWidth(keyByte27->sizePolicy().hasHeightForWidth());
        keyByte27->setSizePolicy(sizePolicy);
        keyByte27->setFont(font);
        keyByte27->setLayoutDirection(Qt::LeftToRight);
        keyByte27->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte27->setAlignment(Qt::AlignCenter);
        keyByte22 = new QLabel(groupKey);
        keyByte22->setObjectName(QString::fromUtf8("keyByte22"));
        keyByte22->setGeometry(QRect(146, 78, 25, 25));
        sizePolicy.setHeightForWidth(keyByte22->sizePolicy().hasHeightForWidth());
        keyByte22->setSizePolicy(sizePolicy);
        keyByte22->setFont(font);
        keyByte22->setLayoutDirection(Qt::LeftToRight);
        keyByte22->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte22->setAlignment(Qt::AlignCenter);
        keyByte01 = new QLabel(groupKey);
        keyByte01->setObjectName(QString::fromUtf8("keyByte01"));
        keyByte01->setGeometry(QRect(26, 54, 25, 25));
        sizePolicy.setHeightForWidth(keyByte01->sizePolicy().hasHeightForWidth());
        keyByte01->setSizePolicy(sizePolicy);
        keyByte01->setFont(font);
        keyByte01->setLayoutDirection(Qt::LeftToRight);
        keyByte01->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte01->setAlignment(Qt::AlignCenter);
        keyByte06 = new QLabel(groupKey);
        keyByte06->setObjectName(QString::fromUtf8("keyByte06"));
        keyByte06->setGeometry(QRect(50, 78, 25, 25));
        sizePolicy.setHeightForWidth(keyByte06->sizePolicy().hasHeightForWidth());
        keyByte06->setSizePolicy(sizePolicy);
        keyByte06->setFont(font);
        keyByte06->setLayoutDirection(Qt::LeftToRight);
        keyByte06->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte06->setAlignment(Qt::AlignCenter);
        keyByte30 = new QLabel(groupKey);
        keyByte30->setObjectName(QString::fromUtf8("keyByte30"));
        keyByte30->setGeometry(QRect(194, 78, 25, 25));
        sizePolicy.setHeightForWidth(keyByte30->sizePolicy().hasHeightForWidth());
        keyByte30->setSizePolicy(sizePolicy);
        keyByte30->setFont(font);
        keyByte30->setLayoutDirection(Qt::LeftToRight);
        keyByte30->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte30->setAlignment(Qt::AlignCenter);
        keyByte12 = new QLabel(groupKey);
        keyByte12->setObjectName(QString::fromUtf8("keyByte12"));
        keyByte12->setGeometry(QRect(98, 30, 25, 25));
        sizePolicy.setHeightForWidth(keyByte12->sizePolicy().hasHeightForWidth());
        keyByte12->setSizePolicy(sizePolicy);
        keyByte12->setFont(font);
        keyByte12->setLayoutDirection(Qt::LeftToRight);
        keyByte12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte12->setAlignment(Qt::AlignCenter);
        keyByte21 = new QLabel(groupKey);
        keyByte21->setObjectName(QString::fromUtf8("keyByte21"));
        keyByte21->setGeometry(QRect(146, 54, 25, 25));
        sizePolicy.setHeightForWidth(keyByte21->sizePolicy().hasHeightForWidth());
        keyByte21->setSizePolicy(sizePolicy);
        keyByte21->setFont(font);
        keyByte21->setLayoutDirection(Qt::LeftToRight);
        keyByte21->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte21->setAlignment(Qt::AlignCenter);
        keyByte26 = new QLabel(groupKey);
        keyByte26->setObjectName(QString::fromUtf8("keyByte26"));
        keyByte26->setGeometry(QRect(170, 78, 25, 25));
        sizePolicy.setHeightForWidth(keyByte26->sizePolicy().hasHeightForWidth());
        keyByte26->setSizePolicy(sizePolicy);
        keyByte26->setFont(font);
        keyByte26->setLayoutDirection(Qt::LeftToRight);
        keyByte26->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte26->setAlignment(Qt::AlignCenter);
        keyByte02 = new QLabel(groupKey);
        keyByte02->setObjectName(QString::fromUtf8("keyByte02"));
        keyByte02->setGeometry(QRect(26, 78, 25, 25));
        sizePolicy.setHeightForWidth(keyByte02->sizePolicy().hasHeightForWidth());
        keyByte02->setSizePolicy(sizePolicy);
        keyByte02->setFont(font);
        keyByte02->setLayoutDirection(Qt::LeftToRight);
        keyByte02->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte02->setAlignment(Qt::AlignCenter);
        keyByte14 = new QLabel(groupKey);
        keyByte14->setObjectName(QString::fromUtf8("keyByte14"));
        keyByte14->setGeometry(QRect(98, 78, 25, 25));
        sizePolicy.setHeightForWidth(keyByte14->sizePolicy().hasHeightForWidth());
        keyByte14->setSizePolicy(sizePolicy);
        keyByte14->setFont(font);
        keyByte14->setLayoutDirection(Qt::LeftToRight);
        keyByte14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte14->setAlignment(Qt::AlignCenter);
        keyByte15 = new QLabel(groupKey);
        keyByte15->setObjectName(QString::fromUtf8("keyByte15"));
        keyByte15->setGeometry(QRect(98, 102, 25, 25));
        sizePolicy.setHeightForWidth(keyByte15->sizePolicy().hasHeightForWidth());
        keyByte15->setSizePolicy(sizePolicy);
        keyByte15->setFont(font);
        keyByte15->setLayoutDirection(Qt::LeftToRight);
        keyByte15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte15->setAlignment(Qt::AlignCenter);
        keyByte05 = new QLabel(groupKey);
        keyByte05->setObjectName(QString::fromUtf8("keyByte05"));
        keyByte05->setGeometry(QRect(50, 54, 25, 25));
        sizePolicy.setHeightForWidth(keyByte05->sizePolicy().hasHeightForWidth());
        keyByte05->setSizePolicy(sizePolicy);
        keyByte05->setFont(font);
        keyByte05->setLayoutDirection(Qt::LeftToRight);
        keyByte05->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte05->setAlignment(Qt::AlignCenter);
        keyByte04 = new QLabel(groupKey);
        keyByte04->setObjectName(QString::fromUtf8("keyByte04"));
        keyByte04->setGeometry(QRect(50, 30, 25, 25));
        sizePolicy.setHeightForWidth(keyByte04->sizePolicy().hasHeightForWidth());
        keyByte04->setSizePolicy(sizePolicy);
        keyByte04->setFont(font);
        keyByte04->setLayoutDirection(Qt::LeftToRight);
        keyByte04->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte04->setAlignment(Qt::AlignCenter);
        keyByte18 = new QLabel(groupKey);
        keyByte18->setObjectName(QString::fromUtf8("keyByte18"));
        keyByte18->setGeometry(QRect(122, 78, 25, 25));
        sizePolicy.setHeightForWidth(keyByte18->sizePolicy().hasHeightForWidth());
        keyByte18->setSizePolicy(sizePolicy);
        keyByte18->setFont(font);
        keyByte18->setLayoutDirection(Qt::LeftToRight);
        keyByte18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte18->setAlignment(Qt::AlignCenter);
        keyByte13 = new QLabel(groupKey);
        keyByte13->setObjectName(QString::fromUtf8("keyByte13"));
        keyByte13->setGeometry(QRect(98, 54, 25, 25));
        sizePolicy.setHeightForWidth(keyByte13->sizePolicy().hasHeightForWidth());
        keyByte13->setSizePolicy(sizePolicy);
        keyByte13->setFont(font);
        keyByte13->setLayoutDirection(Qt::LeftToRight);
        keyByte13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte13->setAlignment(Qt::AlignCenter);
        keyByte24 = new QLabel(groupKey);
        keyByte24->setObjectName(QString::fromUtf8("keyByte24"));
        keyByte24->setGeometry(QRect(170, 30, 25, 25));
        sizePolicy.setHeightForWidth(keyByte24->sizePolicy().hasHeightForWidth());
        keyByte24->setSizePolicy(sizePolicy);
        keyByte24->setFont(font);
        keyByte24->setLayoutDirection(Qt::LeftToRight);
        keyByte24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte24->setAlignment(Qt::AlignCenter);
        keyByte07 = new QLabel(groupKey);
        keyByte07->setObjectName(QString::fromUtf8("keyByte07"));
        keyByte07->setGeometry(QRect(50, 102, 25, 25));
        sizePolicy.setHeightForWidth(keyByte07->sizePolicy().hasHeightForWidth());
        keyByte07->setSizePolicy(sizePolicy);
        keyByte07->setFont(font);
        keyByte07->setLayoutDirection(Qt::LeftToRight);
        keyByte07->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte07->setAlignment(Qt::AlignCenter);
        keyByte16 = new QLabel(groupKey);
        keyByte16->setObjectName(QString::fromUtf8("keyByte16"));
        keyByte16->setGeometry(QRect(122, 30, 25, 25));
        sizePolicy.setHeightForWidth(keyByte16->sizePolicy().hasHeightForWidth());
        keyByte16->setSizePolicy(sizePolicy);
        keyByte16->setFont(font);
        keyByte16->setLayoutDirection(Qt::LeftToRight);
        keyByte16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte16->setAlignment(Qt::AlignCenter);
        keyByte25 = new QLabel(groupKey);
        keyByte25->setObjectName(QString::fromUtf8("keyByte25"));
        keyByte25->setGeometry(QRect(170, 54, 25, 25));
        sizePolicy.setHeightForWidth(keyByte25->sizePolicy().hasHeightForWidth());
        keyByte25->setSizePolicy(sizePolicy);
        keyByte25->setFont(font);
        keyByte25->setLayoutDirection(Qt::LeftToRight);
        keyByte25->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte25->setAlignment(Qt::AlignCenter);
        keyByte03 = new QLabel(groupKey);
        keyByte03->setObjectName(QString::fromUtf8("keyByte03"));
        keyByte03->setGeometry(QRect(26, 102, 25, 25));
        sizePolicy.setHeightForWidth(keyByte03->sizePolicy().hasHeightForWidth());
        keyByte03->setSizePolicy(sizePolicy);
        keyByte03->setFont(font);
        keyByte03->setLayoutDirection(Qt::LeftToRight);
        keyByte03->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte03->setAlignment(Qt::AlignCenter);
        keyByte09 = new QLabel(groupKey);
        keyByte09->setObjectName(QString::fromUtf8("keyByte09"));
        keyByte09->setGeometry(QRect(74, 54, 25, 25));
        sizePolicy.setHeightForWidth(keyByte09->sizePolicy().hasHeightForWidth());
        keyByte09->setSizePolicy(sizePolicy);
        keyByte09->setFont(font);
        keyByte09->setLayoutDirection(Qt::LeftToRight);
        keyByte09->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte09->setAlignment(Qt::AlignCenter);
        keyByte19 = new QLabel(groupKey);
        keyByte19->setObjectName(QString::fromUtf8("keyByte19"));
        keyByte19->setGeometry(QRect(122, 102, 25, 25));
        sizePolicy.setHeightForWidth(keyByte19->sizePolicy().hasHeightForWidth());
        keyByte19->setSizePolicy(sizePolicy);
        keyByte19->setFont(font);
        keyByte19->setLayoutDirection(Qt::LeftToRight);
        keyByte19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte19->setAlignment(Qt::AlignCenter);
        keyByte29 = new QLabel(groupKey);
        keyByte29->setObjectName(QString::fromUtf8("keyByte29"));
        keyByte29->setGeometry(QRect(194, 54, 25, 25));
        sizePolicy.setHeightForWidth(keyByte29->sizePolicy().hasHeightForWidth());
        keyByte29->setSizePolicy(sizePolicy);
        keyByte29->setFont(font);
        keyByte29->setLayoutDirection(Qt::LeftToRight);
        keyByte29->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte29->setAlignment(Qt::AlignCenter);
        keyByte28 = new QLabel(groupKey);
        keyByte28->setObjectName(QString::fromUtf8("keyByte28"));
        keyByte28->setGeometry(QRect(194, 30, 25, 25));
        sizePolicy.setHeightForWidth(keyByte28->sizePolicy().hasHeightForWidth());
        keyByte28->setSizePolicy(sizePolicy);
        keyByte28->setFont(font);
        keyByte28->setLayoutDirection(Qt::LeftToRight);
        keyByte28->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        keyByte28->setAlignment(Qt::AlignCenter);
        btnEditKey = new QToolButton(groupKey);
        btnEditKey->setObjectName(QString::fromUtf8("btnEditKey"));
        btnEditKey->setGeometry(QRect(115, 130, 16, 16));
        btnShowKey = new QPushButton(groupKey);
        btnShowKey->setObjectName(QString::fromUtf8("btnShowKey"));
        btnShowKey->setGeometry(QRect(115, 5, 16, 21));
        btnShowKey->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("help.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnShowKey->setIcon(icon);
        btnShowKey->setCheckable(false);
        btnShowKey->setAutoRepeat(false);
        btnShowKey->setAutoExclusive(false);
        btnShowKey->setFlat(true);
        groupPrevious = new QGroupBox(centralwidget);
        groupPrevious->setObjectName(QString::fromUtf8("groupPrevious"));
        groupPrevious->setGeometry(QRect(20, 210, 150, 150));
        groupPrevious->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        previousByte15 = new QLabel(groupPrevious);
        previousByte15->setObjectName(QString::fromUtf8("previousByte15"));
        previousByte15->setGeometry(QRect(98, 102, 25, 25));
        sizePolicy.setHeightForWidth(previousByte15->sizePolicy().hasHeightForWidth());
        previousByte15->setSizePolicy(sizePolicy);
        previousByte15->setFont(font);
        previousByte15->setLayoutDirection(Qt::LeftToRight);
        previousByte15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte15->setAlignment(Qt::AlignCenter);
        previousByte05 = new QLabel(groupPrevious);
        previousByte05->setObjectName(QString::fromUtf8("previousByte05"));
        previousByte05->setGeometry(QRect(50, 54, 25, 25));
        sizePolicy.setHeightForWidth(previousByte05->sizePolicy().hasHeightForWidth());
        previousByte05->setSizePolicy(sizePolicy);
        previousByte05->setFont(font);
        previousByte05->setLayoutDirection(Qt::LeftToRight);
        previousByte05->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte05->setAlignment(Qt::AlignCenter);
        previousByte03 = new QLabel(groupPrevious);
        previousByte03->setObjectName(QString::fromUtf8("previousByte03"));
        previousByte03->setGeometry(QRect(26, 102, 25, 25));
        sizePolicy.setHeightForWidth(previousByte03->sizePolicy().hasHeightForWidth());
        previousByte03->setSizePolicy(sizePolicy);
        previousByte03->setFont(font);
        previousByte03->setLayoutDirection(Qt::LeftToRight);
        previousByte03->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte03->setAlignment(Qt::AlignCenter);
        previousByte08 = new QLabel(groupPrevious);
        previousByte08->setObjectName(QString::fromUtf8("previousByte08"));
        previousByte08->setGeometry(QRect(74, 30, 25, 25));
        sizePolicy.setHeightForWidth(previousByte08->sizePolicy().hasHeightForWidth());
        previousByte08->setSizePolicy(sizePolicy);
        previousByte08->setFont(font);
        previousByte08->setLayoutDirection(Qt::LeftToRight);
        previousByte08->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte08->setAlignment(Qt::AlignCenter);
        previousByte09 = new QLabel(groupPrevious);
        previousByte09->setObjectName(QString::fromUtf8("previousByte09"));
        previousByte09->setGeometry(QRect(74, 54, 25, 25));
        sizePolicy.setHeightForWidth(previousByte09->sizePolicy().hasHeightForWidth());
        previousByte09->setSizePolicy(sizePolicy);
        previousByte09->setFont(font);
        previousByte09->setLayoutDirection(Qt::LeftToRight);
        previousByte09->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte09->setAlignment(Qt::AlignCenter);
        previousByte00 = new QLabel(groupPrevious);
        previousByte00->setObjectName(QString::fromUtf8("previousByte00"));
        previousByte00->setGeometry(QRect(26, 30, 25, 25));
        sizePolicy.setHeightForWidth(previousByte00->sizePolicy().hasHeightForWidth());
        previousByte00->setSizePolicy(sizePolicy);
        previousByte00->setFont(font);
        previousByte00->setLayoutDirection(Qt::LeftToRight);
        previousByte00->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte00->setAlignment(Qt::AlignCenter);
        previousByte04 = new QLabel(groupPrevious);
        previousByte04->setObjectName(QString::fromUtf8("previousByte04"));
        previousByte04->setGeometry(QRect(50, 30, 25, 25));
        sizePolicy.setHeightForWidth(previousByte04->sizePolicy().hasHeightForWidth());
        previousByte04->setSizePolicy(sizePolicy);
        previousByte04->setFont(font);
        previousByte04->setLayoutDirection(Qt::LeftToRight);
        previousByte04->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte04->setAlignment(Qt::AlignCenter);
        previousByte07 = new QLabel(groupPrevious);
        previousByte07->setObjectName(QString::fromUtf8("previousByte07"));
        previousByte07->setGeometry(QRect(50, 102, 25, 25));
        sizePolicy.setHeightForWidth(previousByte07->sizePolicy().hasHeightForWidth());
        previousByte07->setSizePolicy(sizePolicy);
        previousByte07->setFont(font);
        previousByte07->setLayoutDirection(Qt::LeftToRight);
        previousByte07->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte07->setAlignment(Qt::AlignCenter);
        previousByte14 = new QLabel(groupPrevious);
        previousByte14->setObjectName(QString::fromUtf8("previousByte14"));
        previousByte14->setGeometry(QRect(98, 78, 25, 25));
        sizePolicy.setHeightForWidth(previousByte14->sizePolicy().hasHeightForWidth());
        previousByte14->setSizePolicy(sizePolicy);
        previousByte14->setFont(font);
        previousByte14->setLayoutDirection(Qt::LeftToRight);
        previousByte14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte14->setAlignment(Qt::AlignCenter);
        previousByte01 = new QLabel(groupPrevious);
        previousByte01->setObjectName(QString::fromUtf8("previousByte01"));
        previousByte01->setGeometry(QRect(26, 54, 25, 25));
        sizePolicy.setHeightForWidth(previousByte01->sizePolicy().hasHeightForWidth());
        previousByte01->setSizePolicy(sizePolicy);
        previousByte01->setFont(font);
        previousByte01->setLayoutDirection(Qt::LeftToRight);
        previousByte01->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte01->setAlignment(Qt::AlignCenter);
        previousByte10 = new QLabel(groupPrevious);
        previousByte10->setObjectName(QString::fromUtf8("previousByte10"));
        previousByte10->setGeometry(QRect(74, 78, 25, 25));
        sizePolicy.setHeightForWidth(previousByte10->sizePolicy().hasHeightForWidth());
        previousByte10->setSizePolicy(sizePolicy);
        previousByte10->setFont(font);
        previousByte10->setLayoutDirection(Qt::LeftToRight);
        previousByte10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte10->setAlignment(Qt::AlignCenter);
        previousByte11 = new QLabel(groupPrevious);
        previousByte11->setObjectName(QString::fromUtf8("previousByte11"));
        previousByte11->setGeometry(QRect(74, 102, 25, 25));
        sizePolicy.setHeightForWidth(previousByte11->sizePolicy().hasHeightForWidth());
        previousByte11->setSizePolicy(sizePolicy);
        previousByte11->setFont(font);
        previousByte11->setLayoutDirection(Qt::LeftToRight);
        previousByte11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte11->setAlignment(Qt::AlignCenter);
        previousByte02 = new QLabel(groupPrevious);
        previousByte02->setObjectName(QString::fromUtf8("previousByte02"));
        previousByte02->setGeometry(QRect(26, 78, 25, 25));
        sizePolicy.setHeightForWidth(previousByte02->sizePolicy().hasHeightForWidth());
        previousByte02->setSizePolicy(sizePolicy);
        previousByte02->setFont(font);
        previousByte02->setLayoutDirection(Qt::LeftToRight);
        previousByte02->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte02->setAlignment(Qt::AlignCenter);
        previousByte06 = new QLabel(groupPrevious);
        previousByte06->setObjectName(QString::fromUtf8("previousByte06"));
        previousByte06->setGeometry(QRect(50, 78, 25, 25));
        sizePolicy.setHeightForWidth(previousByte06->sizePolicy().hasHeightForWidth());
        previousByte06->setSizePolicy(sizePolicy);
        previousByte06->setFont(font);
        previousByte06->setLayoutDirection(Qt::LeftToRight);
        previousByte06->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte06->setAlignment(Qt::AlignCenter);
        previousByte12 = new QLabel(groupPrevious);
        previousByte12->setObjectName(QString::fromUtf8("previousByte12"));
        previousByte12->setGeometry(QRect(98, 30, 25, 25));
        sizePolicy.setHeightForWidth(previousByte12->sizePolicy().hasHeightForWidth());
        previousByte12->setSizePolicy(sizePolicy);
        previousByte12->setFont(font);
        previousByte12->setLayoutDirection(Qt::LeftToRight);
        previousByte12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte12->setAlignment(Qt::AlignCenter);
        previousByte13 = new QLabel(groupPrevious);
        previousByte13->setObjectName(QString::fromUtf8("previousByte13"));
        previousByte13->setGeometry(QRect(98, 54, 25, 25));
        sizePolicy.setHeightForWidth(previousByte13->sizePolicy().hasHeightForWidth());
        previousByte13->setSizePolicy(sizePolicy);
        previousByte13->setFont(font);
        previousByte13->setLayoutDirection(Qt::LeftToRight);
        previousByte13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        previousByte13->setAlignment(Qt::AlignCenter);
        groupState = new QGroupBox(centralwidget);
        groupState->setObjectName(QString::fromUtf8("groupState"));
        groupState->setGeometry(QRect(240, 210, 150, 150));
        groupState->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stateByte15 = new QLabel(groupState);
        stateByte15->setObjectName(QString::fromUtf8("stateByte15"));
        stateByte15->setGeometry(QRect(98, 102, 25, 25));
        sizePolicy.setHeightForWidth(stateByte15->sizePolicy().hasHeightForWidth());
        stateByte15->setSizePolicy(sizePolicy);
        stateByte15->setFont(font);
        stateByte15->setLayoutDirection(Qt::LeftToRight);
        stateByte15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte15->setAlignment(Qt::AlignCenter);
        stateByte07 = new QLabel(groupState);
        stateByte07->setObjectName(QString::fromUtf8("stateByte07"));
        stateByte07->setGeometry(QRect(50, 102, 25, 25));
        sizePolicy.setHeightForWidth(stateByte07->sizePolicy().hasHeightForWidth());
        stateByte07->setSizePolicy(sizePolicy);
        stateByte07->setFont(font);
        stateByte07->setLayoutDirection(Qt::LeftToRight);
        stateByte07->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte07->setAlignment(Qt::AlignCenter);
        stateByte06 = new QLabel(groupState);
        stateByte06->setObjectName(QString::fromUtf8("stateByte06"));
        stateByte06->setGeometry(QRect(50, 78, 25, 25));
        sizePolicy.setHeightForWidth(stateByte06->sizePolicy().hasHeightForWidth());
        stateByte06->setSizePolicy(sizePolicy);
        stateByte06->setFont(font);
        stateByte06->setLayoutDirection(Qt::LeftToRight);
        stateByte06->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte06->setAlignment(Qt::AlignCenter);
        stateByte11 = new QLabel(groupState);
        stateByte11->setObjectName(QString::fromUtf8("stateByte11"));
        stateByte11->setGeometry(QRect(74, 102, 25, 25));
        sizePolicy.setHeightForWidth(stateByte11->sizePolicy().hasHeightForWidth());
        stateByte11->setSizePolicy(sizePolicy);
        stateByte11->setFont(font);
        stateByte11->setLayoutDirection(Qt::LeftToRight);
        stateByte11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte11->setAlignment(Qt::AlignCenter);
        stateByte03 = new QLabel(groupState);
        stateByte03->setObjectName(QString::fromUtf8("stateByte03"));
        stateByte03->setGeometry(QRect(26, 102, 25, 25));
        sizePolicy.setHeightForWidth(stateByte03->sizePolicy().hasHeightForWidth());
        stateByte03->setSizePolicy(sizePolicy);
        stateByte03->setFont(font);
        stateByte03->setLayoutDirection(Qt::LeftToRight);
        stateByte03->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte03->setAlignment(Qt::AlignCenter);
        stateByte10 = new QLabel(groupState);
        stateByte10->setObjectName(QString::fromUtf8("stateByte10"));
        stateByte10->setGeometry(QRect(74, 78, 25, 25));
        sizePolicy.setHeightForWidth(stateByte10->sizePolicy().hasHeightForWidth());
        stateByte10->setSizePolicy(sizePolicy);
        stateByte10->setFont(font);
        stateByte10->setLayoutDirection(Qt::LeftToRight);
        stateByte10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte10->setAlignment(Qt::AlignCenter);
        stateByte12 = new QLabel(groupState);
        stateByte12->setObjectName(QString::fromUtf8("stateByte12"));
        stateByte12->setGeometry(QRect(98, 30, 25, 25));
        sizePolicy.setHeightForWidth(stateByte12->sizePolicy().hasHeightForWidth());
        stateByte12->setSizePolicy(sizePolicy);
        stateByte12->setFont(font);
        stateByte12->setLayoutDirection(Qt::LeftToRight);
        stateByte12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte12->setAlignment(Qt::AlignCenter);
        stateByte13 = new QLabel(groupState);
        stateByte13->setObjectName(QString::fromUtf8("stateByte13"));
        stateByte13->setGeometry(QRect(98, 54, 25, 25));
        sizePolicy.setHeightForWidth(stateByte13->sizePolicy().hasHeightForWidth());
        stateByte13->setSizePolicy(sizePolicy);
        stateByte13->setFont(font);
        stateByte13->setLayoutDirection(Qt::LeftToRight);
        stateByte13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte13->setAlignment(Qt::AlignCenter);
        stateByte05 = new QLabel(groupState);
        stateByte05->setObjectName(QString::fromUtf8("stateByte05"));
        stateByte05->setGeometry(QRect(50, 54, 25, 25));
        sizePolicy.setHeightForWidth(stateByte05->sizePolicy().hasHeightForWidth());
        stateByte05->setSizePolicy(sizePolicy);
        stateByte05->setFont(font);
        stateByte05->setLayoutDirection(Qt::LeftToRight);
        stateByte05->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte05->setAlignment(Qt::AlignCenter);
        stateByte02 = new QLabel(groupState);
        stateByte02->setObjectName(QString::fromUtf8("stateByte02"));
        stateByte02->setGeometry(QRect(26, 78, 25, 25));
        sizePolicy.setHeightForWidth(stateByte02->sizePolicy().hasHeightForWidth());
        stateByte02->setSizePolicy(sizePolicy);
        stateByte02->setFont(font);
        stateByte02->setLayoutDirection(Qt::LeftToRight);
        stateByte02->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte02->setAlignment(Qt::AlignCenter);
        stateByte08 = new QLabel(groupState);
        stateByte08->setObjectName(QString::fromUtf8("stateByte08"));
        stateByte08->setGeometry(QRect(74, 30, 25, 25));
        sizePolicy.setHeightForWidth(stateByte08->sizePolicy().hasHeightForWidth());
        stateByte08->setSizePolicy(sizePolicy);
        stateByte08->setFont(font);
        stateByte08->setLayoutDirection(Qt::LeftToRight);
        stateByte08->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte08->setAlignment(Qt::AlignCenter);
        stateByte00 = new QLabel(groupState);
        stateByte00->setObjectName(QString::fromUtf8("stateByte00"));
        stateByte00->setGeometry(QRect(26, 30, 25, 25));
        sizePolicy.setHeightForWidth(stateByte00->sizePolicy().hasHeightForWidth());
        stateByte00->setSizePolicy(sizePolicy);
        stateByte00->setFont(font);
        stateByte00->setLayoutDirection(Qt::LeftToRight);
        stateByte00->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte00->setAlignment(Qt::AlignCenter);
        stateByte01 = new QLabel(groupState);
        stateByte01->setObjectName(QString::fromUtf8("stateByte01"));
        stateByte01->setGeometry(QRect(26, 54, 25, 25));
        sizePolicy.setHeightForWidth(stateByte01->sizePolicy().hasHeightForWidth());
        stateByte01->setSizePolicy(sizePolicy);
        stateByte01->setFont(font);
        stateByte01->setLayoutDirection(Qt::LeftToRight);
        stateByte01->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte01->setAlignment(Qt::AlignCenter);
        stateByte14 = new QLabel(groupState);
        stateByte14->setObjectName(QString::fromUtf8("stateByte14"));
        stateByte14->setGeometry(QRect(98, 78, 25, 25));
        sizePolicy.setHeightForWidth(stateByte14->sizePolicy().hasHeightForWidth());
        stateByte14->setSizePolicy(sizePolicy);
        stateByte14->setFont(font);
        stateByte14->setLayoutDirection(Qt::LeftToRight);
        stateByte14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte14->setAlignment(Qt::AlignCenter);
        stateByte04 = new QLabel(groupState);
        stateByte04->setObjectName(QString::fromUtf8("stateByte04"));
        stateByte04->setGeometry(QRect(50, 30, 25, 25));
        sizePolicy.setHeightForWidth(stateByte04->sizePolicy().hasHeightForWidth());
        stateByte04->setSizePolicy(sizePolicy);
        stateByte04->setFont(font);
        stateByte04->setLayoutDirection(Qt::LeftToRight);
        stateByte04->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte04->setAlignment(Qt::AlignCenter);
        stateByte09 = new QLabel(groupState);
        stateByte09->setObjectName(QString::fromUtf8("stateByte09"));
        stateByte09->setGeometry(QRect(74, 54, 25, 25));
        sizePolicy.setHeightForWidth(stateByte09->sizePolicy().hasHeightForWidth());
        stateByte09->setSizePolicy(sizePolicy);
        stateByte09->setFont(font);
        stateByte09->setLayoutDirection(Qt::LeftToRight);
        stateByte09->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        stateByte09->setAlignment(Qt::AlignCenter);
        groupNext = new QGroupBox(centralwidget);
        groupNext->setObjectName(QString::fromUtf8("groupNext"));
        groupNext->setGeometry(QRect(460, 210, 150, 150));
        groupNext->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nextByte15 = new QLabel(groupNext);
        nextByte15->setObjectName(QString::fromUtf8("nextByte15"));
        nextByte15->setGeometry(QRect(98, 102, 25, 25));
        sizePolicy.setHeightForWidth(nextByte15->sizePolicy().hasHeightForWidth());
        nextByte15->setSizePolicy(sizePolicy);
        nextByte15->setFont(font);
        nextByte15->setLayoutDirection(Qt::LeftToRight);
        nextByte15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte15->setAlignment(Qt::AlignCenter);
        nextByte01 = new QLabel(groupNext);
        nextByte01->setObjectName(QString::fromUtf8("nextByte01"));
        nextByte01->setGeometry(QRect(26, 54, 25, 25));
        sizePolicy.setHeightForWidth(nextByte01->sizePolicy().hasHeightForWidth());
        nextByte01->setSizePolicy(sizePolicy);
        nextByte01->setFont(font);
        nextByte01->setLayoutDirection(Qt::LeftToRight);
        nextByte01->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte01->setAlignment(Qt::AlignCenter);
        nextByte09 = new QLabel(groupNext);
        nextByte09->setObjectName(QString::fromUtf8("nextByte09"));
        nextByte09->setGeometry(QRect(74, 54, 25, 25));
        sizePolicy.setHeightForWidth(nextByte09->sizePolicy().hasHeightForWidth());
        nextByte09->setSizePolicy(sizePolicy);
        nextByte09->setFont(font);
        nextByte09->setLayoutDirection(Qt::LeftToRight);
        nextByte09->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte09->setAlignment(Qt::AlignCenter);
        nextByte14 = new QLabel(groupNext);
        nextByte14->setObjectName(QString::fromUtf8("nextByte14"));
        nextByte14->setGeometry(QRect(98, 78, 25, 25));
        sizePolicy.setHeightForWidth(nextByte14->sizePolicy().hasHeightForWidth());
        nextByte14->setSizePolicy(sizePolicy);
        nextByte14->setFont(font);
        nextByte14->setLayoutDirection(Qt::LeftToRight);
        nextByte14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte14->setAlignment(Qt::AlignCenter);
        nextByte03 = new QLabel(groupNext);
        nextByte03->setObjectName(QString::fromUtf8("nextByte03"));
        nextByte03->setGeometry(QRect(26, 102, 25, 25));
        sizePolicy.setHeightForWidth(nextByte03->sizePolicy().hasHeightForWidth());
        nextByte03->setSizePolicy(sizePolicy);
        nextByte03->setFont(font);
        nextByte03->setLayoutDirection(Qt::LeftToRight);
        nextByte03->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte03->setAlignment(Qt::AlignCenter);
        nextByte10 = new QLabel(groupNext);
        nextByte10->setObjectName(QString::fromUtf8("nextByte10"));
        nextByte10->setGeometry(QRect(74, 78, 25, 25));
        sizePolicy.setHeightForWidth(nextByte10->sizePolicy().hasHeightForWidth());
        nextByte10->setSizePolicy(sizePolicy);
        nextByte10->setFont(font);
        nextByte10->setLayoutDirection(Qt::LeftToRight);
        nextByte10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte10->setAlignment(Qt::AlignCenter);
        nextByte00 = new QLabel(groupNext);
        nextByte00->setObjectName(QString::fromUtf8("nextByte00"));
        nextByte00->setGeometry(QRect(26, 30, 25, 25));
        sizePolicy.setHeightForWidth(nextByte00->sizePolicy().hasHeightForWidth());
        nextByte00->setSizePolicy(sizePolicy);
        nextByte00->setFont(font);
        nextByte00->setLayoutDirection(Qt::LeftToRight);
        nextByte00->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte00->setAlignment(Qt::AlignCenter);
        nextByte06 = new QLabel(groupNext);
        nextByte06->setObjectName(QString::fromUtf8("nextByte06"));
        nextByte06->setGeometry(QRect(50, 78, 25, 25));
        sizePolicy.setHeightForWidth(nextByte06->sizePolicy().hasHeightForWidth());
        nextByte06->setSizePolicy(sizePolicy);
        nextByte06->setFont(font);
        nextByte06->setLayoutDirection(Qt::LeftToRight);
        nextByte06->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte06->setAlignment(Qt::AlignCenter);
        nextByte11 = new QLabel(groupNext);
        nextByte11->setObjectName(QString::fromUtf8("nextByte11"));
        nextByte11->setGeometry(QRect(74, 102, 25, 25));
        sizePolicy.setHeightForWidth(nextByte11->sizePolicy().hasHeightForWidth());
        nextByte11->setSizePolicy(sizePolicy);
        nextByte11->setFont(font);
        nextByte11->setLayoutDirection(Qt::LeftToRight);
        nextByte11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte11->setAlignment(Qt::AlignCenter);
        nextByte13 = new QLabel(groupNext);
        nextByte13->setObjectName(QString::fromUtf8("nextByte13"));
        nextByte13->setGeometry(QRect(98, 54, 25, 25));
        sizePolicy.setHeightForWidth(nextByte13->sizePolicy().hasHeightForWidth());
        nextByte13->setSizePolicy(sizePolicy);
        nextByte13->setFont(font);
        nextByte13->setLayoutDirection(Qt::LeftToRight);
        nextByte13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte13->setAlignment(Qt::AlignCenter);
        nextByte05 = new QLabel(groupNext);
        nextByte05->setObjectName(QString::fromUtf8("nextByte05"));
        nextByte05->setGeometry(QRect(50, 54, 25, 25));
        sizePolicy.setHeightForWidth(nextByte05->sizePolicy().hasHeightForWidth());
        nextByte05->setSizePolicy(sizePolicy);
        nextByte05->setFont(font);
        nextByte05->setLayoutDirection(Qt::LeftToRight);
        nextByte05->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte05->setAlignment(Qt::AlignCenter);
        nextByte07 = new QLabel(groupNext);
        nextByte07->setObjectName(QString::fromUtf8("nextByte07"));
        nextByte07->setGeometry(QRect(50, 102, 25, 25));
        sizePolicy.setHeightForWidth(nextByte07->sizePolicy().hasHeightForWidth());
        nextByte07->setSizePolicy(sizePolicy);
        nextByte07->setFont(font);
        nextByte07->setLayoutDirection(Qt::LeftToRight);
        nextByte07->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte07->setAlignment(Qt::AlignCenter);
        nextByte12 = new QLabel(groupNext);
        nextByte12->setObjectName(QString::fromUtf8("nextByte12"));
        nextByte12->setGeometry(QRect(98, 30, 25, 25));
        sizePolicy.setHeightForWidth(nextByte12->sizePolicy().hasHeightForWidth());
        nextByte12->setSizePolicy(sizePolicy);
        nextByte12->setFont(font);
        nextByte12->setLayoutDirection(Qt::LeftToRight);
        nextByte12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte12->setAlignment(Qt::AlignCenter);
        nextByte02 = new QLabel(groupNext);
        nextByte02->setObjectName(QString::fromUtf8("nextByte02"));
        nextByte02->setGeometry(QRect(26, 78, 25, 25));
        sizePolicy.setHeightForWidth(nextByte02->sizePolicy().hasHeightForWidth());
        nextByte02->setSizePolicy(sizePolicy);
        nextByte02->setFont(font);
        nextByte02->setLayoutDirection(Qt::LeftToRight);
        nextByte02->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte02->setAlignment(Qt::AlignCenter);
        nextByte08 = new QLabel(groupNext);
        nextByte08->setObjectName(QString::fromUtf8("nextByte08"));
        nextByte08->setGeometry(QRect(74, 30, 25, 25));
        sizePolicy.setHeightForWidth(nextByte08->sizePolicy().hasHeightForWidth());
        nextByte08->setSizePolicy(sizePolicy);
        nextByte08->setFont(font);
        nextByte08->setLayoutDirection(Qt::LeftToRight);
        nextByte08->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte08->setAlignment(Qt::AlignCenter);
        nextByte04 = new QLabel(groupNext);
        nextByte04->setObjectName(QString::fromUtf8("nextByte04"));
        nextByte04->setGeometry(QRect(50, 30, 25, 25));
        sizePolicy.setHeightForWidth(nextByte04->sizePolicy().hasHeightForWidth());
        nextByte04->setSizePolicy(sizePolicy);
        nextByte04->setFont(font);
        nextByte04->setLayoutDirection(Qt::LeftToRight);
        nextByte04->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	 border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: black;\n"
"}"));
        nextByte04->setAlignment(Qt::AlignCenter);
        labelPrevOperationDesc = new QLabel(centralwidget);
        labelPrevOperationDesc->setObjectName(QString::fromUtf8("labelPrevOperationDesc"));
        labelPrevOperationDesc->setGeometry(QRect(155, 280, 101, 17));
        labelPrevOperationDesc->setAlignment(Qt::AlignCenter);
        labelRound = new QLabel(centralwidget);
        labelRound->setObjectName(QString::fromUtf8("labelRound"));
        labelRound->setGeometry(QRect(280, 380, 51, 17));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 180, 611, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnShowNextOp = new QPushButton(centralwidget);
        btnShowNextOp->setObjectName(QString::fromUtf8("btnShowNextOp"));
        btnShowNextOp->setGeometry(QRect(418, 300, 16, 21));
        btnShowNextOp->setAutoFillBackground(false);
        btnShowNextOp->setIcon(icon);
        btnShowNextOp->setCheckable(false);
        btnShowNextOp->setAutoRepeat(false);
        btnShowNextOp->setAutoExclusive(false);
        btnShowNextOp->setFlat(true);
        btnShowPreviousOp = new QPushButton(centralwidget);
        btnShowPreviousOp->setObjectName(QString::fromUtf8("btnShowPreviousOp"));
        btnShowPreviousOp->setGeometry(QRect(198, 300, 16, 21));
        btnShowPreviousOp->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../bin/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnShowPreviousOp->setIcon(icon1);
        btnShowPreviousOp->setCheckable(false);
        btnShowPreviousOp->setAutoRepeat(false);
        btnShowPreviousOp->setAutoExclusive(false);
        btnShowPreviousOp->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 609, 25));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "YAAES Inspector", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionNewRijndael->setText(QApplication::translate("MainWindow", "New...", 0, QApplication::UnicodeUTF8));
        actionNewRijndael->setIconText(QApplication::translate("MainWindow", "New...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewRijndael->setToolTip(QApplication::translate("MainWindow", "New Inspection", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSetInputMatrix->setText(QApplication::translate("MainWindow", "Input Matrix...", 0, QApplication::UnicodeUTF8));
        actionSetInputMatrix->setIconText(QApplication::translate("MainWindow", "Input Matrix...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSetInputMatrix->setToolTip(QApplication::translate("MainWindow", "Edit Input Matrix", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSetKeyMatrix->setText(QApplication::translate("MainWindow", "Key Matrix...", 0, QApplication::UnicodeUTF8));
        actionSetKeyMatrix->setIconText(QApplication::translate("MainWindow", "Key Matrix...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSetKeyMatrix->setToolTip(QApplication::translate("MainWindow", "Edit Key Matrix", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        buttonPreviousOp->setText(QApplication::translate("MainWindow", "Previous", 0, QApplication::UnicodeUTF8));
        buttonNextOp->setText(QApplication::translate("MainWindow", "Next", 0, QApplication::UnicodeUTF8));
        buttonFirstOp->setText(QApplication::translate("MainWindow", "First", 0, QApplication::UnicodeUTF8));
        buttonLastOp->setText(QApplication::translate("MainWindow", "Last", 0, QApplication::UnicodeUTF8));
        labelRoundNumber->setText(QApplication::translate("MainWindow", "99", 0, QApplication::UnicodeUTF8));
        labelOperationDesc->setText(QApplication::translate("MainWindow", "AddRoundKey", 0, QApplication::UnicodeUTF8));
        groupOutput->setTitle(QApplication::translate("MainWindow", "Output Matrix", 0, QApplication::UnicodeUTF8));
        outputByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        outputByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        groupInput->setTitle(QApplication::translate("MainWindow", "Input Matrix", 0, QApplication::UnicodeUTF8));
        inputByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        inputByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        btnEditInput->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        groupKey->setTitle(QApplication::translate("MainWindow", "Key Matrix", 0, QApplication::UnicodeUTF8));
        keyByte31->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte17->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte20->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte23->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte27->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte22->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte30->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte21->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte26->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte18->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte24->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte16->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte25->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte19->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte29->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        keyByte28->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        btnEditKey->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnShowKey->setToolTip(QApplication::translate("MainWindow", "ola", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupPrevious->setTitle(QApplication::translate("MainWindow", "Previous Matrix", 0, QApplication::UnicodeUTF8));
        previousByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        previousByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        groupState->setTitle(QApplication::translate("MainWindow", "State Matrix", 0, QApplication::UnicodeUTF8));
        stateByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        stateByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        groupNext->setTitle(QApplication::translate("MainWindow", "Next Matrix", 0, QApplication::UnicodeUTF8));
        nextByte15->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte01->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte09->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte14->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte03->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte10->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte00->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte06->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte11->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte13->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte05->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte07->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte12->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte02->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte08->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        nextByte04->setText(QApplication::translate("MainWindow", "FF", 0, QApplication::UnicodeUTF8));
        labelPrevOperationDesc->setText(QApplication::translate("MainWindow", "AddRoundKey", 0, QApplication::UnicodeUTF8));
        labelRound->setText(QApplication::translate("MainWindow", "Round", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnShowNextOp->setToolTip(QApplication::translate("MainWindow", "ola", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        btnShowPreviousOp->setToolTip(QApplication::translate("MainWindow", "ola", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
