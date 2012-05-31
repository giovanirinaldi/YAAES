#ifndef DIALOGADDROUNDKEY_H
#define DIALOGADDROUNDKEY_H

#include <QDialog>
#include <QLabel>
#include <QAbstractButton>

namespace Ui {
    class DialogAddRoundKey;
}

class DialogAddRoundKey : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddRoundKey(QWidget *parent = 0);
    ~DialogAddRoundKey();

    void setStateMatrix(unsigned char* state);
    void setSubKeyMatrix(unsigned char* subKey);
    void updateMatrix();
    void hexToUpperCaseText(unsigned char &hex, char* temp_string);

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);

private:
    Ui::DialogAddRoundKey *ui;
    unsigned char* state;
    unsigned char* subKey;
    unsigned char* result;

    QLabel** stateArray;
    QLabel** subKeyArray;
    QLabel** resultArray;


};


#endif // DIALOGADDROUNDKEY_H
