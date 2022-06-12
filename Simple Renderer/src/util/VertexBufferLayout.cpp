#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout()
	:m_Stride(0)
{
}

VertexBufferLayout::~VertexBufferLayout()
{
}

template<typename T>
void VertexBufferLayout::Push(unsigned int count) {
	static_assert(false);
}

template<>
void VertexBufferLayout::Push<float>(unsigned int count) {
	VertexBufferLayoutElement element({ GL_FLOAT, count, GL_FALSE, sizeof(float) });
	m_Elements.push_back(element);
	m_Stride += count * sizeof(float);
}
