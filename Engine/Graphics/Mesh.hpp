#pragma once

#include <GL/glew.h>

#include <Core/Resource.hpp>

namespace Engine {

	/*
	Mesh

	Represents a wireframe that exists in the object space. 
	Users must define a MeshDetail object and pass it as an argument in order to create a Mesh.
	Mesh object can consist points in 2D, 3D or whatever dimensional space, 
	can have multiple attributes for each vertex and can represent indexed wireframe. 
	*/
	class Mesh final : public Resource {
	private:
		unsigned vcnt;
		unsigned icnt;

		GLuint vao;
		GLuint vbo;
		GLuint ebo;
		
	public:
		struct Data : Resource::Data {
			const float *vert;
			const unsigned *attrib; // value 0 means that the attribute is empty
			const unsigned *idx;
			unsigned vcnt;
			unsigned acnt; // max index of attributes a vertex can have according to the shader
			unsigned icnt;
		};

		/* acquires resources(VAO, VBO, EBO) needed to generate a mesh for a model */
		explicit Mesh(const Data &data);
		~Mesh();

		friend class Renderer;
	};
}