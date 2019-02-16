#pragma once
#include <vector>
#include <array>

#include "window.h"
#include "Graphics.h"
#include "log.h"
#include "objParser.h"

namespace sge {
	void setupEnv(void) {
		Window window(800, 600, "spiral engine");
		Graph::Graphics g(window.glfwWin);
		GLuint shadProg = g.OGLCreateShadProg("testVertex.vs", "testFragment.fs");

		//GLfloat vertices[] = Utility::OGLCreateObjFromFile("teapot.obj");
		//Graph::OGLObject triangle(0.1, 3);
		//triangle.shaderProgram = shadProg;
		int yes = Utility::OGLCreateObjFromFile("teapot.obj");
		while (!glfwWindowShouldClose(window.glfwWin)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//g.OGLDrawObject(triangle);
			glfwSwapBuffers(window.glfwWin);
			glfwPollEvents();
		}
	}
}

