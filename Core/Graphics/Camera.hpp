#pragma once

#include <glm/glm.hpp>

#include <Common/Component.hpp>

namespace Core {

	/*
	Featured by its normalization matrix. 
	Specify camera properties by directly manipulating the normalization matrix.
	glm::perspective, glm::otrho can be used.
	 */
	class Camera final : public Component {
	private:
		static const Camera *current;

	public:
		static const Camera* GetCurrentCamera() { return current; }
		static void SetCurrentCamera(const Camera *current) { Camera::current = current; }

	private:
		glm::mat4 normalization;

	public:
		Camera(GameObject *object, const glm::mat4 &normalization = glm::mat4(1.0f));
		~Camera();
		
		glm::mat4 GetNormalization() const { return normalization; }
		void SetNormalization(const glm::mat4 &normalization) { this->normalization = normalization; }
	};
}