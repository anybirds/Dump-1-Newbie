#include <GL/glew.h>
#include <glm/glm.hpp>

#include <Core/Debug.hpp>
#include <Core/Resource.hpp>
#include <Graphics/Renderer.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

Renderer::Renderer(const Detail &renderer)
	: mesh(&Resource::FindMesh(renderer.MeshName)), material(&Resource::FindMaterial(renderer.MaterialName)) {

}

Renderer::~Renderer() {
	
}

void Renderer::Render() {
	glBindVertexArray(mesh->vao);

	glUseProgram(material->program);
	material->Update();

	GLuint location;
	if (transform) {
		// object with transform 
		location = glGetUniformLocation(material->program, "model_transform");
		mat4 model_transform = transform->Matrix();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&model_transform);
	}
	if (CameraObject::Current()) {
		// render with scene camera
		location = glGetUniformLocation(material->program, "camera_transform");
		mat4 camera_transform = CameraObject::Current()->Transform().Matrix();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&camera_transform);
		location = glGetUniformLocation(material->program, "camera_normalization");
		mat4 normalization = CameraObject::Current()->Camera().Normalization();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&normalization);
	}

	if (!mesh->icnt) {
		// mesh without EBO 
		glDrawArrays(GL_TRIANGLES, 0, mesh->vcnt);
	}
	else {
		// mesh with EBO
		glDrawElements(GL_TRIANGLES, mesh->icnt, GL_UNSIGNED_INT, 0);
	}
	
}