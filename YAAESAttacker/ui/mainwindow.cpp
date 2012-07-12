#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogshowsubkeys.h"
#include "dialogabout.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    subkeyk0 = new QString[16];
    subkeyk1 = new QString[16];
    subkeyk2 = new QString[16];
    subkeyu2 = new QString[16];
    for (int i = 0; i < 16; i++){
        subkeyk0[i] = "??";
        subkeyk1[i] = "??";
        subkeyk2[i] = "??";
        subkeyu2[i] = "??";
    }

    k0found = new unsigned char[16];
    for (int i = 0; i < 16; i++){
        k0found[i] = 0x00;
    }
    keyFound = false;

    ui->setupUi(this);  

    dialogShowSubKeys = new DialogShowSubKeys(this);

    installEventFilter(this);

    rijn = FastRijndael(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);

    outK0Array = new QLabel*[16];
    outK0Array[0]=ui->outK0byte00;outK0Array[1]=ui->outK0byte01;outK0Array[2]=ui->outK0byte02;outK0Array[3]=ui->outK0byte03;
    outK0Array[4]=ui->outK0byte04;outK0Array[5]=ui->outK0byte05;outK0Array[6]=ui->outK0byte06;outK0Array[7]=ui->outK0byte07;
    outK0Array[8]=ui->outK0byte08;outK0Array[9]=ui->outK0byte09;outK0Array[10]=ui->outK0byte10;outK0Array[11]=ui->outK0byte11;
    outK0Array[12]=ui->outK0byte12;outK0Array[13]=ui->outK0byte13;outK0Array[14]=ui->outK0byte14;outK0Array[15]=ui->outK0byte15;

    outPlain1Array = new QLabel*[16];
    outPlain1Array[0]=ui->outPlainByte00;outPlain1Array[1]=ui->outPlainByte01;outPlain1Array[2]=ui->outPlainByte02;outPlain1Array[3]=ui->outPlainByte03;
    outPlain1Array[4]=ui->outPlainByte04;outPlain1Array[5]=ui->outPlainByte05;outPlain1Array[6]=ui->outPlainByte06;outPlain1Array[7]=ui->outPlainByte07;
    outPlain1Array[8]=ui->outPlainByte08;outPlain1Array[9]=ui->outPlainByte09;outPlain1Array[10]=ui->outPlainByte10;outPlain1Array[11]=ui->outPlainByte11;
    outPlain1Array[12]=ui->outPlainByte12;outPlain1Array[13]=ui->outPlainByte13;outPlain1Array[14]=ui->outPlainByte14;outPlain1Array[15]=ui->outPlainByte15;

    outCipher1Array = new QLabel*[16];
    outCipher1Array[0]=ui->outCipherPair1Byte00;outCipher1Array[1]=ui->outCipherPair1Byte01;outCipher1Array[2]=ui->outCipherPair1Byte02;outCipher1Array[3]=ui->outCipherPair1Byte03;
    outCipher1Array[4]=ui->outCipherPair1Byte04;outCipher1Array[5]=ui->outCipherPair1Byte05;outCipher1Array[6]=ui->outCipherPair1Byte06;outCipher1Array[7]=ui->outCipherPair1Byte07;
    outCipher1Array[8]=ui->outCipherPair1Byte08;outCipher1Array[9]=ui->outCipherPair1Byte09;outCipher1Array[10]=ui->outCipherPair1Byte10;outCipher1Array[11]=ui->outCipherPair1Byte11;
    outCipher1Array[12]=ui->outCipherPair1Byte12;outCipher1Array[13]=ui->outCipherPair1Byte13;outCipher1Array[14]=ui->outCipherPair1Byte14;outCipher1Array[15]=ui->outCipherPair1Byte15;

    outCipherK0Array = new QLabel*[16];
    outCipherK0Array[0]=ui->outCipherK0Byte00;outCipherK0Array[1]=ui->outCipherK0Byte01;outCipherK0Array[2]=ui->outCipherK0Byte02;outCipherK0Array[3]=ui->outCipherK0Byte03;
    outCipherK0Array[4]=ui->outCipherK0Byte04;outCipherK0Array[5]=ui->outCipherK0Byte05;outCipherK0Array[6]=ui->outCipherK0Byte06;outCipherK0Array[7]=ui->outCipherK0Byte07;
    outCipherK0Array[8]=ui->outCipherK0Byte08;outCipherK0Array[9]=ui->outCipherK0Byte09;outCipherK0Array[10]=ui->outCipherK0Byte10;outCipherK0Array[11]=ui->outCipherK0Byte11;
    outCipherK0Array[12]=ui->outCipherK0Byte12;outCipherK0Array[13]=ui->outCipherK0Byte13;outCipherK0Array[14]=ui->outCipherK0Byte14;outCipherK0Array[15]=ui->outCipherK0Byte15;

    s01e01plain1 = new QLabel*[16];
    s01e01plain1[0]=ui->outPlain1s01e01Byte00;s01e01plain1[1]=ui->outPlain1s01e01Byte01;s01e01plain1[2]=ui->outPlain1s01e01Byte02;s01e01plain1[3]=ui->outPlain1s01e01Byte03;
    s01e01plain1[4]=ui->outPlain1s01e01Byte04;s01e01plain1[5]=ui->outPlain1s01e01Byte05;s01e01plain1[6]=ui->outPlain1s01e01Byte06;s01e01plain1[7]=ui->outPlain1s01e01Byte07;
    s01e01plain1[8]=ui->outPlain1s01e01Byte08;s01e01plain1[9]=ui->outPlain1s01e01Byte09;s01e01plain1[10]=ui->outPlain1s01e01Byte10;s01e01plain1[11]=ui->outPlain1s01e01Byte11;
    s01e01plain1[12]=ui->outPlain1s01e01Byte12;s01e01plain1[13]=ui->outPlain1s01e01Byte13;s01e01plain1[14]=ui->outPlain1s01e01Byte14;s01e01plain1[15]=ui->outPlain1s01e01Byte15;

    s01e01plain2 = new QLabel*[16];
    s01e01plain2[0]=ui->outPlain2s01e01Byte00;s01e01plain2[1]=ui->outPlain2s01e01Byte01;s01e01plain2[2]=ui->outPlain2s01e01Byte02;s01e01plain2[3]=ui->outPlain2s01e01Byte03;
    s01e01plain2[4]=ui->outPlain2s01e01Byte04;s01e01plain2[5]=ui->outPlain2s01e01Byte05;s01e01plain2[6]=ui->outPlain2s01e01Byte06;s01e01plain2[7]=ui->outPlain2s01e01Byte07;
    s01e01plain2[8]=ui->outPlain2s01e01Byte08;s01e01plain2[9]=ui->outPlain2s01e01Byte09;s01e01plain2[10]=ui->outPlain2s01e01Byte10;s01e01plain2[11]=ui->outPlain2s01e01Byte11;
    s01e01plain2[12]=ui->outPlain2s01e01Byte12;s01e01plain2[13]=ui->outPlain2s01e01Byte13;s01e01plain2[14]=ui->outPlain2s01e01Byte14;s01e01plain2[15]=ui->outPlain2s01e01Byte15;

    s01e01plain3 = new QLabel*[16];
    s01e01plain3[0]=ui->outPlain3s01e01Byte00;s01e01plain3[1]=ui->outPlain3s01e01Byte01;s01e01plain3[2]=ui->outPlain3s01e01Byte02;s01e01plain3[3]=ui->outPlain3s01e01Byte03;
    s01e01plain3[4]=ui->outPlain3s01e01Byte04;s01e01plain3[5]=ui->outPlain3s01e01Byte05;s01e01plain3[6]=ui->outPlain3s01e01Byte06;s01e01plain3[7]=ui->outPlain3s01e01Byte07;
    s01e01plain3[8]=ui->outPlain3s01e01Byte08;s01e01plain3[9]=ui->outPlain3s01e01Byte09;s01e01plain3[10]=ui->outPlain3s01e01Byte10;s01e01plain3[11]=ui->outPlain3s01e01Byte11;
    s01e01plain3[12]=ui->outPlain3s01e01Byte12;s01e01plain3[13]=ui->outPlain3s01e01Byte13;s01e01plain3[14]=ui->outPlain3s01e01Byte14;s01e01plain3[15]=ui->outPlain3s01e01Byte15;

    s01e02cipher1 = new QLabel*[16];
    s01e02cipher1[0]=ui->s01e02Cipher1Byte00;s01e02cipher1[1]=ui->s01e02Cipher1Byte01;s01e02cipher1[2]=ui->s01e02Cipher1Byte02;s01e02cipher1[3]=ui->s01e02Cipher1Byte03;
    s01e02cipher1[4]=ui->s01e02Cipher1Byte04;s01e02cipher1[5]=ui->s01e02Cipher1Byte05;s01e02cipher1[6]=ui->s01e02Cipher1Byte06;s01e02cipher1[7]=ui->s01e02Cipher1Byte07;
    s01e02cipher1[8]=ui->s01e02Cipher1Byte08;s01e02cipher1[9]=ui->s01e02Cipher1Byte09;s01e02cipher1[10]=ui->s01e02Cipher1Byte10;s01e02cipher1[11]=ui->s01e02Cipher1Byte11;
    s01e02cipher1[12]=ui->s01e02Cipher1Byte12;s01e02cipher1[13]=ui->s01e02Cipher1Byte13;s01e02cipher1[14]=ui->s01e02Cipher1Byte14;s01e02cipher1[15]=ui->s01e02Cipher1Byte15;

    s01e02cipher2 = new QLabel*[16];
    s01e02cipher2[0]=ui->s01e02Cipher2Byte00;s01e02cipher2[1]=ui->s01e02Cipher2Byte01;s01e02cipher2[2]=ui->s01e02Cipher2Byte02;s01e02cipher2[3]=ui->s01e02Cipher2Byte03;
    s01e02cipher2[4]=ui->s01e02Cipher2Byte04;s01e02cipher2[5]=ui->s01e02Cipher2Byte05;s01e02cipher2[6]=ui->s01e02Cipher2Byte06;s01e02cipher2[7]=ui->s01e02Cipher2Byte07;
    s01e02cipher2[8]=ui->s01e02Cipher2Byte08;s01e02cipher2[9]=ui->s01e02Cipher2Byte09;s01e02cipher2[10]=ui->s01e02Cipher2Byte10;s01e02cipher2[11]=ui->s01e02Cipher2Byte11;
    s01e02cipher2[12]=ui->s01e02Cipher2Byte12;s01e02cipher2[13]=ui->s01e02Cipher2Byte13;s01e02cipher2[14]=ui->s01e02Cipher2Byte14;s01e02cipher2[15]=ui->s01e02Cipher2Byte15;

    s01e02cipher3 = new QLabel*[16];
    s01e02cipher3[0]=ui->s01e02Cipher3Byte00;s01e02cipher3[1]=ui->s01e02Cipher3Byte01;s01e02cipher3[2]=ui->s01e02Cipher3Byte02;s01e02cipher3[3]=ui->s01e02Cipher3Byte03;
    s01e02cipher3[4]=ui->s01e02Cipher3Byte04;s01e02cipher3[5]=ui->s01e02Cipher3Byte05;s01e02cipher3[6]=ui->s01e02Cipher3Byte06;s01e02cipher3[7]=ui->s01e02Cipher3Byte07;
    s01e02cipher3[8]=ui->s01e02Cipher3Byte08;s01e02cipher3[9]=ui->s01e02Cipher3Byte09;s01e02cipher3[10]=ui->s01e02Cipher3Byte10;s01e02cipher3[11]=ui->s01e02Cipher3Byte11;
    s01e02cipher3[12]=ui->s01e02Cipher3Byte12;s01e02cipher3[13]=ui->s01e02Cipher3Byte13;s01e02cipher3[14]=ui->s01e02Cipher3Byte14;s01e02cipher3[15]=ui->s01e02Cipher3Byte15;

    s01e02Cipher1InvMC = new QLabel*[16];
    s01e02Cipher1InvMC[0]=ui->s01e02Cipher1InvMCByte00;s01e02Cipher1InvMC[1]=ui->s01e02Cipher1InvMCByte01;s01e02Cipher1InvMC[2]=ui->s01e02Cipher1InvMCByte02;s01e02Cipher1InvMC[3]=ui->s01e02Cipher1InvMCByte03;
    s01e02Cipher1InvMC[4]=ui->s01e02Cipher1InvMCByte04;s01e02Cipher1InvMC[5]=ui->s01e02Cipher1InvMCByte05;s01e02Cipher1InvMC[6]=ui->s01e02Cipher1InvMCByte06;s01e02Cipher1InvMC[7]=ui->s01e02Cipher1InvMCByte07;
    s01e02Cipher1InvMC[8]=ui->s01e02Cipher1InvMCByte08;s01e02Cipher1InvMC[9]=ui->s01e02Cipher1InvMCByte09;s01e02Cipher1InvMC[10]=ui->s01e02Cipher1InvMCByte10;s01e02Cipher1InvMC[11]=ui->s01e02Cipher1InvMCByte11;
    s01e02Cipher1InvMC[12]=ui->s01e02Cipher1InvMCByte12;s01e02Cipher1InvMC[13]=ui->s01e02Cipher1InvMCByte13;s01e02Cipher1InvMC[14]=ui->s01e02Cipher1InvMCByte14;s01e02Cipher1InvMC[15]=ui->s01e02Cipher1InvMCByte15;

    s01e02Cipher2InvMC = new QLabel*[16];
    s01e02Cipher2InvMC[0]=ui->s01e02Cipher2InvMCByte00;s01e02Cipher2InvMC[1]=ui->s01e02Cipher2InvMCByte01;s01e02Cipher2InvMC[2]=ui->s01e02Cipher2InvMCByte02;s01e02Cipher2InvMC[3]=ui->s01e02Cipher2InvMCByte03;
    s01e02Cipher2InvMC[4]=ui->s01e02Cipher2InvMCByte04;s01e02Cipher2InvMC[5]=ui->s01e02Cipher2InvMCByte05;s01e02Cipher2InvMC[6]=ui->s01e02Cipher2InvMCByte06;s01e02Cipher2InvMC[7]=ui->s01e02Cipher2InvMCByte07;
    s01e02Cipher2InvMC[8]=ui->s01e02Cipher2InvMCByte08;s01e02Cipher2InvMC[9]=ui->s01e02Cipher2InvMCByte09;s01e02Cipher2InvMC[10]=ui->s01e02Cipher2InvMCByte10;s01e02Cipher2InvMC[11]=ui->s01e02Cipher2InvMCByte11;
    s01e02Cipher2InvMC[12]=ui->s01e02Cipher2InvMCByte12;s01e02Cipher2InvMC[13]=ui->s01e02Cipher2InvMCByte13;s01e02Cipher2InvMC[14]=ui->s01e02Cipher2InvMCByte14;s01e02Cipher2InvMC[15]=ui->s01e02Cipher2InvMCByte15;

    s01e02Cipher3InvMC = new QLabel*[16];
    s01e02Cipher3InvMC[0]=ui->s01e02Cipher3InvMCByte00;s01e02Cipher3InvMC[1]=ui->s01e02Cipher3InvMCByte01;s01e02Cipher3InvMC[2]=ui->s01e02Cipher3InvMCByte02;s01e02Cipher3InvMC[3]=ui->s01e02Cipher3InvMCByte03;
    s01e02Cipher3InvMC[4]=ui->s01e02Cipher3InvMCByte04;s01e02Cipher3InvMC[5]=ui->s01e02Cipher3InvMCByte05;s01e02Cipher3InvMC[6]=ui->s01e02Cipher3InvMCByte06;s01e02Cipher3InvMC[7]=ui->s01e02Cipher3InvMCByte07;
    s01e02Cipher3InvMC[8]=ui->s01e02Cipher3InvMCByte08;s01e02Cipher3InvMC[9]=ui->s01e02Cipher3InvMCByte09;s01e02Cipher3InvMC[10]=ui->s01e02Cipher3InvMCByte10;s01e02Cipher3InvMC[11]=ui->s01e02Cipher3InvMCByte11;
    s01e02Cipher3InvMC[12]=ui->s01e02Cipher3InvMCByte12;s01e02Cipher3InvMC[13]=ui->s01e02Cipher3InvMCByte13;s01e02Cipher3InvMC[14]=ui->s01e02Cipher3InvMCByte14;s01e02Cipher3InvMC[15]=ui->s01e02Cipher3InvMCByte15;

    s01e02InvCipherDiff12 = new QLabel*[16];
    s01e02InvCipherDiff12[0]=ui->s01e02InvCipherDiff12Byte00;s01e02InvCipherDiff12[1]=ui->s01e02InvCipherDiff12Byte01;s01e02InvCipherDiff12[2]=ui->s01e02InvCipherDiff12Byte02;s01e02InvCipherDiff12[3]=ui->s01e02InvCipherDiff12Byte03;
    s01e02InvCipherDiff12[4]=ui->s01e02InvCipherDiff12Byte04;s01e02InvCipherDiff12[5]=ui->s01e02InvCipherDiff12Byte05;s01e02InvCipherDiff12[6]=ui->s01e02InvCipherDiff12Byte06;s01e02InvCipherDiff12[7]=ui->s01e02InvCipherDiff12Byte07;
    s01e02InvCipherDiff12[8]=ui->s01e02InvCipherDiff12Byte08;s01e02InvCipherDiff12[9]=ui->s01e02InvCipherDiff12Byte09;s01e02InvCipherDiff12[10]=ui->s01e02InvCipherDiff12Byte10;s01e02InvCipherDiff12[11]=ui->s01e02InvCipherDiff12Byte11;
    s01e02InvCipherDiff12[12]=ui->s01e02InvCipherDiff12Byte12;s01e02InvCipherDiff12[13]=ui->s01e02InvCipherDiff12Byte13;s01e02InvCipherDiff12[14]=ui->s01e02InvCipherDiff12Byte14;s01e02InvCipherDiff12[15]=ui->s01e02InvCipherDiff12Byte15;

    s01e02InvCipherDiff13 = new QLabel*[16];
    s01e02InvCipherDiff13[0]=ui->s01e02InvCipherDiff13Byte00;s01e02InvCipherDiff13[1]=ui->s01e02InvCipherDiff13Byte01;s01e02InvCipherDiff13[2]=ui->s01e02InvCipherDiff13Byte02;s01e02InvCipherDiff13[3]=ui->s01e02InvCipherDiff13Byte03;
    s01e02InvCipherDiff13[4]=ui->s01e02InvCipherDiff13Byte04;s01e02InvCipherDiff13[5]=ui->s01e02InvCipherDiff13Byte05;s01e02InvCipherDiff13[6]=ui->s01e02InvCipherDiff13Byte06;s01e02InvCipherDiff13[7]=ui->s01e02InvCipherDiff13Byte07;
    s01e02InvCipherDiff13[8]=ui->s01e02InvCipherDiff13Byte08;s01e02InvCipherDiff13[9]=ui->s01e02InvCipherDiff13Byte09;s01e02InvCipherDiff13[10]=ui->s01e02InvCipherDiff13Byte10;s01e02InvCipherDiff13[11]=ui->s01e02InvCipherDiff13Byte11;
    s01e02InvCipherDiff13[12]=ui->s01e02InvCipherDiff13Byte12;s01e02InvCipherDiff13[13]=ui->s01e02InvCipherDiff13Byte13;s01e02InvCipherDiff13[14]=ui->s01e02InvCipherDiff13Byte14;s01e02InvCipherDiff13[15]=ui->s01e02InvCipherDiff13Byte15;

    s01e02InvCipherDiff12SR = new QLabel*[16];
    s01e02InvCipherDiff12SR[0]=ui->s01e02InvCipherDiff12SRByte00;s01e02InvCipherDiff12SR[1]=ui->s01e02InvCipherDiff12SRByte01;s01e02InvCipherDiff12SR[2]=ui->s01e02InvCipherDiff12SRByte02;s01e02InvCipherDiff12SR[3]=ui->s01e02InvCipherDiff12SRByte03;
    s01e02InvCipherDiff12SR[4]=ui->s01e02InvCipherDiff12SRByte04;s01e02InvCipherDiff12SR[5]=ui->s01e02InvCipherDiff12SRByte05;s01e02InvCipherDiff12SR[6]=ui->s01e02InvCipherDiff12SRByte06;s01e02InvCipherDiff12SR[7]=ui->s01e02InvCipherDiff12SRByte07;
    s01e02InvCipherDiff12SR[8]=ui->s01e02InvCipherDiff12SRByte08;s01e02InvCipherDiff12SR[9]=ui->s01e02InvCipherDiff12SRByte09;s01e02InvCipherDiff12SR[10]=ui->s01e02InvCipherDiff12SRByte10;s01e02InvCipherDiff12SR[11]=ui->s01e02InvCipherDiff12SRByte11;
    s01e02InvCipherDiff12SR[12]=ui->s01e02InvCipherDiff12SRByte12;s01e02InvCipherDiff12SR[13]=ui->s01e02InvCipherDiff12SRByte13;s01e02InvCipherDiff12SR[14]=ui->s01e02InvCipherDiff12SRByte14;s01e02InvCipherDiff12SR[15]=ui->s01e02InvCipherDiff12SRByte15;

    s01e02InvCipherDiff13SR = new QLabel*[16];
    s01e02InvCipherDiff13SR[0]=ui->s01e02InvCipherDiff13SRByte00;s01e02InvCipherDiff13SR[1]=ui->s01e02InvCipherDiff13SRByte01;s01e02InvCipherDiff13SR[2]=ui->s01e02InvCipherDiff13SRByte02;s01e02InvCipherDiff13SR[3]=ui->s01e02InvCipherDiff13SRByte03;
    s01e02InvCipherDiff13SR[4]=ui->s01e02InvCipherDiff13SRByte04;s01e02InvCipherDiff13SR[5]=ui->s01e02InvCipherDiff13SRByte05;s01e02InvCipherDiff13SR[6]=ui->s01e02InvCipherDiff13SRByte06;s01e02InvCipherDiff13SR[7]=ui->s01e02InvCipherDiff13SRByte07;
    s01e02InvCipherDiff13SR[8]=ui->s01e02InvCipherDiff13SRByte08;s01e02InvCipherDiff13SR[9]=ui->s01e02InvCipherDiff13SRByte09;s01e02InvCipherDiff13SR[10]=ui->s01e02InvCipherDiff13SRByte10;s01e02InvCipherDiff13SR[11]=ui->s01e02InvCipherDiff13SRByte11;
    s01e02InvCipherDiff13SR[12]=ui->s01e02InvCipherDiff13SRByte12;s01e02InvCipherDiff13SR[13]=ui->s01e02InvCipherDiff13SRByte13;s01e02InvCipherDiff13SR[14]=ui->s01e02InvCipherDiff13SRByte14;s01e02InvCipherDiff13SR[15]=ui->s01e02InvCipherDiff13SRByte15;

    s01e04Cipher1InvMC = new QLabel*[16];
    s01e04Cipher1InvMC[0]=ui->s01e04Cipher1InvMCByte00;s01e04Cipher1InvMC[1]=ui->s01e04Cipher1InvMCByte01;s01e04Cipher1InvMC[2]=ui->s01e04Cipher1InvMCByte02;s01e04Cipher1InvMC[3]=ui->s01e04Cipher1InvMCByte03;
    s01e04Cipher1InvMC[4]=ui->s01e04Cipher1InvMCByte04;s01e04Cipher1InvMC[5]=ui->s01e04Cipher1InvMCByte05;s01e04Cipher1InvMC[6]=ui->s01e04Cipher1InvMCByte06;s01e04Cipher1InvMC[7]=ui->s01e04Cipher1InvMCByte07;
    s01e04Cipher1InvMC[8]=ui->s01e04Cipher1InvMCByte08;s01e04Cipher1InvMC[9]=ui->s01e04Cipher1InvMCByte09;s01e04Cipher1InvMC[10]=ui->s01e04Cipher1InvMCByte10;s01e04Cipher1InvMC[11]=ui->s01e04Cipher1InvMCByte11;
    s01e04Cipher1InvMC[12]=ui->s01e04Cipher1InvMCByte12;s01e04Cipher1InvMC[13]=ui->s01e04Cipher1InvMCByte13;s01e04Cipher1InvMC[14]=ui->s01e04Cipher1InvMCByte14;s01e04Cipher1InvMC[15]=ui->s01e04Cipher1InvMCByte15;

    s02e01plain1 = new QLabel*[16];
    s02e01plain1[0]=ui->plain1s02e01Byte00;s02e01plain1[1]=ui->plain1s02e01Byte01;s02e01plain1[2]=ui->plain1s02e01Byte02;s02e01plain1[3]=ui->plain1s02e01Byte03;
    s02e01plain1[4]=ui->plain1s02e01Byte04;s02e01plain1[5]=ui->plain1s02e01Byte05;s02e01plain1[6]=ui->plain1s02e01Byte06;s02e01plain1[7]=ui->plain1s02e01Byte07;
    s02e01plain1[8]=ui->plain1s02e01Byte08;s02e01plain1[9]=ui->plain1s02e01Byte09;s02e01plain1[10]=ui->plain1s02e01Byte10;s02e01plain1[11]=ui->plain1s02e01Byte11;
    s02e01plain1[12]=ui->plain1s02e01Byte12;s02e01plain1[13]=ui->plain1s02e01Byte13;s02e01plain1[14]=ui->plain1s02e01Byte14;s02e01plain1[15]=ui->plain1s02e01Byte15;

    s02e01plain2 = new QLabel*[16];
    s02e01plain2[0]=ui->plain2s02e01Byte00;s02e01plain2[1]=ui->plain2s02e01Byte01;s02e01plain2[2]=ui->plain2s02e01Byte02;s02e01plain2[3]=ui->plain2s02e01Byte03;
    s02e01plain2[4]=ui->plain2s02e01Byte04;s02e01plain2[5]=ui->plain2s02e01Byte05;s02e01plain2[6]=ui->plain2s02e01Byte06;s02e01plain2[7]=ui->plain2s02e01Byte07;
    s02e01plain2[8]=ui->plain2s02e01Byte08;s02e01plain2[9]=ui->plain2s02e01Byte09;s02e01plain2[10]=ui->plain2s02e01Byte10;s02e01plain2[11]=ui->plain2s02e01Byte11;
    s02e01plain2[12]=ui->plain2s02e01Byte12;s02e01plain2[13]=ui->plain2s02e01Byte13;s02e01plain2[14]=ui->plain2s02e01Byte14;s02e01plain2[15]=ui->plain2s02e01Byte15;

    s02e01plain3 = new QLabel*[16];
    s02e01plain3[0]=ui->plain3s02e01Byte00;s02e01plain3[1]=ui->plain3s02e01Byte01;s02e01plain3[2]=ui->plain3s02e01Byte02;s02e01plain3[3]=ui->plain3s02e01Byte03;
    s02e01plain3[4]=ui->plain3s02e01Byte04;s02e01plain3[5]=ui->plain3s02e01Byte05;s02e01plain3[6]=ui->plain3s02e01Byte06;s02e01plain3[7]=ui->plain3s02e01Byte07;
    s02e01plain3[8]=ui->plain3s02e01Byte08;s02e01plain3[9]=ui->plain3s02e01Byte09;s02e01plain3[10]=ui->plain3s02e01Byte10;s02e01plain3[11]=ui->plain3s02e01Byte11;
    s02e01plain3[12]=ui->plain3s02e01Byte12;s02e01plain3[13]=ui->plain3s02e01Byte13;s02e01plain3[14]=ui->plain3s02e01Byte14;s02e01plain3[15]=ui->plain3s02e01Byte15;

    s02e03Cipher1InvMC = new QLabel*[16];
    s02e03Cipher1InvMC[0]=ui->s02e03Cipher1InvMCByte00;s02e03Cipher1InvMC[1]=ui->s02e03Cipher1InvMCByte01;s02e03Cipher1InvMC[2]=ui->s02e03Cipher1InvMCByte02;s02e03Cipher1InvMC[3]=ui->s02e03Cipher1InvMCByte03;
    s02e03Cipher1InvMC[4]=ui->s02e03Cipher1InvMCByte04;s02e03Cipher1InvMC[5]=ui->s02e03Cipher1InvMCByte05;s02e03Cipher1InvMC[6]=ui->s02e03Cipher1InvMCByte06;s02e03Cipher1InvMC[7]=ui->s02e03Cipher1InvMCByte07;
    s02e03Cipher1InvMC[8]=ui->s02e03Cipher1InvMCByte08;s02e03Cipher1InvMC[9]=ui->s02e03Cipher1InvMCByte09;s02e03Cipher1InvMC[10]=ui->s02e03Cipher1InvMCByte10;s02e03Cipher1InvMC[11]=ui->s02e03Cipher1InvMCByte11;
    s02e03Cipher1InvMC[12]=ui->s02e03Cipher1InvMCByte12;s02e03Cipher1InvMC[13]=ui->s02e03Cipher1InvMCByte13;s02e03Cipher1InvMC[14]=ui->s02e03Cipher1InvMCByte14;s02e03Cipher1InvMC[15]=ui->s02e03Cipher1InvMCByte15;


    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabOutput));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabInput));

    on_actionExample_1_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* pObject, QEvent* pEvent)
{

    if (pEvent->type() == 77){
        if (dialogShowSubKeys != NULL)
        if (dialogShowSubKeys->isVisible()){
             dialogShowSubKeys->setSubKeysMatrix(subkeyk0, subkeyk1, subkeyk2, subkeyu2);
             dialogShowSubKeys->forceUpdate();
        }
    }
    return QObject::eventFilter(pObject, pEvent);

}

unsigned char hexValue(char hex){
        if (hex >= 48 && hex <= 57){
                return hex - 48;
        }
        else if (toupper(hex) >= 65 && toupper(hex) <= 70){
                return toupper(hex) - 55;
        }
        else{
                return hex;
        }
}

void hexStringToCharString(std::string hexString, int hexStringLen, unsigned char* charString){
        for (int i = 0; i < hexStringLen; i=i+2){
                charString[i/2] = hexValue(hexString[i]) * 16 + hexValue(hexString[i+1]);
        }
}

void MainWindow::on_editByte00From_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte00From->setText(text.toUpper());
    ui->editSugK0Byte00->setText(text.toUpper());
}

void MainWindow::on_editByte00To_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte00To->setText(text.toUpper());    
}

void MainWindow::on_editByte05From_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte05From->setText(text.toUpper());
    ui->editSugK0Byte05->setText(text.toUpper());
}

void MainWindow::on_editByte05To_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte05To->setText(text.toUpper());
}

void MainWindow::on_editByte07From_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte07From->setText(text.toUpper());
    ui->editSugK0Byte07->setText(text.toUpper());
}

void MainWindow::on_editByte07To_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte07To->setText(text.toUpper());
}

void MainWindow::on_editByte08From_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte08From->setText(text.toUpper());
    ui->editSugK0Byte08->setText(text.toUpper());
}

void MainWindow::on_editByte08To_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte08To->setText(text.toUpper());
}

void MainWindow::on_editByte10From_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte10From->setText(text.toUpper());
    ui->editSugK0Byte10->setText(text.toUpper());
}

void MainWindow::on_editByte10To_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte10To->setText(text.toUpper());
}

void MainWindow::on_editByte15From_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte15From->setText(text.toUpper());
    ui->editSugK0Byte15->setText(text.toUpper());
}

void MainWindow::on_editByte15To_textEdited(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte15To->setText(text.toUpper());
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void hexToUpperCaseText(unsigned char &hex, char* temp_string){
        snprintf(temp_string, 3, "%.2x", hex);
        temp_string[0] = toupper(temp_string[0]);
        temp_string[1] = toupper(temp_string[1]);
}

void MainWindow::setOutK0(unsigned char* block){
    char* temp_string = new char [3];
    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(block[i], temp_string);
        outK0Array[i]->setText(temp_string);
    }
    delete[] temp_string;
}

void MainWindow::setOutK0(QString block){
    QString temp_string = "FF";
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = block[i].toUpper();
        temp_string[1] = block[i+1].toUpper();
        outK0Array[i/2]->setText(temp_string);
    }
}

void MainWindow::setOutPlain1(QString block){
    QString temp_string = "FF";
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = block[i].toUpper();
        temp_string[1] = block[i+1].toUpper();
        outPlain1Array[i/2]->setText(temp_string);
    }
}

void MainWindow::setOutCipher1(QString block){
    QString temp_string = "FF";
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = block[i].toUpper();
        temp_string[1] = block[i+1].toUpper();
        outCipher1Array[i/2]->setText(temp_string);
    }
}

void MainWindow::setOutCipherK0(unsigned char* block){
    char* temp_string = new char [3];
    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(block[i], temp_string);
        outCipherK0Array[i]->setText(temp_string);
    }
    delete[] temp_string;
}

void MainWindow::setOutCipherK0(QString block){
    QString temp_string = "FF";
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = block[i].toUpper();
        temp_string[1] = block[i+1].toUpper();
        outCipherK0Array[i/2]->setText(temp_string);
    }
}

void MainWindow::on_actionRun_triggered(){
    unsigned char** plaintexts = new unsigned char* [3];
    unsigned char* plaintext1 = new unsigned char [16];
    unsigned char* plaintext2 = new unsigned char [16];
    unsigned char* plaintext3 = new unsigned char [16];
    plaintexts[0] = plaintext1;
    plaintexts[1] = plaintext2;
    plaintexts[2] = plaintext3;
    unsigned char** ciphertexts = new unsigned char* [3];
    unsigned char* ciphertext1 = new unsigned char [16];
    unsigned char* ciphertext2 = new unsigned char [16];
    unsigned char* ciphertext3 = new unsigned char [16];
    ciphertexts[0] = ciphertext1;
    ciphertexts[1] = ciphertext2;
    ciphertexts[2] = ciphertext3;
    hexStringToCharString(ui->editPlaintext1->text().toStdString(), 32, plaintext1);
    hexStringToCharString(ui->editPlaintext2->text().toStdString(), 32, plaintext2);
    hexStringToCharString(ui->editPlaintext3->text().toStdString(), 32, plaintext3);
    hexStringToCharString(ui->editCiphertext1->text().toStdString(), 32, ciphertext1);
    hexStringToCharString(ui->editCiphertext2->text().toStdString(), 32, ciphertext2);
    hexStringToCharString(ui->editCiphertext3->text().toStdString(), 32, ciphertext3);

    unsigned char k0byte00from, k0byte00to;
    hexStringToCharString(ui->editByte00From->text().toStdString(), 2, &k0byte00from);
    hexStringToCharString(ui->editByte00To->text().toStdString(), 2, &k0byte00to);
    unsigned char k0byte05from, k0byte05to;
    hexStringToCharString(ui->editByte05From->text().toStdString(), 2, &k0byte05from);
    hexStringToCharString(ui->editByte05To->text().toStdString(), 2, &k0byte05to);
    unsigned char k0byte07from, k0byte07to;
    hexStringToCharString(ui->editByte07From->text().toStdString(), 2, &k0byte07from);
    hexStringToCharString(ui->editByte07To->text().toStdString(), 2, &k0byte07to);
    unsigned char k0byte08from, k0byte08to;
    hexStringToCharString(ui->editByte08From->text().toStdString(), 2, &k0byte08from);
    hexStringToCharString(ui->editByte08To->text().toStdString(), 2, &k0byte08to);
    unsigned char k0byte10from, k0byte10to;
    hexStringToCharString(ui->editByte10From->text().toStdString(), 2, &k0byte10from);
    hexStringToCharString(ui->editByte10To->text().toStdString(), 2, &k0byte10to);
    unsigned char k0byte15from, k0byte15to;
    hexStringToCharString(ui->editByte15From->text().toStdString(), 2, &k0byte15from);
    hexStringToCharString(ui->editByte15To->text().toStdString(), 2, &k0byte15to);

    if (rijnAttacker.findKeyForTwoRounds(plaintexts, ciphertexts, 3, k0found, k0byte00from, k0byte00to, k0byte05from, k0byte05to, k0byte07from, k0byte07to, k0byte08from, k0byte08to, k0byte10from, k0byte10to, k0byte15from, k0byte15to)){
        keyFound = true;
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setText("Key found!");
        msgBox->show();
        ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabOutput));
    }
    else{
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setText("Key nof found! Change search range for K0 or try with another plaintext/ciphertext pairs.");
        msgBox->show();
    }

    delete[] plaintexts;
    delete[] plaintext1;
    delete[] plaintext2;
    delete[] plaintext3;
    delete[] ciphertexts;
    delete[] ciphertext1;
    delete[] ciphertext2;
    delete[] ciphertext3;
}

void MainWindow::on_editPlaintext1_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editPlaintext1->setText(text.toUpper());
}

void MainWindow::on_editPlaintext2_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editPlaintext2->setText(text.toUpper());
}

void MainWindow::on_editPlaintext3_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editPlaintext3->setText(text.toUpper());
}

void MainWindow::on_editCiphertext1_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editCiphertext1->setText(text.toUpper());
}

void MainWindow::on_editCiphertext2_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editCiphertext2->setText(text.toUpper());
}

void MainWindow::on_editCiphertext3_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editCiphertext3->setText(text.toUpper());
}

void MainWindow::on_actionExample_1_triggered()
{
    ui->editPlaintext1->setText("00112233445566778899AABBCCDDEEFF");
    ui->editPlaintext2->setText("FFEEDDCCBBAA99887766554433221100");
    ui->editPlaintext3->setText("778899AABBCCDDEEFF00112233445566");
    ui->editCiphertext1->setText("4915598f55e5d7a0daca94fa1f0a63f7");
    ui->editCiphertext2->setText("fb6efda82cd1056060fd9680f11849cb");
    ui->editCiphertext3->setText("a6268dd1f63b351c31930b95dd059b8d");
    ui->editByte00From->setText("00");ui->editByte00To->setText("FF");
    ui->editByte05From->setText("00");ui->editByte05To->setText("FF");
    ui->editByte07From->setText("00");ui->editByte07To->setText("FF");
    ui->editByte08From->setText("00");ui->editByte08To->setText("FF");
    ui->editByte10From->setText("00");ui->editByte10To->setText("FF");
    ui->editByte15From->setText("00");ui->editByte15To->setText("FF");
    ui->editSugK0Byte00->setText("00");
    ui->editSugK0Byte05->setText("05");
    ui->editSugK0Byte07->setText("07");
    ui->editSugK0Byte08->setText("08");
    ui->editSugK0Byte10->setText("0A");
    ui->editSugK0Byte15->setText("0F");
}

void MainWindow::setPlainS01E01(QString plain1, QString plain2, QString plain3){
    QString temp_string = "FF";
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = plain1[i].toUpper();
        temp_string[1] = plain1[i+1].toUpper();
        s01e01plain1[i/2]->setText(temp_string);
    }
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = plain2[i].toUpper();
        temp_string[1] = plain2[i+1].toUpper();
        s01e01plain2[i/2]->setText(temp_string);
    }
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = plain3[i].toUpper();
        temp_string[1] = plain3[i+1].toUpper();
        s01e01plain3[i/2]->setText(temp_string);
    }
}

void MainWindow::setPlainS02E01(){
    for (int i = 0; i < 15; i++){
        s02e01plain1[i]->setText(s01e01plain1[i]->text());
        s02e01plain2[i]->setText(s01e01plain2[i]->text());
        s02e01plain3[i]->setText(s01e01plain3[i]->text());
    }
    ui->plain1s02e01Byte00->setText(ui->outPlain1s01e01Byte00->text());ui->plain1s02e01Byte05->setText(ui->outPlain1s01e01Byte05->text());
    ui->plain1s02e01Byte10->setText(ui->outPlain1s01e01Byte10->text());ui->plain1s02e01Byte15->setText(ui->outPlain1s01e01Byte15->text());
    ui->plain2s02e01Byte00->setText(ui->outPlain2s01e01Byte00->text());ui->plain2s02e01Byte05->setText(ui->outPlain2s01e01Byte05->text());
    ui->plain2s02e01Byte10->setText(ui->outPlain2s01e01Byte10->text());ui->plain2s02e01Byte15->setText(ui->outPlain2s01e01Byte15->text());
    ui->plain3s02e01Byte00->setText(ui->outPlain3s01e01Byte00->text());ui->plain3s02e01Byte05->setText(ui->outPlain3s01e01Byte05->text());
    ui->plain3s02e01Byte10->setText(ui->outPlain3s01e01Byte10->text());ui->plain3s02e01Byte15->setText(ui->outPlain3s01e01Byte15->text());

    ui->plain1s02e01ARKByte00->setText(ui->outPlain1s01e01ARKByte00->text());ui->plain1s02e01ARKByte05->setText(ui->outPlain1s01e01ARKByte05->text());
    ui->plain1s02e01ARKByte10->setText(ui->outPlain1s01e01ARKByte10->text());ui->plain1s02e01ARKByte15->setText(ui->outPlain1s01e01ARKByte15->text());
    ui->plain2s02e01ARKByte00->setText(ui->outPlain2s01e01ARKByte00->text());ui->plain2s02e01ARKByte05->setText(ui->outPlain2s01e01ARKByte05->text());
    ui->plain2s02e01ARKByte10->setText(ui->outPlain2s01e01ARKByte10->text());ui->plain2s02e01ARKByte15->setText(ui->outPlain2s01e01ARKByte15->text());
    ui->plain3s02e01ARKByte00->setText(ui->outPlain3s01e01ARKByte00->text());ui->plain3s02e01ARKByte05->setText(ui->outPlain3s01e01ARKByte05->text());
    ui->plain3s02e01ARKByte10->setText(ui->outPlain3s01e01ARKByte10->text());ui->plain3s02e01ARKByte15->setText(ui->outPlain3s01e01ARKByte15->text());

    ui->plain1s02e01SBByte00->setText(ui->outPlain1s01e01SBByte00->text());ui->plain1s02e01SBByte05->setText(ui->outPlain1s01e01SBByte05->text());
    ui->plain1s02e01SBByte10->setText(ui->outPlain1s01e01SBByte10->text());ui->plain1s02e01SBByte15->setText(ui->outPlain1s01e01SBByte15->text());
    ui->plain2s02e01SBByte00->setText(ui->outPlain2s01e01SBByte00->text());ui->plain2s02e01SBByte05->setText(ui->outPlain2s01e01SBByte05->text());
    ui->plain2s02e01SBByte10->setText(ui->outPlain2s01e01SBByte10->text());ui->plain2s02e01SBByte15->setText(ui->outPlain2s01e01SBByte15->text());
    ui->plain3s02e01SBByte00->setText(ui->outPlain3s01e01SBByte00->text());ui->plain3s02e01SBByte05->setText(ui->outPlain3s01e01SBByte05->text());
    ui->plain3s02e01SBByte10->setText(ui->outPlain3s01e01SBByte10->text());ui->plain3s02e01SBByte15->setText(ui->outPlain3s01e01SBByte15->text());

    ui->plain1s02e01SRByte00->setText(ui->outPlain1s01e01SRByte00->text());ui->plain1s02e01SRByte01->setText(ui->outPlain1s01e01SRByte01->text());
    ui->plain1s02e01SRByte02->setText(ui->outPlain1s01e01SRByte02->text());ui->plain1s02e01SRByte03->setText(ui->outPlain1s01e01SRByte03->text());
    ui->plain2s02e01SRByte00->setText(ui->outPlain2s01e01SRByte00->text());ui->plain2s02e01SRByte01->setText(ui->outPlain2s01e01SRByte01->text());
    ui->plain2s02e01SRByte02->setText(ui->outPlain2s01e01SRByte02->text());ui->plain2s02e01SRByte03->setText(ui->outPlain2s01e01SRByte03->text());
    ui->plain3s02e01SRByte00->setText(ui->outPlain3s01e01SRByte00->text());ui->plain3s02e01SRByte01->setText(ui->outPlain3s01e01SRByte01->text());
    ui->plain3s02e01SRByte02->setText(ui->outPlain3s01e01SRByte02->text());ui->plain3s02e01SRByte03->setText(ui->outPlain3s01e01SRByte03->text());

    ui->plain1s02e01MCByte00->setText(ui->outPlain1s01e01MCByte00->text());ui->plain1s02e01MCByte01->setText(ui->outPlain1s01e01MCByte01->text());
    ui->plain1s02e01MCByte02->setText(ui->outPlain1s01e01MCByte02->text());ui->plain1s02e01MCByte03->setText(ui->outPlain1s01e01MCByte03->text());
    ui->plain2s02e01MCByte00->setText(ui->outPlain2s01e01MCByte00->text());ui->plain2s02e01MCByte01->setText(ui->outPlain2s01e01MCByte01->text());
    ui->plain2s02e01MCByte02->setText(ui->outPlain2s01e01MCByte02->text());ui->plain2s02e01MCByte03->setText(ui->outPlain2s01e01MCByte03->text());
    ui->plain3s02e01MCByte00->setText(ui->outPlain3s01e01MCByte00->text());ui->plain3s02e01MCByte01->setText(ui->outPlain3s01e01MCByte01->text());
    ui->plain3s02e01MCByte02->setText(ui->outPlain3s01e01MCByte02->text());ui->plain3s02e01MCByte03->setText(ui->outPlain3s01e01MCByte03->text());
}

void MainWindow::setCipherS01E02(QString cipher1, QString cipher2, QString cipher3){
    QString temp_string = "FF";
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = cipher1[i].toUpper();
        temp_string[1] = cipher1[i+1].toUpper();
        s01e02cipher1[i/2]->setText(temp_string);
    }
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = cipher2[i].toUpper();
        temp_string[1] = cipher2[i+1].toUpper();
        s01e02cipher2[i/2]->setText(temp_string);
    }
    for (int i = 0; i < 32; i+=2){
        temp_string[0] = cipher3[i].toUpper();
        temp_string[1] = cipher3[i+1].toUpper();
        s01e02cipher3[i/2]->setText(temp_string);
    }
}

void MainWindow::setColumnsS01E03(){
    ui->s01e03plain1AfterR1Col0Byte00->setText(ui->outPlain1s01e01MCByte00->text());
    ui->s01e03plain1AfterR1Col0Byte01->setText(ui->outPlain1s01e01MCByte01->text());
    ui->s01e03plain1AfterR1Col0Byte02->setText(ui->outPlain1s01e01MCByte02->text());
    ui->s01e03plain1AfterR1Col0Byte03->setText(ui->outPlain1s01e01MCByte03->text());
    ui->s01e03plain2AfterR1Col0Byte00->setText(ui->outPlain2s01e01MCByte00->text());
    ui->s01e03plain2AfterR1Col0Byte01->setText(ui->outPlain2s01e01MCByte01->text());
    ui->s01e03plain2AfterR1Col0Byte02->setText(ui->outPlain2s01e01MCByte02->text());
    ui->s01e03plain2AfterR1Col0Byte03->setText(ui->outPlain2s01e01MCByte03->text());
    ui->s01e03plain3AfterR1Col0Byte00->setText(ui->outPlain3s01e01MCByte00->text());
    ui->s01e03plain3AfterR1Col0Byte01->setText(ui->outPlain3s01e01MCByte01->text());
    ui->s01e03plain3AfterR1Col0Byte02->setText(ui->outPlain3s01e01MCByte02->text());
    ui->s01e03plain3AfterR1Col0Byte03->setText(ui->outPlain3s01e01MCByte03->text());

    ui->s01e03InvCipherDiff12Column0Byte00->setText(ui->s01e02InvCipherDiff12SRByte00->text());
    ui->s01e03InvCipherDiff12Column0Byte01->setText(ui->s01e02InvCipherDiff12SRByte01->text());
    ui->s01e03InvCipherDiff12Column0Byte02->setText(ui->s01e02InvCipherDiff12SRByte02->text());
    ui->s01e03InvCipherDiff12Column0Byte03->setText(ui->s01e02InvCipherDiff12SRByte03->text());
    ui->s01e03InvCipherDiff13Column0Byte00->setText(ui->s01e02InvCipherDiff13SRByte00->text());
    ui->s01e03InvCipherDiff13Column0Byte01->setText(ui->s01e02InvCipherDiff13SRByte01->text());
    ui->s01e03InvCipherDiff13Column0Byte02->setText(ui->s01e02InvCipherDiff13SRByte02->text());
    ui->s01e03InvCipherDiff13Column0Byte03->setText(ui->s01e02InvCipherDiff13SRByte03->text());

    ui->s01e03plain1AfterR1Col0Byte00_2->setText(ui->outPlain1s01e01MCByte00->text());
    ui->s01e03plain1AfterR1Col0Byte01_2->setText(ui->outPlain1s01e01MCByte01->text());
    ui->s01e03plain1AfterR1Col0Byte02_2->setText(ui->outPlain1s01e01MCByte02->text());
    ui->s01e03plain1AfterR1Col0Byte03_2->setText(ui->outPlain1s01e01MCByte03->text());

    //ui->s01e03k1Byte00->setText("??"); ui->s01e03k1Byte01->setText("??"); ui->s01e03k1Byte02->setText("??"); ui->s01e03k1Byte03->setText("??");

    unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
    char* temp_string = new char [3];

    byte_temp_a = hexValue(ui->s01e03plain1AfterR1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain1AfterR1Col0Byte00->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e03plain2AfterR1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain2AfterR1Col0Byte00->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s01e03plain3AfterR1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain3AfterR1Col0Byte00->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    byte_temp_c ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s01e03plainAfterR1Diff12Col0Byte00->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);
    ui->s01e03plainAfterR1Diff13Col0Byte00->setText(temp_string);

    byte_temp_a = hexValue(ui->s01e03plain1AfterR1Col0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain1AfterR1Col0Byte01->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e03plain2AfterR1Col0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain2AfterR1Col0Byte01->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s01e03plain3AfterR1Col0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain3AfterR1Col0Byte01->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    byte_temp_c ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s01e03plainAfterR1Diff12Col0Byte01->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);
    ui->s01e03plainAfterR1Diff13Col0Byte01->setText(temp_string);

    byte_temp_a = hexValue(ui->s01e03plain1AfterR1Col0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain1AfterR1Col0Byte02->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e03plain2AfterR1Col0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain2AfterR1Col0Byte02->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s01e03plain3AfterR1Col0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain3AfterR1Col0Byte02->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    byte_temp_c ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s01e03plainAfterR1Diff12Col0Byte02->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);
    ui->s01e03plainAfterR1Diff13Col0Byte02->setText(temp_string);

    byte_temp_a = hexValue(ui->s01e03plain1AfterR1Col0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain1AfterR1Col0Byte03->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e03plain2AfterR1Col0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain2AfterR1Col0Byte03->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s01e03plain3AfterR1Col0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain3AfterR1Col0Byte03->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    byte_temp_c ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s01e03plainAfterR1Diff12Col0Byte03->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);
    ui->s01e03plainAfterR1Diff13Col0Byte03->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::setColumnAndBlockS01E04(){
    ui->s01e04plain1AfterR1Col0Byte00->setText(ui->outPlain1s01e01MCByte00->text());
    ui->s01e04plain1AfterR1Col0Byte01->setText(ui->outPlain1s01e01MCByte01->text());
    ui->s01e04plain1AfterR1Col0Byte02->setText(ui->outPlain1s01e01MCByte02->text());
    ui->s01e04plain1AfterR1Col0Byte03->setText(ui->outPlain1s01e01MCByte03->text());

    ui->s01e04plain2AfterR1Col0Byte00->setText(ui->outPlain2s01e01MCByte00->text());
    ui->s01e04plain3AfterR1Col0Byte00->setText(ui->outPlain3s01e01MCByte00->text());

    ui->s01e04Cipher2InvMCByte00->setText(ui->s01e02Cipher2InvMCByte00->text());
    ui->s01e04Cipher3InvMCByte00->setText(ui->s01e02Cipher3InvMCByte00->text());

    for (int i = 0; i < 16; i++){
        s01e04Cipher1InvMC[i]->setText(s01e02Cipher1InvMC[i]->text());
    }

    ui->k0byte00->setText(subkeyk0[0]);ui->k0byte05->setText(subkeyk0[5]);ui->k0byte10->setText(subkeyk0[10]);ui->k0byte15->setText(subkeyk0[15]);
    ui->k1byte00->setText(subkeyk1[0]);ui->k1byte01->setText(subkeyk1[1]);ui->k1byte02->setText(subkeyk1[2]);ui->k1byte03->setText(subkeyk1[3]);
}

void MainWindow::setColumnAndBlockS02E03(){
    ui->s02e03plain1AfterR1Col2Byte08->setText(ui->plain1s02e01MCByte08->text());
    ui->s02e03plain1AfterR1Col2Byte09->setText(ui->plain1s02e01MCByte09->text());
    ui->s02e03plain1AfterR1Col2Byte10->setText(ui->plain1s02e01MCByte10->text());
    ui->s02e03plain1AfterR1Col2Byte11->setText(ui->plain1s02e01MCByte11->text());

    for (int i = 0; i < 16; i++){
        s02e03Cipher1InvMC[i]->setText(s01e02Cipher1InvMC[i]->text());
    }

    ui->s02e03plain1AfterSRR1Byte00->setText(ui->s01e04plain1AfterSRR1Byte00->text());
    ui->s02e03plain1AfterSRR1Byte07->setText(ui->s01e04plain1AfterSRR1Byte07->text());
    ui->s02e03plain1AfterSRR1Byte10->setText(ui->s01e04plain1AfterSRR1Byte10->text());
    ui->s02e03plain1AfterSRR1Byte13->setText(ui->s01e04plain1AfterSRR1Byte13->text());

    ui->s02e03u2Byte00->setText(ui->s01e04u2Byte00->text());
    ui->s02e03u2Byte07->setText(ui->s01e04u2Byte07->text());
    ui->s02e03u2Byte10->setText(ui->s01e04u2Byte10->text());
    ui->s02e03u2Byte13->setText(ui->s01e04u2Byte13->text());

    ui->k0byte00_2->setText(subkeyk0[0]);ui->k0byte05_2->setText(subkeyk0[5]);ui->k0byte10_2->setText(subkeyk0[10]);ui->k0byte15_2->setText(subkeyk0[15]);
    ui->k0byte02_2->setText(subkeyk0[2]);ui->k0byte07_2->setText(subkeyk0[7]);ui->k0byte08_2->setText(subkeyk0[8]);ui->k0byte13_2->setText(subkeyk0[13]);
    ui->k1byte00_2->setText(subkeyk1[0]);ui->k1byte01_2->setText(subkeyk1[1]);ui->k1byte02_2->setText(subkeyk1[2]);ui->k1byte03_2->setText(subkeyk1[3]);
    ui->k1byte08_2->setText(subkeyk1[8]);ui->k1byte09_2->setText(subkeyk1[9]);ui->k1byte10_2->setText(subkeyk1[10]);ui->k1byte11_2->setText(subkeyk1[11]);
    ui->k1byte05_2->setText(subkeyk1[5]);
}

void MainWindow::setColumnsS02E02(){
    ui->s02e02plain1AfterR1Col2Byte08->setText(ui->plain1s02e01MCByte08->text());
    ui->s02e02plain1AfterR1Col2Byte09->setText(ui->plain1s02e01MCByte09->text());
    ui->s02e02plain1AfterR1Col2Byte10->setText(ui->plain1s02e01MCByte10->text());
    ui->s02e02plain1AfterR1Col2Byte11->setText(ui->plain1s02e01MCByte11->text());
    ui->s02e02plain2AfterR1Col2Byte08->setText(ui->plain2s02e01MCByte08->text());
    ui->s02e02plain2AfterR1Col2Byte09->setText(ui->plain2s02e01MCByte09->text());
    ui->s02e02plain2AfterR1Col2Byte10->setText(ui->plain2s02e01MCByte10->text());
    ui->s02e02plain2AfterR1Col2Byte11->setText(ui->plain2s02e01MCByte11->text());
    ui->s02e02plain3AfterR1Col2Byte08->setText(ui->plain3s02e01MCByte08->text());
    ui->s02e02plain3AfterR1Col2Byte09->setText(ui->plain3s02e01MCByte09->text());
    ui->s02e02plain3AfterR1Col2Byte10->setText(ui->plain3s02e01MCByte10->text());
    ui->s02e02plain3AfterR1Col2Byte11->setText(ui->plain3s02e01MCByte11->text());

    ui->s02e02InvCipherDiff12Column2Byte08->setText(ui->s01e02InvCipherDiff12SRByte08->text());
    ui->s02e02InvCipherDiff12Column2Byte09->setText(ui->s01e02InvCipherDiff12SRByte09->text());
    ui->s02e02InvCipherDiff12Column2Byte10->setText(ui->s01e02InvCipherDiff12SRByte10->text());
    ui->s02e02InvCipherDiff12Column2Byte11->setText(ui->s01e02InvCipherDiff12SRByte11->text());
    ui->s02e02InvCipherDiff13Column2Byte08->setText(ui->s01e02InvCipherDiff13SRByte08->text());
    ui->s02e02InvCipherDiff13Column2Byte09->setText(ui->s01e02InvCipherDiff13SRByte09->text());
    ui->s02e02InvCipherDiff13Column2Byte10->setText(ui->s01e02InvCipherDiff13SRByte10->text());
    ui->s02e02InvCipherDiff13Column2Byte11->setText(ui->s01e02InvCipherDiff13SRByte11->text());

    ui->s02e02plain1AfterR1Col2Byte08_2->setText(ui->plain1s02e01MCByte08->text());
    ui->s02e02plain1AfterR1Col2Byte09_2->setText(ui->plain1s02e01MCByte09->text());
    ui->s02e02plain1AfterR1Col2Byte10_2->setText(ui->plain1s02e01MCByte10->text());
    ui->s02e02plain1AfterR1Col2Byte11_2->setText(ui->plain1s02e01MCByte11->text());

    unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
    char* temp_string = new char [3];

    byte_temp_a = hexValue(ui->s02e02plain1AfterR1Col2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain1AfterR1Col2Byte08->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s02e02plain2AfterR1Col2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain2AfterR1Col2Byte08->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s02e02plain3AfterR1Col2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain3AfterR1Col2Byte08->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    byte_temp_c ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s02e02plainAfterR1Diff12Col2Byte08->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);
    ui->s02e02plainAfterR1Diff13Col2Byte08->setText(temp_string);

    byte_temp_a = hexValue(ui->s02e02plain1AfterR1Col2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain1AfterR1Col2Byte09->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s02e02plain2AfterR1Col2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain2AfterR1Col2Byte09->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s02e02plain3AfterR1Col2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain3AfterR1Col2Byte09->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    byte_temp_c ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s02e02plainAfterR1Diff12Col2Byte09->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);
    ui->s02e02plainAfterR1Diff13Col2Byte09->setText(temp_string);

    byte_temp_a = hexValue(ui->s02e02plain1AfterR1Col2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain1AfterR1Col2Byte10->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s02e02plain2AfterR1Col2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain2AfterR1Col2Byte10->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s02e02plain3AfterR1Col2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain3AfterR1Col2Byte10->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    byte_temp_c ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s02e02plainAfterR1Diff12Col2Byte10->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);
    ui->s02e02plainAfterR1Diff13Col2Byte10->setText(temp_string);

    byte_temp_a = hexValue(ui->s02e02plain1AfterR1Col2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain1AfterR1Col2Byte11->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s02e02plain2AfterR1Col2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain2AfterR1Col2Byte11->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s02e02plain3AfterR1Col2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain3AfterR1Col2Byte11->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    byte_temp_c ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s02e02plainAfterR1Diff12Col2Byte11->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);
    ui->s02e02plainAfterR1Diff13Col2Byte11->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::setColumnsS02E04(){
    ui->s02e04k2byte00->setText(subkeyk2[0]);
    ui->s02e04k2byte02->setText(subkeyk2[2]);
    ui->s02e04u2Byte00->setText(subkeyu2[0]);
    ui->s02e04u2Byte02->setText(subkeyu2[2]);

    ui->s02e04sysk2byte00->setText(subkeyk2[0]);
    ui->s02e04sysk2byte02->setText(subkeyk2[2]);
    ui->s02e04sysu2byte00_0->setText(subkeyu2[0]);ui->s02e04sysu2byte00_1->setText(subkeyu2[0]);ui->s02e04sysu2byte00_2->setText(subkeyu2[0]);ui->s02e04sysu2byte00_3->setText(subkeyu2[0]);
    ui->s02e04sysu2byte02_0->setText(subkeyu2[2]);ui->s02e04sysu2byte02_1->setText(subkeyu2[2]);ui->s02e04sysu2byte02_2->setText(subkeyu2[2]);ui->s02e04sysu2byte02_3->setText(subkeyu2[2]);

    ui->k0byte00_3->setText(subkeyk0[0]);ui->k0byte02_3->setText(subkeyk0[2]);ui->k0byte05_3->setText(subkeyk0[5]);ui->k0byte07_3->setText(subkeyk0[7]);
    ui->k0byte08_3->setText(subkeyk0[8]);ui->k0byte10_3->setText(subkeyk0[10]);ui->k0byte13_3->setText(subkeyk0[13]);ui->k0byte15_3->setText(subkeyk0[15]);

    ui->k1byte00_3->setText(subkeyk1[0]);ui->k1byte01_3->setText(subkeyk1[1]);ui->k1byte02_3->setText(subkeyk1[2]);ui->k1byte03_3->setText(subkeyk1[3]);
    ui->k1byte04_3->setText(subkeyk1[4]);ui->k1byte05_3->setText(subkeyk1[5]);ui->k1byte06_3->setText(subkeyk1[6]);ui->k1byte07_3->setText(subkeyk1[7]);
    ui->k1byte08_3->setText(subkeyk1[8]);ui->k1byte09_3->setText(subkeyk1[9]);ui->k1byte10_3->setText(subkeyk1[10]);ui->k1byte11_3->setText(subkeyk1[11]);
    ui->k1byte13_3->setText(subkeyk1[13]);ui->k1byte15_3->setText(subkeyk1[15]);

    ui->k2byte00_2->setText(subkeyk2[0]);
    ui->k2byte02_2->setText(subkeyk2[2]);
}

void MainWindow::on_buttonS01E01ARK_clicked()
{
    unsigned char plain_byte_temp;
    char* temp_string = new char [3];

    plain_byte_temp = hexValue(ui->outPlain1s01e01Byte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01Byte00->text().at(1).toAscii());
    plain_byte_temp ^= tryByte00;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain1s01e01ARKByte00->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain1s01e01Byte05->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01Byte05->text().at(1).toAscii());
    plain_byte_temp ^= tryByte05;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain1s01e01ARKByte05->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain1s01e01Byte10->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01Byte10->text().at(1).toAscii());
    plain_byte_temp ^= tryByte10;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain1s01e01ARKByte10->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain1s01e01Byte15->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01Byte15->text().at(1).toAscii());
    plain_byte_temp ^= tryByte15;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain1s01e01ARKByte15->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain2s01e01Byte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01Byte00->text().at(1).toAscii());
    plain_byte_temp ^= tryByte00;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain2s01e01ARKByte00->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain2s01e01Byte05->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01Byte05->text().at(1).toAscii());
    plain_byte_temp ^= tryByte05;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain2s01e01ARKByte05->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain2s01e01Byte10->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01Byte10->text().at(1).toAscii());
    plain_byte_temp ^= tryByte10;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain2s01e01ARKByte10->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain2s01e01Byte15->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01Byte15->text().at(1).toAscii());
    plain_byte_temp ^= tryByte15;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain2s01e01ARKByte15->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain3s01e01Byte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01Byte00->text().at(1).toAscii());
    plain_byte_temp ^= tryByte00;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain3s01e01ARKByte00->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain3s01e01Byte05->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01Byte05->text().at(1).toAscii());
    plain_byte_temp ^= tryByte05;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain3s01e01ARKByte05->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain3s01e01Byte10->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01Byte10->text().at(1).toAscii());
    plain_byte_temp ^= tryByte10;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain3s01e01ARKByte10->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain3s01e01Byte15->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01Byte15->text().at(1).toAscii());
    plain_byte_temp ^= tryByte15;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain3s01e01ARKByte15->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::on_buttonS01E01SB_clicked()
{
    unsigned char plain_byte_temp;
    char* temp_string = new char [3];

    plain_byte_temp = hexValue(ui->outPlain1s01e01ARKByte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01ARKByte00->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain1s01e01SBByte00->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain1s01e01ARKByte05->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01ARKByte05->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain1s01e01SBByte05->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain1s01e01ARKByte10->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01ARKByte10->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain1s01e01SBByte10->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain1s01e01ARKByte15->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01ARKByte15->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain1s01e01SBByte15->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain2s01e01ARKByte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01ARKByte00->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain2s01e01SBByte00->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain2s01e01ARKByte05->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01ARKByte05->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain2s01e01SBByte05->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain2s01e01ARKByte10->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01ARKByte10->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain2s01e01SBByte10->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain2s01e01ARKByte15->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01ARKByte15->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain2s01e01SBByte15->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain3s01e01ARKByte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01ARKByte00->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain3s01e01SBByte00->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain3s01e01ARKByte05->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01ARKByte05->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain3s01e01SBByte05->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain3s01e01ARKByte10->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01ARKByte10->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain3s01e01SBByte10->setText(temp_string);

    plain_byte_temp = hexValue(ui->outPlain3s01e01ARKByte15->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01ARKByte15->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->outPlain3s01e01SBByte15->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::on_buttonS01E01SR_clicked()
{
    ui->outPlain1s01e01SRByte00->setText(ui->outPlain1s01e01SBByte00->text());
    ui->outPlain1s01e01SRByte01->setText(ui->outPlain1s01e01SBByte05->text());
    ui->outPlain1s01e01SRByte02->setText(ui->outPlain1s01e01SBByte10->text());
    ui->outPlain1s01e01SRByte03->setText(ui->outPlain1s01e01SBByte15->text());

    ui->outPlain2s01e01SRByte00->setText(ui->outPlain2s01e01SBByte00->text());
    ui->outPlain2s01e01SRByte01->setText(ui->outPlain2s01e01SBByte05->text());
    ui->outPlain2s01e01SRByte02->setText(ui->outPlain2s01e01SBByte10->text());
    ui->outPlain2s01e01SRByte03->setText(ui->outPlain2s01e01SBByte15->text());

    ui->outPlain3s01e01SRByte00->setText(ui->outPlain3s01e01SBByte00->text());
    ui->outPlain3s01e01SRByte01->setText(ui->outPlain3s01e01SBByte05->text());
    ui->outPlain3s01e01SRByte02->setText(ui->outPlain3s01e01SBByte10->text());
    ui->outPlain3s01e01SRByte03->setText(ui->outPlain3s01e01SBByte15->text());
}

void MainWindow::on_buttonS01E01MC_clicked()
{
    unsigned char temp_column[4];
    char* temp_string = new char [3];

    temp_column[0] = hexValue(ui->outPlain1s01e01SRByte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01SRByte00->text().at(1).toAscii());
    temp_column[1] = hexValue(ui->outPlain1s01e01SRByte01->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01SRByte01->text().at(1).toAscii());
    temp_column[2] = hexValue(ui->outPlain1s01e01SRByte02->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01SRByte02->text().at(1).toAscii());
    temp_column[3] = hexValue(ui->outPlain1s01e01SRByte03->text().at(0).toAscii())*16 + hexValue(ui->outPlain1s01e01SRByte03->text().at(1).toAscii());
    rijn.mixFirstColumn(temp_column);
    hexToUpperCaseText(temp_column[0], temp_string);
    ui->outPlain1s01e01MCByte00->setText(temp_string);
    hexToUpperCaseText(temp_column[1], temp_string);
    ui->outPlain1s01e01MCByte01->setText(temp_string);
    hexToUpperCaseText(temp_column[2], temp_string);
    ui->outPlain1s01e01MCByte02->setText(temp_string);
    hexToUpperCaseText(temp_column[3], temp_string);
    ui->outPlain1s01e01MCByte03->setText(temp_string);

    temp_column[0] = hexValue(ui->outPlain2s01e01SRByte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01SRByte00->text().at(1).toAscii());
    temp_column[1] = hexValue(ui->outPlain2s01e01SRByte01->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01SRByte01->text().at(1).toAscii());
    temp_column[2] = hexValue(ui->outPlain2s01e01SRByte02->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01SRByte02->text().at(1).toAscii());
    temp_column[3] = hexValue(ui->outPlain2s01e01SRByte03->text().at(0).toAscii())*16 + hexValue(ui->outPlain2s01e01SRByte03->text().at(1).toAscii());
    rijn.mixFirstColumn(temp_column);
    hexToUpperCaseText(temp_column[0], temp_string);
    ui->outPlain2s01e01MCByte00->setText(temp_string);
    hexToUpperCaseText(temp_column[1], temp_string);
    ui->outPlain2s01e01MCByte01->setText(temp_string);
    hexToUpperCaseText(temp_column[2], temp_string);
    ui->outPlain2s01e01MCByte02->setText(temp_string);
    hexToUpperCaseText(temp_column[3], temp_string);
    ui->outPlain2s01e01MCByte03->setText(temp_string);

    temp_column[0] = hexValue(ui->outPlain3s01e01SRByte00->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01SRByte00->text().at(1).toAscii());
    temp_column[1] = hexValue(ui->outPlain3s01e01SRByte01->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01SRByte01->text().at(1).toAscii());
    temp_column[2] = hexValue(ui->outPlain3s01e01SRByte02->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01SRByte02->text().at(1).toAscii());
    temp_column[3] = hexValue(ui->outPlain3s01e01SRByte03->text().at(0).toAscii())*16 + hexValue(ui->outPlain3s01e01SRByte03->text().at(1).toAscii());
    rijn.mixFirstColumn(temp_column);
    hexToUpperCaseText(temp_column[0], temp_string);
    ui->outPlain3s01e01MCByte00->setText(temp_string);
    hexToUpperCaseText(temp_column[1], temp_string);
    ui->outPlain3s01e01MCByte01->setText(temp_string);
    hexToUpperCaseText(temp_column[2], temp_string);
    ui->outPlain3s01e01MCByte02->setText(temp_string);
    hexToUpperCaseText(temp_column[3], temp_string);
    ui->outPlain3s01e01MCByte03->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::on_buttonS01E02InvMC_clicked()
{
    char* temp_string = new char [3];
    unsigned char* temp_block = new unsigned char[16];

    for (int i = 0; i < 16; i++){
        temp_block[i] = hexValue(s01e02cipher1[i]->text().at(0).toAscii())*16 + hexValue(s01e02cipher1[i]->text().at(1).toAscii());
    }
    rijn.invMixColumns(temp_block);
    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(temp_block[i], temp_string);
        s01e02Cipher1InvMC[i]->setText(temp_string);
    }

    for (int i = 0; i < 16; i++){
        temp_block[i] = hexValue(s01e02cipher2[i]->text().at(0).toAscii())*16 + hexValue(s01e02cipher2[i]->text().at(1).toAscii());
    }
    rijn.invMixColumns(temp_block);
    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(temp_block[i], temp_string);
        s01e02Cipher2InvMC[i]->setText(temp_string);
    }

    for (int i = 0; i < 16; i++){
        temp_block[i] = hexValue(s01e02cipher3[i]->text().at(0).toAscii())*16 + hexValue(s01e02cipher3[i]->text().at(1).toAscii());
    }
    rijn.invMixColumns(temp_block);
    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(temp_block[i], temp_string);
        s01e02Cipher3InvMC[i]->setText(temp_string);
    }

    delete[] temp_block;
    delete[] temp_string;

}

void MainWindow::on_buttonS01E02XOR_clicked()
{
    char* temp_string = new char [3];
    unsigned char* temp_block_1 = new unsigned char[16];
    unsigned char* temp_block_2 = new unsigned char[16];
    unsigned char* temp_block_3 = new unsigned char[16];
    unsigned char* temp_block_diff_12 = new unsigned char[16];
    unsigned char* temp_block_diff_13 = new unsigned char[16];

    for (int i = 0; i < 16; i++){
        temp_block_1[i] = hexValue(s01e02Cipher1InvMC[i]->text().at(0).toAscii())*16 + hexValue(s01e02Cipher1InvMC[i]->text().at(1).toAscii());
        temp_block_2[i] = hexValue(s01e02Cipher2InvMC[i]->text().at(0).toAscii())*16 + hexValue(s01e02Cipher2InvMC[i]->text().at(1).toAscii());
        temp_block_3[i] = hexValue(s01e02Cipher3InvMC[i]->text().at(0).toAscii())*16 + hexValue(s01e02Cipher3InvMC[i]->text().at(1).toAscii());
    }
    rijnAttacker.diff(temp_block_1, temp_block_2, temp_block_diff_12);
    rijnAttacker.diff(temp_block_1, temp_block_3, temp_block_diff_13);

    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(temp_block_diff_12[i], temp_string);
        s01e02InvCipherDiff12[i]->setText(temp_string);
        hexToUpperCaseText(temp_block_diff_13[i], temp_string);
        s01e02InvCipherDiff13[i]->setText(temp_string);
    }

    delete[] temp_block_1;
    delete[] temp_block_2;
    delete[] temp_block_3;
    delete[] temp_block_diff_12;
    delete[] temp_block_diff_13;
    delete[] temp_string;
}

void MainWindow::on_buttonS01E02InvSR_clicked()
{
    char* temp_string = new char [3];
    unsigned char* temp_block_1 = new unsigned char[16];
    unsigned char* temp_block_2 = new unsigned char[16];

    for (int i = 0; i < 16; i++){
        temp_block_1[i] = hexValue(s01e02InvCipherDiff12[i]->text().at(0).toAscii())*16 + hexValue(s01e02InvCipherDiff12[i]->text().at(1).toAscii());
        temp_block_2[i] = hexValue(s01e02InvCipherDiff13[i]->text().at(0).toAscii())*16 + hexValue(s01e02InvCipherDiff13[i]->text().at(1).toAscii());
    }

    rijn.invShiftRows(temp_block_1);
    rijn.invShiftRows(temp_block_2);

    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(temp_block_1[i], temp_string);
        s01e02InvCipherDiff12SR[i]->setText(temp_string);
        hexToUpperCaseText(temp_block_2[i], temp_string);
        s01e02InvCipherDiff13SR[i]->setText(temp_string);
    }

    delete[] temp_block_1;
    delete[] temp_block_2;
    delete[] temp_string;
}

void MainWindow::on_buttonSBoxLookup12_clicked()
{
    unsigned char temp_char_a, temp_char_b, res_x, res_y;
    char* temp_string = new char [3];
    temp_char_a = hexValue(ui->editByteAlpha12->text().at(0).toAscii())*16 + hexValue(ui->editByteAlpha12->text().at(1).toAscii());
    temp_char_b = hexValue(ui->editByteBeta12->text().at(0).toAscii())*16 + hexValue(ui->editByteBeta12->text().at(1).toAscii());
    res_x = rijnAttacker.xSboxDiff(temp_char_a, temp_char_b);
    res_y = rijnAttacker.ySboxDiff(temp_char_a, temp_char_b);
    hexToUpperCaseText(res_x, temp_string);
    ui->labelResultLookupX12->setText(temp_string);
    hexToUpperCaseText(res_y, temp_string);
    ui->labelResultLookupY12->setText(temp_string);
    delete[] temp_string;
}


void MainWindow::on_buttonSBoxLookup13_clicked()
{
    unsigned char temp_char_a, temp_char_b, res_x, res_y;
    char* temp_string = new char [3];
    temp_char_a = hexValue(ui->editByteAlpha13->text().at(0).toAscii())*16 + hexValue(ui->editByteAlpha13->text().at(1).toAscii());
    temp_char_b = hexValue(ui->editByteBeta13->text().at(0).toAscii())*16 + hexValue(ui->editByteBeta13->text().at(1).toAscii());
    res_x = rijnAttacker.xSboxDiff(temp_char_a, temp_char_b);
    res_y = rijnAttacker.ySboxDiff(temp_char_a, temp_char_b);
    hexToUpperCaseText(res_x, temp_string);
    ui->labelResultLookupX13->setText(temp_string);
    hexToUpperCaseText(res_y, temp_string);
    ui->labelResultLookupY13->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_editByteAlpha12_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByteAlpha12->setText(text.toUpper());
}

void MainWindow::on_editByteBeta12_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByteBeta12->setText(text.toUpper());
}

void MainWindow::on_editByteAlpha13_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByteAlpha13->setText(text.toUpper());
}

void MainWindow::on_editByteBeta13_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByteBeta13->setText(text.toUpper());
}

void MainWindow::on_editByte00ResultSbox_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte00ResultSbox->setText(text.toUpper());
    if (ui->editByte00ResultSbox->text().length() == 2){
        unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
        char* temp_string = new char [3];
        byte_temp_a = hexValue(ui->s01e03plain1AfterR1Col0Byte00_2->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain1AfterR1Col0Byte00_2->text().at(1).toAscii());
        byte_temp_b = hexValue(ui->editByte00ResultSbox->text().at(0).toAscii())*16 + hexValue(ui->editByte00ResultSbox->text().at(1).toAscii());
        byte_temp_c = byte_temp_a ^ byte_temp_b;
        hexToUpperCaseText(byte_temp_c, temp_string);
        ui->s01e03k1Byte00->setText(temp_string);
        subkeyk1[0]=ui->s01e03k1Byte00->text();
        delete[] temp_string;
    }
}

void MainWindow::on_editByte01ResultSbox_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte01ResultSbox->setText(text.toUpper());
    if (ui->editByte01ResultSbox->text().length() == 2){
        unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
        char* temp_string = new char [3];
        byte_temp_a = hexValue(ui->s01e03plain1AfterR1Col0Byte01_2->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain1AfterR1Col0Byte01_2->text().at(1).toAscii());
        byte_temp_b = hexValue(ui->editByte01ResultSbox->text().at(0).toAscii())*16 + hexValue(ui->editByte01ResultSbox->text().at(1).toAscii());
        byte_temp_c = byte_temp_a ^ byte_temp_b;
        hexToUpperCaseText(byte_temp_c, temp_string);
        ui->s01e03k1Byte01->setText(temp_string);
        subkeyk1[1]=ui->s01e03k1Byte01->text();
        delete[] temp_string;
    }
}

void MainWindow::on_editByte02ResultSbox_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte02ResultSbox->setText(text.toUpper());
    if (ui->editByte02ResultSbox->text().length() == 2){
        unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
        char* temp_string = new char [3];
        byte_temp_a = hexValue(ui->s01e03plain1AfterR1Col0Byte02_2->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain1AfterR1Col0Byte02_2->text().at(1).toAscii());
        byte_temp_b = hexValue(ui->editByte02ResultSbox->text().at(0).toAscii())*16 + hexValue(ui->editByte02ResultSbox->text().at(1).toAscii());
        byte_temp_c = byte_temp_a ^ byte_temp_b;
        hexToUpperCaseText(byte_temp_c, temp_string);
        ui->s01e03k1Byte02->setText(temp_string);
        subkeyk1[2]=ui->s01e03k1Byte02->text();
        delete[] temp_string;
    }
}

void MainWindow::on_editByte03ResultSbox_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte03ResultSbox->setText(text.toUpper());
    if (ui->editByte03ResultSbox->text().length() == 2){
        unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
        char* temp_string = new char [3];
        byte_temp_a = hexValue(ui->s01e03plain1AfterR1Col0Byte03_2->text().at(0).toAscii())*16 + hexValue(ui->s01e03plain1AfterR1Col0Byte03_2->text().at(1).toAscii());
        byte_temp_b = hexValue(ui->editByte03ResultSbox->text().at(0).toAscii())*16 + hexValue(ui->editByte03ResultSbox->text().at(1).toAscii());
        byte_temp_c = byte_temp_a ^ byte_temp_b;
        hexToUpperCaseText(byte_temp_c, temp_string);
        ui->s01e03k1Byte03->setText(temp_string);
        subkeyk1[3]=ui->s01e03k1Byte03->text();
        delete[] temp_string;
    }
}

void MainWindow::on_buttonS01E04ArkK1_clicked()
{
    unsigned char byte_temp_a, byte_temp_b, byte_temp_c, byte_temp_k1;
    char* temp_string = new char [3];

    byte_temp_a = hexValue(ui->s01e04plain1AfterR1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterR1Col0Byte00->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e04plain2AfterR1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain2AfterR1Col0Byte00->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s01e04plain3AfterR1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain3AfterR1Col0Byte00->text().at(1).toAscii());

    byte_temp_k1 = hexValue(ui->s01e03k1Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e03k1Byte00->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_k1;byte_temp_b ^= byte_temp_k1;byte_temp_c ^= byte_temp_k1;
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s01e04plain1AfterK1Col0Byte00->setText(temp_string);
    byte_temp_k1 = hexValue(ui->s01e03k1Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e03k1Byte01->text().at(1).toAscii());
    byte_temp_a = hexValue(ui->s01e04plain1AfterR1Col0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterR1Col0Byte01->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_k1;
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s01e04plain1AfterK1Col0Byte01->setText(temp_string);
    byte_temp_k1 = hexValue(ui->s01e03k1Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e03k1Byte02->text().at(1).toAscii());
    byte_temp_a = hexValue(ui->s01e04plain1AfterR1Col0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterR1Col0Byte02->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_k1;
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s01e04plain1AfterK1Col0Byte02->setText(temp_string);
    byte_temp_k1 = hexValue(ui->s01e03k1Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e03k1Byte03->text().at(1).toAscii());
    byte_temp_a = hexValue(ui->s01e04plain1AfterR1Col0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterR1Col0Byte03->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_k1;
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s01e04plain1AfterK1Col0Byte03->setText(temp_string);

    hexToUpperCaseText(byte_temp_b, temp_string);   ui->s01e04plain2AfterK1Col0Byte00->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);   ui->s01e04plain3AfterK1Col0Byte00->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonS01E04SB_clicked()
{
    unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
    char* temp_string = new char [3];

    byte_temp_a = hexValue(ui->s01e04plain1AfterK1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterK1Col0Byte00->text().at(1).toAscii());
    byte_temp_a = _sbox[byte_temp_a];
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s01e04plain1AfterSBR1Col0Byte00->setText(temp_string);

    byte_temp_a = hexValue(ui->s01e04plain1AfterK1Col0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterK1Col0Byte01->text().at(1).toAscii());
    byte_temp_a = _sbox[byte_temp_a];
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s01e04plain1AfterSBR1Col0Byte01->setText(temp_string);

    byte_temp_a = hexValue(ui->s01e04plain1AfterK1Col0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterK1Col0Byte02->text().at(1).toAscii());
    byte_temp_a = _sbox[byte_temp_a];
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s01e04plain1AfterSBR1Col0Byte02->setText(temp_string);

    byte_temp_a = hexValue(ui->s01e04plain1AfterK1Col0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterK1Col0Byte03->text().at(1).toAscii());
    byte_temp_a = _sbox[byte_temp_a];
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s01e04plain1AfterSBR1Col0Byte03->setText(temp_string);

    byte_temp_b = hexValue(ui->s01e04plain2AfterK1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain2AfterK1Col0Byte00->text().at(1).toAscii());
    byte_temp_c = hexValue(ui->s01e04plain3AfterK1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain3AfterK1Col0Byte00->text().at(1).toAscii());
    byte_temp_b = _sbox[byte_temp_b]; byte_temp_c = _sbox[byte_temp_c];
    hexToUpperCaseText(byte_temp_b, temp_string);   ui->s01e04plain2AfterSBR1Col0Byte00->setText(temp_string);
    hexToUpperCaseText(byte_temp_c, temp_string);   ui->s01e04plain3AfterSBR1Col0Byte00->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonS01E04SR_clicked()
{
    ui->s01e04plain1AfterSRR1Byte00->setText(ui->s01e04plain1AfterSBR1Col0Byte00->text());
    ui->s01e04plain1AfterSRR1Byte07->setText(ui->s01e04plain1AfterSBR1Col0Byte03->text());
    ui->s01e04plain1AfterSRR1Byte10->setText(ui->s01e04plain1AfterSBR1Col0Byte02->text());
    ui->s01e04plain1AfterSRR1Byte13->setText(ui->s01e04plain1AfterSBR1Col0Byte01->text());
}

void MainWindow::on_buttonS01E04FindU2Bytes_clicked()
{
    unsigned char byte_temp_a, byte_temp_b;
    char* temp_string = new char [3];

    byte_temp_a = hexValue(ui->s01e04plain1AfterSRR1Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterSRR1Byte00->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e04Cipher1InvMCByte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04Cipher1InvMCByte00->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_b;
    hexToUpperCaseText(byte_temp_a, temp_string);
    ui->s01e04u2Byte00->setText(temp_string);
    subkeyu2[0] =ui->s01e04u2Byte00->text();

    byte_temp_b = hexValue(ui->s01e04plain2AfterSBR1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain2AfterSBR1Col0Byte00->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s01e04plain2AfterU2Col0Byte00->setText(temp_string);
    byte_temp_b = hexValue(ui->s01e04plain3AfterSBR1Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain3AfterSBR1Col0Byte00->text().at(1).toAscii());
    byte_temp_b ^= byte_temp_a;
    hexToUpperCaseText(byte_temp_b, temp_string);
    ui->s01e04plain3AfterU2Col0Byte00->setText(temp_string);

    byte_temp_a = hexValue(ui->s01e04plain1AfterSRR1Byte07->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterSRR1Byte07->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e04Cipher1InvMCByte07->text().at(0).toAscii())*16 + hexValue(ui->s01e04Cipher1InvMCByte07->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_b;
    hexToUpperCaseText(byte_temp_a, temp_string);
    ui->s01e04u2Byte07->setText(temp_string);
    subkeyu2[7] =ui->s01e04u2Byte07->text();

    byte_temp_a = hexValue(ui->s01e04plain1AfterSRR1Byte10->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterSRR1Byte10->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e04Cipher1InvMCByte10->text().at(0).toAscii())*16 + hexValue(ui->s01e04Cipher1InvMCByte10->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_b;
    hexToUpperCaseText(byte_temp_a, temp_string);
    ui->s01e04u2Byte10->setText(temp_string);
    subkeyu2[10] =ui->s01e04u2Byte10->text();

    byte_temp_a = hexValue(ui->s01e04plain1AfterSRR1Byte13->text().at(0).toAscii())*16 + hexValue(ui->s01e04plain1AfterSRR1Byte13->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s01e04Cipher1InvMCByte13->text().at(0).toAscii())*16 + hexValue(ui->s01e04Cipher1InvMCByte13->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_b;
    hexToUpperCaseText(byte_temp_a, temp_string);
    ui->s01e04u2Byte13->setText(temp_string);
    subkeyu2[13] =ui->s01e04u2Byte13->text();

    delete[] temp_string;
}

void MainWindow::on_actionSubkeys_triggered()
{    
    dialogShowSubKeys->setSubKeysMatrix(subkeyk0, subkeyk1, subkeyk2, subkeyu2);
    dialogShowSubKeys->show();
}


void MainWindow::on_pushButtonEncryptOutput_clicked()
{
    char* temp_string = new char [3];
    unsigned char* k0test = new unsigned char[16];
    unsigned char* plain1temp = new unsigned char[16];
    for (int i = 0; i < 16; i++){
        k0test[i] = hexValue(outK0Array[i]->text().at(0).toAscii())*16 + hexValue(outK0Array[i]->text().at(1).toAscii());
        plain1temp[i] = hexValue(outPlain1Array[i]->text().at(0).toAscii())*16 + hexValue(outPlain1Array[i]->text().at(1).toAscii());
    }

    FastRijndael rijnTest = FastRijndael(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);
    rijnTest.makeKey(k0test);
    rijnTest.encryptTwoRounds(plain1temp);
    rijnTest.cleanUp();

    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(plain1temp[i], temp_string);
        outCipherK0Array[i]->setText(temp_string);
    }

    delete[] temp_string;
}

void MainWindow::on_editSugK0Byte00_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editSugK0Byte00->setText(text.toUpper());
    subkeyk0[0] = ui->editSugK0Byte00->text();
    on_actionReset_triggered();
}

void MainWindow::on_editSugK0Byte05_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editSugK0Byte05->setText(text.toUpper());
    subkeyk0[5] = ui->editSugK0Byte05->text();
    on_actionReset_triggered();
}

void MainWindow::on_editSugK0Byte07_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editSugK0Byte07->setText(text.toUpper());
    subkeyk0[7] = ui->editSugK0Byte07->text();
    on_actionReset_triggered();
}

void MainWindow::on_editSugK0Byte08_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editSugK0Byte08->setText(text.toUpper());
    subkeyk0[8] = ui->editSugK0Byte08->text();
    on_actionReset_triggered();
}

void MainWindow::on_editSugK0Byte10_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editSugK0Byte10->setText(text.toUpper());
    subkeyk0[10] = ui->editSugK0Byte10->text();
    on_actionReset_triggered();
}

void MainWindow::on_editSugK0Byte15_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editSugK0Byte15->setText(text.toUpper());
    subkeyk0[15] = ui->editSugK0Byte15->text();
    on_actionReset_triggered();
}

void MainWindow::on_buttonSBoxSolveLookupByte00_clicked()
{
    unsigned char temp_char_a12, temp_char_b12, res_x12, res_y12;
    unsigned char temp_char_a13, temp_char_b13, res_x13, res_y13;
    char* temp_string = new char [3];
    temp_char_a12 = hexValue(ui->s01e03plainAfterR1Diff12Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e03plainAfterR1Diff12Col0Byte00->text().at(1).toAscii());
    temp_char_b12 = hexValue(ui->s01e03InvCipherDiff12Column0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e03InvCipherDiff12Column0Byte00->text().at(1).toAscii());
    res_x12 = rijnAttacker.xSboxDiff(temp_char_a12, temp_char_b12);
    res_y12 = rijnAttacker.ySboxDiff(temp_char_a12, temp_char_b12);
    temp_char_a13 = hexValue(ui->s01e03plainAfterR1Diff13Col0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e03plainAfterR1Diff13Col0Byte00->text().at(1).toAscii());
    temp_char_b13 = hexValue(ui->s01e03InvCipherDiff13Column0Byte00->text().at(0).toAscii())*16 + hexValue(ui->s01e03InvCipherDiff13Column0Byte00->text().at(1).toAscii());
    res_x13 = rijnAttacker.xSboxDiff(temp_char_a13, temp_char_b13);
    res_y13 = rijnAttacker.ySboxDiff(temp_char_a13, temp_char_b13);

    if (res_x12 == res_x13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x12 == res_y13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x13 == res_y12){
        hexToUpperCaseText(res_x13, temp_string);
    }
    else if (res_y12 == res_y13){
        hexToUpperCaseText(res_y12, temp_string);
    }
    else{
        temp_string[0] = '?';
        temp_string[1] = '?';
    }
    ui->editByte00ResultSbox->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonSBoxSolveLookupByte01_clicked()
{
    unsigned char temp_char_a12, temp_char_b12, res_x12, res_y12;
    unsigned char temp_char_a13, temp_char_b13, res_x13, res_y13;
    char* temp_string = new char [3];
    temp_char_a12 = hexValue(ui->s01e03plainAfterR1Diff12Col0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e03plainAfterR1Diff12Col0Byte01->text().at(1).toAscii());
    temp_char_b12 = hexValue(ui->s01e03InvCipherDiff12Column0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e03InvCipherDiff12Column0Byte01->text().at(1).toAscii());
    res_x12 = rijnAttacker.xSboxDiff(temp_char_a12, temp_char_b12);
    res_y12 = rijnAttacker.ySboxDiff(temp_char_a12, temp_char_b12);
    temp_char_a13 = hexValue(ui->s01e03plainAfterR1Diff13Col0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e03plainAfterR1Diff13Col0Byte01->text().at(1).toAscii());
    temp_char_b13 = hexValue(ui->s01e03InvCipherDiff13Column0Byte01->text().at(0).toAscii())*16 + hexValue(ui->s01e03InvCipherDiff13Column0Byte01->text().at(1).toAscii());
    res_x13 = rijnAttacker.xSboxDiff(temp_char_a13, temp_char_b13);
    res_y13 = rijnAttacker.ySboxDiff(temp_char_a13, temp_char_b13);

    if (res_x12 == res_x13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x12 == res_y13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x13 == res_y12){
        hexToUpperCaseText(res_x13, temp_string);
    }
    else if (res_y12 == res_y13){
        hexToUpperCaseText(res_y12, temp_string);
    }
    else{
        temp_string[0] = '?';
        temp_string[1] = '?';
    }
    ui->editByte01ResultSbox->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonSBoxSolveLookupByte02_clicked()
{
    unsigned char temp_char_a12, temp_char_b12, res_x12, res_y12;
    unsigned char temp_char_a13, temp_char_b13, res_x13, res_y13;
    char* temp_string = new char [3];
    temp_char_a12 = hexValue(ui->s01e03plainAfterR1Diff12Col0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e03plainAfterR1Diff12Col0Byte02->text().at(1).toAscii());
    temp_char_b12 = hexValue(ui->s01e03InvCipherDiff12Column0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e03InvCipherDiff12Column0Byte02->text().at(1).toAscii());
    res_x12 = rijnAttacker.xSboxDiff(temp_char_a12, temp_char_b12);
    res_y12 = rijnAttacker.ySboxDiff(temp_char_a12, temp_char_b12);
    temp_char_a13 = hexValue(ui->s01e03plainAfterR1Diff13Col0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e03plainAfterR1Diff13Col0Byte02->text().at(1).toAscii());
    temp_char_b13 = hexValue(ui->s01e03InvCipherDiff13Column0Byte02->text().at(0).toAscii())*16 + hexValue(ui->s01e03InvCipherDiff13Column0Byte02->text().at(1).toAscii());
    res_x13 = rijnAttacker.xSboxDiff(temp_char_a13, temp_char_b13);
    res_y13 = rijnAttacker.ySboxDiff(temp_char_a13, temp_char_b13);

    if (res_x12 == res_x13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x12 == res_y13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x13 == res_y12){
        hexToUpperCaseText(res_x13, temp_string);
    }
    else if (res_y12 == res_y13){
        hexToUpperCaseText(res_y12, temp_string);
    }
    else{
        temp_string[0] = '?';
        temp_string[1] = '?';
    }
    ui->editByte02ResultSbox->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonSBoxSolveLookupByte03_clicked()
{
    unsigned char temp_char_a12, temp_char_b12, res_x12, res_y12;
    unsigned char temp_char_a13, temp_char_b13, res_x13, res_y13;
    char* temp_string = new char [3];
    temp_char_a12 = hexValue(ui->s01e03plainAfterR1Diff12Col0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e03plainAfterR1Diff12Col0Byte03->text().at(1).toAscii());
    temp_char_b12 = hexValue(ui->s01e03InvCipherDiff12Column0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e03InvCipherDiff12Column0Byte03->text().at(1).toAscii());
    res_x12 = rijnAttacker.xSboxDiff(temp_char_a12, temp_char_b12);
    res_y12 = rijnAttacker.ySboxDiff(temp_char_a12, temp_char_b12);
    temp_char_a13 = hexValue(ui->s01e03plainAfterR1Diff13Col0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e03plainAfterR1Diff13Col0Byte03->text().at(1).toAscii());
    temp_char_b13 = hexValue(ui->s01e03InvCipherDiff13Column0Byte03->text().at(0).toAscii())*16 + hexValue(ui->s01e03InvCipherDiff13Column0Byte03->text().at(1).toAscii());
    res_x13 = rijnAttacker.xSboxDiff(temp_char_a13, temp_char_b13);
    res_y13 = rijnAttacker.ySboxDiff(temp_char_a13, temp_char_b13);

    if (res_x12 == res_x13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x12 == res_y13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x13 == res_y12){
        hexToUpperCaseText(res_x13, temp_string);
    }
    else if (res_y12 == res_y13){
        hexToUpperCaseText(res_y12, temp_string);
    }
    else{
        temp_string[0] = '?';
        temp_string[1] = '?';
    }
    ui->editByte03ResultSbox->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonS02E01ARK_clicked()
{
    unsigned char plain_byte_temp;
    char* temp_string = new char [3];

    plain_byte_temp = hexValue(ui->plain1s02e01Byte02->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01Byte02->text().at(1).toAscii());
    plain_byte_temp ^= hexValue(subkeyk0[2].at(0).toAscii())*16 + hexValue(subkeyk0[2].at(1).toAscii());
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain1s02e01ARKByte02->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain1s02e01Byte07->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01Byte07->text().at(1).toAscii());
    plain_byte_temp ^= tryByte07;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain1s02e01ARKByte07->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain1s02e01Byte08->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01Byte08->text().at(1).toAscii());
    plain_byte_temp ^= tryByte08;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain1s02e01ARKByte08->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain1s02e01Byte13->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01Byte13->text().at(1).toAscii());
    plain_byte_temp ^= hexValue(subkeyk0[13].at(0).toAscii())*16 + hexValue(subkeyk0[13].at(1).toAscii());
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain1s02e01ARKByte13->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain2s02e01Byte02->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01Byte02->text().at(1).toAscii());
    plain_byte_temp ^= hexValue(subkeyk0[2].at(0).toAscii())*16 + hexValue(subkeyk0[2].at(1).toAscii());
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain2s02e01ARKByte02->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain2s02e01Byte07->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01Byte07->text().at(1).toAscii());
    plain_byte_temp ^= tryByte07;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain2s02e01ARKByte07->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain2s02e01Byte08->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01Byte08->text().at(1).toAscii());
    plain_byte_temp ^= tryByte08;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain2s02e01ARKByte08->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain2s02e01Byte13->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01Byte13->text().at(1).toAscii());
    plain_byte_temp ^= hexValue(subkeyk0[13].at(0).toAscii())*16 + hexValue(subkeyk0[13].at(1).toAscii());
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain2s02e01ARKByte13->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain3s02e01Byte02->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01Byte02->text().at(1).toAscii());
    plain_byte_temp ^= hexValue(subkeyk0[2].at(0).toAscii())*16 + hexValue(subkeyk0[2].at(1).toAscii());
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain3s02e01ARKByte02->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain3s02e01Byte07->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01Byte07->text().at(1).toAscii());
    plain_byte_temp ^= tryByte07;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain3s02e01ARKByte07->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain3s02e01Byte08->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01Byte08->text().at(1).toAscii());
    plain_byte_temp ^= tryByte08;
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain3s02e01ARKByte08->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain3s02e01Byte13->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01Byte13->text().at(1).toAscii());
    plain_byte_temp ^= hexValue(subkeyk0[13].at(0).toAscii())*16 + hexValue(subkeyk0[13].at(1).toAscii());
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain3s02e01ARKByte13->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::on_buttonS02E01SB_clicked()
{
    unsigned char plain_byte_temp;
    char* temp_string = new char [3];

    plain_byte_temp = hexValue(ui->plain1s02e01ARKByte02->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01ARKByte02->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain1s02e01SBByte02->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain1s02e01ARKByte07->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01ARKByte07->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain1s02e01SBByte07->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain1s02e01ARKByte08->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01ARKByte08->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain1s02e01SBByte08->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain1s02e01ARKByte13->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01ARKByte13->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain1s02e01SBByte13->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain2s02e01ARKByte02->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01ARKByte02->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain2s02e01SBByte02->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain2s02e01ARKByte07->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01ARKByte07->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain2s02e01SBByte07->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain2s02e01ARKByte08->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01ARKByte08->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain2s02e01SBByte08->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain2s02e01ARKByte13->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01ARKByte13->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain2s02e01SBByte13->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain3s02e01ARKByte02->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01ARKByte02->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain3s02e01SBByte02->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain3s02e01ARKByte07->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01ARKByte07->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain3s02e01SBByte07->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain3s02e01ARKByte08->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01ARKByte08->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain3s02e01SBByte08->setText(temp_string);

    plain_byte_temp = hexValue(ui->plain3s02e01ARKByte13->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01ARKByte13->text().at(1).toAscii());
    plain_byte_temp = _sbox[plain_byte_temp];
    hexToUpperCaseText(plain_byte_temp, temp_string);
    ui->plain3s02e01SBByte13->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::on_buttonS02E01SR_clicked()
{
    ui->plain1s02e01SRByte08->setText(ui->plain1s02e01SBByte08->text());
    ui->plain1s02e01SRByte09->setText(ui->plain1s02e01SBByte13->text());
    ui->plain1s02e01SRByte10->setText(ui->plain1s02e01SBByte02->text());
    ui->plain1s02e01SRByte11->setText(ui->plain1s02e01SBByte07->text());

    ui->plain2s02e01SRByte08->setText(ui->plain2s02e01SBByte08->text());
    ui->plain2s02e01SRByte09->setText(ui->plain2s02e01SBByte13->text());
    ui->plain2s02e01SRByte10->setText(ui->plain2s02e01SBByte02->text());
    ui->plain2s02e01SRByte11->setText(ui->plain2s02e01SBByte07->text());

    ui->plain3s02e01SRByte08->setText(ui->plain3s02e01SBByte08->text());
    ui->plain3s02e01SRByte09->setText(ui->plain3s02e01SBByte13->text());
    ui->plain3s02e01SRByte10->setText(ui->plain3s02e01SBByte02->text());
    ui->plain3s02e01SRByte11->setText(ui->plain3s02e01SBByte07->text());
}

void MainWindow::on_buttonS02E01MC_clicked()
{
    unsigned char temp_column[4];
    char* temp_string = new char [3];

    temp_column[0] = hexValue(ui->plain1s02e01SRByte08->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01SRByte08->text().at(1).toAscii());
    temp_column[1] = hexValue(ui->plain1s02e01SRByte09->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01SRByte09->text().at(1).toAscii());
    temp_column[2] = hexValue(ui->plain1s02e01SRByte10->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01SRByte10->text().at(1).toAscii());
    temp_column[3] = hexValue(ui->plain1s02e01SRByte11->text().at(0).toAscii())*16 + hexValue(ui->plain1s02e01SRByte11->text().at(1).toAscii());
    rijn.mixFirstColumn(temp_column);
    hexToUpperCaseText(temp_column[0], temp_string);
    ui->plain1s02e01MCByte08->setText(temp_string);
    hexToUpperCaseText(temp_column[1], temp_string);
    ui->plain1s02e01MCByte09->setText(temp_string);
    hexToUpperCaseText(temp_column[2], temp_string);
    ui->plain1s02e01MCByte10->setText(temp_string);
    hexToUpperCaseText(temp_column[3], temp_string);
    ui->plain1s02e01MCByte11->setText(temp_string);

    temp_column[0] = hexValue(ui->plain2s02e01SRByte08->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01SRByte08->text().at(1).toAscii());
    temp_column[1] = hexValue(ui->plain2s02e01SRByte09->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01SRByte09->text().at(1).toAscii());
    temp_column[2] = hexValue(ui->plain2s02e01SRByte10->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01SRByte10->text().at(1).toAscii());
    temp_column[3] = hexValue(ui->plain2s02e01SRByte11->text().at(0).toAscii())*16 + hexValue(ui->plain2s02e01SRByte11->text().at(1).toAscii());
    rijn.mixFirstColumn(temp_column);
    hexToUpperCaseText(temp_column[0], temp_string);
    ui->plain2s02e01MCByte08->setText(temp_string);
    hexToUpperCaseText(temp_column[1], temp_string);
    ui->plain2s02e01MCByte09->setText(temp_string);
    hexToUpperCaseText(temp_column[2], temp_string);
    ui->plain2s02e01MCByte10->setText(temp_string);
    hexToUpperCaseText(temp_column[3], temp_string);
    ui->plain2s02e01MCByte11->setText(temp_string);

    temp_column[0] = hexValue(ui->plain3s02e01SRByte08->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01SRByte08->text().at(1).toAscii());
    temp_column[1] = hexValue(ui->plain3s02e01SRByte09->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01SRByte09->text().at(1).toAscii());
    temp_column[2] = hexValue(ui->plain3s02e01SRByte10->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01SRByte10->text().at(1).toAscii());
    temp_column[3] = hexValue(ui->plain3s02e01SRByte11->text().at(0).toAscii())*16 + hexValue(ui->plain3s02e01SRByte11->text().at(1).toAscii());
    rijn.mixFirstColumn(temp_column);
    hexToUpperCaseText(temp_column[0], temp_string);
    ui->plain3s02e01MCByte08->setText(temp_string);
    hexToUpperCaseText(temp_column[1], temp_string);
    ui->plain3s02e01MCByte09->setText(temp_string);
    hexToUpperCaseText(temp_column[2], temp_string);
    ui->plain3s02e01MCByte10->setText(temp_string);
    hexToUpperCaseText(temp_column[3], temp_string);
    ui->plain3s02e01MCByte11->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::on_buttonS01E04FindMissingBytes_clicked()
{
    unsigned char temp_byte_a, temp_byte_b;
    char* temp_string = new char [3];

    temp_byte_a = hexValue(ui->k0byte15->text().at(0).toAscii())*16 + hexValue(ui->k0byte15->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte02->text().at(0).toAscii())*16 + hexValue(ui->k1byte02->text().at(1).toAscii());
    temp_byte_a = _sbox[temp_byte_a];
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte02->setText(temp_string);
    subkeyk0[2] = ui->k0byte02->text();

    temp_byte_a = hexValue(ui->k0byte00->text().at(0).toAscii())*16 + hexValue(ui->k0byte00->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte00->text().at(0).toAscii())*16 + hexValue(ui->k1byte00->text().at(1).toAscii());
    temp_byte_a ^= 0x01;
    temp_byte_a ^= temp_byte_b;
    temp_byte_a = _inv_sbox[temp_byte_a];
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte13->setText(temp_string);
    subkeyk0[13] = ui->k0byte13->text();

    temp_byte_a = hexValue(ui->k0byte05->text().at(0).toAscii())*16 + hexValue(ui->k0byte05->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte01->text().at(0).toAscii())*16 + hexValue(ui->k1byte01->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k1byte05->setText(temp_string);
    subkeyk1[5] = ui->k1byte05->text();

    delete[] temp_string;
}

void MainWindow::on_buttonSBoxLookup12_2_clicked()
{
    unsigned char temp_char_a, temp_char_b, res_x, res_y;
    char* temp_string = new char [3];
    temp_char_a = hexValue(ui->editByteAlpha12_2->text().at(0).toAscii())*16 + hexValue(ui->editByteAlpha12_2->text().at(1).toAscii());
    temp_char_b = hexValue(ui->editByteBeta12_2->text().at(0).toAscii())*16 + hexValue(ui->editByteBeta12_2->text().at(1).toAscii());
    res_x = rijnAttacker.xSboxDiff(temp_char_a, temp_char_b);
    res_y = rijnAttacker.ySboxDiff(temp_char_a, temp_char_b);
    hexToUpperCaseText(res_x, temp_string);
    ui->labelResultLookupX12_2->setText(temp_string);
    hexToUpperCaseText(res_y, temp_string);
    ui->labelResultLookupY12_2->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonSBoxLookup13_2_clicked()
{
    unsigned char temp_char_a, temp_char_b, res_x, res_y;
    char* temp_string = new char [3];
    temp_char_a = hexValue(ui->editByteAlpha13_2->text().at(0).toAscii())*16 + hexValue(ui->editByteAlpha13_2->text().at(1).toAscii());
    temp_char_b = hexValue(ui->editByteBeta13_2->text().at(0).toAscii())*16 + hexValue(ui->editByteBeta13_2->text().at(1).toAscii());
    res_x = rijnAttacker.xSboxDiff(temp_char_a, temp_char_b);
    res_y = rijnAttacker.ySboxDiff(temp_char_a, temp_char_b);
    hexToUpperCaseText(res_x, temp_string);
    ui->labelResultLookupX13_2->setText(temp_string);
    hexToUpperCaseText(res_y, temp_string);
    ui->labelResultLookupY13_2->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_editByteAlpha12_2_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByteAlpha12_2->setText(text.toUpper());
}

void MainWindow::on_editByteBeta12_2_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByteBeta12_2->setText(text.toUpper());
}

void MainWindow::on_editByteAlpha13_2_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByteAlpha13_2->setText(text.toUpper());
}

void MainWindow::on_editByteBeta13_2_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByteBeta13_2->setText(text.toUpper());
}

void MainWindow::on_editByte08ResultSbox_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte08ResultSbox->setText(text.toUpper());
    if (ui->editByte08ResultSbox->text().length() == 2){
        unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
        char* temp_string = new char [3];
        byte_temp_a = hexValue(ui->s02e02plain1AfterR1Col2Byte08_2->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain1AfterR1Col2Byte08_2->text().at(1).toAscii());
        byte_temp_b = hexValue(ui->editByte08ResultSbox->text().at(0).toAscii())*16 + hexValue(ui->editByte08ResultSbox->text().at(1).toAscii());
        byte_temp_c = byte_temp_a ^ byte_temp_b;
        hexToUpperCaseText(byte_temp_c, temp_string);
        ui->s02e02k1Byte08->setText(temp_string);
        subkeyk1[8]=ui->s02e02k1Byte08->text();
        delete[] temp_string;
    }
}

void MainWindow::on_editByte09ResultSbox_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte09ResultSbox->setText(text.toUpper());
    if (ui->editByte09ResultSbox->text().length() == 2){
        unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
        char* temp_string = new char [3];
        byte_temp_a = hexValue(ui->s02e02plain1AfterR1Col2Byte09_2->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain1AfterR1Col2Byte09_2->text().at(1).toAscii());
        byte_temp_b = hexValue(ui->editByte09ResultSbox->text().at(0).toAscii())*16 + hexValue(ui->editByte09ResultSbox->text().at(1).toAscii());
        byte_temp_c = byte_temp_a ^ byte_temp_b;
        hexToUpperCaseText(byte_temp_c, temp_string);
        ui->s02e02k1Byte09->setText(temp_string);
        subkeyk1[9]=ui->s02e02k1Byte09->text();
        delete[] temp_string;
    }
}

void MainWindow::on_editByte10ResultSbox_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte10ResultSbox->setText(text.toUpper());
    if (ui->editByte10ResultSbox->text().length() == 2){
        unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
        char* temp_string = new char [3];
        byte_temp_a = hexValue(ui->s02e02plain1AfterR1Col2Byte10_2->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain1AfterR1Col2Byte10_2->text().at(1).toAscii());
        byte_temp_b = hexValue(ui->editByte10ResultSbox->text().at(0).toAscii())*16 + hexValue(ui->editByte10ResultSbox->text().at(1).toAscii());
        byte_temp_c = byte_temp_a ^ byte_temp_b;
        hexToUpperCaseText(byte_temp_c, temp_string);
        ui->s02e02k1Byte10->setText(temp_string);
        subkeyk1[10]=ui->s02e02k1Byte10->text();
        delete[] temp_string;
    }
}

void MainWindow::on_editByte11ResultSbox_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    ui->editByte11ResultSbox->setText(text.toUpper());
    if (ui->editByte11ResultSbox->text().length() == 2){
        unsigned char byte_temp_a, byte_temp_b, byte_temp_c;
        char* temp_string = new char [3];
        byte_temp_a = hexValue(ui->s02e02plain1AfterR1Col2Byte11_2->text().at(0).toAscii())*16 + hexValue(ui->s02e02plain1AfterR1Col2Byte11_2->text().at(1).toAscii());
        byte_temp_b = hexValue(ui->editByte11ResultSbox->text().at(0).toAscii())*16 + hexValue(ui->editByte11ResultSbox->text().at(1).toAscii());
        byte_temp_c = byte_temp_a ^ byte_temp_b;
        hexToUpperCaseText(byte_temp_c, temp_string);
        ui->s02e02k1Byte11->setText(temp_string);
        subkeyk1[11]=ui->s02e02k1Byte11->text();
        delete[] temp_string;
    }
}

void MainWindow::on_buttonSBoxSolveLookupByte08_clicked()
{
    unsigned char temp_char_a12, temp_char_b12, res_x12, res_y12;
    unsigned char temp_char_a13, temp_char_b13, res_x13, res_y13;
    char* temp_string = new char [3];
    temp_char_a12 = hexValue(ui->s02e02plainAfterR1Diff12Col2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e02plainAfterR1Diff12Col2Byte08->text().at(1).toAscii());
    temp_char_b12 = hexValue(ui->s02e02InvCipherDiff12Column2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e02InvCipherDiff12Column2Byte08->text().at(1).toAscii());
    res_x12 = rijnAttacker.xSboxDiff(temp_char_a12, temp_char_b12);
    res_y12 = rijnAttacker.ySboxDiff(temp_char_a12, temp_char_b12);
    temp_char_a13 = hexValue(ui->s02e02plainAfterR1Diff13Col2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e02plainAfterR1Diff13Col2Byte08->text().at(1).toAscii());
    temp_char_b13 = hexValue(ui->s02e02InvCipherDiff13Column2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e02InvCipherDiff13Column2Byte08->text().at(1).toAscii());
    res_x13 = rijnAttacker.xSboxDiff(temp_char_a13, temp_char_b13);
    res_y13 = rijnAttacker.ySboxDiff(temp_char_a13, temp_char_b13);

    if (res_x12 == res_x13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x12 == res_y13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x13 == res_y12){
        hexToUpperCaseText(res_x13, temp_string);
    }
    else if (res_y12 == res_y13){
        hexToUpperCaseText(res_y12, temp_string);
    }
    else{
        temp_string[0] = '?';
        temp_string[1] = '?';
    }
    ui->editByte08ResultSbox->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonSBoxSolveLookupByte09_clicked()
{
    unsigned char temp_char_a12, temp_char_b12, res_x12, res_y12;
    unsigned char temp_char_a13, temp_char_b13, res_x13, res_y13;
    char* temp_string = new char [3];
    temp_char_a12 = hexValue(ui->s02e02plainAfterR1Diff12Col2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e02plainAfterR1Diff12Col2Byte09->text().at(1).toAscii());
    temp_char_b12 = hexValue(ui->s02e02InvCipherDiff12Column2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e02InvCipherDiff12Column2Byte09->text().at(1).toAscii());
    res_x12 = rijnAttacker.xSboxDiff(temp_char_a12, temp_char_b12);
    res_y12 = rijnAttacker.ySboxDiff(temp_char_a12, temp_char_b12);
    temp_char_a13 = hexValue(ui->s02e02plainAfterR1Diff13Col2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e02plainAfterR1Diff13Col2Byte09->text().at(1).toAscii());
    temp_char_b13 = hexValue(ui->s02e02InvCipherDiff13Column2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e02InvCipherDiff13Column2Byte09->text().at(1).toAscii());
    res_x13 = rijnAttacker.xSboxDiff(temp_char_a13, temp_char_b13);
    res_y13 = rijnAttacker.ySboxDiff(temp_char_a13, temp_char_b13);

    if (res_x12 == res_x13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x12 == res_y13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x13 == res_y12){
        hexToUpperCaseText(res_x13, temp_string);
    }
    else if (res_y12 == res_y13){
        hexToUpperCaseText(res_y12, temp_string);
    }
    else{
        temp_string[0] = '?';
        temp_string[1] = '?';
    }
    ui->editByte09ResultSbox->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonSBoxSolveLookupByte10_clicked()
{
    unsigned char temp_char_a12, temp_char_b12, res_x12, res_y12;
    unsigned char temp_char_a13, temp_char_b13, res_x13, res_y13;
    char* temp_string = new char [3];
    temp_char_a12 = hexValue(ui->s02e02plainAfterR1Diff12Col2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e02plainAfterR1Diff12Col2Byte10->text().at(1).toAscii());
    temp_char_b12 = hexValue(ui->s02e02InvCipherDiff12Column2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e02InvCipherDiff12Column2Byte10->text().at(1).toAscii());
    res_x12 = rijnAttacker.xSboxDiff(temp_char_a12, temp_char_b12);
    res_y12 = rijnAttacker.ySboxDiff(temp_char_a12, temp_char_b12);
    temp_char_a13 = hexValue(ui->s02e02plainAfterR1Diff13Col2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e02plainAfterR1Diff13Col2Byte10->text().at(1).toAscii());
    temp_char_b13 = hexValue(ui->s02e02InvCipherDiff13Column2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e02InvCipherDiff13Column2Byte10->text().at(1).toAscii());
    res_x13 = rijnAttacker.xSboxDiff(temp_char_a13, temp_char_b13);
    res_y13 = rijnAttacker.ySboxDiff(temp_char_a13, temp_char_b13);

    if (res_x12 == res_x13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x12 == res_y13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x13 == res_y12){
        hexToUpperCaseText(res_x13, temp_string);
    }
    else if (res_y12 == res_y13){
        hexToUpperCaseText(res_y12, temp_string);
    }
    else{
        temp_string[0] = '?';
        temp_string[1] = '?';
    }
    ui->editByte10ResultSbox->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonSBoxSolveLookupByte11_clicked()
{
    unsigned char temp_char_a12, temp_char_b12, res_x12, res_y12;
    unsigned char temp_char_a13, temp_char_b13, res_x13, res_y13;
    char* temp_string = new char [3];
    temp_char_a12 = hexValue(ui->s02e02plainAfterR1Diff12Col2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e02plainAfterR1Diff12Col2Byte11->text().at(1).toAscii());
    temp_char_b12 = hexValue(ui->s02e02InvCipherDiff12Column2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e02InvCipherDiff12Column2Byte11->text().at(1).toAscii());
    res_x12 = rijnAttacker.xSboxDiff(temp_char_a12, temp_char_b12);
    res_y12 = rijnAttacker.ySboxDiff(temp_char_a12, temp_char_b12);
    temp_char_a13 = hexValue(ui->s02e02plainAfterR1Diff13Col2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e02plainAfterR1Diff13Col2Byte11->text().at(1).toAscii());
    temp_char_b13 = hexValue(ui->s02e02InvCipherDiff13Column2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e02InvCipherDiff13Column2Byte11->text().at(1).toAscii());
    res_x13 = rijnAttacker.xSboxDiff(temp_char_a13, temp_char_b13);
    res_y13 = rijnAttacker.ySboxDiff(temp_char_a13, temp_char_b13);

    if (res_x12 == res_x13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x12 == res_y13){
        hexToUpperCaseText(res_x12, temp_string);
    }
    else if (res_x13 == res_y12){
        hexToUpperCaseText(res_x13, temp_string);
    }
    else if (res_y12 == res_y13){
        hexToUpperCaseText(res_y12, temp_string);
    }
    else{
        temp_string[0] = '?';
        temp_string[1] = '?';
    }
    ui->editByte11ResultSbox->setText(temp_string);
    delete[] temp_string;
}

void MainWindow::on_buttonS01E04ArkK1_2_clicked()
{
    unsigned char byte_temp_a, byte_temp_k1;
    char* temp_string = new char [3];

    byte_temp_a = hexValue(ui->s02e03plain1AfterR1Col2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterR1Col2Byte08->text().at(1).toAscii());
    byte_temp_k1 = hexValue(ui->s02e02k1Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e02k1Byte08->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_k1;
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s02e03plain1AfterK1Col2Byte08->setText(temp_string);

    byte_temp_k1 = hexValue(ui->s02e02k1Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e02k1Byte09->text().at(1).toAscii());
    byte_temp_a = hexValue(ui->s02e03plain1AfterR1Col2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterR1Col2Byte09->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_k1;
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s02e03plain1AfterK1Col2Byte09->setText(temp_string);

    byte_temp_k1 = hexValue(ui->s02e02k1Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e02k1Byte10->text().at(1).toAscii());
    byte_temp_a = hexValue(ui->s02e03plain1AfterR1Col2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterR1Col2Byte10->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_k1;
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s02e03plain1AfterK1Col2Byte10->setText(temp_string);

    byte_temp_k1 = hexValue(ui->s02e02k1Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e02k1Byte11->text().at(1).toAscii());
    byte_temp_a = hexValue(ui->s02e03plain1AfterR1Col2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterR1Col2Byte11->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_k1;
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s02e03plain1AfterK1Col2Byte11->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::on_buttonS01E04SB_2_clicked()
{
    unsigned char byte_temp_a;
    char* temp_string = new char [3];

    byte_temp_a = hexValue(ui->s02e03plain1AfterK1Col2Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterK1Col2Byte08->text().at(1).toAscii());
    byte_temp_a = _sbox[byte_temp_a];
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s02e03plain1AfterSBR1Col2Byte08->setText(temp_string);

    byte_temp_a = hexValue(ui->s02e03plain1AfterK1Col2Byte09->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterK1Col2Byte09->text().at(1).toAscii());
    byte_temp_a = _sbox[byte_temp_a];
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s02e03plain1AfterSBR1Col2Byte09->setText(temp_string);

    byte_temp_a = hexValue(ui->s02e03plain1AfterK1Col2Byte10->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterK1Col2Byte10->text().at(1).toAscii());
    byte_temp_a = _sbox[byte_temp_a];
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s02e03plain1AfterSBR1Col2Byte10->setText(temp_string);

    byte_temp_a = hexValue(ui->s02e03plain1AfterK1Col2Byte11->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterK1Col2Byte11->text().at(1).toAscii());
    byte_temp_a = _sbox[byte_temp_a];
    hexToUpperCaseText(byte_temp_a, temp_string);   ui->s02e03plain1AfterSBR1Col2Byte11->setText(temp_string);

     delete[] temp_string;
}

void MainWindow::on_buttonS01E04SR_2_clicked()
{
    ui->s02e03plain1AfterSRR1Byte08->setText(ui->s02e03plain1AfterSBR1Col2Byte08->text());
    ui->s02e03plain1AfterSRR1Byte05->setText(ui->s02e03plain1AfterSBR1Col2Byte09->text());
    ui->s02e03plain1AfterSRR1Byte02->setText(ui->s02e03plain1AfterSBR1Col2Byte10->text());
    ui->s02e03plain1AfterSRR1Byte15->setText(ui->s02e03plain1AfterSBR1Col2Byte11->text());
}

void MainWindow::on_buttonS02E03FindU2Bytes_clicked()
{
    unsigned char byte_temp_a, byte_temp_b;
    char* temp_string = new char [3];

    byte_temp_a = hexValue(ui->s02e03plain1AfterSRR1Byte02->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterSRR1Byte02->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s02e03Cipher1InvMCByte02->text().at(0).toAscii())*16 + hexValue(ui->s02e03Cipher1InvMCByte02->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_b;
    hexToUpperCaseText(byte_temp_a, temp_string);
    ui->s02e03u2Byte02->setText(temp_string);
    subkeyu2[2] =ui->s02e03u2Byte02->text();

    byte_temp_a = hexValue(ui->s02e03plain1AfterSRR1Byte05->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterSRR1Byte05->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s02e03Cipher1InvMCByte05->text().at(0).toAscii())*16 + hexValue(ui->s02e03Cipher1InvMCByte05->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_b;
    hexToUpperCaseText(byte_temp_a, temp_string);
    ui->s02e03u2Byte05->setText(temp_string);
    subkeyu2[5] =ui->s02e03u2Byte05->text();

    byte_temp_a = hexValue(ui->s02e03plain1AfterSRR1Byte08->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterSRR1Byte08->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s02e03Cipher1InvMCByte08->text().at(0).toAscii())*16 + hexValue(ui->s02e03Cipher1InvMCByte08->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_b;
    hexToUpperCaseText(byte_temp_a, temp_string);
    ui->s02e03u2Byte08->setText(temp_string);
    subkeyu2[8] =ui->s02e03u2Byte08->text();

    byte_temp_a = hexValue(ui->s02e03plain1AfterSRR1Byte15->text().at(0).toAscii())*16 + hexValue(ui->s02e03plain1AfterSRR1Byte15->text().at(1).toAscii());
    byte_temp_b = hexValue(ui->s02e03Cipher1InvMCByte15->text().at(0).toAscii())*16 + hexValue(ui->s02e03Cipher1InvMCByte15->text().at(1).toAscii());
    byte_temp_a ^= byte_temp_b;
    hexToUpperCaseText(byte_temp_a, temp_string);
    ui->s02e03u2Byte15->setText(temp_string);
    subkeyu2[15] =ui->s02e03u2Byte15->text();

    delete[] temp_string;
}

void MainWindow::on_buttonS02E03FindMissingBytes_clicked()
{
    /*
        k1[7] = k1[3] ^ k0[7];
       k1[15] = k0[15] ^ k1[11];
        k1[13] = k0[13] ^ k1[9];
        k1[4] = k1[8] ^ k0[8];
        k1[6] = k1[10] ^ k0[10];

        k2[0] = (_sbox[k1[13]] ^ 0x02) ^ k1[0];
        k2[2] = (_sbox[k1[15]]) ^ k1[2];*/

    unsigned char temp_byte_a, temp_byte_b;
    char* temp_string = new char [3];

    temp_byte_a = hexValue(ui->k0byte07_2->text().at(0).toAscii())*16 + hexValue(ui->k0byte07_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte03_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte03_2->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k1byte07_2->setText(temp_string);
    subkeyk1[7] = ui->k1byte07_2->text();

    temp_byte_a = hexValue(ui->k0byte15_2->text().at(0).toAscii())*16 + hexValue(ui->k0byte15_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte11_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte11_2->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k1byte15_2->setText(temp_string);
    subkeyk1[15] = ui->k1byte15_2->text();

    temp_byte_a = hexValue(ui->k0byte13_2->text().at(0).toAscii())*16 + hexValue(ui->k0byte13_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte09_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte09_2->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k1byte13_2->setText(temp_string);
    subkeyk1[13] = ui->k1byte13_2->text();

    temp_byte_a = hexValue(ui->k0byte08_2->text().at(0).toAscii())*16 + hexValue(ui->k0byte08_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte08_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte08_2->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k1byte04_2->setText(temp_string);
    subkeyk1[4] = ui->k1byte04_2->text();

    temp_byte_a = hexValue(ui->k0byte10_2->text().at(0).toAscii())*16 + hexValue(ui->k0byte10_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte10_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte10_2->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k1byte06_2->setText(temp_string);
    subkeyk1[6] = ui->k1byte06_2->text();

    temp_byte_a = hexValue(ui->k1byte13_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte13_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte00_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte00_2->text().at(1).toAscii());
    temp_byte_a = _sbox[temp_byte_a];
    temp_byte_a ^= 0x02;
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k2byte00->setText(temp_string);
    subkeyk2[0] = ui->k2byte00->text();

    temp_byte_a = hexValue(ui->k1byte15_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte15_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte02_2->text().at(0).toAscii())*16 + hexValue(ui->k1byte02_2->text().at(1).toAscii());
    temp_byte_a = _sbox[temp_byte_a];
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k2byte02->setText(temp_string);
    subkeyk2[2] = ui->k2byte02->text();

    delete[] temp_string;
}

void MainWindow::on_buttonS02E04SolveLinearSystem_clicked()
{
    unsigned char* k2temp = new unsigned char[4];
    unsigned char* u2temp = new unsigned char[4];
    char* temp_string = new char [3];

    k2temp[0] = hexValue(ui->s02e04k2byte00->text().at(0).toAscii())*16 + hexValue(ui->s02e04k2byte00->text().at(1).toAscii());
    k2temp[1] = 0x00;
    k2temp[2] = hexValue(ui->s02e04k2byte02->text().at(0).toAscii())*16 + hexValue(ui->s02e04k2byte02->text().at(1).toAscii());
    k2temp[3] = 0x00;
    u2temp[0] = hexValue(ui->s02e04u2Byte00->text().at(0).toAscii())*16 + hexValue(ui->s02e04u2Byte00->text().at(1).toAscii());
    u2temp[1] = 0x00;
    u2temp[2] = hexValue(ui->s02e04u2Byte02->text().at(0).toAscii())*16 + hexValue(ui->s02e04u2Byte02->text().at(1).toAscii());
    u2temp[3] = 0x00;

    rijnAttacker.solveMixColumnFor2RoundPhase2(k2temp, u2temp);

    hexToUpperCaseText(k2temp[1], temp_string);
    ui->s02e04k2byte01->setText(temp_string);
    ui->s02e04sysk2byte01->setText(temp_string);
    ui->k2byte01_2->setText(temp_string);
    hexToUpperCaseText(k2temp[3], temp_string);
    ui->s02e04k2byte03->setText(temp_string);
    ui->s02e04sysk2byte03->setText(temp_string);
    ui->k2byte03_2->setText(temp_string);

    hexToUpperCaseText(u2temp[1], temp_string);
    ui->s02e04u2Byte01->setText(temp_string);
    ui->s02e04sysu2byte01_0->setText(temp_string);
    ui->s02e04sysu2byte01_1->setText(temp_string);
    ui->s02e04sysu2byte01_2->setText(temp_string);
    ui->s02e04sysu2byte01_3->setText(temp_string);

    hexToUpperCaseText(u2temp[3], temp_string);
    ui->s02e04u2Byte03->setText(temp_string);
    ui->s02e04sysu2byte03_0->setText(temp_string);
    ui->s02e04sysu2byte03_1->setText(temp_string);
    ui->s02e04sysu2byte03_2->setText(temp_string);
    ui->s02e04sysu2byte03_3->setText(temp_string);

    delete[] temp_string;
}

void MainWindow::on_buttonS02E04FindMissingBytes_clicked()
{
    /*k1[12] = _inv_sbox[k2[3] ^ k1[3]];
    k1[14] = _inv_sbox[k2[1] ^ k1[1]];

    //now we have k1 fully complete, let's get k0

    k0[12] = k1[8] ^ k1[12];
    k0[14] = k1[10] ^ k1[14];
    k0[9] = k1[5] ^ k1[9];
    k0[11] = k1[7] ^ k1[11];
    k0[4] = k1[0] ^ k1[4];
    k0[6] = k1[2] ^ k1[6];

    k0[1] = _sbox[k0[14]] ^ k1[1];
    k0[3] = _sbox[k0[12]] ^ k1[3];*/


    unsigned char temp_byte_a, temp_byte_b;
    char* temp_string = new char [3];

    temp_byte_a = hexValue(ui->k2byte03_2->text().at(0).toAscii())*16 + hexValue(ui->k2byte03_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte03_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte03_3->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    temp_byte_a = _inv_sbox[temp_byte_a];
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k1byte12_3->setText(temp_string);
    subkeyk1[12] = ui->k1byte12_3->text();

    temp_byte_a = hexValue(ui->k2byte01_2->text().at(0).toAscii())*16 + hexValue(ui->k2byte01_2->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte01_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte01_3->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    temp_byte_a = _inv_sbox[temp_byte_a];
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k1byte14_3->setText(temp_string);
    subkeyk1[14] = ui->k1byte14_3->text();

    temp_byte_a = hexValue(ui->k1byte08_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte08_3->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte12_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte12_3->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte12_3->setText(temp_string);
    subkeyk0[12] = ui->k0byte12_3->text();

    temp_byte_a = hexValue(ui->k1byte10_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte10_3->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte14_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte14_3->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte14_3->setText(temp_string);
    subkeyk0[14] = ui->k0byte14_3->text();

    temp_byte_a = hexValue(ui->k1byte05_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte05_3->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte09_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte09_3->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte09_3->setText(temp_string);
    subkeyk0[9] = ui->k0byte09_3->text();

    temp_byte_a = hexValue(ui->k1byte07_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte07_3->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte11_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte11_3->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte11_3->setText(temp_string);
    subkeyk0[11] = ui->k0byte11_3->text();

    temp_byte_a = hexValue(ui->k1byte00_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte00_3->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte04_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte04_3->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte04_3->setText(temp_string);
    subkeyk0[4] = ui->k0byte04_3->text();

    temp_byte_a = hexValue(ui->k1byte02_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte02_3->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte06_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte06_3->text().at(1).toAscii());
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte06_3->setText(temp_string);
    subkeyk0[6] = ui->k0byte06_3->text();

    temp_byte_a = hexValue(ui->k0byte14_3->text().at(0).toAscii())*16 + hexValue(ui->k0byte14_3->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte01_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte01_3->text().at(1).toAscii());
    temp_byte_a = _sbox[temp_byte_a];
    temp_byte_a ^= temp_byte_b;    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte01_3->setText(temp_string);
    subkeyk0[1] = ui->k0byte01_3->text();

    temp_byte_a = hexValue(ui->k0byte12_3->text().at(0).toAscii())*16 + hexValue(ui->k0byte12_3->text().at(1).toAscii());
    temp_byte_b = hexValue(ui->k1byte03_3->text().at(0).toAscii())*16 + hexValue(ui->k1byte03_3->text().at(1).toAscii());
    temp_byte_a = _sbox[temp_byte_a];
    temp_byte_a ^= temp_byte_b;
    hexToUpperCaseText(temp_byte_a, temp_string);
    ui->k0byte03_3->setText(temp_string);
    subkeyk0[3] = ui->k0byte03_3->text();

    delete[] temp_string;
}

void MainWindow::on_actionReset_triggered()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabInput));
    for (int i = 0; i < 16; i++){
        subkeyk0[i] = "??";
        subkeyk1[i] = "??";
        subkeyk2[i] = "??";
        subkeyu2[i] = "??";
    }
    for (int i = 0; i < 16; i++){
        k0found[i] = 0x00;
    }
    keyFound = false;

    ui->outPlain1s01e01ARKByte00->setText("??");ui->outPlain1s01e01ARKByte05->setText("??");ui->outPlain1s01e01ARKByte10->setText("??");ui->outPlain1s01e01ARKByte15->setText("??");
    ui->outPlain2s01e01ARKByte00->setText("??");ui->outPlain2s01e01ARKByte05->setText("??");ui->outPlain2s01e01ARKByte10->setText("??");ui->outPlain2s01e01ARKByte15->setText("??");
    ui->outPlain3s01e01ARKByte00->setText("??");ui->outPlain3s01e01ARKByte05->setText("??");ui->outPlain3s01e01ARKByte10->setText("??");ui->outPlain3s01e01ARKByte15->setText("??");

    ui->outPlain1s01e01SBByte00->setText("??");ui->outPlain1s01e01SBByte05->setText("??");ui->outPlain1s01e01SBByte10->setText("??");ui->outPlain1s01e01SBByte15->setText("??");
    ui->outPlain2s01e01SBByte00->setText("??");ui->outPlain2s01e01SBByte05->setText("??");ui->outPlain2s01e01SBByte10->setText("??");ui->outPlain2s01e01SBByte15->setText("??");
    ui->outPlain3s01e01SBByte00->setText("??");ui->outPlain3s01e01SBByte05->setText("??");ui->outPlain3s01e01SBByte10->setText("??");ui->outPlain3s01e01SBByte15->setText("??");

    ui->outPlain1s01e01SRByte00->setText("??");ui->outPlain1s01e01SRByte01->setText("??");ui->outPlain1s01e01SRByte02->setText("??");ui->outPlain1s01e01SRByte03->setText("??");
    ui->outPlain2s01e01SRByte00->setText("??");ui->outPlain2s01e01SRByte01->setText("??");ui->outPlain2s01e01SRByte02->setText("??");ui->outPlain2s01e01SRByte03->setText("??");
    ui->outPlain3s01e01SRByte00->setText("??");ui->outPlain3s01e01SRByte01->setText("??");ui->outPlain3s01e01SRByte02->setText("??");ui->outPlain3s01e01SRByte03->setText("??");

    ui->outPlain1s01e01MCByte00->setText("??");ui->outPlain1s01e01MCByte01->setText("??");ui->outPlain1s01e01MCByte02->setText("??");ui->outPlain1s01e01MCByte03->setText("??");
    ui->outPlain2s01e01MCByte00->setText("??");ui->outPlain2s01e01MCByte01->setText("??");ui->outPlain2s01e01MCByte02->setText("??");ui->outPlain2s01e01MCByte03->setText("??");
    ui->outPlain3s01e01MCByte00->setText("??");ui->outPlain3s01e01MCByte01->setText("??");ui->outPlain3s01e01MCByte02->setText("??");ui->outPlain3s01e01MCByte03->setText("??");

    for (int i = 0; i < 16; i++){
        s01e02Cipher1InvMC[i]->setText("??");
        s01e02Cipher2InvMC[i]->setText("??");
        s01e02Cipher3InvMC[i]->setText("??");
        s01e02InvCipherDiff12[i]->setText("??");
        s01e02InvCipherDiff13[i]->setText("??");
        s01e02InvCipherDiff12SR[i]->setText("??");
        s01e02InvCipherDiff13SR[i]->setText("??");
        outK0Array[i]->setText("??");
        outCipherK0Array[i]->setText("??");
    }

    ui->s01e03k1Byte00->setText("??");ui->s01e03k1Byte01->setText("??");ui->s01e03k1Byte02->setText("??");ui->s01e03k1Byte03->setText("??");
    ui->editByteAlpha12->setText("??");ui->editByteAlpha13->setText("??");ui->editByteBeta12->setText("??");ui->editByteBeta13->setText("??");
    ui->labelResultLookupX12->setText("??");ui->labelResultLookupY12->setText("??");ui->labelResultLookupX13->setText("??");ui->labelResultLookupY13->setText("??");
    ui->editByte00ResultSbox->setText("??");ui->editByte01ResultSbox->setText("??");ui->editByte02ResultSbox->setText("??");ui->editByte03ResultSbox->setText("??");

    ui->s01e04plain1AfterK1Col0Byte00->setText("??");ui->s01e04plain1AfterK1Col0Byte01->setText("??");ui->s01e04plain1AfterK1Col0Byte02->setText("??");ui->s01e04plain1AfterK1Col0Byte03->setText("??");
    ui->s01e04plain1AfterSBR1Col0Byte00->setText("??");ui->s01e04plain1AfterSBR1Col0Byte01->setText("??");ui->s01e04plain1AfterSBR1Col0Byte02->setText("??");ui->s01e04plain1AfterSBR1Col0Byte03->setText("??");
    ui->s01e04plain1AfterSRR1Byte00->setText("??");ui->s01e04plain1AfterSRR1Byte07->setText("??");ui->s01e04plain1AfterSRR1Byte10->setText("??");ui->s01e04plain1AfterSRR1Byte13->setText("??");
    ui->s01e04u2Byte00->setText("??");ui->s01e04u2Byte07->setText("??");ui->s01e04u2Byte10->setText("??");ui->s01e04u2Byte13->setText("??");
    ui->s01e04plain2AfterK1Col0Byte00->setText("??");ui->s01e04plain2AfterSBR1Col0Byte00->setText("??");ui->s01e04plain2AfterU2Col0Byte00->setText("??");
    ui->s01e04plain3AfterK1Col0Byte00->setText("??");ui->s01e04plain3AfterSBR1Col0Byte00->setText("??");ui->s01e04plain3AfterU2Col0Byte00->setText("??");
    ui->k0byte00->setText("??");ui->k0byte02->setText("??");ui->k0byte05->setText("??");ui->k0byte10->setText("??");ui->k0byte13->setText("??");ui->k0byte15->setText("??");
    ui->k1byte00->setText("??");ui->k1byte01->setText("??");ui->k1byte02->setText("??");ui->k1byte03->setText("??");ui->k1byte05->setText("??");

    ui->plain1s02e01ARKByte00->setText("??");ui->plain1s02e01ARKByte02->setText("??");ui->plain1s02e01ARKByte05->setText("??");ui->plain1s02e01ARKByte07->setText("??");
    ui->plain1s02e01ARKByte08->setText("??");ui->plain1s02e01ARKByte10->setText("??");ui->plain1s02e01ARKByte13->setText("??");ui->plain1s02e01ARKByte15->setText("??");
    ui->plain2s02e01ARKByte00->setText("??");ui->plain2s02e01ARKByte02->setText("??");ui->plain2s02e01ARKByte05->setText("??");ui->plain2s02e01ARKByte07->setText("??");
    ui->plain2s02e01ARKByte08->setText("??");ui->plain2s02e01ARKByte10->setText("??");ui->plain2s02e01ARKByte13->setText("??");ui->plain2s02e01ARKByte15->setText("??");
    ui->plain3s02e01ARKByte00->setText("??");ui->plain3s02e01ARKByte02->setText("??");ui->plain3s02e01ARKByte05->setText("??");ui->plain3s02e01ARKByte07->setText("??");
    ui->plain3s02e01ARKByte08->setText("??");ui->plain3s02e01ARKByte10->setText("??");ui->plain3s02e01ARKByte13->setText("??");ui->plain3s02e01ARKByte15->setText("??");

    ui->plain1s02e01SBByte00->setText("??");ui->plain1s02e01SBByte02->setText("??");ui->plain1s02e01SBByte05->setText("??");ui->plain1s02e01SBByte07->setText("??");
    ui->plain1s02e01SBByte08->setText("??");ui->plain1s02e01SBByte10->setText("??");ui->plain1s02e01SBByte13->setText("??");ui->plain1s02e01SBByte15->setText("??");
    ui->plain2s02e01SBByte00->setText("??");ui->plain2s02e01SBByte02->setText("??");ui->plain2s02e01SBByte05->setText("??");ui->plain2s02e01SBByte07->setText("??");
    ui->plain2s02e01SBByte08->setText("??");ui->plain2s02e01SBByte10->setText("??");ui->plain2s02e01SBByte13->setText("??");ui->plain2s02e01SBByte15->setText("??");
    ui->plain3s02e01SBByte00->setText("??");ui->plain3s02e01SBByte02->setText("??");ui->plain3s02e01SBByte05->setText("??");ui->plain3s02e01SBByte07->setText("??");
    ui->plain3s02e01SBByte08->setText("??");ui->plain3s02e01SBByte10->setText("??");ui->plain3s02e01SBByte13->setText("??");ui->plain3s02e01SBByte15->setText("??");

    ui->plain1s02e01SRByte00->setText("??");ui->plain1s02e01SRByte01->setText("??");ui->plain1s02e01SRByte02->setText("??");ui->plain1s02e01SRByte03->setText("??");
    ui->plain1s02e01SRByte08->setText("??");ui->plain1s02e01SRByte09->setText("??");ui->plain1s02e01SRByte10->setText("??");ui->plain1s02e01SRByte11->setText("??");
    ui->plain2s02e01SRByte00->setText("??");ui->plain2s02e01SRByte01->setText("??");ui->plain2s02e01SRByte02->setText("??");ui->plain2s02e01SRByte03->setText("??");
    ui->plain2s02e01SRByte08->setText("??");ui->plain2s02e01SRByte09->setText("??");ui->plain2s02e01SRByte10->setText("??");ui->plain2s02e01SRByte11->setText("??");
    ui->plain3s02e01SRByte00->setText("??");ui->plain3s02e01SRByte01->setText("??");ui->plain3s02e01SRByte02->setText("??");ui->plain3s02e01SRByte03->setText("??");
    ui->plain3s02e01SRByte08->setText("??");ui->plain3s02e01SRByte09->setText("??");ui->plain3s02e01SRByte10->setText("??");ui->plain3s02e01SRByte11->setText("??");

    ui->plain1s02e01MCByte00->setText("??");ui->plain1s02e01MCByte01->setText("??");ui->plain1s02e01MCByte02->setText("??");ui->plain1s02e01MCByte03->setText("??");
    ui->plain1s02e01MCByte08->setText("??");ui->plain1s02e01MCByte09->setText("??");ui->plain1s02e01MCByte10->setText("??");ui->plain1s02e01MCByte11->setText("??");
    ui->plain2s02e01MCByte00->setText("??");ui->plain2s02e01MCByte01->setText("??");ui->plain2s02e01MCByte02->setText("??");ui->plain2s02e01MCByte03->setText("??");
    ui->plain2s02e01MCByte08->setText("??");ui->plain2s02e01MCByte09->setText("??");ui->plain2s02e01MCByte10->setText("??");ui->plain2s02e01MCByte11->setText("??");
    ui->plain3s02e01MCByte00->setText("??");ui->plain3s02e01MCByte01->setText("??");ui->plain3s02e01MCByte02->setText("??");ui->plain3s02e01MCByte03->setText("??");
    ui->plain3s02e01MCByte08->setText("??");ui->plain3s02e01MCByte09->setText("??");ui->plain3s02e01MCByte10->setText("??");ui->plain3s02e01MCByte11->setText("??");

    ui->s02e02k1Byte08->setText("??");ui->s02e02k1Byte09->setText("??");ui->s02e02k1Byte10->setText("??");ui->s02e02k1Byte11->setText("??");
    ui->editByteAlpha12_2->setText("??");ui->editByteAlpha13_2->setText("??");ui->editByteBeta12_2->setText("??");ui->editByteBeta13_2->setText("??");
    ui->labelResultLookupX12_2->setText("??");ui->labelResultLookupY12_2->setText("??");ui->labelResultLookupX13_2->setText("??");ui->labelResultLookupY13_2->setText("??");
    ui->editByte08ResultSbox->setText("??");ui->editByte09ResultSbox->setText("??");ui->editByte10ResultSbox->setText("??");ui->editByte11ResultSbox->setText("??");

    ui->s02e03plain1AfterK1Col2Byte08->setText("??");ui->s02e03plain1AfterK1Col2Byte09->setText("??");ui->s02e03plain1AfterK1Col2Byte10->setText("??");ui->s02e03plain1AfterK1Col2Byte11->setText("??");
    ui->s02e03plain1AfterSBR1Col2Byte08->setText("??");ui->s02e03plain1AfterSBR1Col2Byte09->setText("??");ui->s02e03plain1AfterSBR1Col2Byte10->setText("??");ui->s02e03plain1AfterSBR1Col2Byte11->setText("??");
    ui->s02e03plain1AfterSRR1Byte00->setText("??");ui->s02e03plain1AfterSRR1Byte07->setText("??");ui->s02e03plain1AfterSRR1Byte10->setText("??");ui->s02e03plain1AfterSRR1Byte13->setText("??");
    ui->s02e03plain1AfterSRR1Byte02->setText("??");ui->s02e03plain1AfterSRR1Byte05->setText("??");ui->s02e03plain1AfterSRR1Byte08->setText("??");ui->s02e03plain1AfterSRR1Byte15->setText("??");
    ui->s02e03u2Byte00->setText("??");ui->s02e03u2Byte07->setText("??");ui->s02e03u2Byte10->setText("??");ui->s02e03u2Byte13->setText("??");
    ui->s02e03u2Byte02->setText("??");ui->s02e03u2Byte05->setText("??");ui->s02e03u2Byte08->setText("??");ui->s02e03u2Byte15->setText("??");
    ui->k0byte00_2->setText("??");ui->k0byte02_2->setText("??");ui->k0byte05_2->setText("??");ui->k0byte10_2->setText("??");
    ui->k0byte13_2->setText("??");ui->k0byte15_2->setText("??");ui->k0byte07_2->setText("??");ui->k0byte08_2->setText("??");
    ui->k1byte00_2->setText("??");ui->k1byte01_2->setText("??");ui->k1byte02_2->setText("??");ui->k1byte03_2->setText("??");ui->k1byte04_2->setText("??");
    ui->k1byte05_2->setText("??");ui->k1byte06_2->setText("??");ui->k1byte07_2->setText("??");ui->k1byte08_2->setText("??");ui->k1byte09_2->setText("??");
    ui->k1byte10_2->setText("??");ui->k1byte11_2->setText("??");ui->k1byte13_2->setText("??");ui->k1byte15_2->setText("??");
    ui->k2byte00->setText("??");ui->k2byte02->setText("??");

    ui->s02e04u2Byte00->setText("??");ui->s02e04u2Byte01->setText("??");ui->s02e04u2Byte02->setText("??");ui->s02e04u2Byte03->setText("??");
    ui->s02e04k2byte00->setText("??");ui->s02e04k2byte01->setText("??");ui->s02e04k2byte02->setText("??");ui->s02e04k2byte03->setText("??");
    ui->s02e04sysk2byte00->setText("??");ui->s02e04sysk2byte01->setText("??");ui->s02e04sysk2byte02->setText("??");ui->s02e04sysk2byte03->setText("??");
    ui->s02e04sysu2byte00_0->setText("??");ui->s02e04sysu2byte01_0->setText("??");ui->s02e04sysu2byte02_0->setText("??");ui->s02e04sysu2byte03_0->setText("??");
    ui->s02e04sysu2byte00_1->setText("??");ui->s02e04sysu2byte01_1->setText("??");ui->s02e04sysu2byte02_1->setText("??");ui->s02e04sysu2byte03_1->setText("??");
    ui->s02e04sysu2byte00_2->setText("??");ui->s02e04sysu2byte01_2->setText("??");ui->s02e04sysu2byte02_2->setText("??");ui->s02e04sysu2byte03_2->setText("??");
    ui->s02e04sysu2byte00_3->setText("??");ui->s02e04sysu2byte01_3->setText("??");ui->s02e04sysu2byte02_3->setText("??");ui->s02e04sysu2byte03_3->setText("??");
    ui->k0byte00_3->setText("??");ui->k0byte01_3->setText("??");ui->k0byte02_3->setText("??");ui->k0byte03_3->setText("??");
    ui->k0byte04_3->setText("??");ui->k0byte05_3->setText("??");ui->k0byte06_3->setText("??");ui->k0byte07_3->setText("??");
    ui->k0byte08_3->setText("??");ui->k0byte09_3->setText("??");ui->k0byte10_3->setText("??");ui->k0byte11_3->setText("??");
    ui->k0byte12_3->setText("??");ui->k0byte13_3->setText("??");ui->k0byte14_3->setText("??");ui->k0byte15_3->setText("??");
    ui->k1byte00_3->setText("??");ui->k1byte01_3->setText("??");ui->k1byte02_3->setText("??");ui->k1byte03_3->setText("??");
    ui->k1byte04_3->setText("??");ui->k1byte05_3->setText("??");ui->k1byte06_3->setText("??");ui->k1byte07_3->setText("??");
    ui->k1byte08_3->setText("??");ui->k1byte09_3->setText("??");ui->k1byte10_3->setText("??");ui->k1byte11_3->setText("??");
    ui->k1byte12_3->setText("??");ui->k1byte13_3->setText("??");ui->k1byte14_3->setText("??");ui->k1byte15_3->setText("??");
    ui->k2byte00_2->setText("??");ui->k2byte01_2->setText("??");ui->k2byte02_2->setText("??");ui->k2byte03_2->setText("??");
}

void MainWindow::on_actionAbout_triggered()
{
    DialogAbout* dialogAbout = new DialogAbout(this);
    dialogAbout->show();
}

void MainWindow::on_actionExample_2_triggered()
{
    ui->editPlaintext1->setText("0982761b8761c5af6714e92d76e19c92");
    ui->editPlaintext2->setText("cbe9a872b27db198a72b817b9c76119d");
    ui->editPlaintext3->setText("aa789a9276761bc8d8c9814500318301");
    ui->editCiphertext1->setText("d3b51335e39e6ff5e7dc4c92cc997c58");
    ui->editCiphertext2->setText("1a9041431d00059f0f8efc47c0a802e1");
    ui->editCiphertext3->setText("9b1f6286d040a1df4ea34a9f106f764e");
    ui->editByte00From->setText("00");ui->editByte00To->setText("FF");
    ui->editByte05From->setText("00");ui->editByte05To->setText("FF");
    ui->editByte07From->setText("00");ui->editByte07To->setText("FF");
    ui->editByte08From->setText("00");ui->editByte08To->setText("FF");
    ui->editByte10From->setText("00");ui->editByte10To->setText("FF");
    ui->editByte15From->setText("00");ui->editByte15To->setText("FF");
    ui->editSugK0Byte00->setText("00");
    ui->editSugK0Byte05->setText("0A");
    ui->editSugK0Byte07->setText("61");
    ui->editSugK0Byte08->setText("82");
    ui->editSugK0Byte10->setText("19");
    ui->editSugK0Byte15->setText("90");
}

void MainWindow::on_actionExample_3_triggered()
{
    ui->editPlaintext1->setText("66726f6d3a20616c6963654061636d65");
    ui->editPlaintext2->setText("746f3a20626f624061636d65636f7270");
    ui->editPlaintext3->setText("486176652075207365656e204576653f");
    ui->editCiphertext1->setText("cf0beb9741f5f07a34b9d6701c88588a");
    ui->editCiphertext2->setText("90d41a8e441eb55d4bb86cd64a5570e2");
    ui->editCiphertext3->setText("af2cd8abea7e4520f5ff45a9820dbf1f");
    ui->editByte00From->setText("61");ui->editByte00To->setText("7A");
    ui->editByte05From->setText("61");ui->editByte05To->setText("7A");
    ui->editByte07From->setText("61");ui->editByte07To->setText("7A");
    ui->editByte08From->setText("61");ui->editByte08To->setText("7A");
    ui->editByte10From->setText("61");ui->editByte10To->setText("7A");
    ui->editByte15From->setText("61");ui->editByte15To->setText("7A");
    ui->editSugK0Byte00->setText("65");
    ui->editSugK0Byte05->setText("65");
    ui->editSugK0Byte07->setText("68");
    ui->editSugK0Byte08->setText("61");
    ui->editSugK0Byte10->setText("68");
    ui->editSugK0Byte15->setText("61");
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 0){
        subkeyk0[0]=ui->editSugK0Byte00->text();
        subkeyk0[5]=ui->editSugK0Byte05->text();
        subkeyk0[10]=ui->editSugK0Byte10->text();
        subkeyk0[15]=ui->editSugK0Byte15->text();
        subkeyk0[7]=ui->editSugK0Byte07->text();
        subkeyk0[8]=ui->editSugK0Byte08->text();
    }
    else if (index == 9){
        for (int i = 0; i < 16; i++){
            outK0Array[i]->setText(subkeyk0[i]);
        }
        if (ui->editPlaintext1->text().length() == 32){
            setOutPlain1(ui->editPlaintext1->text());
        }
        if (ui->editCiphertext1->text().length() == 32){
            setOutCipher1(ui->editCiphertext1->text());
        }
        if (keyFound){
            setOutK0(k0found);
           // setOutCipherK0(ui->editCiphertext1->text());
        }
    }
    else if (index == 1){
        setPlainS01E01(ui->editPlaintext1->text(), ui->editPlaintext2->text(), ui->editPlaintext3->text());
        tryByte00 = hexValue(ui->editSugK0Byte00->text().at(0).toAscii())*16 + hexValue(ui->editSugK0Byte00->text().at(1).toAscii());
        tryByte05 = hexValue(ui->editSugK0Byte05->text().at(0).toAscii())*16 + hexValue(ui->editSugK0Byte05->text().at(1).toAscii());
        tryByte07 = hexValue(ui->editSugK0Byte07->text().at(0).toAscii())*16 + hexValue(ui->editSugK0Byte07->text().at(1).toAscii());
        tryByte08 = hexValue(ui->editSugK0Byte08->text().at(0).toAscii())*16 + hexValue(ui->editSugK0Byte08->text().at(1).toAscii());
        tryByte10 = hexValue(ui->editSugK0Byte10->text().at(0).toAscii())*16 + hexValue(ui->editSugK0Byte10->text().at(1).toAscii());
        tryByte15 = hexValue(ui->editSugK0Byte15->text().at(0).toAscii())*16 + hexValue(ui->editSugK0Byte15->text().at(1).toAscii());

        subkeyk0[0]=ui->editSugK0Byte00->text();
        subkeyk0[5]=ui->editSugK0Byte05->text();
        subkeyk0[10]=ui->editSugK0Byte10->text();
        subkeyk0[15]=ui->editSugK0Byte15->text();
        subkeyk0[7]=ui->editSugK0Byte07->text();
        subkeyk0[8]=ui->editSugK0Byte08->text();
    }
    else if (index == 2){
        setCipherS01E02(ui->editCiphertext1->text(), ui->editCiphertext2->text(), ui->editCiphertext3->text());
    }
    else if (index == 3){
        setColumnsS01E03();
    }
    else if (index == 4){
        setColumnAndBlockS01E04();
    }
    else if (index == 5){
        setPlainS02E01();
    }
    else if (index == 6){
        setColumnsS02E02();
    }
    else if (index == 7){
        setColumnAndBlockS02E03();
    }
    else if (index == 8){
        setColumnsS02E04();
    }
    else{
    }
}
