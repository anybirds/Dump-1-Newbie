#pragma once

#include <../Core/Graphics/Renderer.hpp>
#include <Common/Component.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {
	ref class Mesh;
	ref class Material;

	public ref class Renderer : public ManagedObject<Core::Renderer>, public IComponent {
	private:
		GameObject ^m_gameObject;
		Mesh ^m_mesh;
		Material ^m_material;

	internal:
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
			virtual GameObject ^get() override {
				return m_gameObject;
			}
		}
	};
}