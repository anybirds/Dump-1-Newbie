#include <Engine.hpp>

#ifdef DEBUG_GENERAL
#define DEBUG
#endif

using namespace std;
using namespace Engine;

int test_mesh_quad(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	vec3 pos[] = {
		vec3(-0.5f, 0.5f, 0.0f),
		vec3(-0.5f, -0.5f, 0.0f),
		vec3(0.5f, -0.5f, 0.0f),
		vec3(0.5f, 0.5f, 0.0f)
	};

	unsigned idx[] = { 
		0, 1, 2,
		2, 3, 0
	};

	Mesh quad_mesh(4, pos, 6, idx);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string quad_vert_path = "Resources\\Shaders\\test_mesh_quad_vertexshader.glsl";
	string quad_frag_path = "Resources\\Shaders\\test_mesh_quad_fragmentshader.glsl";
	Material quad_material(quad_vert_path, quad_frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif


	Renderer quad_renderer(quad_mesh, quad_material);


#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		quad_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}

	return 0;
}