#ifndef DIALOGMIXCOLUMNS_H
#define DIALOGMIXCOLUMNS_H

#include <QDialog>
#include <QLabel>
#include <cstdio>
#include <QAbstractButton>

namespace Ui {
    class DialogMixColumns;
}

class DialogMixColumns : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMixColumns(QWidget *parent = 0);
    ~DialogMixColumns();

    void setStateMatrix(unsigned char* state);
    void updateMatrix();
    void hexToUpperCaseText(unsigned char &hex, char* temp_string);

    QLabel** stateArray;
    QLabel** resultArray;

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);

private:
    unsigned char* state;
    unsigned char* result;

    Ui::DialogMixColumns *ui;
};

#endif // DIALOGMIXCOLUMNS_H
