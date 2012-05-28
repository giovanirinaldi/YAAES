#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "../../src/attacker/rijndaelattacker.h"
#include "../../src/fast-rijndael-1d/fast-rijndael-1d.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_editByte00From_textChanged(QString );
    void on_editByte00To_textChanged(QString );
    void on_editByte05From_textChanged(QString );
    void on_editByte05To_textChanged(QString );
    void on_editByte07From_textChanged(QString );
    void on_editByte07To_textChanged(QString );
    void on_editByte08From_textChanged(QString );
    void on_editByte08To_textChanged(QString );
    void on_editByte10From_textChanged(QString );
    void on_editByte10To_textChanged(QString );
    void on_editByte15From_textChanged(QString );
    void on_editByte15To_textEdited(QString );
    void on_actionExit_triggered();
    void on_buttonRun_clicked();
    void on_editPlaintext1_textChanged(QString );
    void on_editPlaintext2_textChanged(QString );
    void on_editPlaintext3_textChanged(QString );
    void on_editCiphertext1_textChanged(QString );
    void on_editCiphertext2_textChanged(QString );
    void on_editCiphertext3_textChanged(QString );
    void on_actionExample_1_triggered();
    void on_tabWidget_currentChanged(int index);
    void on_tabWidget_currentChanged(QWidget* );
    void on_buttonS01E01ARK_clicked();
    void on_buttonS01E01SB_clicked();
    void on_buttonS01E01SR_clicked();
    void on_buttonS01E01MC_clicked();
    void on_buttonS01E02InvMC_clicked();
    void on_buttonS01E02XOR_clicked();
    void on_buttonS01E02InvSR_clicked();
    void on_buttonSBoxLookup_clicked();
    void on_editByteAlpha_textChanged(QString );
    void on_editByteBeta_textChanged(QString );
    void on_editByte00ResultSbox_textChanged(QString );
    void on_editByte01ResultSbox_textChanged(QString );
    void on_editByte02ResultSbox_textChanged(QString );
    void on_editByte03ResultSbox_textChanged(QString );

private:
    Ui::MainWindow *ui;
    RijndaelAttacker rijnAttacker;
    FastRijndael rijn;


    unsigned char tryByte00, tryByte05, tryByte07, tryByte08, tryByte10, tryByte15;

    QLabel** outK0Array;    QLabel** outPlain1Array;    QLabel** outCipher1Array;    QLabel** outCipherK0Array;

    QLabel** s01e01plain1;QLabel** s01e01plain2;QLabel** s01e01plain3;

    QLabel** s01e02cipher1;QLabel** s01e02cipher2;QLabel** s01e02cipher3;
    QLabel** s01e02Cipher1InvMC;QLabel** s01e02Cipher2InvMC;QLabel** s01e02Cipher3InvMC;
    QLabel** s01e02InvCipherDiff12;QLabel** s01e02InvCipherDiff13;
    QLabel** s01e02InvCipherDiff12SR; QLabel** s01e02InvCipherDiff13SR;

    unsigned char* k0found;
    bool keyFound;

    void setOutK0(unsigned char* block);
    void setOutK0(QString block);
    void setOutPlain1(QString block);
    void setOutCipher1(QString block);
    void setOutCipherK0(unsigned char* block);
    void setOutCipherK0(QString block);

    void setPlainS01E01(QString plain1, QString plain2, QString plain3);
    void setCipherS01E02(QString cipher1, QString cipher2, QString cipher3);
    void setColumnsS01E03();
};

#endif // MAINWINDOW_H
