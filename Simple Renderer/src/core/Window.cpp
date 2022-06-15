#include "Window.h"

Window::Window(const std::string& title, int width, int height)
	:m_Width(width), m_Height(height), m_Title(title), m_Sucsess(true)
{
	if (!glfwInit())
	{
		m_Sucsess = false;
		return;
	}

	m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (!m_Window) {
		m_Sucsess = false;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(m_Window);
	glewInit();

	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");

}

Window::~Window()
{
	glfwTerminate();
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

bool Window::ShouldClose() const
{
	return glfwWindowShouldClose(m_Window);
}

void Window::SwapBuffers() const
{
	glfwSwapBuffers(m_Window);
}

void Window::PollEvents() const
{
	glfwPollEvents();
}

void Window::ImGuiNewFrame() const
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Window::ImGuiRender() const
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
