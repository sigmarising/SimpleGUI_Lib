#include "win_main.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Win_Main w;
    w.show();

    // the draw tasks
    {
        w.draw_line(10,10,10,500,QColor(32,43,222));
        w.draw_line(10,10,500,500,QColor(32,43,222));
        w.draw_line(10,500,500,10,QColor(32,43,222));
        w.draw_line(10,10,500,10,QColor(32,43,222));
    }

    return a.exec();
}
