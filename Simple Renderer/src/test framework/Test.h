#pragma once
#include <functional>
#include <vector>
#include <string>

namespace test {
	
	class Test {
	public:
		Test() {}
		virtual ~Test() {}

		virtual void Start() {}
		virtual void Update() {}
		virtual void OnImGuiRender() {}
	};

	class TestMenu : public Test {
	private:
		Test* m_CurretnTest;
		std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests ;

	public:

		void Start() override;
		void Update() override;
		void OnImGuiRender() override;

		template<typename T>
		void RegisterTest(std::string name);

		inline Test* GetCurretnTest() { return m_CurretnTest; }
		inline void SetCurrentTestToNull() { m_CurretnTest = nullptr; }
	};

	template<typename T>
	void TestMenu::RegisterTest(std::string name)
	{
		m_Tests.push_back({ name,[]() {return new T(); } });
	}

}