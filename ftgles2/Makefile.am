
ACLOCAL_AMFLAGS = -I m4

SUBDIRS = src
DIST_SUBDIRS = $(SUBDIRS) msvc

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = ftgles2.pc

DISTCLEANFILES = ftgles2.pc

EXTRA_DIST = \
	AUTHORS \
	BUGS \
	COPYING \
	ChangeLog \
	INSTALL \
	NEWS \
	README \
	TODO \
	autogen.sh \
	configure.ac \
	ftgles2.pc.in \
	m4 \
	$(NULL)

# Print out an informative summary.
# all-local:
# 	@$(ECHO) "Done."
# 	@$(ECHO)
# 	@if test "x$(MAKECMDGOALS)" = "xall-am" -o "x$(.TARGETS)" = "xall-am" -o "x$(MAKECMDGOALS)" = "x" -o "x$(.TARGETS)" = "x" ; then \
# 	  $(ECHO) "---" ;\
# 	  $(ECHO) "Run 'make install' to begin installation into $(prefix)" ;\
# 	fi
# 	@$(ECHO)

# Upload documentation
DOC = docs/html docs/latex/ftgles2.pdf
HOST = ftgl.sf.net
DIR = /home/groups/f/ft/ftgl/htdocs/
upload-doc:
	tar cz $(DOC) | ssh $(HOST) "cd $(DIR) && rm -Rf $(DOC) && tar xvz"

NULL =
