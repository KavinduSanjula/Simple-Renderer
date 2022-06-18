#pragma once
#include "../Test.h"
#include "core/opengl.h"
#include "imgui/imgui.h"

#include "core/opengl.h"
#include "core/VertexBuffer.h"
#include "util/VertexBufferLayout.h"
#include "core/IndexBuffer.h"
#include "core/Shader.h"
#include "core/Texture.h"
#include "core/Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <memory>

namespace test {

	class BatchRenderer : public Test 
	{
	public:
		BatchRenderer();

		void Update() override;
		void OnImGuiRender() override;

	private:
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
		
		glm::vec3 m_ModelTranslation;
		glm::vec3 m_ViewTranslation;

		glm::mat4 m_Proj;
		glm::mat4 m_View;
		glm::mat4 m_Model;
	};

}