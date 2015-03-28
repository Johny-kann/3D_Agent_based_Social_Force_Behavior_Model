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
    static const int NO_OF_OBJECTS;
    static const double SIGMA;
    static const double HURDLE_STRENGTH;
    static const double SOURCE_STRENGH;
    static const double HURDLE_OPAQUE_DISTANCE;
    static const double SOURCE_OPAQUE_DISTANCE;
    static const QString HURDLE_IMAGE ;
    static const QString SOURCE_IMAGE;
    static const double DEST_FORCE;
//    static double **HURDLE_POINTS;


};

#endif // DATAPOINTS

