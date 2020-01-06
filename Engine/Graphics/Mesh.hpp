#pragma once

#include <../Core/Graphics/Mesh.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {
	public ref class Mesh sealed : public ManagedObject<Core::Mesh> {
	private:
		static System::Collections::Generic::Dictionary<System::String^, Mesh^> m_meshes;

	public:
		static Mesh^ Find(System::String ^name);

	private:
		System::String ^m_name;

	public:
		Mesh(array<float> ^vert, array<int> ^attrib);
		Mesh(array<float> ^vert, array<int> ^attrib, array<int> ^idx);

		/*used in App, Editor*/
		Mesh(System::String ^name, array<float> ^vert, array<int> ^attrib);
		Mesh(System::String ^name, array<float> ^vert, array<int> ^attrib, array<int> ^idx);

		void Destroy() override;

		property System::String ^name {
			System::String ^get() {
				return m_name;
			}
			void set(System::String ^value) {
				m_name = value;
			}
		}
	};
}