#include "win_main.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Win_Main w;
    w.show();

    // the draw tasks
    {
        w.draw_point(10, 10, QColor(50,23,21), 10);
    }

    return a.exec();
}
