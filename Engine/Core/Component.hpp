#pragma once

namespace Engine {

	class Object;

	class Component {
	private:
		Object *object;

	public:
		struct Detail {
			Object *Object;
		};

		Component(const Detail &component);
		virtual ~Component();

		Engine::Object& Object() const { return *object; }
	};
}