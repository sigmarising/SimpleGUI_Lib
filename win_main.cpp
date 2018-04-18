#include "win_main.h"
#include "ui_win_main.h"

Win_Main::Win_Main(QWidget *parent) : QDialog(parent), ui(new Ui::Win_Main) {
    ui->setupUi(this);

    // set windows
    setFixedSize(WIN_WIGHT, WIN_HEIGHT);
    setWindowTitle(WIN_TITLE);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    // init pixmap
    Pix = QPixmap(WIN_WIGHT, WIN_HEIGHT);
    Pix.fill(Qt::white);

    // init isdraw
    for(int i = 0; i < WIN_WIGHT; i++)
        for (int j = 0; j < WIN_HEIGHT; j++)
            is_draw[i][j] = false;
}

Win_Main::~Win_Main() {
    delete ui;
}

// draw task event
void Win_Main::paintEvent(QPaintEvent *) {
    QPainter Painter(this);
    Painter.drawPixmap(0, 0, WIN_WIGHT, WIN_HEIGHT, Pix);
}

// draw - point
bool Win_Main::draw_point(const int x, const int y, const QColor c, int w) {
    if ( !( (0 <= x) && (x <= WIN_WIGHT) && (0 <= y) && (y <= WIN_HEIGHT) ) )
        return false;

    QPainter Painter(&Pix);

    Painter.setPen(QPen(c, w));

    Painter.drawPoint(x, y);

    is_draw[x][y] = true;

    return true;
}

// use bresenham algorithm
bool Win_Main::draw_line(const int x1, const int y1, const int x2, const int y2, const QColor c, int w) {
    if ( !(
            (0 <= x1) && (x1 <= WIN_WIGHT) && (0 <= y1) && (y1 <= WIN_HEIGHT) &&
            (0 <= x2) && (x2 <= WIN_WIGHT) && (0 <= y2) && (y2 <= WIN_HEIGHT)
             ) )
        return false;

    // init two point
    int x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0;
    if (x1 <= x2){
        x_1 = x1, y_1 = y1;
        x_2 = x2, y_2 = y2;
    }
    else{
        x_1 = x2, y_1 = y2;
        x_2 = x1, y_2 = y1;
    }

    int dx = x_2 - x_1;    // must be positive
    int dy = y_2 - y_1;    // can be positive or nagative

    // handle dx = 0;
    if(0 == dx){
        if (y_1 >= y_2){
            int t = y_2;
            y_1 = y_2;
            y_2 = t;
        }
        for (int i = y_1; i <= y_2; i++)
            draw_point(x_1, i, c, w);
        return true;
    }

    // handle others
    int e = -dx;
    int delta_inc = 1;

    // use delta_inc to handle negative dy
    if (dy >= 0)
        delta_inc = 1;
    else{
        delta_inc = -1;
        dy *= -1;
    } // there dx dy both be positive

    // main draw
    int x = x_1, y = y_1;
    for(int i = 0; i <= dx; i++){
        draw_point(x, y, c, w);
        if (e>=0){
            y += delta_inc;
            e = e - 2 * dx;
        }
        x++;
        e = e + 2 * dy;
    }

    return true;
}
