####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = katalysator2
katalysator2_SOURCES = tmetraeger.cpp twerkstoff.cpp trohr.cpp tmatrix.cpp tkonus.cpp tkegelschnitt.cpp tkatbasis.cpp tedelmetall.cpp krohr_view.cpp krohr_impl.cpp krohr.ui katalysator2view.cpp katalysator2doc.cpp katalysator2.cpp main.cpp 
katalysator2_LDADD   =  $(LIB_KFILE) $(LIB_KDEUI) $(LIB_KDECORE) $(LIB_QT) $(LIBSOCKET)

SUBDIRS = sql 

EXTRA_DIST = main.cpp katalysator2.cpp katalysator2.h katalysator2doc.cpp katalysator2doc.h katalysator2view.cpp katalysator2view.h katalysator2ui.rc katalysator2.desktop lo32-app-katalysator2.png lo16-app-katalysator2.png krohr.ui krohr_impl.cpp krohr_impl.h krohr_view.cpp krohr_view.h tedelmetall.cpp tedelmetall.h tkatbasis.cpp tkatbasis.h tkegelschnitt.cpp tkegelschnitt.h tkonus.cpp tkonus.h tmatrix.cpp tmatrix.h trohr.cpp trohr.h twerkstoff.cpp twerkstoff.h definitions.h tmetraeger.cpp tmetraeger.h 

install-data-local:
	$(mkinstalldirs) $(kde_appsdir)/Applications/
	$(INSTALL_DATA) $(srcdir)/katalysator2.desktop $(kde_appsdir)/Applications/katalysator2.desktop
	$(mkinstalldirs) $(kde_icondir)/locolor/32x32/apps/
	$(INSTALL_DATA) $(srcdir)/lo32-app-katalysator2.png $(kde_icondir)/locolor/32x32/apps/katalysator2.png
	$(mkinstalldirs) $(kde_icondir)/locolor/16x16/apps/
	$(INSTALL_DATA) $(srcdir)/lo16-app-katalysator2.png $(kde_icondir)/locolor/16x16/apps/katalysator2.png

uninstall-local:
	-rm -f $(kde_appsdir)/Applications/katalysator2.desktop
	-rm -f $(kde_icondir)/locolor/32x32/apps/katalysator2.png
	-rm -f $(kde_icondir)/locolor/16x16/apps/katalysator2.png

####### kdevelop will overwrite this part!!! (end)############
# this 10 paths are KDE specific. Use them:
# kde_htmldir       Where your docs should go to. (contains lang subdirs)
# kde_appsdir       Where your application file (.kdelnk) should go to. 
# kde_icondir       Where your icon should go to.
# kde_minidir       Where your mini icon should go to.
# kde_datadir       Where you install application data. (Use a subdir)
# kde_locale        Where translation files should go to.(contains lang subdirs)
# kde_cgidir        Where cgi-bin executables should go to.
# kde_confdir       Where config files should go to.
# kde_mimedir       Where mimetypes should go to.
# kde_toolbardir    Where general toolbar icons should go to.
# kde_wallpaperdir  Where general wallpapers should go to.

# set the include path for X, qt and KDE
INCLUDES= $(all_includes)

METASOURCES = AUTO

# the library search path. 
katalysator2_LDFLAGS = $(all_libraries) $(KDE_RPATH)

rcdir = $(kde_datadir)/katalysator2
rc_DATA = katalysator2ui.rc

messages: rc.cpp
	LIST=`find . -name \*.h -o -name \*.hh -o -name \*.H -o -name \*.hxx -o -name \*.hpp -o -name \*.cpp -o -name \*.cc -o -name \*.cxx -o -name \*.ecpp -o -name \*.C`; \
	if test -n "$$LIST"; then \
	 $(XGETTEXT) $$LIST -o $(podir)/katalysator2.pot; \
	fi

