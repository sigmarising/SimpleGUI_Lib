#include "win_main.h"
#include "ui_win_main.h"
#include <cmath>
#include <algorithm>
using namespace std;

template<class Type>
void swap_simpleType(Type &a, Type &b){
    Type t = a;
    a = b;
    b = t;
}

bool sort_use_draw_shadow_line(pair<int,int> i, pair<int, int> j) {
    if (i.first != j.first)
        return i.first < j.first;
    else
        return i.second < j.second;
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

bool Win_Main::fill_shadow_line(vector<pair<int, int> > points_out, vector<pair<int, int> > points_in, const QColor c, int k, int h, int w) {
    // define the shape's line
    class line {
    public:
        void reinit(int x_1, int y_1, int x_2, int y_2, int k) {
            x1 = x_1; y1 = y_1;
            x2 = x_2; y2 = y_2;

            b1 = y1 - k * x1;
            b2 = y2 - k * x2;

            if (b1 >= b2){
                b_max = b1;
                b_min = b2;
            }
            else {
                b_max = b2;
                b_min = b1;
            }
        }
        bool check_cross(int const b){
            if (b_min < b && b < b_max)
                return true;
            else
                return false;
        }
        pair<int, int> get_cross_point(int const b, int const k){
            int xi = 0, yi = 0;
            xi = int(double(x1 * y2 - x2 * y1 + b * (x2 - x1)) / double(y2 - y1 - k * (x2 - x1)));
            yi = k * xi + b;
            pair<int, int> temp(xi, yi);
            return temp;
        }
        pair<int, int> get_B_min_max(){
            pair<int, int>temp(b_min, b_max);
            return temp;
        }
    private:
        int x1, y1;
        int x2, y2;
        int b1, b2;
        int b_min, b_max;
    };

    // do the init job
    vector<line>v_line(points_in.size() + points_out.size());
    int B_MIN = INT_MAX, B_MAX = INT_MIN;
    int index = -1;

    int t = int(points_out.size() - 1);

    for(int i = 0; i < t; i++){
        index++;
        v_line[index].reinit(points_out[i].first, points_out[i].second, points_out[i+1].first, points_out[i+1].second, k);
    }
    if (t+1 != 0){
        index++;
        v_line[index].reinit(points_out[0].first, points_out[0].second, points_out[points_out.size() - 1].first, points_out[points_out.size() - 1].second, k);
    }
    t = int(points_in.size() - 1);
    for(int i = 0; i < t; i++){
        index++;
        v_line[index].reinit(points_in[i].first, points_in[i].second, points_in[i+1].first, points_in[i+1].second, k);
    }
    if(t+1 !=0){
        index++;
        v_line[index].reinit(points_in[0].first, points_in[0].second, points_in[points_in.size() - 1].first, points_in[points_out.size() - 1].second, k);
    }
    for (int i = 0; i < v_line.size(); i++){
        pair<int, int>t = v_line[i].get_B_min_max();
        if(t.first < B_MIN)
            B_MIN = t.first;
        if(t.second > B_MAX)
            B_MAX = t.second;
    }

    // draw
    int delta_b = int(double(h)/double(abs(cos(atan(k)))));
    int b_now = B_MIN + delta_b;
    while(B_MIN < b_now && b_now < B_MAX){
        vector< pair<int,int> >for_draw;

        for(int i = 0; i < v_line.size(); i++){
            if(v_line[i].check_cross(b_now)){
                for_draw.push_back(v_line[i].get_cross_point(b_now, k));
            }
        }

        sort(for_draw.begin(), for_draw.end(), sort_use_draw_shadow_line);

        if(for_draw.size() % 2 == 0){
            for(int i = 0; i < for_draw.size() - 1; i+=2){
                draw_line(for_draw[i].first, for_draw[i].second, for_draw[i+1].first, for_draw[i+1].second, c, w);
            }
        }
        else{
            draw_line(for_draw[0].first, for_draw[0].second,for_draw[for_draw.size()-1].first, for_draw[for_draw.size()-1].second, c, w);
        }

        b_now += delta_b;
    }

    return true;
}
