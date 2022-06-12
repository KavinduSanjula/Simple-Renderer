#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCALL(glGenBuffers(1, &m_bufferID));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_bufferID));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));

	GLCALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0));
	GLCALL(glEnableVertexAttribArray(0));

	GLCALL(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float))));
	GLCALL(glEnableVertexAttribArray(1));
}

VertexBuffer::~VertexBuffer()
{
	GLCALL(glDeleteBuffers(1, &m_bufferID));
}

void VertexBuffer::Bind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_bufferID));
}

void VertexBuffer::Unbind() const
{
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
