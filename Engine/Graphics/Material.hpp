#pragma once

#using <System.Numerics.dll>

#include <../Core/Graphics/Material.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {
	public ref class Material sealed : public ManagedObject<Core::Material> {
	private:
		static System::Collections::Generic::Dictionary<System::String^, Material^> m_materials;
		
	public:
		static Material^ Find(System::String ^name);

	private:
		System::String ^m_name;

	public:
		Material(System::String ^vert_path, System::String ^frag_path);

		/*used in App, Editor*/
		Material(System::String ^name, System::String ^vert_path, System::String ^frag_path);

		void UseShader(System::String ^vert_path, System::String ^frag_path);

		void GetInteger();
		void GetIntegerArray();
		void GetFloat();
		void GetFloatArray();
		void GetVector();
		void GetVectorArray();
		void GetColor();
		void GetColorArray();
		void GetMatrix();
		void GetMatrixArray();

		void SetInteger();
		void SetIntegerArray();
		void SetFloat();
		void SetFloatArray();
		void SetVector();
		void SetVectorArray();
		void SetColor();
		void SetColorArray();
		void SetMatrix();
		void SetMatrixArray();

		virtual void Destroy() override {

		}

		virtual bool IsEmpty() override {

		}

		property System::String ^name {
			System::String ^get() {

			}
			void set(System::String ^value) {

			}
		}
	};
}