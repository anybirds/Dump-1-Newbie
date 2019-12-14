#include <Core/Object.hpp>

using namespace Engine;

Object::Object(const Detail &object) : scene(object.Scene), name(object.Name), transform(object.Transform) {
	
}

Object::~Object() {
	for (auto item : component) {
		delete item.second;
	}
}