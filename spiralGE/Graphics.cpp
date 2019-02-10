#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Graphics.h"
#include "log.h"
namespace sge {
	namespace graph {
		Graphics::Graphics(GLFWwindow* renderWindow) : m_win(renderWindow)
		{
			//the constructor sets up the environment for 3d rendering in the
			// selected renderer
			switch (selectedRendr) {
			case openGL:
				LOG("Using opengl");
				if (!glfwInit()) {
					glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
					glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
					glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
				}
				if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
					LOG("GLAD failed to initialize");
				else
					LOG("GLAD has successfully initialized");
				break;
			case otherOptionTest:
				LOG("Using a test for this system");
				break;
			default:
				LOG("unknown 3d api");
				break;
			}
		}
		Graphics::~Graphics()
		{
		}

		OGLObject::OGLObject(const float data[])
		{	
			GLuint VBO;
			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(data),data, GL_STATIC_DRAW);
			LOG(glGetError());
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
		}
		OGLObject::~OGLObject()
		{
		}
		void Graphics::OGLDrawObject(OGLObject &target) const
		{
			glUseProgram(target.shaderProgram);
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		GLuint Graphics::OGLCreateShadProgFromFiles(std::string vertexLoc, std::string fragmentLoc)
		{
			//Reads two plaintext files and converts them into a openGL shaders
			std::ifstream fragShaderFile, vertShaderFile;
			std::stringstream shadCodeStream;
			try {
				//Fragment shader loading and compilation
				fragShaderFile.open(fragmentLoc, std::ifstream::out);
				fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

				std::string szShaderCode;
				shadCodeStream << fragShaderFile.rdbuf();
				szShaderCode = shadCodeStream.str();
				const char* fragShaderCode = szShaderCode.c_str();
				fragShaderFile.close();

				GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
				glShaderSource(fragmentShader, 1, &fragShaderCode, nullptr);
				glCompileShader(fragmentShader);
				GLint compileCorrectly;
				glGetShaderiv(GL_FRAGMENT_SHADER, GL_COMPILE_STATUS, &compileCorrectly);
				if (!compileCorrectly) {
					LOG("Fragment shader compilation failed with the following error:");
					char compileLog[512];
					glGetShaderInfoLog(fragmentShader, sizeof(compileLog), NULL,compileLog);
					LOG(compileLog);
				}
				//Vertex shader loading and compilation
				vertShaderFile.open(vertexLoc, std::ifstream::out);
				vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

				shadCodeStream.str("");
				shadCodeStream << vertShaderFile.rdbuf();
				szShaderCode = shadCodeStream.str();
				const char* vertShaderCode = szShaderCode.c_str();
				vertShaderFile.close();
				GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
				glShaderSource(vertexShader, 1, &vertShaderCode, nullptr);
				glCompileShader(vertexShader);
				glGetShaderiv(GL_VERTEX_SHADER, GL_COMPILE_STATUS, &compileCorrectly);
				if (!compileCorrectly) {
					LOG("Vertex shader compilation failed with the following error:");
					char compileLog[512];
					glGetShaderInfoLog(vertexShader, sizeof(compileLog),NULL, compileLog);
					LOG(compileLog);
				}
				//Shader program compilation and linking
				GLuint shaderProgram = glCreateProgram();
				glAttachShader(shaderProgram, fragmentShader);
				glAttachShader(shaderProgram, vertexShader);
				glLinkProgram(shaderProgram);
				glDeleteShader(vertexShader);
				glDeleteShader(fragmentShader);
				return shaderProgram;
			}
			catch (const std::ifstream::failure e) {
				LOG("Exception thrown for opening/reading file(s).");
				return NULL;
			}
		}
	}
}