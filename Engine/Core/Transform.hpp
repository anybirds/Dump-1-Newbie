#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Engine {	

	/*
	Transform

	Object's position, rotation, scale and hierarchical parent information.
	 */
	class Transform final {
	private:
		glm::vec3 position;
		glm::mat4 rotation;
		glm::vec3 scale;
		const Transform *parent;

	public:
		struct Detail {
			glm::vec3 Position;
			glm::mat4 Rotation;
			glm::vec3 Scale;
			const class Transform *Parent;
		};

		Transform(const Detail &transform);
		~Transform();

		glm::vec3 Position() const { return position; }
		Transform& Position(const glm::vec3 &position) { this->position = position; return *this; }
		glm::mat4 Rotation() const { return rotation; }
		Transform& Rotation(const glm::mat4 &rotation) { this->rotation = rotation; return *this; }
		glm::vec3 Scale() const { return scale; }
		Transform& Scale(const glm::vec3 &scale) { this->scale = scale; return *this; }

		/*
		Computes transform's 4*4 matrix representation. 
		 */
		glm::mat4 Matrix() const;
	};
}