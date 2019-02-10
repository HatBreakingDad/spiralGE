#pragma once
#include <array>
#include "window.h"
#include "Graphics.h"
namespace sge {
	void setupEnv(void) {
		Window window(800, 600, "spiral engine");
		graph::Graphics g(window.glfwWin);
		GLuint shader = g.OGLCreateShadProgFromFiles("testVertex.vs", "testFragment.fs");
		
		const float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		graph::OGLObject triangle(vertices);
		triangle.shaderProgram = shader;
		while (!glfwWindowShouldClose(window.glfwWin)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.5, 0.5, 0.5, 1);
			g.OGLDrawObject(triangle);
			glfwSwapBuffers(window.glfwWin);
			glfwPollEvents();
		}
	}
}

