#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <QMouseEvent>
#include <list>
#include <rectangle.h>

#include "linealgorithm.h"
#include "circlealgorithm.h"
#include "field.h"
#include "point.h"

class OGLWidget : public QOpenGLWidget
{
public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();
    static void setLineSize(float lineSize_);
    static float getLineSize();
    static void setLineColorRed(float red);
    static void setLineColorGreen(float green);
    static void setLineColorBlue(float blue);
    static void setLineAlgorithm(LineAlgorithm *lineAlg);
    static void setCircleAlgorithm(CircleAlgorithm *circleAlg);
    static LineAlgorithm* getLineAlg();
    static CircleAlgorithm* getCircleAlg();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);

private:
    Field field;
    Point plotter;

    static std::vector<int> points;
    static int _width;
    static int _height;
    static float lineSize;
    static float lineColor[];
    static LineAlgorithm * lineAlg;
    static CircleAlgorithm * circleAlg;
};

#endif // OGLWIDGET_H
