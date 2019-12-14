#include <Core/Component.hpp>
#include <iostream>
using namespace Engine;

Component::Component(const Detail &component) : object(component.Object) {

}

Component::~Component() {

}