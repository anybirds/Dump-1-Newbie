#pragma once

#include <GL/glew.h>

namespace Core {

	/*
	Represents a texture that has been created by loading images.
	*/
	class Texture final {
	private:
		GLuint id;

	public:
		Texture(const char *texture_path);
		~Texture();

		GLuint GetId() const { return id; }
	};
}
