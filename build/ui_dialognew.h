/********************************************************************************
** Form generated from reading UI file 'dialognew.ui'
**
** Created: Sat Oct 22 19:11:45 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNEW_H
#define UI_DIALOGNEW_H

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

class Ui_DialogNew
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

    void setupUi(QDialog *DialogNew)
    {
        if (DialogNew->objectName().isEmpty())
            DialogNew->setObjectName(QString::fromUtf8("DialogNew"));
        DialogNew->setWindowModality(Qt::ApplicationModal);
        DialogNew->resize(340, 279);
        DialogNew->setModal(true);
        buttonBox = new QDialogButtonBox(DialogNew);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 230, 321, 32));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBoxKey = new QGroupBox(DialogNew);
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
        groupNumberRounds = new QGroupBox(DialogNew);
        groupNumberRounds->setObjectName(QString::fromUtf8("groupNumberRounds"));
        groupNumberRounds->setGeometry(QRect(20, 90, 361, 61));
        spinBoxNumberRounds = new QSpinBox(groupNumberRounds);
        spinBoxNumberRounds->setObjectName(QString::fromUtf8("spinBoxNumberRounds"));
        spinBoxNumberRounds->setGeometry(QRect(10, 30, 59, 27));
        spinBoxNumberRounds->setMinimum(1);
        spinBoxNumberRounds->setMaximum(14);
        groupBoxSetData = new QGroupBox(DialogNew);
        groupBoxSetData->setObjectName(QString::fromUtf8("groupBoxSetData"));
        groupBoxSetData->setGeometry(QRect(20, 160, 281, 80));
        buttonSetInput = new QPushButton(groupBoxSetData);
        buttonSetInput->setObjectName(QString::fromUtf8("buttonSetInput"));
        buttonSetInput->setGeometry(QRect(10, 30, 93, 27));
        buttonSetKey = new QPushButton(groupBoxSetData);
        buttonSetKey->setObjectName(QString::fromUtf8("buttonSetKey"));
        buttonSetKey->setGeometry(QRect(130, 30, 93, 27));

        retranslateUi(DialogNew);

        QMetaObject::connectSlotsByName(DialogNew);
    } // setupUi

    void retranslateUi(QDialog *DialogNew)
    {
        DialogNew->setWindowTitle(QApplication::translate("DialogNew", "New Rijndael", 0, QApplication::UnicodeUTF8));
        groupBoxKey->setTitle(QApplication::translate("DialogNew", "Key Size (bits)", 0, QApplication::UnicodeUTF8));
        radioKey128->setText(QApplication::translate("DialogNew", "128", 0, QApplication::UnicodeUTF8));
        radioKey192->setText(QApplication::translate("DialogNew", "192", 0, QApplication::UnicodeUTF8));
        radioKey256->setText(QApplication::translate("DialogNew", "256", 0, QApplication::UnicodeUTF8));
        groupNumberRounds->setTitle(QApplication::translate("DialogNew", "Number of Rounds", 0, QApplication::UnicodeUTF8));
        groupBoxSetData->setTitle(QApplication::translate("DialogNew", "Data Set", 0, QApplication::UnicodeUTF8));
        buttonSetInput->setText(QApplication::translate("DialogNew", "Set Input", 0, QApplication::UnicodeUTF8));
        buttonSetKey->setText(QApplication::translate("DialogNew", "Set Key", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogNew: public Ui_DialogNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNEW_H
