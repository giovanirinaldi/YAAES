/********************************************************************************
** Form generated from reading UI file 'setmatrix.ui'
**
** Created: Fri Apr 27 00:13:11 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETMATRIX_H
#define UI_SETMATRIX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogSetMatrix
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *radioMatrixMode;
    QRadioButton *radioTextMode;
    QLineEdit *setHexTextBytes;
    QLineEdit *setByte00;
    QLineEdit *setByte01;
    QLineEdit *setByte02;
    QLineEdit *setByte03;
    QLineEdit *setByte04;
    QLineEdit *setByte05;
    QLineEdit *setByte06;
    QLineEdit *setByte07;
    QLineEdit *setByte08;
    QLineEdit *setByte09;
    QLineEdit *setByte10;
    QLineEdit *setByte11;
    QLineEdit *setByte12;
    QLineEdit *setByte13;
    QLineEdit *setByte14;
    QLineEdit *setByte15;
    QLineEdit *setByte16;
    QLineEdit *setByte17;
    QLineEdit *setByte18;
    QLineEdit *setByte19;
    QLineEdit *setByte20;
    QLineEdit *setByte21;
    QLineEdit *setByte22;
    QLineEdit *setByte23;
    QLineEdit *setByte24;
    QLineEdit *setByte25;
    QLineEdit *setByte26;
    QLineEdit *setByte27;
    QLineEdit *setByte28;
    QLineEdit *setByte29;
    QLineEdit *setByte30;
    QLineEdit *setByte31;
    QRadioButton *radioCharTextMode;
    QLineEdit *setCharTextBytes;

    void setupUi(QDialog *DialogSetMatrix)
    {
        if (DialogSetMatrix->objectName().isEmpty())
            DialogSetMatrix->setObjectName(QString::fromUtf8("DialogSetMatrix"));
        DialogSetMatrix->setWindowModality(Qt::ApplicationModal);
        DialogSetMatrix->resize(683, 379);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogSetMatrix->sizePolicy().hasHeightForWidth());
        DialogSetMatrix->setSizePolicy(sizePolicy);
        DialogSetMatrix->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: white;\n"
"}"));
        DialogSetMatrix->setModal(true);
        buttonBox = new QDialogButtonBox(DialogSetMatrix);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 340, 671, 32));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        radioMatrixMode = new QRadioButton(DialogSetMatrix);
        radioMatrixMode->setObjectName(QString::fromUtf8("radioMatrixMode"));
        radioMatrixMode->setGeometry(QRect(10, 10, 116, 22));
        radioTextMode = new QRadioButton(DialogSetMatrix);
        radioTextMode->setObjectName(QString::fromUtf8("radioTextMode"));
        radioTextMode->setGeometry(QRect(10, 170, 281, 22));
        setHexTextBytes = new QLineEdit(DialogSetMatrix);
        setHexTextBytes->setObjectName(QString::fromUtf8("setHexTextBytes"));
        setHexTextBytes->setGeometry(QRect(20, 200, 651, 31));
        sizePolicy.setHeightForWidth(setHexTextBytes->sizePolicy().hasHeightForWidth());
        setHexTextBytes->setSizePolicy(sizePolicy);
        setHexTextBytes->setMaxLength(64);
        setByte00 = new QLineEdit(DialogSetMatrix);
        setByte00->setObjectName(QString::fromUtf8("setByte00"));
        setByte00->setGeometry(QRect(230, 40, 30, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(30);
        sizePolicy1.setVerticalStretch(30);
        sizePolicy1.setHeightForWidth(setByte00->sizePolicy().hasHeightForWidth());
        setByte00->setSizePolicy(sizePolicy1);
        setByte00->setMaximumSize(QSize(30, 30));
        setByte00->setMaxLength(2);
        setByte00->setFrame(true);
        setByte00->setAlignment(Qt::AlignCenter);
        setByte01 = new QLineEdit(DialogSetMatrix);
        setByte01->setObjectName(QString::fromUtf8("setByte01"));
        setByte01->setGeometry(QRect(229, 70, 30, 30));
        sizePolicy1.setHeightForWidth(setByte01->sizePolicy().hasHeightForWidth());
        setByte01->setSizePolicy(sizePolicy1);
        setByte01->setMaximumSize(QSize(30, 30));
        setByte01->setMaxLength(2);
        setByte01->setFrame(true);
        setByte01->setAlignment(Qt::AlignCenter);
        setByte02 = new QLineEdit(DialogSetMatrix);
        setByte02->setObjectName(QString::fromUtf8("setByte02"));
        setByte02->setGeometry(QRect(229, 100, 30, 30));
        sizePolicy1.setHeightForWidth(setByte02->sizePolicy().hasHeightForWidth());
        setByte02->setSizePolicy(sizePolicy1);
        setByte02->setMaximumSize(QSize(30, 30));
        setByte02->setMaxLength(2);
        setByte02->setFrame(true);
        setByte02->setAlignment(Qt::AlignCenter);
        setByte03 = new QLineEdit(DialogSetMatrix);
        setByte03->setObjectName(QString::fromUtf8("setByte03"));
        setByte03->setGeometry(QRect(229, 130, 30, 30));
        sizePolicy1.setHeightForWidth(setByte03->sizePolicy().hasHeightForWidth());
        setByte03->setSizePolicy(sizePolicy1);
        setByte03->setMaximumSize(QSize(30, 30));
        setByte03->setMaxLength(2);
        setByte03->setFrame(true);
        setByte03->setAlignment(Qt::AlignCenter);
        setByte04 = new QLineEdit(DialogSetMatrix);
        setByte04->setObjectName(QString::fromUtf8("setByte04"));
        setByte04->setGeometry(QRect(260, 40, 30, 30));
        sizePolicy1.setHeightForWidth(setByte04->sizePolicy().hasHeightForWidth());
        setByte04->setSizePolicy(sizePolicy1);
        setByte04->setMaximumSize(QSize(30, 30));
        setByte04->setMaxLength(2);
        setByte04->setFrame(true);
        setByte04->setAlignment(Qt::AlignCenter);
        setByte05 = new QLineEdit(DialogSetMatrix);
        setByte05->setObjectName(QString::fromUtf8("setByte05"));
        setByte05->setGeometry(QRect(260, 70, 30, 30));
        sizePolicy1.setHeightForWidth(setByte05->sizePolicy().hasHeightForWidth());
        setByte05->setSizePolicy(sizePolicy1);
        setByte05->setMaximumSize(QSize(30, 30));
        setByte05->setMaxLength(2);
        setByte05->setFrame(true);
        setByte05->setAlignment(Qt::AlignCenter);
        setByte06 = new QLineEdit(DialogSetMatrix);
        setByte06->setObjectName(QString::fromUtf8("setByte06"));
        setByte06->setGeometry(QRect(260, 100, 30, 30));
        sizePolicy1.setHeightForWidth(setByte06->sizePolicy().hasHeightForWidth());
        setByte06->setSizePolicy(sizePolicy1);
        setByte06->setMaximumSize(QSize(30, 30));
        setByte06->setMaxLength(2);
        setByte06->setFrame(true);
        setByte06->setAlignment(Qt::AlignCenter);
        setByte07 = new QLineEdit(DialogSetMatrix);
        setByte07->setObjectName(QString::fromUtf8("setByte07"));
        setByte07->setGeometry(QRect(260, 130, 30, 30));
        sizePolicy1.setHeightForWidth(setByte07->sizePolicy().hasHeightForWidth());
        setByte07->setSizePolicy(sizePolicy1);
        setByte07->setMaximumSize(QSize(30, 30));
        setByte07->setMaxLength(2);
        setByte07->setFrame(true);
        setByte07->setAlignment(Qt::AlignCenter);
        setByte08 = new QLineEdit(DialogSetMatrix);
        setByte08->setObjectName(QString::fromUtf8("setByte08"));
        setByte08->setGeometry(QRect(290, 40, 30, 30));
        sizePolicy1.setHeightForWidth(setByte08->sizePolicy().hasHeightForWidth());
        setByte08->setSizePolicy(sizePolicy1);
        setByte08->setMaximumSize(QSize(30, 30));
        setByte08->setMaxLength(2);
        setByte08->setFrame(true);
        setByte08->setAlignment(Qt::AlignCenter);
        setByte09 = new QLineEdit(DialogSetMatrix);
        setByte09->setObjectName(QString::fromUtf8("setByte09"));
        setByte09->setGeometry(QRect(290, 70, 30, 30));
        sizePolicy1.setHeightForWidth(setByte09->sizePolicy().hasHeightForWidth());
        setByte09->setSizePolicy(sizePolicy1);
        setByte09->setMaximumSize(QSize(30, 30));
        setByte09->setMaxLength(2);
        setByte09->setFrame(true);
        setByte09->setAlignment(Qt::AlignCenter);
        setByte10 = new QLineEdit(DialogSetMatrix);
        setByte10->setObjectName(QString::fromUtf8("setByte10"));
        setByte10->setGeometry(QRect(290, 100, 30, 30));
        sizePolicy1.setHeightForWidth(setByte10->sizePolicy().hasHeightForWidth());
        setByte10->setSizePolicy(sizePolicy1);
        setByte10->setMaximumSize(QSize(30, 30));
        setByte10->setMaxLength(2);
        setByte10->setFrame(true);
        setByte10->setAlignment(Qt::AlignCenter);
        setByte11 = new QLineEdit(DialogSetMatrix);
        setByte11->setObjectName(QString::fromUtf8("setByte11"));
        setByte11->setGeometry(QRect(290, 130, 30, 30));
        sizePolicy1.setHeightForWidth(setByte11->sizePolicy().hasHeightForWidth());
        setByte11->setSizePolicy(sizePolicy1);
        setByte11->setMaximumSize(QSize(30, 30));
        setByte11->setMaxLength(2);
        setByte11->setFrame(true);
        setByte11->setAlignment(Qt::AlignCenter);
        setByte12 = new QLineEdit(DialogSetMatrix);
        setByte12->setObjectName(QString::fromUtf8("setByte12"));
        setByte12->setGeometry(QRect(320, 40, 30, 30));
        sizePolicy1.setHeightForWidth(setByte12->sizePolicy().hasHeightForWidth());
        setByte12->setSizePolicy(sizePolicy1);
        setByte12->setMaximumSize(QSize(30, 30));
        setByte12->setMaxLength(2);
        setByte12->setFrame(true);
        setByte12->setAlignment(Qt::AlignCenter);
        setByte13 = new QLineEdit(DialogSetMatrix);
        setByte13->setObjectName(QString::fromUtf8("setByte13"));
        setByte13->setGeometry(QRect(320, 70, 30, 30));
        sizePolicy1.setHeightForWidth(setByte13->sizePolicy().hasHeightForWidth());
        setByte13->setSizePolicy(sizePolicy1);
        setByte13->setMaximumSize(QSize(30, 30));
        setByte13->setMaxLength(2);
        setByte13->setFrame(true);
        setByte13->setAlignment(Qt::AlignCenter);
        setByte14 = new QLineEdit(DialogSetMatrix);
        setByte14->setObjectName(QString::fromUtf8("setByte14"));
        setByte14->setGeometry(QRect(320, 100, 30, 30));
        sizePolicy1.setHeightForWidth(setByte14->sizePolicy().hasHeightForWidth());
        setByte14->setSizePolicy(sizePolicy1);
        setByte14->setMaximumSize(QSize(30, 30));
        setByte14->setMaxLength(2);
        setByte14->setFrame(true);
        setByte14->setAlignment(Qt::AlignCenter);
        setByte15 = new QLineEdit(DialogSetMatrix);
        setByte15->setObjectName(QString::fromUtf8("setByte15"));
        setByte15->setGeometry(QRect(320, 130, 30, 30));
        sizePolicy1.setHeightForWidth(setByte15->sizePolicy().hasHeightForWidth());
        setByte15->setSizePolicy(sizePolicy1);
        setByte15->setMaximumSize(QSize(30, 30));
        setByte15->setMaxLength(2);
        setByte15->setFrame(true);
        setByte15->setAlignment(Qt::AlignCenter);
        setByte16 = new QLineEdit(DialogSetMatrix);
        setByte16->setObjectName(QString::fromUtf8("setByte16"));
        setByte16->setGeometry(QRect(350, 40, 30, 30));
        sizePolicy1.setHeightForWidth(setByte16->sizePolicy().hasHeightForWidth());
        setByte16->setSizePolicy(sizePolicy1);
        setByte16->setMaximumSize(QSize(30, 30));
        setByte16->setLayoutDirection(Qt::LeftToRight);
        setByte16->setMaxLength(2);
        setByte16->setFrame(true);
        setByte16->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        setByte17 = new QLineEdit(DialogSetMatrix);
        setByte17->setObjectName(QString::fromUtf8("setByte17"));
        setByte17->setGeometry(QRect(350, 70, 30, 30));
        sizePolicy1.setHeightForWidth(setByte17->sizePolicy().hasHeightForWidth());
        setByte17->setSizePolicy(sizePolicy1);
        setByte17->setMaximumSize(QSize(30, 30));
        setByte17->setMaxLength(2);
        setByte17->setFrame(true);
        setByte17->setAlignment(Qt::AlignCenter);
        setByte18 = new QLineEdit(DialogSetMatrix);
        setByte18->setObjectName(QString::fromUtf8("setByte18"));
        setByte18->setGeometry(QRect(350, 100, 30, 30));
        sizePolicy1.setHeightForWidth(setByte18->sizePolicy().hasHeightForWidth());
        setByte18->setSizePolicy(sizePolicy1);
        setByte18->setMaximumSize(QSize(30, 30));
        setByte18->setMaxLength(2);
        setByte18->setFrame(true);
        setByte18->setAlignment(Qt::AlignCenter);
        setByte19 = new QLineEdit(DialogSetMatrix);
        setByte19->setObjectName(QString::fromUtf8("setByte19"));
        setByte19->setGeometry(QRect(350, 130, 30, 30));
        sizePolicy1.setHeightForWidth(setByte19->sizePolicy().hasHeightForWidth());
        setByte19->setSizePolicy(sizePolicy1);
        setByte19->setMaximumSize(QSize(30, 30));
        setByte19->setMaxLength(2);
        setByte19->setFrame(true);
        setByte19->setAlignment(Qt::AlignCenter);
        setByte20 = new QLineEdit(DialogSetMatrix);
        setByte20->setObjectName(QString::fromUtf8("setByte20"));
        setByte20->setGeometry(QRect(380, 40, 30, 30));
        sizePolicy1.setHeightForWidth(setByte20->sizePolicy().hasHeightForWidth());
        setByte20->setSizePolicy(sizePolicy1);
        setByte20->setMaximumSize(QSize(30, 30));
        setByte20->setMaxLength(2);
        setByte20->setFrame(true);
        setByte20->setAlignment(Qt::AlignCenter);
        setByte21 = new QLineEdit(DialogSetMatrix);
        setByte21->setObjectName(QString::fromUtf8("setByte21"));
        setByte21->setGeometry(QRect(380, 70, 30, 30));
        sizePolicy1.setHeightForWidth(setByte21->sizePolicy().hasHeightForWidth());
        setByte21->setSizePolicy(sizePolicy1);
        setByte21->setMaximumSize(QSize(30, 30));
        setByte21->setMaxLength(2);
        setByte21->setFrame(true);
        setByte21->setAlignment(Qt::AlignCenter);
        setByte22 = new QLineEdit(DialogSetMatrix);
        setByte22->setObjectName(QString::fromUtf8("setByte22"));
        setByte22->setGeometry(QRect(380, 100, 30, 30));
        sizePolicy1.setHeightForWidth(setByte22->sizePolicy().hasHeightForWidth());
        setByte22->setSizePolicy(sizePolicy1);
        setByte22->setMaximumSize(QSize(30, 30));
        setByte22->setMaxLength(2);
        setByte22->setFrame(true);
        setByte22->setAlignment(Qt::AlignCenter);
        setByte23 = new QLineEdit(DialogSetMatrix);
        setByte23->setObjectName(QString::fromUtf8("setByte23"));
        setByte23->setGeometry(QRect(380, 130, 30, 30));
        sizePolicy1.setHeightForWidth(setByte23->sizePolicy().hasHeightForWidth());
        setByte23->setSizePolicy(sizePolicy1);
        setByte23->setMaximumSize(QSize(30, 30));
        setByte23->setMaxLength(2);
        setByte23->setFrame(true);
        setByte23->setAlignment(Qt::AlignCenter);
        setByte24 = new QLineEdit(DialogSetMatrix);
        setByte24->setObjectName(QString::fromUtf8("setByte24"));
        setByte24->setGeometry(QRect(410, 40, 30, 30));
        sizePolicy1.setHeightForWidth(setByte24->sizePolicy().hasHeightForWidth());
        setByte24->setSizePolicy(sizePolicy1);
        setByte24->setMaximumSize(QSize(30, 30));
        setByte24->setMaxLength(2);
        setByte24->setFrame(true);
        setByte24->setAlignment(Qt::AlignCenter);
        setByte25 = new QLineEdit(DialogSetMatrix);
        setByte25->setObjectName(QString::fromUtf8("setByte25"));
        setByte25->setGeometry(QRect(410, 70, 30, 30));
        sizePolicy1.setHeightForWidth(setByte25->sizePolicy().hasHeightForWidth());
        setByte25->setSizePolicy(sizePolicy1);
        setByte25->setMaximumSize(QSize(30, 30));
        setByte25->setMaxLength(2);
        setByte25->setFrame(true);
        setByte25->setAlignment(Qt::AlignCenter);
        setByte26 = new QLineEdit(DialogSetMatrix);
        setByte26->setObjectName(QString::fromUtf8("setByte26"));
        setByte26->setGeometry(QRect(410, 100, 30, 30));
        sizePolicy1.setHeightForWidth(setByte26->sizePolicy().hasHeightForWidth());
        setByte26->setSizePolicy(sizePolicy1);
        setByte26->setMaximumSize(QSize(30, 30));
        setByte26->setMaxLength(2);
        setByte26->setFrame(true);
        setByte26->setAlignment(Qt::AlignCenter);
        setByte27 = new QLineEdit(DialogSetMatrix);
        setByte27->setObjectName(QString::fromUtf8("setByte27"));
        setByte27->setGeometry(QRect(410, 130, 30, 30));
        sizePolicy1.setHeightForWidth(setByte27->sizePolicy().hasHeightForWidth());
        setByte27->setSizePolicy(sizePolicy1);
        setByte27->setMaximumSize(QSize(30, 30));
        setByte27->setMaxLength(2);
        setByte27->setFrame(true);
        setByte27->setAlignment(Qt::AlignCenter);
        setByte28 = new QLineEdit(DialogSetMatrix);
        setByte28->setObjectName(QString::fromUtf8("setByte28"));
        setByte28->setGeometry(QRect(440, 40, 30, 30));
        sizePolicy1.setHeightForWidth(setByte28->sizePolicy().hasHeightForWidth());
        setByte28->setSizePolicy(sizePolicy1);
        setByte28->setMaximumSize(QSize(30, 30));
        setByte28->setMaxLength(2);
        setByte28->setFrame(true);
        setByte28->setAlignment(Qt::AlignCenter);
        setByte29 = new QLineEdit(DialogSetMatrix);
        setByte29->setObjectName(QString::fromUtf8("setByte29"));
        setByte29->setGeometry(QRect(440, 70, 30, 30));
        sizePolicy1.setHeightForWidth(setByte29->sizePolicy().hasHeightForWidth());
        setByte29->setSizePolicy(sizePolicy1);
        setByte29->setMaximumSize(QSize(30, 30));
        setByte29->setMaxLength(2);
        setByte29->setFrame(true);
        setByte29->setAlignment(Qt::AlignCenter);
        setByte30 = new QLineEdit(DialogSetMatrix);
        setByte30->setObjectName(QString::fromUtf8("setByte30"));
        setByte30->setGeometry(QRect(440, 100, 30, 30));
        sizePolicy1.setHeightForWidth(setByte30->sizePolicy().hasHeightForWidth());
        setByte30->setSizePolicy(sizePolicy1);
        setByte30->setMaximumSize(QSize(30, 30));
        setByte30->setMaxLength(2);
        setByte30->setFrame(true);
        setByte30->setAlignment(Qt::AlignCenter);
        setByte31 = new QLineEdit(DialogSetMatrix);
        setByte31->setObjectName(QString::fromUtf8("setByte31"));
        setByte31->setGeometry(QRect(440, 130, 30, 30));
        sizePolicy1.setHeightForWidth(setByte31->sizePolicy().hasHeightForWidth());
        setByte31->setSizePolicy(sizePolicy1);
        setByte31->setMaximumSize(QSize(30, 30));
        setByte31->setMaxLength(2);
        setByte31->setFrame(true);
        setByte31->setAlignment(Qt::AlignCenter);
        radioCharTextMode = new QRadioButton(DialogSetMatrix);
        radioCharTextMode->setObjectName(QString::fromUtf8("radioCharTextMode"));
        radioCharTextMode->setGeometry(QRect(10, 240, 281, 22));
        setCharTextBytes = new QLineEdit(DialogSetMatrix);
        setCharTextBytes->setObjectName(QString::fromUtf8("setCharTextBytes"));
        setCharTextBytes->setGeometry(QRect(20, 270, 331, 31));
        sizePolicy.setHeightForWidth(setCharTextBytes->sizePolicy().hasHeightForWidth());
        setCharTextBytes->setSizePolicy(sizePolicy);
        setCharTextBytes->setMaxLength(32);

        retranslateUi(DialogSetMatrix);

        QMetaObject::connectSlotsByName(DialogSetMatrix);
    } // setupUi

    void retranslateUi(QDialog *DialogSetMatrix)
    {
        DialogSetMatrix->setWindowTitle(QApplication::translate("DialogSetMatrix", "Set", 0, QApplication::UnicodeUTF8));
        radioMatrixMode->setText(QApplication::translate("DialogSetMatrix", "Matrix Mode", 0, QApplication::UnicodeUTF8));
        radioTextMode->setText(QApplication::translate("DialogSetMatrix", "Hex Text Mode", 0, QApplication::UnicodeUTF8));
        setHexTextBytes->setText(QApplication::translate("DialogSetMatrix", "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD", 0, QApplication::UnicodeUTF8));
        setByte00->setInputMask(QString());
        setByte00->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte01->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte02->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte03->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte04->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte05->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte06->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte07->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte08->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte09->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte10->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte11->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte12->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte13->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte14->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte15->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte16->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte17->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte18->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte19->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte20->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte21->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte22->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte23->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte24->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte25->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte26->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte27->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte28->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte29->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte30->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        setByte31->setText(QApplication::translate("DialogSetMatrix", "FF", 0, QApplication::UnicodeUTF8));
        radioCharTextMode->setText(QApplication::translate("DialogSetMatrix", "Char Text Mode", 0, QApplication::UnicodeUTF8));
        setCharTextBytes->setText(QApplication::translate("DialogSetMatrix", "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogSetMatrix: public Ui_DialogSetMatrix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMATRIX_H
