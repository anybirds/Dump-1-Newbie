#include <Core/Object.hpp>
#include <Core/Scene.hpp>
#include <Core/Script.hpp>

#include <iostream>

using namespace Engine;

Script::Script(const Component &component) : component(&component) {
	std::cout << "properly added" << '\n';
	component.Object().Scene().script.insert(this);
}

Script::~Script() {
	component->Object().Scene().script.erase(this);
}