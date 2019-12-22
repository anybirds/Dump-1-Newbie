#include <Core/Component.hpp>
#include <Core/Object.hpp>
#include <Core/World.hpp>

using namespace Engine;

Object::Object(const Data &object) : name(object.name), transform(object.transform_data) {
	World::AddObject(*this);
}

Object::~Object() {
	for (auto item : component) {
		delete item.second;
	}

	World::RemoveObject(*this);
}