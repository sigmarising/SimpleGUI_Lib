#include "win_main.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Win_Main w;
    w.show();

    // the draw tasks
    {
        w.draw_line(0, 0, 800, 400, QColor(13,23,222));
        w.draw_line(0, 300, 900, 300, QColor(123,33,222));
        w.draw_line(100, 0, 100, 500, QColor(23,22,222));
        w.draw_line(50, 500, 600, 0, QColor(123,33,22));
    }

    return a.exec();
}
