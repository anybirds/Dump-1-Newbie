#include <Renderer.hpp>

using namespace Engine;

Renderer::Renderer(const Mesh &mesh, const Material &material) : mesh(&mesh), material(&material), transform() {
	
}

Renderer::Renderer(const Mesh &mesh, const Material &material, const Transform &transform) : mesh(&mesh), material(&material), transform(&transform) {

}

Renderer::~Renderer() {
	
}

void Renderer::Render() {
	glBindVertexArray(mesh->vao);

	glUseProgram(material->program);
	if (transform) {
		// object with transform 
		GLuint location = glGetUniformLocation(material->program, "model_transform");
		mat4 matrix = transform->Matrix();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&matrix);
	}

	if (!mesh->inum) {
		// mesh without EBO 
		glDrawArrays(GL_TRIANGLES, 0, mesh->vnum);
	}
	else {
		// mesh with EBO
		glDrawElements(GL_TRIANGLES, mesh->inum, GL_UNSIGNED_INT, 0);
	}
	
}