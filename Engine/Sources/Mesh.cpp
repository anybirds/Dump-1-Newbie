#include <Mesh.hpp>

using namespace Engine;

Mesh::Mesh(unsigned vnum, const vec3 pos[]) : vnum(vnum), inum(0) {
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

Mesh::Mesh(unsigned vnum, const vec3 pos[], unsigned inum, const unsigned idx[]) : vnum(vnum), inum(inum) {
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

Mesh::Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[]) {

}

Mesh::Mesh(unsigned vnum, const vec3 pos[], const vec2 uv[]) {

}

Mesh::Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[], const vec2 uv[]) {

}

Mesh::Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[], const vec2 uv[], unsigned inum, const unsigned idx[]) {

}

Mesh::Mesh(string path) {

}

Mesh::~Mesh() {
	// Destroy
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}