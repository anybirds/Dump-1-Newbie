#include <Renderer.hpp>

using namespace Engine;

Renderer::Renderer(Mesh *mesh, Material *material) : mesh(mesh), material(material) {
	
}

Renderer::~Renderer() {
	
}

void Renderer::Render() {
	glBindVertexArray(mesh->vao);
	glUseProgram(material->program);
	glDrawArrays(GL_TRIANGLES, 0, mesh->vnum);
}