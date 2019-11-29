#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

namespace Engine {	
	/**
	 * @brief Engine::Transform class
	 */
	class Transform final {
	private:
		static const mat4 default_transform;
		static const vec3 default_position;
		static const mat4 default_rotation;
		static const vec3 default_scale;

	private:
		vec3 position;
		mat4 rotation;
		vec3 scale;
		const Transform *parent;

	public:
		Transform(const vec3 &position = default_position, const mat4 &rotation = default_rotation, const vec3 &scale = default_scale);
		Transform(const Transform &parent, const vec3 &position = default_position, const mat4 &rotation = default_rotation, const vec3 &scale = default_scale);
		~Transform();

		vec3 Position() const { return position; }
		void Position(const vec3 &position) { this->position = position; }
		mat4 Rotation() const { return rotation; }
		void Rotation(const mat4 &rotation) { this->rotation = rotation; }
		vec3 Scale() const { return scale; }
		void Scale(const vec3 &scale) { this->scale = scale; }

		/**
		 * @brief Matrix method computes transform's 4*4 matrix representation. 
		 * @todo Lazy computation of transform matrix.
		 */
		mat4 Matrix() const;
	};
}