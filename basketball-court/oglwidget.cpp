#include "oglwidget.h"

#include "circleequation.h"
#include "lineequation.h"

#include <QTimer>

float OGLWidget::lineSize = 1.0f;
float OGLWidget::lineColor[] = {1.0f,1.0f,1.0f};
LineAlgorithm *OGLWidget::lineAlg;
CircleAlgorithm *OGLWidget::circleAlg;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    lineAlg = new LineEquation();
    circleAlg = new CircleEquation();
}

OGLWidget::~OGLWidget(){
    delete lineAlg;
    delete circleAlg;
}

void OGLWidget::setLineSize(float lineSize_)
{
    OGLWidget::lineSize = lineSize_;
}

float OGLWidget::getLineSize()
{
    return OGLWidget::lineSize;
}

void OGLWidget::setLineColorRed(float red)
{
    OGLWidget::lineColor[0] = red;
}

void OGLWidget::setLineColorGreen(float green)
{
    OGLWidget::lineColor[1] = green;
}

void OGLWidget::setLineColorBlue(float blue)
{
    OGLWidget::lineColor[2] = blue;
}

void OGLWidget::setLineAlgorithm(LineAlgorithm *lineAlg)
{
    delete OGLWidget::lineAlg;
    OGLWidget::lineAlg = lineAlg;
}

void OGLWidget::setCircleAlgorithm(CircleAlgorithm *circleAlg)
{
    delete OGLWidget::circleAlg;
    OGLWidget::circleAlg = circleAlg;
}

void OGLWidget::initializeGL()
{
    resizeGL(this->width(),this->height());
}

void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    field.draw(circleAlg,lineAlg, 0,0, OGLWidget::lineColor, plotter);

    glFlush();
}

void OGLWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);

    glOrtho(-800, 800, -600, 600, 1, -1);
}
