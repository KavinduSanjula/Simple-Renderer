#pragma once
#include <GL/glew.h>
#include <vector>

struct VertexBufferLayoutElement {
	unsigned int type;
	unsigned int count;
	unsigned int normalized;
	unsigned int size;
};

class VertexBufferLayout
{
private:
	unsigned int m_Stride;
	std::vector<VertexBufferLayoutElement> m_Elements;

public:
	VertexBufferLayout();
	~VertexBufferLayout();

	inline std::vector<VertexBufferLayoutElement> GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride; }

	template<typename T>
	void Push(unsigned int count);

	template<>
	void Push<float>(unsigned int count);

};

