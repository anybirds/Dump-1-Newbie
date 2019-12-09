#pragma once

#include <string>

#include <GL/glew.h>

namespace Engine {
	/*
	Texture
	
	Represents a texture that has been created by loading images.
	*/
	class Texture final {
	private:
		GLuint name;

	public:
		Texture(const std::string &path);
		~Texture();
		GLuint Name() const { return name; }
	};
}
