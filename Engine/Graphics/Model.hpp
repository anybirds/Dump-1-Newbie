#pragma once

#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Graphics/Mesh.hpp>

namespace Engine {

	struct ModelDetail {
		const char *ModelName;
	};

	/*
	Model imported by using assimp library
	
	Stores data read by using assimp library functions. 
	Imported mesh basically has 3 attributes, position, normal and uv.
	A model can import only one mesh.
	*/
	class Model final {
	private:
		const aiScene *scene;

		// mesh
		float *vert;
		unsigned *attrib;
		unsigned *idx;
		MeshDetail *mesh;
		
	public:
		explicit Model(const ModelDetail &model);
		~Model();
		MeshDetail& MeshDetail() const { return *mesh; }
	};
}
