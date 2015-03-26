#include "texturemappingwindow.h"
#include<QDebug>

GLfloat lightv = 0.0;
double alpha = 0.0;
double beta = 0.0;
double distance = 2.5;

/*struct VertexData
{
    QVector3D position;
    QVector3D normal;
    QVector2D texCoord;
};*/

QVector4D LightAmbient = QVector4D(0.5f, 0.5f, 0.5f, 1.0f);
QVector4D LightDiffuse = QVector4D(1.0f, 1.0f, 1.0f, 1.0f);
QVector4D LightPosition = QVector4D(0.0f, 0.0f, 2.0f, 1.0f);
QVector4D LightModelAmbient = QVector4D(0.2, 0.2, 0.2, 1.0);
QVector4D MaterialDiffuse = QVector4D(0.8f, 0.8f, 0.8f, 1.0f);
QVector4D MaterialAmbient = QVector4D(0.2f, 0.2f, 0.2f, 1.0f);






World *TextureMappingWindow::getWorld() const
{
    return world;
}

void TextureMappingWindow::setWorld(World *value)
{
    world = value;
}
TextureMappingWindow::TextureMappingWindow(QWindow *parent) :
    OpenGLWindow(parent), m_xrot(0.0f), m_yrot(0.0f), m_xspeed(0.0f),
    m_yspeed(0.0f), m_z(0.0f), m_light(false), m_filter(0)
{
/*    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerout()));
 //   timer->start(20);*/
}

TextureMappingWindow::~TextureMappingWindow()
{
    glDeleteTextures(3, &m_texture[0]);
    glDeleteBuffers(2, &m_vboIds[0]);

}

void TextureMappingWindow::timerout()
{
    alpha+=1.0;
}

void TextureMappingWindow::initialize()
{
    qDebug()<<"Initialize";
    initGeometry();
    loadShader();
    loadGLTexture(world->getHurdlesList().operator [](0).getTextureImage());
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepthf(1.0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);
}

void TextureMappingWindow::render()
{


    QMatrix4x4 lightTransformation;
    lightTransformation.rotate(lightv, 1, 0, 0);

    m_program->bind();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(int i=0 ; i<world->getHurdlesList().size();i++)
    {

  //  loadGLTexture(world.getHurdlesList().operator [](i).getTextureImage());
    m_program->setUniformValue("lightPos", lightTransformation * LightPosition);
    m_program->setUniformValue("lightDiffuse", LightDiffuse);
    m_program->setUniformValue("lightAmbient", LightAmbient);
    m_program->setUniformValue("lightModelAmbient", LightModelAmbient);
    m_program->setUniformValue("materialDiffuse", MaterialDiffuse);
    m_program->setUniformValue("materialAmbient", MaterialAmbient);
    m_program->setUniformValue("enableLight", m_light);


 //   QVector3D lightPosition = lightTransformation * QVector3D(0, 1, 1);

 //   QMatrix4x4 vMatrix;
 //   vMatrix.setToIdentity();
 //   vMatrix.rotate(lightv, 0.0, 1.0, 0.0);
    m_modelView.setToIdentity();

    m_modelView.translate(0.0f, 0.0f, m_z);
    m_modelView.rotate(m_xrot, 1.0, 0.0, 0.0);
    m_modelView.rotate(m_yrot, 0.0, 1.0, 0.0);

 //   m_modelView.rotate(lightv, 0.0, 1.0, 0.0);

    m_program->setUniformValue("mvMatrix",m_vMatrix * m_modelView);

      initializeCamera();

       quintptr offset = 0;

    m_modelView.setToIdentity();
  //  m_modelView.translate(3.0f, 0.0f, -5.0f);
    m_modelView.translate(world->getHurdlesList().operator [](i).getTransPos());

    m_modelView.rotate(world->getHurdlesList().operator [](i).getRotatePos().x(), 1.0, 0.0, 0.0);
    m_modelView.rotate(world->getHurdlesList().operator [](i).getRotatePos().y(), 0.0, 1.0, 0.0);
    m_modelView.rotate(world->getHurdlesList().operator [](i).getRotatePos().z(), 0.0, 0.0, 1.0);



    m_program->setUniformValue("mvpMatrix", m_projection * m_vMatrix * m_modelView);



    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[0]);
    m_program->enableAttributeArray(m_posAttr);
    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    offset += sizeof(QVector3D);
    m_program->enableAttributeArray(m_normalAttr);
    glVertexAttribPointer(m_normalAttr, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    offset += sizeof(QVector3D);
    m_program->enableAttributeArray(m_texCoordAttr);
    glVertexAttribPointer(m_texCoordAttr, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    glBindTexture(GL_TEXTURE_2D, m_texture[m_filter]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboIds[1]);
    glDrawElements(GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, 0);

}

    m_program->release();


}

void TextureMappingWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_L:
        {
            m_light = !m_light;
            break;
        }
        case Qt::Key_F:
        {
            m_filter+=1;
            if(m_filter > 2)
            {
                m_filter = 0;
            }
            break;
        }
        case Qt::Key_PageUp:
        {
            m_z-=0.2f;
            break;
        }
        case Qt::Key_PageDown:
        {
            m_z+=0.2f;
            break;
        }

    case Qt::Key_Q:
    {
        lightv-=0.5f;
        qDebug()<<lightv;
        break;
    }
    case Qt::Key_E:
    {
        lightv+=0.5f;
        qDebug()<<lightv;
        break;
    }

    case Qt::Key_V:
    {
        alpha+=0.5f;
        qDebug()<<alpha;
        break;
    }
    case Qt::Key_B:
    {
        alpha-=0.5f;
        qDebug()<<alpha;
        break;
    }
    case Qt::Key_N:
    {
        distance+=0.5f;
        qDebug()<<distance;
        break;
    }
    case Qt::Key_C:
    {
        distance-=0.5f;
        qDebug()<<distance;
        break;
    }
        case Qt::Key_Up:
        {
            camera->addTranslateX(0.5f);
            break;
        }
        case Qt::Key_Down:
        {
            camera->addTranslateX(-0.5f);
            break;
        }
        case Qt::Key_Right:
        {
            camera->addTranslateZ(0.5f);
            break;
        }
        case Qt::Key_Left:
        {
            camera->addTranslateZ(-0.5f);
            break;
        }
    }
    OpenGLWindow::keyPressEvent(event);
}

void TextureMappingWindow::loadGLTexture(QString imageLoc)
{
    QImage image(imageLoc);
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();

    glGenTextures(3, &m_texture[0]);

    glBindTexture(GL_TEXTURE_2D, m_texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width(), image.height(),
                 0, GL_RGB, GL_UNSIGNED_BYTE, image.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, m_texture[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width(), image.height(),
                 0, GL_RGB, GL_UNSIGNED_BYTE, image.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, m_texture[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width(), image.height(),
                 0, GL_RGB, GL_UNSIGNED_BYTE, image.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);

    glGenerateMipmap(GL_TEXTURE_2D);
}

void TextureMappingWindow::loadShader()
{
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/vertshader.glsl");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/fragshader.glsl");
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_texCoordAttr = m_program->attributeLocation("texCoordAttr");
    m_normalAttr = m_program->attributeLocation("normalAttr");
}

void TextureMappingWindow::initGeometry()
{
    glGenBuffers(2, &m_vboIds[0]);
    CubePoints cube1;


    VertexData *vertices = new VertexData[cube1.getVertices().size()];;

    GLushort *indices = new GLushort[cube1.getIndices().size()];


  //  VertexData *vert = new VertexData[cube1.getVertices().size()];

    for(int i=0;i<cube1.getVertices().size();i++)
    {
        vertices[i]=cube1.getVertices().at(i);
    }

  //  GLushort *ind = new GLushort[cube1.getIndices().size()];

    for(int i=0;i<cube1.getIndices().size();i++)
    {
        indices[i]=cube1.getIndices().at(i);
    }




  //  CubePoints cube1;
  //  Camera *camera = new Camera(0,0,0,0,0,0,5);

  //  VertexData *vert = cube1.getVertices();
    // Transfer vertex data to VBO 0
    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[0]);
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(VertexData), vertices, GL_STATIC_DRAW);

    // Transfer index data to VBO 1
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboIds[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 34 * sizeof(GLushort), indices, GL_STATIC_DRAW);
}

