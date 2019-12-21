#pragma once

namespace Engine {

	class Object;

	class Component {
	private:
		Object *object;

	public:
		struct Data {
			Object *object;
		};

		explicit Component(const Data &data);
		virtual ~Component();

		Engine::Object& GetObject() const { return *object; }
	};
}