#include <Engine.hpp>

#include <Material/DefaultMaterial.hpp>
#include <Mesh/Geometry.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int test_mesh_triangle(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	Mesh tri_mesh(Geometry::Triangle);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string tri_vert_path = "Resource\\Shader\\test_mesh_triangle_vertexshader.glsl";
	string tri_frag_path = "Resource\\Shader\\test_mesh_triangle_fragmentshader.glsl";
	DefaultMaterial tri_material(tri_vert_path, tri_frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif
	
	Renderer tri_renderer(tri_mesh, tri_material);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		tri_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}

	return 0;
}