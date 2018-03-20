#include "field.h"

#include "rectangle.h"

void Field::draw(CircleAlgorithm *circlealg, LineAlgorithm *linealg, int centerx, int centery, float color[], Point &plotter)
{
    int width = 1000;
    int height = 500;

    Rectangle entireField((int)-width/2.0,(int) height/2.0, width, height);
    Rectangle leftSquare((int)-width/2.0,(int) height/4.0,(int) width/5.0,(int) height/2.0);
    leftSquare.adjustright(0.7f);
    Rectangle rightSquare((int)width/2.0 - width/5.0,(int) height/4.0,(int) width/5.0,(int) height/2.0);
    rightSquare.adjustleft(0.7f);

    circlealg->circle(centerx,centery, 80, color, plotter);

    entireField.draw(linealg,color,plotter);
    leftSquare.draw(linealg,color,plotter);
    rightSquare.draw(linealg,color,plotter);
    linealg->line(centerx, centery - (int) height/2.0, centerx, centery + (int) height/2.0,color, plotter);

    circlealg->circle(centerx-(int)width/2.5,centery, 40, color, plotter);
    circlealg->circle(centerx+(int)width/2.5,centery, 40, color, plotter);
}
