/*
#include <Common/Utility.hpp>
#include <Graphics/Material.hpp>
#include <Graphics/Shader.hpp>

using namespace System;
using namespace Engine;

static Material::Material() {
	m_materials = gcnew System::Collections::Generic::Dictionary<System::String^, Material^>();
}

Material^ Material::Find(String ^name) {
	Material ^material;
	m_materials->TryGetValue(name, material);
	return material;
}

Material::Material(Shader ^vert_shader, Shader ^frag_shader) 
	: ManagedObject<Core::Material>(new Core::Material(vert_shader->instance, frag_shader->instance)) {
	
}

Material::Material(String ^name, Shader ^vert_shader, Shader ^frag_shader) 
	: ManagedObject<Core::Material>(new Core::Material(vert_shader->instance, frag_shader->instance)), m_name(name) {
	m_materials->Add(m_name, this);
}


int Material::GetInteger(System::String ^name) {

}

array<int>^ Material::GetIntegerArray(System::String ^name) {
	
}

float Material::GetFloat(System::String ^name) {
	
}

array<float>^ Material::GetFloatArray(System::String ^name) {


}

System::Numerics::Vector4 Material::GetVector(System::String ^name) {

}

array<System::Numerics::Vector4>^ Material::GetVectorArray(System::String ^name) {

}

System::Numerics::Matrix4x4 Material::GetMatrix(System::String ^name) {

}

array<System::Numerics::Matrix4x4>^ Material::GetMatrixArray(System::String ^name) {

}

void Material::SetInteger(System::String ^name, int value) {

}
void Material::SetIntegerArray(System::String ^name, array<int> ^value) {

}
void Material::SetFloat(System::String ^name, float value) {

}
void Material::SetFloatArray(System::String ^name, array<float> ^value) {

}
void Material::SetVector(System::String ^name, System::Numerics::Vector4 value) {

}
void Material::SetVectorArray(System::String ^name, array<System::Numerics::Vector4> ^value) {

}
void Material::SetMatrix(System::String ^name, System::Numerics::Matrix4x4 value) {

}
void Material::SetMatrixArray(System::String ^name, array<System::Numerics::Matrix4x4> ^value) {

}

void Material::Destroy() {
	m_materials->Remove(m_name);
	ManagedObject<Core::Material>::Destroy();
}
*/