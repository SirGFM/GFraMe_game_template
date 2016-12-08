/**
 * @file include/base/error.h
 */
#ifndef __ERROR_H__
#define __ERROR_H__

#include <conf/error_list.h>

/** Add signal handling so GDB freezes on failed asserts */
#if defined(DEBUG) && !(defined(__WIN32) || defined(__WIN32__))
#  include <stdlib.h>
#  include <signal.h>
#endif

/** Make GDB stop (only on DEBUG mode) */
#if defined(DEBUG) && !(defined(__WIN32) || defined(__WIN32__))
#  define STOP_GDB() \
     do { raise(SIGINT); } while(0)
#else
#  define STOP_GDB()
#endif

/** Simple 'no-op'. Useful in ASSERT_TO, when the return value has already been
 * set */
#define NOOP() \
  do { } while (0)

/**
 * Check if a condition failed, execute a statement (to set the error value) and
 * jump to a label (where clean up should be done).
 *
 * @param  [ in]stmt     Statement to be evaluated
 * @param  [ in]ret_stmt Statement to set the erro value
 * @param  [ in]label    Label where function clean up should be done
 */
#define ASSERT_TO(stmt, ret_stmt, label) \
  do { \
    if (!(stmt)) { \
      STOP_GDB(); \
      ret_stmt; \
      goto label; \
    } \
  } while (0)

/**
 * Check if a condition failed and return its error
 *
 * @param  [ in]stmt Statement to be evaluated
 * @param  [ in]ret  Returned value, on failure
 */
#define ASSERT(stmt, ret) \
  do { \
    if (!(stmt)) { \
      STOP_GDB(); \
      return ret; \
    } \
  } while (0)

enum enErr {
#define X(val) val,
    ERROR_LIST
#undef X
};
typedef enum enErr err;

#endif /* __ERROR_H__ */

