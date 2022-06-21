#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int size,unsigned int count, unsigned int mode)
	:m_count(count)
{
	GLCALL(glGenBuffers(1, &m_bufferID));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID));
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, mode));
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

void IndexBuffer::SetData(const void* data, unsigned int size, unsigned int index_count)
{
	m_count = index_count;
	GLCALL(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, data));
}
