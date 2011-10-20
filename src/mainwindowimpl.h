#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "rijndael.h"

class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	void Initialize();		
	
	void updateKeyMatrix();
	void updateInputMatrix();
	void updateOutputMatrix();
	void updateStateMatrix();	
	void updateAllMatrices();
		
	
public slots:	
	void on_actionSetInputMatrix_activated();
	void on_actionSetKeyMatrix_activated();
	
private slots:	
	void on_actionExit_activated();	
	void on_buttonBackOp_pressed();
	void on_buttonNextOp_pressed();
	void on_buttonFirstOp_pressed();
	void on_buttonLastOp_pressed();
	void on_actionNewRijndael_activated();	
};

#endif




