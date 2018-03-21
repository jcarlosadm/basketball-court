#include "field.h"

#include "rectangle.h"

void Field::draw(CircleAlgorithm *circlealg, LineAlgorithm *linealg, int centerx, int centery, float color[], Point &plotter)
{
    int width = 1000;
    int height = 500;

    // setup
    Rectangle entireField((int)-width/2.0,(int) height/2.0, width, height);
    Rectangle leftSquare((int)-width/2.0,(int) height/6.0 - 23,(int) width/5.0,(int) height/4.0 - 5);
    Rectangle rightSquare((int)width/2.0 - width/5.0,(int) height/6.0 - 23,(int) width/5.0,(int) height/4.0 - 5);

    // draw
    circlealg->circle(centerx,centery, 100, color, plotter);
    circlealg->circle(centerx,centery, 20, color, plotter);

    entireField.draw(linealg,color,plotter);
    leftSquare.draw(linealg,color,plotter);
    rightSquare.draw(linealg,color,plotter);
    linealg->line(centerx, centery - (int) height/2.0, centerx, centery + (int) height/2.0,color, plotter);

    circlealg->circle((int)-width/2.0 + (int) width/5.0,centery, 50, color, plotter);
    circlealg->circle((int) width/2.0 - (int) width/5.0,centery, 50, color, plotter);

    circlealg->circle((int)-width/2.0 + 45,centery, 10, color, plotter);
    circlealg->circle((int) width/2.0 - 45,centery, 10, color, plotter);

    linealg->line((int) - width/2.0 + 35, centery + 20, (int) -width/2.0 + 35, centery - 20, color, plotter);
    linealg->line((int) width/2.0 - 35, centery + 20, (int) width/2.0 - 35, centery - 20, color, plotter);

    linealg->line((int) - width/2.0, centery + (int) height/3.0, (int) -width/2.0 + (int) width/7.0,
                  centery + (int) height/3.0, color, plotter);
    linealg->line((int) - width/2.0, centery - (int) height/3.0, (int) -width/2.0 + (int) width/7.0,
                  centery - (int) height/3.0, color, plotter);
    linealg->line((int) width/2.0, centery + (int) height/3.0, (int) width/2.0 - (int) width/7.0,
                  centery + (int) height/3.0, color, plotter);
    linealg->line((int) width/2.0, centery - (int) height/3.0, (int) width/2.0 - (int) width/7.0,
                  centery - (int) height/3.0, color, plotter);

    circlealg->semicircle_right((int) -width/2.0 + (int) width/7.0, centery, (int) height/3.0, color, plotter);
    circlealg->semicircle_left((int) width/2.0 - (int) width/7.0, centery, (int) height/3.0, color, plotter);
}
