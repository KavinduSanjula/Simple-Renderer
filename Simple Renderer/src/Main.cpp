#include "core/Window.h"

int main() {
	Window window("Simple Renderer", 800, 600);
	if (!window.isSucsess())
		return -1;

	while (!window.ShouldClose()) {
		window.SwapBuffers();
		window.PollEvents();
	}
}