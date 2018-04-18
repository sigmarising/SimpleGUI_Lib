#include "win_main.h"
#include "ui_win_main.h"

Win_Main::Win_Main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Win_Main)
{
    ui->setupUi(this);
}

Win_Main::~Win_Main()
{
    delete ui;
}
