#include <Core/Debug.hpp>
#include <Graphics/Camera.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

const Camera *Camera::current;

Camera::Camera(const Data &data) : Component(data), normalization(data.normalization) {
	
}

Camera::~Camera() {

}
