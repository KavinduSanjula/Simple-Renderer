#pragma once

#include <stb-image/stb_image.h>

#include "opengl.h"

#include <string>

class Texture {
private:
	unsigned int m_TextureID;
	int m_Width, m_Height, m_NrChannels;
	unsigned char* m_LocalBuffer;
	std::string m_TexturePath;

public:
	Texture(const std::string& filepath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind();

	inline std::string GetTexturePath() const { return m_TexturePath; }
	inline unsigned int GetTextureID() const { return m_TextureID; }
};
