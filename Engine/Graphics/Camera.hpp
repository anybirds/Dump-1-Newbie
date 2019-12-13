#pragma once

#include <glm/glm.hpp>

namespace Engine {

	struct CameraDetail {
		glm::mat4 Normalization;
	};

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
		explicit Camera(const CameraDetail &camera);
		~Camera();
		
		glm::mat4 Normalization() const { return normalization; }
		Camera& Normalization(const glm::mat4 &normalization) { this->normalization = normalization; return *this; }
	};
}