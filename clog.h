#ifndef _CLOG_H_
#define _CLOG_H_

#include <stdarg.h>

int lprintf(const char *format, ...);
void lfatalf(const char *format, ...);

int lvprintf(const char *format, va_list ap);
void lvfatalf(const char *format, va_list ap);

#endif
