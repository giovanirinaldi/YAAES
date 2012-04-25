#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "rijndael/rijndael.h"

class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	void Initialize();	
	
	bool initialized;	
	bool previousDisabled;
	bool nextDisabled;
	
	void updateKeyMatrix();
	void updateInputMatrix();
	void updateOutputMatrix();
	void updateStateMatrix();
	void updatePreviousMatrix();
	void updateNextMatrix();
	void updateAllMatrices();
	
	void disablePreviousMatrix();
	void disableNextMatrix();
	
	void updateRoundAndOp();
	
	void calculateMatrices();
		
private:
	QLabel** keyByteArray;
	QLabel** inputByteArray;
	QLabel** outputByteArray;
	QLabel** stateByteArray;
	QLabel** previousByteArray;
	QLabel** nextByteArray;

        void paintEvent(QPaintEvent *);
	
public slots:	
	void on_actionSetInputMatrix_activated();
	void on_actionSetKeyMatrix_activated();
	
private slots:	
	void on_actionExit_activated();	
	void on_buttonNextOp_pressed();
	void on_buttonFirstOp_pressed();
	void on_buttonPreviousOp_pressed();
	void on_buttonLastOp_pressed();
        void on_actionNewRijndael_activated();
        void on_btnEditInput_clicked();
        void on_btnEditKey_clicked();
        void on_btnShowPreviousOp_clicked();
        void on_btnShowNextOp_clicked();
};

#endif




