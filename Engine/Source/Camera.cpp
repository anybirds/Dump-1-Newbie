#include <Camera.hpp>
#include <Debug.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

Camera::Camera(const Engine::Transform &transform, const mat4 &normalization) : transform(&transform), normalization(normalization) {
	
}

Camera::~Camera() {

}
