#ifndef DIALOGEXPORT_H
#define DIALOGEXPORT_H

#include <QDialog>
#include <cstdio>
#include <QAbstractButton>

namespace Ui {
    class DialogExport;
}

class DialogExport : public QDialog
{
    Q_OBJECT

public:
    explicit DialogExport(QWidget *parent = 0);
    ~DialogExport();

    void setPlaintext(unsigned char* plaintext);
    void setCiphertext(unsigned char* ciphertext);
    void update();
    void hexToUpperCaseText(unsigned char &hex, char* temp_string);

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);

private:
    Ui::DialogExport *ui;

    unsigned char* plaintext;
    unsigned char* ciphertext;
};

#endif // DIALOGEXPORT_H
