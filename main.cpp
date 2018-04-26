#include "win_main.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Win_Main w;
    w.show();

    {
//        w.draw_line(0, 30, 800, 30, QColor(255, 0, 0));
//        w.draw_line(800, 60, 0, 60, QColor(255, 0, 0));

//        w.draw_line(400, 500, 400, 0, QColor(0, 255, 100));
//        w.draw_line(100, 0, 100, 500, QColor(0, 255, 100));

//        w.draw_line(0, 500, 800, 0, QColor(0, 0, 255));
//        w.draw_line(0, 500, 100, 0, QColor(0, 0, 255));
//        w.draw_line(10, 0, 0, 500,  QColor(0, 0, 255));
//        w.draw_line(700, 0, 0, 500,  QColor(0, 0, 255));

//        w.draw_line(800, 200, 0, 0, QColor(200, 100, 50));
//        w.draw_line(100, 500, 0, 0, QColor(200, 100, 50));
//        w.draw_line(0, 0, 800, 500, QColor(200, 100, 50));
//        w.draw_line(0, 0, 150, 500, QColor(200, 100, 50));
        w.draw_line(10,10,500,10,QColor(0,0,0));
        w.draw_line(500,10,500,500,QColor(0,0,0));
        w.draw_line(500,500,10,500,QColor(0,0,0));
        w.draw_line(10,10,10,500,QColor(0,0,0));
        vector< pair<int,int> >i,j;
        i.push_back(pair<int,int>(10,10));
        i.push_back(pair<int,int>(10,500));
        i.push_back(pair<int,int>(500,10));
        i.push_back(pair<int,int>(500,500));
        w.fill_shadow_line(i,j,QColor(100,100,100));


    }

    return a.exec();
}
