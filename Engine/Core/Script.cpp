#include <Core/Scene.hpp>
#include <Core/Script.hpp>

using namespace Engine;

Script::Script(Scene &scene) : scene(scene) {
	scene.script.insert(this);
}

Script::~Script() {
	scene.script.erase(this);
}