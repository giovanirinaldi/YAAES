#include <cstdio>

#include "mainwindowimpl.h"
#include "dialognew.h"
#include "dialogsetmatrix.h"
#include "dialogshowexpkey.h"
#include "dialogaddroundkey.h"
#include "dialogshiftrows.h"
#include "dialogsubbytes.h"
#include "dialogmixcolumns.h"
#include "dialogexport.h"
#include "dialogabout.h"

#ifndef EXTERN
#undef EXTERN
#define EXTERN  
#endif

#include "src/global.h"

MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
        : QMainWindow(parent, f)
{
        setupUi(this);
       // rijn = new FastRijndael(FastRijndael::K128);
        ks_temp = FastRijndael::K128;
	maxRounds = 10;
        maxRoundByKey = 10;
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

	initialized = false;
        Initialize();
}

void MainWindowImpl::Initialize(){
        rijn = new FastRijndael(ks_temp);
        if (!initialized){
            //rijn = new FastRijndael(rijn->ks_temp);
            inputMatrix = new unsigned char [rijn->getBlockSizeInBytes()];
            outputMatrix = new unsigned char [rijn->getBlockSizeInBytes()];
            stateMatrix = new unsigned char [rijn->getBlockSizeInBytes()];
            previousMatrix = new unsigned char [rijn->getBlockSizeInBytes()];
            nextMatrix = new unsigned char [rijn->getBlockSizeInBytes()];
            keyMatrix = new unsigned char [rijn->getKeySizeInBytes()];
        }

        for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
            inputMatrix[i] = ((i)<<4) + (i);
        }

        for (int i = 0; i < rijn->getKeySizeInBytes(); i++){
            keyMatrix[i] = i;
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
        btnShowKey->setVisible(false);
        btnShowNextOp->setVisible(false);
        btnShowPreviousOp->setVisible(false);
        switch (rijn->getKeySize()){
                case FastRijndael::K128:
                        for (int i = 0; i < 16; i++){
                            keyByteArray[i]->setGeometry(keyByteArray[i]->x()+48, keyByteArray[i]->y(), keyByteArray[i]->width(), keyByteArray[i]->height());
                        }
			for (int i = 16; i < 32; i++){
				keyByteArray[i]->setVisible(false);
			}
                        btnShowKey->setVisible(true);
                        btnShowNextOp->setVisible(true);
                        btnShowPreviousOp->setVisible(true);
			break;
                case FastRijndael::K192:
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
                case FastRijndael::K256:
                        for (int i = 0; i < 32; i++){
				keyByteArray[i]->setVisible(true);
                        }
			break;
		default:
			break;
	}
	char* temp_string = new char [3];
        for (int i = 0; i < rijn->getKeySizeInBytes(); i++){
            hexToUpperCaseText(keyMatrix[i], temp_string);
            keyByteArray[i]->setText(temp_string);
	}
        delete[] temp_string;
}

void MainWindowImpl::updateInputMatrix(){
	char* temp_string = new char [3];	
        for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
            hexToUpperCaseText(inputMatrix[i], temp_string);
            inputByteArray[i]->setText(temp_string);
	}
        delete[] temp_string;
}

void MainWindowImpl::updateOutputMatrix(){
	char* temp_string = new char [3];	
        for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
            hexToUpperCaseText(outputMatrix[i], temp_string);
            outputByteArray[i]->setText(temp_string);
	}
        delete[] temp_string;
}

void MainWindowImpl::updateStateMatrix(){
	char* temp_string = new char [3];
        for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
            hexToUpperCaseText(stateMatrix[i], temp_string);
            stateByteArray[i]->setText(temp_string);
	}
        delete[] temp_string;
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
                labelArrowOp->setVisible(true);
	}
	char* temp_string = new char [3];
        for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
            hexToUpperCaseText(previousMatrix[i], temp_string);
            previousByteArray[i]->setText(temp_string);
	}
        delete[] temp_string;
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
                labelArrowNextOp->setVisible(true);
	}
        char* temp_string = new char [3];
        for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
            hexToUpperCaseText(nextMatrix[i], temp_string);
            nextByteArray[i]->setText(temp_string);
	}
        delete[] temp_string;
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
        labelArrowOp->setVisible(false);

}

void MainWindowImpl::disableNextMatrix(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			nextByteArray[i+j*4]->setText("--");
		}
	}
	buttonNextOp->setEnabled(false);
        btnShowNextOp->setEnabled(false);
        labelArrowNextOp->setVisible(false);
}

void copyMatrix(unsigned char* a, unsigned char* b, int size){
        for (int i = 0; i < size; i++){
            b[i] = a[i];
        }
}

void MainWindowImpl::updateRoundAndOp(){
	char* temp = new char[3];
	snprintf(temp, 3, "%d", round);
	labelRoundNumber->setText(temp);
        delete[] temp;
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
                            if (maxRounds == maxRoundByKey){
                                labelPrevOperationDesc->setText("AddRoundKey");
                                labelOperationDesc->setText("---");
                            }
                            else{
                                labelPrevOperationDesc->setText("ShiftRows");
                                labelOperationDesc->setText("MixColumns");
                            }
                        }
			break;
                case ARK:
                        if (round != 0){
                            if (round != maxRounds){
                                 labelPrevOperationDesc->setText("MixColumns");
                            }
                            else{
                                if (maxRounds == maxRoundByKey){
                                    labelPrevOperationDesc->setText("ShiftRows");
                                }
                                else{
                                    labelPrevOperationDesc->setText("MixColumns");
                                }
                            }
                        }
                        else{
                            labelPrevOperationDesc->setText("---");
                        }
                        labelOperationDesc->setText("AddRoundKey");
			break;
                case STOP:
                        labelPrevOperationDesc->setText("AddRoundKey");
                        labelOperationDesc->setText("---");
                        break;
        }
        fflush(stdout);
}

void MainWindowImpl::calculateMatrices(){
        if (!initialized){
                switch (ks_temp){
                        case FastRijndael::K128:
				maxRoundByKey = 10; break;				
                        case FastRijndael::K192:
				maxRoundByKey = 12; break;				
                        case FastRijndael::K256:
				maxRoundByKey = 14; break;
		}
		rijn->makeKey(keyMatrix);
                for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
                    outputMatrix[i] = inputMatrix[i];
                    stateMatrix[i] = inputMatrix[i];
                    nextMatrix[i] = inputMatrix[i];
                    previousMatrix[i] = 0x00;
                }
                disablePreviousMatrix();

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
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					previousDisabled = false;
					rijn->addNRoundKey(stateMatrix, round);
					rijn->subBytes(nextMatrix);
					op = SB; round++;
				}
				break;
                        case STOP:
                            break;
		}		
	}
	else if (round < maxRounds){
		switch (op){
			case SB:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->subBytes(stateMatrix);
					rijn->shiftRows(nextMatrix);
					op = SR;
				}
				else{
                                        op = ARK; round--;
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					if (round == 0) previousDisabled = true;
					else rijn->invMixColumns(previousMatrix);
					rijn->addNRoundKey(stateMatrix, round);				
				}
				break;
			case SR:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->shiftRows(stateMatrix);
					rijn->mixColumns(nextMatrix);
					op = MC;
				}
				else{
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->invSubBytes(stateMatrix);
					rijn->addNRoundKey(previousMatrix, round-1);
					op = SB;
				}
				break;
			case MC:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->mixColumns(stateMatrix);
					rijn->addNRoundKey(nextMatrix, round);
					op = ARK;
				}
				else{
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->invShiftRows(stateMatrix);
					rijn->invSubBytes(previousMatrix);
					op = SR;
				}
				break;
			case ARK:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->addNRoundKey(stateMatrix, round);
					rijn->subBytes(nextMatrix);
					op = SB; round++;
				}
				else{
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->invMixColumns(stateMatrix);
					rijn->invShiftRows(previousMatrix);
					op = MC;
				}
				break;
                        case STOP:
                            break;
		}
	}
	else if (round == maxRounds && maxRounds == maxRoundByKey){
		switch (op){
			case SB:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->subBytes(stateMatrix);
					rijn->shiftRows(nextMatrix);
					op = SR;
				}
				else{
					round--;
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->addNRoundKey(stateMatrix, round);
					rijn->invMixColumns(previousMatrix);
					op = ARK;
				}
				break;
			case SR:
				if (forward){					
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->shiftRows(stateMatrix);
					rijn->addNRoundKey(nextMatrix, round);
					op = ARK;
				}
				else{
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->invSubBytes(stateMatrix);
					rijn->addNRoundKey(previousMatrix, round-1);
					op = SB;
				}
				break;			
			case ARK:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->addNRoundKey(stateMatrix, round);
					nextDisabled = true;
					op = MC; //round++;
				}
				else{
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->invShiftRows(stateMatrix);
					rijn->invSubBytes(previousMatrix);
					op = SR;
				}
				break;
			case MC:
				if (!forward){
					nextDisabled = false;
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->addNRoundKey(stateMatrix, round);
					rijn->invShiftRows(previousMatrix);
					op = ARK;
				}
				break;
                        case STOP:
                            break;
		}
	}
	else if (round == maxRounds && maxRounds != maxRoundByKey){
		switch (op){
			case SB:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->subBytes(stateMatrix);
					rijn->shiftRows(nextMatrix);
					op = SR;
				}
				else{
					op = ARK; round--;
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					if (round == 0) previousDisabled = true;
					else rijn->invMixColumns(previousMatrix);
					rijn->addNRoundKey(stateMatrix, round);				
				}
				break;
			case SR:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->shiftRows(stateMatrix);
					rijn->mixColumns(nextMatrix);
					op = MC;
				}
				else{
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->invSubBytes(stateMatrix);
					rijn->addNRoundKey(previousMatrix, round-1);
					op = SB;
				}
				break;
			case MC:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->mixColumns(stateMatrix);
					rijn->addNRoundKey(nextMatrix, round);
					op = ARK;
				}
				else{
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->invShiftRows(stateMatrix);
					rijn->invSubBytes(previousMatrix);
					op = SR;
				}
				break;
			case ARK:
				if (forward){
                                        copyMatrix(stateMatrix, previousMatrix, rijn->getBlockSizeInBytes());
					rijn->addNRoundKey(stateMatrix, round);
					nextDisabled = true;
					//rijn->subBytes(nextMatrix);
					op = STOP;
				}
				else{					
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
					rijn->invMixColumns(stateMatrix);
					rijn->invShiftRows(previousMatrix);
					op = MC;
				}
				break;
			case STOP:
				if (!forward){
					nextDisabled = false;
                                        copyMatrix(stateMatrix, nextMatrix, rijn->getBlockSizeInBytes());
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
        for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
            stateMatrix[i] = inputMatrix[i];
            nextMatrix[i] = inputMatrix[i];
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
        for (int i = 0; i < rijn->getBlockSizeInBytes(); i++){
            stateMatrix[i] = outputMatrix[i];
            previousMatrix[i] = outputMatrix[i];
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
        dialogSetKey->SetMatrixType(DialogSetMatrixImpl::Key, rijn->getKeySize());
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
    switch (previousOp){
        case ARK:
            {
                unsigned char* temp_exp_key = new unsigned char [rijn->getExpKeySizeInBytes()];
                rijn->getExpKey(temp_exp_key);
                DialogAddRoundKey* dialogARK = new DialogAddRoundKey(this);
                dialogARK->setStateMatrix(previousMatrix);
                dialogARK->setSubKeyMatrix(temp_exp_key+16*round);
                dialogARK->updateMatrix();
                dialogARK->show();
                delete[] temp_exp_key;
            }
            break;
        case SR:
            {
                DialogShiftRows* dialogSR = new DialogShiftRows(this);
                dialogSR->setStateMatrix(previousMatrix);
                dialogSR->updateMatrix();
                dialogSR->show();
                break;
            }
        case SB:
            {
                DialogSubBytes* dialogSB = new DialogSubBytes(this);
                dialogSB->setStateMatrix(previousMatrix);
                dialogSB->updateMatrix();
                dialogSB->show();
                break;
            }
            break;
        case MC:
            {
                DialogMixColumns* dialogMC = new DialogMixColumns(this);
                dialogMC->setStateMatrix(previousMatrix);
                dialogMC->updateMatrix();
                dialogMC->show();
                break;
            }
            break;
        case STOP:
            {
                break;
            }

    }
}

void MainWindowImpl::on_btnShowNextOp_clicked()
{
    switch (op){
        case ARK:
            {
                unsigned char* temp_exp_key = new unsigned char [rijn->getExpKeySizeInBytes()];
                rijn->getExpKey(temp_exp_key);
                DialogAddRoundKey* dialogARK = new DialogAddRoundKey(this);
                dialogARK->setStateMatrix(stateMatrix);
                dialogARK->setSubKeyMatrix(temp_exp_key+16*round);
                dialogARK->updateMatrix();
                dialogARK->show();
                delete[] temp_exp_key;
            }
            break;
        case SR:
            {
                DialogShiftRows* dialogSR = new DialogShiftRows(this);
                dialogSR->setStateMatrix(stateMatrix);
                dialogSR->updateMatrix();
                dialogSR->show();
                break;
            }
        case SB:
            {
                DialogSubBytes* dialogSB = new DialogSubBytes(this);
                dialogSB->setStateMatrix(stateMatrix);
                dialogSB->updateMatrix();
                dialogSB->show();
                break;
            }
            break;
        case MC:
            {
                DialogMixColumns* dialogMC = new DialogMixColumns(this);
                dialogMC->setStateMatrix(stateMatrix);
                dialogMC->updateMatrix();
                dialogMC->show();
                break;
            }
            break;
        case STOP:
            {
                break;
            }
    }
}

void MainWindowImpl::on_actionExit_activated()
{
        rijn->cleanUp();
	exit(0);
}

void MainWindowImpl::on_btnShowKey_clicked()
{
    unsigned char* tempExpKey = new unsigned char [rijn->getExpKeySizeInBytes()];
    rijn->getExpKey(tempExpKey);
    DialogShowExpKey* dialogShowExpKey = new DialogShowExpKey(this);
    dialogShowExpKey->SetKeySize(rijn->getKeySize(), rijn->getNumberColumnsExpKey());
    dialogShowExpKey->SetExpKeyMatrixPointer(tempExpKey);
    dialogShowExpKey->show();
}

void MainWindowImpl::on_actionExport_triggered()
{
    DialogExport* dialogExport = new DialogExport(this);
    dialogExport->setPlaintext(inputMatrix);
    dialogExport->setCiphertext(outputMatrix);
    dialogExport->update();
    dialogExport->show();
}

void MainWindowImpl::on_actionAbout_triggered()
{
    DialogAbout* dialogAbout = new DialogAbout(this);
    dialogAbout->show();
}
