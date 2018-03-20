#ifndef LINEALGORITHM_H
#define LINEALGORITHM_H

#include "point.h"

class LineAlgorithm
{
public:
    virtual ~LineAlgorithm(){}
    virtual void line(int x1, int y1, int x2, int y2, float color[3], Point plotter) = 0;
};

#endif // LINEALGORITHM_H
