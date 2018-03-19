#include "lineequation.h"

LineEquation::LineEquation()
{

}

void LineEquation::line(int x1, int y1, int x2, int y2, float color[3], Point plotter)
{
    int x, y;
    float a;

    if (x2 != x1)
        a = (y2 - y1) / (x2 - x1);
    else
        a = 0;
    for(x = x1; x <= x2; ++x) {
        y = (y1 + a * (x - x1));
        plotter.draw(x, y, color);
    }
}
