#pragma once
#include "opengl.h"

#include "../util/VertexBufferLayout.h"

class VertexBuffer {
private:
	unsigned int m_bufferID;

public:
	VertexBuffer(const void* data, unsigned int size, VertexBufferLayout layout);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetBufferID() const { return m_bufferID; }
};