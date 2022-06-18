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

#include <memory>

namespace test {

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


	class BatchRenderer : public Test 
	{
	public:
		BatchRenderer();

		void Update() override;
		void OnImGuiRender() override;

	private:
		std::unique_ptr<VertexArray> m_VertexArray;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
		
		glm::vec3 m_ModelTranslation;
		glm::vec3 m_ViewTranslation;

		glm::mat4 m_Proj;
		glm::mat4 m_View;
		glm::mat4 m_Model;

		Vertex m_vertices[12];

		Vec2 m_PosA = { 100,100 };
		Vec2 m_PosB = { 200,200 };
		float m_SizeA = 100.f;
		float m_SizeB = 200.f;
	};

}