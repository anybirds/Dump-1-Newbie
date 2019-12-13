#include <Mesh/Geometry.hpp>


const float Geometry::tri_vert[] = {
	0.0f, 1.0f, 0.0f,		0.0f, 0.0f, 1.0f,		0.5f, 0.0f,
	-1.0f, -1.0f, 0.0f,		0.0f, 0.0f, 1.0f,		0.0f, 1.0f,
	1.0f, -1.0f, 0.0f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f
};

const unsigned Geometry::tri_attrib[] = {
	3, 3, 2
};

const float Geometry::square_vert[] = {
	-1.0f, 1.0f, 0.0f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
	-1.0f, -1.0f, 0.0f,		0.0f, 0.0f, 1.0f,		0.0f, 1.0f,
	1.0f, -1.0f, 0.0f,		0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
	1.0f, 1.0f, 0.0f,		0.0f, 0.0f, 1.0f,		1.0f, 0.0f
};

const unsigned Geometry::square_attrib[] = {
	3, 3, 2
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

MeshDetail Geometry::Triangle{ 3, tri_vert, 3, tri_attrib, 0, nullptr };
MeshDetail Geometry::Square{ 4, square_vert, 3, square_attrib, 6, square_idx };
MeshDetail Geometry::Cube{ 8, cube_vert, 1, cube_attrib, 36, cube_idx };