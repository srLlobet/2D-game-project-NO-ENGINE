#version 330 core

out vec4 FragColor;
in vec2 TexCoords;
uniform float Time = 1;

uniform sampler2D tex0;

void main(){

    vec4 texColor = texture(tex0, TexCoords + vec2(Time, 0));
    FragColor = vec4(texColor.r, texColor.g, texColor.b, texColor.a);
}