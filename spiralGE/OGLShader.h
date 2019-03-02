#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "log.h"
namespace sge {
	namespace Graph {
		class OGLShader
		{
		public:
			GLuint shaderProgram;
			void setUniformMat4(const char *attributeLocation, glm::mat4 value);
			OGLShader(std::string fragmentPath, std::string vertexPath);
			~OGLShader();
		};
	}
}


