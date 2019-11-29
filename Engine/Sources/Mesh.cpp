#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Mesh.hpp>
#include <iostream>
using namespace Assimp;
using namespace Engine;

void Mesh::CreateMesh(unsigned vnum, const vec3 pos[]) {
	// Generate 
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	
	// Bind
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Data
	glBufferData(GL_ARRAY_BUFFER, vnum * sizeof(vec3), &pos[0], GL_STATIC_DRAW);

	// Attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), (void *)0);

	glBindVertexArray(0);
}

void Mesh::CreateMesh(unsigned vnum, const vec3 pos[], unsigned inum, const unsigned idx[]) {
	// Generate 
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	// Bind
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Data
	glBufferData(GL_ARRAY_BUFFER, vnum * sizeof(vec3), pos, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, inum * sizeof(unsigned), idx, GL_STATIC_DRAW);

	// Attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), (void *)0);

	glBindVertexArray(0);
}

Mesh::Mesh(unsigned vnum, const vec3 pos[]) : vnum(vnum), inum(0) {
	CreateMesh(vnum, pos);
}

Mesh::Mesh(unsigned vnum, const vec3 pos[], unsigned inum, const unsigned idx[]) : vnum(vnum), inum(inum) {
	CreateMesh(vnum, pos, inum, idx);
}

Mesh::Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[]) {

}

Mesh::Mesh(unsigned vnum, const vec3 pos[], const vec2 uv[]) {

}

Mesh::Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[], const vec2 uv[]) {

}

Mesh::Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[], const vec2 uv[], unsigned inum, const unsigned idx[]) {

}

Mesh::Mesh(string path) {
	Importer importer;
	const aiScene *scene = importer.ReadFile(path.c_str(), aiProcess_Triangulate | aiProcess_FlipUVs);
	
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		// exception
		return;
	}
	
	aiMesh *mesh = scene->mMeshes[scene->mRootNode->mChildren[0]->mMeshes[0]];
	vnum = mesh->mNumVertices;

	vec3 *pos = new vec3[vnum];
	for (unsigned i = 0; i < mesh->mNumVertices; i++) {
		pos[i].x = mesh->mVertices[i].x;
		pos[i].y = mesh->mVertices[i].y;
		pos[i].z = mesh->mVertices[i].z;
		// cout << i << ' ' << pos[i].x << ' ' << pos[i].y << ' ' << pos[i].z << '\n';
	}
	
	inum = mesh->mNumFaces * 3;
	unsigned *idx = new unsigned[inum];

	for (unsigned i = 0; i < mesh->mNumFaces; i++) {
		
		idx[i * 3] = mesh->mFaces[i].mIndices[0];
		idx[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
		idx[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
		// cout << mesh->mFaces[i].mNumIndices << ' ' << idx[i * 3] << ' ' << idx[i * 3 + 1] << ' ' << idx[i * 3 + 2] << '\n';
	}

	CreateMesh(vnum, pos, inum, idx);

	delete[] pos;
	delete[] idx;
}

Mesh::~Mesh() {
	// Destroy
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	
	// destroy only if ebo exists
	glDeleteBuffers(1, &ebo);
}