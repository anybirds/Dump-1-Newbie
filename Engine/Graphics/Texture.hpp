#pragma once

#include <string>

#include <GL/glew.h>

namespace Engine {

	struct TextureDetail {
		const char *TextureName;
	};

	/*
	Texture
	
	Represents a texture that has been created by loading images.
	*/
	class Texture final {
	private:
		GLuint name;

	public:
		explicit Texture(const TextureDetail &texture);
		~Texture();
		GLuint Name() const { return name; }
	};
}
