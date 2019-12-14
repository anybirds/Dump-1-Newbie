#include <Core/Object.hpp>

using namespace Engine;

Object::Object(const Detail &object) : transform(object.Transform) {
	
}

Object::~Object() {

}