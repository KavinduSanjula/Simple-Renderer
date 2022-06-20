#include "Renderer.h"

#include <iostream>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	std::cout << "[Draw Call]" << std::endl;
	va.Bind();
	ib.Bind();
	shader.Bind();

	GLCALL(glDrawElements(GL_TRIANGLES,ib.GetCount(),GL_UNSIGNED_INT,nullptr));
}

void Renderer::Clear()
{
	GLCALL(glClear(GL_COLOR_BUFFER_BIT));
}
