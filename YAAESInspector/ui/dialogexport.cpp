#include "dialogexport.h"
#include "ui_dialogexport.h"

DialogExport::DialogExport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogExport)
{
    ui->setupUi(this);
}

DialogExport::~DialogExport()
{
    delete ui;
}

void DialogExport::setPlaintext(unsigned char* plaintext){
    this->plaintext = plaintext;
}

void DialogExport::setCiphertext(unsigned char* ciphertext){
    this->ciphertext = ciphertext;
}

void DialogExport::hexToUpperCaseText(unsigned char &hex, char* temp_string){
        snprintf(temp_string, 3, "%.2x", hex);
        temp_string[0] = toupper(temp_string[0]);
        temp_string[1] = toupper(temp_string[1]);
}

void DialogExport::update(){
    char* temp_string =  new char [3];
    QString line = "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
    for (int i = 0; i < 32; i=i+2){
        hexToUpperCaseText(plaintext[i/2], temp_string);
        line[i] = temp_string[0];
        line[i+1] = temp_string[1];
    }
    ui->linePlaintext->setText(line);
    for (int i = 0; i < 32; i=i+2){
        hexToUpperCaseText(ciphertext[i/2], temp_string);
        line[i] = temp_string[0];
        line[i+1] = temp_string[1];
    }
    ui->lineCiphertext->setText(line);
    delete[] temp_string;
}
