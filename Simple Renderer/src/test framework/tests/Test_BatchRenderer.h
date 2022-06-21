#pragma once
#include "../Test.h"
#include "core/opengl.h"
#include "imgui/imgui.h"

#include "core/opengl.h"
#include "core/VertexBuffer.h"
#include "core/VertexArray.h"
#include "util/VertexBufferLayout.h"
#include "core/IndexBuffer.h"
#include "core/Shader.h"
#include "core/Texture.h"
#include "core/Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "core/BatchRenderer.h"
#include "core/Quad.h"

#include <memory>

namespace test {

	class Test_BatchRenderer : public Test 
	{
	public:
		Test_BatchRenderer();
		~Test_BatchRenderer();

		void Update() override;
		void OnImGuiRender() override;

	private:
		Quad m_Quad1;
		Quad m_Quad2;
		BatchRenderer* m_Renderer;

		Vec2 m_Pos = { -.5f, -.5f };
		Vec2 m_Scale = { .5,.5 };

	};

}