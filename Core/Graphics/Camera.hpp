#pragma once

#include <glm/glm.hpp>

namespace Core {
	class Camera final {
	private:
		static const Camera *current;

	public:
		static const Camera* GetCurrentCamera() { return current; }
		static void SetCurrentCamera(const Camera *current) { Camera::current = current; }

	private:
		glm::mat4 normalization;

	public:
		Camera(const glm::mat4 &normalization = glm::mat4(1.0f));
		~Camera();
		
		glm::mat4 GetNormalization() const { return normalization; }
		void SetNormalization(const glm::mat4 &normalization) { this->normalization = normalization; }
	};
}