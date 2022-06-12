#pragma once
#include "opengl.h"

class IndexBuffer {
private:
	unsigned int m_bufferID;
	unsigned int m_count;

public:
	IndexBuffer(const unsigned int* indeces, unsigned int index_count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetBufferID() { return m_bufferID; }
	inline unsigned int GetCount() const { return m_count; }
};