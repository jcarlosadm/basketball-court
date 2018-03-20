#ifndef CIRCLEALGORITHM_H
#define CIRCLEALGORITHM_H

#include "point.h"

class CircleAlgorithm
{
public:
    virtual ~CircleAlgorithm(){}
    virtual void circle(int centerx, int centery, int radius, float color[], Point plotter) = 0;
};

#endif // CIRCLEALGORITHM_H
