#pragma once

#include "opengl.h"

#include <iostream>
#include <fstream>
#include <string>

#include <glm/gtc/matrix_transform.hpp>

class Shader {
private:
	unsigned int m_programID;

private:
	std::string read_content_from_file(std::string& filename);
	unsigned int compile_shader(unsigned int type, std::string shaderSource);

public:
	Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform1i(const char* uniform, int val);
	void SetUniform4f(const char* uniform, float v1, float v2, float v3, float v4);
	void SetUniformMat4f(const char* uniform, glm::mat4& matrix);

	int GetUniformLocation(const char* uniform) const;

	inline unsigned int GetProgram() const { return m_programID; }
};