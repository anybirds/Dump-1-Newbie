#pragma once

namespace Engine {
	class Object;

	class Component {
	private:
		const Object *object;

	public:
		Component();
		virtual ~Component();

		const class Engine::Object& Object() const { return *object; }
		Component& Object(const class Engine::Object& object) { this->object = &object; return *this; }
	};
}