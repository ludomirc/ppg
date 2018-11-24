#version 330

out vec4 vFragColor;
in vec3 v_vertex_color;
in float v_intesity;
void main()
{
   //vFragColor = vec4(1.f, 0.f, 0.f, 1.f);
   vFragColor = vec4(v_vertex_color*v_intesity, 1.f);
}
