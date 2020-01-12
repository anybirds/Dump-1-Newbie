#pragma once

#include <GL/glew.h>

namespace Core {
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

		int GetVertexCount() const { return vcnt; }
		int GetIndexCount() const { return icnt; }
		int GetVao() const { return vao; }
	};
}