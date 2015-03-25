
#include <QDebug>
#include "glcontainer.h"

GLContainer::GLContainer(QWidget *parent)
    :QOpenGLWidget(parent),m_update_pending(false)
{

    camera = new Camera(
                0.0,0.0,0.0,0.0,0.0,0.0);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
  //  timer->start(50);

    setAnimating(true);

    initializeCamera();

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
   //     qDebug()<<"Timer on";
        timer->start(50);
    }
    else
    {
     //   qDebug()<<"Timer off";
        timer->stop();
    }
}

void GLContainer::signalDetecter()
{
    qDebug()<<"Signal Detected";
}

void GLContainer::initializeCamera()
{
    QMatrix4x4 cameraTransformation;

    m_vMatrix.setToIdentity();
    cameraTransformation.setToIdentity();
//    double alpha = 20.0;
//    double beta = 0.0;
    double distance = 2.5;
    // qDebug()<<QString("alpha %1 beta %2 distance %3").arg(alpha).arg(beta).arg(distance);
    cameraTransformation.rotate(camera->getRotateY(),0,1,0);
    cameraTransformation.rotate(camera->getRotateX(),1,0,0);
    cameraTransformation.rotate(camera->getRotateZ(),0,0,1);

    QVector3D cameraPosition = cameraTransformation*QVector3D(0,0,distance);
    QVector3D cameraUpDirection = cameraTransformation*QVector3D(0,1,0);

    m_vMatrix.lookAt(cameraPosition, QVector3D(0,0,0),cameraUpDirection);
}

void GLContainer::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLContainer::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
    //    setXRotation(xRot + 8 * dy);

    //    setYRotation(yRot + 8 * dx);

        camera->addRotateX((double)dy/4);
        camera->addRotateY((double)dx/4);

    } else if (event->buttons() & Qt::RightButton) {
    //    setXRotation(xRot + 8 * dy);
    //    setZRotation(zRot + 8 * dx);

        camera->addRotateX((double)dy/4);
        camera->addRotateZ((double)dx/4);
    }


    lastPos = event->pos();

}

void GLContainer::timeout()
{

    update();
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

    glClear(GL_COLOR_BUFFER_BIT);
}



void GLContainer::renderNow()
{

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
 //   qDebug()<<"Resize B "<<w<<" "<<h;
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
  // qDebug()<<"Paint B";
    renderNow();
  //   qDebug()<<"Paint is met";
}
