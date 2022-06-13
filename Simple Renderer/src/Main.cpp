#include "core/opengl.h"
#include "core/VertexBuffer.h"
#include "core/IndexBuffer.h"
#include "core/Shader.h"
#include "core/Texture.h"
#include "core/Renderer.h"

#include "util/VertexBufferLayout.h"

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

int main() {
	GLFWwindow* window;
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(800, 600, "Simple Renderer", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewInit();

	

	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;

	{
		float vertices[] = {
			  0.0f,   0.0f, 0.0f, 0.0f, 
			200.0f,   0.0f, 1.0f, 0.0f, 
			200.0f, 200.0f, 1.0f, 1.0f, 
			  0.0f, 200.0f, 0.0f, 1.0f 
		};

	
		unsigned int indeces[] = { 
			0,1,2,
			2,3,0
		};

		Renderer renderer;

		Shader shader("res/basic.vert", "res/basic.frag");

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);

		VertexBuffer vb(vertices, 6 * 4 * sizeof(float), layout);
		IndexBuffer ib(indeces, 6);
		Texture tex("res/images/sanju.jpg");

		glm::mat4 proj = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
		

		tex.Bind(0);
		
		shader.SetUniform1i("u_Texture", 0);
		//shader.SetUniform4f("color", 1.0f, 0.0f, 0.0f, 1.0f);

		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 330 core");

		glm::vec3 translation(0);
		while (!glfwWindowShouldClose(window)) {

			renderer.Clear();

			
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);

			glm::mat4 mvp = proj * view * model;

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			ImGui::Begin("Hello, world!");
			ImGui::Text("Hello, World!");
			ImGui::SliderFloat3("Translation",&translation.x, 0.0f, 700.0f);
			ImGui::End();

			shader.Bind();
			shader.SetUniformMat4f("u_Projection", mvp);
			renderer.Draw(vb, ib, shader);

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}