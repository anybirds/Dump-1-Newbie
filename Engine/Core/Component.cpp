#include <Core/Component.hpp>

using namespace Engine;

Component::Component(const Detail &component) : object(component.Object) {

}

Component::~Component() {

}