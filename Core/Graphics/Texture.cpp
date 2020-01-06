#include <iostream>

#include <SOIL/SOIL.h>

#include <Common/Debug.hpp>
#include <Graphics/Texture.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace std;
using namespace Core;

Texture::Texture(const char *texture_path) {
	int width, height, channel;
	unsigned char *image = SOIL_load_image(texture_path, &width, &height, &channel, SOIL_LOAD_AUTO);
	if (!image) {
#ifdef DEBUG
		cout << '[' << __FUNCTION__ << ']' << " cannot load image file: " << texture_path << '\n';
#endif
	}

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
}

Texture::~Texture() {

}