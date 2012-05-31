#ifndef DIALOGSHOWEXPKEY_H
#define DIALOGSHOWEXPKEY_H

#include <QDialog>
#include "ui_dialogshowexpkey.h"

#include "../Rijndael/fast-rijndael-1d/fast-rijndael-1d.h"

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
    void on_btnShowKeyK0K1_clicked();

    void on_btnShowKeyK1K2_clicked();

    void on_btnShowKeyK2K3_clicked();

    void on_btnShowKeyK3K4_clicked();

    void on_btnShowKeyK4K5_clicked();

    void on_btnShowKeyK5K6_clicked();

    void on_btnShowKeyK6K7_clicked();

    void on_btnShowKeyK7K8_clicked();

    void on_btnShowKeyK8K9_clicked();

    void on_btnShowKeyK9K10_clicked();

    void on_btnShowKeyK10K11_clicked();

    void on_btnShowKeyK11K12_clicked();

    void on_btnShowKeyK12K13_clicked();

    void on_btnShowKeyK13K14_clicked();

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
