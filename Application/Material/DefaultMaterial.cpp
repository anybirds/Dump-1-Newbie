#include <Material/DefaultMaterial.hpp>
#include <Engine.hpp>

using namespace Engine;

DefaultMaterial::DefaultMaterial(const Data &data) 
	: Material(data), 
	texture(data.texture) {

}

void DefaultMaterial::Uniform() const {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->GetId());
}

DefaultMaterial::~DefaultMaterial() {
	Material::~Material();
	if (texture) {
		GLuint name = texture->GetId();
		glDeleteTextures(1, &name); // second argument must be a pointer of lvalue
	}
}