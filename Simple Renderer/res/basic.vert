#version 330 core

layout (location = 0) in vec3 a_Pos;
layout (location = 1) in vec4 a_Color;
layout (location = 2) in vec2 a_TexCoord;
layout (location = 3) in float a_TexID;

out vec4 v_Color;
out vec2 v_TexCoord;
out float v_TexID;

uniform mat4 u_Projection;

void main(){
	gl_Position = vec4(a_Pos.xyz,1.0);//u_Projection * vec4(a_Pos.xyz, 1.0);
	v_Color = a_Color;
	v_TexCoord = a_TexCoord;
	v_TexID = a_TexID;
}