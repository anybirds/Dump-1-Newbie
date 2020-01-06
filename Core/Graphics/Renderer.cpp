#include <GL/glew.h>
#include <glm/glm.hpp>

#include <Common/Debug.hpp>
#include <Common/GameObject.hpp>
#include <Common/Transform.hpp>
#include <Graphics/Camera.hpp>
#include <Graphics/Material.hpp>
#include <Graphics/Mesh.hpp>
#include <Graphics/Renderer.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace glm;
using namespace Core;

Renderer::Renderer(GameObject *object, Mesh *mesh, Material *material)
	: Component(object), 
	mesh(mesh), material(material) {
	
}

Renderer::~Renderer() {
	
}

void Renderer::Render() {
	glBindVertexArray(mesh->vao);

	glUseProgram(material->program);
	material->Uniform();

	GLuint location;

	// GameObject must have transform
	location = glGetUniformLocation(material->program, "model_transform");
	mat4 model_transform = GetGameObject()->GetTransform()->GetMatrix();
	glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&model_transform);

	if (Camera::GetCurrentCamera()) {
		// render with scene camera
		location = glGetUniformLocation(material->program, "camera_transform");
		mat4 camera_transform = Camera::GetCurrentCamera()->GetGameObject()->GetTransform()->GetMatrix();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&camera_transform);
		location = glGetUniformLocation(material->program, "camera_normalization");
		mat4 normalization = Camera::GetCurrentCamera()->GetNormalization();
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