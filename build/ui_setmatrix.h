/********************************************************************************
** Form generated from reading UI file 'setmatrix.ui'
**
** Created: Sat Apr 21 00:21:05 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSetMatrix
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *radioMatrixMode;
    QRadioButton *radioTextMode;
    QWidget *gridLayoutWidget;
    QGridLayout *layoutMatrixMode;
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
    QLineEdit *setTextBytes;

    void setupUi(QDialog *DialogSetMatrix)
    {
        if (DialogSetMatrix->objectName().isEmpty())
            DialogSetMatrix->setObjectName(QString::fromUtf8("DialogSetMatrix"));
        DialogSetMatrix->setWindowModality(Qt::ApplicationModal);
        DialogSetMatrix->resize(299, 297);
        DialogSetMatrix->setModal(true);
        buttonBox = new QDialogButtonBox(DialogSetMatrix);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(9, 259, 281, 32));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        radioMatrixMode = new QRadioButton(DialogSetMatrix);
        radioMatrixMode->setObjectName(QString::fromUtf8("radioMatrixMode"));
        radioMatrixMode->setGeometry(QRect(10, 10, 116, 22));
        radioTextMode = new QRadioButton(DialogSetMatrix);
        radioTextMode->setObjectName(QString::fromUtf8("radioTextMode"));
        radioTextMode->setGeometry(QRect(10, 180, 116, 22));
        gridLayoutWidget = new QWidget(DialogSetMatrix);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 40, 244, 120));
        layoutMatrixMode = new QGridLayout(gridLayoutWidget);
        layoutMatrixMode->setObjectName(QString::fromUtf8("layoutMatrixMode"));
        layoutMatrixMode->setContentsMargins(0, 0, 0, 0);
        setByte00 = new QLineEdit(gridLayoutWidget);
        setByte00->setObjectName(QString::fromUtf8("setByte00"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(25);
        sizePolicy.setVerticalStretch(25);
        sizePolicy.setHeightForWidth(setByte00->sizePolicy().hasHeightForWidth());
        setByte00->setSizePolicy(sizePolicy);
        setByte00->setMaximumSize(QSize(25, 25));
        setByte00->setMaxLength(2);
        setByte00->setFrame(true);
        setByte00->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte00, 0, 0, 1, 1);

        setByte01 = new QLineEdit(gridLayoutWidget);
        setByte01->setObjectName(QString::fromUtf8("setByte01"));
        sizePolicy.setHeightForWidth(setByte01->sizePolicy().hasHeightForWidth());
        setByte01->setSizePolicy(sizePolicy);
        setByte01->setMaximumSize(QSize(25, 25));
        setByte01->setMaxLength(2);
        setByte01->setFrame(true);
        setByte01->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte01, 1, 0, 1, 1);

        setByte02 = new QLineEdit(gridLayoutWidget);
        setByte02->setObjectName(QString::fromUtf8("setByte02"));
        sizePolicy.setHeightForWidth(setByte02->sizePolicy().hasHeightForWidth());
        setByte02->setSizePolicy(sizePolicy);
        setByte02->setMaximumSize(QSize(25, 25));
        setByte02->setMaxLength(2);
        setByte02->setFrame(true);
        setByte02->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte02, 2, 0, 1, 1);

        setByte03 = new QLineEdit(gridLayoutWidget);
        setByte03->setObjectName(QString::fromUtf8("setByte03"));
        sizePolicy.setHeightForWidth(setByte03->sizePolicy().hasHeightForWidth());
        setByte03->setSizePolicy(sizePolicy);
        setByte03->setMaximumSize(QSize(25, 25));
        setByte03->setMaxLength(2);
        setByte03->setFrame(true);
        setByte03->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte03, 3, 0, 1, 1);

        setByte04 = new QLineEdit(gridLayoutWidget);
        setByte04->setObjectName(QString::fromUtf8("setByte04"));
        sizePolicy.setHeightForWidth(setByte04->sizePolicy().hasHeightForWidth());
        setByte04->setSizePolicy(sizePolicy);
        setByte04->setMaximumSize(QSize(25, 25));
        setByte04->setMaxLength(2);
        setByte04->setFrame(true);
        setByte04->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte04, 0, 1, 1, 1);

        setByte05 = new QLineEdit(gridLayoutWidget);
        setByte05->setObjectName(QString::fromUtf8("setByte05"));
        sizePolicy.setHeightForWidth(setByte05->sizePolicy().hasHeightForWidth());
        setByte05->setSizePolicy(sizePolicy);
        setByte05->setMaximumSize(QSize(25, 25));
        setByte05->setMaxLength(2);
        setByte05->setFrame(true);
        setByte05->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte05, 1, 1, 1, 1);

        setByte06 = new QLineEdit(gridLayoutWidget);
        setByte06->setObjectName(QString::fromUtf8("setByte06"));
        sizePolicy.setHeightForWidth(setByte06->sizePolicy().hasHeightForWidth());
        setByte06->setSizePolicy(sizePolicy);
        setByte06->setMaximumSize(QSize(25, 25));
        setByte06->setMaxLength(2);
        setByte06->setFrame(true);
        setByte06->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte06, 2, 1, 1, 1);

        setByte07 = new QLineEdit(gridLayoutWidget);
        setByte07->setObjectName(QString::fromUtf8("setByte07"));
        sizePolicy.setHeightForWidth(setByte07->sizePolicy().hasHeightForWidth());
        setByte07->setSizePolicy(sizePolicy);
        setByte07->setMaximumSize(QSize(25, 25));
        setByte07->setMaxLength(2);
        setByte07->setFrame(true);
        setByte07->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte07, 3, 1, 1, 1);

        setByte08 = new QLineEdit(gridLayoutWidget);
        setByte08->setObjectName(QString::fromUtf8("setByte08"));
        sizePolicy.setHeightForWidth(setByte08->sizePolicy().hasHeightForWidth());
        setByte08->setSizePolicy(sizePolicy);
        setByte08->setMaximumSize(QSize(25, 25));
        setByte08->setMaxLength(2);
        setByte08->setFrame(true);
        setByte08->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte08, 0, 2, 1, 1);

        setByte09 = new QLineEdit(gridLayoutWidget);
        setByte09->setObjectName(QString::fromUtf8("setByte09"));
        sizePolicy.setHeightForWidth(setByte09->sizePolicy().hasHeightForWidth());
        setByte09->setSizePolicy(sizePolicy);
        setByte09->setMaximumSize(QSize(25, 25));
        setByte09->setMaxLength(2);
        setByte09->setFrame(true);
        setByte09->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte09, 1, 2, 1, 1);

        setByte10 = new QLineEdit(gridLayoutWidget);
        setByte10->setObjectName(QString::fromUtf8("setByte10"));
        sizePolicy.setHeightForWidth(setByte10->sizePolicy().hasHeightForWidth());
        setByte10->setSizePolicy(sizePolicy);
        setByte10->setMaximumSize(QSize(25, 25));
        setByte10->setMaxLength(2);
        setByte10->setFrame(true);
        setByte10->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte10, 2, 2, 1, 1);

        setByte11 = new QLineEdit(gridLayoutWidget);
        setByte11->setObjectName(QString::fromUtf8("setByte11"));
        sizePolicy.setHeightForWidth(setByte11->sizePolicy().hasHeightForWidth());
        setByte11->setSizePolicy(sizePolicy);
        setByte11->setMaximumSize(QSize(25, 25));
        setByte11->setMaxLength(2);
        setByte11->setFrame(true);
        setByte11->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte11, 3, 2, 1, 1);

        setByte12 = new QLineEdit(gridLayoutWidget);
        setByte12->setObjectName(QString::fromUtf8("setByte12"));
        sizePolicy.setHeightForWidth(setByte12->sizePolicy().hasHeightForWidth());
        setByte12->setSizePolicy(sizePolicy);
        setByte12->setMaximumSize(QSize(25, 25));
        setByte12->setMaxLength(2);
        setByte12->setFrame(true);
        setByte12->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte12, 0, 3, 1, 1);

        setByte13 = new QLineEdit(gridLayoutWidget);
        setByte13->setObjectName(QString::fromUtf8("setByte13"));
        sizePolicy.setHeightForWidth(setByte13->sizePolicy().hasHeightForWidth());
        setByte13->setSizePolicy(sizePolicy);
        setByte13->setMaximumSize(QSize(25, 25));
        setByte13->setMaxLength(2);
        setByte13->setFrame(true);
        setByte13->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte13, 1, 3, 1, 1);

        setByte14 = new QLineEdit(gridLayoutWidget);
        setByte14->setObjectName(QString::fromUtf8("setByte14"));
        sizePolicy.setHeightForWidth(setByte14->sizePolicy().hasHeightForWidth());
        setByte14->setSizePolicy(sizePolicy);
        setByte14->setMaximumSize(QSize(25, 25));
        setByte14->setMaxLength(2);
        setByte14->setFrame(true);
        setByte14->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte14, 2, 3, 1, 1);

        setByte15 = new QLineEdit(gridLayoutWidget);
        setByte15->setObjectName(QString::fromUtf8("setByte15"));
        sizePolicy.setHeightForWidth(setByte15->sizePolicy().hasHeightForWidth());
        setByte15->setSizePolicy(sizePolicy);
        setByte15->setMaximumSize(QSize(25, 25));
        setByte15->setMaxLength(2);
        setByte15->setFrame(true);
        setByte15->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte15, 3, 3, 1, 1);

        setByte16 = new QLineEdit(gridLayoutWidget);
        setByte16->setObjectName(QString::fromUtf8("setByte16"));
        sizePolicy.setHeightForWidth(setByte16->sizePolicy().hasHeightForWidth());
        setByte16->setSizePolicy(sizePolicy);
        setByte16->setMaximumSize(QSize(25, 25));
        setByte16->setMaxLength(2);
        setByte16->setFrame(true);
        setByte16->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte16, 0, 4, 1, 1);

        setByte17 = new QLineEdit(gridLayoutWidget);
        setByte17->setObjectName(QString::fromUtf8("setByte17"));
        sizePolicy.setHeightForWidth(setByte17->sizePolicy().hasHeightForWidth());
        setByte17->setSizePolicy(sizePolicy);
        setByte17->setMaximumSize(QSize(25, 25));
        setByte17->setMaxLength(2);
        setByte17->setFrame(true);
        setByte17->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte17, 1, 4, 1, 1);

        setByte18 = new QLineEdit(gridLayoutWidget);
        setByte18->setObjectName(QString::fromUtf8("setByte18"));
        sizePolicy.setHeightForWidth(setByte18->sizePolicy().hasHeightForWidth());
        setByte18->setSizePolicy(sizePolicy);
        setByte18->setMaximumSize(QSize(25, 25));
        setByte18->setMaxLength(2);
        setByte18->setFrame(true);
        setByte18->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte18, 2, 4, 1, 1);

        setByte19 = new QLineEdit(gridLayoutWidget);
        setByte19->setObjectName(QString::fromUtf8("setByte19"));
        sizePolicy.setHeightForWidth(setByte19->sizePolicy().hasHeightForWidth());
        setByte19->setSizePolicy(sizePolicy);
        setByte19->setMaximumSize(QSize(25, 25));
        setByte19->setMaxLength(2);
        setByte19->setFrame(true);
        setByte19->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte19, 3, 4, 1, 1);

        setByte20 = new QLineEdit(gridLayoutWidget);
        setByte20->setObjectName(QString::fromUtf8("setByte20"));
        sizePolicy.setHeightForWidth(setByte20->sizePolicy().hasHeightForWidth());
        setByte20->setSizePolicy(sizePolicy);
        setByte20->setMaximumSize(QSize(25, 25));
        setByte20->setMaxLength(2);
        setByte20->setFrame(true);
        setByte20->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte20, 0, 5, 1, 1);

        setByte21 = new QLineEdit(gridLayoutWidget);
        setByte21->setObjectName(QString::fromUtf8("setByte21"));
        sizePolicy.setHeightForWidth(setByte21->sizePolicy().hasHeightForWidth());
        setByte21->setSizePolicy(sizePolicy);
        setByte21->setMaximumSize(QSize(25, 25));
        setByte21->setMaxLength(2);
        setByte21->setFrame(true);
        setByte21->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte21, 1, 5, 1, 1);

        setByte22 = new QLineEdit(gridLayoutWidget);
        setByte22->setObjectName(QString::fromUtf8("setByte22"));
        sizePolicy.setHeightForWidth(setByte22->sizePolicy().hasHeightForWidth());
        setByte22->setSizePolicy(sizePolicy);
        setByte22->setMaximumSize(QSize(25, 25));
        setByte22->setMaxLength(2);
        setByte22->setFrame(true);
        setByte22->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte22, 2, 5, 1, 1);

        setByte23 = new QLineEdit(gridLayoutWidget);
        setByte23->setObjectName(QString::fromUtf8("setByte23"));
        sizePolicy.setHeightForWidth(setByte23->sizePolicy().hasHeightForWidth());
        setByte23->setSizePolicy(sizePolicy);
        setByte23->setMaximumSize(QSize(25, 25));
        setByte23->setMaxLength(2);
        setByte23->setFrame(true);
        setByte23->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte23, 3, 5, 1, 1);

        setByte24 = new QLineEdit(gridLayoutWidget);
        setByte24->setObjectName(QString::fromUtf8("setByte24"));
        sizePolicy.setHeightForWidth(setByte24->sizePolicy().hasHeightForWidth());
        setByte24->setSizePolicy(sizePolicy);
        setByte24->setMaximumSize(QSize(25, 25));
        setByte24->setMaxLength(2);
        setByte24->setFrame(true);
        setByte24->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte24, 0, 6, 1, 1);

        setByte25 = new QLineEdit(gridLayoutWidget);
        setByte25->setObjectName(QString::fromUtf8("setByte25"));
        sizePolicy.setHeightForWidth(setByte25->sizePolicy().hasHeightForWidth());
        setByte25->setSizePolicy(sizePolicy);
        setByte25->setMaximumSize(QSize(25, 25));
        setByte25->setMaxLength(2);
        setByte25->setFrame(true);
        setByte25->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte25, 1, 6, 1, 1);

        setByte26 = new QLineEdit(gridLayoutWidget);
        setByte26->setObjectName(QString::fromUtf8("setByte26"));
        sizePolicy.setHeightForWidth(setByte26->sizePolicy().hasHeightForWidth());
        setByte26->setSizePolicy(sizePolicy);
        setByte26->setMaximumSize(QSize(25, 25));
        setByte26->setMaxLength(2);
        setByte26->setFrame(true);
        setByte26->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte26, 2, 6, 1, 1);

        setByte27 = new QLineEdit(gridLayoutWidget);
        setByte27->setObjectName(QString::fromUtf8("setByte27"));
        sizePolicy.setHeightForWidth(setByte27->sizePolicy().hasHeightForWidth());
        setByte27->setSizePolicy(sizePolicy);
        setByte27->setMaximumSize(QSize(25, 25));
        setByte27->setMaxLength(2);
        setByte27->setFrame(true);
        setByte27->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte27, 3, 6, 1, 1);

        setByte28 = new QLineEdit(gridLayoutWidget);
        setByte28->setObjectName(QString::fromUtf8("setByte28"));
        sizePolicy.setHeightForWidth(setByte28->sizePolicy().hasHeightForWidth());
        setByte28->setSizePolicy(sizePolicy);
        setByte28->setMaximumSize(QSize(25, 25));
        setByte28->setMaxLength(2);
        setByte28->setFrame(true);
        setByte28->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte28, 0, 7, 1, 1);

        setByte29 = new QLineEdit(gridLayoutWidget);
        setByte29->setObjectName(QString::fromUtf8("setByte29"));
        sizePolicy.setHeightForWidth(setByte29->sizePolicy().hasHeightForWidth());
        setByte29->setSizePolicy(sizePolicy);
        setByte29->setMaximumSize(QSize(25, 25));
        setByte29->setMaxLength(2);
        setByte29->setFrame(true);
        setByte29->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte29, 1, 7, 1, 1);

        setByte30 = new QLineEdit(gridLayoutWidget);
        setByte30->setObjectName(QString::fromUtf8("setByte30"));
        sizePolicy.setHeightForWidth(setByte30->sizePolicy().hasHeightForWidth());
        setByte30->setSizePolicy(sizePolicy);
        setByte30->setMaximumSize(QSize(25, 25));
        setByte30->setMaxLength(2);
        setByte30->setFrame(true);
        setByte30->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte30, 2, 7, 1, 1);

        setByte31 = new QLineEdit(gridLayoutWidget);
        setByte31->setObjectName(QString::fromUtf8("setByte31"));
        sizePolicy.setHeightForWidth(setByte31->sizePolicy().hasHeightForWidth());
        setByte31->setSizePolicy(sizePolicy);
        setByte31->setMaximumSize(QSize(25, 25));
        setByte31->setMaxLength(2);
        setByte31->setFrame(true);
        setByte31->setAlignment(Qt::AlignCenter);

        layoutMatrixMode->addWidget(setByte31, 3, 7, 1, 1);

        setTextBytes = new QLineEdit(DialogSetMatrix);
        setTextBytes->setObjectName(QString::fromUtf8("setTextBytes"));
        setTextBytes->setGeometry(QRect(20, 210, 271, 27));
        setTextBytes->setMaxLength(32);

        retranslateUi(DialogSetMatrix);

        QMetaObject::connectSlotsByName(DialogSetMatrix);
    } // setupUi

    void retranslateUi(QDialog *DialogSetMatrix)
    {
        DialogSetMatrix->setWindowTitle(QApplication::translate("DialogSetMatrix", "Set", 0, QApplication::UnicodeUTF8));
        radioMatrixMode->setText(QApplication::translate("DialogSetMatrix", "Matrix Mode", 0, QApplication::UnicodeUTF8));
        radioTextMode->setText(QApplication::translate("DialogSetMatrix", "Text Mode", 0, QApplication::UnicodeUTF8));
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
        setTextBytes->setText(QApplication::translate("DialogSetMatrix", "01234567890123456789012345678901", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogSetMatrix: public Ui_DialogSetMatrix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMATRIX_H
