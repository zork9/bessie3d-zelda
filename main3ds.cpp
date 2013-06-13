#include "3ds/3ds.h"
#include<iostream>
#include<vector>
int mainprogram3dsold()
{
Scene3DS *scene = new Scene3DS("./exmaple.3ds");
/* then you simply read the data (it is automatically
parsed above */

// reading the meshes
std::vector<Mesh3DSObject> meshes = scene->Meshes();

// reading the vertices
// assuming theres at least one mesh in scene
std::vector<Mesh3DSVertex> vertices = meshes[0].Vertices();
std::cout << "(" << vertices[0].x << ","
<< vertices[0].y << ","
<< vertices[0].z << ")\n";

// reading the faces
std::vector<Mesh3DSFace> faces = meshes[0].Faces();
// 3ds files store faces as having 3 indexs in vertex arrays
Mesh3DSFace first_face = faces[0];

// first vertex of first_face
//Mesh3DSVertex a = vertices[first_face.a]
//Mesh3DSVertex b = vertices[first_face.b]
//Mesh3DSVertex c = vertices[first_face.c]

return 0;
}

