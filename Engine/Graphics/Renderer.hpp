#pragma once

#include <../Core/Graphics/Renderer.hpp>
#include <Common/Component.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {
	ref class Mesh;
	ref class Material;

	/*
	Responsible for rendering GameObjects that have Mesh and Material.
	*/
	public ref class Renderer : public ManagedObject<Core::Renderer>, public IComponent {
	private:
		GameObject ^m_gameObject;
		Mesh ^m_mesh;
		Material ^m_material;

	internal:
		/*creating an instance of component is only possible by GameObject::AddComponent*/
		Renderer(GameObject ^gameObject);

	public:
		void Render();

		virtual void Destroy() override;

		property Mesh ^mesh {
			Mesh ^get() {
				return m_mesh;
			}
			void set(Mesh ^value) {
				m_mesh = value;
			}
		}

		property Material ^material {
			Material ^get() {
				return m_material;
			}
			void set(Material ^value) {
				m_material = value;	
			}
		}

		property GameObject ^gameObject {
			virtual GameObject ^get() {
				return m_gameObject;
			}
		}
	};
}