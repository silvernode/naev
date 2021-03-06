#version 130

uniform vec4 color;
uniform sampler2D sampler;

in vec2 tex_coord_out;
out vec4 color_out;

void main(void) {
   color_out = color;
   color_out.a = texture2D(sampler, tex_coord_out).a;
}
