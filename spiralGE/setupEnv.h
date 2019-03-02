#pragma once
#include <vector>
#include <array>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec3.hpp>

#include "window.h"
#include "OGLGraphics.h"
#include "log.h"
#include "modelLoader.h"

namespace sge {
	void setupEnv(void) {
		Window window(800, 600, "spiral engine");
		Graph::OGLGraphics g(window.glfwWin);
		Graph::OGLShader quickShader("res/shaders/basicCamera.vert","res/shaders/testFragment.frag");
		const Graph::BasicModel smileyFaceModel = Utility::createModelFromFile("res/models/teapot.obj");
		
		Graph::OGLObject smileyFace(smileyFaceModel.meshes[0].vertices.data(), 
			smileyFaceModel.meshes[0].indices.data(), smileyFaceModel.meshes[0].vertices.size(),&quickShader.shaderProgram);
		glm::vec3 forwardPosition = glm::vec3(1);
		glm::mat4 transformEdit = glm::mat4(1.0f);
		while (!glfwWindowShouldClose(window.glfwWin)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			g.OGLDrawObject(smileyFace);
			if (glfwGetKey(window.glfwWin, GLFW_KEY_UP)) {
				forwardPosition.z += 0.1;
				transformEdit = glm::translate(transformEdit, forwardPosition);
				quickShader.setMat4("model", transformEdit);
			}
			glfwSwapBuffers(window.glfwWin);
			glfwPollEvents();
		}
	}
}

