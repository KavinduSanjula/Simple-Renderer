#pragma once

#include "core/Quad.h"
#include "core/VertexBuffer.h"
#include "core/VertexArray.h"
#include "core/IndexBuffer.h"
#include "core/Shader.h"
#include "core/Texture.h"
#include "core/Renderer.h"

#include <vector>
#include <memory>

#define MAX_QUAD_OUNT 4


class BatchRenderer {
private:
	std::vector<Quad> m_Quads;

	int m_RecevedVertexCount;
	int m_IndexToDraw;
	unsigned int m_Indeces[MAX_QUAD_OUNT * 6];

	std::unique_ptr<VertexBuffer> m_VB;
	std::unique_ptr<VertexArray> m_VA;
	std::unique_ptr<IndexBuffer> m_IB;
	std::unique_ptr<Shader> m_Shader;

	Vertex m_Buffer[MAX_QUAD_OUNT * 4];


public:
	BatchRenderer();
	~BatchRenderer();

	void BeginBatch();
	void Flush();

	void Push(Quad& quad);

private:
	void GenerateIndeces();
};