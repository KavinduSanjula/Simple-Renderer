#include "VertexBuffer.h"



VertexBuffer::VertexBuffer(const void* data, unsigned int size, VertexBufferLayout layout)
{
	GLCALL(glGenBuffers(1, &m_bufferID));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_bufferID));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));

	int offset = 0;
	auto elements = layout.GetElements();
	for (unsigned int i = 0; i < elements.size(); i++) {
		auto& element = elements[i];

		GLCALL(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (void*)(offset * element.size)));
		GLCALL(glEnableVertexAttribArray(i));
		offset += element.count;
	}
	/*
	GLCALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0));
	GLCALL(glEnableVertexAttribArray(0));

	GLCALL(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float))));
	GLCALL(glEnableVertexAttribArray(1));
	*/
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
