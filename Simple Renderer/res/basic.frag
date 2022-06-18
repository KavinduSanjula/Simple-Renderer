#version 330 core

out vec4 FragColor;

in vec4 v_Color;
in vec2 v_TexCoord;
in float v_TexID;

uniform sampler2D u_Texture[2];

void main(){
	vec4 texColor = texture(u_Texture[int(v_TexID)],v_TexCoord);
	FragColor = texColor * v_Color;
}