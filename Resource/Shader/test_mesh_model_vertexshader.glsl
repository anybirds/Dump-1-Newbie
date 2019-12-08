#version 330 core

layout (location = 0) in vec3 pos;

uniform mat4 model_transform; 
uniform mat4 camera_transform;
uniform mat4 normalization;

void main() {
    gl_Position = normalization * inverse(camera_transform) * model_transform * vec4(pos, 1.0);
}