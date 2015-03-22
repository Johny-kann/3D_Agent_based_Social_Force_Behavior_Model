#ifndef POLYGONWINDOW_H
#define POLYGONWINDOW_H
#include <QOpenGLShaderProgram>
#include "myglwidget.h"

class PolygonWindow : public MyGLWidget
{
    Q_OBJECT
public:
    explicit PolygonWindow(QWidget *parent = 0);
    ~PolygonWindow();
protected:
    void initializeGL();
    void paintGL();
    void render();
private:
    void initGeometry();
private:
    QOpenGLShaderProgram m_program;
    QVector<QVector3D> vertices;
    GLuint m_posAttr;

    GLuint m_vboIds[2];
};

#endif // POLYGONWINDOW_H
