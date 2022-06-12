#include "opengl.h"
#include <iostream>

void GL_ClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GL_GetError() {
	while (GLenum err = glGetError()) {
		std::cout << "OpenGL Error: " << err << std::endl;
		return false;
	}
	return true;
}