#include "oglwidget.h"

#include "circleequation.h"
#include "lineequation.h"

#include <QTimer>

float OGLWidget::lineSize = 1.0f;
float OGLWidget::lineColor[] = {1.0f,1.0f,1.0f};
LineAlgorithm *OGLWidget::lineAlg;
CircleAlgorithm *OGLWidget::circleAlg;
std::vector<int> OGLWidget::points;
int OGLWidget::_width;
int OGLWidget::_height;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    lineAlg = new LineEquation();
    circleAlg = new CircleEquation();

    OGLWidget::_width = this->width();
    OGLWidget::_height = this->height();
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

LineAlgorithm *OGLWidget::getLineAlg()
{
    return OGLWidget::lineAlg;
}

CircleAlgorithm *OGLWidget::getCircleAlg()
{
    return OGLWidget::circleAlg;
}

void OGLWidget::initializeGL()
{
    resizeGL(this->width(),this->height());
}

void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    field.draw(circleAlg,lineAlg, 0,0, OGLWidget::lineColor, plotter);

    if (points.size() > 1) {
        for (unsigned int n = 0; n < points.size(); ++n) {
            if (n % 2 != 0) {
                //plotter.draw(points.at(n - 1), points.at(n), OGLWidget::lineColor);

                int x = points.at(n - 1);
                int y = points.at(n);

                Rectangle rectangle(x, y, 800, 50);
                rectangle.draw(lineAlg, OGLWidget::lineColor, plotter);
            }
        }
    }

    glFlush();
}

void OGLWidget::mousePressEvent(QMouseEvent *event)
{
    //std::cout << "CLICK" << std::endl;
    std::cout << "x: " << event->x() << " y: " << event->y() << std::endl;

    /*Point plotter;
    int x = event->x();
    int y = event->y();
    float color[] = {0.0f, 0.5f, 0.5f};

    plotter.draw(x, y, color);*/
    //std::cout << points.size() << std::endl;

    int x = (int) (event->x() * 1600) / (float) (OGLWidget::width()) - 800;
    int y = -((int) (event->y() * 1200) / (float) (OGLWidget::height()) - 600);

    std::cout << "width: " << OGLWidget::width() << std::endl;

    points.push_back(x);
    points.push_back(y);
}

void OGLWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);

    glOrtho(-800, 800, -600, 600, 1, -1);

}
