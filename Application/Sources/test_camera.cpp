#include <Engine.hpp>

#ifdef DEBUG_GENERAL
#define DEBUG
#endif

using namespace std;
using namespace Engine;

int test_camera(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	/*
	  4---7
	 /|  /|
	0---3 |
	| 5-|-6
	|/  |/
	1---2
	*/

	vec3 cube_pos[] = {
		vec3(-0.5f, 0.5f, -0.5f),
		vec3(-0.5f, -0.5f, -0.5f),
		vec3(0.5f, -0.5f, -0.5f),
		vec3(0.5f, 0.5f, -0.5f),
		vec3(-0.5f, 0.5f, 0.5f),
		vec3(-0.5f, -0.5f, 0.5f),
		vec3(0.5f, -0.5f, 0.5f),
		vec3(0.5f, 0.5f, 0.5f),
	};

	unsigned cube_idx[] = {
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

	Mesh cube_mesh(8, cube_pos, 36, cube_idx);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string vert_path = "Resources\\Shaders\\test_camera_vertexshader.glsl";
	string frag_path = "Resources\\Shaders\\test_camera_fragmentshader.glsl";
	Material material(vert_path, frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif

	Transform cube_transform;

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " transform matrix calculation done ... " << endl;
#endif

	vec3 camera_pos(1.0f, 1.0f, 5.0f);
	Transform camera_transform(camera_pos);
	mat4 projection_normalization(perspective(radians(60.0f), (float)window.Width() / (float)window.Height(), 0.1f, 1000.0f));
	Camera camera(camera_transform, projection_normalization);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " camera configuration done ... " << endl;
#endif

	Renderer::Camera(camera);
	Renderer cube_renderer(cube_mesh, material, cube_transform);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		cube_renderer.Render();
		
		window.SwapBuffers();
		glfwPollEvents();
	}

	return 0;
}