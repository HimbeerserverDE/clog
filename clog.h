#ifndef _CLOG_H_
#define _CLOG_H_

#include <stdarg.h>

int lprintf(const char *format, ...);

int vlprintf(const char *format, va_list ap);

#endif
