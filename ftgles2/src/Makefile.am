
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
    FTGLES2/ftgles2Glue.h \
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
    iGLUes2/include/glues2.h           \
    iGLUes2/include/glues2os.h         \
    iGLUes2/libutil/error.c         \
    iGLUes2/libutil/glue.c          \
    iGLUes2/libutil/glues2int.h        \
    iGLUes2/libutil/project.c       \
    iGLUes2/libutil/registry.c      \
    iGLUes2/libtess/dict.c          \
    iGLUes2/libtess/dict.h          \
    iGLUes2/libtess/geom.c          \
    iGLUes2/libtess/geom.h          \
    iGLUes2/libtess/memalloc.c      \
    iGLUes2/libtess/memalloc.h      \
    iGLUes2/libtess/mesh.c          \
    iGLUes2/libtess/mesh.h          \
    iGLUes2/libtess/normal.c        \
    iGLUes2/libtess/normal.h        \
    iGLUes2/libtess/priorityq.c     \
    iGLUes2/libtess/priorityq.h     \
    iGLUes2/libtess/render.c        \
    iGLUes2/libtess/render.h        \
    iGLUes2/libtess/sweep.c         \
    iGLUes2/libtess/sweep.h         \
    iGLUes2/libtess/tess.c          \
    iGLUes2/libtess/tess.h          \
    iGLUes2/libtess/tessmono.c      \
    iGLUes2/libtess/tessmono.h      \
    $(NULL)

NULL =
