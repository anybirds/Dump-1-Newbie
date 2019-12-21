#include <map>

#include <Core/Debug.hpp>
#include <Graphics/Model.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace std;
using namespace Assimp;
using namespace Engine;

Model::Model(const Data &data) 
	: importer(), scene(importer.ReadFile(data.model_path, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenSmoothNormals)) {

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
#ifdef DEBUG
		cout << '[' << __FUNCTION__ << ']' << " cannot open file: " << data.model_path << '\n';
#endif
		return;
	}

	mcnt = scene->mNumMeshes; 
	vert = new float*[mcnt];
	attrib = new unsigned*[mcnt];
	idx = new unsigned*[mcnt];
	mesh = new Mesh::Data*[mcnt];

	for (unsigned midx = 0; midx < mcnt; midx++) {
		aiMesh *aimesh = scene->mMeshes[midx];
		unsigned base;

		unsigned acnt = 3;
		attrib[midx] = new unsigned[acnt];
		if (aimesh->HasPositions()) {
			attrib[midx][0] = 3;
		}
		if (aimesh->HasNormals()) {
			attrib[midx][1] = 3;
		}
		if (aimesh->HasTextureCoords(0)) {
			attrib[midx][2] = 2;
		}
		unsigned asize = 0; // number of floats for each vertex 
		for (unsigned i = 0; i < acnt; i++) {
			asize += attrib[midx][i];
		}

		unsigned vcnt = aimesh->mNumVertices;
		vert[midx] = new float[vcnt * asize];
		base = 0;
		for (unsigned i = 0; i < aimesh->mNumVertices; i++) {
			if (aimesh->HasPositions()) {
				vert[midx][base] = aimesh->mVertices[i].x;
				vert[midx][base + 1] = aimesh->mVertices[i].y;
				vert[midx][base + 2] = aimesh->mVertices[i].z;
				base += 3;
			}
			if (aimesh->HasNormals()) {
				vert[midx][base] = aimesh->mNormals[i].x;
				vert[midx][base + 1] = aimesh->mNormals[i].y;
				vert[midx][base + 2] = aimesh->mNormals[i].z;
				base += 3;
			}
			if (aimesh->HasTextureCoords(0)) { // texture coordinate set 0
				vert[midx][base] = aimesh->mTextureCoords[0][i].x;
				vert[midx][base + 1] = aimesh->mTextureCoords[0][i].y;
				base += 2;
			}
		}

		unsigned icnt = aimesh->mNumFaces * 3;
		idx[midx] = new unsigned[icnt];
		base = 0;
		for (unsigned i = 0; i < aimesh->mNumFaces; i++) {
			idx[midx][base] = aimesh->mFaces[i].mIndices[0];
			idx[midx][base + 1] = aimesh->mFaces[i].mIndices[1];
			idx[midx][base + 2] = aimesh->mFaces[i].mIndices[2];
			base += 3;
		}

		mesh[midx] = new Engine::Mesh::Data{ vert[midx], attrib[midx], idx[midx], vcnt, acnt, icnt };
	}
}

Model::~Model() {
	for (unsigned i = 0; i < mcnt; i++) {
		if (vert[i]) {
			delete vert[i];
		}
		if (attrib[i]) {
			delete attrib[i];
		}
		if (idx[i]) {
			delete idx[i];
		}
	}
}