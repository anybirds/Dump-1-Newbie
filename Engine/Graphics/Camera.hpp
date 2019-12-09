#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Core/Transform.hpp>

namespace Engine {
	/*
	Camera

	Featured by its own transform and normalization matrix. 
	Specify camera properties by directly manipulating the normalization matrix.
	glm::perspective, glm::otrho can be used.
	 */
	class Camera final {
	private:
		const Transform *transform;
		glm::mat4 normalization;
		
	public:
		Camera(const Engine::Transform &transform, const glm::mat4 &normalization);
		~Camera();
		
		const Transform &Transform() const { return *transform; }
		void Transform(const Engine::Transform &transform) { this->transform = &transform; }
		glm::mat4 Normalization() const { return normalization; }
		void Normalization(const glm::mat4 &normalization) { this->normalization = normalization; }
	};
}