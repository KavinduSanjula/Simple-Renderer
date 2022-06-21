#pragma once
#include "opengl.h"

class IndexBuffer {
private:
	unsigned int m_bufferID;
	unsigned int m_count;

public:
	IndexBuffer(const unsigned int* indeces, unsigned int size, unsigned int count=0, unsigned int mode=GL_DYNAMIC_DRAW);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	void SetData(const void* data, unsigned int size, unsigned int index_count);

	inline unsigned int GetBufferID() { return m_bufferID; }
	inline unsigned int GetCount() const { return m_count; }
};