#include <Core/Component.hpp>
#include <Core/Object.hpp>

using namespace Engine;

Object::Object(const Data &object) : scene(object.scene), name(object.name), transform(object.transform_data) {
	
}

Object::~Object() {
	for (auto item : component) {
		delete item.second;
	}
}