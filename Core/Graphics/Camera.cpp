#include <Common/Debug.hpp>
#include <Graphics/Camera.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace glm;
using namespace Core;

const Camera *Camera::current;

Camera::Camera(GameObject *object, const mat4 &normalization) : Component(object), normalization(normalization) {
	
}

Camera::~Camera() {

}
