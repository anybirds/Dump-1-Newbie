#pragma once

#include <GL/glew.h>

namespace Core {

	/*
	Represents a wireframe that exists in the GameObject space. 
	Users must define a MeshDetail GameObject and pass it as an argument in order to create a Mesh.
	Mesh GameObject can consist points in 2D, 3D or whatever dimensional space, 
	can have multiple attributes for each vertex and can represent indexed wireframe. 
	*/
	class Mesh final {
	private:
		int vcnt;
		int icnt;
			
		GLuint vao;
		GLuint vbo;
		GLuint ebo;
		
	public:
		/* acquires resources(VAO, VBO, EBO) needed to generate a mesh for a model */
		Mesh(const float *vert, int vcnt, const int *attrib, int acnt, const int *idx = nullptr, int icnt = 0);
		~Mesh();

		friend class Renderer;
	};
}