#pragma once
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace sge {
	namespace Graph {
		 
		class OGLObject {
			GLuint m_VBO;
		public:
			const unsigned int vertexCount;
			GLuint shaderProgram;
			OGLObject(const GLfloat *data, const unsigned int arrSize);
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
			GLuint OGLCreateShadProg(std::string fragmentLoc, std::string vertLoc);
			void OGLDrawObject(OGLObject &target) const;
			Graphics(GLFWwindow* renderWindow);
			~Graphics();
		};
	}
}


