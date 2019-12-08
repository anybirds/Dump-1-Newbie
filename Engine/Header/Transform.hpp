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
		static const glm::mat4 default_transform;
		static const glm::vec3 default_position;
		static const glm::mat4 default_rotation;
		static const glm::vec3 default_scale;

	private:
		glm::vec3 position;
		glm::mat4 rotation;
		glm::vec3 scale;
		const Transform *parent;

	public:
		Transform(const glm::vec3 &position = default_position, const glm::mat4 &rotation = default_rotation, const glm::vec3 &scale = default_scale);
		Transform(const Transform &parent, const glm::vec3 &position = default_position, const glm::mat4 &rotation = default_rotation, const glm::vec3 &scale = default_scale);
		~Transform();

		glm::vec3 Position() const { return position; }
		void Position(const glm::vec3 &position) { this->position = position; }
		glm::mat4 Rotation() const { return rotation; }
		void Rotation(const glm::mat4 &rotation) { this->rotation = rotation; }
		glm::vec3 Scale() const { return scale; }
		void Scale(const glm::vec3 &scale) { this->scale = scale; }

		/**
		 * @brief Matrix method computes transform's 4*4 matrix representation. 
		 * @todo Lazy computation of transform matrix.
		 */
		glm::mat4 Matrix() const;
	};
}