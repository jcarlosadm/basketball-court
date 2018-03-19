#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/glu.h>
#include <GL/gl.h>

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

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    static float lineSize;
    static float lineColor[];
};

#endif // OGLWIDGET_H
