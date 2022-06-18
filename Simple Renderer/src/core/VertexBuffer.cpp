#include "VertexBuffer.h"


VertexBuffer::VertexBuffer(const void* data, unsigned int size, unsigned int mode, VertexBufferLayout layout)
{
	GLCALL(glGenBuffers(1, &m_bufferID));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_bufferID));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, mode));

	int offset = 0;
	auto elements = layout.GetElements();
	for (unsigned int i = 0; i < elements.size(); i++) {
		auto& element = elements[i];

		GLCALL(glEnableVertexAttribArray(i));
		GLCALL(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (void*)(offset * element.size)));
		offset += element.count;
	}
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

void VertexBuffer::SetData(const void* data)
{
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);
}
