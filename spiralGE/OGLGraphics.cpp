#include <vector>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "OGLGraphics.h"
#include "log.h"
namespace sge {
	namespace Graph {
		OGLGraphics::OGLGraphics(GLFWwindow* renderWindow) : m_win(renderWindow)
		{
			//the constructor sets up the environment for 3d rendering in the
			// selected renderer
			if (!glfwInit()) {
				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			}
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
				LOG("GLAD failed to initialize");
			else
				LOG("GLAD has successfully initialized");

		}
		OGLGraphics::~OGLGraphics()
		{
		}
		void OGLGraphics::OGLDrawObject(OGLObject &target) const // Temporary for now until batch rendering is implemented.
		{
			glUseProgram(target.shaderProgram);
			if (target.indices) 
				glDrawElements(GL_TRIANGLES, 0, GL_FLOAT, &target.indices);
			else 
				glDrawArrays(GL_TRIANGLES, 0, target.vertexCount / 3);
		}
	}
}