/*
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <Common/GameObject.hpp>
#include <Common/Transform.hpp>
#include <Graphics/Camera.hpp>
#include <Graphics/Material.hpp>
#include <Graphics/Mesh.hpp>
#include <Graphics/Renderer.hpp>

using namespace glm;
using namespace System;
using namespace Engine;

Renderer::Renderer(GameObject ^gameObject) 
	: ManagedObject<Core::Renderer>(new Core::Renderer()), m_gameObject(gameObject) {
	
}

void Renderer::Render() {
	glBindVertexArray(mesh->vao);
	
	glUseProgram(material->program);
	material->instance->UpdateUniforms();

	GLuint location;

	// object must have transform
	location = glGetUniformLocation(material->program, "model_transform");
	mat4 model_transform = gameObject->transform->instance->GetMatrix();

	glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&model_transform);

	if (Camera::current) {
		// render with scene camera
		location = glGetUniformLocation(material->program, "camera_transform");
		mat4 camera_transform = Camera::current->gameObject->transform->instance->GetMatrix();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&camera_transform);
		location = glGetUniformLocation(material->program, "camera_normalization");
		mat4 normalization = Camera::current->instance->GetNormalization();
		glUniformMatrix4fv(location, 1, GL_FALSE, (const GLfloat *)&normalization);
	}

	if (!mesh->indexCount) {
		// mesh without EBO 
		glDrawArrays(GL_TRIANGLES, 0, mesh->vertexCount);
	}
	else {
		// mesh with EBO
		glDrawElements(GL_TRIANGLES, mesh->indexCount, GL_UNSIGNED_INT, 0);
	}

}

void Renderer::Destroy() {
	m_gameObject->RemoveComponent<Renderer>();
	ManagedObject<Core::Renderer>::Destroy();
}
*/