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
		static const Camera* GetCurrentCamera() { return current; }
		static void SetCurrentCamera(const Camera &current) { Camera::current = &current; }

	private:
		glm::mat4 normalization;

	public:
		struct Data : Component::Data {
			glm::mat4 normalization;
		};

		explicit Camera(const Data &data);
		~Camera();
		
		glm::mat4 GetNormalization() const { return normalization; }
		Camera& SetNormalization(const glm::mat4 &normalization) { this->normalization = normalization; return *this; }
	};
}