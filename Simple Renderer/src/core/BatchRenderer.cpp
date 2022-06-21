#include "BatchRenderer.h"



BatchRenderer::BatchRenderer()
	:m_RecevedVertexCount(0),m_IndexToDraw(0), m_TextureID(1)
{
	m_Shader = std::make_unique<Shader>("res/basic.vert", "res/basic.frag");
	m_VB = std::make_unique<VertexBuffer>(nullptr, MAX_QUAD_OUNT * 4 * sizeof(Vertex), GL_DYNAMIC_DRAW);
	m_VA = std::make_unique<VertexArray>();
	m_IB = std::make_unique<IndexBuffer>(nullptr,MAX_QUAD_OUNT * 6 * sizeof(unsigned int));
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
	m_TextureID = 1;
	m_Quads.clear();
	m_TexIDs.clear();

	m_Textures.clear();

	Texture white_texture("res/images/white.jpg");
	white_texture.Bind(0);

	m_Textures["res/images/white.jpg"] = 0;

	m_TexIDs.push_back(0);

}

void BatchRenderer::Flush()
{
	Renderer renderer;
	
	m_IB->SetData(m_Indeces, sizeof(m_Indeces), m_IndexToDraw);

	BindTextures();

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
	
	if (m_RecevedVertexCount/4 > MAX_QUAD_OUNT) {
		Flush();
		BeginBatch();
	}

	if (m_TextureID >= MAX_TEXTURE_COUNT) {
		Flush();
		BeginBatch();
	}

	m_IndexToDraw += 6;
	m_Quads.push_back(quad);

	if (m_Textures.find(quad.GetTexturePath()) == m_Textures.end()) {

		Texture tex(quad.GetTexturePath());
		m_Textures[quad.GetTexturePath()] = m_TextureID;

		m_TexIDs.push_back(m_TextureID);
		quad.SetTextureID((float)m_TextureID);
		m_TextureID++;
	}

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

void BatchRenderer::BindTextures() {
	
	m_Shader->SetUniform1i("u_Texture[0]", 0);
	m_Shader->SetUniform1i("u_Texture[1]", 1);

	for (auto element : m_Textures) {
		Texture tex(element.first);
		tex.Bind(element.second);
	}
}


