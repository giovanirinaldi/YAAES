#ifndef DIALOGSHOWEXPKEY_H
#define DIALOGSHOWEXPKEY_H

#include <QDialog>
#include "ui_dialogshowexpkey.h"

#include "../src/rijndael/rijndael.h"

namespace Ui {
    class DialogShowExpKey;
}

class DialogShowExpKey : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowExpKey(QWidget *parent = 0);
    ~DialogShowExpKey();

    void SetKeySize(Rijndael::KeySize keySize = Rijndael::K128);
    void SetExpKeyMatrixPointer(unsigned char** matrix);

private:
    Ui::DialogShowExpKey *ui;
    QLabel ** k0ByteArray, ** k1ByteArray, ** k2ByteArray, ** k3ByteArray, ** k4ByteArray,
           ** k5ByteArray, ** k6ByteArray, ** k7ByteArray, ** k8ByteArray, ** k9ByteArray,
           ** k10ByteArray,** k11ByteArray,** k12ByteArray,** k13ByteArray,** k14ByteArray;
    QLabel *** kPartArray;
    unsigned char** expKeyMatrix;
    Rijndael::KeySize keySize;


};

#endif // DIALOGSHOWEXPKEY_H
