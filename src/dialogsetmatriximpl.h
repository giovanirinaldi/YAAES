#ifndef DIALOGSETMATRIXIMPL_H
#define DIALOGSETMATRIXIMPL_H

#include <QDialog>
#include "ui_setmatrix.h"

#include "rijndael.h"

class DialogSetMatrixImpl : public QDialog, public Ui::DialogSetMatrix
{
Q_OBJECT
public:
	enum MatrixType{
		Input, Key
	};	
	
	unsigned char** targetMatrix;	

	DialogSetMatrixImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	void SetWindowTitle(QString title);
	void SetMatrixType(MatrixType type, Rijndael::KeySize keySize = Rijndael::K128);
	void SetMatrixPointer(unsigned char** matrix);	
	void updateTargetMatrix();
private slots:
	void on_radioMatrixMode_clicked();
	void on_radioTextMode_clicked();
	void on_buttonBox_clicked(QAbstractButton* button);
	
};
#endif








