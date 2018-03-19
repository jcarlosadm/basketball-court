#include "oglwidget.h"

#include "field.h"
#include "circleequation.h"
#include "circlealgorithm.h"
#include "lineequation.h"
#include "linealgorithm.h"
#include "point.h"

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

OGLWidget::~OGLWidget()
{

}

void OGLWidget::initializeGL()
{
    resizeGL(this->width(),this->height());
}

void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Field field;
    LineEquation line;
    CircleEquation circle;

    LineAlgorithm * lineAlg = &line;
    CircleAlgorithm * circleAlg = &circle;

    float color[] = {1.0f,0.0f,0.0f};
    Point plotter;

    field.draw(circleAlg,lineAlg, 0,0,color,plotter);

    glFlush();
}

void OGLWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);

    //qreal aspectratio = qreal(w) / qreal(h);
    glOrtho(-800, 800, -600, 600, 1, -1);
}
