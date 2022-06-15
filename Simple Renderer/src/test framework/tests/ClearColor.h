#pragma once
#include "../Test.h"

#include "core/opengl.h"
#include "imgui/imgui.h"

namespace test {

	class ClearColor : public Test 
	{
	public:
		void Start() override;
		void Update() override;
		void OnImGuiRender() override;

	private:
		float m_Color[4] = { 1.0f,0.0f,1.0f,1.0f };
	};

}