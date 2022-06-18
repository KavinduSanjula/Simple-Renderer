#pragma once

#include "opengl.h"
#include "VertexBuffer.h"
#include "util/VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_ArrayID;

public: 
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void Bind() const;
	void UnBind() const;
};