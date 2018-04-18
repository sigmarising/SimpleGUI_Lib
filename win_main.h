#ifndef WIN_MAIN_H
#define WIN_MAIN_H

// add header
#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <QDialog>

// define windows
#define WIN_WIGHT   800
#define WIN_HEIGHT  600
#define WIN_TITLE   "Draw Test"

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
    void draw_point(int const x, int const y, QColor const c, int w = 1);

private:
    Ui::Win_Main *ui;

    // add pixmap
    QPixmap Pix;

    //  if the current pixel is drawd
    //      then the bool is true
    //      else is false
    //  from index 0 to win_xxx
    bool is_draw[WIN_WIGHT + 1][WIN_HEIGHT + 1];
};

#endif // WIN_MAIN_H
