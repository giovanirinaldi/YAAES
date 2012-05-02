#include "dialogshowexpkey.h"
#include "ui_dialogshowexpkey.h"

#include <cstdio>

DialogShowExpKey::DialogShowExpKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowExpKey)
{
    ui->setupUi(this);
    k0ByteArray = new QLabel*[16];
    k0ByteArray[0]=ui->k0byte00;k0ByteArray[1]=ui->k0byte01;k0ByteArray[2]=ui->k0byte02;k0ByteArray[3]=ui->k0byte03;k0ByteArray[4]=ui->k0byte04;k0ByteArray[5]=ui->k0byte05;k0ByteArray[6]=ui->k0byte06;k0ByteArray[7]=ui->k0byte07;
    k0ByteArray[8]=ui->k0byte08;k0ByteArray[9]=ui->k0byte09;k0ByteArray[10]=ui->k0byte10;k0ByteArray[11]=ui->k0byte11;k0ByteArray[12]=ui->k0byte12;k0ByteArray[13]=ui->k0byte13;k0ByteArray[14]=ui->k0byte14;k0ByteArray[15]=ui->k0byte15;
    k1ByteArray = new QLabel*[16];
    k1ByteArray[0]=ui->k1byte00;k1ByteArray[1]=ui->k1byte01;k1ByteArray[2]=ui->k1byte02;k1ByteArray[3]=ui->k1byte03;k1ByteArray[4]=ui->k1byte04;k1ByteArray[5]=ui->k1byte05;k1ByteArray[6]=ui->k1byte06;k1ByteArray[7]=ui->k1byte07;
    k1ByteArray[8]=ui->k1byte08;k1ByteArray[9]=ui->k1byte09;k1ByteArray[10]=ui->k1byte10;k1ByteArray[11]=ui->k1byte11;k1ByteArray[12]=ui->k1byte12;k1ByteArray[13]=ui->k1byte13;k1ByteArray[14]=ui->k1byte14;k1ByteArray[15]=ui->k1byte15;
    k2ByteArray = new QLabel*[16];
    k2ByteArray[0]=ui->k2byte00;k2ByteArray[1]=ui->k2byte01;k2ByteArray[2]=ui->k2byte02;k2ByteArray[3]=ui->k2byte03;k2ByteArray[4]=ui->k2byte04;k2ByteArray[5]=ui->k2byte05;k2ByteArray[6]=ui->k2byte06;k2ByteArray[7]=ui->k2byte07;
    k2ByteArray[8]=ui->k2byte08;k2ByteArray[9]=ui->k2byte09;k2ByteArray[10]=ui->k2byte10;k2ByteArray[11]=ui->k2byte11;k2ByteArray[12]=ui->k2byte12;k2ByteArray[13]=ui->k2byte13;k2ByteArray[14]=ui->k2byte14;k2ByteArray[15]=ui->k2byte15;
    k3ByteArray = new QLabel*[16];
    k3ByteArray[0]=ui->k3byte00;k3ByteArray[1]=ui->k3byte01;k3ByteArray[2]=ui->k3byte02;k3ByteArray[3]=ui->k3byte03;k3ByteArray[4]=ui->k3byte04;k3ByteArray[5]=ui->k3byte05;k3ByteArray[6]=ui->k3byte06;k3ByteArray[7]=ui->k3byte07;
    k3ByteArray[8]=ui->k3byte08;k3ByteArray[9]=ui->k3byte09;k3ByteArray[10]=ui->k3byte10;k3ByteArray[11]=ui->k3byte11;k3ByteArray[12]=ui->k3byte12;k3ByteArray[13]=ui->k3byte13;k3ByteArray[14]=ui->k3byte14;k3ByteArray[15]=ui->k3byte15;
    k4ByteArray = new QLabel*[16];
    k4ByteArray[0]=ui->k4byte00;k4ByteArray[1]=ui->k4byte01;k4ByteArray[2]=ui->k4byte02;k4ByteArray[3]=ui->k4byte03;k4ByteArray[4]=ui->k4byte04;k4ByteArray[5]=ui->k4byte05;k4ByteArray[6]=ui->k4byte06;k4ByteArray[7]=ui->k4byte07;
    k4ByteArray[8]=ui->k4byte08;k4ByteArray[9]=ui->k4byte09;k4ByteArray[10]=ui->k4byte10;k4ByteArray[11]=ui->k4byte11;k4ByteArray[12]=ui->k4byte12;k4ByteArray[13]=ui->k4byte13;k4ByteArray[14]=ui->k4byte14;k4ByteArray[15]=ui->k4byte15;
    k5ByteArray = new QLabel*[16];
    k5ByteArray[0]=ui->k5byte00;k5ByteArray[1]=ui->k5byte01;k5ByteArray[2]=ui->k5byte02;k5ByteArray[3]=ui->k5byte03;k5ByteArray[4]=ui->k5byte04;k5ByteArray[5]=ui->k5byte05;k5ByteArray[6]=ui->k5byte06;k5ByteArray[7]=ui->k5byte07;
    k5ByteArray[8]=ui->k5byte08;k5ByteArray[9]=ui->k5byte09;k5ByteArray[10]=ui->k5byte10;k5ByteArray[11]=ui->k5byte11;k5ByteArray[12]=ui->k5byte12;k5ByteArray[13]=ui->k5byte13;k5ByteArray[14]=ui->k5byte14;k5ByteArray[15]=ui->k5byte15;
    k6ByteArray = new QLabel*[16];
    k6ByteArray[0]=ui->k6byte00;k6ByteArray[1]=ui->k6byte01;k6ByteArray[2]=ui->k6byte02;k6ByteArray[3]=ui->k6byte03;k6ByteArray[4]=ui->k6byte04;k6ByteArray[5]=ui->k6byte05;k6ByteArray[6]=ui->k6byte06;k6ByteArray[7]=ui->k6byte07;
    k6ByteArray[8]=ui->k6byte08;k6ByteArray[9]=ui->k6byte09;k6ByteArray[10]=ui->k6byte10;k6ByteArray[11]=ui->k6byte11;k6ByteArray[12]=ui->k6byte12;k6ByteArray[13]=ui->k6byte13;k6ByteArray[14]=ui->k6byte14;k6ByteArray[15]=ui->k6byte15;
    k7ByteArray = new QLabel*[16];
    k7ByteArray[0]=ui->k7byte00;k7ByteArray[1]=ui->k7byte01;k7ByteArray[2]=ui->k7byte02;k7ByteArray[3]=ui->k7byte03;k7ByteArray[4]=ui->k7byte04;k7ByteArray[5]=ui->k7byte05;k7ByteArray[6]=ui->k7byte06;k7ByteArray[7]=ui->k7byte07;
    k7ByteArray[8]=ui->k7byte08;k7ByteArray[9]=ui->k7byte09;k7ByteArray[10]=ui->k7byte10;k7ByteArray[11]=ui->k7byte11;k7ByteArray[12]=ui->k7byte12;k7ByteArray[13]=ui->k7byte13;k7ByteArray[14]=ui->k7byte14;k7ByteArray[15]=ui->k7byte15;
    k8ByteArray = new QLabel*[16];
    k8ByteArray[0]=ui->k8byte00;k8ByteArray[1]=ui->k8byte01;k8ByteArray[2]=ui->k8byte02;k8ByteArray[3]=ui->k8byte03;k8ByteArray[4]=ui->k8byte04;k8ByteArray[5]=ui->k8byte05;k8ByteArray[6]=ui->k8byte06;k8ByteArray[7]=ui->k8byte07;
    k8ByteArray[8]=ui->k8byte08;k8ByteArray[9]=ui->k8byte09;k8ByteArray[10]=ui->k8byte10;k8ByteArray[11]=ui->k8byte11;k8ByteArray[12]=ui->k8byte12;k8ByteArray[13]=ui->k8byte13;k8ByteArray[14]=ui->k8byte14;k8ByteArray[15]=ui->k8byte15;
    k9ByteArray = new QLabel*[16];
    k9ByteArray[0]=ui->k9byte00;k9ByteArray[1]=ui->k9byte01;k9ByteArray[2]=ui->k9byte02;k9ByteArray[3]=ui->k9byte03;k9ByteArray[4]=ui->k9byte04;k9ByteArray[5]=ui->k9byte05;k9ByteArray[6]=ui->k9byte06;k9ByteArray[7]=ui->k9byte07;
    k9ByteArray[8]=ui->k9byte08;k9ByteArray[9]=ui->k9byte09;k9ByteArray[10]=ui->k9byte10;k9ByteArray[11]=ui->k9byte11;k9ByteArray[12]=ui->k9byte12;k9ByteArray[13]=ui->k9byte13;k9ByteArray[14]=ui->k9byte14;k9ByteArray[15]=ui->k9byte15;
    k10ByteArray = new QLabel*[16];
    k10ByteArray[0]=ui->k10byte00;k10ByteArray[1]=ui->k10byte01;k10ByteArray[2]=ui->k10byte02;k10ByteArray[3]=ui->k10byte03;k10ByteArray[4]=ui->k10byte04;k10ByteArray[5]=ui->k10byte05;k10ByteArray[6]=ui->k10byte06;k10ByteArray[7]=ui->k10byte07;
    k10ByteArray[8]=ui->k10byte08;k10ByteArray[9]=ui->k10byte09;k10ByteArray[10]=ui->k10byte10;k10ByteArray[11]=ui->k10byte11;k10ByteArray[12]=ui->k10byte12;k10ByteArray[13]=ui->k10byte13;k10ByteArray[14]=ui->k10byte14;k10ByteArray[15]=ui->k10byte15;
    k11ByteArray = new QLabel*[16];
    k11ByteArray[0]=ui->k11byte00;k11ByteArray[1]=ui->k11byte01;k11ByteArray[2]=ui->k11byte02;k11ByteArray[3]=ui->k11byte03;k11ByteArray[4]=ui->k11byte04;k11ByteArray[5]=ui->k11byte05;k11ByteArray[6]=ui->k11byte06;k11ByteArray[7]=ui->k11byte07;
    k11ByteArray[8]=ui->k11byte08;k11ByteArray[9]=ui->k11byte09;k11ByteArray[10]=ui->k11byte10;k11ByteArray[11]=ui->k11byte11;k11ByteArray[12]=ui->k11byte12;k11ByteArray[13]=ui->k11byte13;k11ByteArray[14]=ui->k11byte14;k11ByteArray[15]=ui->k11byte15;
    k12ByteArray = new QLabel*[16];
    k12ByteArray[0]=ui->k12byte00;k12ByteArray[1]=ui->k12byte01;k12ByteArray[2]=ui->k12byte02;k12ByteArray[3]=ui->k12byte03;k12ByteArray[4]=ui->k12byte04;k12ByteArray[5]=ui->k12byte05;k12ByteArray[6]=ui->k12byte06;k12ByteArray[7]=ui->k12byte07;
    k12ByteArray[8]=ui->k12byte08;k12ByteArray[9]=ui->k12byte09;k12ByteArray[10]=ui->k12byte10;k12ByteArray[11]=ui->k12byte11;k12ByteArray[12]=ui->k12byte12;k12ByteArray[13]=ui->k12byte13;k12ByteArray[14]=ui->k12byte14;k12ByteArray[15]=ui->k12byte15;
    k13ByteArray = new QLabel*[16];
    k13ByteArray[0]=ui->k13byte00;k13ByteArray[1]=ui->k13byte01;k13ByteArray[2]=ui->k13byte02;k13ByteArray[3]=ui->k13byte03;k13ByteArray[4]=ui->k13byte04;k13ByteArray[5]=ui->k13byte05;k13ByteArray[6]=ui->k13byte06;k13ByteArray[7]=ui->k13byte07;
    k13ByteArray[8]=ui->k13byte08;k13ByteArray[9]=ui->k13byte09;k13ByteArray[10]=ui->k13byte10;k13ByteArray[11]=ui->k13byte11;k13ByteArray[12]=ui->k13byte12;k13ByteArray[13]=ui->k13byte13;k13ByteArray[14]=ui->k13byte14;k13ByteArray[15]=ui->k13byte15;
    k14ByteArray = new QLabel*[16];
    k14ByteArray[0]=ui->k14byte00;k14ByteArray[1]=ui->k14byte01;k14ByteArray[2]=ui->k14byte02;k14ByteArray[3]=ui->k14byte03;k14ByteArray[4]=ui->k14byte04;k14ByteArray[5]=ui->k14byte05;k14ByteArray[6]=ui->k14byte06;k14ByteArray[7]=ui->k14byte07;
    k14ByteArray[8]=ui->k14byte08;k14ByteArray[9]=ui->k14byte09;k14ByteArray[10]=ui->k14byte10;k14ByteArray[11]=ui->k14byte11;k14ByteArray[12]=ui->k14byte12;k14ByteArray[13]=ui->k14byte13;k14ByteArray[14]=ui->k14byte14;k14ByteArray[15]=ui->k14byte15;
    kPartArray = new QLabel**[15];
    kPartArray[0]=k0ByteArray;kPartArray[1]=k1ByteArray;kPartArray[2]=k2ByteArray;kPartArray[3]=k3ByteArray;kPartArray[4]=k4ByteArray;
    kPartArray[5]=k5ByteArray;kPartArray[6]=k6ByteArray;kPartArray[7]=k7ByteArray;kPartArray[8]=k8ByteArray;kPartArray[9]=k9ByteArray;
    kPartArray[10]=k10ByteArray;kPartArray[11]=k11ByteArray;kPartArray[12]=k12ByteArray;kPartArray[13]=k13ByteArray;kPartArray[14]=k14ByteArray;
}

DialogShowExpKey::~DialogShowExpKey()
{
    delete ui;
}

void DialogShowExpKey::SetExpKeyMatrixPointer(unsigned char ** matrix){
        this->expKeyMatrix = matrix;
        QLabel** kNow;
        char* temp = new char[3];
        for (int k = 0; k < 11; k++){
            kNow = kPartArray[k];
            for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 4; j++){
                            snprintf(temp, 3, "%.2x", expKeyMatrix[i][j+k*4]);
                            temp[0] = toupper(temp[0]); temp[1] = toupper(temp[1]);
                            kNow[i+j*4]->setText(temp);
                    }
            }
        }
        delete temp;
}

void DialogShowExpKey::SetKeySize(FastRijndael::KeySize keySize)
{
        this->keySize = keySize;
        switch (keySize){
                case FastRijndael::K128:
                        ui->groupK11->setVisible(false);
                        ui->groupK12->setVisible(false);
                        ui->groupK13->setVisible(false);
                        ui->groupK14->setVisible(false);
                        break;
                case FastRijndael::K192:
                        ui->groupK13->setVisible(false);
                        ui->groupK14->setVisible(false);
                        break;
                case FastRijndael::K256:
                        break;
                default:
                        break;
        }
}
