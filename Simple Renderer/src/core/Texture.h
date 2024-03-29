#pragma once

#include <stb-image/stb_image.h>

#include "opengl.h"


class Texture {
private:
	unsigned int m_TextureID;
	int m_Width, m_Height, m_NrChannels;
	unsigned char* m_LocalBuffer;

public:
	Texture(const char* filepath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind();
};
