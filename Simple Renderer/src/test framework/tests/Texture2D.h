#pragma once

#include "test framework/Test.h"
#include "imgui/imgui.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <string>
#include <memory>

#include "core/VertexBuffer.h"
#include "core/IndexBuffer.h"
#include "core/Shader.h"
#include "core/Renderer.h"
#include "core/Texture.h"

#include "util/VertexBufferLayout.h"

namespace test {
	class Texture2D :public Test {
	private:
		std::string m_Filepath;

		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<Texture> m_Texture;

		glm::vec3 m_ModelTranslation;
		glm::vec3 m_CameraTranslation;
		glm::mat4 m_Proj;
		glm::mat4 m_View;
		glm::mat4 m_Model;

	public:
		Texture2D();
		void Start() override;
		void Update() override;
		void OnImGuiRender() override;
	};
}