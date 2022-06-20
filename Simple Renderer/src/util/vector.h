#pragma once
#include "VertexBufferLayout.h"


struct Vec4 {
	float x, y, z, w;
};

struct Vec3 {
	float x, y, z;
};

struct Vec2 {
	float x, y;
};

struct Vertex {
	Vec3 Position;
	Vec4 Color;
	Vec2 TexCoord;
	float TexID;

	static VertexBufferLayout GetLayout() {
		VertexBufferLayout layout;
		layout.Push<float>(3); //0
		layout.Push<float>(4); //1
		layout.Push<float>(2); //2
		layout.Push<float>(1); //3
		return layout;
	}
};