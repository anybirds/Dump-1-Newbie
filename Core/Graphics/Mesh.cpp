#include <iostream>

#include <Common/Debug.hpp>
#include <Graphics/Mesh.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace std;
using namespace Core;

Mesh::Mesh(const float *vert, int vcnt, const int *attrib, int acnt, const int *idx, int icnt) 
	: vcnt(vcnt), icnt(icnt) {

	// generate
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	// bind
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
	// data
	int stride = 0;
	for (int i = 0; i < acnt; i++) {
		stride += attrib[i];
	}
	stride *= sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, vcnt * stride, vert, GL_STATIC_DRAW);

	// attribute
	float *offset = nullptr;
	for (int i = 0; i < acnt; i++) {
		if (attrib[i]) {
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, attrib[i], GL_FLOAT, GL_FALSE, stride, (void *)offset);
			offset += attrib[i];
		}
	}

	if (icnt > 0) {
		// indexed wireframe
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, icnt * sizeof(int), idx, GL_STATIC_DRAW);
	}

	// restore
	glBindVertexArray(0);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' 
		<< "{vertex: " << vcnt << " attribute: " << acnt << " index: " << icnt << '}' 
		<<" Mesh created." << endl;
#endif

}

Mesh::~Mesh() {
	if (icnt > 0) {
		// indexed wireframe
		glDeleteBuffers(1, &ebo);
	}
	// delete
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}