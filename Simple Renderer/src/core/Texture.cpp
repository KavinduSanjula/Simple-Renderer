#include "Texture.h"

Texture::Texture(const std::string& filepath)
	:m_Width(0),m_Height(0),m_NrChannels(0),m_TextureID(0),m_LocalBuffer(nullptr),
	m_TexturePath(filepath)

{
	stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load(filepath.c_str(), &m_Width, &m_Height, &m_NrChannels, 4);

	GLCALL(glGenTextures(1, &m_TextureID));
	GLCALL(glBindTexture(GL_TEXTURE_2D, m_TextureID));
	//glEnable(GL_TEXTURE_2D);

	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

	GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
	glGenerateMipmap(GL_TEXTURE_2D);
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

Texture::~Texture()
{
	stbi_image_free(m_LocalBuffer);
}

void Texture::Bind(unsigned int slot) const
{
	//GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
	//GLCALL(glBindTexture(GL_TEXTURE_2D, m_TextureID));
	glBindTextureUnit(slot, m_TextureID);
}

void Texture::Unbind()
{
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}
