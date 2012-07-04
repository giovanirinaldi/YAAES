#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
    class DialogAbout;
}

class DialogAbout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAbout(QWidget *parent = 0);
    ~DialogAbout();

private slots:
    void on_buttonBox_2_clicked(QAbstractButton* button);

private:
    Ui::DialogAbout *ui;
};

#endif // DIALOGABOUT_H
