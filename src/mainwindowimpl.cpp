#include "mainwindowimpl.h"

MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);	
	rijn = new Rijndael(Rijndael::K128);
}

int MainWindowImpl::getRound(){
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
}

void MainWindowImpl::on_actionNewRijndael_activated()
{
	DialogNew* dialogNewRijndael = new DialogNew(); 
	//dialogSetInput->SetWindowTitle("Set Input Matrix");
	//dialogSetInput->SetMatrixType(DialogSetMatrixImpl::Input);
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
	dialogSetInput->show();
}

void MainWindowImpl::on_actionSetKeyMatrix_activated()
{
	DialogSetMatrixImpl* dialogSetKey = new DialogSetMatrixImpl(this); 
	dialogSetKey->SetWindowTitle("Set Key Matrix");
	dialogSetKey->SetMatrixType(DialogSetMatrixImpl::Key, rijn->ks_temp);
	dialogSetKey->show();
}

void MainWindowImpl::on_actionExit_activated()
{
	exit(0);
}
