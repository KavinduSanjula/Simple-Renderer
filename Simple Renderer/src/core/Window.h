#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

class Window
{
private:
	GLFWwindow* m_Window;
	int m_Width;
	int m_Height;
	std::string m_Title;
	bool m_Sucsess;

public:
	Window(const std::string& title, int width, int height);
	~Window();

	bool ShouldClose() const;
	void SwapBuffers() const;
	void PollEvents() const;

	void ImGuiNewFrame() const;
	void ImGuiRender() const;

	inline GLFWwindow* GetWindow() { return m_Window; }
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline bool isSucsess() const { return m_Sucsess; }
};

