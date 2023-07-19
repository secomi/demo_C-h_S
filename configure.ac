AC_INIT([demo_C-h_S],[1.0.0],[email@domain.com],[demo_C-h_S])

dnl AC_PROG_CC setups with CFLAGS="-g -O2"
AC_PROG_CC

AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_SILENT_RULES([yes])


PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.44])


## warnings
AX_CFLAGS_WARN_ALL([CFLAGS])
AX_APPEND_COMPILE_FLAGS([-fanalyzer], [CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wextra], [CFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wpedantic], [CFLAGS])


AC_CONFIG_FILES([
      Makefile
      src/Makefile
      doc/Makefile
])

AC_OUTPUT
