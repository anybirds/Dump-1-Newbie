#pragma once

#using <System.Numerics.dll>

#include <../Core/Graphics/Camera.hpp>
#include <Common/Component.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {
	
	ref class Transform;

	public ref class Camera sealed : public ManagedObject<Core::Camera>, public IComponent {
	private:
		static Camera ^m_current;

	public:
		static property Camera ^current {
			Camera ^get() {
				return m_current;
			}
			void set(Camera ^value) {
				m_current = value;
			}
		}

	private:
		GameObject ^m_gameObject;
		System::Numerics::Matrix4x4 m_normalization;

	internal:
		/*creating an instance of component is only possible by GameObject::AddComponent*/
		Camera(GameObject ^gameObject);

	public:
		void Destroy() override;

		property System::Numerics::Matrix4x4 normalization {
			System::Numerics::Matrix4x4 get() {
				return m_normalization;
			}
			void set(System::Numerics::Matrix4x4 value) {
				m_normalization = value;
			}
		}

		property GameObject ^gameObject {
			virtual GameObject ^get() override {
				return m_gameObject;
			}
		}
	};
}