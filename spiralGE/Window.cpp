#include <string>

#include "Window.h"
#include "log.h"

namespace sge {
	Window::Window(unsigned int w, unsigned int h, std::string title) 
	{
		if (glfwInit()) {
			glfwWin = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
			if (!glfwWin)
				LOG("Failed to create window");
			glfwMakeContextCurrent(glfwWin);
		}
		else LOG("GLFW failed to initialize");
	}

	Window::~Window()
	{
		glfwTerminate();
	}
}

