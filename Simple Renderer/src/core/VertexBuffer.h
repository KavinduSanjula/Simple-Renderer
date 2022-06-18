#pragma once
#include "opengl.h"

#include "../util/VertexBufferLayout.h"

class VertexBuffer {
private:
	unsigned int m_bufferID;

public:
	VertexBuffer(const void* data, unsigned int size, unsigned int mode);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

	void SetData(const void* data, unsigned int size);

	inline unsigned int GetBufferID() const { return m_bufferID; }

};