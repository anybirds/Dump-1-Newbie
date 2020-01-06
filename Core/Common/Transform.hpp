#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Core {	

	/*
	Transform that has position, rotation, scale and hierarchical parent information.
	*/
	class Transform final {
	private:
		glm::vec3 position;
		glm::mat4 rotation;
		glm::vec3 scale;
		Transform *parent;

	public:
		Transform();
		Transform(const glm::vec3 &position, const glm::mat4 &rotation, const glm::vec3 &scale, Transform *parent = nullptr);
		~Transform();

		glm::vec3 GetPosition() const { return position; }
		void SetPosition(const glm::vec3 &position) { this->position = position; }
		glm::mat4 GetRotation() const { return rotation; }
		void SetRotation(const glm::mat4 &rotation) { this->rotation = rotation; }
		glm::vec3 GetScale() const { return scale; }
		void SetScale(const glm::vec3 &scale) { this->scale = scale; }
		Transform* GetParent() const { return parent; }
		void SetParent(Transform *parent) { this->parent = parent; }

		/*Computes transform's 4*4 matrix representation*/
		glm::mat4 GetMatrix() const;
	};
}