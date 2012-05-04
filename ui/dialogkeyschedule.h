#ifndef DIALOGKEYSCHEDULE_H
#define DIALOGKEYSCHEDULE_H

#include <QDialog>

namespace Ui {
    class DialogKeySchedule;
}

class DialogKeySchedule : public QDialog
{
    Q_OBJECT

public:
    explicit DialogKeySchedule(QWidget *parent = 0);
    ~DialogKeySchedule();

private:
    Ui::DialogKeySchedule *ui;
};

#endif // DIALOGKEYSCHEDULE_H
