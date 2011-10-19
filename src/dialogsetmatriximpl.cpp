#include "dialogsetmatriximpl.h"

#include "global.h"

DialogSetMatrixImpl::DialogSetMatrixImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	radioMatrixMode->click();	
}

void DialogSetMatrixImpl::SetWindowTitle(QString title)
{
	this->setWindowTitle(title);
}

void DialogSetMatrixImpl::SetMatrixPointer(unsigned char ** matrix){
	this->targetMatrix = matrix;
}

void DialogSetMatrixImpl::SetMatrixType(MatrixType type, Rijndael::KeySize keySize)
{
	switch (type){
		case Key:
			switch (keySize){
				case Rijndael::K128:
					setByte16->setVisible(false);
					setByte17->setVisible(false);
					setByte18->setVisible(false);
					setByte19->setVisible(false);
					setByte20->setVisible(false);
					setByte21->setVisible(false);
					setByte22->setVisible(false);
					setByte23->setVisible(false);	
					setByte24->setVisible(false);
					setByte25->setVisible(false);
					setByte26->setVisible(false);
					setByte27->setVisible(false);
					setByte28->setVisible(false);
					setByte29->setVisible(false);
					setByte30->setVisible(false);
					setByte31->setVisible(false);			
					setTextBytes->setMaxLength(16);	
					break;
				case Rijndael::K192:
					setByte16->setVisible(true);
					setByte17->setVisible(true);
					setByte18->setVisible(true);
					setByte19->setVisible(true);
					setByte20->setVisible(true);
					setByte21->setVisible(true);
					setByte22->setVisible(true);
					setByte23->setVisible(true);	
					setByte24->setVisible(false);
					setByte25->setVisible(false);
					setByte26->setVisible(false);
					setByte27->setVisible(false);
					setByte28->setVisible(false);
					setByte29->setVisible(false);
					setByte30->setVisible(false);
					setByte31->setVisible(false);	
					setTextBytes->setMaxLength(24);	
					break;
				case Rijndael::K256:
					setByte16->setVisible(true);
					setByte17->setVisible(true);
					setByte18->setVisible(true);
					setByte19->setVisible(true);
					setByte20->setVisible(true);
					setByte21->setVisible(true);
					setByte22->setVisible(true);
					setByte23->setVisible(true);	
					setByte24->setVisible(true);
					setByte25->setVisible(true);
					setByte26->setVisible(true);
					setByte27->setVisible(true);
					setByte28->setVisible(true);
					setByte29->setVisible(true);
					setByte30->setVisible(true);
					setByte31->setVisible(true);	
					setTextBytes->setMaxLength(32);
					break;
				default:
					break;
			}
			break;
		case Input:
			setByte16->setVisible(false);
			setByte17->setVisible(false);
			setByte18->setVisible(false);
			setByte19->setVisible(false);
			setByte20->setVisible(false);
			setByte21->setVisible(false);
			setByte22->setVisible(false);
			setByte23->setVisible(false);	
			setByte24->setVisible(false);
			setByte25->setVisible(false);
			setByte26->setVisible(false);
			setByte27->setVisible(false);
			setByte28->setVisible(false);
			setByte29->setVisible(false);
			setByte30->setVisible(false);
			setByte31->setVisible(false);		
			setTextBytes->setMaxLength(16);	
			break;
		default:
			break;
	};
}

void DialogSetMatrixImpl::on_buttonBox_clicked(QAbstractButton* button)
{
	if (QString::compare(button->text(),"&ok", Qt::CaseInsensitive) == 0){
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
