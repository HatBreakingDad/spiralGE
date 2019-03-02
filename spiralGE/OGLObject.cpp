#include "OGLobject.h"
#include "log.h"
namespace sge {
	namespace Graph {
		OGLObject::OGLObject(const GLfloat *vertices, const GLint *indic, const unsigned int arrSize, GLuint *shader) 
			: vertexCount(arrSize), indices(*indic), shaderProgram(*shader)
		{
			glGenBuffers(1, &m_VBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertexCount, vertices, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); 
			glEnableVertexAttribArray(0);
			if (indices) {
				glGenBuffers(1, &m_EBO);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);
			}
		}
		OGLObject::~OGLObject()
		{
		}
	}
}
