#include <unistd.h>
#include <FTGLES2/ftgles2.h>

int main() {
/* Create a pixmap font from a TrueType file. */
//FTGLfont *font = ftglCreatePixmapFont("/home/user/Arial.ttf");
FTGLfont *font = ftglCreatePixmapFont("impact.ttf");

/* If something went wrong, bail out. */
if(!font)
    return -1;

/* Set the font size and render a small text. */   
ftglSetFontFaceSize(font, 72, 72);
ftglRenderFont(font, "Hello World!", FTGL_RENDER_ALL);

sleep(10);
/* Destroy the font object. */
ftglDestroyFont(font);

}
