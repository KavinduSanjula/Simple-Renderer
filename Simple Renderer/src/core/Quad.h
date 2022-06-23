#pragma once

#include "util/vector.h"

#include <array>
#include <string>

class Quad {
private:
	Vec2 m_Size;
	Vec2 m_Position;
	Vec4 m_Color;
	float m_TexID;

	std::string m_TexturePath;

	std::array<Vertex, 4> m_Vertices;

public:
	Quad(Vec2 pos, Vec2 size, Vec4 color, const std::string& texPath);
	~Quad();

	inline std::array<Vertex, 4> GetVertices() const { return m_Vertices; }
	inline std::string GetTexturePath() const { return m_TexturePath; }

	void SetTextureID(float texID);
	void SetPosition(Vec2 pos);
	void SetSize(Vec2 size);
	
};