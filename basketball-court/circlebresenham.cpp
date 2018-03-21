#include "circlebresenham.h"

void drawCircle(int centerx, int centery, int x, int y, float color[], Point plotter, bool left, bool right)
{
    if (right) {
        plotter.draw(centerx + x, centery + y, color);
        plotter.draw(centerx + x, centery - y, color);
        plotter.draw(centerx + y, centery + x, color);
        plotter.draw(centerx + y, centery - x, color);
    }

    if (left) {
        plotter.draw(centerx - x, centery + y, color);
        plotter.draw(centerx - x, centery - y, color);
        plotter.draw(centerx - y, centery + x, color);
        plotter.draw(centerx - y, centery - x, color);
    }
}

void draw_(int centerx, int centery, int radius, float color[], Point plotter, bool left, bool right) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;
    while (y >= x)
    {
        drawCircle(centerx, centery, x, y, color, plotter, left, right);
        ++x;

        if (d > 0)
        {
            --y;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(centerx, centery, x, y, color, plotter, left, right);
    }
}

void CircleBresenham::circle(int centerx, int centery, int radius, float color[], Point plotter)
{
    draw_(centerx, centery, radius, color, plotter, true, true);
}

void CircleBresenham::semicircle_left(int centerx, int centery, int radius, float color[], Point plotter)
{
    draw_(centerx, centery, radius, color, plotter, true, false);
}

void CircleBresenham::semicircle_right(int centerx, int centery, int radius, float color[], Point plotter)
{
    draw_(centerx, centery, radius, color, plotter, false, true);
}
