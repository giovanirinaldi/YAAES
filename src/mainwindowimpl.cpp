#include <cstdio>

#include "mainwindowimpl.h"
#include "dialognew.h"
#include "dialogsetmatriximpl.h"

#ifndef EXTERN
#undef EXTERN
#define EXTERN  
#endif

#include "global.h"
#include <QSplitter>
#include <QMessageBox>

MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);	
	rijn = new Rijndael(Rijndael::K128);
	rijn->ks_temp = Rijndael::K128;
	
	/*QSplitter* qs = new QSplitter(this);
	qs->setGeometry(400, 300, 200, 200);
	qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola"));
	qs->setOrientation(Qt::Vertical);
	qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola"));
	qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola"));
	qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola")); qs->addWidget(new QLabel("ola"));*/
		
	Initialize();	
}

void MainWindowImpl::Initialize(){
	//rijn = new Rijndael(rijn->ks_temp);
	inputMatrix = new unsigned char* [4];
	outputMatrix = new unsigned char* [4];
	stateMatrix = new unsigned char* [4];
	keyMatrix = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		inputMatrix[i] = new unsigned char [4];
		outputMatrix[i] = new unsigned char [4];
		stateMatrix[i] = new unsigned char [4];
		keyMatrix[i] = new unsigned char [4];
		for (int j = 0; j < 4; j++){
			inputMatrix[i][j] = 0x00;
			outputMatrix[i][j] = 0x00;
			stateMatrix[i][j] = 0x00;			
			keyMatrix[i][j] = 0x00;
		}
	}
	
	updateAllMatrices();
}

void hexToUpperCaseText(unsigned char &hex, char* temp_string){
	snprintf(temp_string, 3, "%.2x", hex);
	temp_string[0] = toupper(temp_string[0]);
	temp_string[1] = toupper(temp_string[1]);
}

void MainWindowImpl::updateKeyMatrix(){
	switch (rijn->ks_temp){
		case Rijndael::K128:
			keyByte16->setVisible(false);
			keyByte17->setVisible(false);
			keyByte18->setVisible(false);
			keyByte19->setVisible(false);
			keyByte20->setVisible(false);
			keyByte21->setVisible(false);
			keyByte22->setVisible(false);
			keyByte23->setVisible(false);	
			keyByte24->setVisible(false);
			keyByte25->setVisible(false);
			keyByte26->setVisible(false);
			keyByte27->setVisible(false);
			keyByte28->setVisible(false);
			keyByte29->setVisible(false);
			keyByte30->setVisible(false);
			keyByte31->setVisible(false);
			break;
		case Rijndael::K192:
			keyByte16->setVisible(true);
			keyByte17->setVisible(true);
			keyByte18->setVisible(true);
			keyByte19->setVisible(true);
			keyByte20->setVisible(true);
			keyByte21->setVisible(true);
			keyByte22->setVisible(true);
			keyByte23->setVisible(true);	
			keyByte24->setVisible(false);
			keyByte25->setVisible(false);
			keyByte26->setVisible(false);
			keyByte27->setVisible(false);
			keyByte28->setVisible(false);
			keyByte29->setVisible(false);
			keyByte30->setVisible(false);
			keyByte31->setVisible(false);	
			break;
		case Rijndael::K256:
			keyByte16->setVisible(true);
			keyByte17->setVisible(true);
			keyByte18->setVisible(true);
			keyByte19->setVisible(true);
			keyByte20->setVisible(true);
			keyByte21->setVisible(true);
			keyByte22->setVisible(true);
			keyByte23->setVisible(true);	
			keyByte24->setVisible(true);
			keyByte25->setVisible(true);
			keyByte26->setVisible(true);
			keyByte27->setVisible(true);
			keyByte28->setVisible(true);
			keyByte29->setVisible(true);
			keyByte30->setVisible(true);
			keyByte31->setVisible(true);	
			break;
		default:
			break;
	}
	char* temp_string = new char [3];
	QRegExp regex("(keyByte)(([0][0-9])|([1][0-5]))");
	QList<QLabel*> list = this->findChildren<QLabel*>(regex);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(keyMatrix[i][j], temp_string);
			list.at(i+j*4)->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateInputMatrix(){
	char* temp_string = new char [3];
	QRegExp regex("(inputByte)(([0][0-9])|([1][0-5]))");
	QList<QLabel*> list = this->findChildren<QLabel*>(regex);	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(inputMatrix[i][j], temp_string);
			list.at(i+j*4)->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateOutputMatrix(){
	char* temp_string = new char [3];
	QRegExp regex("(outputByte)(([0][0-9])|([1][0-5]))");
	QList<QLabel*> list = this->findChildren<QLabel*>(regex);	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(outputMatrix[i][j], temp_string);
			list.at(i+j*4)->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateStateMatrix(){
	char* temp_string = new char [3];
	QRegExp regex("(stateByte)(([0][0-9])|([1][0-5]))");
	QList<QLabel*> list = this->findChildren<QLabel*>(regex);	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			hexToUpperCaseText(stateMatrix[i][j], temp_string);
			list.at(i+j*4)->setText(temp_string);
		}
	}
	delete temp_string;
}

void MainWindowImpl::updateAllMatrices(){
	updateInputMatrix();
	updateKeyMatrix();
	updateOutputMatrix();
	updateStateMatrix();
}

/*int MainWindowImpl::getRound(){
	return this->round;
}

void MainWindowImpl::setRound(int round){
	this->round = round;
}

int MainWindowImpl::getMaxRounds(){
	return this->maxRounds;
}

void MainWindowImpl::setMaxRounds(int maxRounds){
	this->maxRounds = maxRounds;
}*/

void MainWindowImpl::on_actionNewRijndael_activated()
{
	DialogNew* dialogNewRijndael = new DialogNew(this); 
	dialogNewRijndael->show();	
}

void MainWindowImpl::on_buttonBackOp_pressed()
{
	// TODO
}

void MainWindowImpl::on_buttonNextOp_pressed()
{
	// TODO
	
}

void MainWindowImpl::on_buttonFirstOp_pressed()
{
	// TODO
}

void MainWindowImpl::on_buttonLastOp_pressed()
{
	// TODO
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

void MainWindowImpl::on_actionExit_activated()
{
	exit(0);
}
