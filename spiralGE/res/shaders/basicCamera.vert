#version 330 core
layout(location=0) in vec3 pos;
uniform mat4 projection,view,model;

void main(){
	gl_Position = vec4(projection * view * model,1.0);
}