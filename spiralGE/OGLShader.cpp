#include "OGLShader.h"


namespace sge {
	namespace Graph {
		void OGLShader::setMat4(const char *attributeName, glm::mat4 value)
		{
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram, attributeName),1,GL_FALSE,glm::value_ptr(value));
		}
		OGLShader::OGLShader(std::string vertexPath,std::string fragmentPath)
		{
			//Reads two plaintext files and converts them into a openGL shaders
			std::ifstream fragShaderFile, vertShaderFile;
			std::stringstream shadCodeStream;
			try {
				//Vertex shader loading and compilation
				vertShaderFile.open(vertexPath, std::ifstream::out);
				vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
				std::string szShaderCode;
				shadCodeStream << vertShaderFile.rdbuf();
				szShaderCode = shadCodeStream.str();
				const char* vertShaderCode = szShaderCode.c_str();
				vertShaderFile.close();
				GLint compileCorrectly;
				GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
				glShaderSource(vertexShader, 1, &vertShaderCode, NULL);
				glCompileShader(vertexShader);
				glGetShaderiv(GL_VERTEX_SHADER, GL_COMPILE_STATUS, &compileCorrectly);
				if (!compileCorrectly) {
					LOG("Vertex shader compilation failed with the following error:");
					char compileLog[512];
					glGetShaderInfoLog(vertexShader, sizeof(compileLog), NULL, compileLog);
					LOG(compileLog);
				}

				//Fragment shader loading and compilation
				fragShaderFile.open(fragmentPath, std::ifstream::out);
				fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
				shadCodeStream.str("");
				shadCodeStream << fragShaderFile.rdbuf();
				szShaderCode = shadCodeStream.str();
				const char* fragShaderCode = szShaderCode.c_str();
				fragShaderFile.close();
				GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
				glShaderSource(fragmentShader, 1, &fragShaderCode,NULL);
				glCompileShader(fragmentShader);

				glGetShaderiv(GL_FRAGMENT_SHADER, GL_COMPILE_STATUS, &compileCorrectly);
				if (!compileCorrectly) {
					LOG("Fragment shader compilation failed with the following error:");
					char compileLog[512];
					glGetShaderInfoLog(fragmentShader, sizeof(compileLog), NULL, compileLog);
					LOG(compileLog);
				}
				//Shader program compilation and linking
				shaderProgram = glCreateProgram();
				glAttachShader(shaderProgram, fragmentShader);
				glAttachShader(shaderProgram, vertexShader);
				glLinkProgram(shaderProgram);
				GLint success;
				glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
				if (!success) {
					LOG("Shader program linking failing with the following error:");
					char compileLog[512];
					glGetProgramInfoLog(shaderProgram, 512, NULL, compileLog);
					LOG(compileLog);
				}
				glDeleteShader(vertexShader);
				glDeleteShader(fragmentShader);
			}
			catch (const std::ifstream::failure e) {
				LOG("Exception thrown for opening/reading file(s).");
				shaderProgram = NULL;
			}
		}
		OGLShader::~OGLShader()
		{
		}
	}
}
