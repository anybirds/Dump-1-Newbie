#pragma once

#include <GL/glew.h>

namespace Core {

	class Texture final {
	private:
		GLuint id;

	public:
		Texture(const char *path);
		~Texture();

		GLuint GetId() const { return id; }
	};
}
