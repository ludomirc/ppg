#version 330

layout(location=0) in vec3 vertex_position;
layout(location=1) in vec3 vertex_color;
layout (std140) uniform modelViewProjection {mat4 mvp;};

out vec3 v_vertex_color;
void main()
{

    gl_Position = mvp * vec4(vertex_position, 1.f);
    v_vertex_color = vertex_color;
}
