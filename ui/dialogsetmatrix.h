#ifndef DIALOGSETMATRIXIMPL_H
#define DIALOGSETMATRIXIMPL_H

#include <QDialog>
#include "ui_setmatrix.h"

#include "src/fast-rijndael-1d/fast-rijndael-1d.h"

class DialogSetMatrixImpl : public QDialog, public Ui::DialogSetMatrix
{
Q_OBJECT
public:
	enum MatrixType{
                Input, Key
	};	
	
	MatrixType type;
	
	QLineEdit** setByteArray;
	
        unsigned char* targetMatrix;

        bool editing;

	DialogSetMatrixImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	void SetWindowTitle(QString title);
        void SetMatrixType(MatrixType type, FastRijndael::KeySize keySize = FastRijndael::K128);
        void SetMatrixPointer(unsigned char* matrix);
	bool updateTargetMatrix();
        void updateModeFromTo(QRadioButton* source);
private slots:
	void on_radioMatrixMode_clicked();
	void on_radioTextMode_clicked();
	void on_buttonBox_clicked(QAbstractButton* button);
	
        void on_radioCharTextMode_clicked();
        void on_setByte00_textChanged(QString );
        void on_setByte01_textChanged(QString );
        void on_setByte02_textChanged(QString );
        void on_setByte03_textChanged(QString );
        void on_setByte07_textChanged(QString );
        void on_setByte04_textChanged(QString );
        void on_setByte05_textChanged(QString );
        void on_setByte06_textChanged(QString );
        void on_setByte08_textChanged(QString );
        void on_setByte09_textChanged(QString );
        void on_setByte10_textChanged(QString );
        void on_setByte11_textChanged(QString );
        void on_setByte12_textChanged(QString );
        void on_setByte13_textChanged(QString );
        void on_setByte14_textChanged(QString );
        void on_setByte15_textChanged(QString );
        void on_setByte16_textChanged(QString );
        void on_setByte17_textChanged(QString );
        void on_setByte18_textChanged(QString );
        void on_setByte19_textChanged(QString );
        void on_setByte20_textChanged(QString );
        void on_setByte21_textChanged(QString );
        void on_setByte22_textChanged(QString );
        void on_setByte23_textChanged(QString );
        void on_setByte24_textChanged(QString );
        void on_setByte25_textChanged(QString );
        void on_setByte26_textChanged(QString );
        void on_setByte27_textChanged(QString );
        void on_setByte28_textChanged(QString );
        void on_setByte29_textChanged(QString );
        void on_setByte30_textChanged(QString );
        void on_setByte31_textChanged(QString );
        void on_setHexTextBytes_textChanged(QString );
        void on_setCharTextBytes_textChanged(QString );
};
#endif








