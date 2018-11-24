#version 330

out vec4 vFragColor;
in vec3 v_vertex_color;

void main()
{

   vFragColor = vec4(v_vertex_color, 1.f);
}
