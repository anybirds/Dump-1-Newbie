#include <Material/DefaultMaterial.hpp>

DefaultMaterial::DefaultMaterial(const string &vert_path, const string &frag_path) : Material(vert_path, frag_path), texture(nullptr) {

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