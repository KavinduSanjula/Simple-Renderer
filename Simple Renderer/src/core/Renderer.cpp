#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Draw(VertexBuffer& vb, IndexBuffer& ib, Shader& shader)
{
	shader.Bind();
	vb.Bind();
	ib.Bind();

	GLCALL(glDrawElements(GL_TRIANGLES,ib.GetCount(),GL_UNSIGNED_INT,nullptr));
}

void Renderer::Clear()
{
	GLCALL(glClear(GL_COLOR_BUFFER_BIT));
}
