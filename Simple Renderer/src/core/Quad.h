#pragma once

#include "util/vector.h"

#include <array>

class Quad {
private:
	Vec2 m_Size;
	Vec2 m_Position;
	Vec4 m_Color;

	std::array<Vertex, 4> m_Vertices;

public:
	Quad(Vec2 pos = { 0,0 }, Vec2 size = { 100,100 }, Vec4 color = { 1,1,1,1 });
	~Quad();

	inline std::array<Vertex, 4> GetVertices() const { return m_Vertices; }
	
};