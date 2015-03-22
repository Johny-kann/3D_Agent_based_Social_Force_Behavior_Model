#include<QApplication>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QDebug>
#include <QMatrix4x4>
#include <QGLShaderProgram>


#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H


class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

protected:
   void initializeGL();

   void resizeGL(int w,int h);

   void paintGL();

   QMatrix4x4 m_projection;
//   QGLShaderProgram sharderProgram;
   QMatrix4x4 m_modelView;

};


#endif // MYGLWIDGET_H
