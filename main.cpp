#include "win_main.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Win_Main w;
    w.show();

    {
        // draw line
        w.draw_line(100,100,300,300,QColor(139,101,8));
        w.draw_line(300,100,100,300,QColor(255,115,50));
        w.draw_line(200,100,200,300,QColor(255,106,106));
        w.draw_line(100,200,300,200,QColor(160,32,240));

        // fill color
        w.draw_line(800-10,100-10,900+10,200+10,QColor(0,0,0));
        w.draw_line(900+10,200-10,800-10,300+10,QColor(0,0,0));
        w.draw_line(800+10,300+10,700-10,200-10,QColor(0,0,0));
        w.draw_line(700-10,200+10,800+10,100-10,QColor(0,0,0));
        w.fill_color(800, 200, QColor(255,255,255), QColor(146,168,209));

        // fill shadow line
        w.draw_line(500-10,100-10,600+10,200+10,QColor(0,0,0));
        w.draw_line(600+10,200-10,500-10,300+10,QColor(0,0,0));
        w.draw_line(500+10,300+10,400-10,200-10,QColor(0,0,0));
        w.draw_line(400-10,200+10,500+10,100-10,QColor(0,0,0));
        w.draw_line(460,160,540,160,QColor(0,0,0));
        w.draw_line(540,160,540,240,QColor(0,0,0));
        w.draw_line(540,240,460,240,QColor(0,0,0));
        w.draw_line(460,240,460,160,QColor(0,0,0));
        vector< pair<int,int> >i,j;
        i.push_back(pair<int,int>(500,100));
        i.push_back(pair<int,int>(600,200));
        i.push_back(pair<int,int>(500,300));
        i.push_back(pair<int,int>(400,200));
        j.push_back(pair<int,int>(460,160));
        j.push_back(pair<int,int>(540,160));
        j.push_back(pair<int,int>(540,240));
        j.push_back(pair<int,int>(460,240));
        w.fill_shadow_line(i,j,QColor(220,100,55),4.3);

        // draw arc
        w.draw_arc(200,500,100,0,360,QColor(30,144,255));
        w.draw_arc(200,500,80,0,250,QColor(30,144,2));
        w.draw_arc(200,500,60,220,300,QColor(30,44,55));
        w.draw_arc(200,500,40,70,260,QColor(3,144,5));

        // draw ellipse
        w.draw_ellipse(500,500,150,100,0,360,QColor(123,33,25));
        w.draw_ellipse(500,500,130,80,0,220,QColor(13,33,25));
        w.draw_ellipse(500,500,110,60,50,360,QColor(13,3,5));
        w.draw_ellipse(500,500,90,40,70,140,QColor(1,3,225));
        w.draw_ellipse(500,500,70,20,111,333,QColor(3,133,5));

        // draw name
        w.draw_text(800,600,QColor(0,0,0));
        w.draw_text(800,500,QColor(255,0,0));
        w.draw_text(800,400,QColor(0,0,255));
    }

    return a.exec();
}
