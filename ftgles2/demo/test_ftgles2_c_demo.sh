gcc -g -I/usr/include -DHAVE_GL_GLUT_H -I/usr/include/freetype2 -o ftgles2_c_demo  ftgles2_c_demo.c /usr/local/lib/libftgles2.a   -lGL -lGLESv2 -lEGL -lm -lstdc++ -lfreetype -lglut
./ftgles2_c_demo 

Currently black.
