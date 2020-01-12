#pragma once

#using <System.Numerics.dll>

#include <GL/glew.h>

#include <../Core/Graphics/Material.hpp>
#include <Common/ManagedObject.hpp>

namespace Engine {
	
	ref class Shader;
	
	/*
	Defines how a Mesh is being drawn.
	Attaches Shaders to the program object, which gets linked right after.
	 */
	public ref class Material sealed : public ManagedObject<Core::Material> {
	private:
		static System::Collections::Generic::Dictionary<System::String^, Material^> ^m_materials;
		
	public:
		static Material();
		static Material^ Find(System::String ^name);

	private:
		System::String ^m_name;

		System::Collections::Generic::Dictionary<System::String^, int> ^m_ints;
		System::Collections::Generic::Dictionary<System::String^, array<int>^> ^m_intarrs;
		System::Collections::Generic::Dictionary<System::String^, float> ^m_floats;
		System::Collections::Generic::Dictionary<System::String^, array<float>^> ^m_floatarrs;
		System::Collections::Generic::Dictionary<System::String^, System::Numerics::Vector4> ^m_vecs;
		System::Collections::Generic::Dictionary<System::String^, array<System::Numerics::Vector4>^> ^m_vecarrs;
		System::Collections::Generic::Dictionary<System::String^, System::Numerics::Matrix4x4> ^m_mats;
		System::Collections::Generic::Dictionary<System::String^, array<System::Numerics::Matrix4x4>^> ^m_matarrs;

	internal:
		property GLuint program {
			GLuint get() {
				return instance->GetProgram();
			}
		}

	public:
		Material(Shader ^vert_shader, Shader ^frag_shader);

		/*used in App, Editor*/
		Material(System::String ^name, Shader ^vert_shader, Shader ^frag_shader);

		int GetInteger(System::String ^name);
		array<int>^ GetIntegerArray(System::String ^name);
		float GetFloat(System::String ^name);
		array<float>^ GetFloatArray(System::String ^name);
		System::Numerics::Vector4 GetVector(System::String ^name);
		array<System::Numerics::Vector4>^ GetVectorArray(System::String ^name);
		System::Numerics::Matrix4x4 GetMatrix(System::String ^name);
		array<System::Numerics::Matrix4x4>^ GetMatrixArray(System::String ^name);

		void SetInteger(System::String ^name, int value);
		void SetIntegerArray(System::String ^name, array<int> ^value);
		void SetFloat(System::String ^name, float value);
		void SetFloatArray(System::String ^name, array<float> ^value);
		void SetVector(System::String ^name, System::Numerics::Vector4 value);
		void SetVectorArray(System::String ^name, array<System::Numerics::Vector4> ^value);
		void SetMatrix(System::String ^name, System::Numerics::Matrix4x4 value);
		void SetMatrixArray(System::String ^name, array<System::Numerics::Matrix4x4> ^value);

		virtual void Destroy() override;

		property System::String ^name {
			System::String ^get() {
				return m_name;
			}
			void set(System::String ^value) {
				m_materials->Remove(m_name);
				m_name = value;
				m_materials->Add(m_name, this);
			}
		}
	};
}