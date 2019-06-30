#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

namespace Engine {
	/**
	 * @brief Engine::Mesh class defines a model in a 3D space.
	 * @todo Are pos, normal and uv arrays needed even after giving data? 
	 */
	class Mesh final {
	private:
		unsigned vnum;
		unsigned inum;

		GLuint vao;
		GLuint vbo;
		GLuint ebo;

	public:
		Mesh(unsigned vnum, const vec3 pos[]);
		Mesh(unsigned vnum, const vec3 pos[], unsigned inum, const unsigned indices[]);
		Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[]);
		Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[], unsigned inum, const unsigned indices[]);
		Mesh(unsigned vnum, const vec3 pos[], const vec2 uv[]);
		Mesh(unsigned vnum, const vec3 pos[], const vec2 uv[], unsigned inum, const unsigned indices[]);
		Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[], const vec2 uv[]);
		Mesh(unsigned vnum, const vec3 pos[], const vec3 normal[], const vec2 uv[], unsigned inum, const unsigned indices[]);
		Mesh(string path);
		~Mesh();

		friend class Renderer;
	};
}