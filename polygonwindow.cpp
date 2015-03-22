#include "polygonwindow.h"

PolygonWindow::PolygonWindow(QWidget *parent) :
    MyGLWidget(parent)
{
  //  m_program = NULL;
    QSurfaceFormat format;
       format.setDepthBufferSize(24);
       format.setStencilBufferSize(8);
       format.setVersion(3, 2);
       format.setProfile(QSurfaceFormat::CoreProfile);
       QSurfaceFormat::setDefaultFormat(format);

       this->setFormat(format);
       qDebug()<<"Format is set";
}

PolygonWindow::~PolygonWindow()
{
    glDeleteBuffers(2,&m_vboIds[0]);
}

void PolygonWindow::initializeGL()
{
    initGeometry();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepthf(1.0f);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);

//    m_program = new QOpenGLShaderProgram(this);
    m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertshader.glsl");
    m_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragshader.glsl");
    m_program.link();
    m_posAttr = m_program.attributeLocation("posAttr");
}

void PolygonWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_program.bind();
    m_modelView.setToIdentity();
    m_modelView.translate(-1.5f, 0.0f, -6.0f);
    m_program.setUniformValue("mvpMatrix", m_projection * m_modelView);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[0]);
    m_program.enableAttributeArray(m_posAttr);
    m_program.setAttributeBuffer(m_posAttr, GL_FLOAT, 0, 3);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    m_modelView.translate(3.0f, 0.0f, 0.0f);
    m_program.setUniformValue("mvpMatrix", m_projection * m_modelView);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[1]);
    m_program.enableAttributeArray(m_posAttr);
    m_program.setAttributeBuffer(m_posAttr, GL_FLOAT, 0, 3);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    m_program.release();
}

void PolygonWindow::initGeometry()
{
    glGenBuffers(2, &m_vboIds[0]);
    GLfloat triangleVertices[] = {
        0.0f, 1.0f, 0.0f,
        -1.0f,-1.0f, 0.0f,
        1.0f,-1.0f, 0.0f,
    };
    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

    GLfloat quadVertices[] = {
         1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f,
         1.0f,-1.0f, 0.0f,
        -1.0f,-1.0f, 0.0f
    };
    glBindBuffer(GL_ARRAY_BUFFER, m_vboIds[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
}
