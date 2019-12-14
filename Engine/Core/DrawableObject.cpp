#include <Core/DrawableObject.hpp>

using namespace Engine;

DrawableObject::DrawableObject(const Detail &drawable_object) 
	: Object(drawable_object.Object), renderer(drawable_object.Renderer) {
	renderer.Transform(transform);
}

DrawableObject::~DrawableObject() {

}