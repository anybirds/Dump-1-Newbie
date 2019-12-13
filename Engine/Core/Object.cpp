#include <Core/Object.hpp>

using namespace Engine;

Object::Object(const ObjectDetail &object) : transform(object.Transform) {
	
}

Object::~Object() {

}