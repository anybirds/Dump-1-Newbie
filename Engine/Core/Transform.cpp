#include <glm/gtc/matrix_transform.hpp>

#include <Core/Debug.hpp>
#include <Core/Transform.hpp>

#if defined DEBUG_GRAPHICS || defined DEBUG_PHYSICS
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

Transform::Transform(const Detail &transform) 
	: position(transform.Position), rotation(transform.Rotation), scale(transform.Scale), parent(transform.Parent) {

}

Transform::~Transform() {

}

mat4 Transform::Matrix() const {
	mat4 T = glm::translate(mat4(1.0f), position);
	mat4 R = rotation;
	mat4 S = glm::scale(mat4(1.0f), scale);
	
	mat4 P = parent? parent->Matrix() : mat4(1.0f);
	return P * T * R * S;
}