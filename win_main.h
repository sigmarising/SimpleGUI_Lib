#ifndef WIN_MAIN_H
#define WIN_MAIN_H

// add header
#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <QDialog>
#include <vector>
#include <utility>
using namespace std;

// define windows
#define WIN_WIGHT   1000
#define WIN_HEIGHT  700
#define WIN_TITLE   "MY GUI LIB"

namespace Ui {
    class Win_Main;
}

class Win_Main : public QDialog {
    Q_OBJECT

public:
    explicit Win_Main(QWidget *parent = 0);
    ~Win_Main();

    // add functions
    void paintEvent(QPaintEvent *);

    // draw point on (x, y) with color c
    //      default width w = 1
    bool draw_point(int const x, int const y, QColor const c, int w = 1);

    // draw line from (x_1, y_1) to (x_2, y_2) with color c
    //      default width w = 1
    bool draw_line(int const x_1, int const y_1, int const x_2, int const y_2, QColor const c, int w = 1);

    // fill the shape defined by
    //      outer points stored in points_out   (clockwith or anticlockwith)
    //      inner points stored in points_in    (clockwith or anticlockwith)
    // with shadow_line in color c
    //      default gradiant k = 1
    //      default side width h = 10
    //      default width w = 1
    bool fill_shadow_line(vector< pair<int, int> >points_out, vector< pair<int, int> >points_in, QColor const c, double k = 1, int h = 10, int w = 1);

    // fill color
    //      without set the is_draw
    //      set old color to new color
    bool fill_color(int const x, int const y, QColor const old_c, QColor const new_c);

    // draw arc line
    //      x0 y0 define the center of the circle
    //      r define the R
    //      angle can be from 0 to 360
    bool draw_arc(int const x0, int const y0, int const r, double start_angle, double end_angle, QColor const c, int w = 1);

    // draw ellipse line
    //      x0 y0 define the center of the circle
    //      a b is the A B
    //      angle can be from 0 to 360
    bool draw_ellipse(int const x0, int const y0, int const a, int const b, double start_angle, double end_angle, QColor const c, int w = 1);

    // draw text
    //      draw the name with color c
    bool draw_text(int const x, int const y, QColor const c);
private:
    Ui::Win_Main *ui;

    // draw point on (x, y) with color c
    //      default width w = 1
    //      this func don't set the is_draw arr
    bool draw_point_without_set(int const x, int const y, QColor const c, int w = 1);

    // add pixmap
    QPixmap Pix;

    //  if the current pixel is drawd
    //      then the bool is true
    //      else is false
    //  from index 0 to win_xxx
    bool is_draw[WIN_WIGHT + 1][WIN_HEIGHT + 1];
};

#endif // WIN_MAIN_H
