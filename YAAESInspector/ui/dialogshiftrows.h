#ifndef DIALOGSHIFTROWS_H
#define DIALOGSHIFTROWS_H

#include <QDialog>
#include <QLabel>
#include <QAbstractButton>

#include <cstdio>

namespace Ui {
    class DialogShiftRows;
}

class DialogShiftRows : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShiftRows(QWidget *parent = 0);
    ~DialogShiftRows();

    void setStateMatrix(unsigned char* state);
    void updateMatrix();
    void hexToUpperCaseText(unsigned char &hex, char* temp_string);

    QLabel** stateArray;
    QLabel** shiftArray;
    QLabel** resultArray;

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);

private:
    Ui::DialogShiftRows *ui;
    unsigned char* state;
    unsigned char* shift;
    unsigned char* result;
};

#endif // DIALOGSHIFTROWS_H
