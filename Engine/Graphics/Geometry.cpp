#include <Graphics/Geometry.hpp>

using namespace Engine;

const float Geometry::tri_vert[] = {
	0.0f, 1.0f, 0.0f,		0.5f, 0.0f,
	-1.0f, -1.0f, 0.0f,		0.0f, 1.0f,
	1.0f, -1.0f, 0.0f,		1.0f, 1.0f
};

const unsigned Geometry::tri_attrib[] = {
	3, 0, 2
};

const float Geometry::square_vert[] = {
	-1.0f, 1.0f, 0.0f,		0.0f, 0.0f,
	-1.0f, -1.0f, 0.0f,		0.0f, 1.0f,
	1.0f, -1.0f, 0.0f,		1.0f, 1.0f,
	1.0f, 1.0f, 0.0f,		1.0f, 0.0f
};

const unsigned Geometry::square_attrib[] = {
	3, 0, 2
};

const unsigned Geometry::square_idx[] = {
	0, 1, 2, 
	0, 2, 3
};

/*
  4---7
 /|  /|
0---3 |
| 5-|-6
|/  |/
1---2
*/

const float Geometry::cube_vert[] = {
	-1.0f, 1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, -1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
};

const unsigned Geometry::cube_attrib[] = {
	3
};

const unsigned Geometry::cube_idx[] = {
	4, 5, 1,
	1, 0, 4,
	3, 2, 6,
	6, 7, 3,
	1, 2, 6,
	6, 5, 1,
	4, 0, 3,
	3, 7, 4,
	0, 1, 2,
	2, 3, 0,
	7, 6, 5,
	5, 4, 7
};

Mesh::Data Geometry::Triangle{ tri_vert, tri_attrib, nullptr, 3, 3, 0 };
Mesh::Data Geometry::Square{ square_vert, square_attrib, square_idx, 4, 3, 6 };
Mesh::Data Geometry::Cube{ cube_vert, cube_attrib, cube_idx, 8, 1, 36 };