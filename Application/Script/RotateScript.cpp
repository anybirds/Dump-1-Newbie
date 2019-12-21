#include <Script/RotateScript.hpp>
#include <Engine.hpp>

using namespace glm;
using namespace Engine;

RotateScript::RotateScript(const Data &data) 
	: Component(data), Script(GetObject().GetScene()), 
	rate(data.rate) {

}

RotateScript::~RotateScript() {

}

void RotateScript::Start() {

}

void RotateScript::Update() {
	Transform &transform = GetObject().GetTransform();
	transform.SetRotation(rotate(transform.GetRotation(), radians(rate * Time::DeltaTime()), vec3(0.0f, 1.0f, 0.0f)));
}