#pragma once

#include <../Core/Graphics/Mesh.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {

	/*
	Represents a wireframe that exists in the GameObject space.
	Mesh GameObject can consist points in 2D, 3D or whatever dimensional space.
	Vertices can have multiple attributes and represent indexed wireframe.
	*/
	public ref class Mesh sealed : public ManagedObject<Core::Mesh> {
	private:
		static System::Collections::Generic::Dictionary<System::String^, Mesh^> ^m_meshes;

	public:
		static Mesh();
		static Mesh^ Find(System::String ^name);

	private:
		System::String ^m_name;

	internal:
		property int vertexCount {
			int get() {
				return instance->GetVertexCount();
			}
		}
		property int indexCount {
			int get() {
				return instance->GetIndexCount();
			}
		}
		property GLuint vao {
			GLuint get() {
				return instance->GetVao();
			}
		}

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
				m_meshes->Remove(m_name);
				m_name = value;
				m_meshes->Add(m_name, this);
			}
		}
	};
}