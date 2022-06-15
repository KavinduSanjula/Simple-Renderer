#include "ClearColor.h"

#include <iostream>

namespace test {

	void ClearColor::Start()
	{
		std::cout << "ClearColor test started" << std::endl;
	}

	void ClearColor::Update()
	{
		GLCALL(glClearColor(m_Color[0], m_Color[1], m_Color[2], m_Color[3]));
	}

	void ClearColor::OnImGuiRender()
	{
		ImGui::Begin("Clear Color");
		ImGui::ColorEdit3("Clear Color", m_Color);
		ImGui::End();
	}

}