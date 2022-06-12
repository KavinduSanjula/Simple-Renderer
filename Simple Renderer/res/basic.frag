#version 330 core

out vec4 FragColor;

in vec2 v_TexCoord;

uniform sampler2D u_Texture;
uniform vec4 color;

void main(){
	vec4 texColor = texture(u_Texture, v_TexCoord);
	FragColor = vec4(texColor.xyz, 1.0);
	//vec4(1.0,1.0,0.0,1.0);//
}