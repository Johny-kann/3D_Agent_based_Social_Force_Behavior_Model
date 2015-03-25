#include <QOpenGLWidget>
#include "mainwindow.h"
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QMatrix4x4>
#include <QCoreApplication>
#include <QTimer>
#include <QtWidgets>
#include "models.h"

#ifndef GLCONTAINER_H
#define GLCONTAINER_H


class GLContainer :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    GLContainer(QWidget *parent = 0);
    ~GLContainer();
    void setAnimating(bool animating);
    QTimer *timer;

public slots:

    void renderNow();

    void signalDetecter();

    void timeout();


protected:
  //  bool event(QEvent *event);
    Camera *camera;

    void initializeGL();

   void resizeGL(int w,int h);

   void paintGL();

   void initializeCamera();

   virtual void render();

   virtual void initialize();

   void mousePressEvent(QMouseEvent *event);

   void mouseMoveEvent(QMouseEvent *event);

   QMatrix4x4 m_projection;
    QMatrix4x4 m_vMatrix;
   QMatrix4x4 m_modelView;

   QPoint lastPos;

private:
    bool m_update_pending;
    bool m_animating;
    QOpenGLContext *m_context;


};


#endif // GLCONTAINER_H
