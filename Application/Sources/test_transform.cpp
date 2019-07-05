#include <Engine.hpp>

#ifdef DEBUG_GENERAL
#define DEBUG
#endif

using namespace std;
using namespace Engine;

int test_transform(int argc, char **argv) {
	Window window(600, 600, __FUNCTION__);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " window creation done ..." << endl;
#endif

	vec3 tri_pos[] = {
		vec3(-0.5f, -0.5f, 0.0f),
		vec3(0.5f, -0.5f, 0.0f),
		vec3(0.0f, 0.5f, 0.0f)
	};

	vec3 quad_pos[] = {
		vec3(-0.5f, 0.5f, 0.0f),
		vec3(-0.5f, -0.5f, 0.0f),
		vec3(0.5f, -0.5f, 0.0f),
		vec3(0.5f, 0.5f, 0.0f)
	};

	unsigned quad_idx[] = {
		0, 1, 2,
		2, 3, 0
	};

	Mesh tri_mesh(3, tri_pos);
	Mesh quad_mesh(4, quad_pos, 6, quad_idx);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " mesh creation done ..." << endl;
#endif

	string vert_path = "Resources\\Shaders\\test_transform_vertexshader.glsl";
	string frag_path = "Resources\\Shaders\\test_transform_fragmentshader.glsl";
	Material material(vert_path, frag_path);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " material shader compilation done ... " << endl;
#endif

	Transform quad_transform(vec3(0.0f, -0.5f, 0.0f), glm::rotate(mat4(1.0f), radians(30.0f), vec3(0.0f, 0.0f, 1.0f)), vec3(0.5f, 0.5f, 0.5f));
	Transform tri_transform(quad_transform, vec3(0.0f, 1.0f, 0.0f), mat4(1.0f), vec3(0.5f, 0.5f, 0.5f));

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " transform matrix calculation done ... " << endl;
#endif

	Renderer tri_renderer(tri_mesh, material, tri_transform);
	Renderer quad_renderer(quad_mesh, material, quad_transform);

#ifdef DEBUG
	cout << '[' << __FUNCTION__ << ']' << " renderer configuration done ... " << endl;
#endif

	while (!window.Closed()) {
		tri_renderer.Render();
		quad_renderer.Render();

		window.SwapBuffers();
		glfwPollEvents();
	}

	return 0;
}