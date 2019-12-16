#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Graphics/Mesh.hpp>

namespace Engine {

	/*
	Model imported by using assimp library
	
	Stores data read by using assimp library functions. 
	Imported mesh basically has 3 attributes, position, normal and uv.
	A model can import only one mesh.
	*/

	class Model final {
	private:
		Assimp::Importer importer;
		const aiScene *scene;
		unsigned mcnt;
		
		// mesh
		float **vert;
		unsigned **attrib;
		unsigned **idx;
		Mesh::Detail **mesh;
		
	public:
		struct Detail {
			const char *ModelName;
		};

		explicit Model(const Detail &model);
		~Model();
		Mesh::Detail& MeshDetail(unsigned midx) const { return *mesh[midx]; }
		unsigned MeshCount() const { return mcnt; }
	};
}
