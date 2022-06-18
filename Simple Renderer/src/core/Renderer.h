#pragma once

#include "opengl.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer {
public:
	Renderer();
	~Renderer();
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	void Clear();
};