#pragma once

#include <GL/glew.h>

namespace Engine {

	struct MeshDetail {
		unsigned VertexCount; 
		const float *Vertices;
		unsigned AttributeCount; 
		const unsigned *Attributes;
		unsigned IndexCount;
		const unsigned *Indices;
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
		explicit Mesh(const MeshDetail &mesh);
		~Mesh();

		friend class Renderer;
	};
}