AC_INIT([yaaes], [0.0.1], [gdrinaldi@inf.ufrgs.br], [yaaes], [http://www.inf.ufrgs.br/~gdrinaldi/])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CXX
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
	Makefile
	src/Makefile
])
#PKG_CHECK_MODULES([YAAES], [gtkmm-2.4 >= 2.4])

#AC_SUBST(CXXFLAGS, "-g -O3 -march=amdfam10 -mabm -msse4a -funroll-all-loops -fwhole-program -ftree-parallelize-loops=4 -fprefetch-loop-arrays -ffast-math")
AC_SUBST(CXXFLAGS, "-g -O3 -march=amdfam10 -mabm -msse4a -funroll-all-loops -ftree-parallelize-loops=4 -fprefetch-loop-arrays -ffast-math -fno-trapping-math")
#AC_SUBST(CXXFLAGS, "-g -O2 -pg")

AC_SUBST(YAAES_CFLAGS)
AC_SUBST(YAAES_LIBS)

AC_OUTPUT
