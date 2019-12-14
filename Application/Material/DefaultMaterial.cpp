#include <Material/DefaultMaterial.hpp>

DefaultMaterial::DefaultMaterial(const Detail &default_material) 
	: Material(Material::Detail{default_material.VertexShaderName, default_material.FragmentShaderName}), 
	texture(&Resource::FindTexture(default_material.TextureName)) {

}

void DefaultMaterial::Update() const {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->Name());
}

DefaultMaterial::~DefaultMaterial() {
	Material::~Material();
	if (texture) {
		GLuint name = texture->Name();
		glDeleteTextures(1, &name); // second argument must be a pointer of lvalue
	}
}