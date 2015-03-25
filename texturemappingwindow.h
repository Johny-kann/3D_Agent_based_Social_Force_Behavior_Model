#ifndef TEXTUREMAPPINGWINDOW
#define TEXTUREMAPPINGWINDOW


#include "openglwindow.h"
#include <QOpenGLShaderProgram>
#include <QTimer>


class TextureMappingWindow : public OpenGLWindow
{
    Q_OBJECT
public:
    explicit TextureMappingWindow(QWindow *parent = 0);
    ~TextureMappingWindow();

public slots:
    void timerout();
protected:
    void initialize();
    void render();
    void keyPressEvent(QKeyEvent *event);
    QTimer *timer;

private:
    void loadGLTexture();

    void loadShader();
private:
    void initGeometry();
private:
    QOpenGLShaderProgram *m_program;
    GLuint m_posAttr;
    GLuint m_texCoordAttr;
    GLuint m_normalAttr;
    GLuint m_vboIds[4];
    GLuint m_texture[2];

    GLfloat m_xrot;
    GLfloat m_yrot;
    GLfloat m_xspeed;
    GLfloat m_yspeed;
    GLfloat m_z;
    bool m_light;
    GLuint m_filter;
};

#endif // TEXTUREMAPPINGWINDOW

