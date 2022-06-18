#include "VertexArray.h"


VertexArray::VertexArray()
{
	GLCALL(glGenVertexArrays(1, &m_ArrayID));
}

VertexArray::~VertexArray()
{
	GLCALL(glDeleteVertexArrays(1, &m_ArrayID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();

	int offset = 0;
	auto elements = layout.GetElements();
	for (unsigned int i = 0; i < elements.size(); i++) {
		auto& element = elements[i];

		GLCALL(glEnableVertexAttribArray(i));
		GLCALL(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (void*)(offset * element.size)));
		offset += element.count;
	}

	UnBind();
}

void VertexArray::Bind() const
{
	GLCALL(glBindVertexArray(m_ArrayID));
}

void VertexArray::UnBind() const
{
	GLCALL(glBindVertexArray(0));
}

