#include <Engine.hpp>

#include <Material/DefaultMaterial.hpp>
#include <Mesh/Geometry.hpp>

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif

using namespace std;
using namespace glm;
using namespace Engine;

int test_transform(int argc, char **argv) {
	Window window(600, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	Mesh tri_mesh(Geometry::Triangle);
	Mesh square_mesh(Geometry::Square);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string vert_path = "Resource\\Shader\\test_transform_vertexshader.glsl";
	string frag_path = "Resource\\Shader\\test_transform_fragmentshader.glsl";
	DefaultMaterial material(vert_path, frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif

	Transform square_transform(vec3(0.0f, -0.5f, 0.0f), glm::rotate(mat4(1.0f), radians(30.0f), vec3(0.0f, 0.0f, 1.0f)), vec3(0.5f, 0.5f, 0.5f));
	Transform tri_transform(square_transform, vec3(0.0f, 2.0f, 0.0f), mat4(1.0f));

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " transform matrix calculation done ... " << endl;
#endif

	Renderer tri_renderer(tri_mesh, material, tri_transform);
	Renderer square_renderer(square_mesh, material, square_transform);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		tri_renderer.Render();
		square_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}

	return 0;
}