#include "Test_BatchRenderer.h"

namespace test {


	Test_BatchRenderer::Test_BatchRenderer()
		:m_Quad1({ -0.5,-0.5 }, { 1,1 }, {1,1,1,1}),
		m_Quad2({ .5,.5 }, { .5,.5 }, {1.0,0.0,0.0,1.0}, "res/images/sanju.jpg")
	{
		m_Renderer = new BatchRenderer;
		

	}

	Test_BatchRenderer::~Test_BatchRenderer()
	{
		delete m_Renderer;
	}

	void Test_BatchRenderer::Update()
	{
		m_Quad2.SetPosition(m_Pos);
		m_Quad2.SetSize(m_Scale);

		m_Renderer->BeginBatch();
		m_Renderer->Push(m_Quad1);
		m_Renderer->Push(m_Quad2);
		m_Renderer->Flush();
	}

	void Test_BatchRenderer::OnImGuiRender()
	{
		ImGui::Begin("Controls");
		ImGui::DragFloat2("Pos", &m_Pos.x, 0.01f);
		ImGui::DragFloat2("Scale", &m_Scale.x, 0.01f);
		ImGui::End();
	}

}