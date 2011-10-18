/********************************************************************************
** Form generated from reading UI file 'newrijndael.ui'
**
** Created: Tue Oct 18 15:15:49 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWRIJNDAEL_H
#define UI_NEWRIJNDAEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogNewRijndael
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBoxKey;
    QRadioButton *radioKey128;
    QRadioButton *radioKey192;
    QRadioButton *radioKey256;
    QGroupBox *groupNumberRounds;
    QSpinBox *spinBoxNumberRounds;
    QGroupBox *groupBoxSetData;
    QPushButton *buttonSetInput;
    QPushButton *buttonSetKey;

    void setupUi(QDialog *DialogNewRijndael)
    {
        if (DialogNewRijndael->objectName().isEmpty())
            DialogNewRijndael->setObjectName(QString::fromUtf8("DialogNewRijndael"));
        DialogNewRijndael->setWindowModality(Qt::ApplicationModal);
        DialogNewRijndael->resize(340, 279);
        DialogNewRijndael->setModal(true);
        buttonBox = new QDialogButtonBox(DialogNewRijndael);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 230, 321, 32));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBoxKey = new QGroupBox(DialogNewRijndael);
        groupBoxKey->setObjectName(QString::fromUtf8("groupBoxKey"));
        groupBoxKey->setGeometry(QRect(20, 20, 361, 51));
        radioKey128 = new QRadioButton(groupBoxKey);
        radioKey128->setObjectName(QString::fromUtf8("radioKey128"));
        radioKey128->setGeometry(QRect(10, 30, 116, 22));
        radioKey192 = new QRadioButton(groupBoxKey);
        radioKey192->setObjectName(QString::fromUtf8("radioKey192"));
        radioKey192->setGeometry(QRect(130, 30, 116, 22));
        radioKey256 = new QRadioButton(groupBoxKey);
        radioKey256->setObjectName(QString::fromUtf8("radioKey256"));
        radioKey256->setGeometry(QRect(250, 30, 116, 22));
        groupNumberRounds = new QGroupBox(DialogNewRijndael);
        groupNumberRounds->setObjectName(QString::fromUtf8("groupNumberRounds"));
        groupNumberRounds->setGeometry(QRect(20, 90, 361, 61));
        spinBoxNumberRounds = new QSpinBox(groupNumberRounds);
        spinBoxNumberRounds->setObjectName(QString::fromUtf8("spinBoxNumberRounds"));
        spinBoxNumberRounds->setGeometry(QRect(10, 30, 59, 27));
        spinBoxNumberRounds->setMinimum(1);
        spinBoxNumberRounds->setMaximum(14);
        groupBoxSetData = new QGroupBox(DialogNewRijndael);
        groupBoxSetData->setObjectName(QString::fromUtf8("groupBoxSetData"));
        groupBoxSetData->setGeometry(QRect(20, 160, 281, 80));
        buttonSetInput = new QPushButton(groupBoxSetData);
        buttonSetInput->setObjectName(QString::fromUtf8("buttonSetInput"));
        buttonSetInput->setGeometry(QRect(10, 30, 93, 27));
        buttonSetKey = new QPushButton(groupBoxSetData);
        buttonSetKey->setObjectName(QString::fromUtf8("buttonSetKey"));
        buttonSetKey->setGeometry(QRect(130, 30, 93, 27));

        retranslateUi(DialogNewRijndael);

        QMetaObject::connectSlotsByName(DialogNewRijndael);
    } // setupUi

    void retranslateUi(QDialog *DialogNewRijndael)
    {
        DialogNewRijndael->setWindowTitle(QApplication::translate("DialogNewRijndael", "New Rijndael", 0, QApplication::UnicodeUTF8));
        groupBoxKey->setTitle(QApplication::translate("DialogNewRijndael", "Key Size (bits)", 0, QApplication::UnicodeUTF8));
        radioKey128->setText(QApplication::translate("DialogNewRijndael", "128", 0, QApplication::UnicodeUTF8));
        radioKey192->setText(QApplication::translate("DialogNewRijndael", "192", 0, QApplication::UnicodeUTF8));
        radioKey256->setText(QApplication::translate("DialogNewRijndael", "256", 0, QApplication::UnicodeUTF8));
        groupNumberRounds->setTitle(QApplication::translate("DialogNewRijndael", "Number of Rounds", 0, QApplication::UnicodeUTF8));
        groupBoxSetData->setTitle(QApplication::translate("DialogNewRijndael", "Data Set", 0, QApplication::UnicodeUTF8));
        buttonSetInput->setText(QApplication::translate("DialogNewRijndael", "Set Input", 0, QApplication::UnicodeUTF8));
        buttonSetKey->setText(QApplication::translate("DialogNewRijndael", "Set Key", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogNewRijndael: public Ui_DialogNewRijndael {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWRIJNDAEL_H
