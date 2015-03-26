#include <QOpenGLContext>
#include <QVector2D>
#include <QVector3D>
#include <vector>
#include <QList>

#ifndef DATAPOINTS
#define DATAPOINTS

struct VertexData
{
    QVector3D position;
    QVector3D normal;
    QVector2D texCoord;
};


class CubePoints
{
private:

   QList<VertexData> vertices;
//    VertexData *vertices;
    QList<GLushort> indices;

//   GLushort *indices;


public:

   CubePoints();
  // ~CubePoints();


   QList<VertexData> getVertices() const;
   void setVertices(const QList<VertexData> &value);
   QList<GLushort> getIndices() const;
   void setIndices(const QList<GLushort> &value);
};

class constants
{
public:
    const int NO_OF_OBJECTS = 10;
    const int HURDLE_STRENGTH = 4;
    const int HURDLE_OPAQUE_DISTANCE = 2;
    const QString HURDLE_IMAGE = ":/image/Crate.bmp";

};

#endif // DATAPOINTS

