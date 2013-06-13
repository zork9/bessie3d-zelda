#include "scene3ds.h"

#include <iostream>
#include "../RayMantaPoint.h"
using namespace std;

#include "chunk/file.h"
#include "chunk/chunk.h"

Scene3DS::Scene3DS(const char *src)
{
	operator=(src);
}
Scene3DS::Scene3DS(const string &src)
{
	operator=(src.c_str());
}
Scene3DS::~Scene3DS()
{
}

void Scene3DS::operator=(const char *src)
{
	Model3DSFile file(src);

	Model3DSChunk root = file.Child();

	for(Model3DSChunk cc = root.Child() ; cc ; cc = cc.Sibling())
	{
		switch(cc.ID())
		{
			case(0x0002):
				// parse int which has version info
			break;
			
			case(0x3d3d):
				ParseEditor3D(cc);
			break;

			default:
			break;
		}
	}
}

void Scene3DS::ParseEditor3D(Model3DSChunk c)
{
	for(Model3DSChunk cc = c.Child() ; cc ; cc = cc.Sibling())
	{
		switch(cc.ID())
		{
			case(0x3d3e):
				// mesh version
			break;

			case(0xafff):
				Material3DS::Parse(cc);
			break;
			
			case(0x4000):
				ParseEditObject(cc);
			break;
			
			default:
			break;
		}
	}
}

void Scene3DS::ParseEditObject(Model3DSChunk c)
{
	string obj_name = c.Str();
	
	for(Model3DSChunk cc = c.Child() ; cc ; cc = cc.Sibling())
	{
		switch(cc.ID())
		{
			case(0x4100):
				Mesh3DS::Parse(obj_name , cc);
			break;
			
			case(0x4600):
				Light3DS::Parse(obj_name , cc);
			break;
			
			case(0x4700):
				cout << "\tobject camera\n";
			break;
			
			default:
				cout << "\terror : unknown object "
					<< hex << cc.ID() << dec << "\n";
			break;
		}
	}
}

std::vector<ray3d::Point> load3dsfile_vertices(std::string const& filename)
{
	Scene3DS *scene = new Scene3DS(filename.c_str());
/* then you simply read the data (it is automatically
parsed above */

// reading the meshes
std::vector<Mesh3DSObject> meshes = scene->Meshes();

// reading the vertices
// assuming theres at least one mesh in scene

std::vector<ray3d::Point> points;

for (vector<Mesh3DSObject>::iterator vi = meshes.begin(); vi != meshes.end(); vi++) {
	std::vector<Mesh3DSVertex> vertices = (*vi).Vertices();
	/*std::cout << "(" << vertices[0].x << ","
	<< vertices[0].y << ","
	<< vertices[0].z << ")\n";
	*/
	for (std::vector<Mesh3DSVertex>::iterator wi = vertices.begin(); wi != vertices.end(); wi++) {
		points.push_back(ray3d::Point((*wi).x, (*wi).y, (*wi).z));
	}
}
/*// reading the faces
std::vector<Mesh3DSFace> faces = meshes[0].Faces();//scene->Faces();
// 3ds files store faces as having 3 indexs in vertex arrays
Mesh3DSFace first_face = faces[0];

// first vertex of first_face
//Mesh3DSVertex a = vertices[first_face.a];
//Mesh3DSVertex b = vertices[first_face.b];
//Mesh3DSVertex c = vertices[first_face.c];
*/


	return points;
}