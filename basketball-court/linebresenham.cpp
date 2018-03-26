#include "linebresenham.h"
#include <cmath>

void swap_(int &x1, int &x2) {
    int temp = x1;
    x1 = x2;
    x2 = temp;
}

void LineBresenham::line(int x1, int y1, int x2, int y2, float color[], Point plotter)
{
    int dx, dy, incE, incNE, d, x, y;

    if(x1 > x2){
        swap_(x1,x2);
        swap_(y1,y2);
    }

    if (x1 == x2) {
        if (y1 > y2)
            swap_(y1,y2);
        for(y = y1; y <= y2; ++y)
            plotter.draw(x1,y,color);
    } else {
        dx = std::abs(x2 - x1);
        dy = std::abs(y2 - y1);

        if(dx > dy){
            dx = std::abs(x2 - x1);
            dy = std::abs(y2 - y1);
            int yinc = (y1<y2?1:-1);
            int xinc = (x1<x2?1:-1);

            d = (int)(2.0 * dy - dx);
            incE = (int)(2.0 * dy);
            incNE = (int)(2.0 * (dy - dx));

            x = x1;
            y = y1;
            //plotter.draw(x, y, color);

            while(x < x2) {
                plotter.draw(x, y, color);

                if (d <= 0){
                    d += incE;
                    x += xinc;
                } else {
                    d += incNE;
                    x += xinc;
                    y += yinc;
                }

            }
        } else {
            if (y1 > y2){
                swap_(x1,x2);
                swap_(y1,y2);
            }

            dx = std::abs(x2 - x1);
            dy = std::abs(y2 - y1);
            int yinc = (y1<y2?1:-1);
            int xinc = (x1<x2?1:-1);

            d = (int)(2.0 * dx - dy);
            incE = (int)(2.0 * dx);
            incNE = (int)(2.0 * (dx - dy));

            x = x1;
            y = y1;
            //plotter.draw(x, y, color);

            while(y < y2) {
                plotter.draw(x, y, color);

                if (d <= 0){
                    d += incE;
                    y += yinc;
                } else {
                    d += incNE;
                    x += xinc;
                    y += yinc;
                }

            }
        }
    }

}
