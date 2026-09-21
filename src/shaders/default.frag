#version 460 core

out vec4 FragColor;
in vec4 vcolor;
//in vec2 texCoords;


void main()
{
	FragColor = vec4(vcolor);
}