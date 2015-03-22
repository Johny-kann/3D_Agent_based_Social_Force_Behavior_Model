#include "QOpenGLWidget"
#include "myglwidget.h"
#include <QMouseEvent>

#ifndef TRAINGLE_H
#define TRAINGLE_H


class Traingle : public QGLWidget
{
    Q_OBJECT

public:
    Traingle(QWidget *parent = 0);
    ~Traingle();
    QSize sizeHint() const;

protected:

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QMatrix4x4 pMatrix;
    QGLShaderProgram shaderProgram;
    QVector<QVector3D> vertices;
    QVector<QVector3D> colors;

    double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;

};

#endif // TRAINGLE_H
