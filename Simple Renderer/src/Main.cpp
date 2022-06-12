#include "core/opengl.h"
#include "core/VertexBuffer.h"
#include "core/IndexBuffer.h"
#include "core/Shader.h"
#include "core/Texture.h"
#include "core/Renderer.h"


#include <iostream>

int main() {
	GLFWwindow* window;
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(800, 800, "Simple Renderer", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewInit();
	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;

	{
		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f,
			 0.5f, -0.5f, 1.0f, 0.0f,
			 0.5f,  0.5f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 1.0f
		};

	
		unsigned int indeces[] = { 
			0,1,2,
			2,3,0
		};

		Renderer renderer;

		Shader shader("res/basic.vert", "res/basic.frag");
		VertexBuffer vb(vertices, 16 * sizeof(float));
		IndexBuffer ib(indeces, 6);
		Texture tex("res/images/gravel.jpg");

		tex.Bind(0);
		shader.SetUniform1i("u_Texture", 0);
		//shader.SetUniform4f("color", 1.0f, 0.0f, 0.0f, 1.0f);

		while (!glfwWindowShouldClose(window)) {

			renderer.Clear();
			renderer.Draw(vb, ib, shader);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}