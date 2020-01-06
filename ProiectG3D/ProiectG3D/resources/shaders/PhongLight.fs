#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

uniform float Ka;
uniform float Kd;
uniform float Ks;
uniform float CoefS;

void main()
{
	// ambient
	vec3 ambient = Ka * lightColor;

	// diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = Kd * max(dot(norm, lightDir), 0.0);
	vec3 diffuse=diff*lightColor;

	// specular
	vec3 viewDir=normalize(viewPos-FragPos);
	vec3 reflectDir=reflect(-lightDir,norm);
	float spec=Ks * pow(max(dot(viewDir,reflectDir),0.0),CoefS);
	vec3 specular = spec * lightColor;

	// combined
	vec3 result = (ambient + diffuse + specular)* objectColor;
	FragColor = vec4(result, 1.0);
}