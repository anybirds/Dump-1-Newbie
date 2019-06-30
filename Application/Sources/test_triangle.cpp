#include <iostream>

#include <Window.hpp>
#include <Mesh.hpp>
#include <Material.hpp>
#include <Renderer.hpp>
#include <Debug.hpp>

#ifdef DEBUG_GENERAL
#define DEBUG
#endif

using namespace std;
using namespace Engine;

int test_triangle(int argc, char **argv) {
	Window::Initialize();
	Window window(800, 600, "test_triangle");
	window.Viewport(0, 0, 800, 600);

#ifdef DEBUG
	cout << "[test_triangle] window creation done ..." << endl;
#endif

	vec3 pos[] = {
		vec3(-0.5f, -0.5f, 0.0f),
		vec3(0.5f, -0.5f, 0.0f),
		vec3(0.0f, 0.5f, 0.0f)
	};

	
	Mesh tri_mesh(3, pos);

#ifdef DEBUG
	cout << "[test_triangle] mesh creation done ..." << endl;
#endif

	Material tri_material;
	const char *tri_vert_path = "Resources\\Shaders\\test_triangle_vertexshader.glsl";
	const char *tri_frag_path = "Resources\\Shaders\\test_triangle_fragmentshader.glsl";
	tri_material.UseShaders(tri_vert_path, tri_frag_path);

#ifdef DEBUG
	cout << "[test_triangle] material shader compilation done ... " << endl;
#endif
	

	Renderer tri_renderer(&tri_mesh, &tri_material);


#ifdef DEBUG
	cout << "[test_triangle] renderer ready ... " << endl;
#endif

	while (!window.Closed()) {
		tri_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}
	Window::Terminate();

	return 0;
}