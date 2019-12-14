#pragma once

#include <glm/glm.hpp>

namespace Engine {

	/*
	Camera

	Featured by its normalization matrix. 
	Specify camera properties by directly manipulating the normalization matrix.
	glm::perspective, glm::otrho can be used.
	 */
	class Camera final {
	private:
		glm::mat4 normalization;
		
	public:
		struct Detail {
			glm::mat4 Normalization;
		};
		explicit Camera(const Detail &camera);
		~Camera();
		
		glm::mat4 Normalization() const { return normalization; }
		Camera& Normalization(const glm::mat4 &normalization) { this->normalization = normalization; return *this; }
	};
}