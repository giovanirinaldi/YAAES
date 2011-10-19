#include "dialognew.h"

#include "mainwindowimpl.h"
#include "global.h"

DialogNew::DialogNew( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	radioKey128->click();
	rijn->ks_temp = Rijndael::K128;
}

void DialogNew::on_buttonBox_clicked(QAbstractButton* button)
{
	if (QString::compare(button->text(),"&ok", Qt::CaseInsensitive) == 0){
		MainWindowImpl* p = (MainWindowImpl*)(this->parent());
		p->setMaxRounds(spinBoxNumberRounds->value());		
		this->close();
	}
	else if (QString::compare(button->text(), "&cancel", Qt::CaseInsensitive) == 0){
		this->close();
	}
	else{
	}
}

void DialogNew::on_radioKey128_clicked()
{
	spinBoxNumberRounds->setMaximum(10);
	rijn->ks_temp = Rijndael::K128;	
}

void DialogNew::on_radioKey192_clicked()
{
	spinBoxNumberRounds->setMaximum(12);
	rijn->ks_temp = Rijndael::K192;
}

void DialogNew::on_radioKey256_clicked()
{
	spinBoxNumberRounds->setMaximum(14);
	rijn->ks_temp = Rijndael::K256;
}

void DialogNew::on_buttonSetInput_clicked()
{	
	MainWindowImpl* p = (MainWindowImpl*)(this->parent());
	p->on_actionSetInputMatrix_activated();
}

void DialogNew::on_buttonSetKey_clicked()
{
	MainWindowImpl* p = (MainWindowImpl*)(this->parent());
	p->on_actionSetKeyMatrix_activated();
}
