#include <Engine.hpp>

#include <Material/DefaultMaterial.hpp>
#include <Mesh/Geometry.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int test_mesh_square(int argc, char **argv) {
	Window window(800, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	Mesh square_mesh(Geometry::Square);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string square_vert_path = "Resource\\Shader\\test_mesh_square_vertexshader.glsl";
	string square_frag_path = "Resource\\Shader\\test_mesh_square_fragmentshader.glsl";
	DefaultMaterial square_material(square_vert_path, square_frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif

	Renderer square_renderer(square_mesh, square_material);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		square_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}

	return 0;
}