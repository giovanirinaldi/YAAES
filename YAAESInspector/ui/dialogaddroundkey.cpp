#include "dialogaddroundkey.h"
#include "ui_dialogaddroundkey.h"
#include <cstdio>

DialogAddRoundKey::DialogAddRoundKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddRoundKey)
{
    ui->setupUi(this);

    stateArray = new QLabel* [16];
    stateArray[0] = ui->stateByte00;stateArray[1] = ui->stateByte01;stateArray[2] = ui->stateByte02;stateArray[3] = ui->stateByte03;
    stateArray[4] = ui->stateByte04;stateArray[5] = ui->stateByte05;stateArray[6] = ui->stateByte06;stateArray[7] = ui->stateByte07;
    stateArray[8] = ui->stateByte08;stateArray[9] = ui->stateByte09;stateArray[10] = ui->stateByte10;stateArray[11] = ui->stateByte11;
    stateArray[12] = ui->stateByte12;stateArray[13] = ui->stateByte13;stateArray[14] = ui->stateByte14;stateArray[15] = ui->stateByte15;

    subKeyArray = new QLabel* [16];
    subKeyArray[0] = ui->subKeyByte00;subKeyArray[1] = ui->subKeyByte01;subKeyArray[2] = ui->subKeyByte02;subKeyArray[3] = ui->subKeyByte03;
    subKeyArray[4] = ui->subKeyByte04;subKeyArray[5] = ui->subKeyByte05;subKeyArray[6] = ui->subKeyByte06;subKeyArray[7] = ui->subKeyByte07;
    subKeyArray[8] = ui->subKeyByte08;subKeyArray[9] = ui->subKeyByte09;subKeyArray[10] = ui->subKeyByte10;subKeyArray[11] = ui->subKeyByte11;
    subKeyArray[12] = ui->subKeyByte12;subKeyArray[13] = ui->subKeyByte13;subKeyArray[14] = ui->subKeyByte14;subKeyArray[15] = ui->subKeyByte15;

    resultArray = new QLabel* [16];
    resultArray[0] = ui->resultByte00;resultArray[1] = ui->resultByte01;resultArray[2] = ui->resultByte02;resultArray[3] = ui->resultByte03;
    resultArray[4] = ui->resultByte04;resultArray[5] = ui->resultByte05;resultArray[6] = ui->resultByte06;resultArray[7] = ui->resultByte07;
    resultArray[8] = ui->resultByte08;resultArray[9] = ui->resultByte09;resultArray[10] = ui->resultByte10;resultArray[11] = ui->resultByte11;
    resultArray[12] = ui->resultByte12;resultArray[13] = ui->resultByte13;resultArray[14] = ui->resultByte14;resultArray[15] = ui->resultByte15;
}

DialogAddRoundKey::~DialogAddRoundKey()
{
    delete[] result;
    delete ui;
}

void DialogAddRoundKey::setStateMatrix(unsigned char* state){
    this->state = state;
}

void DialogAddRoundKey::setSubKeyMatrix(unsigned char* subKey){
    this->subKey = subKey;
}

void DialogAddRoundKey::hexToUpperCaseText(unsigned char &hex, char* temp_string){
        snprintf(temp_string, 3, "%.2x", hex);
        temp_string[0] = toupper(temp_string[0]);
        temp_string[1] = toupper(temp_string[1]);
}

void DialogAddRoundKey::updateMatrix(){
    char* temp_string = new char[3];
    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(state[i], temp_string);
        stateArray[i]->setText(temp_string);
        hexToUpperCaseText(subKey[i], temp_string);
        subKeyArray[i]->setText(temp_string);
    }
    result = new unsigned char[16];
    for (int i = 0; i < 16; i++){
        result[i] = state[i] ^ subKey[i];
        hexToUpperCaseText(result[i], temp_string);
        resultArray[i]->setText(temp_string);
    }
    delete[] temp_string;
}

void DialogAddRoundKey::on_buttonBox_clicked(QAbstractButton* button)
{
    this->close();
}
