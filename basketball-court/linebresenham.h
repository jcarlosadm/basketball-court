#ifndef LINEBRESENHAM_H
#define LINEBRESENHAM_H

#include "linealgorithm.h"

class LineBresenham : public LineAlgorithm
{
public:
    LineBresenham(){}
    ~LineBresenham(){
        this->~LineAlgorithm();
    }
    void line(int x1, int y1, int x2, int y2, float color[3], Point plotter);
};

#endif // LINEBRESENHAM_H
