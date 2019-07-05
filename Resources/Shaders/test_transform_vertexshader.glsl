#version 330 core

layout (location = 0) in vec3 pos;

uniform mat4 model_transform; 

void main() {
    gl_Position = model_transform * vec4(pos, 1.0);
}