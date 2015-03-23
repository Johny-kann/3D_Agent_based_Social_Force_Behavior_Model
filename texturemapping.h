#ifndef TEXTUREMAPPING_H
#define TEXTUREMAPPING_H

#include "glcontainer.h"
#include <QOpenGLShaderProgram>

class TextureMapping : public GLContainer
{
    Q_OBJECT
public:
    explicit TextureMapping(QWidget *parent = 0);
    ~TextureMapping();
protected:
    void initialize();
    void render();
private:
    void loadGLTexture();

    void loadShader();
private:
    void initGeometry();
private:
    QOpenGLShaderProgram *m_program;
    GLuint m_posAttr;
    GLuint m_texCoordAttr;
    GLuint m_vboIds[2];
    GLuint m_texture;
    GLfloat m_xrot;
    GLfloat m_yrot;
    GLfloat m_zrot;
};

#endif // TEXTUREMAPPING_H
