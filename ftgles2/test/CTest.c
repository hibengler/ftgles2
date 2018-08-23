/* Small C bindings test program */

/* This changed around - because GLUT is GL based - so we will try GLFW
  and SDL 2.0 later */
  
#include "config.h"


#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <unistd.h>

#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>


GLFWwindow* window;



#include <FTGLES2/ftgles2.h>

#define ALLOC(ctor, var, arg) \
    var = ctor(arg); \
    if(var == NULL) \
        return 2



/*---------------------------------------------------------------------------------------*/
/*  RenderController code */



/*
 *  RenderController.h
 *  OpenGLTest3
 *
 *  Created by David Petrie on 18/05/10.
 *  Copyright 2010 n/a. All rights reserved.
 *
 */

#ifndef GLES2_RENDER_CONTROLLER_H
#define GLES2_RENDER_CONTROLLER_H

#include <math.h>

#define MAX_VERTEX_COUNT 8192

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec4_t color4_t;

#define vec2Set(__v, __x, __y) __v[0] = __x; __v[1] = __y;
#define vec3Set(__v, __x, __y, __z) __v[0] = __x; __v[1] = __y; __v[2] = __z;
#define vec4Set(__v, __x, __y, __z, __u) __v[0] = __x; __v[1] = __y; __v[2] = __z; __v[3] = __u;

typedef struct vertex 
{
	float xyz[3];
	float st[2];
	float rgba[4];
} vertex_t;

enum {
    RENDER_ATTRIB_VERTEX,
    RENDER_ATTRIB_COLOR,
    RENDER_NUM_ATTRIBUTES
};


#define __11 0
#define __21 1
#define __31 2
#define __41 3
#define __12 4
#define __22 5
#define __32 6
#define __42 7
#define __13 8
#define __23 9
#define __33 10
#define __43 11
#define __14 12
#define __24 13
#define __34 14
#define __44 15

#ifdef __cplusplus
extern "C" {
#endif


void aglCross3(vec3_t vOut, const vec3_t a, const vec3_t b);


void aglNormalize3(vec3_t vOut, const vec3_t vec);


void aglMatrixMultiply(float *mOut,
					   const float *mA,
					   const float *mB);


void aglBegin(GLenum prim);

void aglVertex3f(float x, float y, float z);

void aglColor4f(float r, float g, float b, float a);

void aglTexCoord2f(float s, float t);

void aglEnd();

void aglError(const char *source);

void aglMatrixTranslation(
					   float	*mOut,
					   const float	fX,
					   const float	fY,
					   const float	fZ);

void aglMatrixRotationZ(float	*mOut,
						const float fAngle);

void aglMatrixPerspectiveFovRH(
							float	*mOut,
							const float	fFOVy,
							const float	fAspect,
							const float	fNear,
							const float	fFar);

void aglMatrixLookAtRH(float *mOut, const vec3_t vEye, const vec3_t vAt, const vec3_t vUp);



void aglOrtho(float *mOut, float left, float right, float bottom, float top, float zNear, float zFar);



#ifdef __cplusplus
}
#endif
#endif

/* ^^^ .h file */
/* vvv .c file */

/*
 *  RenderController.c
 *  OpenGLTest3
 *
 *  Created by David Petrie on 18/05/10.
 *  Copyright 2010 n/a. All rights reserved.
 *
 */

//#include "RenderController.h"


static vertex_t vertices[MAX_VERTEX_COUNT];
static vertex_t vertex;
static GLenum currentPrimitive = GL_TRIANGLES;
static int vertexCount = 0;



void aglBegin(GLenum prim)
{
	currentPrimitive = prim;
	vertexCount = 0;

	glVertexAttribPointer(RENDER_ATTRIB_VERTEX, 3, GL_FLOAT, 0, sizeof(vertex_t), vertices[0].xyz);
	glVertexAttribPointer(RENDER_ATTRIB_COLOR, 4, GL_FLOAT, 0, sizeof(vertex_t), vertices[0].rgba);
	
	glEnableVertexAttribArray(RENDER_ATTRIB_VERTEX);
	glEnableVertexAttribArray(RENDER_ATTRIB_COLOR);
}


void aglVertex3f(float x, float y, float z)
{
	if (vertexCount > MAX_VERTEX_COUNT) return;
    vec3Set(vertex.xyz, x, y, z);
	vertices[vertexCount] = vertex;
	vertexCount++;
}


void aglColor4f(float r, float g, float b, float a)
{
    vec4Set(vertex.rgba, r, g, b, a);
}


void aglTexCoord2f(float s, float t)
{
    vec2Set(vertex.st, s, t);
}


void aglEnd()
{
	if (vertexCount == 0) 
	{
		currentPrimitive = 0;
		return;
	}
	glDrawArrays(currentPrimitive, 0, vertexCount);
	vertexCount = 0;
	currentPrimitive = 0;
}


void aglMatrixTranslation(
					   float	*mOut,
					   const float	fX,
					   const float	fY,
					   const float	fZ)
{
	mOut[__11] = 1;	mOut[__12] = 0;	mOut[__13] = 0;	mOut[__14] = 0;
	mOut[__21] = 0;	mOut[__22] = 1;	mOut[__23] = 0;	mOut[__24] = 0;
	mOut[__31] = 0;	mOut[__32] = 0;	mOut[__33] = 1;	mOut[__34] = 0;
	mOut[__41] = fX;	mOut[__42] = fY;	mOut[__43] = fZ;	mOut[__44] = 1;
}


void aglMatrixRotationZ(float	*mOut,
					 const float fAngle)
{
	float fsin = sinf(fAngle);
	float fcos = cosf(fAngle);
	
	mOut[__11] = fcos;	mOut[__12] = fsin;	mOut[__13] = 0;	mOut[__14] = 0;
	mOut[__21] = -fsin;	mOut[__22] = fcos;	mOut[__23] = 0;	mOut[__24] = 0;
	mOut[__31] = 0;		mOut[__32] = 0;		mOut[__33] = 1;	mOut[__34] = 0;
	mOut[__41] = 0;		mOut[__42] = 0;	mOut[__43] = 0;	mOut[__44] = 1;
}


void aglMatrixPerspectiveFovRH(
							float	*mOut,
							const float	fFOVy,
							const float	fAspect,
							const float	fNear,
							const float	fFar)
{
	float f, n, fRealAspect;
	
	fRealAspect = fAspect;
	
	// cotangent(a) == 1.0f / tan(a);
	f = 1.0f / (float)tan(fFOVy * 0.5f);
	n = 1.0f / (fNear - fFar);
	
	mOut[ 0] = f / fRealAspect;
	mOut[ 1] = 0;
	mOut[ 2] = 0;
	mOut[ 3] = 0;
	
	mOut[ 4] = 0;
	mOut[ 5] = f;
	mOut[ 6] = 0;
	mOut[ 7] = 0;
	
	mOut[ 8] = 0;
	mOut[ 9] = 0;
	mOut[10] = (fFar + fNear) * n;
	mOut[11] = -1;
	
	mOut[12] = 0;
	mOut[13] = 0;
	mOut[14] = (2 * fFar * fNear) * n;
	mOut[15] = 0;
}


void aglCross3(vec3_t vOut, const vec3_t a, const vec3_t b)
{
	vec3Set(vOut,
			(a[1] * b[2]) - (a[2] * b[1]),
			(a[2] * b[0]) - (a[0] * b[2]),
			(a[0] * b[1]) - (a[1] * b[0]));
}


void aglNormalize3(vec3_t vOut, const vec3_t vec)
{
	float	f;
	double temp;
	
	temp = (double)(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	temp = 1.0 / sqrt(temp);
	f = (float)temp;
	vec3Set(vOut, vec[0] * f, vec[1] * f, vec[2] * f);
}


void aglMatrixLookAtRH(float *mOut, const vec3_t vEye, const vec3_t vAt, const vec3_t vUp)
{
	vec3_t f, vUpActual, s, u;
	float	t[16];
	
	f[0] = vAt[0] - vEye[0];
	f[1] = vAt[1] - vEye[1];
	f[2] = vAt[2] - vEye[2];
	
	aglNormalize3(f, f);
	aglNormalize3(vUpActual, vUp);
	aglCross3(s, f, vUpActual);
	aglCross3(u, s, f);
	
	mOut[ 0] = s[0];
	mOut[ 1] = u[0];
	mOut[ 2] = -f[0];
	mOut[ 3] = 0;
	
	mOut[ 4] = s[1];
	mOut[ 5] = u[1];
	mOut[ 6] = -f[1];
	mOut[ 7] = 0;
	
	mOut[ 8] = s[2];
	mOut[ 9] = u[2];
	mOut[10] = -f[2];
	mOut[11] = 0;
	
	mOut[12] = 0;
	mOut[13] = 0;
	mOut[14] = 0;
	mOut[15] = 1;
	
	aglMatrixTranslation(t, -vEye[0], -vEye[1], -vEye[2]);
	aglMatrixMultiply(mOut, t, mOut);
}


void aglMatrixMultiply(float *mOut,
					  const float *mA,
					  const float *mB)
{
	mOut[__11] = mA[__11]*mB[__11] + mA[__12]*mB[__21] + mA[__13]*mB[__31] + mA[__14]*mB[__41];	
	mOut[__12] = mA[__11]*mB[__12] + mA[__12]*mB[__22] + mA[__13]*mB[__32] + mA[__14]*mB[__42];	
	mOut[__13] = mA[__11]*mB[__13] + mA[__12]*mB[__23] + mA[__13]*mB[__33] + mA[__14]*mB[__43];	
	mOut[__14] = mA[__11]*mB[__14] + mA[__12]*mB[__24] + mA[__13]*mB[__34] + mA[__14]*mB[__44];
	
	mOut[__21] = mA[__21]*mB[__11] + mA[__22]*mB[__21] + mA[__23]*mB[__31] + mA[__24]*mB[__41];	
	mOut[__22] = mA[__21]*mB[__12] + mA[__22]*mB[__22] + mA[__23]*mB[__32] + mA[__24]*mB[__42];	
	mOut[__23] = mA[__21]*mB[__13] + mA[__22]*mB[__23] + mA[__23]*mB[__33] + mA[__24]*mB[__43];	
	mOut[__24] = mA[__21]*mB[__14] + mA[__22]*mB[__24] + mA[__23]*mB[__34] + mA[__24]*mB[__44];
	
	mOut[__31] = mA[__31]*mB[__11] + mA[__32]*mB[__21] + mA[__33]*mB[__31] + mA[__34]*mB[__41];	
	mOut[__32] = mA[__31]*mB[__12] + mA[__32]*mB[__22] + mA[__33]*mB[__32] + mA[__34]*mB[__42];	
	mOut[__33] = mA[__31]*mB[__13] + mA[__32]*mB[__23] + mA[__33]*mB[__33] + mA[__34]*mB[__43];	
	mOut[__34] = mA[__31]*mB[__14] + mA[__32]*mB[__24] + mA[__33]*mB[__34] + mA[__34]*mB[__44];
	
	mOut[__41] = mA[__41]*mB[__11] + mA[__42]*mB[__21] + mA[__43]*mB[__31] + mA[__44]*mB[__41];
	mOut[__42] = mA[__41]*mB[__12] + mA[__42]*mB[__22] + mA[__43]*mB[__32] + mA[__44]*mB[__42];
	mOut[__43] = mA[__41]*mB[__13] + mA[__42]*mB[__23] + mA[__43]*mB[__33] + mA[__44]*mB[__43];
	mOut[__44] = mA[__41]*mB[__14] + mA[__42]*mB[__24] + mA[__43]*mB[__34] + mA[__44]*mB[__44];
}


void aglOrtho(float *mOut, float left, float right, float bottom, float top, float zNear, float zFar)
{
    bzero(mOut, sizeof(float) * 16);
    
    if (right != left)
    {
        mOut[ 0] = 2 / (right - left);
        mOut[ 1] = 0;
        mOut[ 2] = 0;
        mOut[ 3] = - ((right + left) / (right - left));
    }
    
    if (top != bottom)
    {
        mOut[ 4] = 0;
        mOut[ 5] = 2 / (top - bottom);
        mOut[ 6] = 0;
        mOut[ 7] = - ((top + bottom) / (top - bottom));
    }
	
    if (zFar != zNear)
    {
        mOut[ 8] = 0;
        mOut[ 9] = 0;
        mOut[10] = -2 / (zFar - zNear);
        mOut[11] = - ((zFar + zNear) / (zFar - zNear));
    }
	
	mOut[12] = 0;
	mOut[13] = 0;
	mOut[14] = 0;
	mOut[15] = 1;
}


/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Render Controller code end ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^66 */







static GLuint shaderProgram = 0;
static GLuint cameraUniform;
static float cameraMatrix[16];
static float viewMatrix[16];
static float modelMatrix[16];
static float MVMatrix[16];
static float MVPMatrix[16];


//vvvvvvvvvvvvvvvvvvvv this one vvvvvvvvvvvvvvvvvvvvvv



static const GLchar * vertex_shader_text = 
"precision mediump float;\n"
"attribute vec4 ft_position;\n"
"attribute vec4 ft_color;\n"
"attribute vec2 ft_texCoord;\n"
"varying vec4 ft_colorVarying;\n"
"varying vec2 ft_texture_coordinate;\n"
" \n"
"uniform mat4 ft_camera;\n"
" \n"
"void main()\n"
"{\n"
"        gl_Position = (ft_camera * ft_position);\n"
"        ft_colorVarying = ft_color;\n"
"        ft_texture_coordinate = ft_texCoord;\n"
"}\n";


//"precision mediump float;\n"

static const GLchar*  fragment_shader_text = 
"precision mediump float;\n"
"varying vec4 ft_colorVarying;\n"
"varying vec2 ft_texture_coordinate;\n"
"uniform sampler2D ft_color_sampler;\n"
" \n"
"void main()\n"
"{\n"
"vec4 fc;\n"
"float factor;\n"
"fc = texture2D(ft_color_sampler, ft_texture_coordinate);\n"
"factor = fc.a;\n"
"fc.r = ft_colorVarying.r * factor;\n"
"fc.g = ft_colorVarying.g * factor;\n"
"fc.b = ft_colorVarying.b * factor;\n"
"fc.a = factor;\n"
"   gl_FragColor =  fc;\n"
"}\n";


static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    fprintf(stderr,"GL %s = %s\n", name, v);
}

static int checkGlError(const char* op) {
int eflag=0;
    for (GLint error = glGetError(); error; error  = glGetError()) {
        eflag=1;
        char *s = "";
	if  (error==GL_INVALID_ENUM) {s="GL_INAVLID_ENUM";}
	else if (error==GL_INVALID_VALUE) {s="GL_INVALID_VALUE";}
	else if (error==GL_INVALID_OPERATION) {s="GL_INVALID_OPERATION";}
	else if (error==GL_INVALID_FRAMEBUFFER_OPERATION) {s="GL_INVALID_FRAMEBUFFER_OPERATION";}
	else if (error==GL_OUT_OF_MEMORY) {s = "GL_OUT_OF_MEMORY";}
        fprintf(stderr,"after %s() glError %s(0x%x)\n", op, s,error);
    }
return eflag;
}

void gles2_init(void) {
    GLuint shader;
    GLint status;
 shaderProgram = glCreateProgram();
checkGlError("a");
fprintf(stderr,"program %d\n",shaderProgram);
 GLuint vertexShader = shader = glCreateShader(GL_VERTEX_SHADER);
 glShaderSource(vertexShader, 1, &vertex_shader_text, NULL);
checkGlError("b");
 glCompileShader(vertexShader);
checkGlError("c");
 glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
checkGlError("d");
 if (status==0) {
  fprintf(stderr,"bad vertex shader status %d\n",status);
            GLint infoLen = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(vertexShader, infoLen, NULL, buf);
                    fprintf(stderr,"Could not compile shader %d:\n%s\n",
                         shader, buf);
                    free(buf);
                }
                glDeleteShader(vertexShader);
                }
  exit(-1);
  }
 glAttachShader(shaderProgram, vertexShader);


 GLuint fragmentShader =  shader = glCreateShader(GL_FRAGMENT_SHADER);
checkGlError("e");
 glShaderSource(fragmentShader, 1, &fragment_shader_text, NULL);
checkGlError("f");
 glCompileShader(fragmentShader);
checkGlError("g");
 glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
checkGlError("h");
 if (status!= GL_TRUE) {
  fprintf(stderr,"bad fragment shader status %d\n",status);
            GLint infoLen = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(fragmentShader, infoLen, NULL, buf);
                    fprintf(stderr,"Could not compile shader %d:\n%s\n",
                         shader, buf);
                    free(buf);
                }
                glDeleteShader(fragmentShader);
             }
  sleep(3);
  exit(-1);
  }
 glAttachShader(shaderProgram, fragmentShader);

checkGlError("j");

glBindAttribLocation(shaderProgram, RENDER_ATTRIB_VERTEX, "ft_position");
glBindAttribLocation(shaderProgram, RENDER_ATTRIB_COLOR, "ft_color");
glBindAttribLocation(shaderProgram, 2, "ft_texCoord");
checkGlError("k");
glLinkProgram(shaderProgram);

checkGlError("l");

glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
checkGlError("l1");
 if (status!= GL_TRUE) {
  fprintf(stderr,"bad program link status %d\n",status);
            GLint infoLen = 0;
            glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetProgramInfoLog(shaderProgram, infoLen, NULL, buf);
                    fprintf(stderr,"Could not link program %d:\n%s\n",
                         0, buf);
                    free(buf);
                }
             }
  exit(-1);
  }

cameraUniform = glGetUniformLocation(shaderProgram, "ft_camera");
checkGlError("m");
    glDeleteShader(vertexShader);  
    glDeleteShader(fragmentShader);
  aglOrtho(cameraMatrix, -400.f, 400.f, -400.f, 400.f, -10000.0f, 10000.0f);
  aglMatrixTranslation(viewMatrix,0.f,0.f,0.f); // identity
  aglMatrixTranslation(modelMatrix,0.f,0.f,0.f); // identity
  

}


int main(int argc, char *argv[])
{
    FTGLfont *f[6];
    char *font_filename = "impact.ttf";
    int i;

    if(argc == 2)
      font_filename=argv[1];


    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWmonitor *primary_monitor = glfwGetPrimaryMonitor();
//    glfwGetMonitorPhysicalSize(primary_monitor, &widthMM, &heightMM);
      const GLFWvidmode* mode = glfwGetVideoMode(primary_monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    glfwWindowHint(GLFW_AUTO_ICONIFY, GL_FALSE);
 window = glfwCreateWindow(1920,900, 
"Silent Radiance",glfwGetPrimaryMonitor() , NULL);
      glfwMakeContextCurrent(window);
    printf("GL_VERSION  : %s\n", glGetString(GL_VERSION) ); 
    printf("GL_RENDERER : %s\n", glGetString(GL_RENDERER) );


	
    ALLOC(ftglCreateBitmapFont, f[0], font_filename);
    ALLOC(ftglCreateBitmapFont, f[1], font_filename);
    ALLOC(ftglCreateBitmapFont, f[2], font_filename);
//    ALLOC(ftglCreateExtrudeFont, f[1], font_filename);
//    ALLOC(ftglCreateOutlineFont, f[2], font_filename);
    ALLOC(ftglCreatePixmapFont, f[3], font_filename);
    ALLOC(ftglCreatePolygonFont, f[4], font_filename);  // works
    ALLOC(ftglCreateTextureFont, f[5], font_filename);  // works

    gles2_init();
   checkGlError("gles2_init\n");

   glClearColor(0.7f, 0.7f, 0.5f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);
   checkGlError("glClearColor\n");

    glUseProgram(shaderProgram);
   checkGlError("gluse\n");
    
    float plus80[16];
    aglMatrixTranslation(plus80,0.0f,0.f,0.f);
    

    


    for(i = 0; i < 6; i++)  ftglSetFontFaceSize(f[i], 72, 72);
       

    for(i = 0; i < 6; i++) {
      float temp[16];
      fprintf(stdout,"%d:\n",i);
      fflush(stdout);
      for (int j=0;j<16;j++)   temp[j]=viewMatrix[j];
	
//      aglMatrixMultiply(viewMatrix,temp,plus80);
//      aglMatrixMultiply(MVMatrix,modelMatrix,viewMatrix);
//      aglMatrixMultiply(MVPMatrix,MVMatrix,cameraMatrix);
//      aglMatrixMultiply(viewMatrix,plus80,temp);
//      aglMatrixMultiply(MVMatrix,viewMatrix,modelMatrix);
//      aglMatrixMultiply(MVPMatrix,cameraMatrix,MVMatrix);
      aglMatrixMultiply(viewMatrix,plus80,temp);
      aglMatrixMultiply(MVMatrix,viewMatrix,modelMatrix);
      aglMatrixMultiply(MVPMatrix,MVMatrix,cameraMatrix);

      glUniformMatrix4fv(cameraUniform, 1, GL_FALSE, MVPMatrix);
        char buf[200];
	int k;
	for (k=0;k<i;k++) { buf[k*3]=' ';buf[k*3+1]=' ';buf[k*3+2]=' ';}
	sprintf(buf+k+k+k,"%d\n",i);
        ftglRenderFont(f[i],buf, FTGL_RENDER_ALL);
        }	

glfwSwapBuffers(window);
checkGlError("swapbuffers\n");

sleep(3);
    for(i = 0; i < 6; i++)
        ftglDestroyFont(f[i]);
    return 0;
}

