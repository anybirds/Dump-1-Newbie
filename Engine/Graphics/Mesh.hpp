#pragma once

#include <GL/glew.h>

namespace Engine {
	/*
	Mesh details
	
	Represents mesh details, which include vertices, 
	vertex attributes and vertex indices.
	*/
	class MeshDetail final {
	private:
		unsigned vcnt; 
		const float *vert;
		unsigned acnt; 
		const unsigned *attrib;
		unsigned icnt;
		const unsigned *idx;

	public:
		MeshDetail() : vcnt(0), vert(nullptr), acnt(0), attrib(nullptr), icnt(0), idx(nullptr) {}
		MeshDetail(unsigned vcnt, const float *vert, unsigned acnt, const unsigned *attrib, unsigned icnt, const unsigned *idx)
			: vcnt(vcnt), vert(vert), acnt(acnt), attrib(attrib), icnt(icnt), idx(idx) {}
		unsigned VertexCount() const { return vcnt; }
		MeshDetail& VertexCount(unsigned vcnt) { this->vcnt = vcnt; return *this; }
		const float *Vertices() const { return vert; }
		MeshDetail& Vertices(const float *vert) { this->vert = vert; return *this; }
		unsigned AttributeCount() const { return acnt; }
		MeshDetail& AttributeCount(unsigned acnt) { this->acnt = acnt; return *this; }
		const unsigned *Attributes() const { return attrib; }
		MeshDetail& Attributes(const unsigned *attrib) { this->attrib = attrib; return *this; }
		unsigned IndexCount() const { return icnt; }
		MeshDetail& IndexCount(unsigned icnt) { this->icnt = icnt; return *this; }
		const unsigned *Indices() const { return idx; }
		MeshDetail& Indices(const unsigned *idx) { this->idx = idx; return *this; }
	};

	/*
	Mesh

	Represents a wireframe that exists in the object space. 
	Users must define a MeshDetail object and pass it as an argument in order to create a Mesh.
	Mesh object can consist points in 2D, 3D or whatever dimensional space, 
	can have multiple attributes for each vertex and can represent indexed wireframe. 
	*/
	class Mesh final {
	private:
		unsigned vcnt;
		unsigned icnt;

		GLuint vao;
		GLuint vbo;
		GLuint ebo;
		
	public:
		/* acquires resources(VAO, VBO, EBO) needed to generate a mesh for a model */
		Mesh(const MeshDetail &mesh);
		~Mesh();

		friend class Renderer;
	};
}