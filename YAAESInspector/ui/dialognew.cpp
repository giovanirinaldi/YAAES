#include "dialognew.h"

#include "mainwindowimpl.h"
#include "dialogsetmatrix.h"
#include "src/global.h"

DialogNew::DialogNew( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
        switch (rijn->getKeySize()){
                case FastRijndael::K128:
			radioKey128->click();
			break;
                case FastRijndael::K192:
			radioKey192->click();
			break;
                case FastRijndael::K256:
			radioKey256->click();
			break;
	}
	//radioKey128->click();
        ks_temp = FastRijndael::K128;
	spinBoxNumberRounds->setValue(maxRounds);
}

void DialogNew::on_buttonBox_clicked(QAbstractButton* button)
{
	if (QString::compare(button->text(),"&ok", Qt::CaseInsensitive) == 0){
		maxRounds = spinBoxNumberRounds->value();		
		MainWindowImpl* parent_main = qobject_cast<MainWindowImpl*>(this->parent());
		if (parent_main != NULL){	
			parent_main->initialized = false;
                        parent_main->Initialize();
                        //parent_main->calculateMatrices();
                //	parent_main->updateAllMatrices();
		}
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
        ks_temp = FastRijndael::K128;
}

void DialogNew::on_radioKey192_clicked()
{
	spinBoxNumberRounds->setMaximum(12);
        ks_temp = FastRijndael::K192;
}

void DialogNew::on_radioKey256_clicked()
{
	spinBoxNumberRounds->setMaximum(14);
        ks_temp = FastRijndael::K256;
}

void DialogNew::on_buttonSetInput_clicked()
{	
	MainWindowImpl* p = qobject_cast<MainWindowImpl*>(this->parent());
	p->on_actionSetInputMatrix_activated();
}

void DialogNew::on_buttonSetKey_clicked()
{
	MainWindowImpl* p = (MainWindowImpl*)(this->parent());
	p->on_actionSetKeyMatrix_activated();
}
