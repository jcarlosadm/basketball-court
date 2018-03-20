#ifndef FIELD_H
#define FIELD_H

#include "point.h"
#include "circlealgorithm.h"
#include "linealgorithm.h"

class Field
{
public:
    Field(){}
    void draw(CircleAlgorithm *circlealg, LineAlgorithm *linealg, int centerx, int centery, float color[], Point &plotter);
};

#endif // FIELD_H
