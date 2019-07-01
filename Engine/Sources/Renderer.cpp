#include <Renderer.hpp>

using namespace Engine;

Renderer::Renderer(const Mesh &mesh, const Material &material) : mesh(&mesh), material(&material) {
	
}

Renderer::~Renderer() {
	
}

void Renderer::Render() {
	glBindVertexArray(mesh->vao);
	glUseProgram(material->program);
	if (!mesh->inum) {
		// mesh without EBO 
		glDrawArrays(GL_TRIANGLES, 0, mesh->vnum);
	}
	else {
		// mesh with EBO
		glDrawElements(GL_TRIANGLES, mesh->inum, GL_UNSIGNED_INT, 0);
	}
	
}