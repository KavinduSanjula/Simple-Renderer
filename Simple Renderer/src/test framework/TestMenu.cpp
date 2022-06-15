#include "core/opengl.h"
#include "test framework/Test.h"
#include "imgui/imgui.h"

namespace test {

	void TestMenu::Start()
	{

	}

	void TestMenu::Update()
	{
		GLCALL(glClearColor(0.f,0.f,0.f,1.f));
	}

	void TestMenu::OnImGuiRender()
	{
		ImGui::Begin("Main Menu");

		for (auto scene : m_Tests) {

			auto name = scene.first;
			auto func = scene.second;

			if (ImGui::Button(name.c_str())) {
				m_CurretnTest = func();
			}
		}

		ImGui::End();

	}

}
