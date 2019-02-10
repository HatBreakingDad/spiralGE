#include <string>

#include "Window.h"
#include "log.h"

namespace sge {
	Window::Window(unsigned int w, unsigned int h, std::string title) 
	{
		if (glfwInit()) {
			glfwWin = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(glfwWin);
		}
		else LOG("Window failed to initialize");
	}

	Window::~Window()
	{
		glfwTerminate();
	}
}

