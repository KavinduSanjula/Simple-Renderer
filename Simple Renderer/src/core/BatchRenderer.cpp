#include "BatchRenderer.h"


BatchRenderer::BatchRenderer()
	:m_RecevedVertexCount(0),m_IndexToDraw(0), m_TextureID(0)
{
	m_Shader = std::make_unique<Shader>("res/basic.vert", "res/basic.frag");
	m_VB = std::make_unique<VertexBuffer>(nullptr, MAX_QUAD_OUNT * 4 * sizeof(Vertex), GL_DYNAMIC_DRAW);
	m_VA = std::make_unique<VertexArray>();
	m_IB = std::make_unique<IndexBuffer>(nullptr,MAX_QUAD_OUNT * 6 * sizeof(unsigned int));
	m_VA->AddBuffer(*m_VB, Vertex::GetLayout());

	int textures[5] = { 0,1,2,3,4 };
	m_Shader->SetUniformArrayi("u_Texture", 5, textures);

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
	m_TextureID = 0;
	m_Quads.clear();

}

void BatchRenderer::Flush()
{
	Renderer renderer;
	
	m_IB->SetData(m_Indeces, sizeof(m_Indeces), m_IndexToDraw);

	memset(m_Buffer, 0, MAX_QUAD_OUNT * 4 * sizeof(Vertex));

	int offset = 0;
	for (auto quad : m_Quads) {
		auto vertices = quad.GetVertices();
		memcpy(m_Buffer + offset, vertices.data(), 4 * sizeof(Vertex));
		offset += 4;
	}

	m_VB->SetData(m_Buffer, sizeof(m_Buffer));


	renderer.Draw(*m_VA, *m_IB, *m_Shader);
}

void BatchRenderer::Push(Quad& quad)
{
	m_RecevedVertexCount += 4;
	
	if (m_RecevedVertexCount / 4 > MAX_QUAD_OUNT) {
		Flush();
		BeginBatch();
	}

	if (m_TextureID < MAX_TEXTURE_COUNT) {
		std::string tex_path = quad.GetTexturePath();
		Texture tex(tex_path);
		quad.SetTextureID((float)m_TextureID);
		PushTexture(tex);
	}


	m_IndexToDraw += 6;
	m_Quads.push_back(quad);

}

int BatchRenderer::PushTexture(const Texture& texture)
{
	texture.Bind(m_TextureID);
	return m_TextureID++;
}

void BatchRenderer::GenerateIndeces()
{
	int ptr = 0;
	for (int i = 0; i < MAX_QUAD_OUNT; i++) {
		m_Indeces[ptr++] = 0 + (i * 4);
		m_Indeces[ptr++] = 1 + (i * 4);
		m_Indeces[ptr++] = 2 + (i * 4);
		m_Indeces[ptr++] = 2 + (i * 4);
		m_Indeces[ptr++] = 3 + (i * 4);
		m_Indeces[ptr++] = 0 + (i * 4);
	}
}


