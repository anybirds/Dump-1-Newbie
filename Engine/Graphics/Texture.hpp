#pragma once

#include <string>

#include <GL/glew.h>

#include <Core/Resource.hpp>

namespace Engine {

	/*
	Texture
	
	Represents a texture that has been created by loading images.
	*/
	class Texture final : public Resource {
	private:
		GLuint id;

	public:
		struct Data : Resource::Data {
			const char *texture_path;
		};

		explicit Texture(const Data &data);
		~Texture();
		GLuint GetId() const { return id; }
	};
}
