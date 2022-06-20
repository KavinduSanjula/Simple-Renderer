#pragma once

#include "core/Quad.h"
#include "core/VertexBuffer.h"
#include "core/VertexArray.h"
#include "core/IndexBuffer.h"
#include "core/Shader.h"
#include "core/Renderer.h"

#include <vector>
#include <memory>

#define MAX_VERTEX_COUNT 4

class BatchRenderer {
private:
	std::vector<Quad> m_Quads;

	int m_RecevedVertexCount;
	int m_IndexToDraw;
	unsigned int m_Indeces[6];

	std::unique_ptr<VertexBuffer> m_VB;
	std::unique_ptr<VertexArray> m_VA;
	std::unique_ptr<IndexBuffer> m_IB;
	std::unique_ptr<Shader> m_Shader;

	Vertex m_Buffer[MAX_VERTEX_COUNT];

public:
	BatchRenderer();
	~BatchRenderer();

	void BeginBatch();
	void Flush();

	void Push(const Quad& quad);

private:
	void GenerateIndeces();
};