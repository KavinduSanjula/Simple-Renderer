#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int index_count)
	:m_count(index_count)
{
	GLCALL(glGenBuffers(1, &m_bufferID));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID));
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCALL(glDeleteBuffers(1, &m_bufferID));
}

void IndexBuffer::Bind() const
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID));
}

void IndexBuffer::Unbind() const
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
