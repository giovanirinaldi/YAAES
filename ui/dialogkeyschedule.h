#ifndef DIALOGKEYSCHEDULE_H
#define DIALOGKEYSCHEDULE_H

#include <QDialog>
#include <QLabel>
#include <cstdio>
#include <QAbstractButton>

namespace Ui {
    class DialogKeySchedule;
}

class DialogKeySchedule : public QDialog
{
    Q_OBJECT

public:
    explicit DialogKeySchedule(QWidget *parent = 0);
    ~DialogKeySchedule();

    void setSubKeyA(unsigned char* subKeyA);
    void setSubKeyB(unsigned char* subKeyB);
    void update();
    void hexToUpperCaseText(unsigned char &hex, char* temp_string);
    void changeVisibility();
    void setSubKeyNum(int num);

    QLabel** kaArray;
    QLabel** kbArray;

private slots:
    void on_radioButtonCol0_clicked();

    void on_radioButtonCol1_clicked();

    void on_radioButtonCol2_clicked();

    void on_radioButtonCol3_clicked();

    void on_buttonBox_clicked(QAbstractButton* button);

private:
    Ui::DialogKeySchedule *ui;

    unsigned char* ka;
    unsigned char* kb;
    int n;
};

#endif // DIALOGKEYSCHEDULE_H
