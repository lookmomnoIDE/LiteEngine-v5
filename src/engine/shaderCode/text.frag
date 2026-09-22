#version 460 core
out vec4 color;

uniform sampler2D text;
uniform vec4 ourColor;
in vec2 v_texCoord;

void main()
{    
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, v_texCoord).r);
    color = vec4(ourColor) * sampled;
}