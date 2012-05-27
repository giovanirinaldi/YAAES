#include "mainwindow.h"
#include "ui_mainwindow.h"


//d
#include <cstdio>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabInput));

    on_actionExample_1_triggered();

    rijn = FastRijndael(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);

    k0found = new unsigned char[16];
    for (int i = 0; i < 16; i++){
        k0found[i] = 0x00;
    }
    keyFound = false;

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
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_buttonRun_clicked()
{
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
        ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tabOutput));
    }
    else{
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
    ui->editByte00From->setText("00");ui->editByte00To->setText("00");
    ui->editByte05From->setText("05");ui->editByte05To->setText("05");
    ui->editByte07From->setText("07");ui->editByte07To->setText("07");
    ui->editByte08From->setText("08");ui->editByte08To->setText("08");
    ui->editByte10From->setText("0A");ui->editByte10To->setText("0A");
    ui->editByte15From->setText("0F");ui->editByte15To->setText("0F");
}

void MainWindow::on_tabWidget_currentChanged(int index)
{

}


void MainWindow::on_tabWidget_currentChanged(QWidget* tab)
{
    if (tab == ui->tabInput){
        printf("tabInput\n");fflush(stdout);
    }
    else if (tab == ui->tabOutput){
        if (ui->editPlaintext1->text().length() == 32){
            setOutPlain1(ui->editPlaintext1->text());
        }
        if (ui->editCiphertext1->text().length() == 32){
            setOutCipher1(ui->editCiphertext1->text());
        }
        if (keyFound){
            setOutK0(k0found);
            setOutCipherK0(ui->editCiphertext1->text());
        }
        else{
            QString unknown = "????????????????????????????????";
            setOutK0(unknown);
            setOutCipherK0(unknown);
        }
        printf("tabOutput\n");fflush(stdout);
    }
    else if (tab == ui->tabS01E01){
        setPlainS01E01(ui->editPlaintext1->text(), ui->editPlaintext2->text(), ui->editPlaintext3->text());
        tryByte00 = hexValue(ui->editByte00From->text().at(0).toAscii())*256 + hexValue(ui->editByte00From->text().at(1).toAscii());
        tryByte05 = hexValue(ui->editByte05From->text().at(0).toAscii())*256 + hexValue(ui->editByte05From->text().at(1).toAscii());
        tryByte07 = hexValue(ui->editByte07From->text().at(0).toAscii())*256 + hexValue(ui->editByte07From->text().at(1).toAscii());
        tryByte08 = hexValue(ui->editByte08From->text().at(0).toAscii())*256 + hexValue(ui->editByte08From->text().at(1).toAscii());
        tryByte10 = hexValue(ui->editByte10From->text().at(0).toAscii())*256 + hexValue(ui->editByte10From->text().at(1).toAscii());
        tryByte15 = hexValue(ui->editByte15From->text().at(0).toAscii())*256 + hexValue(ui->editByte15From->text().at(1).toAscii());
        printf("%.2x %.2x %.2x %.2x %.2x %.2x\n", tryByte00,tryByte05,tryByte07,tryByte08,tryByte10,tryByte15);
        ui->statusBar->showMessage("oi");
        printf("tabS01E01\n");fflush(stdout);
    }
    else{
        printf("tabFringe\n");fflush(stdout);
    }
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
