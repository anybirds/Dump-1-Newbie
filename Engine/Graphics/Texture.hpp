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
		GLuint id;

	public:
		struct Data {
			const char *texture_path;
		};

		explicit Texture(const Data &data);
		~Texture();
		GLuint GetId() const { return id; }
	};
}
