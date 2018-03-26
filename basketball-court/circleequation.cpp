#include "circleequation.h"

void draw(int centerx, int centery, int radius, float color[], Point plotter, int x_init, int x_end) {
    if (x_init > x_end) {
        int temp = x_init;
        x_init = x_end;
        x_end = temp;
    }

    if (x_init < - radius)
        x_init = - radius;
    if (x_init > radius)
        x_init = radius;

    int x, y1, y2;
    double value;

    for(x = x_init; x <= x_end; ++x) {
        value = sqrt(std::abs(pow((double)radius, 2.0) - pow((double) x, 2.0)));
        y1 = centery + ((int) value);
        y2 = centery - ((int) value);

        plotter.draw(centerx + x, y1, color);
        plotter.draw(centerx + x, y2, color);
    }
}

void CircleEquation::circle(int centerx, int centery, int radius, float color[], Point plotter)
{
    draw(centerx, centery, radius, color, plotter, -radius, radius);
}

void CircleEquation::semicircle_left(int centerx, int centery, int radius, float color[], Point plotter)
{
    draw(centerx, centery, radius, color, plotter, -radius, 0);
}

void CircleEquation::semicircle_right(int centerx, int centery, int radius, float color[], Point plotter)
{
    draw(centerx, centery, radius, color, plotter, 0, radius);
}
