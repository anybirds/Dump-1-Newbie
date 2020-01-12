#pragma once

#include <GL/glew.h>

namespace Core {
	class Shader final {
	private:
		GLenum type;
		GLuint shader;

	public:
		Shader(GLenum type, const char *path);
		~Shader();

		GLenum GetType() const { return type; }
		GLuint GetId() const { return shader; }
	};
}