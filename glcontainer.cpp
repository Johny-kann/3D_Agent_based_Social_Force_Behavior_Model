
#include <QDebug>
#include "glcontainer.h"

GLContainer::GLContainer(QWidget *parent)
    :QOpenGLWidget(parent)
{
  //  initializeOpenGLFunctions();
  //  glClearColor(0.0f,0.0f,0.0f,0.0f);
}

GLContainer::~GLContainer()
{

}

void GLContainer::initialize()
{

}

void GLContainer::initializeGL()
{

         initializeOpenGLFunctions();
         glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void GLContainer::setAnimating(bool animating)
{
    m_animating = animating;
    if(animating)
    {
        renderLater();
    }
}

void GLContainer::renderLater()
{
    if (!m_update_pending)
    {
        m_update_pending = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

void GLContainer::render()
{
   qDebug()<<"Render";
    glClear(GL_COLOR_BUFFER_BIT);
}
void GLContainer::renderNow()
{
   qDebug()<<"Render now";
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
        initializeOpenGLFunctions();
        initialize();
        const qreal retinaScale = devicePixelRatio();
        resizeGL(width()*retinaScale, height()*retinaScale);
    }
  //  render();

 //   m_context->swapBuffers();
  //  frameSwapped();
    if (m_animating)
        renderLater();

}

void GLContainer::resizeGL(int w,int h)
{
    qDebug()<<"Resize";
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
    renderNow();
}

void GLContainer::paintGL()
{
   qDebug()<<"Paint";
    GLContainer::render();
  //   qDebug()<<"Paint is met";
}
