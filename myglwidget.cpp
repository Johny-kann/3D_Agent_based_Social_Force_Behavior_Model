#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
        :QOpenGLWidget(parent)
{
    QSurfaceFormat format;
       format.setDepthBufferSize(24);
       format.setStencilBufferSize(8);
       format.setVersion(3, 2);
       format.setProfile(QSurfaceFormat::CoreProfile);
       QSurfaceFormat::setDefaultFormat(format);

       this->setFormat(format);
       qDebug()<<"Format is set";
}

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::initializeGL()
{

         initializeOpenGLFunctions();
         glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void MyGLWidget::resizeGL(int w,int h)
{
    m_projection.setToIdentity();
    m_projection.perspective(45, (float)w/float(h), 1, 1000);
    m_modelView.setToIdentity();
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
