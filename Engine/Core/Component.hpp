#pragma once

namespace Engine {

	class Object;

	/*
	Component
	
	Base class for components that comprise an Object.
	*/
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