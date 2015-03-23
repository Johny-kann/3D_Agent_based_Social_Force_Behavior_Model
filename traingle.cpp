#include "traingle.h"

//Traingle::Traingle(QWidget *parent)
//    :QGLWidget(QGLFormat(/* Additional format options */), parent)QGLWidget(QGLFormat(/* Additional format options */), parent)
Traingle::Traingle(QWidget *parent)
        : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

    alpha = 25;
    beta = -25;
    distance = 2.5;

    lightAngle = 0;

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
    timer->start(20);
}

Traingle::~Traingle()
{

}

void Traingle::initializeGL()
{
glEnable(GL_DEPTH_TEST);
glEnable(GL_CULL_FACE);
glClearColor(0.0f,0.0f,0.0f,0.0f);

lightingShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/lightingvertexshader.vsh");
lightingShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/lightingfragmentshader.fsh");
lightingShaderProgram.link();

cubeVertices << QVector3D(-0.5, -0.5, 0.5) << QVector3D( 0.5, -0.5, 0.5) << QVector3D( 0.5, 0.5, 0.5) // Front
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


cubeNormals << QVector3D( 0, 0, 1) << QVector3D( 0, 0, 1) << QVector3D( 0, 0, 1) // Front
    << QVector3D( 0, 0, 1) << QVector3D( 0, 0, 1) << QVector3D( 0, 0, 1)
    << QVector3D( 0, 0, -1) << QVector3D( 0, 0, -1) << QVector3D( 0, 0, -1) // Back
    << QVector3D( 0, 0, -1) << QVector3D( 0, 0, -1) << QVector3D( 0, 0, -1)
    << QVector3D(-1, 0, 0) << QVector3D(-1, 0, 0) << QVector3D(-1, 0, 0) // Left
    << QVector3D(-1, 0, 0) << QVector3D(-1, 0, 0) << QVector3D(-1, 0, 0)
    << QVector3D( 1, 0, 0) << QVector3D( 1, 0, 0) << QVector3D( 1, 0, 0) // Right
    << QVector3D( 1, 0, 0) << QVector3D( 1, 0, 0) << QVector3D( 1, 0, 0)
    << QVector3D( 0, 1, 0) << QVector3D( 0, 1, 0) << QVector3D( 0, 1, 0) // Top
    << QVector3D( 0, 1, 0) << QVector3D( 0, 1, 0) << QVector3D( 0, 1, 0)
    << QVector3D( 0, -1, 0) << QVector3D( 0, -1, 0) << QVector3D( 0, -1, 0) // Bottom
    << QVector3D( 0, -1, 0) << QVector3D( 0, -1, 0) << QVector3D( 0, -1, 0);

cubeTextureCoordinates << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Front
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Back
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Left
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Right
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Top
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
    << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Bottom
    << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0);


//vertices << QVector3D(1, 0, -2) << QVector3D(0, 1, -2) << QVector3D(-1, 0, -2);
/*vertices << QVector3D(-0.5, -0.5, 0.5) << QVector3D( 0.5, -0.5, 0.5) << QVector3D( 0.5, 0.5, 0.5) // Front
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
*/
/*colors << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Front
<< QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)
<< QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0) // Back
<< QVector3D(1, 0, 0) << QVector3D(1, 0, 0) << QVector3D(1, 0, 0)
<< QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Left
<< QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)
<< QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0) // Right
<< QVector3D(0, 1, 0) << QVector3D(0, 1, 0) << QVector3D(0, 1, 0)
<< QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Top
<< QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1)
<< QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1) // Bottom
<< QVector3D(0, 0, 1) << QVector3D(0, 0, 1) << QVector3D(0, 0, 1);
*/

/*textureCoordinates<< QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Front
                  << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                  << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Back
                  << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                  << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Left
                  << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                  << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Right
                  << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                  << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Top
                  << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                  << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Bottom
                  << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0);*/
//
// texture = bindTexture(QPixmap(":/texture.png"));
 cubeTexture = bindTexture(QPixmap(":/texture.png"));

 coloringShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/coloringvertexshader.vsh");
 coloringShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/coloringfragshader.fsh");
 coloringShaderProgram.link();

 spotlightVertices << QVector3D( 0, 1, 0) << QVector3D(-0.5, 0, 0.5) << QVector3D( 0.5, 0, 0.5) // Front
        << QVector3D( 0, 1, 0) << QVector3D( 0.5, 0, -0.5) << QVector3D(-0.5, 0, -0.5) // Back
        << QVector3D( 0, 1, 0) << QVector3D(-0.5, 0, -0.5) << QVector3D(-0.5, 0, 0.5) // Left
        << QVector3D( 0, 1, 0) << QVector3D( 0.5, 0, 0.5) << QVector3D( 0.5, 0, -0.5) // Right
        << QVector3D(-0.5, 0, -0.5) << QVector3D( 0.5, 0, -0.5) << QVector3D( 0.5, 0, 0.5) // Bottom
        << QVector3D( 0.5, 0, 0.5) << QVector3D(-0.5, 0, 0.5) << QVector3D(-0.5, 0, -0.5);

 spotlightColors << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Front
        << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Back
        << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Left
        << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Right
        << QVector3D( 1, 1, 1) << QVector3D( 1, 1, 1) << QVector3D( 1, 1, 1) // Bottom
        << QVector3D( 1, 1, 1) << QVector3D( 1, 1, 1) << QVector3D( 1, 1, 1);


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

void Traingle::timeout()
{
    lightAngle += 1;

    while (lightAngle >= 360)
    {
        lightAngle -= 360;

    }

    updateGL();
}

void Traingle::paintGL()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
QMatrix4x4 mMatrix;
QMatrix4x4 vMatrix;

mMatrix.setToIdentity();

QMatrix4x4 mvMatrix;
mvMatrix = vMatrix * mMatrix;
//vMatrix.setToIdentity();

QMatrix3x3 normalMatrix;
normalMatrix = mvMatrix.normalMatrix();

QMatrix4x4 lightTransformation;
lightTransformation.rotate(lightAngle,0,1,0);

QVector3D lightPosition = lightTransformation*QVector3D(0,1,1);

lightingShaderProgram.bind();
lightingShaderProgram.setUniformValue("mvpMatrix",pMatrix * mvMatrix);
lightingShaderProgram.setUniformValue("mvMatrix",mvMatrix);
lightingShaderProgram.setUniformValue("normalMatrix",normalMatrix);
lightingShaderProgram.setUniformValue("lightPosition", vMatrix * lightPosition);

lightingShaderProgram.setUniformValue("ambientColor",QColor(32,32,32));
lightingShaderProgram.setUniformValue("diffuesColor",QColor(128,128,128));
lightingShaderProgram.setUniformValue("ambientReflection", (GLfloat) 1.0);
lightingShaderProgram.setUniformValue("diffuseReflection", (GLfloat) 1.0);
lightingShaderProgram.setUniformValue("specularReflection", (GLfloat) 1.0);
lightingShaderProgram.setUniformValue("shininess", (GLfloat) 100.0);
lightingShaderProgram.setUniformValue("texture", 0);

glBindTexture(GL_TEXTURE_2D,cubeTexture);
//glActiveTe

lightingShaderProgram.setAttributeArray("vertex", cubeVertices.constData());
lightingShaderProgram.enableAttributeArray("vertex");
lightingShaderProgram.setAttributeArray("normal", cubeNormals.constData());
lightingShaderProgram.enableAttributeArray("normal");
lightingShaderProgram.setAttributeArray("textureCoordinate", cubeTextureCoordinates.constData());
lightingShaderProgram.enableAttributeArray("textureCoordinate");

glDrawArrays(GL_TRIANGLES, 0, cubeVertices.size());

lightingShaderProgram.disableAttributeArray("vertex");
lightingShaderProgram.disableAttributeArray("normal");
lightingShaderProgram.disableAttributeArray("textureCoordinate");
lightingShaderProgram.release();

QMatrix4x4 cameraTransformation;
// qDebug()<<QString("alpha %1 beta %2 distance %3").arg(alpha).arg(beta).arg(distance);
cameraTransformation.rotate(alpha,0,1,0);
cameraTransformation.rotate(beta,1,0,0);

QVector3D cameraPosition = cameraTransformation*QVector3D(0,0,distance);
QVector3D cameraUpDirection = cameraTransformation*QVector3D(0,1,0);

vMatrix.lookAt(cameraPosition, QVector3D(0,0,0),cameraUpDirection);

mMatrix.setToIdentity();
mMatrix.translate(lightPosition);
mMatrix.rotate(lightAngle, 0, 1, 0);
mMatrix.rotate(45, 1, 0, 0);
mMatrix.scale(0.1);

coloringShaderProgram.bind();
coloringShaderProgram.setUniformValue("mvpMatrix", pMatrix * vMatrix * mMatrix);

coloringShaderProgram.setAttributeArray("vertex", spotlightVertices.constData());
coloringShaderProgram.enableAttributeArray("vertex");

coloringShaderProgram.setAttributeArray("color", spotlightColors.constData());
coloringShaderProgram.enableAttributeArray("color");

glDrawArrays(GL_TRIANGLES, 0, spotlightVertices.size());

coloringShaderProgram.disableAttributeArray("vertex");
coloringShaderProgram.disableAttributeArray("color");
coloringShaderProgram.release();


/*
//shaderProgram.setUniformValue("color", QColor(Qt::white));
shaderProgram.setAttributeArray("color",colors.constData());
shaderProgram.enableAttributeArray("color");
*/

/*coloringShaderProgram.setAttributeArray("textureCoordinate", textureCoordinates.constData());
coloringShaderProgram.enableAttributeArray("textureCoordinate");

glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    coloringShaderProgram.disableAttributeArray("vertex");
//    shaderProgram.disableAttributeArray("color");
    coloringShaderProgram.disableAttributeArray("textureCoordinate");

    coloringShaderProgram.release();*/
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
