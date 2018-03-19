#include "field.h"

#include "rectangle.h"

void Field::draw(CircleAlgorithm *circlealg, LineAlgorithm *linealg, int centerx, int centery, float color[], Point &plotter)
{
    int width = 700;
    int height = 400;

    Rectangle entireField((int)-width/2.0,(int) height/2.0, width, height);
    Rectangle leftSquare((int)-width/2.0,(int) height/4.0,(int) width/5.0,(int) height/2.0);
    Rectangle rightSquare((int)width/2.0 - width/5.0,(int) height/4.0,(int) width/5.0,(int) height/2.0);

    circlealg->circle(centerx,centery, 80, color, plotter);
    entireField.draw(linealg,color,plotter);
    leftSquare.draw(linealg,color,plotter);
    rightSquare.draw(linealg,color,plotter);
}
