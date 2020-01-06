#pragma once

namespace Core {
	
	class GameObject;
	
	class Component {
	private:
		GameObject *const object;

	public:
		Component(GameObject *object);
		virtual ~Component();

		GameObject* GetGameObject() const { return object; }
	};
}