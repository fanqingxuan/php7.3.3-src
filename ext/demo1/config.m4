dnl config.m4 for extension demo1

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(demo1, for demo1 support,
dnl Make sure that the comment is aligned:
dnl [  --with-demo1             Include demo1 support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(demo1, whether to enable demo1 support,
dnl Make sure that the comment is aligned:
[  --enable-demo1          Enable demo1 support], no)

if test "$PHP_DEMO1" != "no"; then
  dnl Write more examples of tests here...

  dnl # get library FOO build options from pkg-config output
  dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  dnl AC_MSG_CHECKING(for libfoo)
  dnl if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists foo; then
  dnl   if $PKG_CONFIG foo --atleast-version 1.2.3; then
  dnl     LIBFOO_CFLAGS=\`$PKG_CONFIG foo --cflags\`
  dnl     LIBFOO_LIBDIR=\`$PKG_CONFIG foo --libs\`
  dnl     LIBFOO_VERSON=\`$PKG_CONFIG foo --modversion\`
  dnl     AC_MSG_RESULT(from pkgconfig: version $LIBFOO_VERSON)
  dnl   else
  dnl     AC_MSG_ERROR(system libfoo is too old: version 1.2.3 required)
  dnl   fi
  dnl else
  dnl   AC_MSG_ERROR(pkg-config not found)
  dnl fi
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, DEMO1_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-demo1 -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/demo1.h"  # you most likely want to change this
  dnl if test -r $PHP_DEMO1/$SEARCH_FOR; then # path given as parameter
  dnl   DEMO1_DIR=$PHP_DEMO1
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for demo1 files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       DEMO1_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$DEMO1_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the demo1 distribution])
  dnl fi

  dnl # --with-demo1 -> add include path
  dnl PHP_ADD_INCLUDE($DEMO1_DIR/include)

  dnl # --with-demo1 -> check for lib and symbol presence
  dnl LIBNAME=DEMO1 # you may want to change this
  dnl LIBSYMBOL=DEMO1 # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $DEMO1_DIR/$PHP_LIBDIR, DEMO1_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_DEMO1LIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong demo1 lib version or lib not found])
  dnl ],[
  dnl   -L$DEMO1_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(DEMO1_SHARED_LIBADD)

  dnl # In case of no dependencies
  AC_DEFINE(HAVE_DEMO1, 1, [ Have demo1 support ])

  PHP_NEW_EXTENSION(demo1, demo1.c, $ext_shared)
fi
