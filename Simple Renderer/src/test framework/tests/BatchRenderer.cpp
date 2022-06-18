#include "BatchRenderer.h"

#include <iostream>
#include <array>

namespace test {

	std::array<Vertex, 4> MakeQuad(float x, float y,float size, float texID = 0, Vec4 color = { 1,1,1,1 }) {
		//float size = 100.0f;

		Vertex v0;
		v0.Position = { x,y, 0 };
		v0.Color = color;
		v0.TexCoord = { 0,0 };
		v0.TexID = texID;

		Vertex v1;
		v1.Position = { x + size,y, 0 };
		v1.Color = color;
		v1.TexCoord = { 1,0 };
		v1.TexID = texID;

		Vertex v2;
		v2.Position = { x + size,y + size, 0 };
		v2.Color = color;
		v2.TexCoord = { 1,1 };
		v2.TexID = texID;

		Vertex v3;
		v3.Position = { x,y + size, 0 };
		v3.Color = color;
		v3.TexCoord = { 0,1 };
		v3.TexID = texID;

		return std::array<Vertex, 4> {v0, v1, v2, v3};
	}




	BatchRenderer::BatchRenderer()
		:m_ModelTranslation({ 0,0,0 }),
		m_ViewTranslation({0,0,0}),
		m_Proj(glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f)),
		m_View(glm::translate(glm::mat4(1.0f), m_ViewTranslation)),
		m_Model(glm::translate(glm::mat4(1.0f), m_ModelTranslation))
	{

		unsigned int indeces[]{
			0,1,2,2,3,0,
			4,5,6,6,7,4,
			8,9,10,10,11,8
		};

		VertexBufferLayout layout = Vertex::GetLayout();

		m_VertexArray = std::make_unique<VertexArray>();
		m_VertexBuffer = std::make_unique<VertexBuffer>(nullptr, 100 * sizeof(Vertex), GL_DYNAMIC_DRAW);
		m_IndexBuffer = std::make_unique<IndexBuffer>(indeces, 18);
		m_Shader = std::make_unique<Shader>("res/basic.vert", "res/basic.frag");

		m_VertexArray->AddBuffer(*m_VertexBuffer, layout);

		auto mvp = m_Proj * m_View * m_Model;
		m_Shader->Bind();
		m_Shader->SetUniformMat4f("u_Projection", mvp);

		Texture tex0("res/images/white.jpg");
		Texture tex1("res/images/sanju.jpg");
		Texture tex2("res/images/gravel.jpg");
		tex0.Bind(0);
		tex1.Bind(1);
		tex2.Bind(2);

		m_Shader->SetUniform1i("u_Texture[0]", 0);
		m_Shader->SetUniform1i("u_Texture[1]", 1);
		m_Shader->SetUniform1i("u_Texture[2]", 2);

	}

	void BatchRenderer::Update()
	{
		auto q1 = MakeQuad(m_PosA.x, m_PosA.y, m_SizeA, 1);
		auto q2 = MakeQuad(m_PosB.x, m_PosB.y, m_SizeB, 2);
		auto q3 = MakeQuad(500, 500, 100, 0, {0.3,0.5,0.9});

		memcpy(m_vertices, q1.data(), 4 * sizeof(Vertex));
		memcpy(m_vertices + 4, q2.data(), 4 * sizeof(Vertex));
		memcpy(m_vertices + 8, q3.data(), 4 * sizeof(Vertex));

		m_VertexBuffer->SetData(m_vertices, sizeof(m_vertices));

		Renderer renderer;
		renderer.Draw(*m_VertexArray, *m_IndexBuffer, *m_Shader);
	}

	void BatchRenderer::OnImGuiRender()
	{
		ImGui::Begin("Controls");
		ImGui::DragFloat2("Image 1 Translation", &m_PosA.x, 1.f);
		ImGui::DragFloat("Image 1 Scale", &m_SizeA);

		ImGui::DragFloat2("Image 2 Translation", &m_PosB.x, 1.f);
		ImGui::DragFloat("Image 2 Scale", &m_SizeB);
		ImGui::End();
	}

}