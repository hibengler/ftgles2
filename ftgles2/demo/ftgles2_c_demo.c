/*
 * 
 * Copyright (c) 2018 Hibbard M. Engler <h@killercool.net>
 * Copyright (c) 2008 Sam Hocevar <sam@zoy.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/* borrowed code from simple.cpp - simple demo for FTGL, the OpenGL font library */ 
 
#include <math.h> // sin(), cos()
#include <stdlib.h> // exit()
#include <unistd.h>


#if defined HAVE_GL_GLUT_H
#   include <GL/glut.h>
#elif defined HAVE_GLUT_GLUT_H
#   include <GLUT/glut.h>
#else
#   error GLUT headers not present
#endif

#include <FTGLES2/ftgles2.h>

int frames=0;
int lastfps=0;
FTGLfont *font;

static void RenderScene(void)
{
    int now = glutGet(GLUT_ELAPSED_TIME);

    float n = (float)now / 20.;
    float t1 = sin(n / 80);
    float t2 = sin(n / 50 + 1);
    float t3 = sin(n / 30 + 2);

    float ambient[4]  = { (t1 + 2.0) / 3,
                          (t2 + 2.0) / 3,
                          (t3 + 2.0) / 3, 0.3 };
    float diffuse[4]  = { 1.0, 0.9, 0.9, 1.0 };
    float specular[4] = { 1.0, 0.7, 0.7, 1.0 };
    float position[4] = { 100.0, 100.0, 0.0, 1.0 };

    float front_ambient[4]  = { 0.7, 0.7, 0.7, 0.0 };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    glPushMatrix();
        glTranslatef(-0.9, -0.2, -10.0);
        glLightfv(GL_LIGHT1, GL_AMBIENT,  ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE,  diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
        glLightfv(GL_LIGHT1, GL_POSITION, position);
        glEnable(GL_LIGHT1);
    glPopMatrix();



        glMaterialfv(GL_FRONT, GL_AMBIENT, front_ambient);
        glColorMaterial(GL_FRONT, GL_DIFFUSE);
        glTranslatef(0.0, 0.0, 20.0);
        glRotatef(n / 1.11, 0.0, 1.0, 0.0);
        glRotatef(n / 2.23, 1.0, 0.0, 0.0);
        glRotatef(n / 3.17, 0.0, 0.0, 1.0);
        glTranslatef(-260.0, -0.2, 0.0);

	
        glColor4f(1.0, 1.0, 1.0,1.0);
        ftglRenderFont(font, "Hello Worla", FTGL_RENDER_ALL);
        ftglRenderFont(font, "Hello World!", FTGL_RENDER_ALL);

    glutSwapBuffers();

    frames++;

    if(now - lastfps > 5000)
    {
        fprintf(stderr, "%i frames in 5.0 seconds = %g FPS\n",
                frames, frames * 1000. / (now - lastfps));
        lastfps += 5000;
        frames = 0;
    }
}

//
//  GLUT key processing function: <esc> quits, <tab> cycles across fonts.
//
static void ProcessKeys(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27:
        /* Destroy the font object. */
        //delete font;
        ftglDestroyFont(font);
        exit(EXIT_SUCCESS);
        break;
    }
}

#define FONT_FILE "impact.ttf"


int main(int argc, char **argv)
{
    char const *file = NULL;

#ifdef FONT_FILE
    file = FONT_FILE;
#else
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <font_name.ttf>\n", argv[0]);
        return EXIT_FAILURE;
    }
#endif

    if(argc > 1)
    {
        file = argv[1];
    }




    // Initialise GLUT stuff
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("simple FTGL C++ demo");

    glutDisplayFunc(RenderScene);
    glutIdleFunc(RenderScene);
    glutKeyboardFunc(ProcessKeys);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, 640.0f / 480.0f, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 640.0f / 2.0f, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Initialise FTGLES2 stuff
/* Create a pixmap font from a TrueType file. */
font = ftglCreatePixmapFont(file);

/* If something went wrong, bail out. */
if(!font) {
  fprintf(stderr,"cant open font at %s\n",file);
    return -1;
    }

/* Set the font size and render a small text. */   
//    font->FaceSize(80);
ftglSetFontFaceSize(font,72,72);

//    font->Depth(10);
//    font->Outset(0, 3);
//    font->CharMap(ft_encoding_unicode);




    // Run GLUT loop
    glutMainLoop();

    return EXIT_SUCCESS;
}



