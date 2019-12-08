#include <glm/gtc/matrix_transform.hpp>

#include <Debug.hpp>
#include <Transform.hpp>

#if defined DEBUG_GRAPHICS || defined DEBUG_PHYSICS
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

const mat4 Transform::default_transform	= mat4(1.0f);
const vec3 Transform::default_position = vec3(0.0f);
const mat4 Transform::default_rotation = mat4(1.0f);
const vec3 Transform::default_scale = vec3(1.0f);

Transform::Transform(const vec3 &position, const mat4 &rotation, const vec3 &scale) 
: position(position), rotation(rotation), scale(scale), parent() {
	
}

Transform::Transform(const Transform &parent, const vec3 &position, const mat4 &rotation, const vec3 &scale) 
: position(position), rotation(rotation), scale(scale), parent(&parent) {
	
}

Transform::~Transform() {

}

mat4 Transform::Matrix() const {
	mat4 T = glm::translate(mat4(1.0f), position);
	mat4 R = rotation;
	mat4 S = glm::scale(mat4(1.0f), scale);
	
	mat4 P = parent? parent->Matrix() : default_transform;
	return P * T * R * S;
}