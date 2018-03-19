#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"
#include "linealgorithm.h"

class Rectangle
{
public:
    Rectangle(int x, int y, int width, int height);
    void draw(LineAlgorithm *lineAlgorithm,float color[], Point &plotter);

private:
    int x, y, width, height;
};

#endif // RECTANGLE_H
