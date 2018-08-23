/*
 
 Copyright (c) 2010 David Petrie
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 */

#include "ftgles2Glue.h"
#include "strings.h"

#define FTGLES_GLUE_MAX_VERTICES 32768


enum {
    ATTRIB_VERTEX,
    ATTRIB_COLOR,
    ATTRIB_TEXCOORD
};


typedef struct 
{
	float xyz[3];
	float st[2];
	GLubyte rgba[4];
} ftglesVertex_t;


typedef struct 
{
	ftglesVertex_t vertices[FTGLES_GLUE_MAX_VERTICES];
	short quadIndices[FTGLES_GLUE_MAX_VERTICES * 3 / 2];
	ftglesVertex_t currVertex;
	unsigned int currIndex;
} ftglesGlueArrays_t;

ftglesGlueArrays_t ftglesGlueArrays;

GLenum ftglesCurrentPrimitive = GL_TRIANGLES;
bool ftglesQuadIndicesInitted = false;

GLfloat ftgles2_foreground_color[4];	
GLfloat ftgles2_background_color[4];	

static void init_if_first_time(void) {
	if (!ftglesQuadIndicesInitted)
	{
		for (int i = 0; i < FTGLES_GLUE_MAX_VERTICES * 3 / 2; i += 6) 
		{
			int q = i / 6 * 4;
			ftglesGlueArrays.quadIndices[i + 0] = q + 0;
			ftglesGlueArrays.quadIndices[i + 1] = q + 1;
			ftglesGlueArrays.quadIndices[i + 2] = q + 2;
			
			ftglesGlueArrays.quadIndices[i + 3] = q + 0;
			ftglesGlueArrays.quadIndices[i + 4] = q + 2;
			ftglesGlueArrays.quadIndices[i + 5] = q + 3;
		}
		ftglesQuadIndicesInitted = true;
		for (int i = 0; i < FTGLES_GLUE_MAX_VERTICES * 3 / 2; i += 6) 
		{
			int q = i / 6 * 4;
			ftglesGlueArrays.quadIndices[i + 0] = q + 0;
			ftglesGlueArrays.quadIndices[i + 1] = q + 1;
			ftglesGlueArrays.quadIndices[i + 2] = q + 2;
			
			ftglesGlueArrays.quadIndices[i + 3] = q + 0;
			ftglesGlueArrays.quadIndices[i + 4] = q + 2;
			ftglesGlueArrays.quadIndices[i + 5] = q + 3;
		}
		ftglesQuadIndicesInitted = true;
  ftgles2_foreground_color[0] = 1.f;
  ftgles2_foreground_color[1] = 1.f;
  ftgles2_foreground_color[2] = 1.f;
  ftgles2_foreground_color[3] = 1.f;
  
  ftgles2_background_color[0] = 0.f;
  ftgles2_background_color[1] = 0.f;
  ftgles2_background_color[2] = 0.f;
  ftgles2_background_color[3] = 1.f;

  }
}


GLfloat * ftgles2DirectAccessToFakeCurrentColor(void) {
init_if_first_time();
return &(ftgles2_foreground_color[0]);
}	



GLfloat * ftgles2DirectAccessToFakeRasterColor(void) {
init_if_first_time();
return &(ftgles2_background_color[0]);
}	

GLvoid ftglBegin(GLenum prim) 
{
        ftglError("xqwwdd0");
	init_if_first_time();
	
    
	ftglesGlueArrays.currIndex = 0;
	ftglesCurrentPrimitive = prim;
	
        int currentProgram;
    
        glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram);
        ftglError("xqwwdd1");

	
			
/*        GLint positionLocation = glGetAttribLocation(currentProgram, "ft_position");
        GLint colorLocation =    glGetAttribLocation(currentProgram, "ft_colorx");
        ftglError("u1");
*/	
	
// 	glEnableVertexAttribArray(positionLocation);
//        ftglError("v1");
//	glEnableVertexAttribArray(colorLocation);
//        ftglError("v2");
}


GLvoid ftglTranslatef(float x, float y, float z)
{
    //glTranslatef(x, y, z);
}


GLvoid ftglVertex3f(float x, float y, float z) 
{
	if (ftglesGlueArrays.currIndex >= FTGLES_GLUE_MAX_VERTICES)
	{
		return;
	}
	
	ftglesGlueArrays.currVertex.xyz[0] = x;
	ftglesGlueArrays.currVertex.xyz[1] = y;
	ftglesGlueArrays.currVertex.xyz[2] = z;
	ftglesGlueArrays.vertices[ftglesGlueArrays.currIndex] = ftglesGlueArrays.currVertex;
	ftglesGlueArrays.currIndex++;
}


GLvoid ftglVertex2f(float x, float y) 
{
	if (ftglesGlueArrays.currIndex >= FTGLES_GLUE_MAX_VERTICES)
	{
		return;
	}
	
	ftglesGlueArrays.currVertex.xyz[0] = x;
	ftglesGlueArrays.currVertex.xyz[1] = y;
	ftglesGlueArrays.currVertex.xyz[2] = 0.0f;
	ftglesGlueArrays.vertices[ftglesGlueArrays.currIndex] = ftglesGlueArrays.currVertex;
	ftglesGlueArrays.currIndex++;
}


GLvoid ftglColor4ub(GLubyte r, GLubyte g, GLubyte b, GLubyte a) 
{
	ftglesGlueArrays.currVertex.rgba[0] = r;
	ftglesGlueArrays.currVertex.rgba[1] = g;
	ftglesGlueArrays.currVertex.rgba[2] = b;
	ftglesGlueArrays.currVertex.rgba[3] = a;
}


GLvoid ftglColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a) 
{
	ftglesGlueArrays.currVertex.rgba[0] = (GLubyte) (r * 255);
	ftglesGlueArrays.currVertex.rgba[1] = (GLubyte) (g * 255);
	ftglesGlueArrays.currVertex.rgba[2] = (GLubyte) (b * 255);
	ftglesGlueArrays.currVertex.rgba[3] = (GLubyte) (a * 255);
}


GLvoid ftglTexCoord2f(GLfloat s, GLfloat t) 
{
	ftglesGlueArrays.currVertex.st[0] = s;
	ftglesGlueArrays.currVertex.st[1] = t;
}



GLvoid bindArrayBuffers()
{
}


GLvoid ftglBindTexture(unsigned int textureId)
{
/*    GLint activeTextureID;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &activeTextureID);
    if((unsigned int)activeTextureID != textureId)
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
*/
}


GLvoid ftglEnd() 
{
    ftglError("x");

	
//		if (colorArrayEnabled)

        

        
//	if (!texCoordArrayEnabled)
	
    
    int currentProgram;
    
    glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram);
    ftglError("x1");
    
    if (currentProgram == 0)
    {
        return;
    }
    /*
    GLint texCoordLocation = glGetAttribLocation(currentProgram, "ft_texCoord");
    ftglError("x1a");
    GLint positionLocation = glGetAttribLocation(currentProgram, "ft_position");
    ftglError("x1b");
    GLint colorLocation =    glGetAttribLocation(currentProgram, "ft_color");
    ftglError("x1c");
//    colorLocation=1;
*/


    GLint texCoordLocation = ATTRIB_TEXCOORD;
    GLint positionLocation = ATTRIB_VERTEX;
    GLint colorLocation =    ATTRIB_COLOR;
    
	if (ftglesGlueArrays.currIndex == 0) 
	{
		ftglesCurrentPrimitive = 0;
		return;
	}
    ftglError("x2");
    
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, 0, 
      sizeof(ftglesVertex_t), &(ftglesGlueArrays.vertices[0].xyz));
    ftglError("x2a");
    glVertexAttribPointer(colorLocation, 4, GL_UNSIGNED_BYTE, 0, 
      sizeof(ftglesVertex_t), &(ftglesGlueArrays.vertices[0].rgba));
    ftglError("x2b");
    glVertexAttribPointer(texCoordLocation, 2, GL_FLOAT, 0, 
        sizeof(ftglesVertex_t), &(ftglesGlueArrays.vertices[0].st)); 
    ftglError("x2c");
    glEnableVertexAttribArray(positionLocation);
    ftglError("x2c1");
    glEnableVertexAttribArray(colorLocation);
    ftglError("x2c2");
    glEnableVertexAttribArray(texCoordLocation);
    ftglError("x2c3");
    
	if (ftglesCurrentPrimitive == GL_QUADS) 
	{
		glDrawElements(GL_TRIANGLES, ftglesGlueArrays.currIndex / 4 * 6, GL_UNSIGNED_SHORT
		, ftglesGlueArrays.quadIndices);
	} 
	else 
	{
		glDrawArrays(ftglesCurrentPrimitive, 0, ftglesGlueArrays.currIndex);
	}
	ftglesGlueArrays.currIndex = 0;
	ftglesCurrentPrimitive = 0;
    
    
    ftglError("y");
	
    /*
	if (resetPointers)
	{
		if (vertexArrayEnabled)
		{
			glVertexPointer(vertexArraySize, vertexArrayType, 
							vertexArrayStride, vertexArrayPointer);	
		}
		if (texCoordArrayEnabled)
		{
			glTexCoordPointer(texCoordArraySize, texCoordArrayType, 
							  texCoordArrayStride, texCoordArrayPointer);
		}
		if (colorArrayEnabled)
		{
			glColorPointer(colorArraySize, colorArrayType, 
						   colorArrayStride, colorArrayPointer);
		}
	}
	
	if (!vertexArrayEnabled)
		glDisableClientState(GL_VERTEX_ARRAY);
	
	if (!texCoordArrayEnabled)
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	if (!colorArrayEnabled)
		glDisableClientState(GL_COLOR_ARRAY);
     */
    ftglError("z");
}


GLvoid ftglError(const char *source)
{
	GLenum error = glGetError();
	 
	switch (error) {
		case GL_NO_ERROR:
			break;
		case GL_INVALID_ENUM:
			fprintf(stderr,"GL Error (%x): GL_INVALID_ENUM. %s\n\n", error, source);
			break;
		case GL_INVALID_VALUE:
			fprintf(stderr,"GL Error (%x): GL_INVALID_VALUE. %s\n\n", error, source);
			break;
		case GL_INVALID_OPERATION:
			fprintf(stderr,"GL Error (%x): GL_INVALID_OPERATION. %s\n\n", error, source);
			break;
		case GL_OUT_OF_MEMORY:
			fprintf(stderr,"GL Error (%x): GL_OUT_OF_MEMORY. %s\n\n", error, source);
			break;
		default:
			fprintf(stderr,"GL Error (%x): %s\n\n", error, source);
			break;
	}
}

