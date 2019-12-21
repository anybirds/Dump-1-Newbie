#include <glm/gtc/matrix_transform.hpp>

#include <Core/Debug.hpp>
#include <Core/Transform.hpp>

#ifdef DEBUG_CORE
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

Transform::Transform(const Data &data) 
	: position(data.position), rotation(data.rotation), scale(data.scale), parent(data.parent) {

}

Transform::~Transform() {

}

mat4 Transform::GetMatrix() const {
	mat4 T = glm::translate(mat4(1.0f), position);
	mat4 R = rotation;
	mat4 S = glm::scale(mat4(1.0f), scale);
	
	mat4 P = parent? parent->GetMatrix() : mat4(1.0f);
	return P * T * R * S;
}