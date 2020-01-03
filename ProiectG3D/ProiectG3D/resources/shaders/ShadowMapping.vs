#version 330 core

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

out vec2 TexCoords;

out VS_OUT{
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
	vec4 FragPosLightSpace;
} vs_out;

uniform mat4 transform;
uniform mat4 lightSpaceMatrix;

void main()
{
	vs_out.FragPos = vec3(transform * vec4(position, 1.0));
	vs_out.Normal = transpose(inverse(mat3(transform))) * normal;
	vs_out.TexCoords = texCoord;
	vs_out.FragPosLightSpace = lightSpaceMatrix * vec4(vs_out.FragPos, 1.0);
	gl_Position = transform * vec4(position, 1.0);
}