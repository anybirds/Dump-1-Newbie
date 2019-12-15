#include <Script/RotateScript.hpp>
#include <Engine.hpp>

using namespace glm;
using namespace Engine;

RotateScript::RotateScript(const Detail &rotate_script) 
	: Component(rotate_script.Component), Script(Object().Scene()), rate(rotate_script.Rate) {

}

RotateScript::~RotateScript() {

}

void RotateScript::Start() {

}

void RotateScript::Update() {
	Transform &transform = Object().Transform();
	transform.Rotation(rotate(transform.Rotation(), radians(rate * Time::DeltaTime()), vec3(0.0f, 1.0f, 0.0f)));
}