#include "dialogsetmatriximpl.h"
#include "mainwindowimpl.h"
#include "dialognew.h"

#include "global.h"

#include <QMessageBox>

#include <cstdio>
#include <cstring>

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

        setByteArray[0]->setGeometry(230, setByteArray[0]->y(), setByteArray[0]->width(), setByteArray[0]->height());
        setByteArray[1]->setGeometry(230, setByteArray[1]->y(), setByteArray[1]->width(), setByteArray[1]->height());
        setByteArray[2]->setGeometry(230, setByteArray[2]->y(), setByteArray[2]->width(), setByteArray[2]->height());
        setByteArray[3]->setGeometry(230, setByteArray[3]->y(), setByteArray[3]->width(), setByteArray[3]->height());
        for (int i = 4; i < 32; i++){
            setByteArray[i]->setGeometry(setByteArray[i-4]->x()+30, setByteArray[i]->y(), setByteArray[i]->width(), setByteArray[i]->height());
        }        
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

void DialogSetMatrixImpl::updateModeFromTo(QRadioButton* source){
    editing = true;
    if (source == radioMatrixMode){
        QString hexText = "";
        setHexTextBytes->setText("");
        for (int i = 0; i < 16; i++){
            hexText = hexText + setByteArray[i]->text();
        }
        setHexTextBytes->setText(hexText);
        QString charText = "";
        for (int i = 0; i < 16; i++){
            if (setByteArray[i]->text().length() >= 2){
                charText = charText + char(hexValue(setByteArray[i]->text().at(0).toAscii())*16 + hexValue(setByteArray[i]->text().at(1).toAscii()));
            }
        }
        setCharTextBytes->setText(charText);
    }
    else if (source == radioTextMode){
        for (int i = 0; i < 32; i++){
            setByteArray[i]->setText("");
        }
        QString charText = "";
        QString hexByte = "";
        for (int i = 0; i < setHexTextBytes->text().length(); i=i+2){
            hexByte = setHexTextBytes->text().at(i);
            if (i < setHexTextBytes->text().length()-1){
                charText = charText + char(hexValue(setHexTextBytes->text().at(i).toAscii())*16 + hexValue(setHexTextBytes->text().at(i+1).toAscii()));
                hexByte = hexByte + setHexTextBytes->text().at(i+1);
            }
            else{
                charText = charText + char(hexValue(setHexTextBytes->text().at(i).toAscii())*16);
            }
            setByteArray[i/2]->setText(hexByte);            
        }
        setCharTextBytes->setText(charText);
    }
    else if (source == radioCharTextMode){
        for (int i = 0; i < 32; i++){
            setByteArray[i]->setText("");
        }
        QString hexText = "";
        setHexTextBytes->setText("");
        for (int i = 0; i < setCharTextBytes->text().length(); i++){
            char temp[3];
            qsnprintf(temp, 3, "%.2x", setCharTextBytes->text().at(i));
            temp[0] = toupper(temp[0]);
            temp[1] = toupper(temp[1]);
            hexText = hexText + temp[0];
            hexText = hexText + temp[1];
            setByteArray[i]->setText(temp);
        }
        setHexTextBytes->setText(hexText);
    }
    editing = false;
}

bool DialogSetMatrixImpl::updateTargetMatrix(){
        for (int i = 0; i < 16; i++){
            if (setByteArray[i]->text().length() < 2){
                QMessageBox msgbox; msgbox.setText("Input must be 16 bytes in length"); msgbox.exec();
                return false;
            }
        }
        for (int i = 0; i < 4; i++){
                for (int j = 0; j < 4; j++){
                        targetMatrix[i][j] = hexValue(setByteArray[i+j*4]->text().at(0).toAscii())*16 + hexValue(setByteArray[i+j*4]->text().at(1).toAscii());
                }
        }
        /*if (radioMatrixMode->isChecked()){
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				targetMatrix[i][j] = hexValue(setByteArray[i+j*4]->text().at(0).toAscii())*16 + hexValue(setByteArray[i+j*4]->text().at(1).toAscii());
			}
		}	
	}
	else{
                if (this->type == Key){
                        if (setHexTextBytes->text().length() != rijn->ks_temp/16){
				QMessageBox msgbox; msgbox.setText("no"); msgbox.exec();
				return false;
			}
			else{
				QMessageBox msgbox; msgbox.setText("ok"); msgbox.exec();
			}
		}
		else{
                        if (setHexTextBytes->text().length() != 16){
				QMessageBox msgbox; msgbox.setText("no"); msgbox.exec();
				return false;
			}
			else{
				QMessageBox msgbox; msgbox.setText("ok"); msgbox.exec();
			}
		}
        }*/
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
                        updateModeFromTo(radioMatrixMode);
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
                                        for (int i = 0; i < 16; i++){
                                            setByteArray[i]->setGeometry(setByteArray[i]->x()+60, setByteArray[i]->y(), setByteArray[i]->width(), setByteArray[i]->height());
                                        }
					for (int i = 16; i < 32; i++){
						setByteArray[i]->setVisible(false);
					}							
                                        setHexTextBytes->setMaxLength(32);
                                        setCharTextBytes->setMaxLength(16);
					break;
				case Rijndael::K192:
                                        for (int i = 0; i < 24; i++){
                                            setByteArray[i]->setGeometry(setByteArray[i]->x()+30, setByteArray[i]->y(), setByteArray[i]->width(), setByteArray[i]->height());
                                        }
					for (int i = 16; i < 24; i++){
						setByteArray[i]->setVisible(true);
					}		
					for (int i = 24; i < 32; i++){
						setByteArray[i]->setVisible(false);
					}		
                                        setHexTextBytes->setMaxLength(48);
                                        setCharTextBytes->setMaxLength(24);
					break;
				case Rijndael::K256:
					for (int i = 16; i < 32; i++){
						setByteArray[i]->setVisible(true);
					}			
                                        setHexTextBytes->setMaxLength(64);
                                        setCharTextBytes->setMaxLength(32);
					break;
				default:
					break;
			}
			break;
		case Input:
			targetMatrix = inputMatrix;
                        for (int i = 0; i < 16; i++){
                            setByteArray[i]->setGeometry(setByteArray[i]->x()+60, setByteArray[i]->y(), setByteArray[i]->width(), setByteArray[i]->height());
                        }
			for (int i = 16; i < 32; i++){
						setByteArray[i]->setVisible(false);
					}		
                        setHexTextBytes->setMaxLength(32);
                        setCharTextBytes->setMaxLength(16);
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
        setHexTextBytes->setEnabled( false );
        setCharTextBytes->setEnabled(false);
}

void DialogSetMatrixImpl::on_radioTextMode_clicked()
{
	QList<QLineEdit*> list = this->findChildren<QLineEdit*>() ;
	foreach( QLineEdit* l, list )
	{
		l->setEnabled( false ) ;
	}
        setHexTextBytes->setEnabled( true );
        setCharTextBytes->setEnabled(false);
}

void DialogSetMatrixImpl::on_radioCharTextMode_clicked()
{
        QList<QLineEdit*> list = this->findChildren<QLineEdit*>() ;
        foreach( QLineEdit* l, list )
        {
                l->setEnabled( false ) ;
        }
        setHexTextBytes->setEnabled( false );
        setCharTextBytes->setEnabled(true);
}


void DialogSetMatrixImpl::on_setByte00_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte00->setText(text);
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte01_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte01->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte02_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte02->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte03_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte03->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte07_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte07->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte04_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte04->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte05_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte05->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte06_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte06->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte08_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);    
    setByte08->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte09_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);    
    setByte09->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte10_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte10->setText(text.toUpper());
   if (!editing)  updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte11_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte11->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte12_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte12->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte13_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte13->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte14_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte14->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte15_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte15->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte16_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte16->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte17_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte17->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte18_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte18->setText(text.toUpper());
    if (!editing)  updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte19_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte19->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte20_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte20->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte21_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte21->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte22_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte22->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte23_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte23->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte24_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte24->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte25_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte25->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte26_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte26->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte27_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte27->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte28_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte28->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte29_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte29->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte30_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);    
    setByte30->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setByte31_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setByte31->setText(text.toUpper());
    if (!editing)  updateModeFromTo(radioMatrixMode);
}

void DialogSetMatrixImpl::on_setHexTextBytes_textChanged(QString text)
{
    text = text.toUpper();
    for (int i = 0; i < text.length(); i++)
        if (text.at(i).toAscii() < 48 || (text.at(i).toAscii() > 57 && text.at(i).toAscii() < 65) || text.at(i).toAscii() > 70)
            text.remove(i, 1);
    setHexTextBytes->setText(text.toUpper());
    if (!editing) updateModeFromTo(radioTextMode);
}

void DialogSetMatrixImpl::on_setCharTextBytes_textChanged(QString )
{
    if (!editing) updateModeFromTo(radioCharTextMode);
}
