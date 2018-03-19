#include "circlebresenham.h"

void drawCircle(int centerx, int centery, int x, int y, float color[], Point plotter)
{
    plotter.draw(centerx + x, centery + y, color);
    plotter.draw(centerx - x, centery + y, color);
    plotter.draw(centerx + x, centery - y, color);
    plotter.draw(centerx - x, centery - y, color);
    plotter.draw(centerx + y, centery + x, color);
    plotter.draw(centerx - y, centery + x, color);
    plotter.draw(centerx + y, centery - x, color);
    plotter.draw(centerx - y, centery - x, color);
}

// TODO: implement
void CircleBresenham::circle(int centerx, int centery, int radius, float color[], Point plotter)
{
    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    while (y >= x)
    {
        drawCircle(centerx, centery, x, y, color, plotter);
        ++x;

        if (d > 0)
        {
            --y;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(centerx, centery, x, y, color, plotter);
    }
}
