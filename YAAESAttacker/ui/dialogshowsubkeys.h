#ifndef DIALOGSHOWSUBKEYS_H
#define DIALOGSHOWSUBKEYS_H

#include <QDialog>
#include <QAbstractButton>
#include <QLabel>
#include <cstdio>

namespace Ui {
    class DialogShowSubKeys;
}

class DialogShowSubKeys : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowSubKeys(QWidget *parent = 0);
    ~DialogShowSubKeys();

    void setSubKeysMatrix(QString* k0, QString* k1, QString* k2, QString* u2);
    void forceUpdate();

private slots:
    void on_buttonBox_clicked(QAbstractButton* button);

private:
    Ui::DialogShowSubKeys *ui;



    QLabel** k0Array;
    QLabel** k1Array;
    QLabel** k2Array;
    QLabel** u2Array;


};

#endif // DIALOGSHOWSUBKEYS_H
