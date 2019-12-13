#include <Core/Debug.hpp>
#include <Graphics/Camera.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

Camera::Camera(const CameraDetail &camera) : normalization(camera.Normalization) {
	
}

Camera::~Camera() {

}
