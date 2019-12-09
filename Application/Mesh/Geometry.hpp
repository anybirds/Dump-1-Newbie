#include <Engine.hpp>

using namespace Engine;

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
	static MeshDetail Triangle;
	static MeshDetail Square;
	static MeshDetail Cube;
};