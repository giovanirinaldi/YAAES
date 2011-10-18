#include "dialognew.h"

DialogNew::DialogNew( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	radioKey128->click();
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
}

void DialogNew::on_radioKey192_clicked()
{
	spinBoxNumberRounds->setMaximum(12);
}

void DialogNew::on_radioKey256_clicked()
{
	spinBoxNumberRounds->setMaximum(14);
}

void DialogNew::on_buttonSetInput_clicked()
{	
	
}

void DialogNew::on_buttonSetKey_clicked()
{
	
}
