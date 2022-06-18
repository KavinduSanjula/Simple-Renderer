#include "core/Window.h"
#include "core/Renderer.h"

#include "test framework/Test.h"
#include "test framework/tests/BatchRenderer.h"

int main() {

	Window window("Simple Renderer", 800, 600);
	if (!window.isSucsess())
		return -1;

	Renderer renderer;

	test::TestMenu* testMenu = new test::TestMenu();
	testMenu->RegisterTest<test::BatchRenderer>("Batch Renderer");

	test::Test* currentTest = new test::BatchRenderer(); //testMenu;

	currentTest->Start();

	while (!window.ShouldClose()) {
		renderer.Clear();

		window.ImGuiNewFrame();

		if (currentTest) {
			currentTest->Update();
			currentTest->OnImGuiRender();
			ImGui::Begin("Menu");
			if (ImGui::Button("<-")) {
#if 0
				delete currentTest;
				currentTest = nullptr;
				testMenu->SetCurrentTestToNull();
#endif
			}
			ImGui::End();
		}
		else {
			testMenu->Update();
			testMenu->OnImGuiRender();
		}

		//currentTest = testMenu->GetCurretnTest();
		
		window.ImGuiRender();

		

		window.SwapBuffers();
		window.PollEvents();
	}

	delete testMenu;
}