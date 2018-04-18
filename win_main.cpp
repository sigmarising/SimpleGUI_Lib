#include "win_main.h"
#include "ui_win_main.h"

template<class Type>
void swap_simpleType(Type &a, Type &b){
    Type t = a;
    a = b;
    b = t;
}


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
bool Win_Main::draw_line(const int x_1, const int y_1, const int x_2, const int y_2, const QColor c, int w) {
    // judge whether the position is valid
    if ( !(
            (0 <= x_1) && (x_1 <= WIN_WIGHT) && (0 <= y_1) && (y_1 <= WIN_HEIGHT) &&
            (0 <= x_2) && (x_2 <= WIN_WIGHT) && (0 <= y_2) && (y_2 <= WIN_HEIGHT)
             ) )
        return false;


    // adjust two point
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    if (x_1 <= x_2){
        x1 = x_1, y1 = y_1;
        x2 = x_2, y2 = y_2;
    }
    else{
        x1 = x_2, y1 = y_2;
        x2 = x_1, y2 = y_1;
    }


    // init var
    // default condition :
    //     delta_y > 0 && delta_x >= delta_y
    int delta_x = x2 - x1;  // must be positive
    int delta_y = y2 - y1;  // can be positive or nagative
    int x = x1, y = y1;


    // use delta_inc to handle :
    //      negative delta_y
    int delta_inc = 1;
    if (delta_y >= 0)
        delta_inc = 1;
    else{
        delta_inc = -1;
        delta_y *= -1;
    } // there, delta_x delta_y both be positive


    // handle delta_x < delta_y
    bool sign_k_LG_1 = false;
    if(delta_x < delta_y){
        swap_simpleType(delta_x, delta_y);
        sign_k_LG_1 = true;
        if(y1 > y2){
            x = y2;
            y = x2;
        }
        else
            swap_simpleType(x, y);
    }

    // main algorithm
    int e = -delta_x;
    for(int i = 0; i <= delta_x; i++){
        if (sign_k_LG_1)
            draw_point(y, x, c, w);
        else
            draw_point(x, y, c, w);
        if (e >= 0){
            y += delta_inc;
            e = e - 2 * delta_x;
        }
        x++;
        e = e + 2 * delta_y;
    }

    return true;
}
