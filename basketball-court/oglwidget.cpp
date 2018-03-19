#include "oglwidget.h"

#include "field.h"
#include "circleequation.h"
#include "circlealgorithm.h"
#include "lineequation.h"
#include "linealgorithm.h"
#include "point.h"

#include <QTimer>

float OGLWidget::lineSize = 1.0f;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
}

OGLWidget::~OGLWidget()
{

}

void OGLWidget::setLineSize(float lineSize_)
{
    OGLWidget::lineSize = lineSize_;
}

float OGLWidget::getLineSize()
{
    return OGLWidget::lineSize;
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
