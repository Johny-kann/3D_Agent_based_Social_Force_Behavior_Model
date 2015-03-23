#include <QOpenGLWidget>
#include "mainwindow.h"
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QMatrix4x4>
#include <QCoreApplication>

#ifndef GLCONTAINER_H
#define GLCONTAINER_H


class GLContainer :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    GLContainer(QWidget *parent = 0);
    ~GLContainer();
    void setAnimating(bool animating);

public slots:
    void renderLater();

    void renderNow();

    void signalDetecter();


protected:
  //  bool event(QEvent *event);

    void initializeGL();

   void resizeGL(int w,int h);

   void paintGL();

   virtual void render();

   virtual void initialize();

  //  QMatrix4x4 m_projection;
//   QGLShaderProgram sharderProgram;
 //  QMatrix4x4 m_modelView;
   QMatrix4x4 m_projection;

   QMatrix4x4 m_modelView;

private:
    bool m_update_pending;
    bool m_animating;
    QOpenGLContext *m_context;
};


#endif // GLCONTAINER_H
