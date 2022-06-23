#pragma once

#include "core/Quad.h"
#include "core/VertexBuffer.h"
#include "core/VertexArray.h"
#include "core/IndexBuffer.h"
#include "core/Shader.h"
#include "core/Texture.h"
#include "core/Renderer.h"

#include <string>
#include <vector>
#include <memory>
#include <array>

#define MAX_QUAD_OUNT 1000
#define MAX_TEXTURE_COUNT 5

class BatchRenderer {
private:
	std::vector<Quad> m_Quads;

	int m_RecevedVertexCount;
	int m_IndexToDraw;
	int m_TextureID;
	std::array<unsigned int, MAX_TEXTURE_COUNT> m_TextureMap;
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
	int PushTexture(const Texture& texture);
	void GenerateIndeces();
};