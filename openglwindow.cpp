#include "openglwindow.h"

OpenGLWindow::OpenGLWindow(QWindow *parent) :
    QWindow(parent),
    m_update_pending(false),
    m_animating(false),
    m_context(NULL),
    m_show_full_screen(false)
{
    setSurfaceType(QWindow::OpenGLSurface);
    resize(640, 480);

    camera = new Camera(
                0.0,0.0,0.0,0.0,0.0,0.0,5.5);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
  //  timer->start(50);

    setAnimating(true);

    initializeCamera();
}

OpenGLWindow::~OpenGLWindow()
{

}

void OpenGLWindow::render()
{

}

void OpenGLWindow::initialize()
{

}

void OpenGLWindow::resizeGL(int w, int h)
{
    if(h == 0)
    {
        h = 1;
    }
    if (m_context)
    {
        glViewport(0, 0, w, h);
    }
    m_projection.setToIdentity();
    m_projection.perspective(45, (float)w/float(h), 0.1, 1000);
    m_modelView.setToIdentity();
}

void OpenGLWindow::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void OpenGLWindow::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
    //    setXRotation(xRot + 8 * dy);

    //    setYRotation(yRot + 8 * dx);

        camera->addRotateX(-(double)dy/4);
        camera->addRotateY(-(double)dx/4);



    } else if (event->buttons() & Qt::RightButton) {
    //    setXRotation(xRot + 8 * dy);
    //    setZRotation(zRot + 8 * dx);

      //  camera->addRotateX(-(double)dy/4);
        camera->addDistance(-(double)dx/4);
        camera->addRotateZ(-(double)dy/4);
    }



    lastPos = event->pos();
}

void OpenGLWindow::setAnimating(bool animating)
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

void OpenGLWindow::renderLater()
{
    if (!m_update_pending)
    {
        m_update_pending = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

void OpenGLWindow::renderNow()
{
    if (!isExposed())
        return;

    bool needsInitialize = false;

    if (!m_context)
    {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(requestedFormat());
        m_context->create();
        needsInitialize = true;
    }

    m_context->makeCurrent(this);
    if (needsInitialize)
    {
        initializeOpenGLFunctions();
        initialize();
        const qreal retinaScale = devicePixelRatio();
        resizeGL(width()*retinaScale, height()*retinaScale);
    }
    render();

    m_context->swapBuffers(this);

 //   if (m_animating)
   //     renderLater();
}

void OpenGLWindow::timeout()
{
    this->controller->calculateVelocity();

    renderLater();
}
MainController *OpenGLWindow::getController() const
{
    return controller;
}

void OpenGLWindow::setController(MainController *value)
{
    controller = value;
}


bool OpenGLWindow::event(QEvent *event)
{
    switch (event->type())
    {
    case QEvent::UpdateRequest:
        m_update_pending = false;
        renderNow();
            return true;
        default:
            return QWindow::event(event);
    }
}

void OpenGLWindow::exposeEvent(QExposeEvent *event)
{
    if (isExposed())
    {
        renderNow();
    }
    QWindow::exposeEvent(event);
}

void OpenGLWindow::resizeEvent(QResizeEvent *event)
{
    int w = event->size().width();
    int h = event->size().height();
    const qreal retinaScale = devicePixelRatio();
    resizeGL(w*retinaScale, h*retinaScale);
    renderNow();
    QWindow::resizeEvent(event);
}

void OpenGLWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_F1:
        {
            m_show_full_screen = !m_show_full_screen;
            if(m_show_full_screen)
            {
                showFullScreen();
            }
            else
            {
                showNormal();
            }
            break;
        }
        case Qt::Key_Escape:
        {
            qApp->exit();
            break;
        }
    }
    QWindow::keyPressEvent(event);
}

void OpenGLWindow::initializeCamera()
{
    QMatrix4x4 cameraTransformation;

    m_vMatrix.setToIdentity();
    cameraTransformation.setToIdentity();

    cameraTransformation.rotate(camera->getRotateY(),0,1,0);
    cameraTransformation.rotate(camera->getRotateX(),1,0,0);
    cameraTransformation.rotate(camera->getRotateZ(),0,0,1);

    QVector3D cameraPosition = cameraTransformation*QVector3D(0,0,camera->getDistance());
    QVector3D cameraUpDirection = cameraTransformation*QVector3D(0,1,0);

    m_vMatrix.lookAt(cameraPosition, QVector3D(0,0,0),cameraUpDirection);

  //  m_vMatrix.translate(camera->getTranslateX(),camera->getTranslateY(),camera->getTranslateZ());
    QVector3D *temp = camera->getTranslate();
    temp->setX(-temp->x());
  //  temp->setY(-temp->y());
    temp->setZ(-temp->z());
    m_vMatrix.translate(
                *temp
              //  camera->getTranslate()
                );

}

