#version 460 core
out vec4 FragColor;
in vec4 vColor;
in vec2 vTexCoords;

uniform sampler2D u_default;
uniform sampler2D u_albedo;

void main()
{
	//vec4 texColor = texture(u_Texture, v_texCoord);
	FragColor = mix(texture(u_albedo, vTexCoords), vColor, .5);//texture(texture0, v_texCoord);
	//FragColor = vec4(0.0, 1.0, 0.0, 1.0);
}
