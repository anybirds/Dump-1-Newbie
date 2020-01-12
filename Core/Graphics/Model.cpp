#include <iostream>
#include <map>

#include <Common/Debug.hpp>
#include <Graphics/Model.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace std;
using namespace Assimp;
using namespace Core;

bool Model::Import(const char *path) {
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenSmoothNormals);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
#ifdef DEBUG
		cout << '[' << __FUNCTION__ << ']' << " cannot open file: " << path << '\n';
#endif
		return false;
	}

	int mcnt = scene->mNumMeshes; 
	for (int midx = 0; midx < mcnt; midx++) {
		aiMesh *aimesh = scene->mMeshes[midx];
		int base;

		int acnt = 3;
		int *attrib = new int[acnt];
		if (aimesh->HasPositions()) {
			attrib[0] = 3;
		}
		if (aimesh->HasNormals()) {
			attrib[1] = 3;
		}
		if (aimesh->HasTextureCoords(0)) {
			attrib[2] = 2;
		}
		int asize = 0; // number of floats for each vertex 
		for (int i = 0; i < acnt; i++) {
			asize += attrib[i];
		}

		int vcnt = aimesh->mNumVertices;
		float *vert = new float[vcnt * asize];
		base = 0;
		for (int i = 0; i < aimesh->mNumVertices; i++) {
			if (aimesh->HasPositions()) {
				vert[base] = aimesh->mVertices[i].x;
				vert[base + 1] = aimesh->mVertices[i].y;
				vert[base + 2] = aimesh->mVertices[i].z;
				base += 3;
			}
			if (aimesh->HasNormals()) {
				vert[base] = aimesh->mNormals[i].x;
				vert[base + 1] = aimesh->mNormals[i].y;
				vert[base + 2] = aimesh->mNormals[i].z;
				base += 3;
			}
			if (aimesh->HasTextureCoords(0)) { // texture coordinate set 0
				vert[base] = aimesh->mTextureCoords[0][i].x;
				vert[base + 1] = aimesh->mTextureCoords[0][i].y;
				base += 2;
			}
		}

		int icnt = aimesh->mNumFaces * 3;
		int *idx = new int[icnt];
		base = 0;
		for (int i = 0; i < aimesh->mNumFaces; i++) {
			idx[base] = aimesh->mFaces[i].mIndices[0];
			idx[base + 1] = aimesh->mFaces[i].mIndices[1];
			idx[base + 2] = aimesh->mFaces[i].mIndices[2];
			base += 3;
		}

		Mesh *mesh = new Mesh(vert, vcnt, attrib, acnt, idx, icnt);
		delete vert;
		delete attrib;
		delete idx;
	}

	return true;
}