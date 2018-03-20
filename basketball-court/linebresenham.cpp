#include "linebresenham.h"

void swap_(int &x1, int &x2) {
    int temp = x1;
    x1 = x2;
    x2 = temp;
}

void LineBresenham::line(int x1, int y1, int x2, int y2, float color[], Point plotter)
{
    int dx, dy, incE, incNE, d, x, y;

    if (x1 > x2){
        swap_(x1,x2);
        swap_(y1,y2);
    }

    if (x1 == x2) {
        if (y1 > y2)
            swap_(y1,y2);
        for(y = y1; y <= y2; ++y)
            plotter.draw(x1,y,color);
    } else {
        dx = x2 - x1;
        dy = y2 - y1;
        int yinc = 1;
        if (dy < 0){
            yinc = -1;
            dy *= -1;
        }
        d = (int)((2.0 * dy) - dx);
        incE = (int)(2.0 * dy);
        incNE = (int)(2.0 * (dy - dx));
        x = x1;
        y = y1;
        plotter.draw(x, y, color);

        while(x < x2) {
            if (d <= 0){
                d += incE;
                ++x;
            } else {
                d += incNE;
                ++x;
                y += yinc;
            }
            plotter.draw(x, y, color);
        }
    }

}
