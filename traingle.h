#include "QOpenGLWidget"
#include "myglwidget.h"
#include <QMouseEvent>
#include <QTimer>



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
    QGLShaderProgram coloringShaderProgram;
    QGLShaderProgram lightingShaderProgram;

    QVector<QVector3D> cubeVertices;
    QVector<QVector3D> cubeNormals;
    QVector<QVector2D> cubeTextureCoordinates;

    GLuint cubeTexture;

    QGLShaderProgram coloringShadeProgram;
    QVector<QVector3D> spotlightVertices;
    QVector<QVector3D> spotlightColors;


    double lightAngle;
    QVector<QVector3D> vertices;
 //   QVector<QVector3D> colors;
    QVector<QVector2D> textureCoordinates;
    GLuint texture;

    double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;

private Q_SLOTS:
    void timeout();

};

#endif // TRAINGLE_H
