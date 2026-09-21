#version 460 core
out vec4 FragColor;
in vec4 vColor;
in vec2 vTexCoords;

uniform sampler2D texture0;
uniform sampler2D texture1;

void main()
{
	//vec4 texColor = texture(u_Texture, v_texCoord);
	FragColor = mix(texture(texture0, vTexCoords), vColor, .5);//texture(texture0, v_texCoord);
	//FragColor = vec4(0.0, 1.0, 0.0, 1.0);
}
