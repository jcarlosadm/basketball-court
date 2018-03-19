#ifndef LINEEQUATION_H
#define LINEEQUATION_H

#include "linealgorithm.h"

class LineEquation : public LineAlgorithm
{
public:
    LineEquation();
    void line(int x1, int y1, int x2, int y2, float color[3], Point plotter);
};

#endif // LINEEQUATION_H
