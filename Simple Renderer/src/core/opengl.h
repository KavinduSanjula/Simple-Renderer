#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#define ASSERT(x) if(!(x)) __debugbreak()
#define GLCALL(x) GL_ClearError(); x; ASSERT(GL_GetError())

void GL_ClearError();
bool GL_GetError();

