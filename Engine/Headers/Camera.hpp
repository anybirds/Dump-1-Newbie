#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include <Transform.hpp>

using namespace glm;

namespace Engine {
	/**
	 * @brief Camera class
	 */
	class Camera final {
	private:
		const Transform *transform;
		mat4 normalization;
		
	public:
		Camera(const Engine::Transform &transform, const mat4 &normalization);
		~Camera();

		const Transform &Transform() const { return *transform; }
		void Transform(const Engine::Transform &transform) { this->transform = &transform; }
		mat4 Normalization() const { return normalization; }
		void Normalization(const mat4 &normalization) { this->normalization = normalization; }
		
	};
}