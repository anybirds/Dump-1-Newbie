#include <Material/DefaultMaterial.hpp>

DefaultMaterial::DefaultMaterial(const DefaultMaterialDetail &default_material) 
	: Material(MaterialDetail{default_material.VertexShaderName, default_material.FragmentShaderName}), texture(nullptr) {

}

void DefaultMaterial::Update() {
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