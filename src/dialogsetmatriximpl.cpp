#include "dialogsetmatriximpl.h"
#include "mainwindowimpl.h"
#include "dialognew.h"

#include "global.h"

#include <QMessageBox>

#include <cstdio>

DialogSetMatrixImpl::DialogSetMatrixImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	radioMatrixMode->click();
	setByteArray = new QLineEdit* [32];
	setByteArray[0] = setByte00;setByteArray[1] = setByte01;setByteArray[2] = setByte02;setByteArray[3] = setByte03;
	setByteArray[4] = setByte04;setByteArray[5] = setByte05;setByteArray[6] = setByte06;setByteArray[7] = setByte07;
	setByteArray[8] = setByte08;setByteArray[9] = setByte09;setByteArray[10] = setByte10;setByteArray[11] = setByte11;
	setByteArray[12] = setByte12;setByteArray[13] = setByte13;setByteArray[14] = setByte14;setByteArray[15] = setByte15;
	setByteArray[16] = setByte16;setByteArray[17] = setByte17;setByteArray[18] = setByte18;setByteArray[19] = setByte19;
	setByteArray[20] = setByte20;setByteArray[21] = setByte21;setByteArray[22] = setByte22;setByteArray[23] = setByte23;
	setByteArray[24] = setByte24;setByteArray[25] = setByte25;setByteArray[26] = setByte26;setByteArray[27] = setByte27;
	setByteArray[28] = setByte28;setByteArray[29] = setByte29;setByteArray[30] = setByte30;setByteArray[31] = setByte31;	
}

unsigned char hexValue(unsigned char hex){
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

bool DialogSetMatrixImpl::updateTargetMatrix(){
	if (radioMatrixMode->isChecked()){
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				targetMatrix[i][j] = hexValue(setByteArray[i+j*4]->text().at(0).toAscii())*16 + hexValue(setByteArray[i+j*4]->text().at(1).toAscii());
			}
		}	
	}
	else{
		if (this->type == Key){
			if (setTextBytes->text().length() != rijn->ks_temp/16){
				QMessageBox msgbox; msgbox.setText("no"); msgbox.exec();
				return false;
			}
			else{
				QMessageBox msgbox; msgbox.setText("ok"); msgbox.exec();
			}
		}
		else{
			if (setTextBytes->text().length() != 16){
				QMessageBox msgbox; msgbox.setText("no"); msgbox.exec();
				return false;
			}
			else{
				QMessageBox msgbox; msgbox.setText("ok"); msgbox.exec();
			}
		}
	}
	return true;
}

void DialogSetMatrixImpl::SetWindowTitle(QString title)
{
	this->setWindowTitle(title);
}

void DialogSetMatrixImpl::SetMatrixPointer(unsigned char ** matrix){
	this->targetMatrix = matrix;
	char* temp = new char[3];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){			
			snprintf(temp, 3, "%.2x", targetMatrix[i][j]);
			temp[0] = toupper(temp[0]); temp[1] = toupper(temp[1]);
			setByteArray[i+j*4]->setText(temp);
		}
	}
	delete temp;
}

void DialogSetMatrixImpl::SetMatrixType(MatrixType type, Rijndael::KeySize keySize)
{
	this->type = type;
	switch (type){
		case Key:			
			targetMatrix = keyMatrix;
			switch (keySize){
				case Rijndael::K128:
					for (int i = 16; i < 32; i++){
						setByteArray[i]->setVisible(false);
					}							
					setTextBytes->setMaxLength(16);	
					break;
				case Rijndael::K192:
					for (int i = 16; i < 24; i++){
						setByteArray[i]->setVisible(true);
					}		
					for (int i = 24; i < 32; i++){
						setByteArray[i]->setVisible(false);
					}		
					setTextBytes->setMaxLength(24);	
					break;
				case Rijndael::K256:
					for (int i = 16; i < 32; i++){
						setByteArray[i]->setVisible(true);
					}			
					setTextBytes->setMaxLength(32);
					break;
				default:
					break;
			}
			break;
		case Input:
			targetMatrix = inputMatrix;
			for (int i = 16; i < 32; i++){
						setByteArray[i]->setVisible(false);
					}		
			setTextBytes->setMaxLength(16);	
			break;
		default:
			break;
	};
}

void DialogSetMatrixImpl::on_buttonBox_clicked(QAbstractButton* button)
{
	if (QString::compare(button->text(),"&ok", Qt::CaseInsensitive) == 0){
		if (!updateTargetMatrix()) return;
		MainWindowImpl* parent_main = qobject_cast<MainWindowImpl*>(this->parent());
		if (parent_main != NULL){	
			parent_main->initialized = false;
			parent_main->calculateMatrices();
			parent_main->updateAllMatrices();
		}		
		this->close();
	}
	else if (QString::compare(button->text(), "&cancel", Qt::CaseInsensitive) == 0){
		this->close();
	}
	else{
	}
}

void DialogSetMatrixImpl::on_radioMatrixMode_clicked()
{
	QList<QLineEdit*> list = this->findChildren<QLineEdit*>() ;
	foreach( QLineEdit* l, list )
	{
		l->setEnabled( true ) ;
	}
	setTextBytes->setEnabled( false );
}

void DialogSetMatrixImpl::on_radioTextMode_clicked()
{
	QList<QLineEdit*> list = this->findChildren<QLineEdit*>() ;
	foreach( QLineEdit* l, list )
	{
		l->setEnabled( false ) ;
	}
	setTextBytes->setEnabled( true );
}
