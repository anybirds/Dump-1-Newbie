#include <Camera.hpp>

using namespace Engine;

Camera::Camera(const Engine::Transform &transform, const mat4 &normalization) : transform(&transform), normalization(normalization) {
	
}

Camera::~Camera() {

}
