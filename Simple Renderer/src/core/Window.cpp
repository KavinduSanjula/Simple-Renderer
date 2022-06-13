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
}

Window::~Window()
{
	glfwTerminate();
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
