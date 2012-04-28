#include <cstdio>

#include "mainwindowimpl.h"
#include "dialognew.h"
#include "dialogsetmatriximpl.h"

#ifndef EXTERN
#undef EXTERN
#define EXTERN  
#endif

#include "lines.h"
#include "global.h"
#include <QSplitter>
#include <QMessageBox>
#include <QPainter>
#include <QDesktopWidget>

MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);	
	rijn = new Rijndael(Rijndael::K128);
	rijn->ks_temp = Rijndael::K128;
	maxRounds = 10;
	forward = true;

	keyByteArray = new QLabel*[32];
	keyByteArray[0] = keyByte00;keyByteArray[1] = keyByte01;keyByteArray[2] = keyByte02;keyByteArray[3] = keyByte03;
	keyByteArray[4] = keyByte04;keyByteArray[5] = keyByte05;keyByteArray[6] = keyByte06;keyByteArray[7] = keyByte07;
	keyByteArray[8] = keyByte08;keyByteArray[9] = keyByte09;keyByteArray[10] = keyByte10;keyByteArray[11] = keyByte11;
	keyByteArray[12] = keyByte12;keyByteArray[13] = keyByte13;keyByteArray[14] = keyByte14;keyByteArray[15] = keyByte15;
	keyByteArray[16] = keyByte16;keyByteArray[17] = keyByte17;keyByteArray[18] = keyByte18;keyByteArray[19] = keyByte19;
	keyByteArray[20] = keyByte20;keyByteArray[21] = keyByte21;keyByteArray[22] = keyByte22;keyByteArray[23] = keyByte23;
	keyByteArray[24] = keyByte24;keyByteArray[25] = keyByte25;keyByteArray[26] = keyByte26;keyByteArray[27] = keyByte27;
	keyByteArray[28] = keyByte28;keyByteArray[29] = keyByte29;keyByteArray[30] = keyByte30;keyByteArray[31] = keyByte31;
	
	inputByteArray = new QLabel*[16];
	inputByteArray[0] = inputByte00;inputByteArray[1] = inputByte01;inputByteArray[2] = inputByte02;inputByteArray[3] = inputByte03;
	inputByteArray[4] = inputByte04;inputByteArray[5] = inputByte05;inputByteArray[6] = inputByte06;inputByteArray[7] = inputByte07;
	inputByteArray[8] = inputByte08;inputByteArray[9] = inputByte09;inputByteArray[10] = inputByte10;inputByteArray[11] = inputByte11;
	inputByteArray[12] = inputByte12;inputByteArray[13] = inputByte13;inputByteArray[14] = inputByte14;inputByteArray[15] = inputByte15;
	
	outputByteArray = new QLabel*[16];
	outputByteArray[0] = outputByte00;outputByteArray[1] = outputByte01;outputByteArray[2] = outputByte02;outputByteArray[3] = outputByte03;
	outputByteArray[4] = outputByte04;outputByteArray[5] = outputByte05;outputByteArray[6] = outputByte06;outputByteArray[7] = outputByte07;
	outputByteArray[8] = outputByte08;outputByteArray[9] = outputByte09;outputByteArray[10] = outputByte10;outputByteArray[11] = outputByte11;
	outputByteArray[12] = outputByte12;outputByteArray[13] = outputByte13;outputByteArray[14] = outputByte14;outputByteArray[15] = outputByte15;

	stateByteArray = new QLabel*[16];
	stateByteArray[0] = stateByte00;stateByteArray[1] = stateByte01;stateByteArray[2] = stateByte02;stateByteArray[3] = stateByte03;
	stateByteArray[4] = stateByte04;stateByteArray[5] = stateByte05;stateByteArray[6] = stateByte06;stateByteArray[7] = stateByte07;
	stateByteArray[8] = stateByte08;stateByteArray[9] = stateByte09;stateByteArray[10] = stateByte10;stateByteArray[11] = stateByte11;
	stateByteArray[12] = stateByte12;stateByteArray[13] = stateByte13;stateByteArray[14] = stateByte14;stateByteArray[15] = stateByte15;
	
	previousByteArray = new QLabel*[16];
	previousByteArray[0] = previousByte00;previousByteArray[1] = previousByte01;previousByteArray[2] = previousByte02;previousByteArray[3] = previousByte03;
	previousByteArray[4] = previousByte04;previousByteArray[5] = previousByte05;previousByteArray[6] = previousByte06;previousByteArray[7] = previousByte07;
	previousByteArray[8] = previousByte08;previousByteArray[9] = previousByte09;previousByteArray[10] = previousByte10;previousByteArray[11] = previousByte11;
	previousByteArray[12] = previousByte12;previousByteArray[13] = previousByte13;previousByteArray[14] = previousByte14;previousByteArray[15] = previousByte15;
	
	nextByteArray = new QLabel*[16];
	nextByteArray[0] = nextByte00;nextByteArray[1] = nextByte01;nextByteArray[2] = nextByte02;nextByteArray[3] = nextByte03;
	nextByteArray[4] = nextByte04;nextByteArray[5] = nextByte05;nextByteArray[6] = nextByte06;nextByteArray[7] = nextByte07;
	nextByteArray[8] = nextByte08;nextByteArray[9] = nextByte09;nextByteArray[10] = nextByte10;nextByteArray[11] = nextByte11;
	nextByteArray[12] = nextByte12;nextByteArray[13] = nextByte13;nextByteArray[14] = nextByte14;nextByteArray[15] = nextByte15;
	/*QSplitter* qs = new QSplitter(this);
	qs->setGeometry(400, 300, 200, 200);
	qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola"));
	qs->setOrientation(Qt::Vertical);
	qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola"));
	qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola"));
	qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola"));*/
	initialized = false;
        Initialize();
}

void MainWindowImpl::paintEvent(QPaintEvent *){

    /*QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    QPainter painter(this);
    QPen pen(Qt::black, 1, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(600, 50, 800, 50);*/

}

void MainWindowImpl::Initialize(){
	//rijn = new Rijndael(rijn->ks_temp);
	inputMatrix = new unsigned char* [4];
	outputMatrix = new unsigned char* [4];
	stateMatrix = new unsigned char* [4];
	previousMatrix = new unsigned char* [4];
	nextMatrix = new unsigned char* [4];
	keyMatrix = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		inputMatrix[i] = new unsigned char [4];
		outputMatrix[i] = new unsigned char [4];
		stateMatrix[i] = new unsigned char [4];
		previousMatrix[i] = new unsigned char [4];
		nextMatrix[i] = new unsigned char [4];
		keyMatrix[i] = new unsigned char [4];
		/*for (int j = 0; j < 4; j++){
			inputMatrix[i][j] = 0x00;
			outputMatrix[i][j] = 0x00;
			stateMatrix[i][j] = 0x00;			
			keyMatrix[i][j] = 0x00;
		}*/
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			keyMatrix[i][j] = i+j*4;
			inputMatrix[i][j] = ((i+j*4)<<4) + (i+j*4);
		}
	}
	calculateMatrices();
	updateAllMatrices();	
}

void hexToUpperCaseText(unsigned char &hex, char* temp_string){
	snprintf(temp_string, 3, "%.2x", hex);
	temp_string[0] = toupper(temp_string[0]);
	temp_string[1] = toupper(temp_string[1]);
}

void MainWindowImpl::updateKeyMatrix(){
        keyByteArray[0]->setGeometry(26, keyByteArray[0]->y(), keyByteArray[0]->width(), keyByteArray[0]->height());
        keyByteArray[1]->setGeometry(26, keyByteArray[1]->y(), keyByteArray[1]->width(), keyByteArray[1]->height());
        keyByteArray[2]->setGeometry(26, keyByteArray[2]->y(), keyByteArray[2]->width(), keyByteArray[2]->height());
        keyByteArray[3]->setGeometry(26, keyByteArray[3]->y(), keyByteArray[3]->width(), keyByteArray[3]->height());
        for (int i = 4; i < 32; i++){
            keyByteArray[i]->setGeometry(keyByteArray[i-4]->x()+24, keyByteArray[i]->y(), keyByteArray[i]->width(), keyByteArray[i]->height());
        }
	switch (rijn->ks_temp){
		case Rijndael::K128:
                        for (int i = 0; i < 16; i++){
                            keyByteArray[i]->setGeometry(keyByteArray[i]->x()+48, keyByteArray[i]->y(), keyByteArray[i]->width(), keyByteArray[i]->height());
                        }
			for (int i = 16; i < 32; i++){
				keyByteArray[i]->setVisible(false);
			}
			break;
		case Rijndael::K192:
                        for (int i = 0; i < 4; i++){
                            for (int j = 0; j < 6; j++){
                                    keyMatrix[i][j] = i+j*4;
                            }
                        }
                        for (int i = 0; i < 24; i++){
                            keyByteArray[i]->setGeometry(keyByteArray[i]->x()+24, keyByteArray[i]->y(), keyByteArray[i]->width(), keyByteArray[i]->height());
                        }
                        for (int i = 0; i < 24; i++){
				keyByteArray[i]->setVisible(true);
			}
			for (int i = 24; i < 32; i++){
				keyByteArray[i]->setVisible(false);
			}
			break;
		case Rijndael::K256:
                        for (int i = 0; i < 4; i++){
                            for (int j = 0; j < 8; j++){
                                    keyMatrix[i][j] = i+j*4;
                            }
                        }
                        for (int i = 0; i < 32; i++){
				keyByteArray[i]->setVisible(true);
			}
			break;
		default:
			break;
	}
	char* temp_string = new char [3];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(keyMatrix[i][j], temp_string);
			keyByteArray[i+j*4]->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateInputMatrix(){
	char* temp_string = new char [3];	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(inputMatrix[i][j], temp_string);
			inputByteArray[i+j*4]->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateOutputMatrix(){
	char* temp_string = new char [3];	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(outputMatrix[i][j], temp_string);
			outputByteArray[i+j*4]->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateStateMatrix(){
	char* temp_string = new char [3];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(stateMatrix[i][j], temp_string);
			stateByteArray[i+j*4]->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updatePreviousMatrix(){
	if (previousDisabled){
		disablePreviousMatrix();		
		buttonPreviousOp->setEnabled(false);
                btnShowPreviousOp->setEnabled(false);
		return;
	}
	else{		
		buttonPreviousOp->setEnabled(true);
                btnShowPreviousOp->setEnabled(true);
	}
	char* temp_string = new char [3];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(previousMatrix[i][j], temp_string);
			previousByteArray[i+j*4]->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateNextMatrix(){
	if (nextDisabled){
		disableNextMatrix();		
		buttonNextOp->setEnabled(false);
                btnShowNextOp->setEnabled(false);
		return;
	}
	else{
		buttonNextOp->setEnabled(true);
                btnShowNextOp->setEnabled(true);
	}
	char* temp_string = new char [3];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(nextMatrix[i][j], temp_string);
			nextByteArray[i+j*4]->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateAllMatrices(){
	updateInputMatrix();
	updateKeyMatrix();
	updateOutputMatrix();
	updateStateMatrix();
	updatePreviousMatrix();
	updateNextMatrix();
	updateRoundAndOp();
}

void MainWindowImpl::disablePreviousMatrix(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			previousByteArray[i+4*j]->setText("--");
		}
	}
        buttonPreviousOp->setEnabled(false);
        btnShowPreviousOp->setEnabled(false);
}

void MainWindowImpl::disableNextMatrix(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			nextByteArray[i+j*4]->setText("--");
		}
	}
	buttonNextOp->setEnabled(false);
        btnShowNextOp->setEnabled(false);
}

void copyMatrix(unsigned char** a, unsigned char** b){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			b[i][j] = a[i][j];
		}
	}
}

void MainWindowImpl::updateRoundAndOp(){
	char* temp = new char[3];
	snprintf(temp, 3, "%d", round);
	labelRoundNumber->setText(temp);
	delete temp;
	switch (op){
                case SB:
                        labelPrevOperationDesc->setText("AddRoundKey");
			labelOperationDesc->setText("SubBytes");
			break;
		case SR:
                        labelPrevOperationDesc->setText("SubBytes");
			labelOperationDesc->setText("ShiftRows");
			break;                        
                case MC:
                        if (round != maxRounds){
                            labelPrevOperationDesc->setText("ShiftRows");
                            labelOperationDesc->setText("MixColumns");
                        }
                        else{
                            labelPrevOperationDesc->setText("AddRoundKey");
                            labelOperationDesc->setText("---");
                        }
			break;
		case ARK:
                        if (round != 0){
                            if (round != maxRounds){
                                 labelPrevOperationDesc->setText("MixColumns");
                            }
                            else{
                                labelPrevOperationDesc->setText("ShiftRows");
                            }
                        }
                        else{
                            labelPrevOperationDesc->setText("---");
                        }
			labelOperationDesc->setText("AddRoundKey");
			break;
	}
}

void MainWindowImpl::calculateMatrices(){
	if (!initialized){
		switch (rijn->ks_temp){
			case Rijndael::K128:
				maxRoundByKey = 10; break;				
			case Rijndael::K192:
				maxRoundByKey = 12; break;				
			case Rijndael::K256:
				maxRoundByKey = 14; break;
		}
		rijn->makeKey(keyMatrix);
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				outputMatrix[i][j] = inputMatrix[i][j];
				stateMatrix[i][j] = inputMatrix[i][j];
				previousMatrix[i][j] = 0x00;
				disablePreviousMatrix();
				nextMatrix[i][j] = inputMatrix[i][j];		
			}
		}		
		round = 0; op = ARK;
		rijn->encryptNRounds(outputMatrix, maxRounds);
		rijn->addNRoundKey(nextMatrix, round);
		initialized = true;
		previousDisabled = true;
		nextDisabled = false;
		return;
	}
	if (round == 0){
		switch (op){
			case SB:
			case SR:
			case MC:
				break;
			case ARK:
				if (forward){					
					copyMatrix(stateMatrix, previousMatrix);
					previousDisabled = false;
					rijn->addNRoundKey(stateMatrix, round);
					rijn->subBytes(nextMatrix);
					op = SB; round++;
				}
				break;
		}		
	}
	else if (round < maxRounds){
		switch (op){
			case SB:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->subBytes(stateMatrix);
					rijn->shiftRows(nextMatrix);
					op = SR;
				}
				else{
					op = ARK; round--;
					copyMatrix(stateMatrix, nextMatrix);
					if (round == 0) previousDisabled = true;
					else rijn->invMixColumns(previousMatrix);
					rijn->addNRoundKey(stateMatrix, round);				
				}
				break;
			case SR:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->shiftRows(stateMatrix);
					rijn->mixColumns(nextMatrix);
					op = MC;
				}
				else{
					copyMatrix(stateMatrix, nextMatrix);
					rijn->invSubBytes(stateMatrix);
					rijn->addNRoundKey(previousMatrix, round-1);
					op = SB;
				}
				break;
			case MC:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->mixColumns(stateMatrix);
					rijn->addNRoundKey(nextMatrix, round);
					op = ARK;
				}
				else{
					copyMatrix(stateMatrix, nextMatrix);
					rijn->invShiftRows(stateMatrix);
					rijn->invSubBytes(previousMatrix);
					op = SR;
				}
				break;
			case ARK:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->addNRoundKey(stateMatrix, round);
					rijn->subBytes(nextMatrix);
					op = SB; round++;
				}
				else{
					copyMatrix(stateMatrix, nextMatrix);
					rijn->invMixColumns(stateMatrix);
					rijn->invShiftRows(previousMatrix);
					op = MC;
				}
				break;
		}
	}
	else if (round == maxRounds && maxRounds == maxRoundByKey){
		switch (op){
			case SB:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->subBytes(stateMatrix);
					rijn->shiftRows(nextMatrix);
					op = SR;
				}
				else{
					round--;
					copyMatrix(stateMatrix, nextMatrix);
					rijn->addNRoundKey(stateMatrix, round);
					rijn->invMixColumns(previousMatrix);
					op = ARK;
				}
				break;
			case SR:
				if (forward){					
					copyMatrix(stateMatrix, previousMatrix);
					rijn->shiftRows(stateMatrix);
					rijn->addNRoundKey(nextMatrix, round);
					op = ARK;
				}
				else{
					copyMatrix(stateMatrix, nextMatrix);
					rijn->invSubBytes(stateMatrix);
					rijn->addNRoundKey(previousMatrix, round-1);
					op = SB;
				}
				break;			
			case ARK:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->addNRoundKey(stateMatrix, round);
					nextDisabled = true;
					op = MC; //round++;
				}
				else{
					copyMatrix(stateMatrix, nextMatrix);
					rijn->invShiftRows(stateMatrix);
					rijn->invSubBytes(previousMatrix);
					op = SR;
				}
				break;
			case MC:
				if (!forward){
					nextDisabled = false;
					copyMatrix(stateMatrix, nextMatrix);
					rijn->addNRoundKey(stateMatrix, round);
					rijn->invShiftRows(previousMatrix);
					op = ARK;
				}
				break;
		}
	}
	else if (round == maxRounds && maxRounds != maxRoundByKey){
		switch (op){
			case SB:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->subBytes(stateMatrix);
					rijn->shiftRows(nextMatrix);
					op = SR;
				}
				else{
					op = ARK; round--;
					copyMatrix(stateMatrix, nextMatrix);
					if (round == 0) previousDisabled = true;
					else rijn->invMixColumns(previousMatrix);
					rijn->addNRoundKey(stateMatrix, round);				
				}
				break;
			case SR:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->shiftRows(stateMatrix);
					rijn->mixColumns(nextMatrix);
					op = MC;
				}
				else{
					copyMatrix(stateMatrix, nextMatrix);
					rijn->invSubBytes(stateMatrix);
					rijn->addNRoundKey(previousMatrix, round-1);
					op = SB;
				}
				break;
			case MC:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->mixColumns(stateMatrix);
					rijn->addNRoundKey(nextMatrix, round);
					op = ARK;
				}
				else{
					copyMatrix(stateMatrix, nextMatrix);
					rijn->invShiftRows(stateMatrix);
					rijn->invSubBytes(previousMatrix);
					op = SR;
				}
				break;
			case ARK:
				if (forward){
					copyMatrix(stateMatrix, previousMatrix);
					rijn->addNRoundKey(stateMatrix, round);
					nextDisabled = true;
					//rijn->subBytes(nextMatrix);
					op = STOP;
				}
				else{					
					copyMatrix(stateMatrix, nextMatrix);
					rijn->invMixColumns(stateMatrix);
					rijn->invShiftRows(previousMatrix);
					op = MC;
				}
				break;
			case STOP:
				if (!forward){
					nextDisabled = false;
					copyMatrix(stateMatrix, nextMatrix);
					rijn->addNRoundKey(stateMatrix, round);
					rijn->invMixColumns(previousMatrix);
					op = ARK;
				}
				break;
		}
	}
	else{
		
	}
}

void MainWindowImpl::on_actionNewRijndael_activated()
{
	DialogNew* dialogNewRijndael = new DialogNew(this); 
	dialogNewRijndael->show();	
}

void MainWindowImpl::on_buttonPreviousOp_pressed()
{
	forward = false;
	calculateMatrices();
	updateStateMatrix();
	updateNextMatrix();
	updatePreviousMatrix();
	updateRoundAndOp();
        MainWindowImpl::update();
}

void MainWindowImpl::on_buttonNextOp_pressed()
{
	forward = true;
	calculateMatrices();
	updateStateMatrix();
	updateNextMatrix();
        updatePreviousMatrix();
	updateRoundAndOp();
        MainWindowImpl::update();
}

void MainWindowImpl::on_buttonFirstOp_pressed()
{
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			stateMatrix[i][j] = inputMatrix[i][j];
			nextMatrix[i][j] = inputMatrix[i][j];
		}
	}	
	op = ARK; round = 0;
	rijn->addNRoundKey(nextMatrix, round);
	previousDisabled = true;
	nextDisabled = false;
	updateStateMatrix();
	updateNextMatrix();
	updatePreviousMatrix();
	updateRoundAndOp();
        MainWindowImpl::update();
}

void MainWindowImpl::on_buttonLastOp_pressed()
{
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){				
			stateMatrix[i][j] = outputMatrix[i][j];			
			previousMatrix[i][j] = outputMatrix[i][j];	
		}
	}
	if (maxRounds == maxRoundByKey)	{
		op = MC; round = maxRounds;
	}
	else {
		op = STOP; round = maxRounds;
	}
	rijn->addNRoundKey(previousMatrix, round);
	previousDisabled = false;
	nextDisabled = true;
	updateNextMatrix();
	updatePreviousMatrix();
	updateStateMatrix();
	updateRoundAndOp();
        MainWindowImpl::update();
}

void MainWindowImpl::on_actionSetInputMatrix_activated()
{
	DialogSetMatrixImpl* dialogSetInput = new DialogSetMatrixImpl(this); 
	dialogSetInput->SetWindowTitle("Set Input Matrix");
	dialogSetInput->SetMatrixType(DialogSetMatrixImpl::Input);
	dialogSetInput->SetMatrixPointer(inputMatrix);
	dialogSetInput->show();
}

void MainWindowImpl::on_actionSetKeyMatrix_activated()
{
	DialogSetMatrixImpl* dialogSetKey = new DialogSetMatrixImpl(this); 
	dialogSetKey->SetWindowTitle("Set Key Matrix");
        dialogSetKey->SetMatrixType(DialogSetMatrixImpl::Key, rijn->ks_temp);
	dialogSetKey->SetMatrixPointer(keyMatrix);
	dialogSetKey->show();
}

void MainWindowImpl::on_btnEditInput_clicked()
{
    on_actionSetInputMatrix_activated();
}

void MainWindowImpl::on_btnEditKey_clicked()
{
    on_actionSetKeyMatrix_activated();
}

void MainWindowImpl::on_btnShowPreviousOp_clicked()
{

}

void MainWindowImpl::on_btnShowNextOp_clicked()
{

}

void MainWindowImpl::on_actionExit_activated()
{
	exit(0);
}
