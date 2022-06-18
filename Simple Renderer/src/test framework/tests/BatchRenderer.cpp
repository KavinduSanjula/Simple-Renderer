#include "BatchRenderer.h"

#include <iostream>
#include <array>

struct Vec4 {
	float x, y, z, w;
};
struct Vec3 {
	float x, y, z;
};
struct Vec2 {
	float x, y;
};


struct Vertex {
	Vec3 Position;
	Vec4 Color;
	Vec2 TexCoord;
	float TexID;

	static VertexBufferLayout GetLayout() {
		VertexBufferLayout layout;
		layout.Push<float>(3); //0
		layout.Push<float>(4); //1
		layout.Push<float>(2); //2
		layout.Push<float>(1); //3
		return layout;
	}
};

std::array<Vertex, 4> MakeQuad(float x, float y, float texID = 0, Vec4 color = { 1,1,1,1 }) {
	float size = 100.0f;

	Vertex v0;
	v0.Position = { x,y, 0 };
	v0.Color = color;
	v0.TexCoord = { 0,0 };
	v0.TexID = texID;

	Vertex v1;
	v1.Position = { x + size,y, 0};
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

static Vec2 posA = { 100,100 };
static Vec2 posB = { 200,200 };

namespace test {

	BatchRenderer::BatchRenderer()
		:m_ModelTranslation({ 0,0,0 }),
		m_ViewTranslation({0,0,0}),
		m_Proj(glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f)),
		m_View(glm::translate(glm::mat4(1.0f), m_ViewTranslation)),
		m_Model(glm::translate(glm::mat4(1.0f), m_ModelTranslation))
	{

		auto q1 = MakeQuad(100, 100, 1);
		auto q2 = MakeQuad(posB.x, posB.y, 1);

		Vertex vertices[8];

		memcpy(vertices, q1.data(), 4 * sizeof(Vertex));
		memcpy(vertices + 4, q2.data(), 4 * sizeof(Vertex));

		unsigned int indeces[]{
			0,1,2,2,3,0,
			4,5,6,6,7,4
		};

		VertexBufferLayout layout = Vertex::GetLayout();

		m_VertexBuffer = std::make_unique<VertexBuffer>(vertices, 100 * sizeof(Vertex), GL_STATIC_DRAW, layout);
		m_IndexBuffer = std::make_unique<IndexBuffer>(indeces, 12);
		m_Shader = std::make_unique<Shader>("res/basic.vert", "res/basic.frag");

		auto mvp = m_Proj * m_View * m_Model;
		m_Shader->Bind();
		m_Shader->SetUniformMat4f("u_Projection", mvp);

		Texture tex0("res/images/white.jpg");
		Texture tex1("res/images/sanju.jpg");
		tex0.Bind(0);
		tex1.Bind(1);

		m_Shader->SetUniform1i("u_Texture[0]", 0);
		m_Shader->SetUniform1i("u_Texture[1]", 1);

	}

	void BatchRenderer::Update()
	{
		Renderer renderer;
		renderer.Draw(*m_VertexBuffer, *m_IndexBuffer, *m_Shader);
	}

	void BatchRenderer::OnImGuiRender()
	{
		ImGui::Begin("Controls");
		ImGui::DragFloat2("Image 1", &posA.x, 1.f);
		ImGui::DragFloat2("Image 2", &posB.x, 1.f);
		ImGui::End();
	}

}