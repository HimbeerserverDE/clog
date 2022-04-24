#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clog.h"

#define TIMESTRLEN 20

int lprintf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	int n = lvprintf(format, ap);

	va_end(ap);
	return n;
}

void lfatalf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	lvfatalf(format, ap);
	// Can't clean up as lvfatalf ends the process
}

int lvprintf(const char *format, va_list ap)
{
	time_t timer = time(NULL);
	struct tm *tm_info = localtime(&timer);

	char buf[TIMESTRLEN];
	strftime(buf, TIMESTRLEN, "%Y/%m/%d %H:%M:%S", tm_info);
	free(tm_info);

	int n = printf("%s ", buf);

	size_t fmtlen = strlen(format) + 2;
	char fmt[fmtlen];

	memset(fmt, '\0', fmtlen);
	strcpy(fmt, format);
	strcat(fmt, "\n");

	n += vprintf(format, ap);
	return n;
}

void lvfatalf(const char *format, va_list ap)
{
	lvprintf(format, ap);
	exit(EXIT_FAILURE);
}
