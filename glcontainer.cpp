
#include <QDebug>
#include "glcontainer.h"

GLContainer::GLContainer(QWidget *parent)
    :QOpenGLWidget(parent),m_update_pending(false),m_animating(false)
{
  //  initializeOpenGLFunctions();
  //  glClearColor(0.0f,0.0f,0.0f,0.0f); timer = new QTimer(this);
    timer = new QTimer(this);
 //   connect(timer,SIGNAL(timeout()),this,timeout());
 //   timer->start(50);
    setAnimating(false);

}

GLContainer::~GLContainer()
{

}

void GLContainer::initialize()
{
qDebug()<<"Initiali";
}

void GLContainer::initializeGL()
{
        qDebug()<<"Init B GL";
         initializeOpenGLFunctions();
         glClearColor(0.0f,0.0f,0.0f,0.0f);


}

void GLContainer::setAnimating(bool animating)
{
    m_animating = animating;
   /* if(animating)
    {
        renderLater();
    }*/
    if(animating)
    {
        qDebug()<<"Timer on";
        timer->start(50);
    }
    else
    {
        qDebug()<<"Timer off";
        timer->stop();
    }
}

void GLContainer::signalDetecter()
{
    qDebug()<<"Signal Detected";
}

void GLContainer::timeout()
{

}

/*
bool GLContainer::event(QEvent *event)
{
    switch (event->type())
    {
        case QEvent::UpdateRequest:
            m_update_pending = false;
            renderNow();
            return true;
        default:
            return QWidget::event(event);
    }
}
*/

void GLContainer::render()
{
   qDebug()<<"Render B";
    glClear(GL_COLOR_BUFFER_BIT);
}



void GLContainer::renderNow()
{
   qDebug()<<"Render now GL";
    /* if (!isExposed())
        return;
*/
    bool needsInitialize = false;

    if (!m_context)
    {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(format());
        m_context->create();
        needsInitialize = true;
    }

 //   qDebug()<<m_context->makeCurrent(format());
    makeCurrent();
    if (needsInitialize)
    {
       // initializeOpenGLFunctions();
        initialize();
        const qreal retinaScale = devicePixelRatio();
        resizeGL(width()*retinaScale, height()*retinaScale);
    }
    render();

 //   m_context->swapBuffers();
 //   frameSwapped();

}



void GLContainer::resizeGL(int w,int h)
{
    qDebug()<<"Resize B "<<w<<" "<<h;
    if(h == 0)
    {
        h = 1;
    }
    if (m_context)
    {
        glViewport(0, 0, w, h);
    }
    m_projection.setToIdentity();
    m_projection.perspective(45, (float)w/float(h), 1, 1000);
    m_modelView.setToIdentity();
  //  renderNow();
}

void GLContainer::paintGL()
{
   qDebug()<<"Paint B";
    renderNow();
  //   qDebug()<<"Paint is met";
}