#ifndef OPENGLWINDOW
#define OPENGLWINDOW

#include <QWindow>
#include <QOpenGLFunctions>
#include <QCoreApplication>
#include <QEvent>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QMatrix4x4>
#include "models.h"
#include <QTimer>

class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);
    ~OpenGLWindow();

    void setAnimating(bool animating);

    QTimer *timer;

public slots:
    void renderLater();

    void renderNow();

     void timeout();

protected:
     Camera *camera;

    bool event(QEvent *event);

    void exposeEvent(QExposeEvent *event);

    void resizeEvent(QResizeEvent * event);

    void keyPressEvent(QKeyEvent * event);

    void initializeCamera();

    virtual void render();

    virtual void initialize();

    virtual void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    QMatrix4x4 m_projection;
    QMatrix4x4 m_vMatrix;
    QMatrix4x4 m_modelView;

    QPoint lastPos;

private:
    bool m_update_pending;
    bool m_animating;
    QOpenGLContext *m_context;
    bool m_show_full_screen;
};


#endif // OPENGLWINDOW

