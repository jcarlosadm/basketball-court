#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
}

void Rectangle::draw(LineAlgorithm *lineAlgorithm, float color[], Point &plotter)
{
    lineAlgorithm->line(this->x, this->y, this->x + this->width, this->y, color, plotter);
    lineAlgorithm->line(this->x + this->width, this->y, this->x + this->width, this->y - this->height, color, plotter);
    lineAlgorithm->line(this->x + this->width, this->y - this->height, this->x, this->y - this->height, color, plotter);
    lineAlgorithm->line(this->x, this->y - this->height, this->x, this->y, color, plotter);
}
