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

    VertexData *vertices;
 /*   VertexData vertices[]=
    {
        // Vertex data for face 0
        {QVector3D(-1.0, -1.0,  1.0), QVector3D(0.0, 0.0, 1.0), QVector2D(0.0, 0.0)},  // v0
        {QVector3D( 1.0, -1.0,  1.0), QVector3D(0.0, 0.0, 1.0), QVector2D(1.0, 0.0)}, // v1
        {QVector3D(-1.0,  1.0,  1.0), QVector3D(0.0, 0.0, 1.0), QVector2D(0.0, 1.0)},  // v2
        {QVector3D( 1.0,  1.0,  1.0), QVector3D(0.0, 0.0, 1.0), QVector2D(1.0, 1.0)}, // v3

        // Vertex data for face 1
        {QVector3D( 1.0, -1.0,  1.0), QVector3D(1.0, 0.0, 0.0), QVector2D(0.0, 0.0)}, // v4
        {QVector3D( 1.0, -1.0, -1.0), QVector3D(1.0, 0.0, 0.0), QVector2D(1.0, 0.0)}, // v5
        {QVector3D( 1.0,  1.0,  1.0), QVector3D(1.0, 0.0, 0.0), QVector2D(0.0, 1.0)},  // v6
        {QVector3D( 1.0,  1.0, -1.0), QVector3D(1.0, 0.0, 0.0), QVector2D(1.0, 1.0)}, // v7

        // Vertex data for face 2
        {QVector3D( 1.0, -1.0, -1.0), QVector3D(0.0, 0.0, -1.0), QVector2D(0.0, 0.0)}, // v8
        {QVector3D(-1.0, -1.0, -1.0), QVector3D(0.0, 0.0, -1.0), QVector2D(1.0, 0.0)},  // v9
        {QVector3D( 1.0,  1.0, -1.0), QVector3D(0.0, 0.0, -1.0), QVector2D(0.0, 1.0)}, // v10
        {QVector3D(-1.0,  1.0, -1.0), QVector3D(0.0, 0.0, -1.0), QVector2D(1.0, 1.0)},  // v11

        // Vertex data for face 3
        {QVector3D(-1.0, -1.0, -1.0), QVector3D(-1.0, 0.0, 0.0), QVector2D(0.0, 0.0)}, // v12
        {QVector3D(-1.0, -1.0,  1.0), QVector3D(-1.0, 0.0, 0.0), QVector2D(1.0, 0.0)},  // v13
        {QVector3D(-1.0,  1.0, -1.0), QVector3D(-1.0, 0.0, 0.0), QVector2D(0.0, 1.0)}, // v14
        {QVector3D(-1.0,  1.0,  1.0), QVector3D(-1.0, 0.0, 0.0), QVector2D(1.0, 1.0)},  // v15

        // Vertex data for face 4
        {QVector3D(-1.0, -1.0, -1.0), QVector3D(0.0, -1.0, 0.0), QVector2D(0.0, 0.0)}, // v16
        {QVector3D( 1.0, -1.0, -1.0), QVector3D(0.0, -1.0, 0.0), QVector2D(1.0, 0.0)}, // v17
        {QVector3D(-1.0, -1.0,  1.0), QVector3D(0.0, -1.0, 0.0), QVector2D(0.0, 1.0)}, // v18
        {QVector3D( 1.0, -1.0,  1.0), QVector3D(0.0, -1.0, 0.0), QVector2D(1.0, 1.0)}, // v19

        // Vertex data for face 5
        {QVector3D(-1.0,  1.0,  1.0), QVector3D(0.0, 1.0, 0.0), QVector2D(0.0, 0.0)}, // v20
        {QVector3D( 1.0,  1.0,  1.0), QVector3D(0.0, 1.0, 0.0), QVector2D(1.0, 0.0)}, // v21
        {QVector3D(-1.0,  1.0, -1.0), QVector3D(0.0, 1.0, 0.0), QVector2D(0.0, 1.0)}, // v22
        {QVector3D( 1.0,  1.0, -1.0), QVector3D(0.0, 1.0, 0.0), QVector2D(1.0, 1.0)}  // v23
    };
*/
   GLushort *indices;

   /* GLushort indices[] = {
         0,  1,  2,  3,  3,     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
         4,  4,  5,  6,  7,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
         8,  8,  9, 10, 11, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
        12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
        16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
        20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    };
    */

public:

   CubePoints();
  // ~CubePoints();

   VertexData *getVertices();
   void setVertices(VertexData *value);
   GLushort *getIndices();
   void setIndices(GLushort *value);
};


class cbPoints
{
private:

   QList<VertexData> vertices;
//    VertexData *vertices;
    QList<GLushort> indices;

//   GLushort *indices;


public:

   cbPoints();
  // ~CubePoints();


   QList<VertexData> getVertices() const;
   void setVertices(const QList<VertexData> &value);
   QList<GLushort> getIndices() const;
   void setIndices(const QList<GLushort> &value);
};

#endif // DATAPOINTS

