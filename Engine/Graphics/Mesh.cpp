#include <Graphics/Mesh.hpp>

using namespace System;
using namespace Engine;

Mesh^ Mesh::Find(String ^name) {
	Mesh^ mesh;
	m_meshes.TryGetValue(name, mesh);
	return mesh;
}

Mesh::Mesh(array<float> ^vert, array<int> ^attrib) 
	: ManagedObject<Core::Mesh>(new Core::Mesh(&vert[0], vert->Length, &attrib[0], attrib->Length)) {
	
}

Mesh::Mesh(array<float> ^vert, array<int> ^attrib, array<int> ^idx) 
	: ManagedObject<Core::Mesh>(new Core::Mesh(&vert[0], vert->Length, &attrib[0], attrib->Length, &idx[0], idx->Length)){

}

Mesh::Mesh(String ^name, array<float> ^vert, array<int> ^attrib)
	: ManagedObject<Core::Mesh>(new Core::Mesh(&vert[0], vert->Length, &attrib[0], attrib->Length)) {
	m_name = name;
	m_meshes.Add(m_name, this);
}

Mesh::Mesh(String ^name, array<float> ^vert, array<int> ^attrib, array<int> ^idx)
	: ManagedObject<Core::Mesh>(new Core::Mesh(&vert[0], vert->Length, &attrib[0], attrib->Length, &idx[0], idx->Length)) {
	m_meshes.Add(m_name, this);
}

void Mesh::Destroy() {
	m_meshes.Remove(m_name);
	ManagedObject<Core::Mesh>::Destroy();
}