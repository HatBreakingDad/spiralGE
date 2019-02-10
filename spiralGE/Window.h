#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
namespace sge {
	class Window
	{
	public:
		GLFWwindow* glfwWin = nullptr;
		Window(unsigned int w, unsigned int h, std::string title);
		~Window();
	};
}

