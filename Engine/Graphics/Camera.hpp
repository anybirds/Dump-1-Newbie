#pragma once

#include <glm/glm.hpp>

#include <Core/Component.hpp>

namespace Engine {

	/*
	Camera Component

	Featured by its normalization matrix. 
	Specify camera properties by directly manipulating the normalization matrix.
	glm::perspective, glm::otrho can be used.
	 */
	class Camera final : public Component {
	private:
		static const Camera *current;

	public:
		static const Camera* Current() { return current; }
		static void Current(const Camera &current) { Camera::current = &current; }

	private:
		glm::mat4 normalization;

	public:
		struct Detail {
			Component::Detail Component;
			glm::mat4 Normalization;
		};

		explicit Camera(const Detail &camera);
		~Camera();
		
		glm::mat4 Normalization() const { return normalization; }
		Camera& Normalization(const glm::mat4 &normalization) { this->normalization = normalization; return *this; }
	};
}