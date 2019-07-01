#include <Engine.hpp>

#ifdef DEBUG_GENERAL
#define DEBUG
#endif

using namespace std;
using namespace Engine;

int test_mesh_triangle(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	vec3 pos[] = {
		vec3(-0.5f, -0.5f, 0.0f),
		vec3(0.5f, -0.5f, 0.0f),
		vec3(0.0f, 0.5f, 0.0f)
	};

	Mesh tri_mesh(3, pos);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string tri_vert_path = "Resources\\Shaders\\test_mesh_triangle_vertexshader.glsl";
	string tri_frag_path = "Resources\\Shaders\\test_mesh_triangle_fragmentshader.glsl";
	Material tri_material(tri_vert_path, tri_frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif
	
	Renderer tri_renderer(tri_mesh, tri_material);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer ready ... " << endl;
#endif

	while (!window.Closed()) {
		tri_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}

	return 0;
}