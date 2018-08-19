
lib_LTLIBRARIES = libftgles2.la

libftgles2_la_SOURCES = \
    FTBuffer.cpp \
    FTCharmap.cpp \
    FTCharmap.h \
    FTCharToGlyphIndexMap.h \
    FTContour.cpp \
    FTContour.h \
    FTFace.cpp \
    FTFace.h \
    FTGlyphContainer.cpp \
    FTGlyphContainer.h \
    FTInternals.h \
    FTLibrary.cpp \
    FTLibrary.h \
    FTList.h \
    FTPoint.cpp \
    FTSize.cpp \
    FTSize.h \
    FTVector.h \
    FTVectoriser.cpp \
    FTVectoriser.h \
    FTUnicode.h \
    $(iglu_sources) \
    $(ftglyph_sources) \
    $(ftfont_sources) \
    $(ftlayout_sources) \
    $(ftgles2_headers) \
    $(NULL)
libftgles2_la_CPPFLAGS = -IFTGlyph -IFTFont -IFTLayout
libftgles2_la_CXXFLAGS = $(FT2_CFLAGS) $(GL_CFLAGS)
libftgles2_la_LDFLAGS = \
        -no-undefined -version-number $(LT_VERSION) -framework OpenGLES
libftgles2_la_LIBADD = \
	$(FT2_LIBS) 

ftgles2dir = $(includedir)/FTGLES2
ftgles2_HEADERS = $(ftgles2_headers)

ftgles2_headers = \
    FTGLES2/ftgles2.h \
    FTGLES2/ftglesGlue.h \
    FTGLES2/ftgles2Glue.cpp \
    FTGLES2/FTBBox.h \
    FTGLES2/FTBuffer.h \
    FTGLES2/FTPoint.h \
    FTGLES2/FTGlyph.h \
    FTGLES2/FTBitmapGlyph.h \
    FTGLES2/FTBufferGlyph.h \
    FTGLES2/FTOutlineGlyph.h \
    FTGLES2/FTTextureGlyph.h \
    FTGLES2/FTFont.h \
    FTGLES2/FTGLBitmapFont.h \
    FTGLES2/FTBufferFont.h \
    FTGLES2/FTGLExtrdFont.h \
    FTGLES2/FTGLOutlineFont.h \
    FTGLES2/FTGLTextureFont.h \
    FTGLES2/FTGLPixmapFont.h \
    FTGLES2/FTPixmapGlyph.h \
    FTGLES2/FTPolyGlyph.h \
    FTGLES2/FTGLPolygonFont.h \
    FTGLES2/FTLayout.h \
    FTGLES2/FTSimpleLayout.h \
    ${NULL}

ftglyph_sources = \
    FTGlyph/FTGlyph.cpp \
    FTGlyph/FTGlyphImpl.h \
    FTGlyph/FTGlyphGlue.cpp \
    FTGlyph/FTBitmapGlyph.cpp \
    FTGlyph/FTBitmapGlyphImpl.h \
    FTGlyph/FTBufferGlyph.cpp \
    FTGlyph/FTBufferGlyphImpl.h \
    FTGlyph/FTOutlineGlyph.cpp \
    FTGlyph/FTOutlineGlyphImpl.h \
    FTGlyph/FTTextureGlyph.cpp \
    FTGlyph/FTTextureGlyphImpl.h \
    FTGlyph/FTPixmapGlyph.cpp \
    FTGlyph/FTPixmapGlyphImpl.h \
    FTGlyph/FTPolygonGlyph.cpp \
    FTGlyph/FTPolygonGlyphImpl.h
    $(NULL)

ftfont_sources = \
    FTFont/FTFont.cpp \
    FTFont/FTFontImpl.h \
    FTFont/FTFontGlue.cpp \
    FTFont/FTBitmapFont.cpp \
    FTFont/FTBitmapFontImpl.h \
    FTFont/FTBufferFont.cpp \
    FTFont/FTBufferFontImpl.h \
    FTFont/FTOutlineFont.cpp \
    FTFont/FTOutlineFontImpl.h \
    FTFont/FTTextureFont.cpp \
    FTFont/FTTextureFontImpl.h \
    FTFont/FTPolygonFont.cpp \
    FTFont/FTPolygonFontImpl.h \
    FTFont/FTPixmapFont.cpp \
    FTFont/FTPixmapFontImpl.h \
    $(NULL)

ftlayout_sources = \
    FTLayout/FTLayout.cpp \
    FTLayout/FTLayoutImpl.h \
    FTLayout/FTLayoutGlue.cpp \
    FTLayout/FTSimpleLayout.cpp \
    FTLayout/FTSimpleLayoutImpl.h \
    $(NULL)

iglu_sources = \
    iGLU-1.0.0/include/glu.h           \
    iGLU-1.0.0/include/gluos.h         \
    iGLU-1.0.0/libutil/error.c         \
    iGLU-1.0.0/libutil/glue.c          \
    iGLU-1.0.0/libutil/gluint.h        \
    iGLU-1.0.0/libutil/project.c       \
    iGLU-1.0.0/libutil/registry.c      \
    iGLU-1.0.0/libtess/dict.c          \
    iGLU-1.0.0/libtess/dict.h          \
    iGLU-1.0.0/libtess/geom.c          \
    iGLU-1.0.0/libtess/geom.h          \
    iGLU-1.0.0/libtess/memalloc.c      \
    iGLU-1.0.0/libtess/memalloc.h      \
    iGLU-1.0.0/libtess/mesh.c          \
    iGLU-1.0.0/libtess/mesh.h          \
    iGLU-1.0.0/libtess/normal.c        \
    iGLU-1.0.0/libtess/normal.h        \
    iGLU-1.0.0/libtess/priorityq.c     \
    iGLU-1.0.0/libtess/priorityq.h     \
    iGLU-1.0.0/libtess/render.c        \
    iGLU-1.0.0/libtess/render.h        \
    iGLU-1.0.0/libtess/sweep.c         \
    iGLU-1.0.0/libtess/sweep.h         \
    iGLU-1.0.0/libtess/tess.c          \
    iGLU-1.0.0/libtess/tess.h          \
    iGLU-1.0.0/libtess/tessmono.c      \
    iGLU-1.0.0/libtess/tessmono.h      \
    $(NULL)

NULL =
