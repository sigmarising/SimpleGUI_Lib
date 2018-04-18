#ifndef WIN_MAIN_H
#define WIN_MAIN_H

#include <QDialog>

namespace Ui {
    class Win_Main;
}

class Win_Main : public QDialog
{
    Q_OBJECT

public:
    explicit Win_Main(QWidget *parent = 0);
    ~Win_Main();

private:
    Ui::Win_Main *ui;
};

#endif // WIN_MAIN_H
