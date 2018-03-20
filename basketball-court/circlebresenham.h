#ifndef CIRCLEBRESENHAM_H
#define CIRCLEBRESENHAM_H

#include "circlealgorithm.h"

class CircleBresenham : public CircleAlgorithm
{
public:
    CircleBresenham(){}
    ~CircleBresenham(){
        this->~CircleAlgorithm();
    }
    void circle(int centerx, int centery, int radius, float color[], Point plotter);
};

#endif // CIRCLEBRESENHAM_H
