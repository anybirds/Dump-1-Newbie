#pragma once 

#include <Graphics/Mesh.hpp>

namespace Engine {
	class Geometry {
	private:
		static const float tri_vert[];
		static const unsigned tri_attrib[];

		static const float square_vert[];
		static const unsigned square_attrib[];
		static const unsigned square_idx[];

		static const float cube_vert[];
		static const unsigned cube_attrib[];
		static const unsigned cube_idx[];

	public:
		static Engine::Mesh::Data Triangle;
		static Engine::Mesh::Data Square;
		static Engine::Mesh::Data Cube;
	};
}
