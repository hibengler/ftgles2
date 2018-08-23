gcc -DFTGLES2=1 -g -I/usr/include -DHAVE_GL_GLUT_H \
 -I/usr/include/freetype2 -o CTest CTest.c  \
 ../src/.libs/libftgles2.a    -lGLESv2 -lEGL -lglfw \
 -lm -lstdc++ -lfreetype 

