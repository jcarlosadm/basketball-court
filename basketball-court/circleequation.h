#ifndef CIRCLEEQUATION_H
#define CIRCLEEQUATION_H

#include "circlealgorithm.h"
#include <cmath>

class CircleEquation : public CircleAlgorithm
{
public:
    CircleEquation(){}
    ~CircleEquation(){
        this->~CircleAlgorithm();
    }
    void circle(int centerx, int centery, int radius, float color[], Point plotter);
    void semicircle_left(int centerx, int centery, int radius, float color[], Point plotter);
    void semicircle_right(int centerx, int centery, int radius, float color[], Point plotter);
};

#endif // CIRCLEEQUATION_H
