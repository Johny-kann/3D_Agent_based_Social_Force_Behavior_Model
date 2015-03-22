#include "traingle.h"

//Traingle::Traingle(QWidget *parent)
//    :QGLWidget(QGLFormat(/* Additional format options */), parent)QGLWidget(QGLFormat(/* Additional format options */), parent)
Traingle::Traingle(QWidget *parent)
        : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

    alpha = 25;
    beta = -25;
    distance = 2.5;
}

Traingle::~Traingle()
{

}

void Traingle::initializeGL()
{
glEnable(GL_DEPTH_TEST);
glEnable(GL_CULL_FACE);
glClearColor(0.0f,0.0f,0.0f,0.0f);
shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/vertshader.glsl");
shaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/fragshader.glsl");
shaderProgram.link();
//vertices << QVector3D(1, 0, -2) << QVector3D(0, 1, -2) << QVector3D(-1, 0, -2);
vertices << QVector3D(-0.5, -0.5, 0.5) << QVector3D( 0.5, -0.5, 0.5) << QVector3D( 0.5, 0.5, 0.5) // Front
<< QVector3D( 0.5, 0.5, 0.5) << QVector3D(-0.5, 0.5, 0.5) << QVector3D(-0.5, -0.5, 0.5)
<< QVector3D( 0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5, 0.5, -0.5) // Back
<< QVector3D(-0.5, 0.5, -0.5) << QVector3D( 0.5, 0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5)
<< QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, 0.5) << QVector3D(-0.5, 0.5, 0.5) // Left
<< QVector3D(-0.5, 0.5, 0.5) << QVector3D(-0.5, 0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5)
<< QVector3D( 0.5, -0.5, 0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5, 0.5, -0.5) // Right
<< QVector3D( 0.5, 0.5, -0.5) << QVector3D( 0.5, 0.5, 0.5) << QVector3D( 0.5, -0.5, 0.5)
<< QVector3D(-0.5, 0.5, 0.5) << QVector3D( 0.5, 0.5, 0.5) << QVector3D( 0.5, 0.5, -0.5) // Top
<< QVector3D( 0.5, 0.5, -0.5) << QVector3D(-0.5, 0.5, -0.5) << QVector3D(-0.5, 0.5, 0.5)
<< QVector3D(-0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, 0.5) // Bottom
<< QVector3D( 0.5, -0.5, 0.5) << QVector3D(-0.5, -0.5, 0.5) << QVector3D(-0.5, -0.5, -0.5);
}

void Traingle::resizeGL(int width, int height)
{
if (height == 0) {
height = 1;
}
pMatrix.setToIdentity();
pMatrix.perspective(60.0, (float) width / (float) height, 0.001, 1000);
glViewport(0, 0, width, height);
}

void Traingle::paintGL()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
QMatrix4x4 mMatrix;
QMatrix4x4 vMatrix;

QMatrix4x4 cameraTransformation;
cameraTransformation.rotate(alpha,0,1,0);
cameraTransformation.rotate(beta,1,0,0);

QVector3D cameraPosition = cameraTransformation*QVector3D(0,0,distance);
QVector3D cameraUpDirection = cameraTransformation*QVector3D(0,1,0);

vMatrix.lookAt(cameraPosition, QVector3D(0,0,0),cameraUpDirection);
shaderProgram.bind();
shaderProgram.setUniformValue("mvpMatrix", pMatrix * vMatrix * mMatrix);
shaderProgram.setUniformValue("color", QColor(Qt::white));
shaderProgram.setAttributeArray("vertex", vertices.constData());
shaderProgram.enableAttributeArray("vertex");
glDrawArrays(GL_TRIANGLES, 0, vertices.size());
shaderProgram.disableAttributeArray("vertex");
shaderProgram.release();
}

void Traingle::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();

    event->accept();
}

void Traingle::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if(event->buttons() & Qt::LeftButton)
    {
        alpha -= deltaX;
        while(alpha < 0)
        {
            alpha += 360;
        }

        while (alpha >= 360) {
        alpha -= 360;
        }

        beta -= deltaY;

        if (beta < -90) {
        beta = -90;
        }

        if (beta > 90) {
        beta = 90;
        }

        updateGL();
    }
    lastMousePosition = event->pos();
    event->accept();
}

void Traingle::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();

    if(event->orientation() == Qt::Vertical)
    {
        if(delta<0)
        {
            distance *= 1.1;
        }else if(delta > 0)
        {
            distance *= 0.9;
        }

        updateGL();
    }

    event->accept();
}

QSize Traingle::sizeHint() const
{
return QSize(640, 480);
}
