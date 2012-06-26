#include "dialogkeyschedule.h"
#include "ui_dialogkeyschedule.h"

#include "../Rijndael/fast-rijndael-1d/fast-rijndael-1d.h"

DialogKeySchedule::DialogKeySchedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogKeySchedule)
{
    ui->setupUi(this);

    kaArray = new QLabel* [16];
    kaArray[0] = ui->kaByte00;kaArray[1] = ui->kaByte01;kaArray[2] = ui->kaByte02;kaArray[3] = ui->kaByte03;
    kaArray[4] = ui->kaByte04;kaArray[5] = ui->kaByte05;kaArray[6] = ui->kaByte06;kaArray[7] = ui->kaByte07;
    kaArray[8] = ui->kaByte08;kaArray[9] = ui->kaByte09;kaArray[10] = ui->kaByte10;kaArray[11] = ui->kaByte11;
    kaArray[12] = ui->kaByte12;kaArray[13] = ui->kaByte13;kaArray[14] = ui->kaByte14;kaArray[15] = ui->kaByte15;

    kbArray = new QLabel* [16];
    kbArray[0] = ui->kbByte00;kbArray[1] = ui->kbByte01;kbArray[2] = ui->kbByte02;kbArray[3] = ui->kbByte03;
    kbArray[4] = ui->kbByte04;kbArray[5] = ui->kbByte05;kbArray[6] = ui->kbByte06;kbArray[7] = ui->kbByte07;
    kbArray[8] = ui->kbByte08;kbArray[9] = ui->kbByte09;kbArray[10] = ui->kbByte10;kbArray[11] = ui->kbByte11;
    kbArray[12] = ui->kbByte12;kbArray[13] = ui->kbByte13;kbArray[14] = ui->kbByte14;kbArray[15] = ui->kbByte15;



    ui->radioButtonCol0->setChecked(true);
    changeVisibility();
}

DialogKeySchedule::~DialogKeySchedule()
{
    delete ui;
}

void DialogKeySchedule::setSubKeyNum(int num){
    n = num;
    char temp_string[3] = "\0\0";
    snprintf(temp_string, 3, "%d", n);
    QString lblRcon = "RCon[";
    lblRcon.append(temp_string);
    lblRcon.append("]");
    ui->labelRcon->setText(lblRcon);
}

void DialogKeySchedule::setSubKeyA(unsigned char* subKeyA){
    ka = subKeyA;
}

void DialogKeySchedule::setSubKeyB(unsigned char* subKeyB){
    kb = subKeyB;
}

void DialogKeySchedule::hexToUpperCaseText(unsigned char &hex, char* temp_string){
        snprintf(temp_string, 3, "%.2x", hex);
        temp_string[0] = toupper(temp_string[0]);
        temp_string[1] = toupper(temp_string[1]);
}

void DialogKeySchedule::update(){
    char* temp_string = new char[3];
    unsigned char temp_byte;

    snprintf(temp_string, 3, "K%d", n-1);
    ui->groupK0->setTitle(temp_string);
    snprintf(temp_string, 3, "K%d", n);
    ui->groupK1->setTitle(temp_string);


    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(ka[i], temp_string);
        kaArray[i]->setText(temp_string);
        hexToUpperCaseText(kb[i], temp_string);
        kbArray[i]->setText(temp_string);

    }
    ui->kaAfterRotWordByte00->setText(kaArray[13]->text());
    ui->kaAfterRotWordByte01->setText(kaArray[14]->text());
    ui->kaAfterRotWordByte02->setText(kaArray[15]->text());
    ui->kaAfterRotWordByte03->setText(kaArray[12]->text());

    temp_byte = _sbox[ka[13]];
    hexToUpperCaseText(temp_byte, temp_string);
    ui->kaAfterSBByte00->setText(temp_string);
    temp_byte = _sbox[ka[14]];
    hexToUpperCaseText(temp_byte, temp_string);
    ui->kaAfterSBByte01->setText(temp_string);
    temp_byte = _sbox[ka[15]];
    hexToUpperCaseText(temp_byte, temp_string);
    ui->kaAfterSBByte02->setText(temp_string);
    temp_byte = _sbox[ka[12]];
    hexToUpperCaseText(temp_byte, temp_string);
    ui->kaAfterSBByte03->setText(temp_string);

    temp_byte = _rcon[n];
    hexToUpperCaseText(temp_byte, temp_string);
    ui->rconByte00->setText(temp_string);
    ui->rconByte01->setText("00");
    ui->rconByte02->setText("00");
    ui->rconByte03->setText("00");

    ui->kaByte00_2->setText(ui->kaByte00->text());
    ui->kaByte01_2->setText(ui->kaByte01->text());
    ui->kaByte02_2->setText(ui->kaByte02->text());
    ui->kaByte03_2->setText(ui->kaByte03->text());

    ui->kbByte00_2->setText(ui->kbByte00->text());
    ui->kbByte01_2->setText(ui->kbByte01->text());
    ui->kbByte02_2->setText(ui->kbByte02->text());
    ui->kbByte03_2->setText(ui->kbByte03->text());

    if (ui->radioButtonCol1->isChecked()){
        ui->rconByte00->setText(ui->kaByte04->text());
        ui->rconByte01->setText(ui->kaByte05->text());
        ui->rconByte02->setText(ui->kaByte06->text());
        ui->rconByte03->setText(ui->kaByte07->text());

        ui->kaByte00_2->setText(ui->kbByte00->text());
        ui->kaByte01_2->setText(ui->kbByte01->text());
        ui->kaByte02_2->setText(ui->kbByte02->text());
        ui->kaByte03_2->setText(ui->kbByte03->text());

        ui->kbByte04_2->setText(ui->kbByte04->text());
        ui->kbByte05_2->setText(ui->kbByte05->text());
        ui->kbByte06_2->setText(ui->kbByte06->text());
        ui->kbByte07_2->setText(ui->kbByte07->text());
    }
    if (ui->radioButtonCol2->isChecked()){
        ui->rconByte00->setText(ui->kaByte08->text());
        ui->rconByte01->setText(ui->kaByte09->text());
        ui->rconByte02->setText(ui->kaByte10->text());
        ui->rconByte03->setText(ui->kaByte11->text());

        ui->kaByte00_2->setText(ui->kbByte04->text());
        ui->kaByte01_2->setText(ui->kbByte05->text());
        ui->kaByte02_2->setText(ui->kbByte06->text());
        ui->kaByte03_2->setText(ui->kbByte07->text());

        ui->kbByte08_2->setText(ui->kbByte08->text());
        ui->kbByte09_2->setText(ui->kbByte09->text());
        ui->kbByte10_2->setText(ui->kbByte10->text());
        ui->kbByte11_2->setText(ui->kbByte11->text());
    }
    if (ui->radioButtonCol3->isChecked()){
        ui->rconByte00->setText(ui->kaByte12->text());
        ui->rconByte01->setText(ui->kaByte13->text());
        ui->rconByte02->setText(ui->kaByte14->text());
        ui->rconByte03->setText(ui->kaByte15->text());

        ui->kaByte00_2->setText(ui->kbByte08->text());
        ui->kaByte01_2->setText(ui->kbByte09->text());
        ui->kaByte02_2->setText(ui->kbByte10->text());
        ui->kaByte03_2->setText(ui->kbByte11->text());

        ui->kbByte12_2->setText(ui->kbByte12->text());
        ui->kbByte13_2->setText(ui->kbByte13->text());
        ui->kbByte14_2->setText(ui->kbByte14->text());
        ui->kbByte15_2->setText(ui->kbByte15->text());
    }


    delete[] temp_string;
}

void DialogKeySchedule::changeVisibility(){
    //ui->arrowAnswer->setVisible(true);
    ui->hlineAnswer->setVisible(true);
    ui->arrowKaCol->setVisible(true);
    ui->rconByte00->setVisible(true);
    ui->rconByte01->setVisible(true);
    ui->rconByte02->setVisible(true);
    ui->rconByte03->setVisible(true);
    ui->kaByte00_2->setVisible(true);
    ui->kaByte01_2->setVisible(true);
    ui->kaByte02_2->setVisible(true);
    ui->kaByte03_2->setVisible(true);
    ui->widgetXor_2->setVisible(true);


    /*first*/
    ui->kaAfterRotWordByte00->setVisible(true);
    ui->kaAfterRotWordByte01->setVisible(true);
    ui->kaAfterRotWordByte02->setVisible(true);
    ui->kaAfterRotWordByte03->setVisible(true);
    ui->kaAfterSBByte00->setVisible(true);
    ui->kaAfterSBByte01->setVisible(true);
    ui->kaAfterSBByte02->setVisible(true);
    ui->kaAfterSBByte03->setVisible(true);
    ui->kbByte00_2->setVisible(true);
    ui->kbByte01_2->setVisible(true);
    ui->kbByte02_2->setVisible(true);
    ui->kbByte03_2->setVisible(true);
    ui->vlineKaCol3->setVisible(true);
    ui->vlineKaCol0->setVisible(true);
    ui->arrowSubBytes->setVisible(true);
    ui->arrowKaCol4->setVisible(true);
    ui->labelRcon->setVisible(true);
    ui->labelRotWord->setVisible(true);
    ui->labelSubBytes->setVisible(true);
    ui->hlineKaCol0->setVisible(true);
    ui->vlineKbCol0->setVisible(true);
    ui->widgetXor->setVisible(true);
    ui->hlineSubBytes->setVisible(true);
    ui->arrowKbCol0->setVisible(true);
    ui->arrowKaCol->setVisible(true);
    ui->vlineArrowKaCol->setVisible(true);

    /*second*/
    ui->vlineKaCol1->setVisible(false);
    ui->hlineKaCol1->setVisible(false);
    ui->arrowKaColGen->setVisible(false);
    ui->vlineArrowKaColGen->setVisible(false);
    ui->arrowKbXor->setVisible(false);
    ui->vlineKbXor->setVisible(false);
    ui->hlineKbCol1->setVisible(false);
    ui->vlineKbCol1->setVisible(false);
    ui->arrowKbCol1->setVisible(false);
    ui->kbByte04_2->setVisible(false);
    ui->kbByte05_2->setVisible(false);
    ui->kbByte06_2->setVisible(false);
    ui->kbByte07_2->setVisible(false);

    /*third*/
    ui->vlineKaCol2->setVisible(false);
    ui->hlineKaCol2->setVisible(false);
    ui->hlineKbCol2->setVisible(false);
    ui->vlineKbCol2->setVisible(false);
    ui->arrowKbCol2->setVisible(false);
    ui->kbByte08_2->setVisible(false);
    ui->kbByte09_2->setVisible(false);
    ui->kbByte10_2->setVisible(false);
    ui->kbByte11_2->setVisible(false);

    /*fourth*/
    ui->vlineKaCol3_2->setVisible(false);
    ui->hlineKaCol3->setVisible(false);
    ui->hlineKbCol3->setVisible(false);
    ui->vlineKbCol3->setVisible(false);
    ui->arrowKbCol3->setVisible(false);
    ui->kbByte12_2->setVisible(false);
    ui->kbByte13_2->setVisible(false);
    ui->kbByte14_2->setVisible(false);
    ui->kbByte15_2->setVisible(false);

    if (ui->radioButtonCol0->isChecked()){

    }
    else{
        ui->kaAfterRotWordByte00->setVisible(false);
        ui->kaAfterRotWordByte01->setVisible(false);
        ui->kaAfterRotWordByte02->setVisible(false);
        ui->kaAfterRotWordByte03->setVisible(false);
        ui->kaAfterSBByte00->setVisible(false);
        ui->kaAfterSBByte01->setVisible(false);
        ui->kaAfterSBByte02->setVisible(false);
        ui->kaAfterSBByte03->setVisible(false);
        ui->kbByte00_2->setVisible(false);
        ui->kbByte01_2->setVisible(false);
        ui->kbByte02_2->setVisible(false);
        ui->kbByte03_2->setVisible(false);
        ui->vlineKaCol3->setVisible(false);
        ui->vlineKaCol0->setVisible(false);
        ui->arrowSubBytes->setVisible(false);
        ui->arrowKaCol4->setVisible(false);
        ui->labelRcon->setVisible(false);
        ui->labelRotWord->setVisible(false);
        ui->labelSubBytes->setVisible(false);
        ui->hlineKaCol0->setVisible(false);
        ui->vlineKbCol0->setVisible(false);
        ui->widgetXor->setVisible(false);
        ui->hlineSubBytes->setVisible(false);
        ui->arrowKbCol0->setVisible(false);
        ui->arrowKaCol->setVisible(false);
        ui->vlineArrowKaCol->setVisible(false);

        ui->vlineArrowKaColGen->setVisible(true);
        ui->arrowKaColGen->setVisible(true);
        ui->arrowKbXor->setVisible(true);
        ui->vlineKbXor->setVisible(true);
        if (ui->radioButtonCol1->isChecked()){
            ui->vlineKaCol1->setVisible(true);
            ui->hlineKaCol1->setVisible(true);
            ui->hlineKbCol1->setVisible(true);
            ui->vlineKbCol1->setVisible(true);
            ui->arrowKbCol1->setVisible(true);
            ui->kbByte04_2->setVisible(true);
            ui->kbByte05_2->setVisible(true);
            ui->kbByte06_2->setVisible(true);
            ui->kbByte07_2->setVisible(true);
        }
        else{
            if (ui->radioButtonCol2->isChecked()){
                ui->vlineKaCol2->setVisible(true);
                ui->hlineKaCol2->setVisible(true);
                ui->hlineKbCol2->setVisible(true);
                ui->vlineKbCol2->setVisible(true);
                ui->arrowKbCol2->setVisible(true);
                ui->kbByte08_2->setVisible(true);
                ui->kbByte09_2->setVisible(true);
                ui->kbByte10_2->setVisible(true);
                ui->kbByte11_2->setVisible(true);
            }
            else{
                if (ui->radioButtonCol3->isChecked()){
                    ui->vlineKaCol3_2->setVisible(true);
                    ui->hlineKaCol3->setVisible(true);
                    ui->hlineKbCol3->setVisible(true);
                    ui->vlineKbCol3->setVisible(true);
                    ui->arrowKbCol3->setVisible(true);
                    ui->kbByte12_2->setVisible(true);
                    ui->kbByte13_2->setVisible(true);
                    ui->kbByte14_2->setVisible(true);
                    ui->kbByte15_2->setVisible(true);
                }
            }
        }
    }
}

void DialogKeySchedule::on_radioButtonCol0_clicked()
{
    changeVisibility();
    update();
}

void DialogKeySchedule::on_radioButtonCol1_clicked()
{
    changeVisibility();
    update();
}

void DialogKeySchedule::on_radioButtonCol2_clicked()
{
    changeVisibility();
    update();
}

void DialogKeySchedule::on_radioButtonCol3_clicked()
{
    changeVisibility();
    update();
}

void DialogKeySchedule::on_buttonBox_clicked(QAbstractButton* button)
{
    this->close();
}
