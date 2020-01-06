#pragma once

namespace Core {
	
	class Transform;

	class GameObject final {
	private:
		Transform *const transform;
	public:
		GameObject(Transform *transform);
		~GameObject();

		Transform* GetTransform() const { return transform; }
	};
}