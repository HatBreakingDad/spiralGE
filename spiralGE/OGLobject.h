#pragma once
#include <glad/glad.h>
namespace sge {
	namespace Graph {
		class OGLObject {
			GLuint m_VBO, m_EBO;
		public:
			const GLint indices;
			const unsigned int vertexCount;
			GLuint &shaderProgram;
			OGLObject(const GLfloat *vertices, const GLint *indic, const unsigned int arrSize, GLuint *shader);
			~OGLObject();
		};
	}
}
