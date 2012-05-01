#ifndef DIALOGNEW_H
#define DIALOGNEW_H

#include <QDialog>
#include "ui_dialognew.h"

class DialogNew : public QDialog, public Ui::DialogNew
{
Q_OBJECT
public:
	DialogNew( QWidget * parent = 0, Qt::WFlags f = 0 );
	
private:
	//MainWindowImpl* mainwin;
private slots:
	void on_buttonSetInput_clicked();
	void on_buttonSetKey_clicked();
	void on_buttonBox_clicked(QAbstractButton* button);
	void on_radioKey128_clicked();
	void on_radioKey192_clicked();
	void on_radioKey256_clicked();
};
#endif






