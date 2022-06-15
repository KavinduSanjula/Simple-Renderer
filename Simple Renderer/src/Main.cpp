#include "core/Window.h"
#include "core/Renderer.h"

#include "test framework/Test.h"
#include "test framework/tests/ClearColor.h"

int main() {

	Window window("Simple Renderer", 800, 600);
	if (!window.isSucsess())
		return -1;

	Renderer renderer;

	test::TestMenu* testMenu = new test::TestMenu();
	testMenu->RegisterTest<test::ClearColor>("Clear Color");

	test::Test* currentTest = testMenu;//new test::ClearColor();

	currentTest->Start();

	while (!window.ShouldClose()) {
		renderer.Clear();

		window.ImGuiNewFrame();
		
		currentTest = testMenu->GetCurretnTest();

		if (currentTest) {
			currentTest->Update();
			currentTest->OnImGuiRender();
			ImGui::Begin("Menu");
			if (ImGui::Button("<-")) {
				delete currentTest;
				currentTest = nullptr;
				testMenu->SetCurrentTestToNull();
			}
			ImGui::End();
		}
		else {
			testMenu->Update();
			testMenu->OnImGuiRender();
		}
		
		window.ImGuiRender();

		

		window.SwapBuffers();
		window.PollEvents();
	}

	delete testMenu;
}