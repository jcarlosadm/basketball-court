#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"
#include "linealgorithm.h"

class Rectangle
{
public:
    Rectangle(int x, int y, int width, int height);
    void draw(LineAlgorithm *lineAlgorithm,float color[], Point plotter);
    void adjustleft(float adjust);
    void adjustright(float adjust);

private:
    int x, y, width, height;
    float adjust_left = 1.0f, adjust_right = 1.0f;
};

#endif // RECTANGLE_H
