#ifndef DIALOGSHOWEXPKEY_H
#define DIALOGSHOWEXPKEY_H

#include <QDialog>
#include "ui_dialogshowexpkey.h"

#include "src/fast-rijndael-1d/fast-rijndael-1d.h"

namespace Ui {
    class DialogShowExpKey;
}

class DialogShowExpKey : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowExpKey(QWidget *parent = 0);
    ~DialogShowExpKey();

    void SetKeySize(FastRijndael::KeySize keySize = FastRijndael::K128, int numberColumns = 11);
    void SetExpKeyMatrixPointer(unsigned char* matrix);

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);

    void on_btnShowKey_clicked();

private:
    Ui::DialogShowExpKey *ui;
    QLabel ** k0ByteArray, ** k1ByteArray, ** k2ByteArray, ** k3ByteArray, ** k4ByteArray,
           ** k5ByteArray, ** k6ByteArray, ** k7ByteArray, ** k8ByteArray, ** k9ByteArray,
           ** k10ByteArray,** k11ByteArray,** k12ByteArray,** k13ByteArray,** k14ByteArray;
    QLabel *** kPartArray;
    unsigned char* expKeyMatrix;
    FastRijndael::KeySize keySize;
    int numberColumns;


};

#endif // DIALOGSHOWEXPKEY_H
