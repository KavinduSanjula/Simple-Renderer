#include "Texture2D.h"


namespace test {


	Texture2D::Texture2D()
		:m_ModelTranslation(glm::vec3(200,200,0)), m_CameraTranslation(glm::vec3(0, 0, 0)),
		m_Proj(glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f)),
		m_View(glm::translate(glm::mat4(1.0f),m_CameraTranslation)),
		m_Model(glm::translate(glm::mat4(1.0f), m_ModelTranslation))
	{
		float vertices[] = {
			  0.0f,   0.0f, 0.0f, 0.0f,
			200.0f,   0.0f, 1.0f, 0.0f,
			200.0f, 200.0f, 1.0f, 1.0f,
			  0.0f, 200.0f, 0.0f, 1.0f
		};


		unsigned int indeces[] = {
			0,1,2,
			2,3,0
		};

		

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);

		m_VertexBuffer = std::make_unique<VertexBuffer>(vertices, 4 * 4 * sizeof(float),layout);
		m_IndexBuffer = std::make_unique<IndexBuffer>(indeces, 6);
		m_Shader = std::make_unique<Shader>("res/basic.vert", "res/basic.frag");
		m_Texture = std::make_unique<Texture>("res/images/sanju.jpg");

		m_Texture->Bind();
		m_Shader->SetUniform1i("u_Texture", 0);
		
	}

	void Texture2D::Start()
	{
	}

	void Texture2D::Update()
	{
		Renderer renderer;

		m_Model = glm::translate(glm::mat4(1.0f), m_ModelTranslation);
		glm::mat4 mvp = m_Proj * m_View * m_Model;

		m_Texture->Bind();
		m_Shader->SetUniformMat4f("u_MVP", mvp);

		renderer.Draw(*m_VertexBuffer, *m_IndexBuffer, *m_Shader);
	}

	void Texture2D::OnImGuiRender()
	{
		ImGui::Begin("Translation");
		ImGui::DragFloat3("Position", &m_ModelTranslation.x);
		ImGui::End();
	}

}