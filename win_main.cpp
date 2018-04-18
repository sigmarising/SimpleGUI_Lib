#include "win_main.h"
#include "ui_win_main.h"

Win_Main::Win_Main(QWidget *parent) : QDialog(parent), ui(new Ui::Win_Main) {
    ui->setupUi(this);

    // set windows
    setFixedSize(WIN_WIGHT, WIN_HEIGHT);
    setWindowTitle(WIN_TITLE);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    // init pixmap
    Pix = QPixmap(WIN_WIGHT, WIN_WIGHT);
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
void Win_Main::draw_point(const int x, const int y, const QColor c, int w) {
    QPainter Painter(&Pix);

    Painter.setPen(QPen(c, w));

    Painter.drawPoint(x, y);

    is_draw[x][y] = true;
}
