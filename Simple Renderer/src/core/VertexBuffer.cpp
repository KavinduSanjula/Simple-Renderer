#include "VertexBuffer.h"


VertexBuffer::VertexBuffer(const void* data, unsigned int size, unsigned int mode)
{
	GLCALL(glGenBuffers(1, &m_bufferID));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_bufferID));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, mode));
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

void VertexBuffer::SetData(const void* data, unsigned int size)
{
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}
