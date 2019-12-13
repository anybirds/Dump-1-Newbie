#include <Core/Debug.hpp>
#include <Graphics/Mesh.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace Engine;

Mesh::Mesh(const MeshDetail &mesh) : vcnt(mesh.VertexCount), icnt(mesh.IndexCount) {
	unsigned acnt = mesh.AttributeCount;

	const float *vert = mesh.Vertices;
	const unsigned *attrib = mesh.Attributes;
	const unsigned *idx = mesh.Indices;

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' 
		<< " vertex: " << vcnt << " attribute: " << acnt << " index: " << icnt << endl;
#endif

	// generate
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	// bind
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	
	// data
	unsigned stride = 0;
	for (unsigned i = 0; i < acnt; i++) {
		stride += attrib[i];
	}
	stride *= sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, vcnt * stride, vert, GL_STATIC_DRAW);

	if (icnt > 0) {
		// indexed wireframe
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, icnt * sizeof(unsigned), idx, GL_STATIC_DRAW);
	}

	// attribute
	float *offset = nullptr;
	for (unsigned i = 0; i < acnt; i++) {
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, attrib[i], GL_FLOAT, GL_FALSE, stride, (void *)offset);
		offset += attrib[i];
	}

	// restore
	glBindVertexArray(0);
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