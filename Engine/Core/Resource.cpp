#include <typeinfo>

#include <../Application/Mesh/Geometry.hpp>
#include <../Application/Material/DefaultMaterial.hpp>
#include <Core/Resource.hpp>

#ifdef DEBUG_CORE
#define DEBUG
#endif

using namespace std;
using namespace Engine;

Resource Resource::resource;

Material& Resource::FindMaterial(const string& name) {
	return *resource.material.find(name)->second;
}

Mesh& Resource::FindMesh(const string& name) {
	return *resource.mesh.find(name)->second;
}

Model& Resource::FindModel(const string& name) {
	return *resource.model.find(name)->second;
}

/*
Material& Resource::FindMaterial(const string& name) {

}
*/

Texture& Resource::FindTexture(const string& name) {
	return *resource.texture.find(name)->second;
}

void Resource::Load() {
	resource.model.insert({ "Bunny", new Model({"Resource\\Model\\bunny_model.obj"}) });

	resource.mesh.insert({ "Square", new Mesh(Geometry::Square) });
	resource.mesh.insert({ "Bunny", new Mesh(FindModel("Bunny").MeshDetail()) });

	resource.texture.insert({ "Bunny", new Texture({"Resource\\Texture\\bunny_texture.png"}) });

	resource.material.insert({ "Bunny",
		new DefaultMaterial({
			"Resource\\Shader\\test_graphics_vert.glsl" ,
			"Resource\\Shader\\test_graphics_frag.glsl" ,
			"Bunny"
			})
		});

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " Resource loaded." << endl;
#endif

}

Resource::Resource() 
{

}

Resource::~Resource() {
	for (auto item : material) {
		delete item.second; 
	}
	for (auto item : mesh) {
		delete item.second; 
	}
	for (auto item : model) {
		delete item.second; 
	}
	/*
	for (auto item : shader) {
		delete item.second;
	}
	*/
	for (auto item : texture) {
		delete item.second; 
	}
}

