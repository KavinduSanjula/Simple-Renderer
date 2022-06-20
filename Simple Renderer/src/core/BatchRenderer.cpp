#include "BatchRenderer.h"


BatchRenderer::BatchRenderer()
	:m_RecevedVertexCount(0),m_IndexToDraw(0)
{
	m_Shader = std::make_unique<Shader>("res/basic.vert", "res/basic.frag");
	m_VB = std::make_unique<VertexBuffer>(nullptr, MAX_VERTEX_COUNT * sizeof(Vertex), GL_DYNAMIC_DRAW);
	m_VA = std::make_unique<VertexArray>();
	m_VA->AddBuffer(*m_VB, Vertex::GetLayout());

	GenerateIndeces();
	BeginBatch();
}

BatchRenderer::~BatchRenderer()
{
	
}

void BatchRenderer::BeginBatch()
{
	m_RecevedVertexCount = 0;
	m_IndexToDraw = 0;
	m_Quads.clear();

}

void BatchRenderer::Flush()
{
	Renderer renderer;
	m_IB = std::make_unique<IndexBuffer>(m_Indeces, m_IndexToDraw);

	for (unsigned int i = 0; i < m_Quads.size(); i++) {
		Quad quad = m_Quads[i];

		auto vertices = quad.GetVertices();
		memcpy(m_Buffer + i, vertices.data(), 4 * sizeof(Vertex));
	}

	m_VB->SetData(m_Buffer, sizeof(m_Buffer));

	renderer.Draw(*m_VA, *m_IB, *m_Shader);
}

void BatchRenderer::Push(const Quad& quad)
{
	m_RecevedVertexCount += 4;
	
	if (m_RecevedVertexCount > MAX_VERTEX_COUNT) {
		Flush();
		BeginBatch();
	}
	m_IndexToDraw += 6;
	m_Quads.push_back(quad);

}

void BatchRenderer::GenerateIndeces()
{
	m_Indeces[0] = 0;
	m_Indeces[1] = 1;
	m_Indeces[2] = 2;
	m_Indeces[3] = 2;
	m_Indeces[4] = 3;
	m_Indeces[5] = 0;
}


