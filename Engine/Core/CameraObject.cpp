#include <Core/CameraObject.hpp>

using namespace glm;
using namespace Engine;

const CameraObject *CameraObject::current;

CameraObject::CameraObject(const Detail &camera_object) 
	: Object(camera_object.Object), camera(camera_object.Camera) {

}

CameraObject::~CameraObject() {

}