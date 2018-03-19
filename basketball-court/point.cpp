#include "point.h"

void Point::draw(int x, int y, float color[])
{
    glBegin(GL_POINTS);
    glColor3f(color[0],color[1],color[2]);
    glVertex2i(x, y);
    glEnd();
}
