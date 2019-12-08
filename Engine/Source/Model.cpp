#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Debug.hpp>
#include <Model.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace Assimp;
using namespace Engine;

Model::Model(std::string path) : vert(nullptr), attrib(nullptr), idx(nullptr), mesh() {
	Importer importer;
	scene = importer.ReadFile(path.c_str(), aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenSmoothNormals);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
#ifdef DEBUG
		cout << '[' << __FUNCTION__ << ']' << " cannot open file: " << path << '\n';
#endif
		return;
	}

	aiMesh *aimesh = scene->mMeshes[scene->mRootNode->mChildren[0]->mMeshes[0]];
	
	// imported vertices have position, normal and uv attributes.
	unsigned acnt = 3;
	attrib = new unsigned[acnt] {3, 3, 2};
	unsigned asize = 0; // number of floats for each vertex 
	for (unsigned i = 0; i < acnt; i++) {
		asize += attrib[i];
	}

	unsigned vcnt = aimesh->mNumVertices;
	vert = new float[vcnt * asize];
	for (unsigned i = 0; i < aimesh->mNumVertices; i++) {
		unsigned base = i * asize;
		if (aimesh->HasPositions()) {
			vert[base] = aimesh->mVertices[i].x;
			vert[base + 1] = aimesh->mVertices[i].y;
			vert[base + 2] = aimesh->mVertices[i].z;
		}
		else {
			vert[base] = 0;
			vert[base + 1] = 0;
			vert[base + 2] = 0;
		}

		if (aimesh->HasNormals()) {
			vert[base + 3] = aimesh->mNormals[i].x;
			vert[base + 4] = aimesh->mNormals[i].y;
			vert[base + 5] = aimesh->mNormals[i].z;
		}
		else {
			vert[base + 3] = 0.0f;
			vert[base + 4] = 0.0f;
			vert[base + 5] = 0.0f;
		}

		if (aimesh->HasTextureCoords(0)) { // texture coordinate set 0
			vert[base + 6] = aimesh->mTextureCoords[0][i].x; 
			vert[base + 7] = aimesh->mTextureCoords[0][i].y;
		}
		else {
			vert[base + 6] = 0.0f;
			vert[base + 7] = 0.0f;
		}
	}
	cout << vert[6] << ' ' << vert[7] << '\n';
	unsigned icnt = aimesh->mNumFaces * 3;
	idx = new unsigned[icnt];
	for (unsigned i = 0; i < aimesh->mNumFaces; i++) {
		unsigned base = i * 3;
		idx[base] = aimesh->mFaces[i].mIndices[0];
		idx[base + 1] = aimesh->mFaces[i].mIndices[1];
		idx[base + 2] = aimesh->mFaces[i].mIndices[2];
	}

	mesh.VertexCount(vcnt).Vertices(vert)
		.AttributeCount(acnt).Attributes(attrib)
		.IndexCount(icnt).Indices(idx);
}

Model::~Model() {
	delete[] vert;
	delete[] attrib;
	delete[] idx;
}
