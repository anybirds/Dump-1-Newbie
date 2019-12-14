#pragma once

#include <GL/glew.h>

namespace Engine {

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
		struct Detail {
			unsigned VertexCount;
			const float *Vertices;
			unsigned AttributeCount;
			const unsigned *Attributes;
			unsigned IndexCount;
			const unsigned *Indices;
		};

		/* acquires resources(VAO, VBO, EBO) needed to generate a mesh for a model */
		explicit Mesh(const Detail &mesh);
		~Mesh();

		friend class Renderer;
	};
}