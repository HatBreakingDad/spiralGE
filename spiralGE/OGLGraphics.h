#pragma once
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OGLObject.h"
#include "OGLShader.h"
namespace sge {
	namespace Graph {
		class OGLGraphics
		{
			GLFWwindow *m_win = nullptr;
		public:
			void OGLDrawObject(OGLObject &target) const;
			OGLGraphics(GLFWwindow* renderWindow);
			~OGLGraphics();
		};
	}
}


