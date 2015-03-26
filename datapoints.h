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

#endif // DATAPOINTS

