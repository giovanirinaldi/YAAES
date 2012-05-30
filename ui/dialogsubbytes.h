#ifndef DIALOGSUBBYTES_H
#define DIALOGSUBBYTES_H

#include <QDialog>
#include <QLabel>
#include <cstdio>
#include <QAbstractButton>

namespace Ui {
    class DialogSubBytes;
}

class DialogSubBytes : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSubBytes(QWidget *parent = 0);
    ~DialogSubBytes();

    void setStateMatrix(unsigned char* state);
    void updateMatrix();
    void hexToUpperCaseText(unsigned char &hex, char* temp_string);

    QLabel** stateArray;
    QLabel** resultArray;

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);

private:
    Ui::DialogSubBytes *ui;

    unsigned char* state;
    unsigned char* result;
};

#endif // DIALOGSUBBYTES_H
