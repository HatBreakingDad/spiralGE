#pragma once
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace sge {
	namespace graph {
		class OGLObject {
		public:
			GLuint shaderProgram;
			OGLObject(const float data[]);
			~OGLObject();
		};
		class Graphics
		{
			GLFWwindow *m_win = nullptr;
		public:
			enum renderers {
				openGL,
				otherOptionTest
			};
			constexpr static const int selectedRendr = openGL;
			GLuint OGLCreateShadProgFromFiles(std::string fragmentLoc, std::string vertLoc);
			void OGLDrawObject(OGLObject &target) const;
			Graphics(GLFWwindow* renderWindow);
			~Graphics();
		};
	}
}


