#include "dialogshiftrows.h"
#include "ui_dialogshiftrows.h"


#include "src/global.h"

DialogShiftRows::DialogShiftRows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShiftRows)
{
    ui->setupUi(this);

    stateArray = new QLabel* [16];
    stateArray[0] = ui->stateByte00;stateArray[1] = ui->stateByte01;stateArray[2] = ui->stateByte02;stateArray[3] = ui->stateByte03;
    stateArray[4] = ui->stateByte04;stateArray[5] = ui->stateByte05;stateArray[6] = ui->stateByte06;stateArray[7] = ui->stateByte07;
    stateArray[8] = ui->stateByte08;stateArray[9] = ui->stateByte09;stateArray[10] = ui->stateByte10;stateArray[11] = ui->stateByte11;
    stateArray[12] = ui->stateByte12;stateArray[13] = ui->stateByte13;stateArray[14] = ui->stateByte14;stateArray[15] = ui->stateByte15;

    shiftArray = new QLabel* [16];
    shiftArray[0] = ui->shiftByte00;shiftArray[1] = ui->shiftByte01;shiftArray[2] = ui->shiftByte02;shiftArray[3] = ui->shiftByte03;
    shiftArray[4] = ui->shiftByte04;shiftArray[5] = ui->shiftByte05;shiftArray[6] = ui->shiftByte06;shiftArray[7] = ui->shiftByte07;
    shiftArray[8] = ui->shiftByte08;shiftArray[9] = ui->shiftByte09;shiftArray[10] = ui->shiftByte10;shiftArray[11] = ui->shiftByte11;
    shiftArray[12] = ui->shiftByte12;shiftArray[13] = ui->shiftByte13;shiftArray[14] = ui->shiftByte14;shiftArray[15] = ui->shiftByte15;

    resultArray = new QLabel* [16];
    resultArray[0] = ui->resultByte00;resultArray[1] = ui->resultByte01;resultArray[2] = ui->resultByte02;resultArray[3] = ui->resultByte03;
    resultArray[4] = ui->resultByte04;resultArray[5] = ui->resultByte05;resultArray[6] = ui->resultByte06;resultArray[7] = ui->resultByte07;
    resultArray[8] = ui->resultByte08;resultArray[9] = ui->resultByte09;resultArray[10] = ui->resultByte10;resultArray[11] = ui->resultByte11;
    resultArray[12] = ui->resultByte12;resultArray[13] = ui->resultByte13;resultArray[14] = ui->resultByte14;resultArray[15] = ui->resultByte15;
}

DialogShiftRows::~DialogShiftRows()
{
    delete[] result;
    delete ui;
}

void DialogShiftRows::setStateMatrix(unsigned char* state){
    this->state = state;
}

void DialogShiftRows::hexToUpperCaseText(unsigned char &hex, char* temp_string){
        snprintf(temp_string, 3, "%.2x", hex);
        temp_string[0] = toupper(temp_string[0]);
        temp_string[1] = toupper(temp_string[1]);
}

void DialogShiftRows::updateMatrix(){
    char* temp_string = new char[3];
    result = new unsigned char[16];
    for (int i = 0; i < 16; i++){
        result[i] = state[i];
        hexToUpperCaseText(state[i], temp_string);
        stateArray[i]->setText(temp_string);
        shiftArray[i]->setText(temp_string);
    }
    rijn->shiftRows(result);
    for (int i = 0; i < 16; i++){
        hexToUpperCaseText(result[i], temp_string);
        resultArray[i]->setText(temp_string);
    }
    delete[] temp_string;
}

void DialogShiftRows::on_buttonBox_clicked(QAbstractButton* )
{
    this->close();
}
