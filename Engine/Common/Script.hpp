#pragma once

#include <../Core/Common/Script.hpp>
#include <Common/ManagedObject.hpp>
#include <Common/Component.hpp>

namespace Engine {
	public ref class Script : public ManagedObject<Core::Script>, public IComponent {
	private:
		GameObject ^m_gameObject;

	public:
		Script(GameObject ^gameObject);

		property GameObject ^gameObject {
			virtual GameObject ^get() {
				return m_gameObject;
			}
		}
		
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}