#include "Shader.h"

std::string Shader::read_content_from_file(std::string& filename) {
	std::string content;
	std::string line;

	std::ifstream stream(filename);
	if (stream.is_open()) {
		while (getline(stream, line)) {
			content += line + "\n";
		}
	}
	else {
		std::cout << "Error: can't read file." << std::endl;
	}

	stream.close();
	return content;
}

unsigned int Shader::compile_shader(unsigned int type, std::string shaderSource)
{
	const char* shader_source = shaderSource.c_str();
	GLCALL(unsigned int shader = glCreateShader(type));
	GLCALL(glShaderSource(shader, 1, &shader_source, NULL));
	GLCALL(glCompileShader(shader));

	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success) {
		std::cout << infoLog << std::endl;
		ASSERT(false);
	}

	return shader;
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	std::string vs = read_content_from_file(vertexShaderPath);
	std::string fs = read_content_from_file(fragmentShaderPath);

	unsigned int vertexShader = compile_shader(GL_VERTEX_SHADER, vs);
	unsigned int fragmentShader = compile_shader(GL_FRAGMENT_SHADER, fs);

	m_programID = glCreateProgram();
	glAttachShader(m_programID, vertexShader);
	glAttachShader(m_programID, fragmentShader);
	glLinkProgram(m_programID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLCALL(glUseProgram(m_programID));
}

Shader::~Shader()
{
	GLCALL(glDeleteProgram(m_programID));
}

void Shader::Bind() const
{
	GLCALL(glUseProgram(m_programID));
}

void Shader::Unbind() const
{
	GLCALL(glUseProgram(0));
}

void Shader::SetUniform1i(const char* uniform, int val)
{
	int location = GetUniformLocation(uniform);
	GLCALL(glUniform1i(location, val));
}

void Shader::SetUniform4f(const char* uniform, float v1, float v2, float v3, float v4)
{
	GLCALL(glUniform4f(GetUniformLocation(uniform), v1, v2, v3, v4));
}

void Shader::SetUniformMat4f(const char* uniform, glm::mat4& matrix)
{
	GLCALL(glUniformMatrix4fv(GetUniformLocation(uniform), 1, GL_FALSE, &matrix[0][0]));
}

int Shader::GetUniformLocation(const char* uniform) const
{
	GLCALL(int location = glGetUniformLocation(m_programID, uniform));
	return location;
}
