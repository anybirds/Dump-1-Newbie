#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;

uniform mat4 model_transform; 
uniform mat4 camera_transform;
uniform mat4 normalization;

out vec2 uv;

void main() {
    uv = texcoord;
    gl_Position = normalization * inverse(camera_transform) * model_transform * vec4(pos, 1.0);
}