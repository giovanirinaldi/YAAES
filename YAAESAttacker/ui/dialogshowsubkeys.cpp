#include "dialogshowsubkeys.h"
#include "ui_dialogshowsubkeys.h"

DialogShowSubKeys::DialogShowSubKeys(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowSubKeys)
{
    ui->setupUi(this);

    k0Array = new QLabel*[16];
    k0Array[0]=ui->k0byte00;k0Array[1]=ui->k0byte01;k0Array[2]=ui->k0byte02;k0Array[3]=ui->k0byte03;
    k0Array[4]=ui->k0byte04;k0Array[5]=ui->k0byte05;k0Array[6]=ui->k0byte06;k0Array[7]=ui->k0byte07;
    k0Array[8]=ui->k0byte08;k0Array[9]=ui->k0byte09;k0Array[10]=ui->k0byte10;k0Array[11]=ui->k0byte11;
    k0Array[12]=ui->k0byte12;k0Array[13]=ui->k0byte13;k0Array[14]=ui->k0byte14;k0Array[15]=ui->k0byte15;

    k1Array = new QLabel*[16];
    k1Array[0]=ui->k1byte00;k1Array[1]=ui->k1byte01;k1Array[2]=ui->k1byte02;k1Array[3]=ui->k1byte03;
    k1Array[4]=ui->k1byte04;k1Array[5]=ui->k1byte05;k1Array[6]=ui->k1byte06;k1Array[7]=ui->k1byte07;
    k1Array[8]=ui->k1byte08;k1Array[9]=ui->k1byte09;k1Array[10]=ui->k1byte10;k1Array[11]=ui->k1byte11;
    k1Array[12]=ui->k1byte12;k1Array[13]=ui->k1byte13;k1Array[14]=ui->k1byte14;k1Array[15]=ui->k1byte15;

    k2Array = new QLabel*[16];
    k2Array[0]=ui->k2byte00;k2Array[1]=ui->k2byte01;k2Array[2]=ui->k2byte02;k2Array[3]=ui->k2byte03;
    k2Array[4]=ui->k2byte04;k2Array[5]=ui->k2byte05;k2Array[6]=ui->k2byte06;k2Array[7]=ui->k2byte07;
    k2Array[8]=ui->k2byte08;k2Array[9]=ui->k2byte09;k2Array[10]=ui->k2byte10;k2Array[11]=ui->k2byte11;
    k2Array[12]=ui->k2byte12;k2Array[13]=ui->k2byte13;k2Array[14]=ui->k2byte14;k2Array[15]=ui->k2byte15;

    u2Array = new QLabel*[16];
    u2Array[0]=ui->u2byte00;u2Array[1]=ui->u2byte01;u2Array[2]=ui->u2byte02;u2Array[3]=ui->u2byte03;
    u2Array[4]=ui->u2byte04;u2Array[5]=ui->u2byte05;u2Array[6]=ui->u2byte06;u2Array[7]=ui->u2byte07;
    u2Array[8]=ui->u2byte08;u2Array[9]=ui->u2byte09;u2Array[10]=ui->u2byte10;u2Array[11]=ui->u2byte11;
    u2Array[12]=ui->u2byte12;u2Array[13]=ui->u2byte13;u2Array[14]=ui->u2byte14;u2Array[15]=ui->u2byte15;
}

DialogShowSubKeys::~DialogShowSubKeys()
{
    delete ui;
}

void DialogShowSubKeys::on_buttonBox_clicked(QAbstractButton* )
{
    this->close();
}

void DialogShowSubKeys::setSubKeysMatrix(QString* k0, QString* k1, QString* k2, QString* u2){
    for (int i = 0; i < 16; i++){
        k0Array[i]->setText(k0[i]);
        k1Array[i]->setText(k1[i]);
        k2Array[i]->setText(k2[i]);
        u2Array[i]->setText(u2[i]);
    }
}

void DialogShowSubKeys::forceUpdate(){
    k0Array[0]=ui->k0byte00;k0Array[1]=ui->k0byte01;k0Array[2]=ui->k0byte02;k0Array[3]=ui->k0byte03;
    k0Array[4]=ui->k0byte04;k0Array[5]=ui->k0byte05;k0Array[6]=ui->k0byte06;k0Array[7]=ui->k0byte07;
    k0Array[8]=ui->k0byte08;k0Array[9]=ui->k0byte09;k0Array[10]=ui->k0byte10;k0Array[11]=ui->k0byte11;
    k0Array[12]=ui->k0byte12;k0Array[13]=ui->k0byte13;k0Array[14]=ui->k0byte14;k0Array[15]=ui->k0byte15;
    k1Array[0]=ui->k1byte00;k1Array[1]=ui->k1byte01;k1Array[2]=ui->k1byte02;k1Array[3]=ui->k1byte03;
    k1Array[4]=ui->k1byte04;k1Array[5]=ui->k1byte05;k1Array[6]=ui->k1byte06;k1Array[7]=ui->k1byte07;
    k1Array[8]=ui->k1byte08;k1Array[9]=ui->k1byte09;k1Array[10]=ui->k1byte10;k1Array[11]=ui->k1byte11;
    k1Array[12]=ui->k1byte12;k1Array[13]=ui->k1byte13;k1Array[14]=ui->k1byte14;k1Array[15]=ui->k1byte15;
    k2Array[0]=ui->k2byte00;k2Array[1]=ui->k2byte01;k2Array[2]=ui->k2byte02;k2Array[3]=ui->k2byte03;
    k2Array[4]=ui->k2byte04;k2Array[5]=ui->k2byte05;k2Array[6]=ui->k2byte06;k2Array[7]=ui->k2byte07;
    k2Array[8]=ui->k2byte08;k2Array[9]=ui->k2byte09;k2Array[10]=ui->k2byte10;k2Array[11]=ui->k2byte11;
    k2Array[12]=ui->k2byte12;k2Array[13]=ui->k2byte13;k2Array[14]=ui->k2byte14;k2Array[15]=ui->k2byte15;
    u2Array[0]=ui->u2byte00;u2Array[1]=ui->u2byte01;u2Array[2]=ui->u2byte02;u2Array[3]=ui->u2byte03;
    u2Array[4]=ui->u2byte04;u2Array[5]=ui->u2byte05;u2Array[6]=ui->u2byte06;u2Array[7]=ui->u2byte07;
    u2Array[8]=ui->u2byte08;u2Array[9]=ui->u2byte09;u2Array[10]=ui->u2byte10;u2Array[11]=ui->u2byte11;
    u2Array[12]=ui->u2byte12;u2Array[13]=ui->u2byte13;u2Array[14]=ui->u2byte14;u2Array[15]=ui->u2byte15;
    this->repaint();
    this->update();
}
