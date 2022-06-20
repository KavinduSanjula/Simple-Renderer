#include "Quad.h"

std::array<Vertex, 4> MakeQuad(Vec2 pos, Vec2 size, Vec4 color, float texID = 0);

Quad::Quad(Vec2 pos, Vec2 size , Vec4 color)
	:m_Position(pos), m_Size(size), m_Color(color)
{
	m_Vertices = MakeQuad(m_Position, m_Size, m_Color);
}

Quad::~Quad()
{

}


std::array<Vertex, 4> MakeQuad(Vec2 pos, Vec2 size, Vec4 color, float texID) {

	Vertex v0;
	v0.Position = { pos.x,pos.y, 0 };
	v0.Color = color;
	v0.TexCoord = { 0,0 };
	v0.TexID = texID;

	Vertex v1;
	v1.Position = { pos.x + size.x, pos.y, 0 };
	v1.Color = color;
	v1.TexCoord = { 1,0 };
	v1.TexID = texID;

	Vertex v2;
	v2.Position = { pos.x + size.x, pos.y + size.y, 0 };
	v2.Color = color;
	v2.TexCoord = { 1,1 };
	v2.TexID = texID;

	Vertex v3;
	v3.Position = { pos.x, pos.y + size.y, 0 };
	v3.Color = color;
	v3.TexCoord = { 0,1 };
	v3.TexID = texID;

	return std::array<Vertex, 4> {v0, v1, v2, v3};
}