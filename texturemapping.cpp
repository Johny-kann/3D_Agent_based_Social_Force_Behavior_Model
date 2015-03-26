#include "texturemapping.h"
#include "datapoints.h"

/*
struct VertexData
{
    QVector3D position;
    QVector3D normal;
    QVector2D texCoord;
};
*/
TextureMapping::TextureMapping(QWidget *parent):
       GLContainer(parent),  m_xrot(0.0f), m_yrot(0.0f), m_zrot(0.0f)
{
 //   initialize();
 //   timer = new QTimer(this);
  //  connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
  //  timer->start(50);
}

TextureMapping::~TextureMapping()
{
    glDeleteTextures(2, &m_texture[0]);
    glDeleteBuffers(4, &m_vboIds[0]);

}

void TextureMapping::timeout()
{
    qDebug()<<"In Timer slot";
}

void TextureMapping::initGeometry()
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


    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[0]);
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(VertexData), vertices, GL_STATIC_DRAW);

    // Transfer index data to VBO 1
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboIds[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 34 * sizeof(GLushort), indices, GL_STATIC_DRAW);


}

/*void TextureMapping::initializeGL()
{
    initialize();
}*/

void TextureMapping::initialize()
{


    qDebug()<<"Initiali T";
    initGeometry();
    loadShader();
    loadGLTexture();
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepthf(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);
}

void TextureMapping::initializeGL()
{
    qDebug()<<"Initiali GL T";
    initializeOpenGLFunctions();
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    initialize();
}

void TextureMapping::render()
{
   // qDebug()<<"TRender";

    m_program->bind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    initializeCamera();

    quintptr offset = 0;

    m_modelView.setToIdentity();
    m_modelView.translate(3.0f, 0.0f, -5.0);

    m_modelView.rotate(m_xrot, 1.0, 0.0, 0.0);
    m_modelView.rotate(m_yrot, 0.0, 1.0, 0.0);

    m_program->setUniformValue("mvpMatrix", m_projection * m_vMatrix * m_modelView);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[2]);
    m_program->enableAttributeArray(m_posAttr);
    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    offset += sizeof(QVector3D);
    m_program->enableAttributeArray(m_normalAttr);
    glVertexAttribPointer(m_normalAttr, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    offset += sizeof(QVector3D);
    m_program->enableAttributeArray(m_texCoordAttr);
    glVertexAttribPointer(m_texCoordAttr, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    glBindTexture(GL_TEXTURE_2D, m_texture[1]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboIds[3]);
    glDrawElements(GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, 0);



    offset = 0;
    m_modelView.setToIdentity();
    m_modelView.translate(0.0f, 0.0f, 0.0);
  m_modelView.rotate(m_xrot, 1.0, 0.0, 0.0);
    m_modelView.rotate(m_yrot, 0.0, 1.0, 0.0);

    m_program->setUniformValue("mvpMatrix", m_projection * m_vMatrix * m_modelView);



    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[2]);
    m_program->enableAttributeArray(m_posAttr);
    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    offset += sizeof(QVector3D);
    m_program->enableAttributeArray(m_normalAttr);
    glVertexAttribPointer(m_normalAttr, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    offset += sizeof(QVector3D);
    m_program->enableAttributeArray(m_texCoordAttr);
    glVertexAttribPointer(m_texCoordAttr, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void *)offset);

    glBindTexture(GL_TEXTURE_2D, m_texture[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboIds[3]);
    glDrawElements(GL_TRIANGLE_STRIP, 34, GL_UNSIGNED_SHORT, 0);

    m_program->release();

   // m_xrot+=0.3f;
  //  m_yrot+=0.3f;
//    m_zrot+=0.4f;
}

void TextureMapping::loadGLTexture()
{
    QImage image(":/image/NeHe.bmp");
    image = image.convertToFormat(QImage::Format_RGB888);
    image = image.mirrored();

    glGenTextures(2, &m_texture[0]);
    glBindTexture(GL_TEXTURE_2D, m_texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width(), image.height(),
                 0, GL_RGB, GL_UNSIGNED_BYTE, image.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage image2(":/image/Crate.bmp");
    image2 = image2.convertToFormat(QImage::Format_RGB888);
    image2 = image2.mirrored();

  //  glActiveTexture(GLText);
    glBindTexture(GL_TEXTURE_2D, m_texture[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image2.width(), image2.height(),
                 0, GL_RGB, GL_UNSIGNED_BYTE, image2.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void TextureMapping::loadShader()
{
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader/vertshader.glsl");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/fragshader.glsl");
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_texCoordAttr = m_program->attributeLocation("texCoordAttr");
    m_normalAttr = m_program->attributeLocation("normalAttr");

}
