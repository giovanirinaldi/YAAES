#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "../../Rijndael/attacker/rijndaelattacker.h"
#include "../../Rijndael/fast-rijndael-1d/fast-rijndael-1d.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString* subkeyk0;
    QString* subkeyk1;
    QString* subkeyk2;
    QString* subkeyu2;

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
    void on_editPlaintext1_textChanged(QString );
    void on_editPlaintext2_textChanged(QString );
    void on_editPlaintext3_textChanged(QString );
    void on_editCiphertext1_textChanged(QString );
    void on_editCiphertext2_textChanged(QString );
    void on_editCiphertext3_textChanged(QString );
    void on_actionExample_1_triggered();
    void on_tabWidget_currentChanged(QWidget* );
    void on_buttonS01E01ARK_clicked();
    void on_buttonS01E01SB_clicked();
    void on_buttonS01E01SR_clicked();
    void on_buttonS01E01MC_clicked();
    void on_buttonS01E02InvMC_clicked();
    void on_buttonS01E02XOR_clicked();
    void on_buttonS01E02InvSR_clicked();
    void on_buttonSBoxLookup12_clicked();
    void on_editByteAlpha12_textChanged(QString );
    void on_editByteBeta12_textChanged(QString );
    void on_editByte00ResultSbox_textChanged(QString );
    void on_editByte01ResultSbox_textChanged(QString );
    void on_editByte02ResultSbox_textChanged(QString );
    void on_editByte03ResultSbox_textChanged(QString );
    void on_buttonS01E04ArkK1_clicked();
    void on_buttonS01E04SB_clicked();
    void on_buttonS01E04SR_clicked();
    void on_buttonS01E04FindU2Bytes_clicked();
    void on_buttonSBoxLookup13_clicked();
    void on_editByteAlpha13_textChanged(QString );
    void on_editByteBeta13_textChanged(QString );
    void on_actionRun_triggered();
    void on_actionSubkeys_triggered();
    void on_pushButtonEncryptOutput_clicked();
    void on_editSugK0Byte00_textChanged(QString );
    void on_editSugK0Byte05_textChanged(QString );
    void on_editSugK0Byte07_textChanged(QString );
    void on_editSugK0Byte08_textChanged(QString );
    void on_editSugK0Byte10_textChanged(QString );
    void on_editSugK0Byte15_textChanged(QString );
    void on_buttonSBoxSolveLookupByte00_clicked();
    void on_buttonSBoxSolveLookupByte01_clicked();
    void on_buttonSBoxSolveLookupByte02_clicked();
    void on_buttonSBoxSolveLookupByte03_clicked();
    void on_buttonS02E01ARK_clicked();
    void on_buttonS02E01SB_clicked();
    void on_buttonS02E01SR_clicked();
    void on_buttonS02E01MC_clicked();
    void on_buttonS01E04FindMissingBytes_clicked();
    void on_buttonSBoxLookup12_2_clicked();
    void on_buttonSBoxLookup13_2_clicked();
    void on_editByteAlpha12_2_textChanged(QString );
    void on_editByteBeta12_2_textChanged(QString );
    void on_editByteAlpha13_2_textChanged(QString );
    void on_editByteBeta13_2_textChanged(QString );
    void on_editByte08ResultSbox_textChanged(QString );
    void on_editByte09ResultSbox_textChanged(QString );
    void on_editByte10ResultSbox_textChanged(QString );
    void on_editByte11ResultSbox_textChanged(QString );
    void on_buttonSBoxSolveLookupByte08_clicked();
    void on_buttonSBoxSolveLookupByte09_clicked();
    void on_buttonSBoxSolveLookupByte10_clicked();
    void on_buttonSBoxSolveLookupByte11_clicked();
    void on_buttonS01E04ArkK1_2_clicked();
    void on_buttonS01E04SB_2_clicked();
    void on_buttonS01E04SR_2_clicked();
    void on_buttonS02E03FindU2Bytes_clicked();
    void on_buttonS02E03FindMissingBytes_clicked();

    void on_buttonS02E04SolveLinearSystem_clicked();

    void on_buttonS02E04FindMissingBytes_clicked();

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
    QLabel** s01e04Cipher1InvMC;
    QLabel** s02e01plain1;QLabel** s02e01plain2;QLabel** s02e01plain3;
    QLabel** s02e03Cipher1InvMC;

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
    void setColumnAndBlockS01E04();
    void setPlainS02E01();
    void setColumnsS02E02();
    void setColumnAndBlockS02E03();
    void setColumnsS02E04();
};

#endif // MAINWINDOW_H
