#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
}

void Rectangle::draw(LineAlgorithm *lineAlgorithm, float color[], Point plotter)
{

    int adjl = (int) ((height*(1.0-adjust_left))/2.0);
    int adjr = (int) ((height*(1.0-adjust_right))/2.0);

    lineAlgorithm->line(this->x,
                        this->y - adjl,
                        this->x + this->width,
                        this->y - adjr,
                        color, plotter);

    lineAlgorithm->line(this->x + this->width,
                        this->y - adjr,
                        this->x + this->width,
                        this->y - this->height + adjr,
                        color, plotter);

    lineAlgorithm->line(this->x + this->width,
                        this->y - this->height + adjr,
                        this->x,
                        this->y - this->height + adjl,
                        color, plotter);

    lineAlgorithm->line(this->x,
                        this->y - this->height + adjl,
                        this->x,
                        this->y - adjl,
                        color, plotter);
}

void Rectangle::adjustleft(float adjust)
{
    this->adjust_left = adjust;
}

void Rectangle::adjustright(float adjust)
{
    this->adjust_right = adjust;
}
