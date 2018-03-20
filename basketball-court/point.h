#ifndef POINT_H
#define POINT_H

#include <GL/glu.h>
#include <GL/gl.h>

class Point
{
public:
    Point(){}
    void draw(int x, int y, float color[3]);
};

#endif // POINT_H
