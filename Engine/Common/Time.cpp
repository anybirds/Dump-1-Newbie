#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Common/Time.hpp>

using namespace Engine;

static Time::Time() {
	m_dt = 0.0f;
	m_prev = 0.0f;
}

Time::Time() {

}

void Time::Tick() {
	double curr = glfwGetTime();
	m_dt = curr - m_prev;
	m_prev = curr;
}
