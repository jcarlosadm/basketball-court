#include "lineequation.h"

LineEquation::LineEquation()
{

}

void LineEquation::line(int x1, int y1, int x2, int y2, float color[3], Point plotter)
{
    int x, y;
    float a;

    if(x1 > x2){
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }

    if (x2 != x1){
        a = (y2 - y1) / (float) (x2 - x1);

        for(x = x1; x <= x2; ++x) {
            y = (y1 + (int)(a * (x - x1)));
            plotter.draw(x, y, color);
        }
    }
    else{
        if(y1 > y2){
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }

        for(y = y1; y<=y2;++y){
            plotter.draw(x1,y,color);
        }
    }

}
