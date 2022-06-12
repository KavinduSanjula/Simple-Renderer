#pragma once
#include "opengl.h"

class VertexBuffer {
private:
	unsigned int m_bufferID;

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetBufferID() const { return m_bufferID; }
};