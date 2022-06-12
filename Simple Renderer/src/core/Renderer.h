#pragma once

#include "opengl.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer {
public:
	Renderer();
	~Renderer();
	void Draw(VertexBuffer& vb, IndexBuffer& ib, Shader& shader);
	void Clear();
};