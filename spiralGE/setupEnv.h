#pragma once
#include <vector>
#include <array>
#include "window.h"
#include "Graphics.h"
#include "log.h"


namespace sge {
	void setupEnv(void) {
		Window window(800, 600, "spiral engine");
		Graph::Graphics g(window.glfwWin);
		GLuint shadProg = g.OGLCreateShadProg("testVertex.vs", "testFragment.fs");

		GLfloat vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		Graph::OGLObject triangle(vertices,8);
		triangle.shaderProgram = shadProg;
		while (!glfwWindowShouldClose(window.glfwWin)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			g.OGLDrawObject(triangle);
			glfwSwapBuffers(window.glfwWin);
			glfwPollEvents();
		}
	}
}

