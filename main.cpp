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
        w.draw_line(50,50,300,50,QColor(0,0,0));
        w.draw_line(300,50,300,300,QColor(0,0,0));
        w.draw_line(300,300,50,300,QColor(0,0,0));
        w.draw_line(50,300,50,50,QColor(0,0,0));
        w.draw_line(70,70,70,50,QColor(0,0,0));
        w.draw_line(70,70,50,70,QColor(0,0,0));
        vector< pair<int,int> >i,j;
        i.push_back(pair<int,int>(10,10));
        i.push_back(pair<int,int>(500,10));
        i.push_back(pair<int,int>(500,500));
        i.push_back(pair<int,int>(10,500));
        j.push_back(pair<int,int>(50,50));
        j.push_back(pair<int,int>(300,50));
        j.push_back(pair<int,int>(300,300));
        j.push_back(pair<int,int>(50,300));
//        w.fill_shadow_line(i,j,QColor(100,222,12),1);
//        w.fill_color(80,80, QColor(255,255,255), QColor(22,45,56));
        w.draw_arc(400,400,50,200,360,QColor(0,0,0));

    }

    return a.exec();
}
