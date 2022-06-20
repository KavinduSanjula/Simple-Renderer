#include "Test_BatchRenderer.h"

namespace test {

	Test_BatchRenderer::Test_BatchRenderer()
		:m_Quad1({-0.5,-0.5},{1,1})
	{
		m_Renderer = new BatchRenderer;
		

	}

	Test_BatchRenderer::~Test_BatchRenderer()
	{
		delete m_Renderer;
	}

	void Test_BatchRenderer::Update()
	{
		m_Renderer->BeginBatch();
		m_Renderer->Push(m_Quad1);
		m_Renderer->Flush();
	}

	void Test_BatchRenderer::OnImGuiRender()
	{

	}

}