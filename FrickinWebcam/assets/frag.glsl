uniorm sampler2D tex0;

void main()
{   
    vec3 color  = texture2D(tex0,gl_TexCoord[0].st).rgb;
    gl_FragColor.rbg=color;
    gl_FragColor.a=1.0;
}