#include "circleequation.h"

void CircleEquation::circle(int centerx, int centery, int radius, float color[], Point plotter)
{
    int x, y1, y2;
    double value;

    for(x = -radius; x <= radius; ++x) {
        value = sqrt(std::abs(pow((double)radius, 2.0) - pow((double) x, 2.0)));
        y1 = centery + ((int) value);
        y2 = centery - ((int) value);

        plotter.draw(centerx + x, y1, color);
        plotter.draw(centerx + x, y2, color);
    }
}
