#include <Renderer.hpp>

using namespace Engine;

const Engine::Camera *Renderer::camera = nullptr;

Renderer::Renderer(const Mesh &mesh, const Material &material) : mesh(&mesh), material(&material), transform() {
	
}

Renderer::Renderer(const Mesh &mesh, const Material &material, const Transform &transform) : mesh(&mesh), material(&material), transform(&transform) {

}

Renderer::~Renderer() {
	
}

void Renderer::Render() {
	glBindVertexArray(mesh->vao);

	glUseProgram(material->program);
	GLuint location;
	if (transform) {
		// object with transform 
		location = glGetUniformLocation(material->program, "model_transform");
		mat4 model_transform = transform->Matrix();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&model_transform);
	}
	if (camera) {
		// render with scene camera
		location = glGetUniformLocation(material->program, "camera_transform");
		mat4 camera_transform = camera->Transform().Matrix();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&camera_transform);
		location = glGetUniformLocation(material->program, "normalization");
		mat4 normalization = camera->Normalization();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&normalization);
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